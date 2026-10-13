/* Near miss from src/levels/11_joba/L11_003D6270-g8.c: the build refuses this body at its
   place — 252 bytes, expected 240. Kept as a starting point;
   not linked, not counted. */
void func_L11_003F2C28(u8 *arg0) {
    u8 *s1 = arg0;
    u8 *s0 = *(u8 **)(s1 + 0x68);
    u16 *v1;
    u16 *v2;
    s32 a2;

    func_L11_003F33E0(s1);
    func_L00_002E6EF8(func_L11_003F3CB8, s1);
    func_L00_002E6EF8(func_L11_003F4F30, s1);
    func_002AB8C0(s1, s0 + 0x70);
    if (*(s16 *)(s0 + 0x70) != 0) {
        *(s32 *)(s0 + 0x28C) = 0;
    } else if (*(s32 *)(s0 + 0x28C) == 0) {
        func_002A0488(s1, *(u32 *)(s0 + 0x280), *(u32 *)(s0 + 0x284),
                      *(u32 *)(s0 + 0x288));
        *(s32 *)(s0 + 0x28C) = 1;
    }
    v1 = (u16 *)(s0 + 0x274);
    v2 = (u16 *)(s0 + 0x2A0);
    a2 = 1;
    do {
        if (*(s16 *)v1 < 0x7FFF)
            *(u16 *)v1 = *(u16 *)v1 + 1;
        a2--;
        v1++;
    } while (a2 >= 0);
    if (*(u16 *)(s1 + 0x96) <= 0xFFFE)
        (*(u16 *)(s1 + 0x96))++;
    func_002B0990(s1, v2, D_L11_001B0670, 0xC, 1);
}
