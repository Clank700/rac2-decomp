/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -mno-split-addresses
 * 364/356 bytes; 0/1 placements in us and us2; pal has no catalogue entry.
 * Residual: The three real 16-byte records and 0x60 frame are recovered; the record-copy addresses and invariant frame-step allocation differ.
 * Reopen: Independent evidence for the three scratch-record lifetimes and the scalar frame-step across the loop.
 * Trial-only markers and profiles are restored after checking.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector16;
extern float D_L16_001B18A0 __attribute__((sda));
extern float D_L16_001B18A4 __attribute__((nosda));
extern u32 D_L16_001B18A8 __attribute__((sda));
extern u32 D_L16_001B18C0 __attribute__((sda));
extern u32 D_L16_001B2648 __attribute__((nosda));
extern u32 D_L16_001B18AC __attribute__((nosda));
extern u32 D_L16_001B18B0 __attribute__((nosda));
extern u32 D_L16_001B18B4 __attribute__((nosda));
extern u32 D_L16_001B18C4 __attribute__((nosda));
extern u32 D_L16_001B18B8 __attribute__((nosda));
extern u32 D_L16_001B18BC __attribute__((nosda));
extern u32 D_L16_001B18C8 __attribute__((nosda));
extern void func_0029FCC0(void *, s32, void *);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern u8 *func_002BAE50(void *, void *, u32, s32, s32, s32, s32, s32);

/* Emits two pairs using three distinct aligned records. The acceleration copy
 * is local state for the emitter, not an extra argument to the joint query. */
void func_L16_00412F48(u8 *owner)
{
    Vector16 point;
    Vector16 parameter;
    Vector16 acceleration;
    float f;
    s32 i = 0;
    s32 value;
    do {
        acceleration.q = 0;
        f = func_002A7878(D_L16_001B18A0, D_L16_001B18A4);
        acceleration.f[2] = -(f * 0.016666668f);
        qcopy(&parameter, &acceleration);
        func_0029FCC0(owner, i, &point);
        if (D_L16_001B2648 & 1) {
            value = func_002A7820(0x12, 0x16);
            func_002BAE50(&point, &parameter, D_L16_001B18A8, D_L16_001B18AC,
                         value, D_L16_001B18C0, -10, 1);
        } else {
            value = func_002A7820(0x14, 0x18);
            func_002BAE50(&point, &parameter, D_L16_001B18B0, D_L16_001B18B4,
                         value, D_L16_001B18C4, -10, 1);
        }
        value = func_002A7820(10, 15);
        func_002BAE50(&point, &parameter, D_L16_001B18B8, D_L16_001B18BC,
                     value, D_L16_001B18C8, -10, 1);
        i++;
    } while (i < 2);
}
