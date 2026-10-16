/* Wave 6 lvl6-12 tour 2, round 2: the two closest forms. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef float f32;

extern u8 *D_001B1F9C;
extern s32 func_2EE138(void *, void *, void *);
extern void func_2EE5B0(void *, void *, void *);
extern f32 func_2EE268(void *);

/* --- func_L14_003F0E98: the two four-store blocks swapped in the source (gcc emits them
   in the reverse of the source order, so retail's [0x28,0x38,0x14,0x34] first means the
   source lists the [0x08,0x18,0x04,0x24] block first) --- */
void func_L14_003F0E98_v3(u8 *a0) {
    *(u64 *)(a0 + 0x80) = 0x0000FF9000000260ULL;
    *(f32 *)(a0 + 0x08) = -4.0f;
    *(f32 *)(a0 + 0x18) = 4.0f;
    *(f32 *)(a0 + 0x04) = -2.0f;
    *(f32 *)(a0 + 0x24) = 2.0f;
    *(u64 *)(a0 + 0x70) = 0;
    *(s32 *)(a0 + 0x50) = 0;
    *(s32 *)(a0 + 0x54) = 0;
    *(f32 *)(a0 + 0x58) = 1.0f;
    *(s32 *)(a0 + 0x5C) = 0;
    *(s32 *)(a0 + 0x60) = 0;
    *(f32 *)(a0 + 0x64) = 1.0f;
    *(f32 *)(a0 + 0x68) = 1.0f;
    *(f32 *)(a0 + 0x6C) = 1.0f;
    *(f32 *)(a0 + 0x28) = -4.0f;
    *(f32 *)(a0 + 0x38) = 4.0f;
    *(f32 *)(a0 + 0x14) = -2.0f;
    *(f32 *)(a0 + 0x34) = 2.0f;
    *(s32 *)(a0 + 0x00) = 0;
    *(s32 *)(a0 + 0x10) = 0;
    *(s32 *)(a0 + 0x20) = 0;
    *(s32 *)(a0 + 0x30) = 0;
    *(f32 *)(a0 + 0x0C) = 1.0f;
    *(f32 *)(a0 + 0x1C) = 1.0f;
    *(f32 *)(a0 + 0x2C) = 1.0f;
    *(f32 *)(a0 + 0x3C) = 1.0f;
}

/* --- func_L00_003206B8 (27 places): body inside the guard, one trailing return 0 --- */
s32 func_L00_003206B8_v3(u8 *a0, s32 a1) {
    u8 *s0;
    f32 b1[4];
    f32 b2[4];

    if (a1 >= 0) {
        s0 = D_001B1F9C + (a1 << 7);
        func_2EE138(b1, a0, s0 + 0x30);
        *(s32 *)((u8 *)b1 + 0xC) = 0;
        func_2EE5B0(b2, b1, s0 + 0x40);
        if (func_2EE268(b2) < 1.0f) {
            if (*(f32 *)((u8 *)b2 + 8) >= -1.0f) {
                if (*(f32 *)((u8 *)b2 + 8) <= 1.0f)
                    return 1;
            }
        }
    }
    return 0;
}

/* --- func_L00_003206B8: same, with the byte offset spelled on the pointer --- */
s32 func_L00_003206B8_v4(u8 *a0, s32 a1) {
    u8 *s0;
    f32 b1[4];
    f32 b2[4];

    if (a1 < 0)
        return 0;
    s0 = D_001B1F9C + (a1 << 7);
    func_2EE138(b1, a0, s0 + 0x30);
    *(s32 *)((u8 *)b1 + 0xC) = 0;
    func_2EE5B0(b2, b1, s0 + 0x40);
    if (func_2EE268(b2) < 1.0f) {
        f32 r = *(f32 *)((u8 *)b2 + 8);

        if (r >= -1.0f && r <= 1.0f)
            return 1;
    }
    return 0;
}
