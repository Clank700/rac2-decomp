/* Near miss from src/levels/shared/L05_0037B6D0.c: the build refuses this body at its
   place — instruction at +0xc differs. Kept as a starting point;
   not linked, not counted. */
void func_L05_003CFB90(char *a0, char *a1)
{
    char buf[0x30];

    *(char *)(buf + 0x19) = 2;
    *(int *)(buf + 0x10) = (int)a0;
    *(int *)(buf + 0x14) = 0x10000;
    *(int *)(buf + 0x20) = 1;
    *(short *)(buf + 0x1A) = *(short *)(a0 + 0xAA);
    *(char *)(buf + 0x18) = 0;
    func_00282CF0((float *)buf, a0 + 0x10, a1);
    func_00282F20(buf, buf, 1.0f);
    *(float *)(buf + 0x0C) = 5628.6171875f;
    *(float *)(buf + 0x1C) = 5.0f;
    func_002A8E20(a0, buf);
}
