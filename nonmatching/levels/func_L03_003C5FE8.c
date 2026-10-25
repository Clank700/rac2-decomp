/* Near miss, 2026-10-25 wave 10: 532 bytes expected, 532 produced, 0 of 1
   place (03_endako @0x003C5FF0).  One three-instruction window differs, around
   +0xB4: retail loads the second rate (`lwc1 $f13,0x1064($gp)`) and the second
   float (`lwc1 $f12,0x10($s2)`) before the jal and puts the *first* result's
   store (`swc1 $f0,0x4($s2)`) in that jal's delay slot; this C emits the first
   store first and lands the multiply in the delay slot.  Every other word,
   including both calls' scheduling, the loop and the whole motion-table tail,
   is byte-identical.
   Tried: the same two statements with pointer locals; result temporaries in
   `f32 a, b` (544 bytes, extra saves); an inner block forcing the second rate
   before the call (unchanged).  Next hypothesis: the original pairs the two
   stores through a single expression, or the second call's first argument is a
   reload of a local that keeps the store pending one slot longer.

   This body needs -G8: it reads D_L03_001B0050/54/58 ($gp+0x1060..68).
   gp = 0x001AEFF0 in the level programs (from D_L03_001B0340 at $gp+0x1350).
   The 0.000290888245f literal is fine; the multiply by it is not a clamp. */

#include "common.h"

extern f32 D_L03_001B0050 __attribute__((sda));
extern f32 D_L03_001B0054 __attribute__((sda));
extern f32 D_L03_001B0058[2] __attribute__((sda));
extern char D_L03_00188660[];
extern void func_31B920(char *a0, s32 a1, s32 a2);
extern f32  func_2F0000(f32 a0, f32 a1);
extern void func_2E77F0(void *a0, void *a1);
extern void func_L03_003C6208(void);
extern s32  func_32AB10(char *a0);
extern void func_31EBA8(f32 *a0, f32 a1, f32 a2);
extern void func_360780(s32 a0);
extern s32  func_360A80(s32 a0, s32 a1, char *a2);

void func_L03_003C5FE8(char *a0)
{
    char *s1 = a0;
    char *s2 = *(char **)(s1 + 0x68);

    switch (*(u8 *)(s1 + 0x20)) {
    case 0:
        *(f32 *)(s1 + 0x2C) = *(f32 *)(*(s32 *)(s1 + 0x24) + 0x24) * *(f32 *)s2;
        func_31B920(s1, 1, -1);
        *(u16 *)(s1 + 0x34) |= 1;
        *(u8 *)(s1 + 0x31) = 0;
        *(f32 *)(s2 + 0x14) = 1.0f;
        break;
    case 1: {
        f32 k = 0.000290888245f;
        f32 *c = D_L03_001B0058;
        f32 *p = (f32 *)(s2 + 8);
        s32 i;

        *(f32 *)(s2 + 4) = func_2F0000(*(f32 *)(s2 + 4), D_L03_001B0050 * k);
        *(f32 *)(s2 + 0x10) = func_2F0000(*(f32 *)(s2 + 0x10), D_L03_001B0054 * k);
        for (i = 1; i >= 0; i--) {
            *p = func_2F0000(*p, *c * 0.000290888245f);
            p++;
            c++;
        }
        func_2E77F0(func_L03_003C6208, s1);
        if (func_32AB10(s1) != 0) {
            func_31EBA8((f32 *)(s2 + 0x14), 0.0f, 0.0333333351f);
            if (*(f32 *)(s2 + 0x14) <= 0.0f) {
                func_31B920(s1, 2, -1);
                *(s32 *)(s1 + 0x98) = 0;
            }
        }
        break;
    }
    }
    if (*(u8 *)(s1 + 0x20) == 1) {
        char *p = D_L03_00188660 + *(s32 *)(s2 + 0x18) * 0x70;

        if (*(char **)(p + 0x88) != s1 || *(u8 *)(p + 0x74) == 0)
            *(s32 *)(s2 + 0x18) = func_360A80(0, 4, s1);
    } else {
        s32 v = *(s32 *)(s2 + 0x18);

        if (v != -1) {
            char *p = D_L03_00188660 + v * 0x70;

            if (*(char **)(p + 0x88) == s1 && *(u8 *)(p + 0x74) != 0)
                func_360780(v);
        }
        *(s32 *)(s2 + 0x18) = -1;
    }
}
