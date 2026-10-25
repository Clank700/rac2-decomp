/* Retained manual C reconstruction; not linked or counted.
 * Retail: 552 bytes, 1 place (12:00420950).
 * Checked trial profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * us: 0/1 placements, 520 compiled bytes.
 * Residual: the 0xDF-record loop, the two table lookups and the -frac2-qcopy lq/sq copies
 * are semantically right, but the frame is 0xC0 instead of retail's 0xE0 and the inner loop
 * carries three address pointers where retail keeps one; the 0x20-byte tail of the local
 * object is not explained. First differing word is +0x4 (prologue size).
 * Reopen with evidence for the real submission object (its 0x80/0x90 size) and its two
 * float output pointers; do not add a dummy local just to grow the frame.
 *
 * The ASM marker was restored in src/levels/12_todano/L12_0041E3E8.c after the checks.
 */

#include "common.h"

typedef int L12_TI128 __attribute__((mode(TI)));

extern int D_L12_001B1F40 __attribute__((sda));
extern int D_L12_001B1F34 __attribute__((sda));
extern int D_L12_001B1F38 __attribute__((sda));

extern float D_L12_002A38F8[][2];
extern char D_L12_002A11B0[][16];
extern short D_L12_002A2410[][12];

extern void func_2EF5E0(void *, int, int, int);
extern void func_2EE220(void *, int, int);

typedef struct {
    L12_TI128 v[4];
    int i[4];
    float f[8];
} L12Buf_420950;

void func_L12_00420950(char *a0)
{
    char *state = *(char **)(a0 + 0x68);
    L12Buf_420950 buf;
    short *p;
    int i;
    int j;

    func_2EF5E0(&buf, D_L12_001B1F40, 2, 0x80);
    buf.i[0] = D_L12_001B1F34;
    buf.i[3] = D_L12_001B1F34;
    buf.i[2] = D_L12_001B1F34;
    buf.i[1] = D_L12_001B1F34;
    p = D_L12_002A2410[0];
    for (i = 0; i < 0xDF; i++) {
        char *dst = (char *)&buf.v[0];
        float *f0p = &buf.f[0];
        float *f1p = &buf.f[1];
        short *e = p;

        for (j = 0; j < 4; j++, e += 3) {
            short i0 = e[0];
            short i1 = e[1];

            *(L12_TI128 *)dst = *(L12_TI128 *)D_L12_002A11B0[i0];
            *f0p = D_L12_002A38F8[i1][0] + *(float *)(state + 0x10);
            *f1p = D_L12_002A38F8[i1][1];
            dst += 16;
            f0p += 2;
            f1p += 2;
        }
        func_2EE220(&buf, 0, 0);
        p += 12;
    }
    func_2EF5E0(&buf, D_L12_001B1F40 + 1, 2, 0x80);
    for (i = 0; i < 0xDF; i++) {
        char *dst;
        float *f0p;
        float *f1p;
        short *e;

        p = (short *)((char *)D_L12_002A2410 + i * 0x18);
        dst = (char *)&buf.v[0];
        f0p = &buf.f[0];
        f1p = &buf.f[1];
        e = p;
        for (j = 0; j < 4; j++, e += 3) {
            short i0 = e[0];
            short i1 = e[1];

            *(L12_TI128 *)dst = *(L12_TI128 *)D_L12_002A11B0[i0];
            *f0p = D_L12_002A38F8[i1][0] + *(float *)(state + 0x10);
            *f1p = D_L12_002A38F8[i1][1];
            dst += 16;
            f0p += 2;
            f1p += 2;
        }
        func_2EE220(&buf, 0, 0);
    }
}
