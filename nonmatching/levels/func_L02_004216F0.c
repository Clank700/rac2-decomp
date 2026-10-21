/* Near miss: 368 bytes, retail's size (check.py first differs at +0x64).  Every word of the
 * function is retail's; sixteen of them, in the window 0x421754-0x421794 (the first call's
 * argument set-up and the two 16-byte copies), are in another order.
 *
 * It needs a unit of its own, `src/levels/02_maktar_nebula/L02_004216F0-g8.c`, with one line in
 * config/cflags.txt:
 *     -O2 -G8 -ffunction-sections -g -frac2-qcopy -fno-schedule-insns
 *   -G8 / the `sda` floats      the `lwc1 ...($gp)` words (1.0f/60.0f is an immediate)
 *   -frac2-qcopy                `addiu $v1,$s4,0x10 ; lq $v0,0($s1) ; sq $v0,0($v1)` copies
 *   -fno-schedule-insns         retail's registers: $s1/$s0/$s5 for the three arguments, $s4 the
 *                               new object, $s3 its state, $s2 the vector at +0x40, $f21 the
 *                               argument float and $f20 the 1/60 constant; with the first
 *                               scheduler on, this body takes seven callee-saved registers
 *   -g                          the two `nop ; nop` before each `div.s`: the assembler pads a
 *                               division that is fewer than two slots after a line label.  The
 *                               divisor of the first one must sit in a statement of its own
 *                               (`t = ...; n = f(D / t);`), so that the line labels fall between
 *                               its `mul.s` and the `div.s`
 *
 * What differs.  Retail's sequence after the first call is, in source order,
 *     addiu $v1,$s4,0x10 ; lq ; sq ; addiu $s1,$s4,0xC0 ; lq ; sq ;
 *     addiu $s0,$s4,0xD0 ; lui $a2 ; addiu $a2 ; daddu $a0,$s0,$zero ; jal
 * and before the call, `... lwc1 $f12 ; lw $s3 ; mul.s ; swc1 $f21,0x64($s3) ; addiu $s2,$s3,0x40`.
 * The second scheduler moves instead `addiu $s0,$s4,0xD0` up into the idle slot before the first
 * `lwc1`, `lui $a2`/`daddu $a0,$s0` up in front of the two copies, and puts `addiu $s2` before
 * the `swc1`.
 *
 * Cause, measured: retail's two copies are barriers.  Written as
 *     __asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(obj + 0x10), "r"(a0) : "$2", "memory");
 *     __asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(obj + 0xC0), "r"(v + 0x40) : "$2", "memory");
 * in place of the two TI128 assignments (and with the same flags line), this body is
 * `func_L02_004216F0: 1 of 1 places match`.  The `rac2_qcopy` pattern is "not an opaque asm", so
 * it is an ordinary insn for the schedulers and nothing keeps the neighbouring arithmetic from
 * moving across it.  No plain C spelling tried changes that (named pointers for obj+0xC0 and
 * obj+0xD0, the order of the stores, casts instead of subscripts, the product `t` in or out of the
 * call).  A compiler-side candidate: an opt-in variant of -frac2-qcopy whose copy is a scheduling
 * barrier, like the one `-frac2-zero-ti-barrier` gives the clears. */
typedef unsigned char u8;
typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029EFD0(int);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern void func_L02_004224C8(u8 *);
extern int func_002E5CF8(int, int, void *);
extern char D_0018A0E0[];
extern float D_L02_001B1F98 __attribute__((sda));
extern float D_L02_001B1FA0 __attribute__((sda));
extern float D_L02_001B1FA4 __attribute__((sda));

u8 *func_L02_004216F0(u8 *a0, int a1, u8 *a2, float a3) {
    u8 *obj = func_0029EFD0(0xD08);
    u8 *v;
    int n;
    float t;

    if (obj != 0) {
        *(u8 *)(obj + 0x20) = 0;
        *(u8 *)(obj + 0x30) = 0xFF;
        t = D_L02_001B1FA0 * 0.016666668f;
        v = *(u8 **)(obj + 0x68);
        *(float *)(v + 0x64) = a3;
        func_00282F20(v + 0x40, a2, t);
        *(TI128 *)(obj + 0x10) = *(TI128 *)a0;
        *(TI128 *)(obj + 0xC0) = *(TI128 *)(v + 0x40);
        func_00282DD8(obj + 0xD0, obj + 0xC0, D_0018A0E0);
        func_00282F20(obj + 0xD0, obj + 0xD0, -1.0f);
        func_00282DD8(obj + 0xE0, obj + 0xD0, obj + 0xC0);
        t = D_L02_001B1FA0 * 0.016666668f;
        n = func_00283CF0(D_L02_001B1FA4 / t);
        *(int *)(v + 0x58) = n;
        *(float *)(v + 0x5C) = 1.0f / func_00283CE0(n);
        *(int *)(v + 0x50) = a1;
        *(u8 *)(obj + 0x20) = 0;
        *(float *)(v + 0x60) = D_L02_001B1F98;
        func_L02_004224C8(obj);
        func_002E5CF8(1, 0, obj);
    }
    return obj;
}
