#include "include_asm.h"
#include "common.h"

typedef u64 TI128 __attribute__((mode(TI)));

extern f32 D_L08_001BE0B0;
extern void func_0027AB40();

extern int r1_D_0015F564_002F2D10 MACRO_ADDR;

 /* GetEffectTex(int, int) */

/*
 * Four parallel callback lists, each a (function, argument) pair of
 * arrays with its own count, plus a "register" and a "run them all"
 * function per list. The counts are reached with retail's one-register
 * macro form, so they are MACRO_ADDR.
 */
typedef void (*DrawCallback_r002F2D10)(void *);

extern DrawCallback_r002F2D10 r1_D_0018DC40_002F2D10[];

extern void *r1_D_0018DD40_002F2D10[];

/* rac1-decomp src/game/draw.c: func_001F49B0 */
void func_L08_002F2D10(DrawCallback_r002F2D10 fn, void *arg) {
    int count = r1_D_0015F564_002F2D10;
    if (count < 0x40) {
        r1_D_0018DC40_002F2D10[count] = fn;
        r1_D_0018DD40_002F2D10[count] = arg;
        r1_D_0015F564_002F2D10 = count + 1;
    }
}

INCLUDE_ASM("asm/levels", func_L08_002F5CB8);

void func_L08_00300100(void) {
    D_L08_001BE0B0 = 0.62f;
    func_0027AB40();
}

extern void func_00292408();
extern void func_L00_002FE268();
extern void func_002934B8();
extern u8 D_L08_001DB5E7;
extern s32 D_L08_001DAC40[];
extern s32 D_L08_001BFEF4;

void func_L08_0030A8F8(s32 x) {
    func_00292408(x);
    func_L00_002FE268(x);
    func_002934B8(D_L08_001DAC40[D_L08_001DB5E7], D_L08_001BFEF4);
}

INCLUDE_ASM("asm/levels", func_L08_00318F90);
f32 func_L08_003277C0(s32 n, f32 x) {
    f32 r;
    if (n < 2)
        return x;
    r = x;
    while (n >= 2) {
        n--;
        r = r * x;
    }
    return r;
}

INCLUDE_ASM("asm/levels", func_L08_003289D0);

INCLUDE_ASM("asm/levels", func_L08_00328AE0);

extern u8 *D_L08_001B29DC __attribute__((sda));
extern void func_L08_00328AE0(void *, s32, s32, s32);

void func_L08_00328B80(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (a0 == -1)
        return;
    func_L08_00328AE0(D_L08_001B29DC + (a0 << 8), a1, a2, a3);
}

INCLUDE_ASM("asm/levels", func_L08_00328BB0);

extern f32 func_00283248(f32, f32);
extern f32 func_00282E20(void *);

/* Splits a four-float vector: two components give an angle, 0x45AFDF66 marks an
   already-resolved vector. */
void func_L08_0032A4D0(u8 *a0, f32 *a1, f32 *a2, f32 *a3) {
    f32 v[4];

    *(TI128 *)v = *(TI128 *)a0;
    if (v[3] != 5627.9248046875f) {
        *a1 = func_00283248(v[0], v[1]);
        return;
    }
    *a1 = func_00283248(v[0], v[1]);
    *a2 = *a2 * func_00282E20(v);
    v[3] = 0;
    *a3 = *a3 * v[2];
}

INCLUDE_ASM("asm/levels", func_L08_0032C0D8);

s32 func_L08_003391C0(u8 *p, s32 a1, s32 a2, u8 *out, f32 f1, f32 f2) {
    u8 *q;
    if (p == 0)
        return -1;
    q = *(u8 **)(p + 0x24);
    if (q == 0)
        return -1;
    if (*(s32 *)(q + 0x28) == 0)
        return -1;
    *(u32 *)(out + 0x1C) = (u32)p;
    *(f32 *)(out + 0x14) = f2 * 0.016666668f;
    *(f32 *)(out + 0x10) = f1 * 0.016666668f;
    *(TI128 *)out = *(TI128 *)(p + 0x10);
    *(s32 *)(out + 0x18) = a2;
    *(s32 *)(out + 0x20) = a1;
    return 1;
}

INCLUDE_ASM("asm/levels", func_L08_00339220);

extern void func_L01_00324410(s32, s32, void *);

/* The float varargs entry: 2.95.3 spills $a2-$a3, $t0-$t3 (eight bytes each)
   and $f12-$f18; the work is done by the shared worker on that save area. */
void func_L08_0033CD18(s32 a0, s32 a1, ...) {
    func_L01_00324410(a0, a1, (char *)__builtin_next_arg(a1) - 0x30);
}

INCLUDE_ASM("asm/levels", func_L08_0034A078);

INCLUDE_ASM("asm/levels", func_L08_00363320);

INCLUDE_ASM("asm/levels", func_L08_0036EFC8);

INCLUDE_ASM("asm/levels", func_L08_0036F030);

INCLUDE_ASM("asm/levels", func_L08_0037E6D8);

INCLUDE_ASM("asm/levels", func_L08_00389B68);

INCLUDE_ASM("asm/levels", func_L08_0039DBE8);

INCLUDE_ASM("asm/levels", func_L08_0039E000);

INCLUDE_ASM("asm/levels", func_L08_003A35E0);

INCLUDE_ASM("asm/levels", func_L08_003B2DB0);

INCLUDE_ASM("asm/levels", func_L08_003B2F70);

INCLUDE_ASM("asm/levels", func_L08_003C5940);

INCLUDE_ASM("asm/levels", func_L08_003C63F0);

INCLUDE_ASM("asm/levels", func_L08_003C6528);

INCLUDE_ASM("asm/levels", func_L08_003C66F0);

INCLUDE_ASM("asm/levels", func_L08_003C67B8);

INCLUDE_ASM("asm/levels", func_L08_003C6AB0);

INCLUDE_ASM("asm/levels", func_L08_003CC4B8);

INCLUDE_ASM("asm/levels", func_L08_003CD488);

extern u8 *D_0018C0B0;
extern void func_002A0F48();

INCLUDE_ASM("asm/levels", func_L08_003CD600);

INCLUDE_ASM("asm/levels", func_L08_003CD648);

INCLUDE_ASM("asm/levels", func_L08_003CD6C8);

INCLUDE_ASM("asm/levels", func_L08_003CD708);

INCLUDE_ASM("asm/levels", func_L08_003CDB38);

INCLUDE_ASM("asm/levels", func_L08_003CDB78);

INCLUDE_ASM("asm/levels", func_L08_003CDF98);

