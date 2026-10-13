/* Near miss from src/levels/shared/L05_0037B6D0.c: the build refuses this body at its
   place — 324 bytes, expected 344. Kept as a starting point;
   not linked, not counted. */
void func_L05_0037BD40(char *a0)
{
    char *s4 = 0;
    char *s3;
    short *s1;

    if (D_L05_0020B220[((unsigned char *)a0)[0x21]] == 0)
        return;
    s3 = (char *)func_002ED688(a0);
    s1 = D_L05_0020B220[((unsigned char *)a0)[0x21]];
    do {
        char *p = D_L05_001B251C + (((unsigned short)*s1 & 0x7FFF) << 8);
        char *r = (char *)func_002ED688(p);

        if (func_L05_0037BBB8(p) != 0 && func_L05_0037BB90(p) == 0 &&
            *(int *)(r + 0x1C) == *(int *)(s3 + 0x1C) && *(int *)(r + 0x20) == 1)
            s4 = p;
        s1++;
    } while (*s1 >= 0);
    {
        char *q = (char *)func_002ED688(s4);

        *(TI128 *)s3 = *(TI128 *)q;
        func_00282C88(q);
        *(int *)(q + 0x20) = 0;
        *(int *)(s3 + 0x20) = 1;
        *(int *)(q + 0x10) = 0;
        *(int *)(s3 + 0x10) = (int)s4;
        *(int *)(q + 0x14) = 1;
        *(int *)(s3 + 0x14) = 0;
        *(int *)(q + 0x18) = *(int *)(s3 + 0x18);
        func_002EE678(s4, 1);
        *(int *)(s3 + 0x18) = -1;
    }
}
