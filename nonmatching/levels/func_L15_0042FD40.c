/* Near miss from src/levels/15_gorn/L15_00315428-g8.c: the build refuses this body at its
   place — instruction at +0xc differs. Kept as a starting point;
   not linked, not counted. */
void func_L15_0042FD40(void)
{
    char *stage = D_L15_00221E10;
    char *p;
    int n;

    D_L15_001B1530 = -2;
    *(int *)(stage + 0x2C) = 1;
    *(int *)(stage + 0x28) = 100;
    D_L15_001B15C4 = 1;
    D_L15_001B1534 = 0;
    n = func_80381310(6);
    *(int *)(stage + 0x14) = 0;
    *(float *)(stage + 0x30) = 8.0f;
    p = (char *)(D_L15_0029FD80 + n * 40);
    *(int *)(p + 0x14) = *(int *)(p + 0x10);
    func_80380770(0, p);
    func_80383FB8();
    func_803807B0();
}
