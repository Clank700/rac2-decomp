/* Near miss from src/levels/shared/L03_002AB5C8.c: the build refuses this body at its
   place — 144 bytes, expected 148. Kept as a starting point;
   not linked, not counted. */
int func_L03_002AB5C8(unsigned char *a0) {
    extern unsigned char D_L03_00189E20[];
    unsigned char *g = D_L03_00189E20;
    unsigned char *e;

    if (g[0x22B4] == 1)
        return 0x51;
    if (a0 == 0)
        return 0x51;
    if (g[0x22BA] == 0)
        return 0x51;
    if (*(short *)(g + 0x24EC) == 0) {
        e = (unsigned char *)(func_2B3760(0) + 0x00139568);
        return *(int *)(0x00266DA0 + *e * 0xE0 + 0x28);
    }
    return (*(int *)(g + 0x24CC) ^ 1) ? 0 : 0x51;
}
