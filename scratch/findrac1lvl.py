#!/usr/bin/env python3
"""Find a RAC2 level function's masked instruction pattern inside RAC1 level overlays.

  python3 scratch/findrac1lvl.py func_L00_0032A0B8 [--level 00] [--mask loose|strict]

Prints every RAC1 overlay address whose 12/48... word window matches, plus the RAC1 ELF and
the section-relative address. Read-only: reads D:/RAC2/master baserom and D:/RAC1/levels.
"""
import struct
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
RAC1 = Path(r"D:/RAC1/levels")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402


def words(b):
    return list(struct.unpack(f"<{len(b) // 4}I", b[: len(b) // 4 * 4]))


def loose_one(x):
    """opcode + registers only: every immediate and jump target masked."""
    op = x >> 26
    if op in (0x02, 0x03):                       # j / jal
        return x & 0xFC000000
    if op == 0:
        if (x & 0x3F) in (0x00, 0x02, 0x03, 0x06, 0x08, 0x0A, 0x0B, 0x2B):
            return x & 0xFFFF07C0
        return x
    if op in (0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17):
        return x & 0xFFFF0000
    return x & 0xFFFF0000


def strict_one(x):
    """immediates kept except address-ish ones (lui, $gp offsets, branches)."""
    op = x >> 26
    rs = (x >> 21) & 31
    if op in (0x02, 0x03):
        return x & 0xFC000000
    if op == 0x01 or 0x04 <= op <= 0x07:
        return x & 0xFFFF0000
    if op == 0x0F:
        return x & 0xFFFF0000
    if rs == 28:
        return x & 0xFFFF0000
    return x


def segments(path):
    elf = path.read_bytes()
    phoff, phnum = struct.unpack_from("<I", elf, 0x1C)[0], struct.unpack_from("<H", elf, 0x2C)[0]
    segs = []
    for i in range(phnum):
        kind, off, va, _, size = struct.unpack_from("<5I", elf, phoff + 32 * i)
        if kind == 1:
            segs.append((va, off, size))
    return elf, segs


def main():
    name = sys.argv[1]
    mask_name, level_want = "loose", None
    if "--mask" in sys.argv:
        mask_name = sys.argv[sys.argv.index("--mask") + 1]
    if "--level" in sys.argv:
        level_want = int(sys.argv[sys.argv.index("--level") + 1])
    mask = loose_one if mask_name == "loose" else strict_one

    row = next(r for r in levels.read_catalogue() if r[0] == name)
    kind, size, places = row[1], row[2], row[4]
    number, address = places[0]
    base, data = levels.level_text(MASTER / "baserom/levels" / levels.level_dir(number))
    address, size = levels.level_extent(number, address, size)
    needle = words(data[address - base: address - base + size])
    needle_m = [mask(x) for x in needle]
    print(f"# {name}: {size} bytes, {len(needle)} words, from level {number:02d}")

    for directory in sorted(RAC1.iterdir()):
        if level_want is not None and not directory.name.startswith(f"{level_want}_"):
            continue
        elf_path = directory / "build" / "overlay.elf"
        if not elf_path.is_file():
            continue
        elf, segs = segments(elf_path)
        for va, off, n in segs:
            hay = words(elf[off:off + n])
            hay_m = [mask(x) for x in hay]
            first, ln = needle_m[0], len(needle_m)
            for i in range(0, len(hay_m) - ln + 1):
                if hay_m[i] == first and hay_m[i:i + ln] == needle_m:
                    print(f"{directory.name}: VA {va + 4 * i:#010x} (file off {off + 4 * i:#x})")


if __name__ == "__main__":
    main()
