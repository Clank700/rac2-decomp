/* Opus big26 handoff, 2026-10-26: func_L17_003E7068 (6,636 bytes), first decompilation.
 * Step 0: one function (one prologue, one return); no matched twin (lead's slate).
 * Draft: m2c (mipsee target) with callee prototypes from src/, then a Sonnet first pass.
 * Profile: -O2 -G8 -ffunction-sections. Measured: 1657/1659 instructions, 1280 difflib-aligned, 378 same-address.
 * Control flow, jump tables and call sequences line up with retail.
 * Left: func_002A8D70 calls (first-switch case 3, second-switch case 12): retail writes stack words sp+0..0x24 directly (sin, cos, 1.0f, 5627.925f, self, 0x10001, bytes 0/1, u16 self+0xAA, float st+0x700, 1) with six int and three float register args; the draft fakes the frame with a dead Hit local, so the real prototype (stack arguments past a7/f19?) is the first thing to settle; retail keeps &v30 in $s3 through the second switch; st in $s4 (draft $s3 with a 0x64 spill); the case 8 loop exit (bc1tl with s6++ in the slot).
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
typedef struct { float sn, cs, one, big; void *obj; int flags; u8 z, o; u16 id; float val; int k; } Hit;
extern void func_0026FEB8(const char *, ...);
extern int func_002761F8(void *, void *, int, void *, int);
extern int func_00282948(void *);
extern int func_00282978(short *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283C80(float, float);
extern void func_0029F338(void *);
extern float func_0029F530(u8 *);
extern void func_0029FCC0(void *, int, void *);
extern void func_002A6C58(void *, int, int);
extern void func_002A7470(void *, int, int, int);
extern void func_002A7750(u8 *, int, int);
extern int func_002A77E0(int);
extern float func_002A89A8(void *, int, float);
extern int func_002A8D70(void *, float, float, int, int, float, int, int, int);
extern void func_002AA800(void *, int, float, float);
extern int func_002AD0E0(void *, void *, void *, void *, void *, void *);
extern int func_002B1C20(void *, void *);
extern int func_002B3868(u8 *);
extern int func_002B3890(u8 *);
extern int func_002B50E0(void *, void *, float);
extern void func_002B60B0(void *, float, float, float, float);
extern int func_L01_00321178(void *, void *);
extern void func_L01_003E9CF8(u8 *, int, void *);
extern void func_L02_0032E998(void *, void *, void *, void *, int, void *, void *, float, float);
extern int func_L02_0032EF10(void *, void *, void *, int, float);
extern void func_L17_0032C070(void *, void *, void *, int, float, float);
extern void func_L17_003C5AF8(u8 *);
extern int func_L17_003C5B68(u8 *);
extern void func_L17_003C7250(u8 *, u8 *);
extern int func_L17_003E6DE8(u8 *);
extern void func_L17_003E6F20(u8 *);
extern int func_L17_003E6F58(u8 *);
extern int func_L17_003E7010(u8 *);
extern void func_L17_003E8A58(void);
extern u8 D_00189E20[];
extern u8 *D_L17_001B2C1C[] __attribute__((sda));
extern int D_L17_001B3940[] __attribute__((sda));
extern u8 *D_001FB720[];
extern u8 *D_001FE880[];
extern Vec D_001B9BC0;
extern Vec D_001C0020;
extern char d_001B0ED0[], d_001B0EE8[], d_001B0F10[], d_001B0F20[];
extern float D_L17_001B0E3C __attribute__((sda));
extern float D_L17_001B0E58 __attribute__((sda));
extern int D_L17_001B0E68 __attribute__((sda));
extern int D_L17_001B0E6C __attribute__((sda));
extern float D_L17_001B0E70 __attribute__((sda));
extern float D_L17_001B0E74 __attribute__((sda));
extern float D_L17_001B0E7C __attribute__((sda));
extern float D_L17_001B0E80 __attribute__((sda));
extern float D_L17_001B0E88 __attribute__((sda));
extern int D_L17_001B0E8C __attribute__((sda));
extern float D_L17_001B0E90 __attribute__((sda));
extern int D_L17_001B0E94 __attribute__((sda));
extern int D_L17_001B0E9C __attribute__((sda));
extern float D_L17_001B0EA4 __attribute__((sda));
extern int D_L17_001B0EA8 __attribute__((sda));
extern float D_L17_001B0EAC __attribute__((sda));
extern float D_L17_001B0EB0 __attribute__((sda));
extern float D_L17_001B0EB4 __attribute__((sda));
extern float D_L17_001B0EB8 __attribute__((sda));
extern int D_L17_001B0EC0 __attribute__((sda));
extern int D_L17_001B0EC4 __attribute__((sda));
extern float D_L17_001B0EC8 __attribute__((sda));

void func_L17_003E7068(u8 *self) {
    Hit h;
    u8 *st = *(u8 **)(self + 0x68);
    float dist, ang, f0, f20, fa, fb, fc, fd, fe, ff, fg;
    Vec v30, v40, v50, *vp;
    float f60;
    int idx, s1, a1, a2, hit, n;
    u8 *o, *p, *pos;
    u8 k;

    func_L17_003E8A58();
    dist = func_00282E80(self + 0x10, st + 0x240);
    ang = func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14));
    idx = *(int *)(st + 0x6B8);
    if (idx != -1) {
        o = D_L17_001B2C1C[0] + (idx << 8);
        if (*(s16 *)(o + 0xAA) != 0x929) {
            func_0026FEB8(d_001B0ED0);
        } else {
            func_L17_003C7250(o, self);
        }
    }
    switch (self[0x95]) {
    case 5:
        func_002AD0E0(self, D_L17_001B2C1C[0] + (*(int *)(st + 0x6B8) << 8), self + 0x10, self + 0xF0, self + 0x10, self + 0xF0);
        idx = *(int *)(st + 0x6DC);
        if (idx == -1 || (o = D_L17_001B2C1C[0] + (idx << 8)) == self || o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD) {
            idx = *(int *)(st + 0x6B8);
            if (idx != -1) {
                if (*(s16 *)(st + 0x69E) == 1 && func_L17_003C5B68(D_L17_001B2C1C[0] + (idx << 8))) {
                    func_L17_003C5AF8(D_L17_001B2C1C[0] + (*(int *)(st + 0x6B8) << 8));
                    if (*(s16 *)(D_L17_001B2C1C[0] + (*(int *)(st + 0x6B8) << 8) + 0xAA) == 0x929) {
                        if (self[0x20] != 6) func_002A7750(self, 6, -1);
                        *(u16 *)(self + 0x34) = *(u16 *)(self + 0x34) & 0xFFBE;
                        *(int *)(self + 0x98) = *(int *)(*(u8 **)(self + 0x24) + 0x10);
                        *(float *)(self + 0xF8) = *(float *)(D_L17_001B2C1C[0] + (*(int *)(st + 0x6B8) << 8) + 0xF8);
                    } else if (self[0x20] != 6) {
                        func_002A7750(self, 6, -1);
                    }
                }
                break;
            }
            goto case0;
        }
        break;
    case 0:
    case0:
        if (*(s16 *)(st + 0x69E) == 1) {
            if (*(int *)(st + 0x730) == 0 || D_001FB720[self[0x21]] == 0 || func_L17_003E6DE8(self) != 0) {
                func_002A7750(self, 0xF, 2);
            } else {
                func_002A7750(self, 7, 6);
                if (self[0x43] != 1) func_002A7470(self, 1, 0, D_L17_001B0E9C);
            }
            func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, D_L17_001B0E70 * 0.016666668f, 0.10471977f, 0.10471977f);
            *(s16 *)(st + 0x69C) = 0xC8;
            *(int *)(st + 0x148) = *(int *)(st + 0x148) | 0x10;
        }
        break;
    case 2:
        if (*(s16 *)(st + 0x69E) == 1) *(s16 *)(st + 0x69C) = 0xC8;
        if (func_00282978((short *)(st + 0x69C)) != 0) {
            func_002A7750(self, 5, 4);
            if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
            if (self[0x43] != 3) func_002A7470(self, 3, 0, 0x14);
            *(s16 *)(st + 0x69C) = 0xDC;
        }
        break;
    case 4:
        if (*(s16 *)(st + 0x69E) == 1) {
            func_002A7750(self, 0xB, 2);
            func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, D_L17_001B0E70 * 0.016666668f, 0.10471977f, 0.10471977f);
            *(s16 *)(st + 0x69C) = 0xC8;
            *(int *)(st + 0x148) = *(int *)(st + 0x148) | 0x10;
        } else {
            goto b62;
        }
        break;
    case 6:
        if (func_L17_003E6DE8(self) != 0) {
            if ((self[0x42] != 1 && self[0x43] != 1) || (self[0x60] & 2)) {
                func_002A7750(self, 0xB, 2);
                func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, D_L17_001B0E70 * 0.016666668f, 0.10471977f, 0.10471977f);
                *(s16 *)(st + 0x69C) = 0xC8;
                *(int *)(st + 0x148) = *(int *)(st + 0x148) | 0x10;
            }
        } else {
            f20 = func_0029F530(self);
            if (*(s16 *)(st + 0x69E) == 1) *(s16 *)(st + 0x69C) = 0xC8;
            if ((self[0x60] & 2) && self[0x42] == 3 && self[0x43] != 0xE) func_002A7470(self, 0xE, 0, D_L17_001B0E9C);
            if (f20 >= 20.0f && self[0x42] == 0xE && self[0x43] != 3) func_002A7470(self, 3, 0, D_L17_001B0E9C);
            if (self[0x60] & 2) {
                if (self[0x42] == 1) {
                    if (self[0x43] != 0xE) func_002A7470(self, 0xE, 0, D_L17_001B0E9C);
                    goto b60;
                }
            } else {
b60:
                if (self[0x42] == 1) {
                    func_002AA800(self + 0xF8, 0, func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)), 0.10471977f);
                }
            }
b62:
            if (func_00282978((short *)(st + 0x69C)) != 0) {
                if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                if (self[0x43] != 2) func_002A7470(self, 2, 0, 0x14);
                func_002A7750(self, 3, 0);
            }
        }
        break;
    case 3:
        if (func_002B3890(self) != 0) {
            fa = *(float *)(self + 0x48);
            if (fa <= 0.0f || fa > 1.0f) *(float *)(self + 0x48) = 1.0f;
            func_002B60B0(self, (float)(D_L17_001B0E68 * 8) * 0.00027777778f, D_L17_001B0E70 * 0.13333334f, 0.10471977f, 0.10471977f);
        }
        if (*(float *)(self + 0x18) < D_L17_001B0E3C) goto b262;
        if (*(float *)(st + 0xE8) > 0.016666668f) {
            *(float *)(st + 0xE8) = 0.016666668f;
            func_0026FEB8(d_001B0F10);
        }
        hit = func_002B1C20(self, st + 0x60);
        if (hit & 1) {
            func_L01_003E9CF8(self, 0, 0);
            func_002A6C58(self, 0, 3);
        }
        fb = func_0029F530(self);
        if (fb >= 13.0f && fb <= 14.0f && self[0x42] == self[0x43]
            && func_00283C80(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)), *(float *)(self + 0xF8)) < 1.9198624f
            && func_00282E48(self + 0x10, st + 0x240) < D_L17_001B0E58) {
            k = self[0x42];
            if (k == 4) {
                if (func_L17_003E7010(self) != 0) {
                    h.obj = self;
                    h.flags = 0x10001;
                    h.val = *(float *)(st + 0x700);
                    h.sn = func_00283180(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)));
                    h.cs = func_00283198(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)));
                    h.one = 1.0f;
                    h.big = 5627.925f;
                    h.o = 1;
                    h.id = *(u16 *)(self + 0xAA);
                    h.k = 1;
                    h.z = 0;
                    a1 = self[0x42] == k ? D_L17_001B0EC4 : D_L17_001B0EC0;
                    func_002A8D70(self, D_L17_001B0EC8, *(float *)(st + 0x700), a1, 0x10001, 1.0f, 0, 1, 0);
                }
            }
        }
        if (self[0x42] != 4 && self[0x43] != 4) {
            a2 = hit & 2;
        } else {
            a2 = hit & 2;
            if (!(fb > 13.0f)) {
                func_L01_00321178(self, st + 0x240);
                a2 = hit & 2;
            }
        }
        if (a2 != 0 && D_L17_001B0EB0 <= fb) func_002A7750(self, 0xD, 2);
        if (self[0x42] == 0xD && D_L17_001B0EB4 <= fb) {
            if (self[0x43] != 4) func_002A7470(self, 4, 0, 8);
            *(s16 *)(D_00189E20 + 0x1DC) = 0;
        }
        break;
    }
    vp = &v30;
    switch (self[0x20]) {
    case 3:
        if (func_002B3868(self) != 0) {
            if (func_002A77E0(2) == 0) {
                if (self[0x43] != 2) func_002A7470(self, 2, 0, D_L17_001B0E9C);
            } else if (self[0x43] != 0xE) {
                func_002A7470(self, 0xE, 0, D_L17_001B0E9C);
            }
        }
        fg = func_0029F530(self);
        if ((self[0x42] == 2 && (self[0x60] & 2)) || (self[0x42] == 0xE && fg >= 20.0f)) {
            if (func_002A77E0(2) == 0) {
                if (self[0x43] != 2) func_002A7470(self, 2, 0, D_L17_001B0E9C);
            } else if (self[0x43] != 0xE) {
                func_002A7470(self, 0xE, 0, D_L17_001B0E9C);
            }
        }
        break;
    case 8:
        if (func_002B3868(self) != 0) {
            Vec *pb = &v40, *pc = pb;
            u8 *tgt = st + 0x710;
            pos = self + 0x10;
            s1 = 0;
            do {
                n = func_L17_003E6F58(self);
                qcopy(&v30, pos);
                qcopy(pc, D_001FE880[*(int *)(st + 0x684)] + (n << 4) + 0x10);
                v30.f[2] = v30.f[2] + 1.0f;
                v40.f[2] = v30.f[2];
                if (func_002761F8(&v30, pc, 0, self, 0) != 0) {
                    if (func_00282E80(pos, &D_001C0020) < 2.0f) {
                        s1++;
                        continue;
                    }
                    qcopy(tgt, &D_001C0020);
                } else {
                    qcopy(tgt, pb);
                }
                break;
            } while (s1 < 5);
            if (s1 != 5) {
                if (self[0x43] != 0xC) func_002A7470(self, 0xC, 0, D_L17_001B0E9C);
            } else {
                func_002A7750(self, 3, -1);
                break;
            }
        }
        hit = func_L01_00321178(self, st + 0x710);
        func_002AA800(self + 0xF8, 0, func_00283248(*(float *)(st + 0x710) - *(float *)(self + 0x10), *(float *)(st + 0x714) - *(float *)(self + 0x14)), 0.043633237f);
        if (!(hit & 0x80) && *(int *)(st + 0x190) < 0xB && !(hit & 0x10F)) {
        } else {
            func_002A7750(self, 3, -1);
        }
        break;
    case 6:
        if (func_002B3868(self) != 0) {
            if (*(s16 *)(D_L17_001B2C1C[0] + (*(int *)(st + 0x6B8) << 8) + 0xAA) != 0x929) {
                if (self[0x43] != 1) func_002A7470(self, 1, 0, D_L17_001B0E9C);
                func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, D_L17_001B0E70 * 0.016666668f, 0.10471977f, 0.10471977f);
                p = self + 0x10;
            } else {
                *(float *)(self + 0x48) = -1.0f;
                if (self[0x43] != 0xA) func_002A7470(self, 0xA, 0, D_L17_001B0E9C);
                func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, D_L17_001B0E70 * 0.016666668f, 0.10471977f, 0.10471977f);
                p = self + 0x10;
            }
            *(float *)(self + 0x18) = func_002A89A8(p, 0, 3.0f);
            qcopy(st + 0x6C0, p);
        }
        if (self[0x60] & 2) {
            if (self[0x42] == 1) {
                *(float *)(self + 0x48) = -1.0f;
                if (self[0x43] != 0xA) func_002A7470(self, 0xA, 0, 0x14);
                func_L01_00321178(self, self + 0x10);
                goto s6_157;
            }
            goto s6_159;
        }
s6_157:
        if (self[0x42] == 1) {
            *(float *)(self + 0x18) = func_002A89A8(self + 0x10, 0, 3.0f);
            break;
        }
s6_159:
        if (self[0x42] == 0xA) {
            vp->f[0] = func_00283180(*(float *)(self + 0xF8)) * 3.0f;
            vp->f[1] = func_00283198(*(float *)(self + 0xF8)) * 3.0f;
            vp->f[2] = 0.0f;
            func_00282CC0(&v40, self + 0x10, vp);
            *(float *)(self + 0x18) = func_002A89A8(self + 0x10, 0, 0.5f);
            func_L01_00321178(self, &v40);
            if (!(func_00282E80(self + 0x10, st + 0x6C0) > 4.9f)) {
            } else if (*(int *)(st + 0x730) == 0 || D_001FB720[self[0x21]] == 0 || (*(float *)(self + 0x48) = 1.0f, func_L17_003E6DE8(self) != 0)) {
                func_002A7750(self, 0xB, 2);
            } else {
                func_002A7750(self, 7, 6);
                if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                if (self[0x43] != 3) func_002A7470(self, 3, 0, 0x14);
            }
        }
        break;
    case 11:
        if (func_002B3868(self) != 0) {
            if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
            if (self[0x43] != 0xA) func_002A7470(self, 0xA, 0, D_L17_001B0E9C);
            fc = D_L17_001B0EB8;
            *(float *)(self + 0x48) = -fc;
            func_002B60B0(self, (float)D_L17_001B0E68 * 0.00027777778f, fc * D_L17_001B0E70 * 0.016666668f, 0.05817765f, 0.05817765f);
        }
        if (self[0x42] == 0xA) {
            if (dist < D_L17_001B0E7C) {
                qcopy(vp, &D_001B9BC0);
                if (func_00282E80(vp, self + 0x10) < D_L17_001B0EA4) {
                    if (*(int *)(st + 0x738) < D_L17_001B0EA8) {
                        vp->f[2] = *(float *)(st + 0x248);
                        func_00282CF0(vp, st + 0x240, vp);
                        func_00282F20(vp, vp, 2.0f * D_L17_001B0EA4);
                        func_00282CC0(vp, &D_001B9BC0, vp);
                        v40.q = *(Quad *)(self + 0x10);
                        func_L02_0032EF10(&v40, vp, vp, *(int *)(st + 0x684), 3.0f);
                        if ((D_L17_001B0EA4 + 0.3f) < func_00282E80(self + 0x10, vp)) {
                            func_L01_00321178(self, vp);
                            *(int *)(st + 0x738) = *(int *)(st + 0x738) + 1;
                            break;
                        }
                    } else {
                        goto s11_184;
                    }
                }
                if (*(int *)(st + 0x738) >= D_L17_001B0EA8) {
s11_184:
                    func_0026FEB8(d_001B0F20);
                }
                *(int *)(st + 0x738) = 0;
                func_002A7750(self, 0xC, -1);
                *(float *)(self + 0x48) = 1.0f;
                if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                if (self[0x43] != func_002A77E0(2) + 4) func_002A7470(self, func_002A77E0(2) + 4, 2, 0x14);
            } else {
                func_L02_0032E998(self + 0x10, st + 0x240, &f60, st + 0x280, 0, 0, 0, 0.0f, 0.5f);
                func_002B50E0(self, st + 0x240, f60);
                func_002AA800(self + 0xF8, 0, ang, 0.05817765f);
                if (*(int *)(st + 0x190) >= 0x3D) {
                    *(int *)(st + 0x704) = D_L17_001B0E8C;
                    func_002A7750(self, 4, -1);
                    *(float *)(self + 0x48) = 1.0f;
                    if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                    if (self[0x43] != 2) func_002A7470(self, 2, 0, 0x14);
                }
            }
        }
        break;
    case 15:
        if (func_002B3868(self) != 0 && self[0x43] != 1) func_002A7470(self, 1, 0, 0x14);
        func_002AA800(self + 0xF8, 0, func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)), 0.10471977f);
        if (self[0x60] & 2) func_002A7750(self, 0xB, -1);
        break;
    case 12:
        func_002AA800(self + 0xF8, 0, ang, 0.05817765f);
        fd = func_0029F530(self);
        if (fd >= 13.0f && fd <= 14.0f && self[0x42] == self[0x43]
            && func_00283C80(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)), *(float *)(self + 0xF8)) < 1.9198624f
            && func_00282E48(self + 0x10, st + 0x240) < D_L17_001B0E58
            && func_L17_003E7010(self) != 0) {
            h.obj = self;
            h.flags = 0x10001;
            h.val = *(float *)(st + 0x700);
            h.sn = func_00283180(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)));
            h.cs = func_00283198(func_00283248(*(float *)(st + 0x240) - *(float *)(self + 0x10), *(float *)(st + 0x244) - *(float *)(self + 0x14)));
            h.one = 1.0f;
            h.big = 5627.925f;
            h.o = 1;
            h.id = *(u16 *)(self + 0xAA);
            h.k = 1;
            h.z = 0;
            a1 = self[0x42] == 4 ? D_L17_001B0EC4 : D_L17_001B0EC0;
            func_002A8D70(self, D_L17_001B0EC8, *(float *)(st + 0x700), a1, 0x10001, 1.0f, 0, 1, 0);
        }
        if ((u32)(self[0x42] - 4) < 2U && D_L17_001B0EAC <= fd) func_002A7750(self, 0xD, -1);
        break;
    case 4:
        if (func_00282948(st + 0x704) != 0) {
            func_002A7750(self, 0xC, -1);
            if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
            if (self[0x43] != func_002A77E0(2) + 4) func_002A7470(self, func_002A77E0(2) + 4, 0, 0x14);
        }
        break;
    case 13:
        pos = self + 0x10;
        if (func_002B3868(self) != 0) {
            fe = func_00283B98(*(float *)(self + 0xF8), 3.141593f);
            vp->f[0] = func_00283180(fe) * D_L17_001B0E88;
            vp->f[1] = func_00283198(fe) * D_L17_001B0E88;
            vp->f[2] = 0.0f;
            func_00282CC0(vp, vp, self + 0x10);
            v40.q = *(Quad *)(self + 0x10);
            func_L02_0032EF10(&v40, vp, vp, *(int *)(st + 0x684), 3.0f);
            if (func_00282E48(self + 0x10, vp) < D_L17_001B0E88 * 0.5f) {
                func_L17_0032C070(self + 0x10, st + 0x240, vp, *(int *)(st + 0x684), D_L17_001B0E90, 1.0f);
            }
            qcopy(&v40, pos);
            v40.f[2] += 0.5f;
            qcopy(&v50, vp);
            v50.f[2] += 0.5f;
            if (func_002761F8(&v40, &v50, 2, 0, 0) != 0) qcopy(vp, &D_001C0020);
            qcopy(st + 0x710, vp);
            if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
            if (self[0x43] != 0xA) func_002A7470(self, 0xA, 0, D_L17_001B0E9C);
            func_002B60B0(self, (float)D_L17_001B0E6C * 0.00027777778f, D_L17_001B0E74 * 0.016666668f, 0.10471977f, 0.10471977f);
            *(int *)(st + 0x708) = D_L17_001B0E94;
            func_L17_003E6F20(self);
            *(float *)(self + 0x48) = D_L17_001B0EB8;
        }
        s1 = 0;
        hit = func_L01_00321178(self, st + 0x710);
        func_0029FCC0(self, 3, vp);
        if (func_002A89A8(vp, 0, 0.5f) < 10.0f) s1 = 1;
        if (!(hit & 0x80) && *(int *)(st + 0x190) < 0xA && !(hit & 0xF) && s1 != 1) {
        } else {
            *(float *)(self + 0x48) = 1.0f;
            if (dist < D_L17_001B0E7C + D_L17_001B0E80) {
                func_002A7750(self, 0xC, -1);
                if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                if (self[0x43] != func_002A77E0(2) + 4) func_002A7470(self, func_002A77E0(2) + 4, 0, 0x14);
            } else {
                func_002A7750(self, 7, 6);
                if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
                if (self[0x43] != 3) func_002A7470(self, 3, 0, 0x14);
            }
        }
        if (func_00282948(st + 0x708) != 0 && dist < D_L17_001B0E7C) {
            func_002A7750(self, 0xC, -1);
            *(float *)(self + 0x48) = 1.0f;
            if (self[0x43] != self[0x42]) func_0026FEB8(d_001B0EE8, self[0x42], *(s16 *)(self + 0xB2));
            if (self[0x43] != func_002A77E0(2) + 4) func_002A7470(self, func_002A77E0(2) + 4, 0, 0x14);
        }
        func_002AA800(self + 0xF8, 0, ang, 0.05817765f);
        break;
    case 9:
        if (func_002B3868(self) != 0 && self[0x43] != 7) func_002A7470(self, 7, 0, 0x14);
        qcopy(vp, self + 0x10);
        ff = *(float *)(self + 0x18) - 0.050000004f;
        vp->f[2] = 70.0f;
        *(float *)(self + 0x18) = ff;
        if (ff < 70.0f) {
b262:
            func_002A6C58(self, 0, 3);
            func_0029F338(self);
            return;
        }
        break;
    }
    func_0029FCC0(self, D_L17_001B3940[0], vp);
    if (func_002A89A8(vp, 0, 1.0f) < 20.0f && self[0x95] != 3 && self[0x20] != 9) {
        if (self[0x20] == 0xD || self[0x20] == 0xB) func_002A7750(self, 9, 7);
    }
}
