/* func_L04_002CC748 - 144 bytes, 2 places. Opus near miss (M18): func_L00_002A4E48 (F300) without the 0x22B4 early-out, in a default -G0 unit. 148/144 B: retail does lui $a1 and keeps it for both base computations; this cc1 does lui $v0 then daddu $a1,$v0 (one insn). Eight spellings of the base pointer tried. */
#include "include_asm.h"
typedef unsigned char u8;
typedef short s16;
extern char D_00189E20[];
extern u8 D_00139568[];
extern char D_L04_0027B470[];
extern int func_L00_002ADEA0(int);
typedef struct {
    u8 pad[0x28];
    int v;
} WeaponEntry;

/* func_L00_002A4E48 without the 0x22B4 early-out; its own unit for the default profile. */
int func_L04_002CC748(char *a0)
{
    char *s0 = D_00189E20;

    if (a0 != 0 && *(u8 *)(s0 + 0x22BA) != 0 && *(s16 *)(s0 + 0x24EC) == 0) {
        int idx = func_L00_002ADEA0(0);
        return ((WeaponEntry *)(D_L04_0027B470 + D_00139568[idx] * 224))->v;
    }
    a0 = D_00189E20;
    if (*(int *)(a0 + 0x24CC) != 1)
        return *(u8 *)(a0 + 0x1492) ? 0x67 : 0;
    return 0x51;
}
