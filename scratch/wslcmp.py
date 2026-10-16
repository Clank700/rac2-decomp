#!/usr/bin/env python3
"""Docker-free check: compile a C file with the 32-bit Linux cc1 under WSL, then give
every function in it the verdict tools/check.py would give it.

  D:\\RAC2\\.venv\\Scripts\\python.exe scratch\\wslcmp.py <source.c> [names...] [flags="..."] [full] [cc=<wsl path>] [quiet]

The compiler is the same rebuilt cc1/cpp/as as the container's (master's build); WSL runs it
directly, so no Docker daemon is involved. Intermediates and the object live in
scratch/out/. Verdicts come from tools/build.py's Placement.derive, i.e. the same code path
as tools/check.py.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(r"D:/RAC2/worktrees/agent-lvl6-04")
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import elf  # noqa: E402
import levels  # noqa: E402

OUT = ROOT / "scratch" / "out"
WSL = ["wsl", "-d", "Ubuntu", "--"]
CC = "/mnt/d/RAC2/master/build/compiler/tools"
MASTER_BUILD = "--master-build"


def to_wsl(p: Path) -> str:
    p = Path(p)
    return "/mnt/" + p.drive[0].lower() + str(p)[2:].replace("\\", "/")


def compile_wsl(source: Path, flags: str, out_obj: Path) -> bool:
    # scratch/wslcc.sh does the work in /tmp (Linux-native): the 32-bit cc1 cannot stat drvfs
    # files (EOVERFLOW), which is why the container runs on a docker volume instead.
    script = (f"bash '{to_wsl(ROOT / 'scratch' / 'wslcc.sh')}' "
              f"'{to_wsl(source)}' '{to_wsl(out_obj)}' '{flags}'")
    r = subprocess.run(WSL + ["bash", "-c", script], capture_output=True, text=True)
    if r.returncode or "COMPILE_OK" not in r.stdout:
        print(f"COMPILE FAILED ({source.name}):")
        print((r.stdout or "")[-1500:])
        print((r.stderr or "")[-1500:])
        return False
    print((r.stdout or "").strip())
    return True


def disassemble(data: bytes, address: int) -> list:
    import rabbitizer
    out = []
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i + 4], "little")
        out.append(rabbitizer.Instruction(word, vram=address + i).disassemble())
    return out


def verdict(name: str, obj: dict, index: int, full: bool, quiet: bool) -> bool:
    programs = ["boot"] if any(n == name for n, _, _ in levels.read_boot_functions()) else []
    for row in levels.read_catalogue():
        if row[0] == name:
            programs += [levels.level_dir(lv) for lv, _ in row[4]]
    if not programs:
        print(f"{name}: in neither catalogue")
        return False
    ok, shown, first = 0, False, None
    for program in programs:
        image = elf.read(levels.BOOT if program == "boot"
                         else build.level_reference(int(program[:2])))
        placement = build.Placement(program, image)
        if name not in placement.functions:
            if first is None:
                first = f"{program}: not in the program"
            continue
        address, size = placement.functions[name][0]
        have = obj["sections"][index]["size"]
        if have != size:
            why = f"{have} bytes, expected {size}"
        else:
            _, why = placement.derive(obj, index, address)
        if why is None:
            ok += 1
        elif first is None:
            first = f"{program}: {why}"
        if why and (full or not shown) and not quiet:
            shown = True
            mine = disassemble(obj["sections"][index]["data"], address)
            theirs = disassemble(placement.retail(address, size), address)
            print(f"  --- {program} @{address:#010x}: {why}")
            for k in range(max(len(mine), len(theirs))):
                a = mine[k] if k < len(mine) else ""
                b = theirs[k] if k < len(theirs) else ""
                if a != b or full:
                    print(f"  {address + 4 * k:08X}  {a:<40} | {b}")
    print(f"{name}: {ok} of {len(programs)} places match"
          + ("" if ok == len(programs) else f"   [{first}]"))
    return ok == len(programs)


def main() -> None:
    args = sys.argv[1:]
    source = Path(args[0])
    if not source.is_absolute():
        source = ROOT / source
    flags, full, quiet = None, "full" in args, "quiet" in args
    names = []
    for a in args[1:]:
        if a.startswith("flags="):
            flags = a[6:]
        elif a.startswith("cc="):
            globals()["CC"] = a[3:]
        elif a in ("quiet", "full", "--master-build"):
            pass
        elif not a.startswith("--"):
            names.append(a)
    if flags is None:
        flags = build.flags_for(source)
    obj_path = OUT / (source.stem + ".wsl.o")
    OUT.mkdir(parents=True, exist_ok=True)
    print(f"=== {source.relative_to(ROOT) if ROOT in source.parents else source.name}  "
          f"flags {flags}  cc {CC}")
    if not compile_wsl(source, flags, obj_path):
        sys.exit(2)
    obj = elf.read_object(obj_path)
    cat = {row[0] for row in levels.read_catalogue()}
    funcs = []
    # -ffunction-sections puts every function in its own .text.<name> section, which is the
    # name build.py's Placement.place() looks for, so the section table is the reliable
    # index here (the symbol table reports the same bodies as STT_NOTYPE).
    funcs = []
    for i, sec in enumerate(obj["sections"]):
        nm = sec["name"]
        if not nm.startswith(".text.") or not sec["size"]:
            continue
        sym_name = nm[len(".text."):]
        base = re.sub(r"_v\d+$", "", sym_name)      # func_X_v1 is a variant of func_X
        if base in cat:
            funcs.append((base, sym_name, i))
    if not funcs:
        for s in obj["symbols"]:
            sym_name = s.get("name") or ""
            base = re.sub(r"_v\d+$", "", sym_name)
            if base in cat and s.get("section"):
                funcs.append((base, sym_name, s["section"]))
    if names:
        funcs = [f for f in funcs if f[0] in names or f[1] in names]
    if not funcs:
        print("no catalogued function in the object")
        return
    n_ok = 0
    for base, sym, index in funcs:
        if sym != base:
            print(f"[{sym}]")
        if verdict(base, obj, index, full, quiet):
            n_ok += 1
    print(f"--- {n_ok} of {len(funcs)} clean")


if __name__ == "__main__":
    main()
