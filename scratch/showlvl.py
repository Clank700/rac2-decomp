#!/usr/bin/env python3
"""Retail disassembly of a level function (func_LNN_XXXXXXXX), with absolute branch targets.

  python3 scratch/showlvl.py func_L00_0030D7C8 ...        # one place each (level 00)
  python3 scratch/showlvl.py -p 3 func_...                # first 3 places each
  python3 scratch/showlvl.py -w 0 0x0030D7A0 0xA0         # raw window: level, start, count

Reads the dumped level programs under D:/RAC2/master/baserom/levels/ (read-only) and the
catalogue config/levels/functions.tsv for sizes.
"""
import struct
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402
import rabbitizer  # noqa: E402


def target(word, addr):
    """Branch/jump destination: j/jal use the absolute (imm << 2) form, branches are
    PC-relative."""
    op = (word >> 26) & 0x3F
    imm = word & 0xFFFF
    if imm & 0x8000:
        imm -= 0x10000
    if op in (0x02, 0x03):
        return ((addr + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
    if op in (0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17,
              0x02, 0x03, 0x13, 0x11, 0x12, 0x10, 0x08, 0x09):
        return addr + 4 + (imm << 2)
    return None


def dump(start: int, body: bytes, label: str = ""):
    print(label)
    for i in range(0, len(body), 4):
        word = int.from_bytes(body[i:i + 4], "little")
        t = target(word, start + i)
        tgt = f"  -> {t:#010x}" if t is not None else ""
        print(f"    +{i:3d}  0x{word:08X}  "
              f"{rabbitizer.Instruction(word, vram=start + i).disassemble():<32}{tgt}")
    print()


def window(level: int, start: int, count: int):
    base, data = levels.level_text(MASTER / "baserom/levels" / levels.level_dir(level))
    dump(start, data[start - base:start - base + count], f"--- window level {level:02d} {start:#010x} +{count}")


def catalogue_rows():
    out = {}
    for name, kind, size, fp, places in levels.read_catalogue():
        out[name] = (kind, size, places)
        for number, address in places:
            out[(number, address)] = name
    return out


def main():
    argv = sys.argv[1:]
    places_wanted = 1
    if "-p" in argv:
        i = argv.index("-p")
        places_wanted = int(argv[i + 1])
        del argv[i:i + 2]
    if argv and argv[0] == "-w":
        window(int(argv[1]), int(argv[2], 16), int(argv[3], 0))
        return
    rows = catalogue_rows()
    if argv and argv[0] == "-a":
        for spec in argv[1:]:
            level, address = spec.split(":")
            print(f"{spec}: {rows.get((int(level), int(address, 16)), 'no function starts here')}")
        return
    for name in argv:
        if name not in rows:
            print(f"{name}: not in the level catalogue")
            continue
        kind, size, places = rows[name]
        print(f"=== {name}  {kind}  {size} bytes  {len(places)} places")
        for number, address in places[:places_wanted]:
            directory = MASTER / "baserom/levels" / levels.level_dir(number)
            base, data = levels.level_text(directory)
            start, length = levels.level_extent(number, address, size)
            dump(start, data[start - base:start - base + length],
                 f"--- level {number:02d} {levels.NAMES[number]}  {start:#010x} +{length}")


if __name__ == "__main__":
    main()
