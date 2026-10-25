/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 504 bytes; compiled: 500 bytes.
 * Final coverage: us: 0/6; us2: 0/6; pal: catalogue absent.
 * Residual: 500/504 bytes, with the correct canonical sine/cosine, random, angle-clamp
 * and height-query interfaces. The full snapshot uses qcopy. Retail rematerializes the
 * resident base from its saved hero-position pointer in the final branch; this source
 * retains the base and folds component addresses.
 * Reopen: An independently measured resident-object/hero-position lifetime or layout
 * witness. Previous pointer spellings, SDK and no-split-address forms are not new
 * inputs; do not repeat them or fabricate a dependency.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

extern char D_00189E20[];

extern float func_002A78D8(float, float);
extern int func_002A7820(int a0, int a1);
extern void func_002AA800(float *, int, float, float);
extern int func_00282978(void *a0);
extern float func_00283180(float f12);
extern float func_00283198(float f12);
extern int func_L01_00321178(char *a0, float *a1);
extern float func_002A89A8(void *, int, float);
extern float func_00282E80(char *a0, char *a1);
extern float func_00283248(float f12, float f13);
extern float func_002AA150(float f12, float f13, float f14);

/* Advances a steer-toward state: the init branch seeds the turn rate and a random
   delay, the live branch re-reads the smoothed yaw and drops the state once the
   probe reports, then the body copies the anchor position, offsets it by two
   probe lookups, and either snaps the yaw at the target (ray hit or the far
   cone) or interpolates it toward the hero scaled by the distance ratio. */
void func_L01_00318638(char *a0, char *a1, char *a2) {
    char *s3;
    char *hp;
    Vector v;
    float f20;
    float t;
    float w;
    float keep;
    float lim;
    int r;

    if (*(short *)(a1 + 0x28) == 0) {
        t = func_002A78D8(0.78539824f, 2.617994f);
        *(float *)(a1 + 0x24) = *(float *)(a1 + 0x24) + t;
        *(short *)(a1 + 0x2A) = func_002A7820(*(short *)(a1 + 0x2C), *(short *)(a1 + 0x2E));
        *(short *)(a1 + 0x28) = 1;
    } else {
        func_002AA800((float *)(a0 + 0xF8), 0, *(float *)(a1 + 0x24), *(float *)(a1 + 0x18));
        if (func_00282978(a1 + 0x2A) != 0)
            *(short *)(a1 + 0x28) = 0;
    }
    s3 = a0 + 0x10;
    qcopy(&v, s3);
    keep = *(float *)(a2 + 0x28);
    *(float *)(a2 + 0x28) = *(float *)(a1 + 0x14);
    t = func_00283180(*(float *)(a0 + 0xF8));
    v.f[0] = v.f[0] + (t + t);
    w = func_00283198(*(float *)(a0 + 0xF8));
    *(float *)(a2 + 0x28) = keep;
    v.f[1] = v.f[1] + (w + w);
    r = func_L01_00321178(a0, v.f);
    *(float *)(a0 + 0x18) = func_002A89A8(s3, 0, 0.5f);
    f20 = func_00282E80(s3, a1);
    if (r != 0 || *(float *)(a1 + 0x1C) < f20) {
        *(float *)(a1 + 0x24) =
            func_00283248(*(float *)(a1 + 0x0) - *(float *)(a0 + 0x10),
                        *(float *)(a1 + 0x4) - *(float *)(a0 + 0x14));
        *(short *)(a1 + 0x2A) = func_002A7820(0x1E, 0x5A);
        *(short *)(a1 + 0x28) = 1;
    } else {
        hp = D_00189E20 + 0x80;
        f20 = func_00282E80(s3, hp);
        lim = *(float *)(a1 + 0x20);
        if (f20 < lim) {
            f20 = f20 / lim;
            *(float *)(a1 + 0x24) =
                func_002AA150(*(float *)(a1 + 0x24),
                            func_00283248(*(float *)(a0 + 0x10) - *(float *)(D_00189E20 + 0x80),
                                        *(float *)(a0 + 0x14) - *(float *)(D_00189E20 + 0x84)),
                            f20);
        }
    }
}
