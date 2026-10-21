/* func_L02_003D6570, 284 bytes, 1 placement (level 2, 02_maktar_nebula). NEAR MISS: 284 bytes, the size of retail,
   but about 19 words are in other places. Compiled as a unit of its own, `-O2 -G8 -ffunction-sections
   -frac2-qcopy` (G8: the five data accesses are `$gp` words, all but the colour load outside a delay slot, so a
   `-g8.c` unit; the 16-byte copies need -frac2-qcopy: `addiu $v1,$sp,0x10 ; lq $v0,0($sp) ; sq $v0,0($v1)`).

   The body is right and every register is right; only the order of independent instructions around the two
   copies and in the four call-argument groups that follow differs:
     - `addiu $s2,$sp,0x20` (the matrix address) is hoisted above the first copy; retail has it after it;
     - func_002830C0's arguments come out `$a1, $a0, [call], $a2` against retail's `$a2, $a1, [call], $a0`;
       func_00282CF0's `lui $a1; $a2; addiu $a1; [call]; $a0` against `lui; addiu; $a0; [call]; $a2`;
       func_00282F20's `$a0 ... [call] $a1` against `$a1 ... [call] $a0`.
   Retail's copies are scheduling barriers. Measured (diagnostic only, not admissible in src/): the same body
   with both copies written as `__asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(dst), "r"(src) :
   "$2", "memory")` and compiled WITHOUT -frac2-qcopy is byte-identical to retail (the placement derive says
   OK): the barrier also fixes the four argument groups, which are not next to any copy (presumably through
   the dependences every earlier and later insn gets on it, which change the priorities the schedulers rank
   those moves by). -frac2-qcopy makes the copies ordinary insns, so the groups come out in the order the
   ranking gives without a barrier. The model needs both schedulers (-fno-schedule-insns leaves 23 words off,
   -fno-schedule-insns2 11). The same applies to its twins func_L02_003DB030 and func_L02_003DAE60. What would
   unblock it: a barrier model for the rac2_qcopy parallel in sched_analyze_insn, like the one
   zero_ti_store_barrier.py gives the quadword clear.

   Two spellings in the body are measured, not natural: `len = len * len;` reuses the variable (a separate
   temporary leaves the float registers off by one: len/thr/alpha in $f1/$f0/$f1 instead of retail's
   $f2/$f1/$f0, 7 words), and `(float)(int)(color >> 24)` (an unsigned colour converts through a `bltz` fix-up).
   Layout: a (sp+0) is the vector func_0029FCC0 fills, b (sp+0x10) its copy (dead here, but retail stores it),
   c (sp+0x20) a 64-byte matrix, d (sp+0x60), e (sp+0x70), f (sp+0x80).
   Tried on the schedulers, added to -frac2-qcopy: -fno-schedule-insns (30 words off), -fno-schedule-insns2 (34),
   both (36); -fno-sched-interblock and -frac2-zero-ti-barrier change nothing (19). */

typedef int TI128 __attribute__((mode(TI)));

extern float D_L02_001B0318 __attribute__((sda));
extern float D_L02_001B031C __attribute__((sda));
extern int D_L02_001B0320 __attribute__((sda));
extern unsigned int D_L02_001B0330 __attribute__((sda));
extern float D_L02_001B0334 __attribute__((sda));
extern float D_L02_001BA500[4];

extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

void func_L02_003D6570(char *arg0, int arg1) {
    float a[4];
    float b[4];
    float c[16];
    float d[4];
    float e[4];
    float f[4];
    float len;
    unsigned int color;

    func_0029FCC0(arg0, arg1, a);
    *(TI128 *)b = *(TI128 *)a;
    func_0029FC20(arg0, arg1, c);
    func_002830C0(d, &D_L02_001B0320, c);
    func_00282CC0(a, a, d);
    func_00282CF0(e, D_L02_001BA500, a);
    func_00282F20(e, e, 1.0f);
    *(TI128 *)f = *(TI128 *)c;
    len = func_00282DB0(e, f);
    if (D_L02_001B0334 < len) {
        color = D_L02_001B0330;
        len = len * len;
        func_L00_00325AE8(a, (color & 0xFFFFFF) | ((int)(len * (float)(int)(color >> 24)) << 24),
                          D_L02_001B031C, D_L02_001B0318);
    }
}
