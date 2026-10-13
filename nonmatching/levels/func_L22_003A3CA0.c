/* Near miss from src/levels/shared/L22_0039D708.c: the build refuses this body at its
   place — 192 bytes, expected 176. Kept as a starting point;
   not linked, not counted. */
void func_L22_003A3CA0(char *a0) {
    char *s = *(char **)(a0 + 0x68);
    int a;
    int b;
    int i;
    int k;
    int *p;

    *(int *)0x001B2AC4 = 0;
    for (i = 0; i < 3; i++) {
        p = (int *)(0x0023B530 + i * 0xF0 + 0xC4);
        ((int *)0x001B2AB8)[i] = 0;
        for (k = 0x31; k >= 0; k--) {
            *p = 0;
            p--;
        }
    }
    a = *(short *)(s + 0x32E);
    b = *(short *)(s + 0x32A);
    D_001B1920.fC = a;
    D_L22_001B2AB4[0]->fC = a;
    D_001B1920.f8 = b;
    D_L22_001B2AB4[0]->f8 = b;
    D_001B1920.f0 = 0;
    D_L22_001B2AB4[0]->f0 = 0;
    D_001B1920.f4 = 0;
    D_L22_001B2AB4[0]->f4 = 0;
}
