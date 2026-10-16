#!/usr/bin/env python3
"""Multi-target variant ruler (worker lvl6-11).

Compile ONE scratch .c holding every candidate form in ONE container call, then diff each
.text.<name> section against the retail bytes of ITS OWN level function, with the linker's
relocation freedoms (same rules as tools/build.py Placement.derive). RULER ONLY --
tools/check.py in the container decides a real match.

usage: cmp11.py <variants.c> [map=a:func_L12_00425448:12,b:func_L23_0041E538:23,...]
                             [flags="-O2 -G0 -ffunction-sections"] [full] [only=a,b]

A variant function named `a1`, `a2` ... is matched by the mapping entry whose key is the
longest prefix of the section name (so map=a:... sends a1,a2,a3 to that target).
"""
import base64
import struct
import subprocess
import sys
from pathlib import Path

MASTER = Path(r"D:/RAC2/master")
sys.path.insert(0, str(MASTER / "tools"))
import levels  # noqa: E402
import elf  # noqa: E402

REPO = "/mnt/d/RAC2/worktrees/agent-lvl6-11"
WSL = ["wsl", "-d", "Ubuntu", "--", "env",
       f"RAC2_RUNTIME_ROOT={REPO}",
       "RAC2_RUNTIME_VOLUME=rac2-a00-w2",
       "CONTAINER_CLI=python3 /mnt/d/RAC2/work/master-migration-20261012/runtime/docker-wsl-cli.py"]
RUN = ["bash", f"{REPO}/tools/docker/run.sh"]
OUT = Path(__file__).resolve().parent / "out"


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
    if flags.startswith("sdk"):
        head = (f"{REPO}/build/compiler/sdk/xgcc -B{REPO}/build/compiler/sdk/ -S {flags[3:].strip()} "
                f"-I{REPO}/include -I{REPO}/build/compiler/sdk/include -I{REPO}/src/core x.c -o x.s")
    else:
        head = (f"{REPO}/build/compiler/tools/cpp -I{REPO}/build/compiler/tools/include "
                f"-I{REPO}/include -I{REPO}/src/core x.c > x.i; "
                f"{REPO}/build/compiler/tools/cc1 -quiet {flags} x.i -o x.s")
    b64 = base64.b64encode(src).decode()
    pack = ("python3 -c \"import base64,struct; s=open('x.s','rb').read(); o=open('x.o','rb').read(); "
            "print(base64.b64encode(struct.pack('<I',len(s))+s+o).decode())\"")
    inner = ("set -e; mkdir -p /tmp/shape11; cd /tmp/shape11; "
             f"echo {b64} | base64 -d > x.c; {head}; "
             f"{REPO}/build/compiler/tools/as -o x.o x.s; {pack}")
    proc = subprocess.run([*WSL, *RUN, "bash", "-c", inner], capture_output=True, text=True)
    path = OUT / f"{tag}.o"
    lines = [ln.strip() for ln in proc.stdout.splitlines() if len(ln.strip()) > 100]
    if proc.returncode or not lines:
        print("CONTAINER FAILED:", (proc.stderr or "")[-2000:], (proc.stdout or "")[-600:])
        path.write_bytes(b"")
    else:
        blob = base64.b64decode(lines[-1])
        n = struct.unpack_from("<I", blob, 0)[0]
        (OUT / f"{tag}.s").write_bytes(blob[4:4 + n])
        path.write_bytes(blob[4 + n:])
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
            # R_MIPS_32: free
        elif mine != ref:
            bad.append((at, "word differs"))
    return bad


def main() -> int:
    args = sys.argv[1:]
    srcpath = Path(args[0])
    targets = []          # (prefix, name, level)
    flags = "-O2 -G0 -ffunction-sections"
    only = None
    full = "full" in args
    for a in args[1:]:
        if a.startswith("map="):
            for item in a[4:].split(","):
                parts = item.split(":")
                if len(parts) == 2:
                    targets.append((parts[0], parts[1], None))
                else:
                    targets.append((parts[0], parts[1], int(parts[2])))
        elif a.startswith("flags="):
            flags = a[6:]
        elif a.startswith("only="):
            only = a[5:].split(",")
    if not targets:
        print("no map= given")
        return 2
    cache = {}
    for _p, name, lv in targets:
        if name not in cache:
            cache[name] = retail_words(name, lv)
    tag = srcpath.stem
    obj = compile_all(srcpath.read_bytes(), flags, tag)
    if obj.stat().st_size == 0:
        return 1
    o = elf.read_object(obj)
    print(f"=== {srcpath.name} | flags {flags} | {len(o['sections'])} sections")
    for i, sec in enumerate(o["sections"]):
        if sec["type"] != 1 or not sec["name"].startswith(".text") or not sec["size"]:
            continue
        short = sec["name"].split(".text.")[-1]
        if only and not any(x in short for x in only):
            continue
        hit = None
        for p, name, lv in targets:
            if short == p or short.startswith(p):
                if hit is None or len(p) > len(hit[0]):
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
        if full and bad:
            for at in range(0, min(len(sec["data"]), len(retail) * 4), 4):
                mine = int.from_bytes(sec["data"][at:at + 4], "little")
                ref = retail[at // 4]
                print(f"   {'  ' if mine == ref else '!!'} +{at:4d}  retail {ref:08X} {dis(ref):<40} mine {mine:08X} {dis(mine)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
