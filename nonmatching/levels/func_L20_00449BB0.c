/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: the build refuses this body at its
   place — instruction at +0x20 differs. Kept as a starting point;
   not linked, not counted. */
void func_L20_00449BB0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    char *sub = arg0 + 0x10;
    u32 *p;
    int i;
    int count;
    TI128 buf1;
    TI128 buf2;

    if (*(int *)(state + 0xAC) != 0
        && (D_L20_001B2AC8 & 7) == (int)(((u32)arg0 >> 8) & 7)) {
        count = func_00277F48(sub, 0, arg0, 0, 1.5f);
        if (count > 0) {
            p = (u32 *)0x1C4480;
            for (i = 0; i < count; i++, p++) {
                if (*(short *)(*p + 0xAA) == 0x11E0) {
                    func_L20_00449AE8(arg0);
                    return;
                }
            }
        }
    }
    func_L20_00444C18(*(char **)(state + 0xA4), (char *)&buf1);
    func_00282CF0(&buf2, sub, &buf1);
    if (func_00282E20(&buf2) < D_L20_001B23F0) {
        func_00282F70((char *)&buf2, (char *)&buf2);
        func_00282CC0((u8 *)sub, (u8 *)&buf2, (u8 *)&buf1);
        *(TI128 *)(state + 0x60) = *(TI128 *)sub;
        func_002C9218(*(char **)(state + 0xA0), sub, sub, 0.5f);
    }
}
