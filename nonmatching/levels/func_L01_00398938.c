/* Near miss from src/levels/shared/L01_00397110-g8.c: the build refuses this body at its
   place — 348 bytes, expected 340. Kept as a starting point;
   not linked, not counted. */
void func_L01_00398938(char *a0)
{
    char *s1 = *(char **)(a0 + 0x68);
    char **q = (char **)(s1 + 0x14);
    float v[4];
    int i;

    for (i = 2; i >= 0; i--) {
        char *o = *q;

        if (o != 0) {
            *(TI128 *)(o + 0x10) = *(TI128 *)(a0 + 0x10);
            *(float *)(o + 0x18) = *(float *)(o + 0x18) + D_L01_001AF578;
            *(float *)(o + 0xF4) = D_L01_001AF598 * 0.01745329424738884f;
            func_002E3CB8(o + 0xC0, o + 0xF0);
            func_002E3738(v, o + 0xC0,
                          *(float *)(s1 + 0x20) * 2.4000000953674316f -
                              1.2000000476837158f);
            func_002E3470(o + 0x10, o + 0x10, v);
            *(float *)(o + 0xF4) =
                *(float *)(s1 + 0x24) * -1.047197699546814f - 0.349065899848938f;
            func_002E3CB8(o + 0xC0, o + 0xF0);
            func_00308938(o);
        }
        q++;
    }
}
