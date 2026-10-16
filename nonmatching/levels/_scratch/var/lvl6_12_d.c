/* Wave 6 lvl6-12 tour 2: func_L14_003F0E98, func_L00_003206B8, func_L22_00415A48,
   func_L04_0040ACC8 (the $gp recipe). */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef float f32;

extern u8 *D_001B1F9C;

extern s32 func_2EE138(void *, void *, void *);
extern void func_2EE5B0(void *, void *, void *);
extern f32 func_2EE268(void *);

extern f32 func_2F36F0(s32);
extern void func_2F9E20(s32, s32);

extern s32 D_L22_0018B6A8_nosda __asm__("D_L22_0018B6A8") __attribute__((nosda));

extern s32 D_L04_001B0914_gp __asm__("D_L04_001B0914") __attribute__((section(".sdata")));
extern s32 D_L04_001B092C_gp __asm__("D_L04_001B092C") __attribute__((section(".sdata")));
extern s32 D_L04_001B0934_gp __asm__("D_L04_001B0934") __attribute__((section(".sdata")));
extern s32 D_L04_001B0938_gp __asm__("D_L04_001B0938") __attribute__((section(".sdata")));

/* --- func_L14_003F0E98: source order = retail's emitted order rotated left by one
   (the last store of a straight-line run comes out first) --- */
void func_L14_003F0E98_v1(u8 *a0) {
    *(u64 *)(a0 + 0x80) = 0x0000FF9000000260ULL;
    *(f32 *)(a0 + 0x28) = -4.0f;
    *(f32 *)(a0 + 0x38) = 4.0f;
    *(f32 *)(a0 + 0x14) = -2.0f;
    *(f32 *)(a0 + 0x34) = 2.0f;
    *(u64 *)(a0 + 0x70) = 0;
    *(s32 *)(a0 + 0x50) = 0;
    *(s32 *)(a0 + 0x54) = 0;
    *(f32 *)(a0 + 0x58) = 1.0f;
    *(s32 *)(a0 + 0x5C) = 0;
    *(s32 *)(a0 + 0x60) = 0;
    *(f32 *)(a0 + 0x64) = 1.0f;
    *(f32 *)(a0 + 0x68) = 1.0f;
    *(f32 *)(a0 + 0x6C) = 1.0f;
    *(f32 *)(a0 + 0x08) = -4.0f;
    *(f32 *)(a0 + 0x18) = 4.0f;
    *(f32 *)(a0 + 0x04) = -2.0f;
    *(f32 *)(a0 + 0x24) = 2.0f;
    *(s32 *)(a0 + 0x00) = 0;
    *(s32 *)(a0 + 0x10) = 0;
    *(s32 *)(a0 + 0x20) = 0;
    *(s32 *)(a0 + 0x30) = 0;
    *(f32 *)(a0 + 0x0C) = 1.0f;
    *(f32 *)(a0 + 0x1C) = 1.0f;
    *(f32 *)(a0 + 0x2C) = 1.0f;
    *(f32 *)(a0 + 0x3C) = 1.0f;
}

/* --- func_L14_003F0E98: the four quad rows in ascending order --- */
void func_L14_003F0E98_v2(u8 *a0) {
    *(s32 *)(a0 + 0x00) = 0;
    *(f32 *)(a0 + 0x04) = -2.0f;
    *(f32 *)(a0 + 0x08) = -4.0f;
    *(f32 *)(a0 + 0x0C) = 1.0f;
    *(s32 *)(a0 + 0x10) = 0;
    *(f32 *)(a0 + 0x14) = -2.0f;
    *(f32 *)(a0 + 0x18) = 4.0f;
    *(f32 *)(a0 + 0x1C) = 1.0f;
    *(s32 *)(a0 + 0x20) = 0;
    *(f32 *)(a0 + 0x24) = 2.0f;
    *(f32 *)(a0 + 0x28) = -4.0f;
    *(f32 *)(a0 + 0x2C) = 1.0f;
    *(s32 *)(a0 + 0x30) = 0;
    *(f32 *)(a0 + 0x34) = 2.0f;
    *(f32 *)(a0 + 0x38) = 4.0f;
    *(f32 *)(a0 + 0x3C) = 1.0f;
    *(s32 *)(a0 + 0x50) = 0;
    *(s32 *)(a0 + 0x54) = 0;
    *(f32 *)(a0 + 0x58) = 1.0f;
    *(s32 *)(a0 + 0x5C) = 0;
    *(s32 *)(a0 + 0x60) = 0;
    *(f32 *)(a0 + 0x64) = 1.0f;
    *(f32 *)(a0 + 0x68) = 1.0f;
    *(f32 *)(a0 + 0x6C) = 1.0f;
    *(u64 *)(a0 + 0x70) = 0;
    *(u64 *)(a0 + 0x80) = 0x0000FF9000000260ULL;
}

/* --- func_L00_003206B8 (27 places) --- */
s32 func_L00_003206B8_v1(u8 *a0, s32 a1) {
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
        if (*(f32 *)((u8 *)b2 + 8) >= -1.0f) {
            if (*(f32 *)((u8 *)b2 + 8) <= 1.0f)
                return 1;
        }
    }
    return 0;
}

/* --- func_L00_003206B8: early returns --- */
s32 func_L00_003206B8_v2(u8 *a0, s32 a1) {
    u8 *s0;
    f32 b1[4];
    f32 b2[4];

    if (a1 < 0)
        return 0;
    s0 = D_001B1F9C + (a1 << 7);
    func_2EE138(b1, a0, s0 + 0x30);
    *(s32 *)((u8 *)b1 + 0xC) = 0;
    func_2EE5B0(b2, b1, s0 + 0x40);
    if (func_2EE268(b2) >= 1.0f)
        return 0;
    if (*(f32 *)((u8 *)b2 + 8) < -1.0f)
        return 0;
    if (*(f32 *)((u8 *)b2 + 8) > 1.0f)
        return 0;
    return 1;
}

/* --- func_L22_00415A48 --- */
void func_L22_00415A48_v1(s32 a0) {
    s32 s1 = *(s32 *)(a0 + 0x68);
    s32 s0;

    if (*(u8 *)(a0 + 0x20) == 0) {
        *(u8 *)(a0 + 0x20) = 1;
        *(u8 *)(a0 + 0x30) = 0xFF;
        *(s32 *)s1 = 0x708;
    }
    if (*(u8 *)(a0 + 0x20) != 1)
        return;
    s0 = D_L22_0018B6A8_nosda;
    if (func_2F36F0(s1) == 0)
        return;
    if (*(s32 *)(s0 + 8) != 0)
        return;
    if (*(s32 *)(s0 + 0xC) != 0)
        return;
    func_2F9E20(0x9FD, 0x54);
    *(s32 *)s1 = 0x708;
}

/* --- func_L04_0040ACC8 (2 places): the four globals through $gp --- */
void func_L04_0040ACC8_v1(void) {
    char *v1 = (char *)D_L04_001B0914_gp;
    char *o = *(char **)(v1 + 0x68);

    if (*(s32 *)(o + 0x744) < 5) {
        s32 v = *(s32 *)(o + 0x724);

        D_L04_001B092C_gp = 1;
        if (v != 0) {
            D_L04_001B0938_gp = D_L04_001B0938_gp + 1;
            if (D_L04_001B0938_gp == 3)
                D_L04_001B0934_gp = 1;
        }
    } else if (D_L04_001B0938_gp < 4) {
        D_L04_001B0938_gp = 0;
    }
    *(s32 *)(o + 0x744) = 0;
    *(s32 *)(o + 0x724) = 0;
}
