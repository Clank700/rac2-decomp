/* Near miss from src/levels/03_endako/L03_00399230-g8.c: the build refuses this body at its
   place — 212 bytes, expected 208. Kept as a starting point;
   not linked, not counted. */
char *func_L03_003D18F8(char *a0, char *a1, f32 *a2, s32 a3)
{
    char *s1 = func_3113F0(0xA02);
    char *s0;

    if (s1 == 0)
        return s1;
    func_32AA20(s1, a0);
    s0 = *(char **)(s1 + 0x68);
    *(TI128 *)(s1 + 0x10) = *(TI128 *)a1;
    *(TI128 *)s0 = *(TI128 *)a2;
    *(f32 *)(s1 + 0xF8) = func_2EF670(a2[0], a2[1]);
    {
        f32 t = func_2EF110(a2);

        *(f32 *)(s1 + 0xF4) = -func_2EF670(t, a2[2]);
    }
    *(s32 *)(s0 + 0x38) = a3;
    *(s32 *)(s0 + 0x30) = 0x78;
    *(f32 *)(s1 + 0x2C) = *(f32 *)(*(u32 *)(s1 + 0x24) + 0x24)
        * D_L03_001B0648;
    return s1;
}
