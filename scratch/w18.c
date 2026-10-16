typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern void *memcpy(void *, const void *, unsigned int);
extern int func_002761F8(void *a, void *b, int mode, void *self, int flag);
extern u8 D_L04_001AFAC0[];

/* z1: s32 buffers filled by memcpy, floats through casts */
int z1(void *a0, void *a1, s32 a2, float f12, float f13) {
    s32 v1[4];
    s32 v2[4];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    memcpy(v1, a0, 16);
    memcpy(v2, a0, 16);
    *(float *)(v1 + 2) += f12;
    *(float *)(v2 + 2) -= f13;
    if (*(float *)(v2 + 2) < 0.0f)
        *(float *)(v2 + 2) = 0.0f;
    r = func_002761F8(v1, v2, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* z2: float buffers, memcpy copies */
int z2(void *a0, void *a1, s32 a2, float f12, float f13) {
    float v1[4];
    float v2[4];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    memcpy(v1, a0, 16);
    memcpy(v2, a0, 16);
    v1[2] += f12;
    v2[2] -= f13;
    if (v2[2] < 0.0f)
        v2[2] = 0.0f;
    r = func_002761F8(v1, v2, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* z3: float buffers, memcpy, negated first comparison */
int z3(void *a0, void *a1, s32 a2, float f12, float f13) {
    float v1[4];
    float v2[4];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    memcpy(v1, a0, 16);
    memcpy(v2, a0, 16);
    v1[2] += f12;
    v2[2] -= f13;
    if (v2[2] < 0.0f)
        v2[2] = 0.0f;
    r = func_002761F8(v1, v2, 0x22, a1, 0);
    if (!(*(s32 *)(base + 0x1C) > -1))
        r = 0;
    if (a2 != 0 && *(s32 *)(base + 0x18) != 0)
        r = 0;
    return r;
}
