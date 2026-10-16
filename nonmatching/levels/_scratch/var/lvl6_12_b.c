/* Wave 6 lvl6-12 round 2: high-value 27-place candidates + the two close near misses. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern char D_00189E20_2[];
extern int func_L00_002D1F78(int, int *);
extern void func_002A7470(void *, int, int, int);

extern char *D_0018C0B0;
extern void func_00310498(void *);
extern int func_002A4DB0(void *, int, int, void *);
extern char D_001B4400[];

extern s32 func_L22_003A48F8(int);
extern s32 func_312898(s32 a0, s32 a1, void *a2);
extern void func_2EEFE0(char *a0, char *a1, void *a2);
extern void func_31B920(char *a0, s32 a1, s32 a2);

/* --- func_L00_002D1FD8 (27 places): same two gates as its matched sibling above --- */
void func_L00_002D1FD8_v1(int a0, int a1, float f12)
{
    char *base = D_00189E20_2;
    int out;

    if (*(int *)(base + 0x2494) == 0)
        return;
    if (*(int *)(base + 0x2498) == 0)
        return;
    if (func_L00_002D1F78(a0, &out) != 0) {
        func_002A7470(*(void **)(base + 0x2494), out, a1, (int)f12);
    } else if (*(unsigned char *)(*(char **)(base + 0x2494) + 0x43) != 0) {
        func_002A7470(*(void **)(base + 0x2494), 0, 0, 7);
    }
}

/* --- func_L00_002D23C0 (27 places) --- */
void func_L00_002D23C0_v1(int a0, int a1)
{
    char *o = D_0018C0B0;
    unsigned char t;

    *(unsigned char *)(o + 0x41) = a1 + 1;
    *(unsigned char *)(o + 0x40) = a1;
    t = *(unsigned char *)(*(int *)(*(int *)(o + 0x24) + (a0 << 2) + 0x48) + 0x10) - 1;
    if (t < (unsigned char)(a1 + 1))
        *(unsigned char *)(o + 0x41) = t;
    *(int *)(o + 0x44) = 0;
    *(unsigned char *)(o + 0x43) = a0;
    func_00310498(o);
    *(unsigned char *)(o + 0x42) = a0;
    *(int *)(o + 0x58) = func_002A4DB0(o, *(unsigned char *)(o + 0x42),
                                       *(unsigned char *)(o + 0x40), D_001B4400);
    *(int *)(o + 0x5C) = func_002A4DB0(o, *(unsigned char *)(o + 0x43),
                                       *(unsigned char *)(o + 0x41), D_001B4400 + 0x600);
}

/* --- func_L22_003A6128: explicit n == 0 / n == 1 tests instead of a switch --- */
int func_L22_003A6128_v2(f32 f12) {
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
    if (n == 0)
        return 0;
    if (n == 1) {
        if (func_L22_003A48F8(idx) == 0)
            return 1;
    }
    return 0;
}

/* --- func_L03_003C85F8: the second argument parked in a local at entry --- */
void func_L03_003C85F8_v2(char *a0, s32 a1) {
    char *s1 = *(char **)(a0 + 0x68);
    char buf[0x10];
    s32 mode = a1;

    *(s32 *)(s1 + 0xA0) = func_312898(mode, 2, buf);
    func_2EEFE0(s1 + 0x90, a0 + 0x10, buf);
    func_31B920(a0, 2, -1);
}

/* --- func_L03_003C85F8: both pointers parked in locals at entry --- */
void func_L03_003C85F8_v3(char *a0, s32 a1) {
    char *v = a0;
    char *s1 = *(char **)(a0 + 0x68);
    char buf[0x10];
    s32 mode = a1;

    *(s32 *)(s1 + 0xA0) = func_312898(mode, 2, buf);
    func_2EEFE0(s1 + 0x90, v + 0x10, buf);
    func_31B920(v, 2, -1);
}
