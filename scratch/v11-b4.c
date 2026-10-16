/* worker lvl6-11 -- round 4: constant-form and argument-type variants. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* ---------------- func_L12_00425448 ---------------- */
extern int func_00282948(void *);
extern s32 func_002A7820(s32, s32);
extern s32 func_002E5CF8(s32, s32, void *);
extern s32 D_L12_001B20C0 __attribute__((sda));

/* a3: the absolute global spelled as a literal address (no relocation) */
void a3(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_00282948(s0 + 0x2C0) != 0) {
        *(s32 *)(s0 + 0x2C0) = func_002A7820(D_L12_001B20C0, (s32)*(u8 **)0x001B20C4);
        func_002E5CF8(1, 0, a0);
    }
}

/* a4: the absolute global through a local pointer, result through a local */
void a4(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    if (func_00282948(s0 + 0x2C0) != 0) {
        u8 *q = *(u8 **)0x001B20C4;
        s32 v = func_002A7820(D_L12_001B20C0, (s32)q);

        *(s32 *)(s0 + 0x2C0) = v;
        func_002E5CF8(1, 0, a0);
    }
}

/* ---------------- func_L12_004254A8 ---------------- */
extern s32 func_002ACBC8(s32);
extern void func_002A7750(void *, s32, s32);

/* b3: int argument so the constant comes out lui/addiu signed */
void b3(u8 *a0) {
    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (*(s32 *)*(u8 **)(a0 + 0x68) == -1)
        return;
    if (func_002ACBC8(0x00189EA0) == 0)
        return;
    *(u8 *)0x001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b4: same, explicit signed cast */
void b4(u8 *a0) {
    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (*(s32 *)*(u8 **)(a0 + 0x68) == -1)
        return;
    if (func_002ACBC8((s32)0x00189EA0) == 0)
        return;
    *(u8 *)0x001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b5: named field value and inverted test */
void b5(u8 *a0) {
    u8 *s0 = a0;

    if (*(u8 *)(s0 + 0x20) != 0)
        return;
    if (*(s32 *)*(u8 **)(s0 + 0x68) != -1) {
        if (func_002ACBC8((s32)0x00189EA0) != 0) {
            *(u8 *)0x001395DB = 1;
            func_002A7750(s0, 1, -1);
        }
    }
}
