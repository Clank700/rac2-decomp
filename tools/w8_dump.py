#!/usr/bin/env python3
"""Dump the retail bytes of one catalogue function, in one level or in all of them.

Runs inside the build container, next to the repository:

    python3 tools/w8_dump.py func_L00_002B1308
    python3 tools/w8_dump.py func_L00_002B1308 --level 07_siberius

Prints the address, the raw words, the disassembly and the addresses the
branches and the jumps reach, with the catalogue name when there is one. This
is the ground truth a body is reconstructed from: nothing here is invented.
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import build  # noqa: E402
import elf  # noqa: E402
import levels  # noqa: E402

import rabbitizer  # noqa: E402


def catalogue_names(program: str) -> dict:
    """address -> function name, for one program."""
    names = {}
    for name, places in build.program_functions(program).items():
        for address, size in places:
            names.setdefault(address, name)
    return names


def sign16(value: int) -> int:
    return value - 0x10000 if value & 0x8000 else value


def main() -> None:
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    name = args[0]
    only = None
    if "--level" in sys.argv:
        only = sys.argv[sys.argv.index("--level") + 1]

    row = next((r for r in levels.read_catalogue() if r[0] == name), None)
    if row is None:
        sys.exit(f"{name} is not in the level catalogue")
    places = row[4]

    for lv, address in places:
        program = levels.level_dir(lv)
        if only and program != only and program[:2] != only[:2]:
            continue
        image = elf.read(build.level_reference(lv))
        placement = build.Placement(program, image)
        real, size = placement.functions[name][0]
        data = placement.retail(real, size)
        names = catalogue_names(program)
        print(f"=== {name}: level {program} address 0x{real:08X} size {size}")
        for i in range(0, len(data), 4):
            word = struct.unpack_from("<I", data, i)[0]
            text = rabbitizer.Instruction(word, vram=real + i).disassemble()
            at = real + i
            opcode = word >> 26
            if opcode == 2:                      # beq / bne / blez / bgtz
                target = at + 4 + (sign16(word & 0xFFFF) << 2)
                text += f"        -> 0x{target:08X} {names.get(target, '')}"
            elif opcode == 3:                    # jal
                target = (word & 0x3FFFFFF) << 2
                text += f"        -> 0x{target:08X} {names.get(target, '')}"
            elif opcode == 1:                    # jr / jalr
                text += f"        -> link reg ${word & 0x3F}"
            print(f"  {at:08X}  {word:08X}  {text}")
        print()


if __name__ == "__main__":
    main()
