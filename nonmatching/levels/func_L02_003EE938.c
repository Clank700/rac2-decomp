/* 0 of 1 places match - candidate is 416 bytes = retail (104 instructions); the frame, the
   decision tree, every branch, every call and every constant match, and only FOUR words differ
   (+0x84..+0x94, the arguments of the func_00283CF0 call in case 0 of the switch):
       retail:  lwc1 $f0,0x2C($s1) ; lui $at,0x3FC0 ; mtc1 $at,$f12 ; jal ; mul.s $f12,$f0,$f12
       here:    lui $at,0x3FC0 ; mtc1 $at,$f0 ; lwc1 $f12,0x2C($s1) ; jal ; mul.s $f12,$f12,$f0
   i.e. the load comes second and the product shares the load's register instead of the
   constant's. File: src/levels/02_maktar_nebula/L02_003DB310.c (would be a unit of its own with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`). Checked with the master cc1 of 21 October.

   Cause, measured: retail's 16-byte copy (`lq $v0,0($v1) ; sq $v0,0($a0)` just before the
   load) is a SCHEDULING BARRIER. sched1 sees the load of state+0x2C as a true dependence on the
   copy (the rac2_qcopy insn writes memory), queues it, and fills the slot with the constant; the
   allocator then gives the first-born quantity (the constant) $f0 and ties the product to the
   load. Diagnostic only, never to be committed: with the copy written as
       __asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(arg0 + 0x10), "r"(state + 0x20)
                         : "$2", "memory");
   instead of the TI assignment (and no profile flag), this exact function reports
   "func_L02_003EE938: 1 of 1 places match". -frac2-qcopy gives the pair no barrier; a barrier
   variant of it is the lever (the same diagnostic matches func_L02_003F1A88 and
   func_L02_003E8CE8 as well).

   Source habits found on the way (they are in the C below): the clamp has to be
   `if (v >= 256) v = 255;` -- the ternary `(v < 256) ? v : 255` allocates the slti result to
   $a1 and swaps the two argument moves of the next call; `D_L02_001B30C8` needs
   `__attribute__((sda))` (the bare `lui`/`lw` pair is one scheduling unit, the plain extern is
   split in two and sorts differently); the pad is a struct view so the base of D_00138180 is
   built once for the two floats at +0x100/+0x104.
   Tried against the four words, no change: `1.5f * x` for `x * 1.5f`; the load into a local
   first; a const-qualified load; the load as a struct member read; an unprototyped
   `func_002A7750()`; `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-sched-interblock`. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    unsigned char pad[0x100];
    float f100;
    float f104;
} Pad003EE938;

extern void func_0029F338(char *);
extern void func_L02_003EEAD8(char *);
extern int func_00283CF0(float);
extern void func_002A7750(char *, int, int);
extern int func_L02_003EEFB8(char *);
extern float func_L02_003EEC58(char *);
extern void func_L02_003EEDD0(char *);
extern void func_002AA2E8(float *, float, float);
extern int D_L02_001B30C8 __attribute__((sda));
extern Pad003EE938 D_00138180;

/* The actor's state machine (byte at +0x20): 0 prepares it, 1 waits for the target to come within
   range on its own frame of eight, 2 follows the pad until the state asks to restart. */
void func_L02_003EE938(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    int v;

    switch (*(unsigned char *)(arg0 + 0x20)) {
    case 0:
        if (*(int *)state == -1) {
            func_0029F338(arg0);
            return;
        }
        func_L02_003EEAD8(arg0);
        *(TI128 *)(arg0 + 0x10) = *(TI128 *)(state + 0x20);
        v = func_00283CF0(*(float *)(state + 0x2C) * 1.5f);
        if (v >= 256)
            v = 255;
        *(unsigned char *)(arg0 + 0x30) = v;
        func_002A7750(arg0, 1, -1);
        return;
    case 1:
        if ((D_L02_001B30C8 & 7) == (((int)arg0 >> 8) & 7)) {
            if (func_L02_003EEFB8(arg0)) {
                func_002A7750(arg0, 2, -1);
                *(int *)(state + 0x34) = 0;
            }
        }
        return;
    case 2:
        *(float *)(state + 0x44) = func_L02_003EEC58(arg0);
        func_L02_003EEDD0(arg0);
        if (0.2f < D_00138180.f100 + D_00138180.f104)
            func_002AA2E8((float *)(state + 0x34), 0.0f, 0.33333334f);
        if (*(float *)(state + 4) + 1.0f < *(float *)(state + 0x44))
            func_002A7750(arg0, 1, -1);
        return;
    }
}
