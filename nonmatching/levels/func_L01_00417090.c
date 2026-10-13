/* Near miss from src/levels/shared/L01_00397110-g8.c: the build refuses this body at its
   place — 316 bytes, expected 308. Kept as a starting point;
   not linked, not counted. */
void func_L01_00417090(char *a0)
{
    float m[4];
    float m2[4];
    float tmp[4];
    float *p;
    int i;

    if (*(unsigned char *)(a0 + 0x20) == 1)
        func_002E34E0(tmp, a0, 0.0009765625f);
    else
        func_00307390(a0, 0, tmp);

    {
        float k = 0.01666666753590107f;

        func_00310708(m, D_L01_001B1A9C * k, D_L01_001B1AA0 * k);
        p = m;
        {
            unsigned char a = D_L01_001B1AAC;

            func_00330048(tmp, p, D_L01_001B1AB0, a, (unsigned char)func_003104E8(0xFF), 0);
        }

        i = 2;
        do {
            func_00310708(m2, D_L01_001B1AA4 * k, D_L01_001B1AA8 * k);
            func_002E3470(p, p, m2);
            {
                unsigned char a = D_L01_001B1AAC;

                func_00330048(tmp, p, D_L01_001B1AB4, a,
                              (unsigned char)func_003104E8(0xFF), 0);
            }
        } while (--i >= 0);
    }
}
