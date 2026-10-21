/* func_L02_003D6388, 432 bytes, 1 placement (level 2).  Near miss with the opt-in `-frac2-qcopy`
   profile (#262): in a -G8 unit of its own (src/levels/02_maktar_nebula/L02_003D6388-g8.c, flags
   `-O2 -G8 -ffunction-sections -frac2-qcopy`; -G8 for the `$gp` reads below, at
   `$gp + 0x12E8 / 0x12EC / 0x12F0 / 0x1300 / 0x1310 / 0x1320 / 0x1324`: three floats, the colour
   word, the threshold and the two 16-byte vectors that are copied) the C below is retail's
   432 bytes: same frame (0xD0), same seven stack blocks, same twelve calls with the same argument
   registers and delay slots, the `beqz` over the two `neg.s`, and the whole colour block
   (`srl` / `cvt.s.w` / `mul.s` / `cvt.w.s` / `mfc1` / `sll` / `or`, with `$s0` updated in place).
   12 of its 108 words differ (tools/check.py: 0 of 1 places match, first difference at +0x1C):
     retail prologue   sd s0, sd s1, daddu s0,a0, sd s2, daddu s1,a1, daddu s2,a2, sd s4, sd s3, sd ra
     this unit         sd s0, sd s1, daddu s0,a0, sd s2, daddu s1,a1, daddu s2,a2, sd s3, sd s4, sd ra
     retail after the first call   addiu s4,sp,0x10 ; lq v0,0(sp) ; sq v0,0(s4) ; addiu s3,sp,0x20 ; daddu a0,s0 ; daddu a1,s1
     this unit                     addiu s4,sp,0x10 ; addiu s3,sp,0x20 ; daddu a0,s0 ; daddu a1,s1 ; lq v0,0(sp) ; sq v0,0(s4)
     retail after the second call  addiu s0,sp,0x60 ; addiu v1,gp,0x12F0 ; lq ; sq ; addiu s1,sp,0x70 ; addiu v1,gp,0x1310 ; lq ; sq
     this unit                     addiu s0,sp,0x60 ; addiu v1,gp,0x12F0 ; addiu s1,sp,0x70 ; addiu a0,gp,0x1310 ; lq ; sq ; lq ; sq
   Cause: wall (2).  Retail's three copies were volatile asms, a barrier for both scheduling passes
   (it leaves `sd s4` one dependent more than `sd s3`, since `addiu s4` comes before the barrier
   and `addiu s3` after it, and it keeps the pointer set-ups of the next copy behind the previous
   one), and `rac2_qcopy` is an ordinary insn.  Measured in a scratch copy (not allowed in src/):
   with `__asm__ __volatile__("" : : : "memory");` written after each of the three copies the same
   C is exact: 1 of 1 places.
   Source notes (each measured):
   - `D_L02_001BA500` must be declared as a large object (`float [4]`, passed as the array): a one
     byte `char` is small data in a -G8 unit and its address comes out as one `la`, so the `lui` and
     the `addiu` of the fifth call stay together; as an array they are split and scheduled apart as
     retail has them (`lui a1,0x1C ; daddu a2,sp ; addiu a1,a1,-0x5B00`);
   - the two 16-byte `$gp` vectors are `char [8] __attribute__((sda))` read as `*(TI128 *)`;
   - the colour is `color = D_L02_001B0310; alpha = (float)(int)(color >> 24); color &= 0xFFFFFF;
     d = d * d; color |= (int)(d * alpha) << 24;`, which gives retail's registers ($f1 threshold,
     $f2 the dot product squared in place, $f0 the alpha, $s0 the colour in place); the same
     expression written as one `(color & 0xFFFFFF) | ((int)(d * d * alpha) << 24)` takes other
     registers and `and`/`or` into $v1;
   - the dot product is a `float` return of func_00282DB0(r, s) with `s` the negated third row
     of the matrix (`func_00282F20(s, m + 8, -1.0f)`), and the threshold test is
     `D_L02_001B0314 < d`.
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.
   Body measured in that unit: */

typedef int TI128 __attribute__((mode(TI)));

extern void *func_0029FCC0(char *, int, void *);

extern void func_0029FC20(char *, int, void *);

extern void func_002830C0(void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern float func_00282DB0(void *, void *);

extern void func_L00_00325AE8(void *, int, float, float);

extern float D_L02_001BA500[4];

extern char D_L02_001B02E0[8] __attribute__((sda));

extern char D_L02_001B0300[8] __attribute__((sda));

extern unsigned int D_L02_001B0310 __attribute__((sda));

extern float D_L02_001B0314 __attribute__((sda));

extern float D_L02_001B02DC __attribute__((sda));

extern float D_L02_001B02D8 __attribute__((sda));

extern float D_L02_001B02F0 __attribute__((sda));

void func_L02_003D6388(char *arg0, int arg1, int arg2) {
    float a[4];
    float b[4];
    float m[16];
    float p[4];
    float q[4];
    float r[4];
    float s[4];
    float d;
    float alpha;
    unsigned int color;

    func_0029FCC0(arg0, arg1, a);
    *(TI128 *)b = *(TI128 *)a;
    func_0029FC20(arg0, arg1, m);
    *(TI128 *)p = *(TI128 *)D_L02_001B02E0;
    *(TI128 *)q = *(TI128 *)D_L02_001B0300;
    if (arg2 != 0) {
        p[1] = -p[1];
        q[1] = -q[1];
    }
    func_002830C0(p, p, m);
    func_00282CC0(a, a, p);
    func_002830C0(q, q, m);
    func_00282CC0(b, b, q);
    func_00282CF0(r, D_L02_001BA500, a);
    func_00282F20(r, r, 1.0f);
    func_00282F20(s, m + 8, -1.0f);
    d = func_00282DB0(r, s);
    if (D_L02_001B0314 < d) {
        color = D_L02_001B0310;
        alpha = (float)(int)(color >> 24);
        color &= 0xFFFFFF;
        d = d * d;
        color |= (int)(d * alpha) << 24;
        func_L00_00325AE8(a, color, D_L02_001B02DC, D_L02_001B02D8);
        func_L00_00325AE8(b, color, D_L02_001B02F0, D_L02_001B02D8);
    }
}
