#include "include_asm.h"

INCLUDE_ASM("asm/pal/levels", func_PAL_L22_003A95C8);

typedef unsigned char u8;
extern u8 D_001A63A8_4[];
extern u8 D_00189E20[];

/* shared native body of family cbc1388ebe801e68 */
void func_PAL_L22_003A9808(u8 *a0, int a1) {
    u8 *g = D_001A63A8_4;
    u8 *p = *(u8 **)(a0 + 104);
    int bit;
    if (*(int *)(g + 104) != 0) return;
    if (*(int *)(g + 36) != -1) return;
    if (a1 == *(int *)(p + 1256)) return;
    bit = 1 << a1;
    { u8 *w = p + a1 * 4; *(int *)(g + 36) = (*(int *)(w + 1152) & 0x3fff) + 2000; }
    *(int *)(g + 40) = 0;
    *(int *)(p + 1256) = a1;
    *(int *)(p + 1252) = 1500;
    *(int *)(p + 1248) |= bit;
}

INCLUDE_ASM("asm/pal/levels", func_PAL_L22_003A9880);
