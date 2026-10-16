#!/usr/bin/env python3
"""Docker-free multi-variant ruler: compile ONE .c holding SEVERAL variants with the WSL
compiler (scratch/wslcc.sh, Linux-native /tmp), then diff each .text.<fn> section against a
LEVEL function's retail bytes with the linker's relocation freedoms (the same rules as
tools/build.py Placement.derive). RULER ONLY -- tools/check.py decides a real match.

usage: cmp_w.py <file.c> <retail-name> [Ln] [flags="..."] [full] [only=a,b]
"""
import struct
import subprocess
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
ROOT = Path(r"D:/RAC2/worktrees/agent-lvl6-03")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402
import elf  # noqa: E402

WSL = ["wsl", "-d", "Ubuntu", "--"]
OUT = ROOT / "scratch" / "out"


def to_wsl(p: Path) -> str:
    p = Path(p)
    return "/mnt/" + p.drive[0].lower() + str(p)[2:].replace("\\", "/")


def place(name, level=None):
    for row in levels.read_catalogue():
        if row[0] == name:
            size, pl = row[2], row[4]
            if level is None:
                return size, min(pl)
            return size, next(p for p in pl if p[0] == level)
    raise SystemExit(f"{name}: not in the level catalogue")


def retail_words(name, level=None):
    size, (number, address) = place(name, level)
    skip = levels.LEVEL_ENTRY_OFFSETS.get((number, address), 0)
    address, size = address + skip, size - skip
    base, data = levels.level_text(levels.DUMP / levels.level_dir(number))
    body = data[address - base:address - base + size]
    return [int.from_bytes(body[i:i + 4], "little") for i in range(0, len(body), 4)], address


def compile_all(src: bytes, flags: str, tag: str) -> Path:
    OUT.mkdir(exist_ok=True)
    path = OUT / f"{tag}.o"
    srcp = OUT / f"{tag}.c"
    srcp.write_bytes(src)
    script = (f"bash '{to_wsl(ROOT / 'scratch' / 'wslcc.sh')}' '{to_wsl(srcp)}' "
              f"'{to_wsl(path)}' '{flags}'")
    r = subprocess.run(WSL + ["bash", "-c", script], capture_output=True, text=True)
    if r.returncode or "COMPILE_OK" not in (r.stdout or ""):
        print("COMPILE FAILED:")
        print((r.stdout or "")[-1200:])
        print((r.stderr or "")[-1200:])
        path.write_bytes(b"")
    return path


def dis(word):
    try:
        import rabbitizer
        return rabbitizer.Instruction(word).disassemble()
    except Exception:
        return f"{word:08X}"


def compare(section, relocs, symbols, retail):
    """derive()-style verdict: list of (offset, 'why') differences."""
    data = section["data"]
    touched = {}
    for at, kind, sym in relocs:
        touched.setdefault(at, (kind, sym))
    bad = []
    if len(data) != len(retail) * 4:
        bad.append((-1, f"size {len(data)} vs retail {len(retail) * 4}"))
    for at in range(0, min(len(data), len(retail) * 4), 4):
        mine = int.from_bytes(data[at:at + 4], "little")
        ref = retail[at // 4]
        if at in touched:
            kind, sym = touched[at]
            name = symbols[sym]["name"] if sym < len(symbols) else "?"
            if kind == elf.R_MIPS_26:
                if (mine ^ ref) & 0xFC000000:
                    bad.append((at, f"jump opcode differs (-> {name})"))
            elif kind in (elf.R_MIPS_HI16, elf.R_MIPS_GPREL16):
                if (mine ^ ref) & 0xFFFF0000:
                    bad.append((at, f"%hi/gp upper differs (-> {name})"))
            elif kind == elf.R_MIPS_LO16:
                if (mine ^ ref) & 0xFFFF0000:
                    bad.append((at, f"%lo upper differs (-> {name})"))
        elif mine != ref:
            bad.append((at, "word differs"))
    return bad


def main() -> int:
    args = sys.argv[1:]
    src = Path(args[0]).read_bytes()
    name = args[1]
    level = None
    flags = "-O2 -G0 -ffunction-sections"
    only = None
    full = "full" in args
    for a in args[2:]:
        if a.startswith("L") and a[1:].isdigit():
            level = int(a[1:])
        elif a.startswith("flags="):
            flags = a[6:]
        elif a.startswith("only="):
            only = a[5:].split(",")
    retail, address = retail_words(name, level)
    tag = Path(args[0]).stem
    obj = compile_all(src, flags, tag)
    if obj.stat().st_size == 0:
        return 1
    o = elf.read_object(obj)
    print(f"retail {name} @{address:#010x} {len(retail)} words | flags {flags}")
    for i, sec in enumerate(o["sections"]):
        if sec["type"] != 1 or not sec["name"].startswith(".text") or not sec["size"]:
            continue
        if only and not any(x in sec["name"] for x in only):
            continue
        bad = compare(sec, o["relocations"].get(i, []), o["symbols"], retail)
        print(f"{'OK ' if not bad else '   '}{sec['name']}  {sec['size']} bytes, {len(bad)} diff(s)")
        shown = 0
        for at, why in bad:
            if full or shown < 8:
                if at >= 0:
                    mine = int.from_bytes(sec["data"][at:at + 4], "little")
                    ref = retail[at // 4]
                    print(f"      +{at:4d}  retail {ref:08X} {dis(ref)}\n"
                          f"                mine  {mine:08X} {dis(mine)}   [{why}]")
                else:
                    print(f"      {why}")
                shown += 1
        if bad and not full and shown < len(bad):
            print(f"      ... {len(bad) - shown} more")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
