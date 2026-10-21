/* 0 of 1 places match - candidate is 420 bytes = retail (105 instructions); the frame, the saves'
   registers, the two branches, every call, every constant and the three-instruction division
   site (`nop ; nop ; div.s`, which needs -g) match; about 30 words differ, ALL of them order:
     +0x04..+0x2C  the head: retail loads the entity table base first (`lui $a1 ; lw $a1`),
                   copies actor+0x10 with lq/sq, then builds the address of D_00189E20 and loads
                   the float at $gp+0x1C10; this cc1 hoists the $gp float and the base load over
                   the copy and builds the player address twice (`lui $a1` + `addiu`) so the
                   16-byte copy moves 9 words down;
     +0x68..+0xB4  the two arms of the `if`: retail `daddu $v1,$s0,$zero` in the delay slot of
                   the `b` and `addiu $v1,$sp,0x10 ; lq ; sq` in the else arm, with ONE
                   `daddu $a2,$v1,$zero` after the join; this cc1 puts the join value in $a2 in
                   both arms (`daddu $a2,$s0,$zero` / `daddu $a2,$v1,$zero`).
   File: would be src/levels/02_maktar_nebula/L02_003E8CE8-g8.c with `-O2 -G8
   -ffunction-sections -g -frac2-qcopy` (-G8 for the four $gp floats, -g for the division's
   nops, as func_L02_003EEAD8 has it). Checked with the master cc1 of 21 October.

   Cause, measured: retail's two 16-byte copies are SCHEDULING BARRIERS. Diagnostic only, never to
   be committed: with both copies written as
       __asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(dst), "r"(src) : "$2", "memory");
   (dst/src = pos, arg0 + 0x10 and vec, pos) and no profile flag, this exact body (with the
   constant below) reports "func_L02_003E8CE8: 1 of 1 places match": the head, the join copy
   through $v1 and the placement of every float load all come out as retail's. -frac2-qcopy
   groups the lq/sq pair and clobbers $v0 but adds no barrier. The same diagnostic matches
   func_L02_003F1A88 and func_L02_003EE938; a barrier variant of -frac2-qcopy is the lever.

   Source habits found on the way (in the C below): D_L02_001B359C as `[3] __attribute__((sda))`
   read as [0] (a bare `lui`/`lw`; the plain `sda` word comes out `lw $a2,0($gp)`); a struct
   view of D_00189E20 so one `lui`/`addiu` serves the +0x5C0 load and the +0xE0 argument; the
   join pointer assigned AFTER the `if` (`q = vec;`), which gives the right word count (420; a
   `q = vec` inside each arm gives 416); the constant 1/3600 = 0x3991A2B4 (0.00027777778f).
   Tried against the order differences, no change: `q` through a block-local pointer in each
   arm; `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-sched-interblock`. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    unsigned char pad000[0xE0];
    float vecE0[4];
    unsigned char pad0F0[0x5C0 - 0xF0];
    char *target5C0;
} Player003E8CE8;

extern char *D_L02_001B359C[3] __attribute__((sda));
extern float D_L02_001B0C00 __attribute__((sda));
extern float D_L02_001B0C04 __attribute__((sda));
extern float D_L02_001B0C08 __attribute__((sda));
extern float D_L02_001B0C0C __attribute__((sda));
extern Player003E8CE8 D_00189E20;

extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002AA2E8(float *, float, float);

/* Steers the entity named by the state's first word toward the actor's position (lifted by
   D_L02_001B0C00): when it is the entity the player holds, the offset is first eased through
   func_002AA2E8; the entity's position then gets a spring term (distance times 1/3600 times
   D_L02_001B0C08) and a damping term (the speed over D_L02_001B0C0C) added to the velocity at
   state+0x10, and the velocity added to the position. */
void func_L02_003E8CE8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    char *target = D_L02_001B359C[0] + (*(int *)state << 8);
    float pos[4];
    float vec[4];
    float diff[4];
    float spring[4];
    float damp[4];
    float step;
    float *q;
    float a;
    float b;

    *(TI128 *)pos = *(TI128 *)(arg0 + 0x10);
    pos[2] += D_L02_001B0C00;
    if (D_00189E20.target5C0 == target) {
        func_00282CF0(vec, D_00189E20.vecE0, pos);
        step = func_00282DF0(vec);
        func_002AA2E8(&step, 0.1f, D_L02_001B0C04);
        func_00282F20(vec, vec, step);
        func_00282CC0(vec, vec, pos);
    } else {
        *(TI128 *)vec = *(TI128 *)pos;
    }
    q = vec;
    func_00282CF0(diff, target + 0x10, q);
    a = func_00282DF0(diff);
    b = func_00282DF0(state + 0x10);
    a = a * 0.00027777778f;
    b = b / D_L02_001B0C0C;
    func_00282F20(spring, diff, -(D_L02_001B0C08 * a));
    func_00282F20(damp, state + 0x10, -b);
    func_00282CC0(state + 0x10, state + 0x10, spring);
    func_00282CC0(state + 0x10, state + 0x10, damp);
    func_00282CC0(target + 0x10, target + 0x10, state + 0x10);
}
