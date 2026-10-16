/* Wave 6 lvl6-12: form variants for the near-miss functions. Ruler only (wslcmp). */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;
typedef char s8;
typedef float f32;

extern s32 D_L17_001C0018;
extern s32 func_2DF570(s32, s32, s32, s32, s32);

extern u8 D_L04_00254E10[];
extern void func_0030C948(u8 *a0, s32 a1, s32 a2, s32 a3);

extern s16 *D_L17_001FB720[];
extern s32 D_L17_001B2C1C __attribute__((sda));

extern s32 func_321F48(s32, s32, s32);
extern u8 *func_31FC88(s32);
extern void func_362DE0(u8 *, s32, s32, s32);
extern void func_325308(s32, s32, s32, f32, f32);
extern void func_3159F0(s32);

extern s32 func_312898(s32 a0, s32 a1, void *a2);
extern void func_2EEFE0(char *a0, char *a1, void *a2);
extern void func_31B920(char *a0, s32 a1, s32 a2);

extern int func_L22_003A48F8(int);

/* --- func_L17_003E7010: the == operands swapped so the global lands in $v0 --- */
s32 func_L17_003E7010_v1(s32 a0) {
    s32 s0 = *(s32 *)(a0 + 0x68);

    if (func_2DF570(a0 + 0x10, s0 + 0x240, 0, a0, 0) == 0)
        return 1;
    return D_L17_001C0018 == *(s32 *)(s0 + 0x250);
}

/* --- func_L04_00415EA8: for-loop so the counter decrement is at the loop bottom --- */
void func_L04_00415EA8_v1(s32 a0) {
    s32 *p = (s32 *)(D_L04_00254E10 + 0x144);
    s32 n;

    for (n = 0x8B; n >= 0; n--) {
        if (a0 == 0)
            p[0] = 0;
        else if (p[1] == a0)
            p[0] = 0;
        p = (s32 *)((u8 *)p + 0x150);
    }
}

/* --- func_L04_00415EA8: pointer advanced by the byte offset kept in a local --- */
void func_L04_00415EA8_v2(s32 a0) {
    u8 *q = D_L04_00254E10 + 0x144;
    s32 n;

    for (n = 0x8B; n >= 0; n--) {
        s32 *p = (s32 *)q;

        if (a0 == 0 || p[1] == a0)
            p[0] = 0;
        q += 0x150;
    }
}

/* --- func_L04_00415E28: do-while (retail has no pre-loop guard) --- */
void func_L04_00415E28_v1(void) {
    u8 *p = D_L04_00254E10;
    u8 *end = p + 0xB7C0;

    do {
        if (*(s32 *)(p + 0x144) != 0 && *(s32 *)(p + 0x138) >= 2)
            func_0030C948(p, 0x43, 0x44, 0x45);
        p += 0x150;
    } while (p < end);
}

/* --- func_L04_00415E28: do-while, second condition read into a named local --- */
void func_L04_00415E28_v2(void) {
    u8 *p = D_L04_00254E10;
    u8 *end = p + 0xB7C0;

    do {
        if (*(s32 *)(p + 0x144) != 0) {
            s32 c = *(s32 *)(p + 0x138);

            if (c >= 2)
                func_0030C948(p, 0x43, 0x44, 0x45);
        }
        p += 0x150;
    } while (p < end);
}

/* --- func_L17_003E4860: the record base hoisted into a local before the loop --- */
void func_L17_003E4860_v1(s32 a0) {
    s32 i = *(u8 *)(a0 + 0x21);
    s16 *p;
    u8 *base;

    if (i == 0xFF)
        return;
    p = D_L17_001FB720[i];
    if (p == 0)
        return;
    base = (u8 *)D_L17_001B2C1C;
    do {
        u8 *q = base + ((*(u16 *)p & 0x7FFF) << 8);

        if (*(s8 *)(q + 0x20) >= 0 && *(s16 *)(q + 0xAA) == 0xB88)
            *(s16 *)(*(s32 *)(q + 0x68) + 0x406) = 1;
        p++;
    } while (*p >= 0);
}

/* --- func_L22_003E87B8: the 0xE0B argument hoisted into a named local --- */
void func_L22_003E87B8_v1(s32 a0, s32 a1, s32 a2) {
    s32 k = 0xE0B;

    if (func_321F48(a0, -1, 0) == 0)
        return;
    func_362DE0(func_31FC88(3) + 0xC, 0, a0, k);
    func_325308(a0, a0 + 0x10, -1, 2.0f, 13.0f);
    func_3159F0(a0);
}

/* --- func_L22_003E87B8: the font handle fetched first into a local --- */
void func_L22_003E87B8_v2(s32 a0, s32 a1, s32 a2) {
    u8 *h;

    if (func_321F48(a0, -1, 0) == 0)
        return;
    h = func_31FC88(3) + 0xC;
    func_362DE0(h, 0, a0, 0xE0B);
    func_325308(a0, a0 + 0x10, -1, 2.0f, 13.0f);
    func_3159F0(a0);
}

/* --- func_L03_003C85F8: a0 kept in a named local used by every call --- */
void func_L03_003C85F8_v1(char *a0, s32 a1) {
    char *s1;
    char buf[0x10];

    s1 = *(char **)(a0 + 0x68);
    *(s32 *)(s1 + 0xA0) = func_312898(a1, 2, buf);
    func_2EEFE0(s1 + 0x90, a0 + 0x10, buf);
    func_31B920(a0, 2, -1);
}

/* --- func_L22_003A6128: two-case switch instead of the double if --- */
int func_L22_003A6128_v1(f32 f12) {
    union { f32 f; unsigned int u; } c;
    int n = 0;
    int i;
    int idx = 0;

    c.f = f12;
    for (i = 0; i < 32; i++) {
        if (c.u & 1) {
            n++;
            if (n >= 2)
                return 0;
            idx = i;
        }
        c.u >>= 1;
    }
    switch (n) {
    case 1:
        if (func_L22_003A48F8(idx) == 0)
            return 1;
        /* fall through */
    default:
        return 0;
    }
}
