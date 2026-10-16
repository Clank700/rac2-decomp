/* worker lvl6-11 -- variant ruler round 1.
   a* = func_L12_00425448 (96 B, level 12, needs $gp 0x30D0)
   b* = func_L12_004254A8 (104 B, level 12, no $gp)
   c* = func_L02_003FC1B0 (152 B, level 2, no $gp)  */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* ---------------- func_L12_00425448 ---------------- */
extern int func_00282948(void *);
extern s32 func_002A7820(s32, s32);
extern s32 func_002E5CF8(s32, s32, void *);
extern u8 *D_L12_001B20C4;
extern u8 *D_L12_001B20C4_ns __attribute__((nosda));
extern s32 D_L12_001B20C0 __attribute__((sda));

/* a1: pointer global left un-annotated (absolute), value global sda */
void a1(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_00282948(s0 + 0x2C0) != 0) {
        *(s32 *)(s0 + 0x2C0) = func_002A7820(D_L12_001B20C0, (s32)D_L12_001B20C4);
        func_002E5CF8(1, 0, a0);
    }
}

/* a2: pointer global explicitly nosda */
void a2(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_00282948(s0 + 0x2C0) != 0) {
        *(s32 *)(s0 + 0x2C0) = func_002A7820(D_L12_001B20C0, (s32)D_L12_001B20C4_ns);
        func_002E5CF8(1, 0, a0);
    }
}

/* ---------------- func_L12_004254A8 ---------------- */
extern s32 func_002ACBC8(void *);
extern void func_002A7750(void *, s32, s32);

void b1(u8 *a0) {
    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (*(s32 *)*(u8 **)(a0 + 0x68) == -1)
        return;
    if (func_002ACBC8((void *)0x00189EA0) == 0)
        return;
    *(u8 *)0x001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b2: same, with an int-typed body word */
void b2(u8 *a0) {
    if (*(u8 *)(a0 + 0x20))
        return;
    if (*(s32 *)*(u32 **)(a0 + 0x68) == -1)
        return;
    if (!func_002ACBC8((void *)0x00189EA0))
        return;
    *(u8 *)0x001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* ---------------- func_L02_003FC1B0 ---------------- */
/* c1: switch, break on 0xA44, no default */
s32 c1(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    switch (a1) {
    case 0xA44:
        break;
    case 0x9CA:
        return ++v1[0x14];
    case 0xB22:
        return ++v1[0x15];
    case 0xC3B:
        return ++v1[0x16];
    case 0xC3E:
        return ++v1[0x17];
    }
    return 0xA44;
}

/* c2: switch with explicit returns, no default, unsigned arg */
s32 c2(u8 *a0, u32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    switch (a1) {
    case 0x9CA:
        return ++v1[0x14];
    case 0xB22:
        return ++v1[0x15];
    case 0xC3B:
        return ++v1[0x16];
    case 0xC3E:
        return ++v1[0x17];
    }
    return 0xA44;
}

/* c3: if/else chain in the retail's compare order */
s32 c3(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    if (a1 == 0xA44)
        return 0xA44;
    if (a1 >= 0xA45) {
        if (a1 == 0xC3B)
            return ++v1[0x16];
        if (a1 >= 0xC3C) {
            if (a1 == 0xC3E)
                return ++v1[0x17];
            return 0xC3E;
        }
        if (a1 == 0xB22)
            return ++v1[0x15];
        return 0xB22;
    }
    if (a1 == 0x9CA)
        return ++v1[0x14];
    return 0x9CA;
}
