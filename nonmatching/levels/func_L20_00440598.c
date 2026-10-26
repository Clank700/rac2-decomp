/* Opus big26 handoff, 2026-10-26: func_L20_00440598 (5,920 bytes), first decompilation.
 * Step 0: one function (one prologue, one return); no matched twin (lead's slate).
 * Draft: m2c (mipsee target) with callee prototypes from src/, then a Sonnet first pass.
 * Profile: -O2 -G8 -ffunction-sections. Measured: 1480/1480 instructions, 1144 difflib-aligned, 360 same-address.
 * Control flow, jump tables and call sequences line up with retail.
 * Left: hero addressing: retail keeps D_00189EA0 in s0 and E20 as s1 = s0 - 0x80 (cases 6/16), a register E20 base in cases 7/13/24 (alt_hero_ptr.c in the big26 scratch had the shape, 6 short); case 17 loop constants 0xCBC/0xFE/0xFD/0xD0F in s6/s4/s1/s5; the entry bnel with a duplicated lbu 0x20; D_001B2AC8 tied lui/lw form; D_001A8F00 read both absolute and $gp (two names, two addressing forms, as MATCHING-BLOCKERS allows).
 */
#include "common.h"
extern int func_00282948(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282E80(void *, void *);
extern void func_00283098(void *, void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern f32 func_00283C80(f32, f32);
extern void func_00285788(int, int);
extern void func_00285828(int, int, int, int);
extern s32 func_00288AA0(u8 *, s32);
extern s32 func_00288BE8(u8 *);
extern int func_00288FB8(int);
extern void func_0029F338(void *);
extern float func_0029F530(char *);
extern void func_002A6C58(void *, int, int);
extern void func_002A7470(void *, int, int, int);
extern void func_002A7750(char *, int, int);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern float func_002A89A8(void *, int, float);
extern void func_002A8C28(s32, s32, s32, f32, f32, f32, s32, s32, s32);
extern float func_002AA2E8(float *, float, float);
extern void func_002AA800(s32, s32, f32, f32);
extern void func_002ACB48(float *, float);
extern int func_002ACBC8(void *, int);
extern s32 func_002AEB60(u8 *, f32);
extern int func_002B3868(u8 *);
extern int func_002B49E0(int, int, int, int, int);
extern void func_002BDBC0(char *, char *, int, int, int, float);
extern void func_002DF3F8(void *, void *);
extern void func_002E59F8(s32);
extern int func_002E5CF8(int, int, char *);
extern void func_L00_002B30E8(void);
extern void func_L00_002E6EF8(void *, void *);
extern void func_L00_002F3478(void);
extern int func_L01_00322288(void *, float);
extern void func_L20_0036E720(void);
extern void func_L20_0039DE88(char *arg0);
extern void func_L20_0039F210(char *arg0, char *arg1, int arg2);
extern void func_L20_00442140(char *arg0);
extern void func_L20_004424A0(char *actor);
extern void func_L20_00442740(char *arg0, float f);
extern void func_L20_004427C8(char *arg0, char *arg1, float f);
extern void func_L20_00442C10(char *arg0);
extern void func_L20_00442F30(char *arg0);
extern int func_L20_00443508(char *arg0, char *arg1);
extern char * func_L20_00443790(char *arg0, int arg1, char *arg2);
extern void func_L20_00443B60(char *, char *, char *, float *);
extern void func_L20_00444088(char *arg0);
extern void func_L20_00444AA8(char *arg0, float *arg1);
extern u8 D_00189E20[] MACRO_ADDR;
extern u8 D_00189EA0[];

extern void func_L20_00441CB8();
extern int func_L20_004421A8(char *);
extern int func_L20_00442550(char *);
extern void func_L20_00442F80(char *);
extern void func_L20_00442CD8(char *);
extern void func_L20_004435A0(char *);
extern void func_L20_00443A10(char *, char *);
extern int func_L20_00443CF0(char *);
extern void func_L20_00443D58(char *);
extern void func_L20_00443DF0(char *);
extern int func_L20_00444018(char *);
extern void func_L20_004441D8(char *);
extern int func_L20_00440398(int);
extern char *func_L20_0039EEC8(char *, char *);
extern void func_L20_0043F318(char *, void *, int, int, float, void *);
extern void func_L20_00440570(void);
extern s32 D_L20_001A8F00 __attribute__((sda));
extern s32 D_L20_001A8F08 __attribute__((sda));
extern f32 D_L20_001B2030 __attribute__((sda));
extern f32 D_L20_001B2038 __attribute__((sda));
extern f32 D_L20_001B2040 __attribute__((sda));
extern f32 D_L20_001B2054 __attribute__((sda));
extern f32 D_L20_001B2060 __attribute__((sda));
extern s32 D_L20_001B2070 __attribute__((sda));
extern s32 D_L20_001B2074 __attribute__((sda));
extern f32 D_L20_001B209C __attribute__((sda));
extern f32 D_L20_001B20A0 __attribute__((sda));
extern f32 D_L20_001B20B0 __attribute__((sda));
extern s32 D_L20_001B20C4 __attribute__((sda));
extern s32 D_L20_001B20C8 __attribute__((sda));
extern f32 D_L20_001B2100 __attribute__((sda));
extern u8 D_00188660[];
extern s32 D_001B29C0[];
extern s32 D_001B29E0[];
extern s32 D_001B2AC8[];
extern s32 D_001B2AD4[];
extern f32 D_001B2BE8[];
extern char * D_001B2FA8[];
extern char * D_001B308C[];
extern u8 D_001B9E80[];
extern s16 D_001C0184[];
extern u8 D_001C01C0[];
extern s32 D_001CA540[];
extern s32 D_0021FC18[];
extern s32 d_001A8F00[];
extern s8 d_001A8F20[];
extern f32 d_001B210C[];
extern char * D_0018C0B0[];
extern s32 D_0018C0B4[];
#define AT(T, p, o) (*(T *)((char *)(p) + (o)))

void func_L20_00440598(char *self) {
    float sp[16] __attribute__((aligned(16)));
    char *st;
    int ctr = D_001CA540[0];
    int v;
    int fl;
    char *s0;
    char *tb;

    if (ctr == 2) {
        st = AT(char *, self, 0x68);
        func_L20_00441CB8();
        if (AT(u8, self, 0x95) == 6) {
            if ((u32)(AT(u8, self, 0x20) - 0x18) < 2U) {
                if (func_002ACBC8(D_00189E20 + 0x80, AT(s32, st, 0x230)) != 0) {
                    qcopy(sp, &D_L20_001B2100);
                    qzero(&sp[4]);
                    sp[6] = d_001B210C[0];
                    func_002DF3F8(sp, &sp[4]);
                    D_L20_001B20A0 = D_L20_001B20A0 + 1.0f;
                    func_002A7750(self, 1, 0);
                    fl = d_001A8F00[0];
                } else {
                    fl = D_L20_001A8F00;
                }
                if (fl == ctr) {
                    AT(s32, self, 0x98) = 0;
                    AT(u16, self, 0x34) = (AT(u16, self, 0x34) | 0x41) & 0xEFFF;
                } else {
                    AT(u16, self, 0x34) = (AT(u16, self, 0x34) & 0xFFBE) | 0x1000;
                    AT(s32, self, 0x98) = AT(s32, AT(char *, self, 0x24), 0x10);
                }
            }
            if (D_001CA540[0] == 2) {
                D_001B2BE8[0] = AT(f32, self, 0x18) - 2.0f;
            }
        }
        switch (AT(u8, self, 0x20)) {
        case 1:
            if (func_002B3868(self) != 0 && AT(u8, self, 0x43) != 0x13) {
                func_002A7470(self, 0x13, 0, 0x14);
            }
            s0 = D_0018C0B0[0];
            func_L01_00322288(self, func_00283248(AT(f32, s0, 0x10) - AT(f32, self, 0x10), AT(f32, s0, 0x14) - AT(f32, self, 0x14)));
            if (AT(u8, self, 0x60) & 2) {
                func_L20_00442C10(self);
            }
            break;
        case 2:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 6) {
                    func_002A7470(self, 6, 0, 0x14);
                }
                func_L20_00442140(self);
                AT(s32, self, 0x9C) = 1;
            }
            tb = (char *)D_00188660 + AT(s32, st, 0x1854) * 0x70;
            if (AT(s32, tb, 0x88) != (s32)self || AT(u8, tb, 0x74) == 0) {
                AT(s32, st, 0x1854) = func_002E5CF8(1, 4, self);
            }
            if (AT(char *, st, 0x1850) != 0) {
                func_00283098(sp, &D_L20_001B20B0, self + 0xC0);
                func_00282CC0(sp, sp, self + 0x10);
                func_L20_0039F210(AT(char *, st, 0x1850), (char *)sp, 1);
            }
            if (func_L20_004421A8(self) != 0) {
                func_002A7750(self, 3, -1);
                v = AT(s32, st, 0x1854);
                if (v != -1 && (tb = (char *)D_00188660 + v * 0x70, AT(s32, tb, 0x88) == (s32)self)) {
                    if (AT(u8, tb, 0x74) != 0) {
                        func_002E59F8(v);
                    }
                }
                AT(s32, st, 0x1854) = -1;
            }
            break;
        case 3:
            if (func_002B3868(self) != 0) {
                func_L20_004424A0(self);
                if (AT(u8, self, 0x43) != 6) {
                    func_002A7470(self, 6, 0, 0x14);
                }
                AT(s32, self, 0x9C) = 1;
                if (AT(char *, st, 0x1850) == 0) {
                    if (AT(s32, st, 0x17F8) != 0) {
                        AT(char *, st, 0x1850) = func_L20_0039EEC8(self, self + 0x10);
                    }
                }
            }
            if (AT(char *, st, 0x1850) != 0) {
                func_00283098(sp, &D_L20_001B20B0, self + 0xC0);
                func_00282CC0(sp, sp, self + 0x10);
                func_L20_0039F210(AT(char *, st, 0x1850), (char *)sp, 0);
            }
            func_002AA800(st + 0x1804, 0, 0.0f, 0.10471977f);
            if (func_L20_00442550(self) != 0) {
                if (D_0018C0B4[0] != 0x8C && (func_00282948(st + 0x17F8) == 1 || D_L20_001B20C8 != 0)) {
                    if (AT(s32, st, 0x1810) > 0) {
                        AT(s32, st, 0x1810) = -1;
                        func_L20_00442F80(self);
                    }
                    func_L20_00442C10(self);
                    AT(s32, self, 0x9C) = 2;
                } else {
                    func_002A7750(self, 2, 1);
                }
            }
            break;
        case 4:
            if (func_002B3868(self) != 0) {
                func_L20_00442740(self, D_L20_001B2038);
                if (AT(u8, self, 0x43) != 2) {
                    func_002A7470(self, 2, 0, 0x14);
                }
            }
            s0 = AT(char *, st, 0x17FC);
            func_L20_004427C8(self, s0 + 0x10, func_00283248(AT(f32, s0, 0x10) - AT(f32, self, 0x10), AT(f32, s0, 0x14) - AT(f32, self, 0x14)));
            if (func_L20_00443508(self, AT(char *, st, 0x17FC)) == 0) {
                func_002A7750(self, 1, -1);
            } else {
                if (AT(f32, st, 0x11C) <= D_L20_001B2038 || AT(u16, self, 0x96) >= 0x12DU) {
                    func_002A7750(self, 5, -1);
                }
            }
            break;
        case 5:
            if (func_002B3868(self) != 0 && AT(u8, self, 0x43) != 0xB) {
                func_002A7470(self, 0xB, 0, 0xF);
            }
            if (func_0029F530(self) < 31.0f) {
                s0 = AT(char *, st, 0x17FC);
                func_L01_00322288(self, func_00283248(AT(f32, s0, 0x10) - AT(f32, self, 0x10), AT(f32, s0, 0x14) - AT(f32, self, 0x14)));
                if (func_L20_00443508(self, AT(char *, st, 0x17FC)) == 0) {
                    func_002A7750(self, 1, -1);
                }
            } else if (func_002AEB60((u8 *)self, 32.0f) != 0) {
                s0 = AT(char *, st, 0x17FC);
                func_00282D30(sp, &D_L20_001B2040, D_L20_001B2030);
                func_00283098(sp, sp, self + 0xC0);
                func_00282CC0(sp, sp, self + 0x10);
                AT(char *, st, 0x17FC) = func_L20_00443790(s0, AT(s16, s0, 0xAA), (char *)sp);
                AT(s32, st, 0x183C) = AT(s16, s0, 0xAA);
                func_L20_00442F30(s0);
                AT(f32, self, 0x48) = D_L20_001B2054;
            } else if (func_002AEB60((u8 *)self, 50.0f) != 0) {
                AT(f32, self, 0x48) = 1.0f;
            }
            if (func_0029F530(self) >= 60.0f) {
                func_L20_00442CD8(self);
                func_002A7750(self, 6, 3);
            }
            break;
        case 6:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 2) {
                    func_002A7470(self, 2, 0, 0x14);
                }
                func_L20_00442740(self, AT(f32, st, 0x1838) * 0.5f);
            }
            s0 = (char *)(D_00189E20 + 0x80);
            func_L20_004427C8(self, s0, func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14)));
            if (AT(f32, st, 0x11C) < AT(f32, st, 0x1838) && func_00283C80(AT(f32, self, 0xF8), func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14))) < 0.087266475f) {
                func_002A7750(self, AT(s32, st, 0x1834), -1);
            }
            break;
        case 7: {
            int n;
            f32 w;
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x11) {
                    func_002A7470(self, 0x11, 0, 0x14);
                }
                AT(s32, st, 0x180C) = 0;
            }
            n = 1;
            func_L01_00322288(self, func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14)));
            AT(s32, st, 0x1808) = D_001B2AC8[0];
            func_00283098(sp, &D_L20_001B2060, self + 0xC0);
            func_00282CC0(sp, sp, self + 0x10);
            do {
                qcopy(&sp[4], sp);
                n -= 1;
                func_002ACB48(&sp[4], 1.5f);
                sp[2] -= 0.5f;
                func_002BDBC0((char *)&sp[4], d_001A8F20, 0x60309030, 0x107090, 0x2D, func_002A7878(2.0f, 3.0f) * 210000.0f);
            } while (n >= 0);
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43) && func_00282948(st + 0x180C) != 0) {
                AT(s32, st, 0x180C) = D_L20_001B2070;
                func_L20_00443B60(self, (char *)&sp[4], (char *)&sp[8], &sp[12]);
                sp[6] += 1.5f;
                func_L20_0043F318(self, &sp[4], 0x78, func_002A77E0(2), (f32)AT(u8, st, 0x35), st + 0x1808);
            }
            if (D_L20_001B2074 < (s32)AT(u16, self, 0x96)) {
                func_002A7750(self, 1, -1);
            }
            break;
        }
        case 11:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x11) {
                    func_002A7470(self, 0x11, 0, 0x14);
                }
                AT(s32, st, 0x1840) = func_002A7820(0xA, 0xF);
            }
            func_L20_00444AA8(self, (float *)(D_00189E20 + 0x80));
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43) && (AT(u16, self, 0x96) % 60U) == 0x1E) {
                func_L20_00444088(self);
                func_00282948(st + 0x1840);
            }
            if (AT(s32, st, 0x1840) == 0) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 10:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x11) {
                    func_002A7470(self, 0x11, 0, 0x14);
                }
                AT(s32, st, 0x1840) = func_002A7820(0x1E, 0x32);
            }
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43) && (D_001B2AC8[0] & 7) == (((s32)self >> 8) & 7)) {
                func_L20_00443D58(self);
                func_00282948(st + 0x1840);
            }
            if (AT(s32, st, 0x1840) == 0) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 8:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x11) {
                    func_002A7470(self, 0x11, 0, 0x14);
                }
                AT(s32, st, 0x1840) = func_002A7820(0xA, 0x14);
            }
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43) && (D_001B2AC8[0] & 0x1F) == (((s32)self >> 8) & 0x1F)) {
                func_L20_00443DF0(self);
                func_00282948(st + 0x1840);
            }
            if (AT(s32, st, 0x1840) == 0) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 9:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x11) {
                    func_002A7470(self, 0x11, 0, 0x14);
                }
                AT(s32, st, 0x1840) = func_002A7820(4, 5);
            }
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43) && (D_001B2AC8[0] & 0x1F) == (((s32)self >> 8) & 0x1F)) {
                if (func_L20_00444018(self) != 0) {
                    func_00282948(st + 0x1840);
                } else {
                    AT(s32, st, 0x1840) = 0;
                }
            }
            if (AT(s32, st, 0x1840) == 0) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 12:
            if (func_002B3868(self) != 0 && AT(u8, self, 0x43) != 0x11) {
                func_002A7470(self, 0x11, 0, 0x14);
            }
            if ((D_001B2AC8[0] & 7) == (((s32)self >> 8) & 7)) {
                if (D_L20_001B20C4 != 0) {
                    func_002A7750(self, 0xD, -1);
                } else if (func_L20_00443CF0(self) == 0 || func_L20_00440398(AT(s32, st, 0x21C)) >= 0x15) {
                    func_002A7750(self, 0xD, -1);
                }
            }
            break;
        case 13:
            s0 = st + 0x17D0;
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 2) {
                    func_002A7470(self, 2, 0, 0x14);
                }
                func_L20_00443A10(self, s0);
                func_L20_00442740(self, 1.0f);
            }
            func_L20_004427C8(self, s0, func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14)));
            if (AT(f32, st, 0x11C) < 1.0f && func_00283C80(AT(f32, self, 0xF8), func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14))) < 0.087266475f) {
                func_002A7750(self, 0xE, -1);
            } else if (func_L20_00440398(AT(s32, st, 0x21C)) < 3) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 14:
            if (func_002B3868(self) != 0 && AT(u8, self, 0x43) != 1) {
                func_002A7470(self, 1, 0, 0x14);
            }
            func_L20_00444AA8(self, (float *)(D_00189E20 + 0x80));
            if (func_00282E80(self + 0x10, D_00189E20 + 0x80) < D_L20_001B209C) {
                func_002A7750(self, 0xD, -1);
            }
            if (func_L20_00440398(AT(s32, st, 0x21C)) < 3) {
                func_002A7750(self, 1, -1);
            }
            break;
        case 15:
            if (func_002B3868(self) != 0 && AT(u8, self, 0x43) != 0x15) {
                func_002A7470(self, 0x15, 0, 0xA);
            }
            func_002AA2E8((f32 *)(self + 0x18), func_002A89A8(self + 0x10, 0, 0.5f), 0.16666667f);
            if (AT(u8, self, 0x60) & 2) {
                if (AT(u8, self, 0xBC) != 0) {
                    func_002A7750(self, 1, 0);
                    AT(u8, self, 0xBC) = 0;
                } else {
                    func_002A7750(self, 0x10, -1);
                    AT(u8, self, 0xBC) = 0;
                }
            }
            break;
        case 16: {
            f32 dist;
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 7) {
                    func_002A7470(self, 7, 0, 0x14);
                }
                func_L20_00442740(self, 1.0f);
                AT(s32, st, 0x1830) = 0;
            }
            if (AT(u8, self, 0x60) & 2) {
                switch (AT(u8, self, 0x42)) {
                case 7:
                    if (AT(u8, self, 0x43) != 8) {
                        func_002A7470(self, 8, 0, 1);
                    }
                    break;
                case 8:
                    if (AT(u8, self, 0x43) != 9) {
                        func_002A7470(self, 9, 0, 1);
                    }
                    break;
                case 9:
                    AT(s32, st, 0x1830) = AT(s32, st, 0x1830) + 1;
                    break;
                }
            }
            if (AT(s32, D_00189E20, 0x2294) == 0x8C) {
                AT(s16, D_00189E20, 0x1E0) = 0xF;
            }
            dist = func_0029F530(self);
            if (AT(u8, self, 0x42) == AT(u8, self, 0x43)) {
                if ((AT(u8, self, 0x42) == 8 && dist < 9.0f) || (AT(u8, self, 0x42) == 9 && dist > 12.0f && dist < 30.0f)) {
                    s0 = (char *)(D_00189E20 + 0x80);
                    func_L20_004427C8(self, s0, func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14)));
                    if (AT(u8, self, 0x42) == AT(u8, self, 0x43)) {
                        if ((AT(u8, self, 0x42) == 8 && dist < 9.0f && dist > 7.0f) || (AT(u8, self, 0x43) == 9 && dist > 25.0f && dist < 30.0f)) {
                            qcopy(sp, self + 0x10);
                            sp[2] += 1.0f;
                            func_002A8C28(self, sp, 0x10008, 5.5f, (f32)AT(u8, st, 0x34), 2.0f, 0, 1, 0);
                        }
                    }
                }
            }
            if (AT(u8, self, 0x42) == 8 && func_002AEB60((u8 *)self, 6.0f) != 0) {
                AT(f32, D_001B9E80, 0x180) = 0.05f;
                AT(s32, D_001B9E80, 0x188) = 0x2D;
                AT(s32, D_001B9E80, 0x16C) = 0;
            }
            if (AT(u8, self, 0x42) == 9 && func_002AEB60((u8 *)self, 30.0f) != 0) {
                if (AT(s32, st, 0x1830) >= 2 || AT(s32, D_00189E20, 0x2294) == 0x8C) {
                    func_L20_004441D8(self);
                    func_002A7750(self, 3, -1);
                }
                AT(s32, D_001B9E80, 0x188) = 0x2D;
                AT(s32, D_001B9E80, 0x16C) = 0;
                AT(f32, D_001B9E80, 0x180) = (f32)(AT(s32, st, 0x1830) + 1) * 0.05f;
            }
            break;
        }
        case 17:
            if (func_002B3868(self) != 0) {
                if (AT(u8, self, 0x43) != 0x15) {
                    func_002A7470(self, 0x15, 0, 0xA);
                }
                s0 = D_001B2FA8[0];
                v = D_L20_001A8F00;
                if (s0 != 0) {
                    int c1 = 0xCBC, c2 = 0xFE, c3 = 0xFD, c4 = 0xD0F;
                    int id = AT(s16, s0, 0xAA);
                    do {
                        if (id == c1 && s0 != 0) {
                            u8 k = AT(u8, s0, 0x20);
                            if (k != c2 && k != c3) {
                                func_0029F338(s0);
                            }
                            id = AT(s16, s0, 0xAA);
                        }
                        if (id == c4 && s0 != 0) {
                            u8 k = AT(u8, s0, 0x20);
                            if (k != c2 && k != c3 && AT(u8, s0, 0x21) == AT(s32, st, 0x21C)) {
                                func_002A6C58(s0, 0, 3);
                                func_L20_0039DE88(s0);
                            }
                        }
                        s0 = AT(char *, s0, 0x28);
                        if (s0 != 0) {
                            id = AT(s16, s0, 0xAA);
                        }
                    } while (s0 != 0);
                    v = d_001A8F00[0];
                }
            } else {
                v = d_001A8F00[0];
            }
            if (v == 2) {
                AT(s32, self, 0x98) = 0;
                AT(u16, self, 0x34) = (AT(u16, self, 0x34) | 0x41) & 0xEFFF;
            }
            if (AT(u8, self, 0x60) & 2) {
                AT(s32, self, 0x48) = 0;
            }
            break;
        case 18:
            if (func_002B3868(self) != 0) {
                D_001B29C0[0] = 0;
                func_002B49E0(9, 1, 0, 0, 0);
            }
            if (d_001A8F00[0] == 0 && D_L20_001A8F08 <= 0 && func_00288AA0(D_001C01C0, 0x1E) != 0) {
                func_00288BE8(D_001C01C0);
                func_002A7750(self, 0x13, -1);
            }
            break;
        case 19:
            if (d_001A8F00[0] == 0) {
                v = D_L20_001A8F00;
                if (D_L20_001A8F08 <= 0) {
                    D_001B2AD4[0] = 1;
                    func_002B49E0(9, 1, 0, 0, 0);
                    func_002A7750(self, 0x14, -1);
                    v = d_001A8F00[0];
                }
                if (v == 0) {
                    func_L00_002E6EF8(func_L20_00440570, self);
                }
            }
            break;
        case 20:
            if (d_001A8F00[0] == 0 && D_L20_001A8F08 <= 0 && func_00288AA0(D_001C01C0, 0x1F) != 0) {
                func_00288BE8(D_001C01C0);
                func_002A7750(self, 0x15, -1);
            }
            break;
        case 21:
            if (d_001A8F00[0] == 0 && D_L20_001A8F08 <= 0) {
                int a, b;
                func_002A7750(self, 0x16, -1);
                a = func_00288FB8(0x325E);
                b = func_00288FB8(0x3210);
                func_00285828(a, b, func_00288FB8(0xA1F), 1);
                func_00285788(0x40, 0x20);
                func_002B49E0(4, 1, 9, 0, 0);
            }
            break;
        case 22:
            D_001B29E0[0] = 0;
            if (D_001C0184[0] == 1) {
                func_L20_0036E720();
                func_002A7750(self, 0x17, -1);
            } else {
                char *t;
                func_L00_002F3478();
                t = D_001B308C[0] + (AT(s32, st, 0x248) << 7);
                func_002DF3F8(t + 0x30, t + 0x70);
                D_0021FC18[0] = 0;
                func_L00_002B30E8();
            }
            break;
        case 24:
            s0 = st + 0x17D0;
            if (func_002B3868(self) != 0) {
                f32 mag = func_002A7878(5.0f, 15.0f);
                f32 ang = func_002A7940();
                AT(f32, st, 0x17D0) = func_00283180(ang) * mag;
                AT(f32, st, 0x17D4) = func_00283198(ang) * mag;
                AT(s32, st, 0x17D8) = 0;
                func_00282CC0(s0, s0, D_001B308C[0] + (AT(s32, st, 0x230) << 7) + 0x30);
                if (AT(u8, self, 0x43) != 2) {
                    func_002A7470(self, 2, 0, 0x14);
                }
                func_L20_00442740(self, 1.5f);
            }
            func_L20_004427C8(self, s0, func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14)));
            if (AT(f32, st, 0x11C) <= 1.5f && func_00283C80(AT(f32, self, 0xF8), func_00283248(AT(f32, D_00189E20, 0x80) - AT(f32, self, 0x10), AT(f32, D_00189E20, 0x84) - AT(f32, self, 0x14))) < 0.087266475f) {
                func_002A7750(self, 0x19, -1);
            }
            break;
        case 25: {
            int anim;
            if (func_002B3868(self) != 0) {
                anim = (func_002A77E0(3) != 0) ? 0x13 : 0x14;
                if (AT(u8, self, 0x43) != anim) {
                    func_002A7470(self, anim, 0, 0x14);
                }
            }
            if (AT(u8, self, 0x60) & 2) {
                func_002A7750(self, 0x18, -1);
            }
            break;
        }
        }
        func_L20_004435A0(self);
        if (AT(u8, self, 0x20) != 2) {
            v = AT(s32, st, 0x1854);
            if (v != -1) {
                tb = (char *)D_00188660 + v * 0x70;
                if (AT(s32, tb, 0x88) == (s32)self && AT(u8, tb, 0x74) != 0) {
                    func_002E59F8(v);
                }
            }
            AT(s32, st, 0x1854) = -1;
        }
    }
}
