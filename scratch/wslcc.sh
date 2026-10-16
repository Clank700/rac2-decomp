#!/usr/bin/env bash
# Compile one C file with the game's 32-bit Linux compiler, from inside WSL, without Docker.
#
#   bash /mnt/d/RAC2/worktrees/agent-lvl6-04/scratch/wslcc.sh <source.c> <out.o> [flags]
#
# Everything (source, headers, compiler, output) works in /tmp, a Linux-native tmpfs: the
# 32-bit cc1/cpp cannot stat drvfs files ("Value too large for defined data type"), which is
# why tools/docker/run.sh runs them on a docker volume. Only the finished object is copied
# back to the drvfs path given as <out.o>, by 64-bit cp.
set -e
SRC="$1"
OUT="$2"
FLAGS="${3:--O2 -G0 -ffunction-sections}"
CCTOOLS=/mnt/d/RAC2/master/build/compiler/tools
W=/tmp/rac2w
C=$W/cc
mkdir -p "$C" "$W/inc"
for t in cpp cc1 as; do
  [ -x "$C/$t" ] || cp -f "$CCTOOLS/$t" "$C/$t"
  chmod +x "$C/$t"
done
cp -rf /mnt/d/RAC2/worktrees/agent-lvl6-04/include/. "$W/inc/"
cp -f "$SRC" "$W/x.c"
cd "$W"
"$C/cpp" -I"$W/inc" -I"$W" "$W/x.c" > "$W/x.i"
"$C/cc1" -quiet $FLAGS "$W/x.i" -o "$W/x.s"
"$C/as" -o "$W/x.o" "$W/x.s"
cp -f "$W/x.o" "$OUT"
echo "wslcc sizes: c=$(wc -c < "$W/x.c") i=$(wc -c < "$W/x.i") s=$(wc -c < "$W/x.s") o=$(wc -c < "$W/x.o")"
echo "wslcc funcs: $(grep -c '^\.section \.text\.' "$W/x.s" || true)"
echo COMPILE_OK
