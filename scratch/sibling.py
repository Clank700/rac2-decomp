#!/usr/bin/env python3
"""Find the other names of a shared level function, and whether one is already matched.

A shared function has one catalogue row with one place per program, and each program's
source file may carry it under its own name (func_L09_003C8CD8 for func_L00_003C2F10).
Those per-level names are what a sibling copy in another level's file is called.

  python scratch/sibling.py func_L00_003C2F10 [more names...]
"""
import re
import sys
from pathlib import Path

WORKTREE = Path(r"D:/RAC2/worktrees/agent-lvl-08")
MASTER = Path(r"D:/RAC2/master")
CATALOGUE = MASTER / "config/levels/functions.tsv"
NAMES = {0: "aranos_tutorial", 1: "oozla", 2: "maktar_nebula", 3: "endako", 4: "barlow",
         5: "feltzin_system", 6: "notak", 7: "siberius", 8: "tabora", 9: "dobbo",
         10: "hrugis_cloud", 11: "joba", 12: "todano", 13: "boldan", 14: "aranos_prison",
         15: "gorn", 16: "snivelak", 17: "smolg", 18: "damosel", 19: "grelbin",
         20: "yeedil", 22: "dobbo_orbit", 23: "damosel_orbit", 24: "ship_shack",
         25: "wupash_nebula", 26: "jamming_array", 30: "insomniac_museum"}


def rows():
    for line in CATALOGUE.read_text().splitlines():
        if line.startswith("#"):
            continue
        name, kind, size, fp, _, places = line.split("\t")
        yield name, kind, int(size), fp, [(int(p.split(":")[0]), int(p.split(":")[1], 16))
                                          for p in places.split(",")]


def find(name, needle):
    """Where NEEDLE appears in the worktree's C sources, and whether it is defined there."""
    hits = []
    for path in sorted((WORKTREE / "src").rglob("*.c")):
        text = path.read_text(errors="replace")
        if needle not in text:
            continue
        # defined = a line that starts a body (no trailing semicolon, not INCLUDE_ASM)
        defined = any(re.match(rf"^(?:[A-Za-z_][^;=#]*?\b)?{needle}\s*\(", ln)
                      and not ln.rstrip().endswith(";") and not ln.startswith(("extern", "typedef"))
                      for ln in text.splitlines())
        hits.append((path.relative_to(WORKTREE), defined))
    return hits


def main():
    for name in sys.argv[1:]:
        row = next((r for r in rows() if r[0] == name), None)
        if row is None:
            print(f"{name}: not in the catalogue")
            continue
        _, kind, size, fp, places = row
        print(f"{name}  {kind} {size} bytes  fp={fp}  {len(places)} places")
        for lv, addr in sorted(places):
            alt = f"func_L{lv:02d}_{addr:08X}"
            hits = find(name, alt) if alt != name else find(name, name)
            for path, defined in hits:
                print(f"    {lv:02d} {NAMES[lv]:20s} {alt}  -> {path}{'  [DEFINED]' if defined else ' (declared only)'}")


if __name__ == "__main__":
    main()
