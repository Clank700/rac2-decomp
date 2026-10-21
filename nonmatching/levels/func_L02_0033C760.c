/* NEAR MISS: 336 bytes against retail's 340 (level 2 only). Builds a trail node (type 0x1E) from the point
   `pos` (or, without one, from the previous node `prev`, lowered by 0.15 in y), links it behind `prev`, and
   returns it; `flag` set keeps the node's life at 1/0, clear makes it 0xFF.
   Needs the `-frac2-qcopy` profile (the 16-byte copies go through register addresses): a unit of its own,
   src/levels/02_maktar_nebula/L02_0033C760.c, with the config/cflags.txt line
   `-O2 -G0 -ffunction-sections -frac2-qcopy`. Everything matches except two scheduling choices around the
   grouped lq/sq pairs, 4 words in all:
   (1) in the `pos` arm retail has `lq/sq`, then `addiu $a0,$zero,1`, then the `b` with the `sh` in its slot;
       here the `li` is scheduled above the pair (the pair needs `addiu $v1,$s0,0x10` first, and the scheduler
       fills that gap with the independent `li`);
   (2) in the `prev` arm retail loads `lwc1 $f0,0x18($s0)` right after the pair and the 0.15 constant after
       it (so the assembler pads the `sub.s` with a nop: 340 bytes); here the constant (`lui/ori/mtc1`) is
       issued first, in the cycle of the pair, and the load follows, which needs no nop.
   Both are what retail would give if its lq/sq pairs were scheduling barriers (inline-asm copies): nothing
   after the pair moves above it and no gap in front of the pair is filled.
   What was needed and kept: `ptail = prev + 0x20;` written BEFORE the `if (node[2] == prev[2])` (a different
   extended basic block from its use, so cse does not fold `ptail + 0x14` into `prev + 0x34` and retail's
   `addiu $a0,$s2,0x20` / `sw $s0,0x14($a0)` come out); D_L02_00200080 is a record whose word at +0x78 points
   to a byte table (retail reaches it through `addiu $a1,$v0,0x80` twice).
   Tried without effect: -fno-schedule-insns, -fno-schedule-insns2, -fno-sched-interblock, -fno-sched-spec,
   the flag store before the copy (worse), the float read through a temporary or a float pointer, storing
   `pos != 0` instead of 1 (worse: sltu and other registers). */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern char *func_002B9030(int);

extern int func_00283CF0(float);

typedef struct {
    u8 pad00[0x78];
    u8 *ids;
} L02_Palette;

extern L02_Palette D_L02_00200080;

char *func_L02_0033C760(TI128 *pos, char *prev, int flag, float scale) {
    char *node = func_002B9030(0x1E);
    char *tail;
    char *ptail;

    if (node != 0) {
        tail = node + 0x20;
        *(int *)(node + 4) = 0x80808080;
        *(u8 *)(node + 9) = func_00283CF0(4.0f) + 0x40;
        *(u8 *)(node + 3) = 0x44;
        *(u8 *)(node + 8) = 0x20;
        *(float *)(node + 0xC) = scale * 210000.0f;
        *(u8 *)(node + 1) = 0;
        if (pos != 0) {
            *(TI128 *)(node + 0x10) = *pos;
            *(short *)(tail + 0x1E) = 1;
        } else {
            *(TI128 *)(node + 0x10) = *(TI128 *)(prev + 0x10);
            *(float *)(node + 0x18) -= 0.15f;
            *(short *)(tail + 0x1E) = 0;
        }
        if (flag == 0)
            *(short *)(tail + 0x1E) = 0xFF;
        *(u8 *)(node + 2) = D_L02_00200080.ids[0];
        if (prev != 0) {
            ptail = prev + 0x20;
            if (*(u8 *)(node + 2) == *(u8 *)(prev + 2))
                *(u8 *)(node + 2) = D_L02_00200080.ids[1];
            *(char **)(tail + 0x10) = prev;
            *(char **)(ptail + 0x14) = node;
        } else {
            *(char **)(tail + 0x10) = 0;
        }
    }
    return node;
}
