/* Near miss from src/levels/shared/L22_0039D708.c: the build refuses this body at its
   place — instruction at +0x14 differs. Kept as a starting point;
   not linked, not counted. */
void func_L22_003A2988(void *a0, float f12) {
    char buf[16];
    char *p = (char *)a0;

    func_00282CC0(buf, p, D_00189ED0);
    func_00282F20(buf, buf, f12 + D_L22_001B2AA4);
    func_00282CC0(buf, buf, D_00189ED0);
    *(TI128 *)p = *(TI128 *)buf;
}
