/* Opus big26 handoff, 2026-10-26: func_L01_003C09C0 (7,360 bytes), first decompilation.
 * Step 0: one function (one prologue, one return); no matched twin (lead's slate).
 * Draft: m2c (mipsee target) with callee prototypes from src/, then a Sonnet first pass.
 * Profile: -O2 -G8 -ffunction-sections. Measured: 1848/1840 instructions, 1614 difflib-aligned (477 same-address: a +2 shift in inner case 9).
 * Control flow, jump tables and call sequences line up with retail.
 * Left: case 4 float select: retail has one jal with mov.s $f12,$f21 / bc1f / mov.s $f12,$f22, the draft has two calls (most of the +8); the repeated func_002B60B0 setup blocks (constant and gp-float order); the switch 5 case 1 loop roles (s5/s2/s1, the +-0.3 constants hoisted before the loop, a movz arm); case 4 reaches the hero data from one D_00189EA0 base (-0x80, +0x20 for D_00189F10, -0x70 for the qcopy), probably one pointer local; delay-slot hoists of D_L01_001AFE5C in inner switch 3 case 2.
 */
#include "common.h"
extern int func_002761F8(void *,void *,int,void *,void *);
extern s32 func_00277F48(f32, s32, s32, s32, s32);
extern void func_0027D330(s32);
extern s32 func_002829A8(void *a0);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern f32 func_00282DF0(void *);
extern f32 func_00282E20(void *);
extern f32 func_00282E48(void *, void *);
extern float func_00282E80(void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern f32 func_00283C80(f32, f32);
extern float func_00283CE0(int);
extern void func_0029F338(void *);
extern float func_0029F530(char *);
extern void func_0029FCC0(void *, int, void *);
typedef int TI128 __attribute__((mode(TI)));
extern void func_L01_003C01C0(void);
extern void func_L01_003BFE48(void *);
extern void func_L01_003C0140(void *);
extern float func_L01_003C0408(void *);
extern void func_L01_003C06E8(void *);
extern void func_L01_003C0760(void *);
extern void func_L01_003C07C8(void *);
extern void func_L01_003C0830();
extern void func_L01_003C08A0(void *);
extern void func_L01_003DA300(void *, void *, void *, float);
extern void *func_L01_004171C8(void *, int, int, int);
extern void func_L01_00394240(void *);
extern int func_1163B0(void);
#define NULL ((void *)0)
extern void func_002A0430(u32 a0);
extern void func_002A0F48(void *);
extern void func_002A6C58(void *, int, int);
extern void func_002A7750(char *, int, int);
extern float func_002A7790(float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern void func_002A8BD0(void *a0, int a1, int a2, float a3);
extern s32 func_002A8D70(void *, f32, f32, s32, s32, f32, s32, s32, s32);
extern void func_002A8E20(s32, void *);
extern s32 func_002AEB60(u8 *, f32);
extern int func_002B1C20(void *, void *);
extern void func_002B60B0(void *, float, float, float, float);
extern void func_002DF3F8(void *, void *);
extern void func_L00_002B30E8(void);
extern void func_L00_002B9D60(int a0, int a1, int a2, int a3);
extern void * func_L00_002D70A0(s32 size);
extern void func_L00_002D7140(char *);
extern void func_L00_00303530(int, int);
extern f32 func_L00_0031CDD0(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
extern s32 func_L01_002BEB90(s32 action, s32 animate);
extern int func_L01_00322288(void *, float);
extern void func_L01_00323310(int, int);
extern float func_L01_003BAFB0(void);
extern void func_L01_003BFDC8(void *, int, int, int);
typedef struct { u8 pad[0x80]; f32 x; f32 y; f32 z; u8 pad2[0x2204]; s32 a2290; s32 a2294; u8 pad3[4]; s32 a229c; u8 pad4[0x15]; u8 a22b5; u8 pad5[0x1EA]; s32 a24a0; u8 pad6[0x28]; s32 a24cc; } HeroV;
extern u8 D_00189E20[] NOT_SDA;
extern s32 D_0018C0B4 __attribute__((nosda));
extern u8 D_0018C0D5 __attribute__((nosda));
extern u8 D_00189EA0[] NOT_SDA;

extern s32 D_001A79F0 __attribute__((sda));
extern f32 D_L01_001AFE54 __attribute__((sda));
extern f32 D_L01_001AFE58 __attribute__((sda));
extern f32 D_L01_001AFE5C __attribute__((sda));
extern f32 D_L01_001AFE60 __attribute__((sda));
extern f32 D_L01_001AFE68 __attribute__((sda));
extern f32 D_L01_001AFE6C __attribute__((sda));
extern f32 D_L01_001AFE74 __attribute__((sda));
extern f32 D_L01_001AFE78 __attribute__((sda));
extern f32 D_L01_001AFE7C __attribute__((sda));
extern f32 D_L01_001AFE84 __attribute__((sda));
extern f32 D_L01_001AFE88 __attribute__((sda));
extern f32 D_L01_001AFE8C __attribute__((sda));
extern f32 D_L01_001AFE94 __attribute__((sda));
extern f32 D_L01_001AFE98 __attribute__((sda));
extern f32 D_L01_001AFE9C __attribute__((sda));
extern f32 D_L01_001AFEA0 __attribute__((sda));
extern f32 D_L01_001AFEA4 __attribute__((sda));
extern f32 D_L01_001AFEA8 __attribute__((sda));
extern f32 D_L01_001AFEAC __attribute__((sda));
extern f32 D_L01_001AFEB0 __attribute__((sda));
extern f32 D_L01_001AFEB4 __attribute__((sda));
extern f32 D_L01_001AFEB8 __attribute__((sda));
extern s32 D_L01_001AFEC0 __attribute__((sda));
extern s32 D_L01_001AFEC4 __attribute__((sda));
extern u8 D_L01_001AFEC8 __attribute__((sda));
extern s32 D_L01_001AFECC __attribute__((sda));
extern f32 D_L01_001AFEEC __attribute__((sda));
extern f32 D_L01_001AFEF0 __attribute__((sda));
extern f32 D_L01_001AFEF4 __attribute__((sda));
extern f32 D_L01_001AFEF8 __attribute__((sda));
extern u8 *D_L01_001B255C __attribute__((sda));
extern u8 *D_L01_001B264C __attribute__((sda));
extern u8 D_00189F10[] NOT_SDA;
extern u8 D_0019B2E8[] NOT_SDA;
extern u8 *D_001B255C;
extern u8 *D_001B264C;

void func_L01_003C09C0(u8 *arg0) {
    float sp[20] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f23;
    f32 var_f12_2;
    u8 *temp_a0_6;
    s32 temp_a1;
    s32 temp_a1_2;
    u8 *temp_a2;
    s32 temp_v0_4;
    s32 temp_v1_13;
    s32 temp_v1_14;
    s32 temp_v1_15;
    s32 temp_v1_19;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s5;
    u8 *temp_a0;
    u8 *temp_a0_3;
    u8 *temp_s1;
    u8 *temp_v1_12;
    u8 temp_s0;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_10;
    u8 temp_v1_11;
    u8 temp_v1_17;
    u8 temp_v1_18;
    u8 temp_v1_2;
    u8 temp_v1_5;
    u8 temp_v1_6;
    u8 temp_v1_7;
    u8 temp_v1_8;
    u8 temp_v1_9;
    u8 *temp_a0_2;
    u8 *temp_a0_4;
    u8 *temp_a0_5;
    u8 *temp_a1_3;
    u8 *temp_s0_2;
    u8 *temp_s0_3;
    u8 *temp_s0_4;
    u8 *temp_s1_2;
    u8 *temp_s1_3;
    u8 *temp_s4;
    u8 *temp_v0;
    u8 *temp_v0_3;
    u8 *temp_v0_5;
    u8 *temp_v0_6;
    u8 *temp_v0_7;
    u8 *temp_v1_16;

    temp_s4 = *(u8 **)(arg0 + 0x68);
    func_L01_003C01C0();
    temp_v1 = *(u8 *)(arg0 + 0x95);
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        temp_v1_2 = *(u8 *)(arg0 + 0xB0);
        if ((temp_v1_2 != 0xFF) && (D_0019B2E8[temp_v1_2 + (D_001A79F0 * 0x10)] & 0x80)) {
            temp_v1_3 = *(s32 *)(temp_s4 + 0x308);
            if (temp_v1_3 != -1) {
                (*(s8 *)((u8 *)(((temp_v1_3 << 8) + D_L01_001B255C)) + 0xBC)) = 1;
            }
            func_0029F338(arg0);
            return;
        }
        func_L01_003BFE48(arg0);
    default:
        break;
    case 1:                                         /* switch 1 */
        if (*(s32 *)(temp_s4 + 0x124) == 1) {
            if (*(u8 **)(temp_s4 + 0x2E4) == NULL) {
                func_L01_00323310(*(s32 *)(temp_s4 + 0x310), *(s32 *)(temp_s4 + 0x318));
                *(u8 **)(temp_s4 + 0x2E4) = func_L00_002D70A0(5);
            }
            func_002A7750(arg0, 0, 2);
        }
        break;
    case 2:                                         /* switch 1 */
        temp_f0 = func_L01_003C0408(arg0);
        if (temp_f0 == -1000.0f) {
            temp_a0 = *(u8 **)(temp_s4 + 0x2E4);
            if (temp_a0 != NULL) {
                func_L00_002D7140(temp_a0);
                *(u8 **)(temp_s4 + 0x2E4) = NULL;
            }
            func_002A7750(arg0, 0, 1);
            func_L01_003BFDC8(arg0, 0, 0, 0xA);
        } else {
            temp_v0 = *(u8 **)(temp_s4 + 0x120);
            temp_f21 = func_00283C80(*(f32 *)(arg0 + 0xF8), func_00283248(*(f32 *)(temp_v0 + 0x10) - *(f32 *)(arg0 + 0x10), *(f32 *)(temp_v0 + 0x14) - *(f32 *)(arg0 + 0x14)));
            switch (*(u8 *)(arg0 + 0xBC)) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
                if ((temp_f0 <= D_L01_001AFE5C) && (temp_f21 < (D_L01_001AFEAC * 0.017453294f)) && (*(s16 *)(temp_s4 + 0x2DC) == 0)) {
                    var_s0 = 1;
                    func_L01_003C06E8(arg0);
                } else {
                    var_s0 = D_L01_001AFECC < (s32) *(u16 *)(arg0 + 0x96);
                }
                if (var_s0 != 0) {
                    func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE84 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                    *(u8 *)(arg0 + 0xBC) = 1U;
                }
                if (*(f32 *)(temp_s4 + 0x20) < (2.0f * func_00283CE0((s32) *(s16 *)(temp_s4 + 0x24)) * 0.33333334f)) {
                    *(s8 *)(temp_s4 + 0x2E0) = 1;
                    *(u8 *)(temp_s4 + 0x2E1) = 5U;
                    *(s8 *)(temp_s4 + 0x2E2) = 0xE;
                    *(s8 *)(temp_s4 + 0x72) = 0x13;
                    *(s8 *)(temp_s4 + 0x71) = 0x13;
                    func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE88 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE54;
                    *(u8 *)(arg0 + 0xBC) = 3U;
                    func_L01_003BFDC8(arg0, 0x10, 0, 0xD);
                    func_002A7750(arg0, 0, 5);
                }
            default:                                /* switch 2 */
                break;
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                temp_v1_5 = *(u8 *)(arg0 + 0xBC);
                var_s1 = 0;
                switch (temp_v1_5) {                /* switch 3; irregular */
                case 1:                             /* switch 3 */
                    if ((temp_f0 <= D_L01_001AFE5C) && (temp_f21 < (D_L01_001AFEAC * 0.017453294f))) {
                        if ((func_002A77E0(D_L01_001AFEC0 - 1) == 0) && (*(s16 *)(temp_s4 + 0x2DC) == 0)) {
                            func_L01_003C06E8(arg0);
                        } else {
                            goto block_36;
                        }
                    } else {
block_36:
                        if ((D_L01_001AFE5C < temp_f0) && (temp_f0 <= D_L01_001AFE60) && (temp_f21 < (D_L01_001AFEB0 * 0.017453294f))) {
                            if ((func_002A77E0(D_L01_001AFEC4 - 1) == 0) && (*(s16 *)(temp_s4 + 0x2DA) == 0)) {
                                func_L01_003C07C8(arg0);
                            } else {
                                goto block_43;
                            }
                        } else {
block_43:
                            if (D_L01_001AFE68 < temp_f0) {
                                *(u8 *)(temp_s4 + 0x2E1) = 4U;
                                *(s8 *)(temp_s4 + 0x2E2) = 0x16;
                                *(s8 *)(temp_s4 + 0x2E0) = 0;
                                func_002B60B0(arg0, D_L01_001AFE9C * 0.00027777778f, D_L01_001AFEA0 * 0.016666668f, D_L01_001AFEA4 * 0.0000048481375f, D_L01_001AFEA8 * 0.00029088825f);
                                *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                                *(u8 *)(arg0 + 0xBC) = 2U;
                                *(s8 *)(temp_s4 + 0x72) = 0xF;
                                *(s8 *)(temp_s4 + 0x71) = 0xF;
                                func_L01_003BFDC8(arg0, 3, 0, 0xD);
                                func_002A7750(arg0, 0, 5);
                            }
                        }
                    }
                    break;
                case 2:                             /* switch 3 */
                    var_s1 = 0x3C;
                    *(s32 *)(arg0 + 0x98) = 0;
                    if ((temp_f0 <= D_L01_001AFE5C) && ((temp_v1_6 = *(u8 *)(arg0 + 0x42), (temp_v1_6 == 0x16)) || (temp_v1_6 == 0))) {
                        *(s8 *)(temp_s4 + 0x2E0) = 1;
                        *(u8 *)(temp_s4 + 0x2E1) = 1U;
                        *(s8 *)(temp_s4 + 0x2E2) = 0;
                        func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE84 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                        *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                        *(u8 *)(arg0 + 0xBC) = 1U;
                        *(s8 *)(temp_s4 + 0x72) = 0x13;
                        *(s8 *)(temp_s4 + 0x71) = 0x13;
                        *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                        func_L01_003BFDC8(arg0, 0x16, 0, 0x14);
                        func_002A7750(arg0, 0, 5);
                    }
                    break;
                }
                if (*(f32 *)(temp_s4 + 0x20) < (2.0f * func_00283CE0((s32) *(s16 *)(temp_s4 + 0x24)) * 0.33333334f)) {
                    *(s8 *)(temp_s4 + 0x2E0) = 1;
                    *(u8 *)(temp_s4 + 0x2E1) = 5U;
                    *(s8 *)(temp_s4 + 0x2E2) = 0xE;
                    *(s8 *)(temp_s4 + 0x72) = 0x13;
                    *(s8 *)(temp_s4 + 0x71) = 0x13;
                    func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE88 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE54;
                    *(u8 *)(arg0 + 0xBC) = 3U;
                    func_L01_003BFDC8(arg0, 0x10, 0, var_s1 + 0xD);
                    func_002A7750(arg0, 0, 5);
                }
                break;
            case 3:                                 /* switch 2 */
            case 4:                                 /* switch 2 */
            case 5:                                 /* switch 2 */
            case 6:                                 /* switch 2 */
                temp_s0 = *(u8 *)(arg0 + 0xBC);
                switch (temp_s0) {                  /* switch 4; irregular */
                case 3:                             /* switch 4 */
                    if ((temp_f0 <= D_L01_001AFE54) && (temp_f21 < (D_L01_001AFEB4 * 0.017453294f)) && (*(s16 *)(temp_s4 + 0x2DE) == 0)) {
                        func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE8C * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                        *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE58;
                        *(u8 *)(arg0 + 0xBC) = 4U;
                        *(s8 *)(temp_s4 + 0x2E2) = 0;
                        *(u8 *)(temp_s4 + 0x2E3) = (u8) D_L01_001AFEC8;
                        *(s8 *)(temp_s4 + 0x72) = 0x13;
                        *(u8 *)(temp_s4 + 0x2E1) = 1U;
                        *(s8 *)(temp_s4 + 0x71) = 0x13;
                        *(s8 *)(temp_s4 + 0x2E0) = 1;
                        func_L01_003C0830(arg0, 1);
                    }
                    break;
                case 4:                             /* switch 4 */
                    if ((D_L01_001AFE5C < temp_f0) && (temp_f0 <= D_L01_001AFE58) && (temp_f21 < (D_L01_001AFEB8 * 0.017453294f)) && (*(s16 *)(temp_s4 + 0x2DC) == 0)) {
                        if (func_002829A8(temp_s4 + 0x2E3) != 0) {
                            func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFEA0 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                            *(u8 *)(arg0 + 0xBC) = 5U;
                            *(s8 *)(temp_s4 + 0x2E0) = 0;
                            *(u8 *)(temp_s4 + 0x2E1) = temp_s0;
                            *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                            *(s8 *)(temp_s4 + 0x2E2) = 0x16;
                            *(s8 *)(temp_s4 + 0x72) = 0xF;
                            *(s8 *)(temp_s4 + 0x71) = 0xF;
                            func_L01_003BFDC8(arg0, 3, 0, 0xD);
                            func_002A7750(arg0, 0, 5);
                        }
                        func_L01_003C0760(arg0);
                    }
                    break;
                case 5:                             /* switch 4 */
                    *(s32 *)(arg0 + 0x98) = 0;
                    if (temp_f0 <= D_L01_001AFE5C) {
                        temp_v1_7 = *(u8 *)(arg0 + 0x42);
                        if (temp_v1_7 != 0x16) {
                            if (temp_v1_7 == 0) {
                                goto block_72;
                            }
                        } else {
block_72:
                            *(u8 *)(temp_s4 + 0x2E1) = 1U;
                            *(s8 *)(temp_s4 + 0x72) = 0x13;
                            *(s8 *)(temp_s4 + 0x2E0) = 1;
                            *(s8 *)(temp_s4 + 0x71) = 0x13;
                            *(s8 *)(temp_s4 + 0x2E2) = 0;
                            func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE84 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                            *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE58;
                            *(u8 *)(arg0 + 0xBC) = 6U;
                            *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                            func_L01_003BFDC8(arg0, 0x16, 0, 0x14);
                            func_002A7750(arg0, 0, 5);
                        }
                    }
                    break;
                case 6:                             /* switch 4 */
                    *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                    if ((temp_f0 <= D_L01_001AFE58) && (temp_f21 < (D_L01_001AFEAC * 0.017453294f)) && (func_002A77E0(D_L01_001AFEC0 - 1) == 0) && (*(s16 *)(temp_s4 + 0x2DC) == 0)) {
                        if ((D_L01_001AFE5C < temp_f0) && (func_1163B0() & 1)) {
                            func_L01_003C0760(arg0);
                        } else {
                            func_L01_003C06E8(arg0);
                        }
                    }
                    break;
                }
                temp_v0_2 = *(u8 *)(arg0 + 0xBC);
                if ((temp_v0_2 != 5) && (temp_v0_2 < 7U) && (D_L01_001AFE68 < temp_f0)) {
                    func_002B60B0(arg0, D_L01_001AFE9C * 0.00027777778f, D_L01_001AFEA0 * 0.016666668f, D_L01_001AFEA4 * 0.0000048481375f, D_L01_001AFEA8 * 0.00029088825f);
                    *(u8 *)(arg0 + 0xBC) = 5U;
                    *(s8 *)(temp_s4 + 0x2E0) = 0;
                    *(s8 *)(temp_s4 + 0x72) = 0xF;
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                    *(u8 *)(temp_s4 + 0x2E1) = 4U;
                    *(s8 *)(temp_s4 + 0x2E2) = 0x16;
                    *(s8 *)(temp_s4 + 0x71) = 0xF;
                }
                if (*(f32 *)(temp_s4 + 0x20) < (func_00283CE0((s32) *(s16 *)(temp_s4 + 0x24)) * 0.33333334f)) {
                    *(s8 *)(temp_s4 + 0x2E0) = 1;
                    *(u8 *)(temp_s4 + 0x2E1) = 5U;
                    *(s8 *)(temp_s4 + 0x2E2) = 0xE;
                    *(s8 *)(temp_s4 + 0x72) = 0x13;
                    *(s8 *)(temp_s4 + 0x71) = 0x13;
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE54;
                    func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE94 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                    *(u8 *)(arg0 + 0xBC) = 7U;
                    func_L01_003BFDC8(arg0, 0x10, 0, 0xD);
                    func_002A7750(arg0, 0, 5);
                }
                break;
            case 7:                                 /* switch 2 */
                if ((temp_f0 <= D_L01_001AFE54) && (temp_f21 < (D_L01_001AFEB4 * 0.017453294f)) && (*(s16 *)(temp_s4 + 0x2DE) == 0)) {
                    *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                    *(u8 *)(arg0 + 0xBC) = 9U;
                    *(u8 *)(temp_s4 + 0x2E1) = 1U;
                    *(s8 *)(temp_s4 + 0x72) = 0x13;
                    *(s8 *)(temp_s4 + 0x2E0) = 1;
                    *(s8 *)(temp_s4 + 0x2E2) = 0;
                    *(s8 *)(temp_s4 + 0x71) = 0x13;
                    func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE98 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                    func_L01_003C0830(arg0);
                }
                break;
            case 8:                                 /* switch 2 */
                *(s32 *)(arg0 + 0x98) = 0;
                if (temp_f0 <= D_L01_001AFE5C) {
                    temp_v1_8 = *(u8 *)(arg0 + 0x42);
                    if (temp_v1_8 != 0x16) {
                        if (temp_v1_8 == 0) {
                            goto block_95;
                        }
                    } else {
block_95:
                        *(u8 *)(temp_s4 + 0x2E1) = 1U;
                        *(s8 *)(temp_s4 + 0x72) = 0x13;
                        *(s8 *)(temp_s4 + 0x2E0) = 1;
                        *(s8 *)(temp_s4 + 0x71) = 0x13;
                        *(s8 *)(temp_s4 + 0x2E2) = 0;
                        func_002B60B0(arg0, D_L01_001AFE74 * 0.00027777778f, D_L01_001AFE84 * 0.016666668f, D_L01_001AFE78 * 0.0000048481375f, D_L01_001AFE7C * 0.00029088825f);
                        *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                        *(u8 *)(arg0 + 0xBC) = 9U;
                        *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                        func_L01_003BFDC8(arg0, 0x16, 0, 0x14);
                        func_002A7750(arg0, 0, 5);
                    }
                }
                break;
            case 9:                                 /* switch 2 */
                *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                if ((temp_f0 <= D_L01_001AFE5C) && (temp_f21 < (D_L01_001AFEAC * 0.017453294f))) {
                    if ((func_002A77E0(D_L01_001AFEC0 - 1) == 0) && (*(s16 *)(temp_s4 + 0x2DC) == 0)) {
                        if (func_1163B0() & 1) {
                            func_L01_003C0760(arg0);
                        } else {
                            func_L01_003C06E8(arg0);
                        }
                    } else {
                        goto block_105;
                    }
                } else {
block_105:
                    if ((D_L01_001AFE5C < temp_f0) && (temp_f0 <= D_L01_001AFE60) && (temp_f21 < (D_L01_001AFEB0 * 0.017453294f))) {
                        if ((func_002A77E0(D_L01_001AFEC4 - 1) == 0) && (*(s16 *)(temp_s4 + 0x2DA) == 0)) {
                            func_L01_003C07C8(arg0);
                        } else {
                            goto block_112;
                        }
                    } else {
block_112:
                        if (D_L01_001AFE68 < temp_f0) {
                            *(u8 *)(temp_s4 + 0x2E1) = 4U;
                            *(s8 *)(temp_s4 + 0x2E2) = 0x16;
                            *(s8 *)(temp_s4 + 0x2E0) = 0;
                            func_002B60B0(arg0, D_L01_001AFE9C * 0.00027777778f, D_L01_001AFEA0 * 0.016666668f, D_L01_001AFEA4 * 0.0000048481375f, D_L01_001AFEA8 * 0.00029088825f);
                            *(f32 *)(temp_s4 + 0x2EC) = (f32) D_L01_001AFE5C;
                            *(u8 *)(arg0 + 0xBC) = 8U;
                            *(s8 *)(temp_s4 + 0x72) = 0xF;
                            *(s8 *)(temp_s4 + 0x71) = 0xF;
                            func_L01_003BFDC8(arg0, 3, 0, 0xD);
                            func_002A7750(arg0, 0, 5);
                        }
                    }
                }
                break;
            }
            if ((*(u8 *)(arg0 + 0x42) == 0x16) && (*(u8 *)(arg0 + 0x60) & 2)) {
                *(s8 *)(temp_s4 + 0x2E2) = 0;
                func_L01_003BFDC8(arg0, 0, 0, 0xA);
            }
        }
        break;
    case 3:                                         /* switch 1 */
        temp_v1_9 = *(u8 *)(arg0 + 0x20);
        temp_f20 = func_0029F530(arg0);
        switch (temp_v1_9) {                        /* switch 5; irregular */
        case 1:                                     /* switch 5 */
            func_L01_00322288(arg0, func_00283248(((HeroV *)D_00189E20)->x - *(f32 *)(arg0 + 0x10), ((HeroV *)D_00189E20)->y - *(f32 *)(arg0 + 0x14)));
            if ((temp_f20 > 44.0f) && (temp_f20 < 68.0f)) {
                temp_v1_10 = *(u8 *)(arg0 + 0x42);
                if (temp_v1_10 == 6) {
                    var_s5 = 0;
                } else {
                    var_s5 = ((temp_v1_10 ^ 7) == 0) ? 4 : -1;
                }
                if (var_s5 >= 0) {
                    func_0029FCC0(arg0, var_s5, (sp + 4));
                    var_s1_2 = 1;
loop_133:
                    func_002A8BD0((sp + 8), (s32) arg0, 1, (f32) *(u8 *)(temp_s4 + 0x34));
                    temp_a1 = var_s5 + var_s1_2;
                    var_s1_2 += 1;
                    qcopy(sp, sp + 4);
                    func_0029FCC0(arg0, temp_a1, sp + 4);
                    func_00277F48(0.5f, (s32) (sp + 4), 0, (s32) arg0, (s32) (sp + 8));
                    sp[4] += func_002A7878(-0.3f, 0.3f);
                    sp[5] += func_002A7878(-0.3f, 0.3f);
                    sp[6] += func_002A7878(-0.3f, 0.3f);
                    func_002761F8(sp, (sp + 4), 9, arg0, (sp + 8));
                    if (var_s1_2 < 3) {
                        goto loop_133;
                    }
                }
            }
            break;
        case 2:                                     /* switch 5 */
            func_L01_00322288(arg0, func_00283248(((HeroV *)D_00189E20)->x - *(f32 *)(arg0 + 0x10), ((HeroV *)D_00189E20)->y - *(f32 *)(arg0 + 0x14)));
            if (func_002AEB60((u8 *) arg0, 16.0f) != 0) {
                func_0029FCC0(arg0, 0xA, sp);
                func_00282CF0((sp + 4), *(u8 **)(temp_s4 + 0x120) + 0x10, sp);
                func_00282F20((sp + 4), (sp + 4), D_L01_001AFEF4 * 0.016666668f);
                sp[6] = func_L00_0031CDD0(sp, *(u8 **)(temp_s4 + 0x120) + 0x10, NULL, D_L01_001AFEF4 * 0.016666668f, -(D_L01_001AFEF8 * 0.00027777778f));
                func_L01_003DA300(sp, (sp + 4), arg0, (f32) *(u8 *)(temp_s4 + 0x34));
            }
            break;
        case 3:                                     /* switch 5 */
            if ((temp_f20 > 34.0f) && (temp_f20 < 41.0f)) {
                temp_a1 = (func_1163B0() & 1) | 8;
                func_002A8D70(arg0, 2.2f, (f32) *(u8 *)(temp_s4 + 0x34), temp_a1, 1, 1.0f, 0, 1, 0);
            }
            break;
        case 4:                                     /* switch 5 */
            func_L01_00322288(arg0, func_00283248(((HeroV *)D_00189E20)->x - *(f32 *)(arg0 + 0x10), ((HeroV *)D_00189E20)->y - *(f32 *)(arg0 + 0x14)));
            if (*(u8 *)(temp_s4 + 0x2F4) == 0) {
                if (temp_f20 > 12.0f) {
                    if (temp_f20 <= 17.0f) {
                        func_0029FCC0(arg0, 0xC, sp);
                        sp[2] -= 2.4f;
                        if ((func_00282E48(sp, &((HeroV *)D_00189E20)->x) < D_L01_001AFE6C) && (*(s32 *)(D_00189E20 + 0x2294) != 0x6F)) {
                            *(u8 *)(temp_s4 + 0x2F4) = 1U;
                        }
                    } else {
                        goto block_149;
                    }
                } else {
block_149:
                    if ((temp_f20 > 17.0f) && (temp_f20 < 19.0f)) {
                        *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                        temp_a1 = (func_1163B0() & 1) | 0xC;
                        func_002A8D70(arg0, 2.0f, (f32) *(u8 *)(temp_s4 + 0x35), temp_a1, 1, 1.0f, 0, 1, 0);
                    }
                }
            } else if (temp_f20 > 19.0f) {
                ((HeroV *)D_00189E20)->a22b5 = 1;
            }
            break;
        }
        if (*(u8 *)(temp_s4 + 0x2F4) != 0) {
            func_L01_003C08A0(arg0);
            if (*(u8 *)(arg0 + 0x60) & 2) {
                if (((HeroV *)D_00189E20)->a24cc < 2) {
                    func_L00_002B30E8();
                } else {
                    func_002A8BD0(sp, (s32) arg0, 1, (f32) *(u8 *)(temp_s4 + 0x36));
                    func_002A8E20(((HeroV *)D_00189E20)->a2290, sp);
                }
                ((HeroV *)D_00189E20)->a22b5 = 1;
                func_L01_003BFDC8(arg0, 0xB, 0, 0x14);
                func_002A7750(arg0, 0, 4);
            }
        } else {
            if (*(u8 *)(arg0 + 0x60) & 2) {
                *(s32 *)(arg0 + 0x9C) = (s32) (*(s32 *)(arg0 + 0x9C) & ~0x30);
                func_002A7750(arg0, 0, 2);
                func_L01_003BFDC8(arg0, 0, 0, 0x14);
            }
        }
        break;
    case 4:                                         /* switch 1 */
        temp_f23 = func_0029F530(arg0);
        temp_v0_3 = (*(s32 *)(temp_s4 + 0x2CC) << 7) + D_001B264C;
        temp_f0_2 = func_00283248(*(f32 *)(temp_v0_3 + 0x30) - *(f32 *)(arg0 + 0x10), *(f32 *)(temp_v0_3 + 0x34) - *(f32 *)(arg0 + 0x14));
        temp_f22 = func_00283B98(temp_f0_2, 1.5707965f);
        temp_f21_2 = func_00283BE0(temp_f0_2, 1.5707965f);
        temp_f20_2 = func_00283C80(*(f32 *)(arg0 + 0xF8), temp_f22);
        if (temp_f20_2 < func_00283C80(*(f32 *)(arg0 + 0xF8), temp_f21_2)) {
            func_L01_00322288(arg0, temp_f22);
        } else {
            func_L01_00322288(arg0, temp_f21_2);
        }
        if (*(u8 *)(arg0 + 0x42) == 0xB) {
            var_s2 = 1;
            func_0029FCC0(arg0, 0xE, sp);
            temp_f0_3 = func_00282E48(sp, D_00189EA0);
            if (!(temp_f0_3 > 13.0f)) {
                var_s2 = 0;
            }
            if (*(u8 *)(temp_s4 + 0x2F4) != 0) {
                if (temp_f23 > 33.0f) {
                    func_L01_002BEB90(0x16, 1);
                    temp_v1_12 = D_00189E20;
                    *(s32 *)(temp_v1_12 + 0x2294) = 0x6F;
                    *(s32 *)(temp_v1_12 + 0x229C) = 9;
                    *(s8 *)(temp_v1_12 + 0x22B5) = 0;
                    *(s32 *)(temp_v1_12 + 0x24A0) = 0;
                    *(u8 *)(temp_s4 + 0x2F4) = 0U;
                } else {
                    *(s8 *)(D_00189EA0 + 0x2235) = 1;
                    func_L01_003C08A0(arg0);
                }
            }
            if ((*(u8 *)(temp_s4 + 0x2F4) == 0) && (var_s2 == 0)) {
                func_00282F20((sp + 4), arg0 + 0xC0, D_L01_001AFEEC);
                func_00282F20((sp + 8), (sp + 4), D_L01_001AFEF0 * 0.016666668f);
                temp_f20_3 = func_00282E20((sp + 8));
                sp[10] = temp_f20_3 * (func_002A7790(1.0f - (temp_f0_3 * 0.006666667f)) * 0.7f);
                qcopy(D_00189F10, sp + 8);
                qcopy(D_00189F10 + 0x20, sp + 8);
                temp_a0_2 = D_00189EA0;
                func_00282CC0(temp_a0_2, temp_a0_2, (sp + 8));
            }
            if (var_s2 != 0) {
                *(s32 *)(arg0 + 0x9C) = (s32) (*(s32 *)(arg0 + 0x9C) & ~0x30);
                *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                if (D_0018C0B4 == 0x6F) {
                    func_L01_002BEB90(0x16, 1);
                }
            }
            if (*(u8 *)(arg0 + 0x60) & 2) {
                *(s32 *)(arg0 + 0x9C) = (s32) (*(s32 *)(arg0 + 0x9C) & ~0x30);
                *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
                func_L01_003BFDC8(arg0, 0xC, 0, 0x14);
                func_002A7750(arg0, 0, 5);
                if (D_0018C0B4 == 0x6F) {
                    func_L01_002BEB90(0x16, 1);
                }
            }
        } else {
            if (*(u8 *)(arg0 + 0x95) == 4) {
                temp_v1_11 = *(u8 *)(temp_s4 + 0x2F4);
                if (temp_v1_11 == 1) {
                    D_0018C0D5 = temp_v1_11;
                }
            }
        }
        break;
    case 5:                                         /* switch 1 */
        if (*(u8 *)(arg0 + 0x60) & 2) {
            func_002A7750(arg0, 0, 2);
            func_L01_003BFDC8(arg0, (s32) *(u8 *)(temp_s4 + 0x2E1), 0, 0x14);
            *(s8 *)(arg0 + 0xA8) = 0xFF;
        }
        break;
    case 6:                                         /* switch 1 */
        temp_v0_4 = func_002B1C20(arg0, temp_s4 + 0x60);
        if (temp_v0_4 & 1) {
            func_002A7750(arg0, 0, 7);
        } else if (temp_v0_4 & 2) {
            func_L01_003BFDC8(arg0, (s32) *(u8 *)(temp_s4 + 0x2E1), 0, 0xC);
            func_002A7750(arg0, 0, 2);
        }
        break;
    case 7:                                         /* switch 1 */
        *(s32 *)(arg0 + 0x48) = 0;
        *(u16 *)(arg0 + 0x34) = (u16) (*(u16 *)(arg0 + 0x34) | 0x41);
        temp_a0_3 = *(u8 **)(temp_s4 + 0x2E4);
        temp_s1 = arg0 + 0x10;
        if (temp_a0_3 != NULL) {
            func_L00_002D7140(temp_a0_3);
            *(u8 **)(temp_s4 + 0x2E4) = NULL;
        }
        temp_v0_5 = func_L01_004171C8(temp_s1, 1, -1, -1);
        *(u8 **)(temp_s4 + 0x300) = temp_v0_5;
        if (temp_v0_5 != NULL) {
            func_L01_002BEB90(0x6F, 1);
            temp_s0_2 = temp_s4 + 0x2A0;
            temp_v0_6 = *(u8 **)(temp_s4 + 0x300);
            *(f32 *)(temp_v0_6 + 0x18) = (f32) (*(f32 *)(temp_v0_6 + 0x18) - 0.5f);
            func_00282CF0(temp_s0_2, temp_s1, D_00189EA0);
            *(f32 *)(temp_s4 + 0x2A8) = (f32) (*(f32 *)(temp_s4 + 0x2A8) + 1.0f);
            func_00282D30(temp_s0_2, temp_s0_2, 0.85f);
            *(f32 *)(temp_s4 + 0x2AC) = 1.0f;
            func_002A7750(arg0, 0, 8);
        }
        break;
    case 8:                                         /* switch 1 */
        temp_v1_13 = *(s32 *)(temp_s4 + 0x2F8);
        temp_f21_3 = *(f32 *)(temp_s4 + 0x2AC) - 0.00625f;
        *(f32 *)(temp_s4 + 0x2AC) = temp_f21_3;
        if (temp_v1_13 != -1) {
            temp_v1_14 = (*(s32 *)((u8 *)((*(u8 **)((u8 *)(((temp_v1_13 << 8) + D_001B255C)) + 0x68))) + 0x28));
            temp_a2 = D_L01_001B264C;
            if (temp_v1_14 != -1) {
                temp_a1_2 = temp_v1_14 << 7;
                qcopy(D_00189EA0, (u8 *)(temp_a1_2 + temp_a2) + 0x30);
                temp_a1_3 = temp_a1_2 + temp_a2;
                qcopy(D_00189EA0 + 0x10, (u8 *)temp_a1_3 + 0x70);
            }
        }
        if ((u8) *(u8 *)(*(u8 **)(temp_s4 + 0x300) + 0x20) < 2U) {
            temp_v1_15 = *(s32 *)(temp_s4 + 0x2F8);
            if (temp_v1_15 != -1) {
                temp_v1_16 = (temp_v1_15 << 8) + D_L01_001B255C;
                if (*(u8 *)(temp_v1_16 + 0xBC) != 0) {
                    *(u8 *)(temp_v1_16 + 0xBC) = 0U;
                    func_L01_00394240(D_001B255C + (*(s32 *)(temp_s4 + 0x2F8) << 8));
                }
            }
            temp_s1_2 = temp_s4 + 0x2A0;
            temp_s0_3 = *(u8 **)(temp_s4 + 0x300) + 0x10;
            func_00282F20(temp_s0_3, temp_s1_2, temp_f21_3 * func_00282DF0(temp_s1_2));
            temp_v0_7 = *(u8 **)(temp_s4 + 0x300);
            *(f32 *)(temp_v0_7 + 0x18) = (f32) (*(f32 *)(temp_v0_7 + 0x18) + (func_00283198(temp_f21_3 * 3.1415927f) * 4.0f));
            temp_a0_4 = *(u8 **)(temp_s4 + 0x300) + 0x10;
            func_00282CC0(temp_a0_4, temp_a0_4, D_00189EA0);
            temp_s1_3 = *(u8 **)(*(u8 **)(temp_s4 + 0x300) + 0x68);
            temp_s0_4 = temp_s1_3 + 0x10;
            func_00282CF0(temp_s0_4, arg0 + 0x10, D_00189EA0);
            func_00282F20(temp_s0_4, temp_s0_4, 2.5f);
            *(f32 *)(temp_s1_3 + 0x1C) = func_00283B98(func_00283248(*(f32 *)(temp_s1_3 + 0x10), *(f32 *)(temp_s1_3 + 0x14)), 3.1415927f);
            func_00282CC0(temp_s0_4, temp_s0_4, D_00189EA0);
            func_002A0F48(*(u8 **)(temp_s4 + 0x300));
            *(f32 *)(temp_s4 + 0x2AC) = temp_f21_3;
        }
        temp_a0_5 = *(u8 **)(temp_s4 + 0x300);
        if ((temp_a0_5 == NULL) || (*(s16 *)(temp_a0_5 + 0xAA) != 0x1250) || (temp_v1_17 = *(u8 *)(temp_a0_5 + 0x20), (temp_v1_17 == 0xFE)) || (temp_v1_17 == 0xFD)) {
            func_002A6C58(arg0, 0, 3);
            temp_v1_18 = *(u8 *)(arg0 + 0xB0);
            if (temp_v1_18 != 0xFF) {
                func_002A0430((u32) temp_v1_18);
            }
            if (*(s32 *)(temp_s4 + 0x304) != -1) {
                func_0027D330(0x10);
                func_L00_00303530(0, 0);
                temp_a0_6 = D_001B264C + (*(s32 *)(temp_s4 + 0x304) << 7);
                func_L00_002B9D60(temp_a0_6 + 0x30, temp_a0_6 + 0x70, 0, 1);
                func_002DF3F8(D_00189EA0, D_00189EA0 + 0x10);
            }
            temp_v1_19 = *(s32 *)(temp_s4 + 0x308);
            if (temp_v1_19 != -1) {
                (*(s8 *)((u8 *)(((temp_v1_19 << 8) + D_L01_001B255C)) + 0xBC)) = 1;
            }
            func_L01_00323310(*(s32 *)(temp_s4 + 0x314), *(s32 *)(temp_s4 + 0x31C));
            func_0029F338(arg0);
            return;
        }
        break;
    }
        temp_f1 = func_L01_003BAFB0();
        if ((*(u8 *)(arg0 + 0x95) != 0) && (((HeroV *)D_00189E20)->z < (temp_f1 - 1.8f)) && (((HeroV *)D_00189E20)->z < (*(f32 *)(arg0 + 0x18) - 1.0f)) && (func_00282E80(arg0 + 0x10, &((HeroV *)D_00189E20)->x) < 10.0f)) {
            func_L00_002B30E8();
        }
        func_L01_003C0140(arg0);
}
