#!/usr/bin/env python3
"""Every instruction in a level's text whose branch/jump target is ADDRESS.

  python3 scratch/whotargets.py 0 0x0035CC98 [...]
"""
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402


def target(word, addr):
    op = (word >> 26) & 0x3F
    imm = word & 0xFFFF
    if imm & 0x8000:
        imm -= 0x10000
    if op in (0x02, 0x03):
        return ((addr + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
    if op in (0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17,
              0x08, 0x09, 0x10, 0x11, 0x12, 0x13):
        return addr + 4 + (imm << 2)
    return None


def main():
    level = int(sys.argv[1])
    base, data = levels.level_text(MASTER / "baserom/levels" / levels.level_dir(level))
    for spec in sys.argv[2:]:
        address = int(spec, 16)
        hits = []
        for i in range(0, len(data) - 3, 4):
            word = int.from_bytes(data[i:i + 4], "little")
            if target(word, base + i) == address:
                hits.append(f"{base + i:#010x} 0x{word:08X}")
        print(f"level {level:02d} -> {address:#010x}: " + (", ".join(hits) if hits else "no branch or jump targets it"))


if __name__ == "__main__":
    main()
