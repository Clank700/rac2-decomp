/* Near miss from src/levels/shared/L05_00428350.c: the build refuses this body at its
   place — 180 bytes, expected 168. Kept as a starting point;
   not linked, not counted. */
void func_L05_004424B8(char *a0, float f12)
{
    char *a1 = a0;
    char buf[16];
    char *head = a1 + 0x30;
    char *table;

    table = D_001B251C
            + (*(int *)(*(char **)(D_001B1EC4 + ((*(short *)(a1 + 0x84)) << 5) + 0x1C) + 0x20)
               << 8);
    func_3066A0(buf, a1, -f12);
    func_306630(D_001B3620, D_001B3620, buf);
    if (func_2F9888(head, 0x10, table, 0, 0.25f) != 0)
        *(TI128 *)head = *(TI128 *)D_001BFB30;
}
