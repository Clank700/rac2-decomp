# The game's C compiler

The retail code was built with GNU EE-GCC 2.9-ee-991111b. `build.sh` rebuilds its `cpp`,
`cc1` and `as` from the public source archive:

- `patches/`: Lombyte's `sce-991111b` stack (MIT, github.com/mateuszklysz/Lombyte) and the
  project's opt-in `0057` and `0058` extensions, applied in
  the order `build.sh` lists, with two pinned versions: `0034`, which Lombyte has since
  retired, and the earlier `0020` (Lombyte c260794). `0001` is applied and then reversed: the
  retail saves registers in 8-byte slots.
- `transformers/`: the source edits measured for this game, each a script carrying its exact
  replacement text, in the order `build.sh` runs them. `u3_frame_order_on.py` and
  `u4_mtc1_helper.py` are two earlier steps the later ones build on.

Patch `0057` adds the opt-in `-mastra-split-trunc-slot` switch. It splits the
two-word `truncdisi2` pattern after reload, before delay-slot scheduling, so
the sign-extension can occupy a return slot. The default compiler output is
unchanged. Use the switch only on a dedicated C file in `config/cflags.txt`;
`src/core/0012E8C8.c` is the measured witness.

Patch `0058` adds the opt-in `-mastra-quad-saves` switch. It widens every GPR save slot to
TImode, so the prologue and the epilogue emit `sq`/`lq` as the two measured `src/core` units
are saved; without the switch the output is unchanged. Use it only on a dedicated C file in
`config/cflags.txt`; `src/core/00119BC8.c` is the measured witness.

`build.sh` stops unless `mips.c`, `mips.h`, `mips.md`, `toplev.c` and `tc-mips.c` hash as it
lists. The binaries' own hashes depend on the build host and path, so check a compiler by its
output: `tools/build.py` compiles every matched function to the retail bytes.
