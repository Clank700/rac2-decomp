#!/usr/bin/env python3
"""Check SEVERAL scratch C variants of one function in one container call.

  python3 scratch/multichk.py <level-nn> <addr-hex> <size> <variant.c>...

Runs inside the container (see tools/check.py for the placement test it reuses).
Each variant file is compiled with the file's own flags through build.compile_c
and its bytes are compared with the retail function at ADDR/SIZE in the level
program; the first differing instructions are printed like check.py --diff.
The same bytes are also tried in every other place the catalogue lists.
"""
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
while not (ROOT / "tools").is_dir():
    ROOT = ROOT.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import elf  # noqa: E402
import levels  # noqa: E402


def compile_flags(source: Path, flags: str) -> Path:
    """build.compile_c with explicit flags (same chain), object under build/obj/scratch."""
    out = build.BUILD / "obj" / "scratch" / (source.stem + "-" + str(abs(hash(flags)) % 100000) + ".o")
    out.parent.mkdir(parents=True, exist_ok=True)
    script = (f"set -e; t=$(mktemp -d); cd $t; cp '{source}' x.c; "
              f"'{build.COMPILER}/cpp' -I'{build.COMPILER}/include' -I'{ROOT}/include' -I'{source.parent}' x.c > x.i; "
              f"'{build.COMPILER}/cc1' -quiet {flags} x.i -o x.s; '{build.COMPILER}/as' -o x.o x.s; "
              f"cp x.o '{out}'.$$; mv '{out}'.$$ '{out}'; rm -rf $t")
    result = subprocess.run(["bash", "-c", script], capture_output=True, text=True)
    if result.returncode:
        print(f"  compile failed: {result.stderr[-600:]}")
    return out


def disassemble(data: bytes, address: int) -> list[str]:
    import rabbitizer
    out = []
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i + 4], "little")
        out.append(rabbitizer.Instruction(word, vram=address + i).disassemble())
    return out


def body_of(obj: dict, name: str):
    sym = next((s for s in obj["symbols"] if s["name"] == name and s["type"] == 2), None)
    if sym is None:
        return None
    index = sym["section"]
    return index, obj["sections"][index]["data"]


def main() -> None:
    argv = sys.argv[1:]
    flags = next((a[8:] for a in argv if a.startswith("--flags=")), None)
    full = "--full" in argv
    # targets: --at LEVEL:ADDR:SIZE, each followed by that target's variant files
    targets = []
    for a in argv:
        if a.startswith("--at="):
            lv, addr, size = a[5:].split(":")
            targets.append((int(lv), int(addr, 16), int(size), []))
        elif a.startswith("--") or a == "--full":
            continue
        elif targets:
            targets[-1][3].append(a)
    if not targets:                      # legacy: LEVEL ADDR SIZE file...
        plain = [a for a in argv if not a.startswith("--")]
        targets = [(int(plain[0]), int(plain[1], 16), int(plain[2]), plain[3:])]
    for level, address, size, files_raw in targets:
      for spec in files_raw:
        spec_flags, path = (spec.split("@", 1) if "@" in spec and spec.startswith("-")
                            else (None, spec))
        path = Path(path).resolve()
        try:
            obj = elf.read_object(compile_flags(path, spec_flags or flags) if (spec_flags or flags)
                                  else build.compile_c(path))
        except SystemExit as e:
            print(f"=== {path.name}: does not compile: {e}")
            continue
        name = next((s["name"] for s in obj["symbols"]
                     if s["type"] == 2 and s["name"].startswith("func_")), None)
        got = body_of(obj, name)
        if got is None:
            print(f"=== {path.name}: no function symbol")
            continue
        index, data = got
        print(f"=== {path.name}  {name}  {len(data)} bytes (retail {size})")
        for program in [levels.level_dir(level)]:
            image = elf.read(build.level_reference(level))
            placement = build.Placement(program, image)
            why = None
            have = obj["sections"][index]["size"]
            if have != size:
                why = f"{have} bytes, expected {size}"
            else:
                _, why = placement.derive(obj, index, address)
            print(f"    {program}: {'OK' if why is None else why}")
            if why:
                mine = disassemble(data, address)
                theirs = disassemble(placement.retail(address, size), address)
                if full:
                    for k in range(max(len(mine), len(theirs))):
                        a = mine[k] if k < len(mine) else ""
                        b = theirs[k] if k < len(theirs) else ""
                        print(f"      {address + 4 * k:08X}  {a:<34}{'  ' if a == b else '| '}{b}")
                    continue
                shown = 0
                for k in range(max(len(mine), len(theirs))):
                    a = mine[k] if k < len(mine) else ""
                    b = theirs[k] if k < len(theirs) else ""
                    if a != b and shown < 10:
                        print(f"      {address + 4 * k:08X}  {a:<34}| {b}")
                        shown += 1


if __name__ == "__main__":
    main()
