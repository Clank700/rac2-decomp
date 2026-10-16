typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));

extern int func_002761F8(void *a, void *b, int mode, void *self, int flag);
extern u8 D_L04_001AFAC0[];

/* p1: one 32-byte buffer holding both 16-byte samples */
int p1(void *a0, void *a1, s32 a2, float f12, float f13) {
    s32 buf[8];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    *(TI128 *)buf = *(TI128 *)a0;
    *(TI128 *)(buf + 4) = *(TI128 *)a0;
    *(float *)(buf + 2) += f12;
    *(float *)(buf + 6) -= f13;
    if (*(float *)(buf + 6) < 0.0f)
        *(float *)(buf + 6) = 0.0f;
    r = func_002761F8(buf, buf + 4, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}

/* p2: the same buffer typed as two 128-bit words */
int p2(void *a0, void *a1, s32 a2, float f12, float f13) {
    TI128 buf[2];
    u8 *base = D_L04_001AFAC0;
    s32 r;

    buf[0] = *(TI128 *)a0;
    buf[1] = *(TI128 *)a0;
    *(float *)((char *)&buf[0] + 8) += f12;
    *(float *)((char *)&buf[1] + 8) -= f13;
    if (*(float *)((char *)&buf[1] + 8) < 0.0f)
        *(float *)((char *)&buf[1] + 8) = 0.0f;
    r = func_002761F8(buf, buf + 1, 0x22, a1, 0);
    if (*(s32 *)(base + 0x1C) <= -1)
        r = 0;
    if (a2 != 0) {
        if (*(s32 *)(base + 0x18) != 0)
            r = 0;
    }
    return r;
}
