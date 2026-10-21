/* func_L18_004308F0 (1384 bytes, 1 place: level 18_damosel) - NEAR MISS, ONE WORD.
 *
 * This body compiles to 1384 bytes, retail's size, and 345 of retail's 346 words are retail's
 * (prologue, both calls to the shared helpers, the three id-list walks, the spawn block, the
 * float tests and the epilogue, delay slots included). tools/check.py (checked in
 * src/levels/18_damosel/L18_003F80A0.c, where this body replaces the marker): "instruction at
 * +0xe4 differs", and nothing else.
 *
 * The one word is a branch offset. Retail's second `if (state->f20 <= 0.0f && ...)` shares the
 * compare with the first one on the path that already made it:
 *
 *     retail                                     this C
 *     +00DC c.le.s $f1,$f0                       +00DC c.le.s $f1,$f0
 *     +00E4 bc1f   -> +0x114                     +00E4 bc1f   -> +0x118
 *     ...                                        ...
 *     +0108 mtc1 $zero,$f0   (other path)        +0108 mtc1 $zero,$f0
 *     +0110 c.le.s $f1,$f0                       +0110 c.le.s $f1,$f0
 *     +0114 nop              <- branch target    +0114 nop
 *     +0118 bc1fl  -> +0x164                     +0118 bc1fl  -> +0x164   <- branch target
 *
 * Retail's join label sits BEFORE the hazard nop that follows the compare, this C's after it.
 * cc1 prints `c.le.s ; #nop ; $L181: ; .set noreorder ; bc1fl`, and gas pads the compare at the
 * label (the `.set noreorder` that opens the branch flushes the pending delay, and the label
 * ends up after the nop that is emitted there). Measured with this repository's assembler on hand-written text: every
 * placement of the label and of `.set noreorder` between `c.le.s` and `bc1fl` gives the label
 * after the nop (also for bc1f, bc1t, bc1tl); only an explicit `nop` instruction written after the
 * label gives retail's layout (and gas then adds no second nop). No source spelling reaches that:
 * the label is the join of an `if` whose compare lives on one path only (gcse PRE inserted it on
 * the other path - that part IS retail's, see below), so it always falls between compare and
 * branch. A `!(t > 0.0f)` spelling removes the label problem only by turning the compare into
 * `c.lt.s ; bc1t`, which is not retail's.
 *
 * Checked directly: compiling this file with the game cc1, putting one `nop` line after the
 * `$L...:` label that follows the `c.le.s` in the assembly text, and assembling it with
 * build/compiler/tools/as gives a section that Placement.derive accepts at retail's address
 * (1384 bytes, no difference, the same relocations): this C needs nothing but that pad.
 *
 * It is not one function's quirk, and the retail layout follows a rule. Scanning the retail
 * programs of levels 0-30 for a branch target at or just after the hazard `nop` that follows a
 * `c.xx.s`, `mtc1`, `mfc1`, `ctc1` or `cfc1` (the cases whose nops lead to a `div.s` left out:
 * the assembler's division-floor rule puts those labels before the padding on purpose) gives 247
 * sites: all 192 whose target is reached by FORWARD branches (a join, as here) have the label
 * BEFORE the nop, and all 55 whose target is a BACKWARD branch (a loop head) have it AFTER the
 * nop. No exceptions either way. This repository's assembler puts every label after the nop, which
 * is right for the 55 (8 of those functions are matched C) and wrong for the 192, which lie in
 * about 160 functions (func_002B63C0, func_L00_003D1258, func_L00_003F4210, func_L00_004051C8,
 * func_L02_00411530, func_L02_003D0408, func_L06_0040C270, func_L07_003BA4D0, func_L11_003D90C0,
 * func_0027BD70, func_002BEBC0, ...); none of them is matched C. What would unblock them: gas
 * keeping a label that was referenced before its definition (every forward target) in front of the
 * delay nop, or cc1 writing an explicit `nop` after such a label.
 *
 * Smallest repro of the same layout: func_L02_00411530 (80 bytes, still an INCLUDE_ASM row).
 * This body (in a -G0 unit, `D_L02_001B2FE0` an `sda` float; the clamp of a state float to 0..1)
 *
 *     float *s = *(float **)(a0 + 0x68);  float x = s[0x3C / 4];
 *     if (x > 1.0f) x = 1.0f; else if (x < 0.0f) x = 0.0f;
 *     D_L02_001B2FE0 = 1.0f - x;
 *
 * compiles to retail's 80 bytes, word for word, except the first `bc1tl`, which retail aims at the
 * hazard `nop` after the `mtc1 $at,$f0` of the 1.0f reload (+0x40, label before the nop) and this
 * build at the `sub.s` behind it (+0x44). The same one-line text patch (a `nop` after the `$L7:`
 * label in cc1's output) makes this 80-byte body derive exactly at retail's address.
 *
 * What got the body this far (each measured with tools/check.py --diff / the word count):
 *   - the second f20 test and the first one share ONE load: `t20 = *(float *)(state + 0x20)`
 *     read once after the call and tested twice. With the load repeated in each test cse leaves
 *     two loads, two compares and a `mov.s`, 8 bytes too long; with the local, gcse's PRE moves
 *     the compare to the other path exactly as retail has it (`mtc1 $zero,$f0 ; c.le.s` at +0x108);
 *   - the spawn block written `if (v != 0) { init } else { destroy }` (retail lays the init
 *     first and the destroy call last);
 *   - the three vector words as three int locals (`&b0, &b1, &b2`, `ori $a2,$sp,4`), not an
 *     array: the array gives lw $a0/$a1/$a2/$a3 in the wrong order before the 0x2A0488 call;
 *   - the walk of the object's group (byte 0x21) in the rotated form with `if (e == 0) break;`.
 *
 * Callees (level 18 addresses -> names): 0x337BB0 func_002A9640, 0x341358 func_002B0ED8,
 * 0x334B70 func_002A6C58, 0x4329B0 func_L18_004329B0, 0x335738 func_002A77E0, 0x335668
 * func_002A7750, 0x432E78 func_L18_00432E78, 0x432D60 func_L18_00432D60, 0x343800 func_002B3380,
 * 0x32B0F8 func_0029EFD0, 0x32DB88 func_002A0F48, 0x335388 func_002A7470, 0x32D148 func_002A04B8,
 * 0x32D118 func_002A0488, 0x432E28 func_L18_00432E28, 0x344B10 func_002B3BA8.
 */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

