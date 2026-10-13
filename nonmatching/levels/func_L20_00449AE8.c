/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: the build refuses this body at its
   place — instruction at +0x4 differs. Kept as a starting point;
   not linked, not counted. */
void func_L20_00449AE8(char *arg0) {
    TI128 tmp;

    func_00282CF0(&tmp, (void *)0x001B9FC0, arg0 + 0x10);
    func_00282F20(&tmp, &tmp, 1.0f);
    func_0032DA58(arg0, arg0 + 0x10, &tmp, *(float *)(arg0 + 0x18) - 0.5f);
    func_002A8C28(arg0, arg0 + 0x10, 0x10000, 0, 6.0f, D_L20_001B23EC, 2.0f, 1, 0);
    *(int *)(arg0 + 0x98) = 0;
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
    func_002A7750(arg0, 1, -1);
}
