/* Near miss from src/levels/shared/L22_0039D708.c: the build refuses this body at its
   place — 288 bytes, expected 292. Kept as a starting point;
   not linked, not counted. */
void func_L22_003A2B90(void *arg0, void *a1, void *a2, int a3) {
    char *a0 = (char *)arg0;
    char *s7 = *(char **)(a0 + 0x68) + 0x2A0;
    float best = 30000.0f;
    int i;

    for (i = 0; i < 0x20; i++) {
        Rec_003A2D58 *rec;
        char *e;
        int j;

        if (a3 != 0 && func_L22_003A48F8(i) == 0) continue;
        rec = D_L22_001FE940[*(int *)(s7 + i * 4)];
        if (rec->count <= 0) continue;
        e = (char *)rec + 0x10;
        for (j = 0; j < rec->count; j++) {
            float f = func_00282E48(e, a1);
            if (f < best) {
                best = f;
                *(TI128 *)a2 = *(TI128 *)e;
            }
            e += 0x10;
        }
    }
}
