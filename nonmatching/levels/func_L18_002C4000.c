/* Complete reconstruction; one branch target off (not linked).
 * Profile: -O2 -G0 -ffunction-sections (split addresses: retail keeps %hi(D_00189E20) in $s1).
 * 496/496 bytes, us 0/3 at +0x1CC only. 26 October 2026 (M10): the hero block through the Hero
 * union view (constant-address fields legitimized as a based register) closes every other
 * difference. Left: the last `beqz` (% 6 test) branches to the epilogue's `ld $s0` in retail,
 * one past it in ours (reorg treats the restore already done in the earlier bne slot as
 * redundant). Nested-if, return and inverted forms of the tail compile identically.
 * EXACT 3/3 in every release under the held compiler change on branch
 * hold/compiler-trap-redundant-barrier (f67a3bd6: reorg's redundant_insn search stops at a
 * division guard), found by M4. Land in src only once that change is approved.
 */
#include "common.h"
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s16 h[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; u8 *ptr[0x980]; TI128 q[0x260]; } Hero;
extern u8 D_00189E20[];
extern u32 D_00138320;
extern s32 D_L18_001AFBB0 MACRO_ADDR;
extern void func_L00_002D2168(s32, s32, float);
extern void func_L18_00428428(u8 *, s32);
#define H ((Hero *)D_00189E20)
void func_L18_002C4000(void)
{
    u8 *object;
    object = H->ptr[0x2290 / 4];
    if (*(s16 *)(object + 0xAA) != 0xEC0) {
        if ((D_00138320 & 0x80) && D_L18_001AFBB0 == 0 && H->h[0x1E0 / 2] == 0 && H->i[0x2294 / 4] != 0x6F) {
            H->b[0x22B8] = 1;
            H->b[0x22BA] = 1;
            if (object[0x43] != 11) {
                func_L00_002D2168(11, 1, 5.0f);
                H->f[0xC20 / 4] = 3.0f;
            }
        } else if (H->i[0xC28 / 4] & 2) {
            H->b[0x22B8] = 0;
            H->b[0x22BA] = 0;
            if (H->i[0x2294 / 4] == 0x8E) func_L00_002D2168(14, 0, 8.0f);
            else func_L00_002D2168(13, 0, 9.0f);
        }
    }
    object = H->ptr[0x2290 / 4];
    if (object[0x42] == 11 || (*(u64 *)(object + 0x40) & 0xFFFF0000ULL) == 0x0BFF0000ULL) {
        H->f[0xC20 / 4] = 3.0f;
        if (*(s16 *)(object + 0xAA) == 0xEE1) {
            if (H->i[0x1D8 / 4] > 3) {
                if (H->i[0x1D8 / 4] % 6 == 0) func_L18_00428428(object, 0);
                if ((H->i[0x1D8 / 4] + 3) % 6 == 0) func_L18_00428428(H->ptr[0x2290 / 4], 1);
            }
        } else if (*(s16 *)(object + 0xAA) == 0xED4 && H->i[0x1D8 / 4] % 6 != 0) {
            func_L18_00428428(object, 0);
        }
    }
}
