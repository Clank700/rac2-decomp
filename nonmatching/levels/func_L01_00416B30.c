/* Near miss from src/levels/01_oozla/L01_003DA740.c: the build refuses this body at its
   place — instruction at +0x8 differs. Kept as a starting point;
   not linked, not counted. */
void func_L01_00416B30(u8 *a0) {
    s32 i;
    u8 *o = (u8 *)*(s32 **)(a0 + 0x68);
    f32 *p = (f32 *)(o + 0x20);
    s32 *ip;
    s32 v;

    for (i = 3; i >= 0; i--) {
        *p = (f32)func_L01_003104E8(0xFF);
        p++;
    }
    *(f32 *)(o + 0x30) = -1.0f;
    *(f32 *)(o + 0x34) = -2.25f;
    *(f32 *)(o + 0x38) = 1.25f;
    *(f32 *)(o + 0x3C) = 2.5f;
    ip = (s32 *)(o + 0x4C);
    v = 0xFF;
    for (i = 3; i >= 0; i--) {
        *ip = v;
        ip--;
        v -= 0x40;
    }
    *(f32 *)(o + 0x50) = 2.5f;
    *(f32 *)(o + 0x54) = 3.0f;
    *(f32 *)(o + 0x58) = 3.0f;
    *(f32 *)(o + 0x5C) = 2.5f;
}
