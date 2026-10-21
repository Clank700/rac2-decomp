/* Near miss, 2026-10-21, in a unit of its own built with -O2 -G8 -ffunction-sections -frac2-qcopy
 * (a `-g8.c` file; the body reads and writes $gp data): 428 bytes, retail 428; 0 of 1 places match
 * (28 differing words of 107 in a longest-common-subsequence comparison).
 *
 * KNOWN WALL 2: what differs is register allocation and order around retail's grouped 16-byte
 * copy, which is a scheduling barrier, and `-frac2-qcopy` is not. Retail copies state + 0x20 into
 * D_L02_00249090 with `lq $v0,0($s1)` / `sq $v0,0($a0)`; what follows it in retail (the address
 * pairs of the other three arrays, `daddu $s6,$s0,$zero`, the counter init `addiu $s0,$zero,0x12`)
 * stays behind that pair, so `&v1` (`addiu $s0,$sp,0x10`) is still in $s0 across the call to
 * func_00282F20 (and copied to $s6 after the copy) and the counter takes $s0 only then. Here the
 * first scheduler hoists the `&v1` copy above that call (so `&v1` lives in $a0) and `$s5 = 0x12` to
 * the top of the block (a long live range, so the counter gets the lowest priority and $s5), and the
 * saved registers rotate: state + 0x20 lands in $s0 where retail has $s1.
 *
 * Proof that nothing else is missing: a SCRATCH copy of this file (never for src/) with the TI128
 * assignment replaced by
 * `asm volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(D_L02_00249090[0]), "r"(state + 0x20) : "$2", "memory")`
 * gives tools/check.py's own verdict (Placement.derive): `func_L02_003E9040: 1 of 1 places match`.
 * Unblocking this one needs a barrier form of the quadword copy (the wall's compiler-side fix).
 *
 * Source shapes that mattered (all in the candidate below): `state` is loaded before the flag test
 * (otherwise the first `beqz` takes `sd $ra` in its slot instead of `lw $a1,0x68($a0)`); the first
 * loop runs i = 1..19 over A[i] and A[i - 1] (with i = 0..18 and A[i + 1], cse shares `i + 1` with
 * the increment across the first call, loop.c finds no biv and keeps `sll`/`addu` index arithmetic:
 * 408 bytes and a bigger frame); the halfword table is `sda` with a size over 8 bytes (bare `sh`
 * per store, each with its own `lui $at`); the small down-counter has its own variable and the -1
 * is a variable (`addiu $a0,$zero,-1` before `addiu $v1,$zero,3`); the eight halfword stores are
 * written in the order that this scheduler turns into retail's (0 4 1 2 5 6 3 7 of the table). Tried
 * without effect: a pointer variable for &v1 before, around or after the call, the two vectors in
 * one local struct, the copy before the scale call, the scale in a temporary, v1 declared first,
 * -fno-schedule-insns (38 differing words against 28), -fno-schedule-insns2, -frac2-gcse-unsplit-edges,
 * -frac2-keep-block-order, -fno-gcse, -fno-strength-reduce, -fno-sched-interblock, and every order
 * of the three stores before the first call.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L02_001B0BA4 __attribute__((sda));

extern int D_L02_001B0CA8 __attribute__((sda));

extern float D_L02_001B0BA8 __attribute__((sda));

extern int D_L02_001B4208;

extern int D_L02_001B420C;

extern float D_L02_00249090[20][4];

extern int D_L02_00249310[20];

extern float D_L02_00249360[20][4];

extern int D_L02_002494A0[20];

extern short D_L02_001B41E8[4];

extern short D_L02_001B41F8[8] __attribute__((sda));

extern int D_L02_001B0C28 __attribute__((sda));

extern int D_L02_001B0C30 __attribute__((sda));

extern int D_L02_001B0C44 __attribute__((sda));

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern void func_00282CC0(void *, void *, void *);

extern void func_00282C88(void *);

void func_L02_003E9040(char *arg0) {
    char *state;
    float v0[4];
    float v1[4];
    int i;
    int j;
    short m1;

    state = *(char **)(arg0 + 0x68);
    if (D_L02_001B0BA4 != 0) {
        D_L02_001B4208 = D_L02_001B0CA8;
        D_L02_001B0BA4 = 0;
        D_L02_001B420C = 0;
        func_00282CF0(v0, state + 0x30, state + 0x20);
        func_00282F20(v1, v0, D_L02_001B0BA8 * 0.05f);
        *(TI128 *)D_L02_00249090[0] = *(TI128 *)(state + 0x20);
        for (i = 1; i < 20; i++) {
            func_00282CC0(D_L02_00249090[i], D_L02_00249090[i - 1], v1);
            D_L02_00249310[i] = 0;
            func_00282C88(D_L02_00249360[i]);
            D_L02_002494A0[i] = 0;
        }
        m1 = -1;
        for (j = 3; j >= 0; j--)
            D_L02_001B41E8[j] = m1;
        D_L02_001B41F8[0] = 8;
        D_L02_001B41F8[4] = 4;
        D_L02_001B41F8[1] = 4;
        D_L02_001B41F8[2] = 8;
        D_L02_001B41F8[5] = 2;
        D_L02_001B41F8[6] = 4;
        D_L02_001B41F8[3] = 4;
        D_L02_001B41F8[7] = 2;
        D_L02_001B0C28 = 0;
        D_L02_001B0C30 = 0;
        D_L02_001B0C44 = 0;
    }
}
