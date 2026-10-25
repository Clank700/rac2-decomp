/*
 * Retained complete manual reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 708 bytes; compiled: 712 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: catalogue absent.
 * Residual: 712/708 bytes with a 0x80 rather than 0x70 frame. The source capture remains
 * ordinary TI because retail folds its source+0x10 address. The global float remains a
 * real external scalar. Saved source-position lifetime and float-load scheduling still
 * differ; the helper and folded controls both emit 712 bytes.
 * Reopen: An independently measured source-position/global-float lifetime witness.
 * Preserve the actual two aligned vectors, float returns of AA548/AAA00 and the integer
 * third input to AAA00; do not replace the external scalar by a literal.
 */
#include "common.h"

extern float D_L02_001B01B8;
typedef int Vector __attribute__((mode(TI)));
extern float func_00282E48(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283248(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002AA548(void *, void *, float, float, float, float);
extern float func_002AAA00(void *, void *, int, float, float, float, float);


int func_L02_003D52A8(char *self) {
    float position[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float *p = position;
    char *state = *(char **)(self + 0x68);
    float angle = 1.15f;
    float distance;
    float height;
    float sine;
    float cosine;
    *(Vector *)position = *(Vector *)(self + 0x10);
    distance = func_00282E48(position, *(char **)(state + 0x30C) + 0x10);
    sine = func_00283180(angle);
    cosine = func_00283198(angle);
    height = D_L02_001B01B8 + distance * sine / cosine;
    p[2] = height - 4.2f;
    if (D_L02_001B01B8 + 5.0f < p[2])
        return 0;
    if (p[2] < D_L02_001B01B8 + 0.5f) {
        float scale = 4.7f / (p[2] - D_L02_001B01B8 + 4.2f);
        func_00282CF0(delta, self + 0x10, *(char **)(state + 0x30C) + 0x10);
        delta[2] = 0.0f;
        func_00282D30(delta, delta, scale);
        func_00282CC0(&position, &position, delta);
        func_002AA548(self + 0x10, state + 0x1B0, p[0], 0.025f, 0.025f, 2.5000002f);
        func_002AA548(self + 0x14, state + 0x1B4, p[1], 0.025f, 0.025f, 2.5000002f);
        func_002AAA00(self + 0xF8, state + 0x1C4, 0,
            func_00283248(*(float *)(*(char **)(state + 0x30C) + 0x10) - *(float *)(self + 0x10),
                         *(float *)(*(char **)(state + 0x30C) + 0x14) - *(float *)(self + 0x14)),
            0.003490659f, 0.003490659f, 0.22107507f);
    } else {
        func_002AA548(self + 0x18, state + 0x1B8, p[2], 0.025f, 0.025f, 2.5000002f);
        func_002AAA00(self + 0xF8, state + 0x1C4, 0,
            func_00283248(*(float *)(*(char **)(state + 0x30C) + 0x10) - *(float *)(self + 0x10),
                         *(float *)(*(char **)(state + 0x30C) + 0x14) - *(float *)(self + 0x14)),
            0.003490659f, 0.003490659f, 0.22107507f);
    }
    if (func_00282E48(self + 0x10, &position) < 0.0001f) {
        *(int *)(state + 0x1B8) = 0;
        return 2;
    }
    return 1;
}
