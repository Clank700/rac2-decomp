/* 0 of 1 places match - candidate is 252 bytes = retail (63 instructions); the frame, the three
   stack vectors (sp+0x00 / 0x10 / 0x20), the registers ($s1 = pos, $s0 = tmp, $s2 = count, the
   count-down copy in $s0 beside it), the loop (`blez` guard, `bnez` at the bottom with the
   `lwc1 $f12` in its delay slot), every call, every $gp float and every constant match. What
   differs is the head, about 25 words, in two layers:
     1. `por $v0,$zero,$zero` ... `sq $v0,0($sp)` (retail: the zero is built as the second
        instruction and stored after the saves) against `sq $zero,0($sp)` here. Everything
        after it is one word off (retail has no `nop` before the loop, this body has one:
        the assembler aligns the loop label, the `por` it lacks moved it);
     2. the order of the saves and of the first loads (retail: sd $s1, sd $s2, addiu $s1,
        daddu $s2, sd $s0, sd $ra, swc1 $f20, then the zero store, lq, sq, lwc1).
   File: would be src/levels/02_maktar_nebula/L02_003DBA70-g8.c with `-O2 -G8
   -ffunction-sections -frac2-qcopy` (the g8 sibling already declares it as
   `extern void func_L02_003DBA70();`, called by func_L02_003DB9E0 with (char *, int)). Checked
   with the master cc1 of 21 October.

   Cause of layer 2, measured: retail's 16-byte copy is a SCHEDULING BARRIER. Diagnostic only,
   never to be committed: with the copy written as
       __asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(pos), "r"(arg0)
                         : "$2", "memory");
   instead of the TI assignment (and no profile flag), the head comes out in retail's order
   word for word; only layer 1 remains. -frac2-qcopy has no barrier; the same diagnostic
   matches func_L02_003F1A88, func_L02_003EE938 and func_L02_003E8CE8 outright.

   Cause of layer 1: tools/compiler/transformers/fold_zero_ti_store.py. The pass turns a
   `por`-built zero into `sq $zero` when the store's address is a bare register, the register is
   dead after the store and the `por` is within twelve instructions above it. Here the store is
   `(mem:TI (reg sp))` -- a frame slot at offset 0, which is a bare register -- so it folds,
   while retail keeps `por` + `sq $v0,0($sp)` (the pass's own comment says the retail forms
   with an offset keep the `por`; a stack slot at offset 0 is the counter-example). Tried to
   keep the `por`, none works: `TI128 zero = 0; *(TI128 *)vel = zero;`, a union { TI128 q;
   float f[4]; } for the vector, a TI128 local, `-frac2-zero-ti-barrier` (still `sq $zero`;
   it reschedules the store but does not stop the fold). Making the slot's offset non-zero
   keeps the `por` (witnesses L00_003ACC88, L20_0044AB68) but moves the whole frame.

   Source habits found on the way (in the C below): the three vectors must be `float x[4]`
   arrays declared in stack order (a TI128 local gets its slot by first use and the order
   comes out wrong); `for (i = 0; i < arg1; i++)` is what gives retail's count-down copy in a
   second register (`for (i = arg1; i > 0; i--)` and `n = arg1; while (n > 0) { n--; ... }`
   decrement the argument's own register and put `&pos` in the spare one); the table at D_L02_001B0500 is passed as
   `D_L02_001B0500` with a 4-byte `sda` declaration (the 24-byte declaration builds the address
   with lui/addiu instead of `addiu $a2,$gp,0x1510`). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L02_001B0518 __attribute__((sda));
extern float D_L02_001B051C __attribute__((sda));
extern float D_L02_001B0520 __attribute__((sda));
extern float D_L02_001B0524 __attribute__((sda));
extern float D_L02_001B0528 __attribute__((sda));
extern char D_L02_001B0500[4] __attribute__((sda));
extern char D_L02_001BA500[];

extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACB48(float *, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void *func_L02_003449D8(void *, void *, void *, void *, int);

/* Spawns arg1 particles at the point arg0 raised by D_L02_001B0524 and pushed along the vector
   from D_L02_001BA500, each with a random upward speed (a sixtieth of the range D_L02_001B051C ..
   D_L02_001B0520) and the particle kind that func_002A77E0 picks for 2. */
void func_L02_003DBA70(char *arg0, int arg1) {
    float vel[4];
    float pos[4];
    float tmp[4];
    int i;

    *(TI128 *)vel = 0;
    *(TI128 *)pos = *(TI128 *)arg0;
    pos[2] += D_L02_001B0524;
    pos[3] = 0;
    func_00282CF0(tmp, D_L02_001BA500, pos);
    tmp[2] = 0;
    func_00282F20(tmp, tmp, D_L02_001B0528);
    func_00282CC0(pos, pos, tmp);
    for (i = 0; i < arg1; i++) {
        func_002ACB48(pos, D_L02_001B0518);
        vel[2] = func_002A7878(D_L02_001B051C, D_L02_001B0520) * 0.016666668f;
        func_L02_003449D8(pos, vel, D_L02_001B0500, (void *)func_002A77E0(2), 1);
    }
}
