/* NEAR MISS: 716 bytes, retail's 716, with -O2 -G0 -ffunction-sections -frac2-qcopy
   -frac2-zero-ti-barrier (a unit of its own, L02_003EAA68.c); 0 of 1 places match: 6 of the 179
   instructions differ, all of them in the entity branch of the first walk.

   Both profiles are needed. The zero clear at the top is retail's `sq $zero,0($sp)` followed at
   once by a reload of the group byte (-frac2-zero-ti-barrier). The copy of the entity's +0x10
   quadword into the +0x30 of its private data goes through register addresses (`addiu
   $a2,$s0,0x10 ; addiu $v1,$a0,0x30 ; lq $v0,0($a2) ; sq $v0,0($v1)`, -frac2-qcopy).

   What differs is the known wall (2): retail's copy is a scheduling barrier, which -frac2-qcopy
   is not. Retail computes `state + 0x24` (`addiu $v0,$s7,0x24`) AFTER the copy and the `lwc1`
   of arg0's +0xF8, and its `sw` is the delay slot of the `beqz`; here the scheduler fills an
   idle ALU slot while the entity's `lw` is in flight and hoists the `addiu` and the `sw` above
   the copy. The statement order below (+0x28 store, copy, +0x3C store) is the one that keeps
   the registers right under -qcopy ($a0 for the entity's state, $v0 for the sum) and gets the
   size; retail's own statement order, copy / +0x3C / +0x28, gives 708 bytes and 22 instructions
   off under -qcopy (the pointer is hoisted into $a0 and the entity's state lands in $a1).
   All six orders of the three stores were tried; the other five are 22 to 23 instructions off.

   Measured in a scratch copy that is NOT for src/: with the copy written as
   `asm volatile("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(dst), "r"(src) : "$2", "memory")` and
   retail's statement order (copy / +0x3C / +0x28), under -frac2-zero-ti-barrier only, the
   function is 716 of 716 bytes and Placement.derive reports OK at its one place. So the
   barrier is the only difference. Not helpful: -fno-schedule-insns (37 off),
   -fno-schedule-insns2 (16 off).

   What the body needed: both walks are the `for` list walks of this file with the second
   `p != 0` guard (the first walk enters through `b test`, the second one gets the loop test
   copied in front of it); D_L02_001B359C and D_L02_001B35B8 are `sda` arrays of unknown size
   read as [0] (bare-symbol loads: `lui`/`lw`, and the `$gp` form in the delay slot of the first
   walk's `beq`), so this is a -G0 unit; `first` is set after the early return (retail has
   `daddu $s3,$zero,$zero` in that `beq`'s delay slot); the 0xFF stored at +0x30 is an unsigned
   char store (a plain `char` store of 0xFF is -1 and takes its own register); the pi store
   (0x40490FDB, hoisted into $f21) comes after the call that sets the +0xF8 angle, so that
   `sb $s3,0x30($s0)` is the call's delay slot; the angle's constant is 1.5707965f (0x3FC90FDC).
   Retail's story: the entities of the group with class 0xAB0 get their private data pointed at
   this actor's, their positions summed and averaged; the second walk then moves every such
   entity (private word 0) to that centre plus the +0xD0 axis scaled by 0.5, with its +0xF0
   angle pi and its +0xF8 turned by func_00283B98. */

typedef int TI128 __attribute__((mode(TI)));

extern unsigned short *D_L02_001FC060[];
extern char *D_L02_001B359C[] __attribute__((sda));
extern int D_L02_001B35B8[] __attribute__((sda));

extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern float func_00283B98(float, float);

void func_L02_003EAA68(unsigned char *arg0) {
    char *state;
    float sum[4];
    float off[4];
    int first;
    unsigned short *p;
    char *e;

    if (arg0[0x21] == 0xFF)
        return;
    first = 0;
    state = *(char **)(arg0 + 0x68);
    *(TI128 *)sum = 0;
    for (p = D_L02_001FC060[arg0[0x21]];
         arg0[0x21] != 0xFF && arg0[0x21] <= D_L02_001B35B8[0] && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[arg0[0x21]]);
         p++) {
        e = D_L02_001B359C[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(short *)(e + 0xAA) == 0xAB0) {
            char *es = *(char **)(e + 0x68);

            *(char **)(es + 0x28) = state + 0x24;
            *(TI128 *)(es + 0x30) = *(TI128 *)(e + 0x10);
            *(float *)(es + 0x3C) = *(float *)(arg0 + 0xF8);
            if (*(int *)es != 0) {
                if (first == 0) {
                    *(int *)es = 2;
                    first = 1;
                }
                func_00282CC0(sum, sum, e + 0x10);
                e[0x20] = 2;
            } else {
                e[0x20] = 1;
            }
        }
    }
    func_00282D30(sum, sum, 0.5f);
    func_00282F20(off, arg0 + 0xD0, 0.5f);
    off[2] -= 0.5f;
    for (p = D_L02_001FC060[arg0[0x21]];
         arg0[0x21] != 0xFF && arg0[0x21] <= D_L02_001B35B8[0] && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[arg0[0x21]]);
         p++) {
        e = D_L02_001B359C[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(short *)(e + 0xAA) == 0xAB0 && **(int **)(e + 0x68) == 0) {
            ((unsigned char *)e)[0x30] = 0xFF;
            *(float *)(e + 0xF8) = func_00283B98(*(float *)(e + 0xF8), 1.5707965f);
            *(float *)(e + 0xF0) = 3.1415927f;
            func_00282CC0(e + 0x10, sum, off);
            *(int *)(e + 0x98) = 0;
            *(unsigned short *)(e + 0x34) = (*(unsigned short *)(e + 0x34) | 0x41) & 0xEFFF;
        }
    }
}
