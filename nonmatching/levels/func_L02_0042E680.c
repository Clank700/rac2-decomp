/* func_L02_0042E680 (776 bytes, 1 place: level 02) -- NEAR MISS, not integrated.
   state: 768 bytes against retail's 776 (194 instructions) in a unit of its own built with
   `-O2 -G0 -ffunction-sections -frac2-qcopy` (without the profile the copy folds its offsets into
   lq/sq and the function is 760 bytes); check.py: 0 of 1 places.
   Why it stops: only ONE thing differs, and it is retail's 16-byte copy (v70 = v20, retail
   `addiu $v1,$sp,0x20 ; lq $v0,0($v1) ; sq $v0,0($fp)`), which is also a scheduling barrier in
   retail (the known wall: -frac2-qcopy groups the pair but does not block the schedulers).
   Measured in a SCRATCH copy (never in src/): replacing `*(TI128 *)v70 = *(TI128 *)v20;` with
       __asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r" (v70), "r" (v20) : "$2", "memory");
   gives "func_L02_0042E680: 1 of 1 places match" (776 bytes, every word), so everything else in this
   C is exact: the call chain and its argument order, every constant, the sda colour-pair loads, the
   frame and the three spill slots, the counter. What the barrier changes: the first scheduling pass
   hoists `i = i - 1` of the loop counter (a spilled pseudo, its slot 0x80($sp)) to the top of the
   loop block (`lw` in the preheader, `addiu` in front of the first call, `sw` in that call's delay
   slot), because nothing holds it down; retail keeps `lw $v0,0x80($sp) ; addiu ; sw` between the
   jitter call (func_002ACB48) and the spawn call (func_002BAA28), leaves a `nop` in the first
   call's delay slot, reloads the counter into $v1 for the test, and the order of the preheader's
   `$sp`-relative address pairs and of the last call's argument moves follows from that.
   Spellings measured for the loop (all give the same hoisted decrement): do-while with `--i >= 0`,
   `for (i = 0; i < 30; i++)`, `for (i = 29; i >= 0; i--)`, `i--` at the top of the body, a
   one-element array for the counter; a volatile counter (scratch only) puts the decrement where
   retail has it but changes the other orders, and `-fno-schedule-insns` loses the prologue order.
   Facts worth keeping for the next worker:
   - callees (retail's call targets in level 02 are catalogue names of boot functions):
     func_00282CC0 = vector * matrix (out, in, matrix), func_00282F20 = scale (out, in, f),
     func_00282C88 = clear, func_00283CF0 = float to int, func_00283D38 = colour blend (c0, c1, t),
     func_002A7878 = random(lo, hi), func_002ACB48 = jitter (vec, f), func_002BAA28 = spawn, which
     returns the new object (declare it `void *`; with a void return a sched2 tie flips);
   - `float k = 0.0025f;` kept in a variable gives retail's hoisted constant and `neg.s $f0,$f26`;
   - v10 must be four element stores (an aggregate initialiser is copied from rodata);
   - the colours are two sda arrays of two words (D_L02_001B2410, D_L02_001B2418): the second word
     of each pair is symbol+4, which keeps it out of the call's delay slot, as retail has it.
   What would unblock it: a copy that is a scheduling barrier in plain C, or a variant of
   -frac2-qcopy that is one. */

typedef unsigned char u8;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282C88(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_002A7878(float, float);
extern int func_00283CF0(float);
extern int func_00283D38(int, int, float);
extern void *func_002BAA28(void *, void *, void *, int, int, int, int, int, int);
extern void func_002ACB48(void *, float);
extern int D_L02_001B2410[2] __attribute__((sda));
extern int D_L02_001B2418[2] __attribute__((sda));

void func_L02_0042E680(u8 *a0, float lo, float hi) {
    float v10[4];
    float v20[4];
    float v30[4];
    float v40[4];
    float v50[4];
    float v60[4];
    float v70[4];
    int i;
    float r;
    int a, b, c;
    int c0, c1;
    float k = 0.0025f;

    v10[0] = 0.0f;
    v10[1] = 0.0f;
    v10[2] = 4.0f;
    v10[3] = 1.0f;
    func_00282CC0(v20, v10, a0 + 0x10);
    i = 29;
    do {
        func_00282F20(v40, a0 + 0xC0, func_002A7878(-0.8f, 0.8f));
        func_00282F20(v30, a0 + 0xE0, func_002A7878(0.25f, 1.0f));
        func_00282CC0(v50, a0 + 0xD0, v40);
        func_00282CC0(v50, v50, v30);
        func_00282F20(v50, v50, func_002A7878(lo, hi));
        r = func_002A7878(0.5f, 1.5f);
        a = func_00283CF0(r * 10.0f);
        b = func_00283CF0(r * 30.0f);
        c = func_00283CF0(r * 7.0f);
        v50[3] = func_002A7878(0.2f, 0.6f);
        func_00282C88(v60);
        v60[2] = -k * (float)(a + b + c);
        func_00282CC0(v60, v60, v50);
        v60[3] = 0.01f;
        c0 = func_00283D38(D_L02_001B2410[0], D_L02_001B2410[1], func_002A7878(0.0f, 1.0f));
        c1 = func_00283D38(D_L02_001B2418[0], D_L02_001B2418[1], func_002A7878(0.0f, 1.0f));
        *(TI128 *)v70 = *(TI128 *)v20;
        func_002ACB48(v70, 0.25f);
        func_002BAA28(v70, v50, v60, c0, c1, a, b, c, 0x1003C);
    } while (--i >= 0);
}
