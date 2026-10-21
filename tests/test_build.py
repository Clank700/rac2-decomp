"""Object-cache and release-check regressions, without game data or toolchains."""
from contextlib import ExitStack, redirect_stdout
from io import StringIO
import json
import os
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import build


class ObjectCache(unittest.TestCase):
    def setUp(self):
        self.stack = ExitStack()
        self.addCleanup(self.stack.close)
        self.root = Path(self.stack.enter_context(tempfile.TemporaryDirectory()))
        self.stack.enter_context(patch.multiple(build, ROOT=self.root, BUILD=self.root / "build",
            COMPILER=self.root / "build/compiler/tools", SDK_COMPILER=self.root / "build/compiler/sdk"))
        self.stack.enter_context(patch.dict(os.environ, {"RAC2_LINUX": ""}))
        self.source = self.root / "src/game/example.c"
        self.write(self.source, "int example(void) { return 1; }\n")
        self.write(self.root / "include/example.h", "#define EXAMPLE 1\n")
        self.write(self.source.parent / "local.h", "#define LOCAL 1\n")
        for directory in (build.COMPILER, build.SDK_COMPILER):
            for name in ("cpp", "cc1", "as", "xgcc"):
                self.write(directory / name, name)
            self.write(directory / "include/stdarg.h", "/* compiler header */\n")
        self.out = build.BUILD / "obj/src/game/example.c.o"
        self.compiler = self.stack.enter_context(patch.object(build.subprocess, "run", side_effect=self.compile))

    def write(self, path, contents):
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(contents)

    def compile(self, *args, **kwargs):
        self.out.write_bytes(b"compiled object")
        return SimpleNamespace(returncode=0, stderr="")

    def test_unchanged_inputs_reuse_object(self):
        build.compile_c(self.source)
        build.compile_c(self.source)
        self.assertEqual(self.compiler.call_count, 1)

    def test_changed_executables_invalidate_even_with_preserved_mtime_and_size(self):
        for name in ("cpp", "cc1", "as"):
            with self.subTest(name=name):
                build.compile_c(self.source)
                before = self.compiler.call_count
                path = build.COMPILER / name
                stat = path.stat()
                replacement = path.with_suffix(".new")
                replacement.write_bytes(b"X" * stat.st_size)
                os.utime(replacement, ns=(stat.st_atime_ns, stat.st_mtime_ns))
                os.replace(replacement, path)
                build.compile_c(self.source)
                self.assertEqual(self.compiler.call_count, before + 1)

    def test_sdk_tracks_driver_frontend_preprocessor_and_game_assembler(self):
        self.write(self.root / "config/cflags.txt", "src/game/example.c\tsdk -O2\n")
        for path in [build.SDK_COMPILER / name for name in ("xgcc", "cpp", "cc1")] + [build.COMPILER / "as"]:
            with self.subTest(path=path):
                build.compile_c(self.source)
                before = self.compiler.call_count
                path.write_bytes(path.read_bytes() + b"new")
                build.compile_c(self.source)
                self.assertEqual(self.compiler.call_count, before + 1)
        before = self.compiler.call_count
        (build.COMPILER / "cc1").write_text("unselected game compiler changed")
        build.compile_c(self.source)
        self.assertEqual(self.compiler.call_count, before)

    def test_source_headers_flags_and_runner_invalidate(self):
        for path in (self.source, self.root / "include/example.h", self.source.parent / "local.h",
                     build.COMPILER / "include/stdarg.h"):
            with self.subTest(path=path):
                build.compile_c(self.source)
                before = self.compiler.call_count
                path.write_text(path.read_text() + "\n")
                build.compile_c(self.source)
                self.assertEqual(self.compiler.call_count, before + 1)
        before = self.compiler.call_count
        self.write(self.root / "config/cflags.txt", "src/game/example.c\t-O1\n")
        build.compile_c(self.source)
        self.assertEqual(self.compiler.call_count, before + 1)
        with patch.dict(os.environ, {"RAC2_LINUX": "container exec compiler"}):
            build.compile_c(self.source)
        self.assertEqual(self.compiler.call_count, before + 2)

    def test_old_flags_only_cache_is_rebuilt(self):
        self.write(self.out, "old object")
        self.write(self.out.with_suffix(".flags"), build.flags_for(self.source))
        build.compile_c(self.source)
        self.assertEqual(self.compiler.call_count, 1)

    def test_missing_tool_does_not_reuse_cached_object(self):
        build.compile_c(self.source)
        (build.COMPILER / "as").unlink()
        with self.assertRaises(FileNotFoundError):
            build.compile_c(self.source)

    def test_failed_compile_does_not_stamp_new_inputs(self):
        build.compile_c(self.source)
        stamp = self.out.with_suffix(".inputs")
        previous = stamp.read_text()
        self.source.write_text("not C")
        self.compiler.side_effect = None
        self.compiler.return_value = SimpleNamespace(returncode=1, stderr="syntax error")
        with self.assertRaisesRegex(SystemExit, "syntax error"):
            build.compile_c(self.source)
        self.assertEqual(stamp.read_text(), previous)


