/* Near miss: func_L08_0042FAC0, 544 bytes, 1 place (level 08 Tabora).
   Profile: -O2 -G0 -ffunction-sections (the shipped file's flags).

   This is the twin of func_L08_0042F440: the same body with the second
   func_334BB0 arm's first integer argument 1 instead of 9. It was measured
   after the 440 draft: `0 of 1 places match`, first differing word at +0x128,
   body size 544 = retail. The residue is identical to func_L08_0042F440's
   (see that file): func_334BB0's argument-setup order and case 3's counter
   register. Both are sched2/allocator choices, not source-shape differences. */

#include "include_asm.h"

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef float f32;

extern s32 D_L08_001B29DC __attribute__((sda));
extern f32 D_L08_001B250C __attribute__((sda));
extern s32 D_L08_001B3AA0 __attribute__((sda));
extern char D_L08_001A8F20[];
extern char *func_32A170(s32 a, s32 b, s32 c);
extern void func_327758(char *a0, s32 a1, s32 a2);
extern void func_334BB0(char *a0, f32 f12, f32 f13, s32 a1, char *a2,
                        f32 f14, f32 f15, s32 a3);
extern void func_334860(char *a0, s32 a1, f32 f12);
extern void func_36D8E0(s32 a0, s32 a1, char *a2);
extern s32 func_338040(char *a0);
extern s32 func_2F9A60(char *a0);
extern void func_31D540(char *a0);

void func_L08_0042FAC0(char *a0) {
    char *s1 = *(char **)(a0 + 0x68);
    u8 state = *(u8 *)(a0 + 0x20);
    char *p;
    s32 n;
    u8 st;

    switch (state) {
    case 0:
        func_327758(a0, 1, -1);
        return;
    case 1:
        p = func_32A170((s32)a0, 0x04010000, 0);
        if (p != 0 && *(s32 *)s1 == 0) {
            func_327758(a0, 2, -1);
            return;
        }
        *(u8 *)(a0 + 0xA8) = 0xFF;
        n = *(s32 *)(s1 + 4);
        if (n > 0) {
            char *e = (char *)(D_L08_001B29DC + (n << 8));

            if (e == 0) {
                return;
            }
            st = *(u8 *)(e + 0x20);
            if (st == 0xFE || (st == 0xFD || st == 3)) {
                func_327758(a0, 2, -1);
            }
        }
        return;
    case 2:
        if (*(u8 *)(a0 + 0x31) != 0 && D_L08_001B250C < 0.9f &&
            D_L08_001B3AA0 < 10) {
            func_334BB0(a0, 3.0f, 6.0f, 15, D_L08_001A8F20, 3.0f, 6.0f, 0xFF);
        } else {
            func_334BB0(a0, 3.0f, 6.0f, 1, D_L08_001A8F20, 3.0f, 6.0f, 0xFF);
        }
        func_334860(a0, 1, 0.0f);
        func_36D8E0(0, 0, a0);
        func_327758(a0, 3, -1);
        return;
    case 3:
        if (func_338040(a0) != 0) {
            *(u8 *)(a0 + 0x31) = 0;
            *(u16 *)(a0 + 0x34) |= 1;
            *(s32 *)(a0 + 0x98) = 0;
            D_L08_001B3AA0 = D_L08_001B3AA0 + 1;
            *(s32 *)(s1 + 8) = 0x78;
        }
        if (func_2F9A60(s1 + 8) != 0) {
            D_L08_001B3AA0 = D_L08_001B3AA0 - 1;
            func_31D540(a0);
        }
        return;
    }
}
