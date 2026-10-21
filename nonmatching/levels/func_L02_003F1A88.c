/* 0 of 1 places match - candidate is 228 bytes = retail (57 instructions); 15 words differ, all
   of them ORDER (the frame, the registers, every operand and every call match):
     +0x14..+0x20  prologue saves: retail stores f21, f20, then $ra last; this cc1 stores $ra
                   right after the first move and f21, f20 after it;
     +0x60..+0x6C  the two constants of the second func_002A7878 call: retail loads -2.0 into
                   $f12 first and 2.0 into $f13 second, this cc1 the reverse;
     +0x7C..+0x88  after the second call retail runs lw $s0, the 8.0, addiu $v1, add.s $f20 and
                   then lq/sq; this cc1 starts with `mov.s $f12,$f21`;
     +0x98         the delay slot of the sin call: retail `mov.s $f12,$f21`, this cc1
                   `add.s $f20,$f0,$f1`;
     +0x9C..+0xA4  after the sin call: retail mul.s, lwc1, mov.s; this cc1 lwc1, mov.s, mul.s.
   File: src/levels/02_maktar_nebula/L02_003DB310.c (would be a unit of its own with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`). Checked with the master cc1 of 21 October.

   Cause, measured: retail's 16-byte copy is a SCHEDULING BARRIER, as the maintainers' inline-asm
   copy macro would be. Diagnostic only, never to be committed: with the copy written as
       __asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(state + 0x4A0), "r"(arg1)
                         : "$2", "memory");
   instead of the TI assignment (and no profile flag), this exact function reports
   "func_L02_003F1A88: 1 of 1 places match". Everything before the copy then stays before it
   (the add.s of the radius, the address, the loads) and everything after stays after, which is
   all four differences above; -frac2-qcopy groups lq/sq with a $v0 clobber but gives the pair no
   barrier ("No memory barrier is added"), so sched1/sched2 are free to move the neighbours.
   A barrier variant of -frac2-qcopy (the copy given the dependences, cost and unit of a
   volatile asm, as -frac2-zero-ti-barrier does for the clears) is the lever; the same asm
   diagnostic makes func_L02_003EE938 and func_L02_003E8CE8 match, and func_L02_003DBA70 match
   except for its unfolded zero (see their files).

   Tried, none changes the 15 words: loads as struct members (`arg0->x`, `arg1[0]`), const-
   qualified loads, `-fno-schedule-insns`, `-fno-schedule-insns2` (220 bytes),
   `-fno-sched-interblock`; without the profile the TI copy folds its offset into the sq
   (`sq $v0,0x4A0($s0)`, a different word count). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_00283248(float, float);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);

/* Moves the actor's effect point to a spot around the target position at arg1: the heading from
   the target to the actor plus up to a quarter turn either way, at a distance of 8 plus or minus
   2; the point is copied from arg1 into the state (+0x4A0) and then offset in x and y. */
void func_L02_003F1A88(char *arg0, char *arg1) {
    char *state;
    float angle;
    float radius;

    angle = func_00283248(*(float *)(arg0 + 0x10) - *(float *)arg1,
                          *(float *)(arg0 + 0x14) - *(float *)(arg1 + 4));
    angle += func_002A7878(-0.78539824f, 0.78539824f);
    radius = func_002A7878(-2.0f, 2.0f) + 8.0f;
    state = *(char **)(arg0 + 0x68);
    *(TI128 *)(state + 0x4A0) = *(TI128 *)arg1;
    *(float *)(state + 0x4A0) += radius * func_00283180(angle);
    *(float *)(state + 0x4A4) += radius * func_00283198(angle);
}
