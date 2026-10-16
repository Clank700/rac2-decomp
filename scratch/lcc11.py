#!/usr/bin/env python3
"""Local (docker-free) variant ruler for level functions -- worker lvl6-11.

The wedged Docker daemon makes tools/docker/run.sh unusable, but the compiler in
D:/RAC2/master/build/compiler/tools is an i386 Linux ELF that WSL Ubuntu runs
directly. This compiles the variants in WSL and compares each .text.<name> section
against its retail function with the same relocation freedoms as tools/build.py
Placement.derive. RULER ONLY -- tools/check.py in the container stays the gate.

usage: lcc11.py <variants.c> [map=a:func_L12_00425448:12,b:...] [flags="..."] [full] [only=a,b]
"""
import struct
import subprocess
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402
import elf  # noqa: E402

TOOLS = "/mnt/d/RAC2/master/build/compiler/tools"
ROOT = "/mnt/d/RAC2/worktrees/agent-lvl6-11"
WORK = Path(r"D:/RAC2/work/agent11")


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


def compile_wsl(src: Path, flags: str, out: Path) -> bool:
    dest = str(out).replace(chr(92), "/").replace("D:", "/mnt/d")
    # The 32-bit cpp cannot stat files on /mnt/d (EOVERFLOW), so every input is staged
    # into WSL's ext4 /tmp once; only the finished object goes back to D:.
    inner = (
        "set -e; mkdir -p /tmp/lcc11; "
        "if [ ! -f /tmp/lcc11/.inc ]; then rm -rf /tmp/lcc11/incA; "
        f"cp -r {ROOT}/include /tmp/lcc11/incA; touch /tmp/lcc11/.inc; fi; "
        f"cd /tmp/lcc11; cp {ROOT}/scratch/{src.name} x.c; "
        f"{TOOLS}/cpp -I/tmp/lcc11/incA -I/tmp/lcc11 x.c > x.i; "
        f"{TOOLS}/cc1 -quiet {flags} x.i -o x.s; "
        f"{TOOLS}/as -o x.o x.s; "
        f"cp x.o {dest}"
    )
    proc = subprocess.run(["wsl", "-d", "Ubuntu", "--", "bash", "-c", inner],
                          capture_output=True, text=True)
    if proc.returncode:
        print("COMPILE FAILED:", (proc.stderr or "")[-1500:], (proc.stdout or "")[-400:])
        return False
    return True


def dis(word):
    try:
        import rabbitizer
        return rabbitizer.Instruction(word).disassemble()
    except Exception:
        return f"{word:08X}"


def compare(section, relocs, symbols, retail):
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
    src = Path(args[0])
    targets, flags, only = [], "-O2 -G0 -ffunction-sections", None
    full = "full" in args
    for a in args[1:]:
        if a.startswith("map="):
            for item in a[4:].split(","):
                p = item.split(":")
                targets.append((p[0], p[1], int(p[2]) if len(p) > 2 else None))
        elif a.startswith("flags="):
            flags = a[6:]
        elif a.startswith("only="):
            only = a[5:].split(",")
    if not targets:
        print("no map=")
        return 2
    cache = {}
    for _p, name, lv in targets:
        if name not in cache:
            cache[name] = retail_words(name, lv)
    out = WORK / f"{src.stem}.o"
    if not compile_wsl(src, flags, out):
        return 1
    o = elf.read_object(out)
    print(f"=== {src.name} | flags {flags}")
    for i, sec in enumerate(o["sections"]):
        if sec["type"] != 1 or not sec["name"].startswith(".text") or not sec["size"]:
            continue
        short = sec["name"].split(".text.")[-1]
        if only and not any(x in short for x in only):
            continue
        hit = None
        for p, name, lv in targets:
            if (short == p or short.startswith(p)) and (hit is None or len(p) > len(hit[0])):
                hit = (p, name, lv)
        if hit is None:
            print(f"   {sec['name']}  {sec['size']} bytes, NO TARGET")
            continue
        _p, name, lv = hit
        retail, address = cache[name]
        bad = compare(sec, o["relocations"].get(i, []), o["symbols"], retail)
        print(f"{'OK ' if not bad else '   '}{name} <- {short}  {sec['size']} bytes, {len(bad)} diff(s)")
        for at, why in bad[:8]:
            if at >= 0:
                mine = int.from_bytes(sec["data"][at:at + 4], "little")
                ref = retail[at // 4]
                print(f"      +{at:4d}  retail {ref:08X} {dis(ref)}\n"
                      f"                mine  {mine:08X} {dis(mine)}   [{why}]")
            else:
                print(f"      {why}")
        if full:
            for at in range(0, min(len(sec["data"]), len(retail) * 4), 4):
                mine = int.from_bytes(sec["data"][at:at + 4], "little")
                ref = retail[at // 4]
                print(f"   {'  ' if mine == ref else '!!'} +{at:4d}  retail {ref:08X} {dis(ref):<40} mine {mine:08X} {dis(mine)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
