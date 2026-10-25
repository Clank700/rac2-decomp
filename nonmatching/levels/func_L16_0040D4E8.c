/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections
 * Coverage: US: 0/1; US2: 0/1; PAL: absent from catalogue.
 * Compiled text: 1496 bytes; retail: 1524 bytes.
 * Remaining difference: The complete interpolation prefix now has four full16-byte nodes, three
 * float progress/rate values and the measured sound handle. The real two position transfers use
 * qcopy and state dispatch follows the observed switch. Frame0xC0 now agrees; body1496/1524 still
 * differs in node/progress loop pointer lifetimes, sound-address formation and scheduling. Both
 * actual three-float coefficient arrays and all four explosion stack words remain. The factory
 * return and nullable stack-pointer contract are repaired.
 * Reopen when: Independent exact loop/global-owner lifetime evidence within this measured prefix;
 * do not add padding or alter the three-point interpolation/particle inputs.
 */

#include "common.h"
typedef int MissileQuadword __attribute__((mode(TI)));
typedef union { MissileQuadword q; float f[4]; } PositionVector;
/* Measured interpolation/sound prefix; the complete allocation extent is unknown. */
typedef struct {
    PositionVector point[4]; float progress[3]; u8 gap4C[4];
    float rate[3]; u8 gap5C[12]; int sound;
} MissileState;
extern u8 D_00188660[];
extern float D_00189EA0[4], D_L16_001B9B00[4];
extern int D_L16_001A8F00;
extern u8 *D_L16_001BFF58;
extern float D_L16_001B1648[3] __attribute__((sda));
extern float D_L16_001B1658[3] __attribute__((sda));
extern float D_L16_001B1664 __attribute__((sda));
extern int func_002E5CF8(int, int, void *);
extern void func_002E59F8(int), func_002A7470(void *, int, int, int);
extern void func_002AA548(float *, float *, float, float, float, float);
extern void func_00282CF0(void *, void *, void *), func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float), func_00282F20(void *, void *, float);
extern float func_00283248(float, float), func_002A78D8(float, float), func_002A7878(float, float);
extern void func_002AA800(float *, int, float, float), func_L16_0040DC70(u8 *);
extern void *func_002A9640(void *, int, int);
extern u8 *func_00273730(void *, int, int, int, void *, void *, void *, int, float, float);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, void *);
extern void func_0029F338(void *), func_002A7750(void *, int, int);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern void func_0032DA58(void *, void *, void *, float);
extern int func_002A8C28(void *, void *, int, int, float, float, float, int, int);

/* The sound handle indexes 0x70-byte resident records. The sound owner and
 * active byte are checked before stopping a handle that may have been reused. */
void func_L16_0040D4E8(u8 *moby)
{
    MissileState *state = *(MissileState **)(moby + 0x68);
    float oldPosition[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float velocity[4] __attribute__((aligned(16)));
    int handle, i;
    switch (moby[0x20]) {
    case 0:
        handle = state->sound;
        if (*(u8 **)(D_00188660 + handle * 0x70 + 0x88) != moby ||
            !D_00188660[handle * 0x70 + 0x74])
            state->sound = func_002E5CF8(0, 4, moby);
        qcopy(oldPosition, (moby + 0x10));
        qcopy((moby + 0x10), &state->point[0]);
        for (i = 0; i < 3; i++) {
            if (i == 0 || D_L16_001B1664 < state->progress[i-1]) {
                func_002AA548(&state->progress[i],
                    &state->rate[i], 1.0f,
                    D_L16_001B1648[i] * 0.00027777778f,
                    D_L16_001B1648[i] * 0.00027777778f,
                    D_L16_001B1658[i] * 0.016666668f);
                if (i == 2 && state->progress[1] > 0.95f && moby[0x43])
                    func_002A7470(moby, 0, 0, 20);
            }
            func_00282CF0(delta, &state->point[i+1], &state->point[i]);
            func_00282D30(delta, delta, state->progress[i]);
            func_00282CC0(moby + 0x10, moby + 0x10, delta);
        }
        func_002AA800((float *)(moby + 0xf8), 0,
            func_00283248(D_00189EA0[0] - *(float *)(moby + 0x10),
                D_00189EA0[1] - *(float *)(moby + 0x14)), 0.20943955f);
        func_L16_0040DC70(moby);
        if (func_002A9640(moby, 0x10000, 0) || D_L16_001A8F00 == 2) {
            func_002E5CF8(2, 0, moby);
            handle = state->sound;
            if (handle != -1 && *(u8 **)(D_00188660 + handle * 0x70 + 0x88) == moby &&
                D_00188660[handle * 0x70 + 0x74]) func_002E59F8(handle);
            state->sound = -1;
            for (i = 0; i < 3; i++) {
                float lifetime, size;
                if (i == 0) func_00282D30(velocity, moby + 0xd0, 0.15f);
                else if (i == 1) func_00282D30(velocity, moby + 0xd0, -0.15f);
                else if (i == 2) func_00282D30(velocity, moby + 0xe0, 0.10000001f);
                lifetime = func_002A78D8(90.0f, 180.0f);
                size = func_002A7878(5.0f, 15.0f);
                func_00273730(moby, 1, *(short *)(moby + 0xaa), i,
                    moby + 0x10, moby + 0xf0, velocity, 255, lifetime, size);
            }
            func_0032C700(moby + 0x10, 0, 0, 0, 0, 20, 45, 1,
                1.0f, 20.0f, 1, 0, 0, 0);
            func_0029F338(moby);
        } else {
            if (state->progress[2] >= 1.0f) func_002A7750(moby, 1, -1);
            if (func_002761F8(oldPosition, moby + 0x10, 0, moby, 0)) {
                if (D_L16_001BFF58 &&
                    (*(short *)(D_L16_001BFF58 + 0xaa) == 0xf78 ||
                     *(short *)(D_L16_001BFF58 + 0xaa) == 0x7e8)) return;
            } else {
                if (state->progress[1] < 0.9f) return;
                if (!func_00277258(moby + 0x10, 0, moby, 1.5f)) return;
            }
            func_002A7750(moby, 1, -1);
        }
        break;
    case 1:
        handle = state->sound;
        if (handle != -1 && *(u8 **)(D_00188660 + handle * 0x70 + 0x88) == moby &&
            D_00188660[handle * 0x70 + 0x74]) func_002E59F8(handle);
        state->sound = -1;
        func_002E5CF8(1, 0, moby);
        func_00282CF0(oldPosition, D_L16_001B9B00, moby + 0x10);
        func_00282F20(oldPosition, oldPosition, 1.0f);
        func_0032DA58(moby, moby + 0x10, oldPosition, 0.0f);
        func_002A8C28(moby, moby + 0x10, 0x10001, 0, 2.0f, 5.0f, 1.0f, 1, 0);
        func_0029F338(moby);
        break;
    }
}
