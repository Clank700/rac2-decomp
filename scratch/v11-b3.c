/* worker lvl6-11 -- variant ruler round 3 (five functions in ONE container call).
   e* = func_L23_004277E8 (196 B, level 23)
   d* = func_L02_003FC9C0 (188 B, level 2)
   f1 = func_L23_0041E5B0 (168 B, level 23)  */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct {
    u32 w[4];
} V4;

/* ---------------- func_L23_004277E8 ---------------- */
extern void func_002A7750(void *, s32, s32);
extern void func_L23_004278D8(u8 *);
extern f32 D_L23_001B36FC __attribute__((sda));

/* e1: call first, the 0x7C store after it (retail has it in the jal delay slot) */
void e1(u8 *a0) {
    u8 *s0 = a0;
    u8 *o = *(u8 **)(s0 + 0x68);
    u8 st = *(u8 *)(s0 + 0x20);

    if (st == 0) {
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x100;
        *(u8 *)(s0 + 0x32) = 0xFF;
        *(u16 *)(o + 0x24) = 0x7D0;
        *(f32 *)(o + 0x20) = 2000.0f;
        func_002A7750(s0, 1, 0);
        *(u16 *)(s0 + 0x7C) = 0x3FF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x4000;
    } else if (st == 1) {
        f32 f = D_L23_001B36FC;

        if (f != 0.0f) {
            *(f32 *)(o + 0x20) = f;
            *(s16 *)(o + 0x24) = (s16)f;
        }
        func_002A7750(s0, 2, 0);
    }
    func_L23_004278D8(s0);
}

/* e2: the 0x7C store written before the call */
void e2(u8 *a0) {
    u8 *s0 = a0;
    u8 *o = *(u8 **)(s0 + 0x68);
    u8 st = *(u8 *)(s0 + 0x20);

    if (st == 0) {
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x100;
        *(u8 *)(s0 + 0x32) = 0xFF;
        *(u16 *)(o + 0x24) = 0x7D0;
        *(f32 *)(o + 0x20) = 2000.0f;
        *(u16 *)(s0 + 0x7C) = 0x3FF;
        func_002A7750(s0, 1, 0);
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) | 0x4000;
    } else if (st == 1) {
        f32 f = D_L23_001B36FC;

        if (f != 0.0f) {
            *(f32 *)(o + 0x20) = f;
            *(s16 *)(o + 0x24) = (s16)f;
        }
        func_002A7750(s0, 2, 0);
    }
    func_L23_004278D8(s0);
}

/* ---------------- func_L02_003FC9C0 ---------------- */
extern void *func_L00_002D70A0(s32);
extern void func_L00_002D7140(void *);
extern f32 D_L02_001B1234 __attribute__((sda));
extern f32 D_L02_001B1238 __attribute__((sda));
extern f32 D_L02_001B123C __attribute__((sda));
extern f32 D_L02_001B1240 __attribute__((sda));
extern f32 D_L02_001B1244 __attribute__((sda));
extern f32 D_L02_001B1248 __attribute__((sda));
extern f32 D_L02_001B124C __attribute__((sda));
extern f32 D_L02_001B1250 __attribute__((sda));
extern f32 D_L02_001B1254 __attribute__((sda));

/* d1: the three stores re-read the 0xC0 field (retail reloads it twice) */
void d1(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (*(u8 *)(a0 + 0x20) == 8) {
        u8 *obj = *(u8 **)(s0 + 0xC0);

        if (obj == 0) {
            *(u8 **)(s0 + 0xC0) = func_L00_002D70A0(5);
        } else {
            u8 *src = *(u8 **)(s0 + 0xD0);
            f32 f0, f1, f2;

            if (src == 0) {
                f0 = D_L02_001B1234;
                f1 = D_L02_001B1238;
                f2 = D_L02_001B123C;
            } else if (*(s16 *)(src + 0xAA) == 0x9F8) {
                f0 = D_L02_001B1240;
                f1 = D_L02_001B1244;
                f2 = D_L02_001B1248;
            } else if (*(s16 *)(src + 0xAA) == 0xA44) {
                f0 = D_L02_001B124C;
                f1 = D_L02_001B1250;
                f2 = D_L02_001B1254;
            } else {
                return;
            }
            *(f32 *)(obj + 0) = f0;
            *(f32 *)(*(u8 **)(s0 + 0xC0) + 4) = f1;
            *(f32 *)(*(u8 **)(s0 + 0xC0) + 8) = f2;
        }
    } else {
        func_L00_002D7140(*(u8 **)(s0 + 0xC0));
        *(u8 **)(s0 + 0xC0) = 0;
    }
}

/* d2: same, with a local pointer for the object and a local id */
void d2(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (*(u8 *)(a0 + 0x20) == 8) {
        f32 *obj = *(f32 **)(s0 + 0xC0);

        if (obj == 0) {
            *(f32 **)(s0 + 0xC0) = func_L00_002D70A0(5);
        } else {
            u8 *src = *(u8 **)(s0 + 0xD0);
            f32 f0, f1, f2;

            if (src != 0) {
                s32 id = *(s16 *)(src + 0xAA);

                if (id == 0x9F8) {
                    f0 = D_L02_001B1240;
                    f1 = D_L02_001B1244;
                    f2 = D_L02_001B1248;
                } else if (id == 0xA44) {
                    f0 = D_L02_001B124C;
                    f1 = D_L02_001B1250;
                    f2 = D_L02_001B1254;
                } else {
                    return;
                }
            } else {
                f0 = D_L02_001B1234;
                f1 = D_L02_001B1238;
                f2 = D_L02_001B123C;
            }
            obj[0] = f0;
            obj[1] = f1;
            obj[2] = f2;
        }
    } else {
        func_L00_002D7140(*(f32 **)(s0 + 0xC0));
        *(s32 *)(s0 + 0xC0) = 0;
    }
}

/* ---------------- func_L23_0041E5B0 ---------------- */
extern void func_002A8F70(void *, void *, void *, f32, V4 *);
extern void func_002A90C8(void *, void *, void *, f32, V4 *);
extern s32 D_L23_001B13D4 __attribute__((sda));

void f1(void *a0, s32 a1, s32 a2, V4 *a3, s32 a4, s32 a5) {
    V4 v = *a3;

    if (a4 == 0)
        func_002A8F70((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    else
        func_002A90C8((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    if ((a1 & 4) != 0 || a5 != 0)
        *(s32 *)0x001B3718 = D_L23_001B13D4;
}
