/* worker lvl6-11 -- round 6: allocation shapes for the -1 compare in func_L12_004254A8. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 func_002ACBC8(s32);
extern void func_002A7750(void *, s32, s32);
extern u8 D_L12_00189EA0[];
extern u8 D_L12_001395DB;

/* b8: typed pointer local, indexed field */
void b8(u8 *a0) {
    s32 *p;

    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    p = *(s32 **)(a0 + 0x68);
    if (p[0] == -1)
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b9: the object pointer in a local, unsigned compare against -1 */
void b9(u8 *a0) {
    u8 *s0;

    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    s0 = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s0 + 0x0) == -1)
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b10: constant on the left */
void b10(u8 *a0) {
    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (-1 == *(s32 *)&((u8 *)*(u8 **)(a0 + 0x68))[0])
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b11: field value through a named local declared before the guard */
void b11(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);
    s32 v = *(s32 *)(s0 + 0);

    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (v == -1)
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b12: the field compared through a pointer variable, arithmetically inverted */
void b12(u8 *a0) {
    s32 *p;

    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    p = *(s32 **)(a0 + 0x68);
    if (*p != -1) {
        if (func_002ACBC8((s32)D_L12_00189EA0) != 0) {
            D_L12_001395DB = 1;
            func_002A7750(a0, 1, -1);
        }
    }
}
