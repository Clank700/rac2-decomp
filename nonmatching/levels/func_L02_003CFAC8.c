/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 1820 bytes; retail: 1832 bytes.
 * Remaining difference: 1820 bytes versus 1832. The function-scope position view and actor pointer have different saved-register assignments from retail; prologue/global-test scheduling and later branches differ. The complete constructor and emitter argument banks are retained.
 * Reopen only with: A qualified actor/position access shape and state lifetime that explains the retail register interference while retaining the six-GPR/three-FP emitter and twelve-GPR/two-FP constructor.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
extern int D_L02_001CAA80;
extern char *D_L02_001C0958;
extern char D_00189E20[] NOT_SDA, D_L02_001BA3C0[];
extern u16 D_0018CA60;
extern Vector D_L02_001BA500;
extern int D_L02_001B0130 __attribute__((sda)), D_L02_001B0138 __attribute__((sda));
extern float D_L02_001B0134 __attribute__((sda));
extern int D_L02_001B013C __attribute__((sda)), D_L02_001B0140 __attribute__((sda));
extern float func_002A89A8(void *, int, float), func_00282E48(void *, void *), func_00283B98(float, float), func_002AA340(int *, int, int);
extern void func_L01_0031AB20(char *, void *, int, float, float, float), func_002A7750(u8 *, int, int), func_L02_003D0238(char *), func_L02_003D02F0(char *);
extern int func_00283CF0(float), func_002B3868(u8 *), func_002B38B8(u8 *), func_00282948(int *), func_002E5CF8(int, int, char *), func_002E5DA0(int, int, char *, int);
extern int func_L01_0031BC68(int, int, float), func_00277258(void *, int, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002A8C28(void *, float, float *, int, float, float, int, int, int);
/* Full constructor: position, seven register words, four stack words, and two FP inputs. */
extern void *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
/* Drives the timed platform through activation, falling, detonation and respawn. */
void func_L02_003CFAC8(char *self) {
    Vector point;
    char *position=self + 0x10;
    char *state;
    float shake, radius;
    int timer, hits, i, old;
    if (D_L02_001CAA80) return;
    state = *(char **)(self + 0x68);
    switch (((u8 *)self)[0x20]) {
    case 0:
        ((u8 *)self)[0x30] = 0xFF; *(u16 *)(self + 0x34) |= 0x1000;
        *(float *)(state + 0xE0) = 0.333f; *(float *)(state + 0x84) = 2.75f;
        *(u32 *)(state + 0x70) |= 6; ((u8 *)self)[0x20] = 1;
        *(float *)(self + 0x18) = func_002A89A8(position, 0, 0.5f) + 0.7f;
        *(float *)(state + 0x88) = D_L02_001C0958 ? 14.5f : 10.0f;
        qcopy(state + 0xA0,position);
        break;
    case 1:
        func_L01_0031AB20(self, state + 0x50, -1, 0.5f, 0.5f, 0.1f);
        if (D_L02_001B0130) { D_L02_001B0130 = 0; goto detonate; }
        if (*(char **)(D_00189E20 + 0x5C0) != self) break;
        D_0018CA60 = 0xFFFF; func_002A7750((u8 *)self, 2, -1);
        *(int *)(state + 0xD4) = func_00283CF0(*(float *)(state + 0xC0) * 60.0f);
        break;
    case 2:
        if (func_002B3868((u8 *)self)) *(int *)(state + 0xDC) = 0;
        func_L01_0031AB20(self, state + 0x50, -1, 0.5f, 0.5f, 0.1f);
        if (*(int *)(state + 0xC4) != -1 && *(char **)(D_00189E20 + 0x5C0) == self) func_L02_003D02F0(self);
        timer = *(int *)(state + 0xD4);
        if (timer % 60 == 10 || (timer < 120 && timer % 30 == 10)) func_002E5DA0(1, 0, self, 0x1F9);
        if (func_00282948((int *)(state + 0xD4))) goto detonate;
        if (func_002B38B8((u8 *)self)) func_002A7750((u8 *)self, 3, -1);
        break;
    case 4:
        func_00282CC0(position, position, state + 0xB0);
        *(float *)(state + 0xB8) -= 0.004166667f;
        hits = 0; i = 0;
        do {
            qcopy(&point,position);
            point.f[2] += (float)i; ++i;
            if (func_00277258(&point, 0, self, *(float *)(state + 0xE0))) hits = 1;
        } while (i < 1);
        if (hits || *(float *)(self + 0x18) < *(float *)(state + 0xA8) - 1.0f) func_002A7750((u8 *)self, 5, -1);
        if (*(float *)(position) < 2 || *(float *)(position) > 1021 || *(float *)(self + 0x14) < 2 ||
            *(float *)(self + 0x14) > 1021 || *(float *)(self + 0x18) < 2 || *(float *)(self + 0x18) > 1021) goto respawn;
        break;
    case 5:
        if (func_002B3868((u8 *)self)) {
            func_0032C700(position, 1, 25, 20, 20, 20, 45, 0, 1, 1, 0, 0, D_L02_001B0134, 20.0f);
            ((u8 *)self)[0x31] = 0; *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 1) & 0xEFFF;
            func_002E5CF8(1, 0, self);
            shake = (24.0f - func_00282E48(&D_L02_001BA500, position)) * 0.0062500006f;
            if (shake > 0.15f) shake = 0.15f; else if (shake < 0) shake = 0;
            if (shake != 0) {
                *(int *)(D_L02_001BA3C0 + 0x188) = 90;
                *(int *)(D_L02_001BA3C0 + 0x16C) = 0;
                *(float *)(D_L02_001BA3C0 + 0x180) = shake;
            }
        }
        func_002A8C28(self, (float)*(u16 *)(self + 0x96) * 0.5f, (float *)(position), 0x830000, 5.0f, 1.0f, 0, 1, 0);
        if (D_L02_001C0958 && *(short *)(D_L02_001C0958 + 0xAA) == 0xC82) func_002AA340((int *)(state + 0xE4), 0, 4);
        if (*(u16 *)(self + 0x96) < 11) break;
        old = *(int *)(state + 0xE4); *(int *)(state + 0xE4) = old + 1;
        if (old + 1 < 8) *(float *)(state + 0xE0) = 0.333f;
        else {
            radius = (float)(old - 6) * 0.09514286f + 0.333f;
            *(float *)(state + 0xE0) = radius;
            if (radius > 1) *(float *)(state + 0xE0) = 1;
        }
        func_002A8C28(self, 6.0f, (float *)(position), 0x830000, 10.0f, 1.0f, 0, 1, 0);
respawn:
        func_002A7750((u8 *)self, 6, -1); break;
    case 6:
        qcopy(&point,state + 0xA0); point.f[2] += 0.7f;
        if (!func_00277258(&point, 5, self, 0.75f)) func_L02_003D0238(self);
        break;
    case 3: default: break;
    }
    goto finish;
detonate:
    func_002A7750((u8 *)self, 5, -1);
finish:
    if (((u8 *)self)[0x31]) {
        *(float *)(self + 0xF4) = func_00283B98(*(float *)(self + 0xF4), 0.026179943f);
        *(float *)(self + 0xF8) = func_00283B98(*(float *)(self + 0xF4), 0.015126189216971397f);
        if (((u8 *)self)[0x20] == 1) *(int *)(self + 0x78) = D_L02_001B0138;
        else {
            *(float *)(state + 0xD8) = func_00283B98(*(float *)(state + 0xD8), 0.20943955f);
            *(int *)(self + 0x78) = func_L01_0031BC68(D_L02_001B013C, D_L02_001B0140, *(float *)(state + 0xD8));
        }
    }
    ++*(u16 *)(self + 0x96);
}
