/*
 * Complete manual reconstruction retained as nonmatching; no coverage credit.
 * Fresh qualified-compiler checks, 2026-10-25.
 * Profile: -O2 -G8 -ffunction-sections
 * Coverage: US: 0/1; US2: 0/1; PAL: absent from catalogue.
 * Compiled text: 664 bytes; retail: 664 bytes.
 * Remaining difference: The full three local vectors and branch-specific captures are retained.
 * Snapshotting the heading result before preparing the control addresses removes the extra saved
 * state-field pointer; the observed orientation pointer lifetime restores664-byte size and
 * frame0x90. The first356 bytes agree after relocation normalization. Five argument-setup
 * instructions around AAA00 and final bound-store ordering still differ. A typed two-word bound
 * view was negative and remains private. The fifth A8D70 argument is the canonical integer bone
 * index.
 * Reopen when: A true control-expression/field lifetime witness for the remaining scheduling
 * differences; do not permute the canonical helper prototype or add artificial memory barriers.
 */

#include "common.h"
typedef int BossQuadword __attribute__((mode(TI)));
extern unsigned int D_L16_001B2648;
extern u8 *D_L16_001FE7C0[];
extern u8 *D_L16_001B2C0C;
extern float D_L16_001B9B00[4];
extern float D_L16_001B1750 __attribute__((sda));
extern float D_L16_001B18CC __attribute__((sda));
extern float D_L16_001B18D0 __attribute__((sda));
extern float D_L16_001B18D4 __attribute__((sda));
extern float func_002A7878(float, float);
extern int func_002A7820(int, int), func_002A77E0(int);
extern void func_0029FCC0(char *, int, char *);
extern void *func_002BAE50(void *, void *, int, int, int, int, int, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_002AAC80(float *, float, float, float, float);
extern float func_00283248(float, float);
extern void func_002AAA00(float *, float *, int, float, float, float, float);
extern int func_002A8D70(float, float, float, void *, int, int, int, int, int);
extern void func_L16_00410FA8(u8 *);
extern u8 *func_0029EFD0(int);
extern void func_002B37E8(u8 *, u8 *);
extern void func_002A7750(u8 *, int, int);
extern void func_00282C90(void *);
extern int func_00283DB8(void *, float);
extern void func_002830C0(void *, void *, void *);
extern float func_00283B98(float, float), func_00283180(float), func_00283198(float);
extern int func_00283CF0(float);
extern void func_0029F338(void *), func_002A0F48(void *);
extern void func_L16_004133B0(u8 *);

void func_L16_004110D0(u8 *moby, float dt)
{
    float point[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float step[4] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(moby + 0x68);
    u8 *path = D_L16_001FE7C0[*(int *)(state + 0x170)];
    int finalPoint = 1;
    float distance, heading;
    float *orientation;
    *(float *)(moby + 0x48) = *(float *)(state + 0x230) * 3.0f;
    *(float *)(*(u8 **)(state + 0x1f0) + 0x48) = *(float *)(moby + 0x48);
    if (*(int *)(state + 0x220) == *(int *)(state + 0x1f4) && *(int *)(state + 0x224) == *(int *)(state + 0x1f8)) {
        qcopy(point, (state + 0x200));
    } else {
        int previous = *(int *)(state + 0x22c);
        if (previous == *(int *)(state + 0x220) || previous == *(int *)(state + 0x224) ||
            *(int *)(state + 0x228) != *(int *)(state + 0x220) || *(int *)(state + 0x228) != *(int *)(state + 0x224)) func_L16_00410FA8(moby);
        qcopy(point, (path + *(int *)(state + 0x228) * 16 + 16));
        finalPoint = 0;
    }
    orientation = (float *)(moby + 0xf8);
    func_00282CF0(delta, point, moby + 0x10);
    delta[2] = 0.0f;
    distance = func_00282DF0(delta);
    func_002AAC80((float *)(state + 0x230), distance, D_L16_001B1750 * 0.00027777778f, D_L16_001B1750 * 0.00027777778f, dt);
    heading = func_00283248(delta[0], delta[1]);
    func_002AAA00(orientation, (float *)(state + 0x234), 0, heading, 0.00174532947f, 0.00174532947f, 0.104719773f);
    func_00282F20(step, delta, *(float *)(state + 0x230));
    func_00282CC0(moby + 0x10, moby + 0x10, step);
    if (!*(int *)(state + 0x26c)) {
        func_002A8D70(6.0f, 50.0f, 1.0f, moby, 0, 0x90000, 0, 1, 0);
        func_002A8D70(6.0f, 50.0f, 1.0f, moby, 1, 0x90000, 0, 1, 0);
    }
    if (!finalPoint && distance < 0.5f) {
        int current = *(int *)(state + 0x228);
        int previous = *(int *)(state + 0x22c);
        if (previous < current) { *(int *)(state + 0x224) = current; *(int *)(state + 0x220) = previous; }
        else { *(int *)(state + 0x224) = previous; *(int *)(state + 0x220) = current; }
    }
}
