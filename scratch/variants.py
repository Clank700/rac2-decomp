#!/usr/bin/env python3
"""Screen candidate C bodies for one function the way tools/check.py would.

  python3 scratch/variants.py func_L00_0032A0B8 scratch/v1.c scratch/v2.c ...

Compiles each candidate file, finds NAME in it and derives symbol values against one program
(level number as --level, default 0), printing OK or the first reason it differs.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import elf  # noqa: E402
import levels  # noqa: E402


def main() -> None:
    argv = sys.argv[1:]
    level = 0
    if "--level" in argv:
        i = argv.index("--level")
        level = int(argv[i + 1])
        del argv[i:i + 2]
    name, candidates = argv[0], argv[1:]
    program = levels.level_dir(level)
    image = elf.read(build.level_reference(level))
    placement = build.Placement(program, image)
    for candidate in candidates:
        source = Path(candidate).resolve()
        try:
            obj = elf.read_object(build.compile_c(source))
        except SystemExit as error:
            print(f"{source.name}: does not compile: {str(error)[-400:]}")
            continue
        sym = next((s for s in obj["symbols"] if s["name"] == name and s["type"] == 2), None)
        if sym is None:
            print(f"{source.name}: defines no function {name}")
            continue
        address, size = placement.functions[name][0]
        index = sym["section"]
        have = obj["sections"][index]["size"]
        data, ref = obj["sections"][index]["data"], placement.retail(address, size)

        def show_diff():
            import rabbitizer

            def dis(word, at):
                return rabbitizer.Instruction(int.from_bytes(word, "little"), vram=at).disassemble()

            for at in range(0, max(len(data), len(ref)), 4):
                mine, theirs = data[at:at + 4], ref[at:at + 4]
                if mine != theirs:
                    left = dis(mine, address + at) if len(mine) == 4 else ""
                    right = dis(theirs, address + at) if len(theirs) == 4 else ""
                    print(f"    +{at:#04x}  {address + at:08X}  {left:<34}| {right}")

        if have != size:
            print(f"{source.name}: {have} bytes, expected {size}")
            show_diff()
            continue
        _, why = placement.derive(obj, index, address)
        print(f"{source.name}: {'OK' if why is None else why}")
        if why is not None:
            show_diff()


if __name__ == "__main__":
    main()
