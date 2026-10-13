/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: the build refuses this body at its
   place — 236 bytes, expected 224. Kept as a starting point;
   not linked, not counted. */
void func_L20_0044AA88(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float a;
    float b;

    a = D_L20_001B2450 * 4.84813745e-06f;
    b = D_L20_001B2454 * 0.000290888245f;
    func_002AAA00(arg0 + 0xF8, state + 0x1A4, 0,
                  func_00283248(*(float *)(state + 0x140) - *(float *)(arg0 + 0x10),
                                *(float *)(state + 0x144) - *(float *)(arg0 + 0x14)),
                  a, a, b);
    b = b * 4.0f;
    func_002AA2E8((float *)(arg0 + 0xF0), *(float *)(state + 0x1A8), b);
    *(int *)(state + 0x1A8) = 0;
    func_002AA2E8((float *)(arg0 + 0xF4), *(float *)(state + 0x1AC), b);
    *(int *)(state + 0x1AC) = 0;
}
