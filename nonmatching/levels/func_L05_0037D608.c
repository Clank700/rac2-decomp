/* Near miss from src/levels/shared/L05_0037B6D0.c: the build refuses this body at its place.
   Kept as a starting point; not linked, not counted. */
void func_L05_0037D608(char *a0, char *a1, float f12)
{
    short *s0 = D_L05_0020B220[((unsigned char *)a0)[0x21]];
    float f21 = f12;
    float f20;
    float m[4];

    if (s0 == 0)
        return;
    do {
        char *obj = D_L05_001B251C + (((unsigned short)*s0 & 0x7FFF) << 8);

        if (func_002ED688(obj) != 0) {
            float a = func_002A7940();
            float b = func_002A7940();

            f20 = a;
            func_002AF000((char *)m, f21, f20, b);
            func_00282CC0((char *)m, (char *)m, a1);
            func_002EE920(obj, (char *)m);
        }
        s0++;
    } while (*s0 >= 0);
}