class StrictBuild(unittest.TestCase):
    def exercise(self, strict, differs, same=True):
        with tempfile.TemporaryDirectory() as directory, ExitStack() as stack:
            root = Path(directory)
            placement = SimpleNamespace(functions={}, values={}, placed={}, differ=differs, place=lambda: None)

            def configure(reference, out, name):
                (out / "config").mkdir(parents=True)
                (out / "config/rac2.ld").write_text("SECTIONS {}")
                return {}

            stack.enter_context(patch.object(build, "BUILD", root))
            stack.enter_context(patch.object(build, "splat_config", side_effect=configure))
            stack.enter_context(patch.object(build, "Placement", return_value=placement))
            stack.enter_context(patch.object(build.elf, "read", return_value={"entry": 0}))
            stack.enter_context(patch.object(build.elf, "compare_loads", return_value=(same, "synthetic comparison")))
            for name in ("run", "adapt_linker", "undefined_symbols"):
                stack.enter_context(patch.object(build, name))
            stack.enter_context(redirect_stdout(StringIO()))
            error = None
            try:
                build.build_program("boot", root / "reference", strict=strict)
            except SystemExit as exc:
                error = exc.code
            report = root / "boot/placed.json"
            return error, json.loads(report.read_text()) if report.exists() else None

    def test_strict_rejects_fallback_even_when_loaded_bytes_match(self):
        error, report = self.exercise(True, [("candidate", "wrong size")])
        self.assertIn("strict check failed", error)
        self.assertEqual(report["differ"], {"candidate": "wrong size"})

    def test_exploratory_build_retains_fallback(self):
        error, report = self.exercise(False, [("candidate", "wrong size")])
        self.assertIsNone(error)
        self.assertEqual(report["differ"], {"candidate": "wrong size"})

    def test_strict_accepts_no_fallback_and_rejects_loaded_byte_changes(self):
        self.assertEqual(self.exercise(True, [])[0], None)
        error, report = self.exercise(True, [], same=False)
        self.assertEqual(error, 1)
        self.assertIsNone(report)

    def test_parallel_build_propagates_strict_and_child_failure(self):
        with patch.object(sys, "argv", ["build.py", "all", "--strict", "--jobs", "2"]), \
             patch.object(build.levels, "NAMES", {0: "test"}), \
             patch.object(build.subprocess, "run", return_value=SimpleNamespace(
                 returncode=1, stdout="", stderr="strict failure")) as run, redirect_stdout(StringIO()):
            with self.assertRaisesRegex(SystemExit, "2 of 2 programs failed"):
                build.main()
            self.assertEqual(run.call_count, 2)
            for call in run.call_args_list:
                self.assertIn("--strict", call.args[0])
