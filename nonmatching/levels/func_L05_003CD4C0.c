/* Near miss from src/levels/shared/L05_0037B6D0.c: the build refuses this body at its
   place — instruction at +0x4c differs. Kept as a starting point;
   not linked, not counted. */
void func_L05_003CD4C0(char *a0)
{
    char *s1 = *(char **)(a0 + 0x68);
    char *s0 = s1;
    int j;
    int i;
    int v;

    for (i = 3; i >= 0; i--) {
        *(float *)s0 = (float)func_002A77E0(0xFF);
        s0 += 4;
    }
    *(float *)(s1 + 0x10) = -1.0f;
    *(float *)(s1 + 0x14) = -2.25f;
    *(float *)(s1 + 0x18) = 1.25f;
    *(float *)(s1 + 0x1C) = 2.5f;
    v = 0xFF;
    for (j = 3; j >= 0; j--) {
        *(int *)((char *)s1 + 0x2C + j * -4) = v;
        v -= 0x40;
    }
    *(float *)(s1 + 0x34) = 3.5f;
    *(float *)(s1 + 0x30) = 2.8f;
    *(float *)(s1 + 0x38) = 3.5f;
    *(float *)(s1 + 0x3C) = 2.8f;
}