extern u16 *D_L18_001FB320[];
extern u8 *D_L18_001B281C[] __attribute__((sda));
extern s32 D_L18_001B2838[] __attribute__((sda));

extern void func_002A7750(u8 *arg0, s32 arg1, s32 arg2);
extern u8 *func_002A9640(u8 *, s32, s32);
extern s32 func_002B0ED8(u8 *, u8 *, s32);
extern void func_002A6C58(u8 *, s32, s32);
extern s32 func_002A77E0(s32);
extern void func_002B3380(u8 *, u8 *, u8 *);
extern u8 *func_0029EFD0(s32);
extern void func_002A0F48(u8 *);
extern void func_002A7470(u8 *, s32, s32, s32);
extern void func_002A04B8(u8 *, s32 *, s32 *, s32 *);
extern void func_002A0488(u8 *, s32, s32, s32);
extern s32 func_002B3BA8(u8 *, s32, s32, s32, float, float);
extern void func_L18_004329B0(u8 *);
extern void func_L18_00432D60(u8 *);
extern void func_L18_00432E78(u8 *, s32, s32, s32);
extern s32 func_L18_00432E28(u8 *);

void func_L18_004308F0(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    u8 *t;
    u8 *e;
    u16 *p;
    u8 saved;
    s32 b0;
    s32 b1;
    s32 b2;
    float t20;

    t = func_002A9640(object, 0x10000, 1);
    if (t != 0) {
        if (*(u8 **)(t + 0x20) != 0) {
            if (*(s16 *)(*(u8 **)(t + 0x20) + 0xAA) == 0xF0A || *(s16 *)(*(u8 **)(t + 0x20) + 0xAA) == 0xF9E)
                *(s32 *)(t + 0x2C) = 0;
        }
        if ((u8)(object[0x20] - 1) < 2)
            *(s32 *)(t + 0x2C) = 0;
    }
    saved = object[0x94];
    if (func_002B0ED8(object, state + 0x50, 0)) {
        if (object[0x94] == 0xD || object[0x94] == 9 || object[0x94] == 0xA || object[0x94] == 0xB ||
            object[0x94] == 0xC || object[0x94] == 5)
            object[0x94] = saved;
        t20 = *(float *)(state + 0x20);
        if (*(u8 **)(state + 0x7C0) == 0) {
            if (t20 <= 0.0f) {
                func_002A6C58(object, 0, 3);
                func_L18_004329B0(object);
                return;
            }
        }
        if (t20 <= 0.0f && func_002A77E0(7) == 0) {
            *(float *)(state + 0x20) = 8.0f;
            *(s32 *)(object + 0x98) = *(s32 *)(*(u8 **)(object + 0x24) + 0x10);
            func_002A7750(object, 0xE, -1);
            *(s16 *)(state + 0x88) = 0;
            state[0x6A] = 0;
        } else {
            func_L18_00432E78(object, object[0x43], 0, 3);
        }
        func_L18_00432D60(object);
    }
    object[0xA8] = 0xFF;
    if (*(u8 **)(state + 0x188) != 0 && *(s16 *)(*(u8 **)(state + 0x188) + 0xAA) == 0xF59) {
        func_002A6C58(object, 0, 3);
        func_L18_004329B0(object);
    }
    if (*(u8 **)(state + 0x7C0) != 0) {
        func_002B3380(*(u8 **)(state + 0x7C0), *(u8 **)(*(u8 **)(state + 0x7C0) + 0x68) + 0x20, state + 0x20);
        if (!(*(u16 *)(*(u8 **)(state + 0x7C0) + 0x7C) & 2) && *(u8 **)(state + 0x7C4) == 0) {
            u8 *v = func_0029EFD0(0xF0C);
            *(u8 **)(state + 0x7C4) = v;
            if (v != 0) {
                v[0x30] = object[0x30];
                *(u16 *)(*(u8 **)(state + 0x7C4) + 0x32) = *(u16 *)(object + 0x32);
                *(long *)(*(u8 **)(state + 0x7C4) + 0x38) = *(long *)(object + 0x38);
                func_002A0F48(*(u8 **)(state + 0x7C4));
                *(s32 *)(*(u8 **)(state + 0x7C4) + 0x98) = 0;
                if ((*(u8 **)(state + 0x7C4))[0x43] != 0x14)
                    func_002A7470(*(u8 **)(state + 0x7C4), 0x14, 0, 3);
                *(u16 *)(*(u8 **)(state + 0x7C4) + 0x34) |= 6;
                *(u16 *)(*(u8 **)(state + 0x7C4) + 0x34) |= *(u16 *)(object + 0x34) & 0x8000;
                *(float *)(*(u8 **)(state + 0x7C4) + 0x2C) =
                    *(float *)(*(u8 **)(*(u8 **)(state + 0x7C4) + 0x24) + 0x24) * *(float *)(state + 0x7E8);
            } else {
                func_L18_004329B0(object);
            }
        }
        if (*(u8 **)(state + 0x7C0) != 0) {
            func_002A04B8(object, &b0, &b1, &b2);
            func_002A0488(*(u8 **)(state + 0x7C0), b0, b1, b2);
        }
    }
    if (*(u8 **)(state + 0x7C4) != 0) {
        func_002A04B8(object, &b0, &b1, &b2);
        func_002A0488(*(u8 **)(state + 0x7C4), b0, b1, b2);
    }
    if (*(s16 *)(state + 0x7F4) != -1) {
        *(u16 *)(state + 0x7F6) = 0;
        for (p = D_L18_001FB320[object[0x21]];
             object[0x21] != 0xFF && object[0x21] <= D_L18_001B2838[0] && p != 0 &&
             ((p != 0 && (s16)p[-1] >= 0) || p == D_L18_001FB320[object[0x21]]);
             p++) {
            e = D_L18_001B281C[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (func_L18_00432E28(e))
                *(u16 *)(state + 0x7F6) = *(u16 *)(state + 0x7F6) + 1;
        }
    } else {
        *(u16 *)(state + 0x7F6) = *(u16 *)(state + 0x7F4);
    }
    if (*(float *)(object + 0x18) < 90.0f ||
        (*(float *)(state + 0x800) != -1.0f && *(float *)(object + 0x18) < *(float *)(state + 0x800)))
        func_L18_004329B0(object);
    if (state[0x2E] == 2)
        func_L18_004329B0(object);
    if (*(float *)(state + 0x20) <= 0.0f) {
        if (object[0x20] != 0xD)
            func_L18_004329B0(object);
    }
    *(s32 *)(state + 0x79C) =
        func_002B3BA8(object, *(s32 *)(state + 0x790), 0, 0, *(float *)(state + 0x794), 0.0f);
    if (object[0x20] < 4) {
        if (object[0x20] != 3)
            return;
        if (object[0xBC] == 0)
            return;
    }
    if (*(float *)(state + 0x7E8) < 1.5f) {
        *(float *)(state + 0x7E8) = *(float *)(state + 0x7E8) + 0.01f;
        *(float *)(object + 0x2C) = *(float *)(*(u8 **)(object + 0x24) + 0x24) * *(float *)(state + 0x7E8);
        if (*(u8 **)(state + 0x7C0) != 0)
            *(float *)(*(u8 **)(state + 0x7C0) + 0x2C) =
                *(float *)(*(u8 **)(*(u8 **)(state + 0x7C0) + 0x24) + 0x24) * *(float *)(state + 0x7E8);
        if (*(u8 **)(state + 0x7C4) != 0)
            *(float *)(*(u8 **)(state + 0x7C4) + 0x2C) =
                *(float *)(*(u8 **)(*(u8 **)(state + 0x7C4) + 0x24) + 0x24) * *(float *)(state + 0x7E8);
        if (*(u8 **)(state + 0x7C8) != 0)
            *(float *)(*(u8 **)(state + 0x7C8) + 0x2C) =
                *(float *)(*(u8 **)(*(u8 **)(state + 0x7C8) + 0x24) + 0x24) * *(float *)(state + 0x7E8);
    }
}
