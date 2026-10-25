/* Near miss: func_L08_0042F440, 544 bytes, 1 place (level 08 Tabora).
   Profile: -O2 -G0 -ffunction-sections (the shipped file's flags).

   wslcmp: `0 of 1 places match`, first differing word at +0x128; the body is
   544 bytes, i.e. retail's size, and every instruction up to +0x128 is equal.

   What matches: prologue, state dispatch, case 0, case 1 and case 2's condition
   are byte-identical, including all branch offsets.

   Remaining difference (all in two blocks):
   - func_002B0A68's argument setup. Retail's order in the a1=0xF arm is
     `daddu a0,s0` / 3.0f / 6.0f / `addiu a1,15` / `lui a2` + `addiu a2` /
     `mov.s f14` / `mov.s f15` / `jal` / `addiu a3,0xFF`; here `lui a2,%hi(D)`
     is hoisted into the beqz delay slot and `daddu a0,s0` takes the later slot.
     Declaring the last integer argument after the four floats moved that
     argument's `addiu` into the jal delay slot as retail has it, but did not
     change the a2/a0 order.
   - Case 3's D_L08_001B3AA0 increment: retail keeps address and value in one
     register (`lui a0` / `lw a0` / `addiu a0` / `lui at` / `sw a0`), the
     allocator here uses `$v1`, which also moves the 0x78 store value to
     `$a1`/`$v1` instead of `$v0` and swaps the `lhu`/`sb` order.

   Next hypotheses:
   - the two blocks are a sched2 tie: the address pseudo's priority beats the
     first-argument copy. Try a different declaration for the a2 data (typed
     struct pointer, `void *`) or a measured pointer parameter, then re-check
     that no other function in the unit moves.
   - section 19 of docs/MATCHING-BLOCKERS.md (delay-slot filler chosen by the
     scheduler) is the same wall; a shared hoisted setup would need a callee
     prototype where both arms share one call site, which retail's duplicated
     blocks rule out.

   Levers measured on the way:
   - `extern s32 D_L08_001B3AA0 __attribute__((sda));` at -G0 gives the absolute
     `lui`+`%lo` form in ordinary flow and the `$gp` form in a delay slot from a
     single declaration; no -g8 sibling is needed for that mixed access.
   - `st == 0xFE || (st == 0xFD || st == 3)` (right-nested OR) keeps retail's
     three separate compares; the left-associative form is folded by combine
     into a `(st + 3) & 0xFF < 2` range test. */

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
extern char *func_002A9640(s32 a, s32 b, s32 c);
extern void func_002A7750(char *a0, s32 a1, s32 a2);
extern void func_002B0A68(char *a0, f32 f12, f32 f13, s32 a1, char *a2,
                        f32 f14, f32 f15, s32 a3);
extern void func_L00_00326110(char *a0, s32 a1, f32 f12);
extern void func_002E5CF8(s32 a0, s32 a1, char *a2);
extern s32 func_002B3868(char *a0);
extern s32 func_00282948(char *a0);
extern void func_0029F338(char *a0);

void func_L08_0042F440(char *a0) {
    char *s1 = *(char **)(a0 + 0x68);
    u8 state = *(u8 *)(a0 + 0x20);
    char *p;
    s32 n;
    u8 st;

    switch (state) {
    case 0:
        func_002A7750(a0, 1, -1);
        return;
    case 1:
        p = func_002A9640((s32)a0, 0x04010000, 0);
        if (p != 0 && *(s32 *)s1 == 0) {
            func_002A7750(a0, 2, -1);
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
                func_002A7750(a0, 2, -1);
            }
        }
        return;
    case 2:
        if (*(u8 *)(a0 + 0x31) != 0 && D_L08_001B250C < 0.9f &&
            D_L08_001B3AA0 < 10) {
            func_002B0A68(a0, 3.0f, 6.0f, 15, D_L08_001A8F20, 3.0f, 6.0f, 0xFF);
        } else {
            func_002B0A68(a0, 3.0f, 6.0f, 9, D_L08_001A8F20, 3.0f, 6.0f, 0xFF);
        }
        func_L00_00326110(a0, 1, 0.0f);
        func_002E5CF8(0, 0, a0);
        func_002A7750(a0, 3, -1);
        return;
    case 3:
        if (func_002B3868(a0) != 0) {
            *(u8 *)(a0 + 0x31) = 0;
            *(u16 *)(a0 + 0x34) |= 1;
            *(s32 *)(a0 + 0x98) = 0;
            D_L08_001B3AA0 = D_L08_001B3AA0 + 1;
            *(s32 *)(s1 + 8) = 0x78;
        }
        if (func_00282948(s1 + 8) != 0) {
            D_L08_001B3AA0 = D_L08_001B3AA0 - 1;
            func_0029F338(a0);
        }
        return;
    }
}
