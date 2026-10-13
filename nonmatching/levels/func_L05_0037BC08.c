/* Near miss from src/levels/shared/L05_0037B6D0.c: the build refuses this body at its
   place — 292 bytes, expected 312. Kept as a starting point;
   not linked, not counted. */
void func_L05_0037BC08(char *a0)
{
    char *s4;
    short *s1;

    if (D_L05_0020B220[((unsigned char *)a0)[0x21]] == 0)
        return;
    s4 = (char *)func_002ED688(a0);
    s1 = D_L05_0020B220[((unsigned char *)a0)[0x21]];
    do {
        char *p = D_L05_001B251C + (((unsigned short)*s1 & 0x7FFF) << 8);
        char *r = (char *)func_002ED688(p);

        if (func_L05_0037BBB8(p) != 0 && func_L05_0037BB90(p) == 0 &&
            *(int *)(r + 0x1C) == *(int *)(s4 + 0x1C)) {
            func_L05_0037BB28(p);
            func_002EE678(p, 1);
        }
        s1++;
    } while (*s1 >= 0);
    func_L05_0037BB28(a0);
    func_002EE678(a0, 1);
    D_L05_00221D10[2]--;
}
