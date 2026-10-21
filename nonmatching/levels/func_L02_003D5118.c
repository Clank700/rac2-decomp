/* func_L02_003D5118, 396 bytes, 1 placement (level 2).  Near miss with the opt-in `-frac2-qcopy`
   profile (#262): in a unit of its own (src/levels/02_maktar_nebula/L02_003D5118.c, flags
   `-O2 -G0 -ffunction-sections -frac2-qcopy`) the C below is retail's 396 bytes: same frame
   (0xF0), same seven stack blocks at the same offsets, same ten calls and arguments, retail's
   copy `addiu s0,sp,0x60 ; lq v0,0(s1) ; sq v0,0(s0)`, the two clamp compares and the final call's
   third float (`1.0f`, which retail keeps in $f14 from the clamp's constant).  13 of its 99
   words differ (tools/check.py: 0 of 1 places match, first difference at +0x14):
     retail prologue   sd s0, daddu a2,sp, sd s1, daddu s0,a1, sd s4, sd s2, daddu s4,a0, sd s3, sd ra, swc1 f20, sd s5
     this unit         sd s0, daddu a2,sp, sd s1, daddu s0,a1, sd s2, sd s3, sd s4, swc1 f20, daddu s4,a0, sd ra, sd s5
     retail 2nd call   addiu s1,sp,0x20 ; daddu a1,s0 ; daddu a0,s4 ; jal ; daddu a2,s1
     this unit         addiu s1,sp,0x20 ; daddu a1,s0 ; daddu a2,s1 ; jal ; daddu a0,s4
     retail after it   addiu s0,sp,0x60 ; lq ; sq ; lui/ori/mtc1 f12 (5.3f) ; daddu a0,s0 ; jal ; daddu a1,s0
     this unit         addiu s0,sp,0x60 ; lui/ori/mtc1 f12 ; lq ; sq ; daddu a0,s0 ; jal ; daddu a1,s0
   Cause (measured, `-fsched-verbose-5 -dS -dR`): retail's copy was a volatile asm, a barrier for
   both scheduling passes, and `rac2_qcopy` is an ordinary insn (no unit).  Behind a barrier the
   stores' first writers that sit after it (`addiu s2,sp,0x80`, `addiu s3,sp,0x70`, `mov.s f20,f0`)
   are no longer direct dependents of the callee-save stores, while those before it
   (`daddu s0,a1`, `addiu s1,sp,0x20`, `daddu s4,a0`) still are: sched2 ranks by priority (all
   equal), then by how many insns depend on the insn (more first), then by emission order, which
   gives retail's s0, s1, s4, s2, s3, ra, f20, s5.  The same counts put `daddu a0,s4` ahead of
   `daddu a2,s1` (a2 loses its dependents behind the barrier), and the barrier keeps the
   `li.s $f12` of the next call after the copy.
   Measured in a scratch copy (not allowed in src/): with the copy written as one volatile asm
   `__asm__ __volatile__("lq $2,0(%0)\n\tsq $2,0(%1)" : : "r"(m), "r"(p) : "$2", "memory")`
   in place of `*(TI128 *)p = *(TI128 *)m` (flags `-O2 -G0 -ffunction-sections`, no profile) the
   same C is exact: 1 of 1 places.  Adding `-frac2-zero-ti-barrier` to the profile does not
   change the copy (it selects zero stores only).
   Corrections found on the way: the callee func_002A8C28 takes THREE floats (f12, f13, f14, as in
   the L02_003DB310.c call), and retail passes the clamp's `1.0f` as the third; a two-float
   prototype leaves the clamp's constant in $f0 instead of $f14.  Both `func_00282DF0` calls are
   `float` returns divided as `t = r / s`, each in its own statement or in one expression
   (identical code).
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.
   Body measured in that unit: */

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029FCC0(char *, int, void *);

extern void func_0029FC20(char *, int, void *);

extern void func_00282F20(char *, char *, float);

extern void func_00282CC0(void *, void *, void *);

extern void func_L00_0031BDC0(char *, char *, char *, char *);

extern void func_00282CF0(void *, void *, void *);

extern float func_00282DF0(void *);

extern void func_002A8C28(char *, char *, int, float, float, float, int, int, int);

void func_L02_003D5118(char *arg0, int arg1) {
    char *state = *(char **)(arg0 + 0x68);
    float a[4];
    float d[4];
    float m[16];
    float p[4];
    float q[4];
    float r[4];
    float s[4];
    float t;

    func_0029FCC0(arg0, arg1, a);
    func_0029FC20(arg0, arg1, m);
    *(TI128 *)p = *(TI128 *)m;
    func_00282F20((char *)p, (char *)p, 5.3f);
    func_00282CC0(d, a, p);
    func_L00_0031BDC0((char *)q, (char *)a, (char *)d, *(char **)(state + 0x30C) + 0x10);
    func_00282CF0(r, a, q);
    func_00282CF0(s, a, d);
    t = func_00282DF0(r);
    t = t / func_00282DF0(s);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_002A8C28(arg0, (char *)q, 0x10001, t * 0.2f + 0.3f,
                  (float)*(unsigned char *)(state + 0x34), 1.0f, 0, 1, 0);
}
