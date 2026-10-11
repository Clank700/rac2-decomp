# Building

The build disassembles the retail programs, links the C in `src/` in place of the matching
assembly, and compares every loaded byte with the retail programs. Everything it needs
from the game comes from your own disc; nothing game-derived is committed.

## What you need

- A disc image of **Ratchet & Clank: Going Commando, USA v1.01** (`SCUS_972.68`), as
  `baserom/SCUS_972.68.iso`. SHA-256
  `9db2e33e276133cc283647fa3279b37911955e123d6199d10065547eaa9b1ce5`.
- Python 3.12 with `pip install -r requirements.txt` (splat, spimdisasm, rabbitizer).
- **SN ProDG 2.0**'s assembler and linker as `toolchain/sn-prodg-2.0/ee/bin/Ps2EeAs.exe`
  (SHA-256 `c839dd63…`, `ps2eeas.exe` in the `eegcc_sn_v2.73a` archive) and `ld.exe`
  (`80f3724a…`, the SN ProDG 3.01 linker). Proprietary: bring your own, never commit them.
- An x86-64 Linux environment with 32-bit support (`gcc -m32`) for the compilers, and Wine
  for the SN tools.

## Steps

```sh
python3 tools/levels.py dump          # baserom/SCUS_972.68 and the 27 level programs
tools/compiler/build.sh               # the game's compiler, into build/compiler/tools/
python3 tools/compiler/sdk/build.py   # the SDK units' compiler, into build/compiler/sdk/
python3 tools/build.py all            # build and compare the boot and all 27 levels
python3 tools/progress.py             # progress/report.json
```

`tools/build.py boot`, `tools/build.py level 4` and `tools/build.py levels` build a part.
Each program prints `OK` with its C functions, or stops at the first byte that differs.
A C function that does not match where the catalogue places it is listed with the reason
and stays assembly there; the program still has to come out equal.

## On macOS (Apple Silicon) and other hosts

The compilers are 32-bit Linux programs and the SN tools are 32-bit Windows programs. Two
containers run them; mount the repository at the same path in both:

```sh
docker run -d --init --name rac2-gnu --platform linux/amd64 --tmpfs /rac2tmp:exec \
  -v "$PWD:$PWD" ubuntu:24.04 sleep infinity          # then: apt install gcc-multilib make git python3
docker run -d --init --name rac2-wine --platform linux/386 -v "$PWD:$PWD" <an i386 Wine image> sleep infinity
docker exec -w "$PWD" -e WORK=/rac2tmp/cc rac2-gnu tools/compiler/build.sh
docker exec -w "$PWD" rac2-gnu python3 tools/compiler/sdk/build.py --work /rac2tmp/sdk
RAC2_LINUX="docker exec rac2-gnu" RAC2_WINE="docker exec -w {cwd} rac2-wine wine" \
  python3 tools/build.py all
```

`RAC2_LINUX` prefixes the compiler commands and `RAC2_WINE` the SN tools (`{cwd}` becomes
the directory they run in). On x86-64 Linux with Wine installed, neither is needed. Rosetta
cannot run 32-bit Wine, hence the `linux/386` container.

## The compilers

- **The game's code**: GNU EE-GCC 2.9-ee-991111b rebuilt from its public source with
  Lombyte's patch stack and the transformers this project measured
  ([tools/compiler/](../tools/compiler/README.md)). The build stops unless the five patched
  sources hash as recorded; the binaries' own hashes depend on the host, so a compiler is
  checked by its output.
- **The boot's SDK units** (the `src/core/` files `config/cflags.txt` marks `sdk`): Sony EE-GCC 2.9-ee-991111-01, unmodified, from
  the public SSXModding snapshot (`tools/compiler/sdk/build.py`), with `-O2 -g2 -gstabs`.

Flags are per file, never per function: `config/cflags.txt` (default
`-O2 -G0 -ffunction-sections`, `-G8` for a file named `*-g8.c`).
