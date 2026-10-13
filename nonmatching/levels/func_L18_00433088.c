/* Near miss from src/levels/18_damosel/L18_003F80A0-g8.c: the build refuses this body at its
   place — 216 bytes, expected 220. Kept as a starting point;
   not linked, not counted. */
void func_L18_00433088(u8 *a0, s32 a1) {
    u8 buf[0x70];
    float t;

    func_0029FC20(*(s32 *)(*(u8 **)(a0 + 0x68) + 0x7C4), a1, buf + 0x10);
    func_00308DE0(buf, D_L18_001B1600, buf + 0x10);
    func_003088F0(buf, buf, buf + 0x40);
    func_00308920(buf + 0x50, D_001C97C0, buf);
    func_00308BD8(buf + 0x50, buf + 0x50, 1.0f);
    *(TI128 *)(buf + 0x60) = *(TI128 *)(buf + 0x10);
    t = func_003089E0(buf + 0x50, buf + 0x60);
    if (D_L18_001B1610 < t) {
        func_00340828(buf, func_00337AD8(D_L18_001B15F0 & 0xFFFFFF,
                                         D_L18_001B15F0, t * t),
                      D_L18_001B15F8, D_L18_001B15F4);
    }
}
