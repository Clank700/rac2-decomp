typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));

extern int func_002761F8(void *a, void *b, int mode, void *self, int flag);
extern u8 D_L04_001AFAC0[];

/* q1: one 32-byte buffer, flag block named inline (no live base across the call) */
int q1(void *a0, void *a1, s32 a2, float f12, float f13) {
    s32 buf[8];
    s32 r;

    *(TI128 *)buf = *(TI128 *)a0;
    *(TI128 *)(buf + 4) = *(TI128 *)a0;
    *(float *)(buf + 2) += f12;
    *(float *)(buf + 6) -= f13;
    if (*(float *)(buf + 6) < 0.0f)
        *(float *)(buf + 6) = 0.0f;
    r = func_002761F8(buf, buf + 4, 0x22, a1, 0);
    if (*(s32 *)(D_L04_001AFAC0 + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(D_L04_001AFAC0 + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* q2: the same, buffer typed as two 128-bit words */
int q2(void *a0, void *a1, s32 a2, float f12, float f13) {
    TI128 buf[2];
    s32 r;

    buf[0] = *(TI128 *)a0;
    buf[1] = *(TI128 *)a0;
    *(float *)((char *)&buf[0] + 8) += f12;
    *(float *)((char *)&buf[1] + 8) -= f13;
    if (*(float *)((char *)&buf[1] + 8) < 0.0f)
        *(float *)((char *)&buf[1] + 8) = 0.0f;
    r = func_002761F8(buf, buf + 1, 0x22, a1, 0);
    if (*(s32 *)(D_L04_001AFAC0 + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(D_L04_001AFAC0 + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* q3: two float buffers copied with 128-bit casts, flag block inline */
int q3(void *a0, void *a1, s32 a2, float f12, float f13) {
    float v1[4];
    float v2[4];
    s32 r;

    *(TI128 *)v1 = *(TI128 *)a0;
    *(TI128 *)v2 = *(TI128 *)a0;
    v1[2] += f12;
    v2[2] -= f13;
    if (v2[2] < 0.0f)
        v2[2] = 0.0f;
    r = func_002761F8(v1, v2, 0x22, a1, 0);
    if (*(s32 *)(D_L04_001AFAC0 + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(D_L04_001AFAC0 + 0x18) != 0)
            r = 0;
    }
    return r;
}
