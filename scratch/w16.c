typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));
typedef struct { float f[4]; } V4;

extern int func_002761F8(float *a, float *b, int mode, void *self, int flag);
extern u8 D_L04_001AFAC0[];

/* v1: 16-byte struct copy-initialised at the declaration */
int v1(void *a0, void *a1, s32 a2, float f12, float f13) {
    V4 v1 = *(V4 *)a0;
    V4 v2 = *(V4 *)a0;
    u8 *base = D_L04_001AFAC0;
    s32 r;

    v1.f[2] += f12;
    v2.f[2] -= f13;
    if (v2.f[2] < 0.0f)
        v2.f[2] = 0.0f;
    r = func_002761F8(v1.f, v2.f, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* v2: TI128 locals, cast at the call */
int v2(void *a0, void *a1, s32 a2, float f12, float f13) {
    TI128 t1 = *(TI128 *)a0;
    TI128 t2 = *(TI128 *)a0;
    u8 *base = D_L04_001AFAC0;
    s32 r;

    *(float *)((char *)&t1 + 8) += f12;
    *(float *)((char *)&t2 + 8) -= f13;
    if (*(float *)((char *)&t2 + 8) < 0.0f)
        *(float *)((char *)&t2 + 8) = 0.0f;
    r = func_002761F8((float *)&t1, (float *)&t2, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* v3: float arrays filled by a plain assignment from the parameter */
int v3(void *a0, void *a1, s32 a2, float f12, float f13) {
    float v1[4];
    float v2[4];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    *(V4 *)v1 = *(V4 *)a0;
    *(V4 *)v2 = *(V4 *)a0;
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
