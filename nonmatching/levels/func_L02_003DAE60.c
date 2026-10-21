/* func_L02_003DAE60, 300 bytes, 1 placement (level 2, 02_maktar_nebula). NEAR MISS: 300 bytes, the size of retail,
   but about 24 words are in other places. Compiled as a unit of its own, `-O2 -G8 -ffunction-sections
   -frac2-qcopy` (a `-g8.c` unit: the five data accesses are `$gp` words, all but the colour load outside a delay
   slot; the two 16-byte copies are the `lq $v0,0($sp) ; sq $v0,0($v1)` pairs of -frac2-qcopy).

   Same body as its twin func_L02_003D6570 (read that header for the whole story) with the bone index passed
   through (arg1) and the colour read from the second object's state, as func_L02_003DB030 does (st =
   *(*(arg0 + 0xB8) + 0x68); it lives in $s3 here). The body is right and every register is right; what differs is
   the order of independent instructions: the prologue's `sd $s2` / `daddu $s0,$a0` / `daddu $s2,$a1` run in
   another order (the first call's argument moves are scheduled into the saves), `addiu $s1,$sp,0x20` is hoisted
   above the first copy, and the argument moves of func_002830C0, func_00282CF0 and func_00282F20 come out in
   another order (the same three groups as in func_L02_003D6570).
   Measured (diagnostic only, not admissible in src/): with both copies written as
   `__asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(dst), "r"(src) : "$2", "memory")` and no -frac2-qcopy
   the same body is byte-identical to retail (the placement derive says OK). So retail's copies are scheduling
   barriers and -frac2-qcopy's are not; a barrier model for the rac2_qcopy parallel (as zero_ti_store_barrier.py
   gives the clear) would unblock it.
   Spellings that matter: `len = len * len;` (a separate temporary gives the float registers off by one, 7 words)
   and `(float)(int)(color >> 24)`. -fno-schedule-insns (35 words off), -fno-schedule-insns2 (36) and both (40) are
   worse than the default (24). */

typedef int TI128 __attribute__((mode(TI)));

extern float D_L02_001B0410 __attribute__((sda));
extern float D_L02_001B0414 __attribute__((sda));
extern int D_L02_001B0420 __attribute__((sda));
extern float D_L02_001B0430 __attribute__((sda));
extern float D_L02_001BA500[4];

extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

void func_L02_003DAE60(char *arg0, int arg1) {
    float a[4];
    float b[4];
    float c[16];
    float d[4];
    float e[4];
    float f[4];
    float len;
    unsigned int color;
    char *st = *(char **)(*(char **)(arg0 + 0xB8) + 0x68);

    func_0029FCC0(arg0, arg1, a);
    *(TI128 *)b = *(TI128 *)a;
    func_0029FC20(arg0, arg1, c);
    func_002830C0(d, &D_L02_001B0420, c);
    func_00282CC0(a, a, d);
    func_00282CF0(e, D_L02_001BA500, a);
    func_00282F20(e, e, 1.0f);
    *(TI128 *)f = *(TI128 *)c;
    len = func_00282DB0(e, f);
    if (D_L02_001B0430 < len) {
        color = *(unsigned int *)(st + 0x250);
        len = len * len;
        func_L00_00325AE8(a, (color & 0xFFFFFF) | ((int)(len * (float)(int)(color >> 24)) << 24),
                          D_L02_001B0414, D_L02_001B0410);
    }
}
