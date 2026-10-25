/* Near miss: per-frame sweep that walks two half circles around D_00189E20.
 *
 * wslcmp (00_aranos_tutorial): 0 of 22 places; 472 bytes against 480, first
 * difference in the prologue (frame 0x70 against retail's 0x80). The whole body
 * agrees: the +0xA48 counter gate, the 0.0100000007f/18.0f/0.0250000022f scale
 * constants, the 0.785398006f half angle, both stack vectors (v[3] at sp+0 and
 * w[3] at sp+0x10), the func_002A7878_6(0.4f, 0.5f) result and the +-2.0f fifth
 * argument, and the func_002A77E0_2 tail with the zero case. Retail additionally
 * keeps the symbol's %hi in $s5 and re-materialises the base inside the loop
 * (`addiu $s0,$s5,-0x61E0`), saving one more callee-saved register; this cc1
 * keeps the base in one register (the shape func_L00_002AA478 above uses).
 * Measured: direct `*(float *)(D_00189E20 + 0xNN)` casts anchor a +0x80-based
 * pointer (496 bytes); a struct with 0x80/0x84/0x98/0x330/0xA48 members gives
 * 504 bytes and an extra $s6. Callee mapping measured by matching level-0 call
 * addresses against the catalogue (they print anonymously as 0x2EExxx):
 * 0x2EE6E0/0x2EE6F8 = func_00283180/func_00283198, 0x2EF0F8/0x2EF140 =
 * func_00283B98/func_00283BE0, 0x31A728/0x31A7C0 = func_002A77E0/func_002A7878,
 * 0x338AE0 = func_L00_00338AE0. Reopen by forcing retail's %hi/base split.
 */
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_L00_00338AE0(float *, float *, float *, float, float);

void func_L00_002AA570(char *self, int arg1)
{
    float v[3];
    float w[3];
    float f;
    float r;
    int n;
    int i;
    char *p;

    p = D_00189E20_20;
    n = *(unsigned short *)(p + 0xA48) + 1;
    *(unsigned short *)(p + 0xA48) = n;
    if (arg1 < (short)n) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                f = func_00283B98(*(float *)(p + 0x98), 0.785398006f);
            else
                f = func_00283BE0(*(float *)(p + 0x98), 0.785398006f);
            v[0] = func_00283180(f) * 0.0100000007f;
            v[1] = func_00283198(f) * 0.0100000007f;
            w[0] = *(float *)(p + 0x80) + v[0] * 18.0f;
            w[1] = *(float *)(p + 0x84) + v[1] * 18.0f;
            w[2] = *(float *)(p + 0x330);
            v[2] = 0.0f;
            v[0] = v[0] - func_00283180(*(float *)(p + 0x98)) * 0.0250000022f;
            v[1] = v[1] - func_00283198(*(float *)(p + 0x98)) * 0.0250000022f;
            r = func_002A7878_6(0.4f, 0.5f);
            func_L00_00338AE0(w, v, (float *)(p + 0x330), r,
                              i == 0 ? 2.0f : -2.0f);
            if (self == 0)
                *(unsigned short *)(p + 0xA48) = 0;
            else
                *(unsigned short *)(p + 0xA48) = func_002A77E0_2(self);
        }
    }
}
