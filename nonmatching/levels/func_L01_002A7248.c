#include "include_asm.h"
typedef unsigned char u8;
typedef short s16;
extern char D_00189E20[];
extern u8 D_00139568[];
extern char D_L01_002637A0[];
extern int func_L00_002ADEA0(int);
typedef struct {
    u8 pad[0x28];
    int v;
} WeaponEntry;

/* func_L01_002A7248 - 128 bytes, 4 places. Opus near miss (M26): 132/128 B, one insn over, the
   same blocker as func_L04_002CC748: retail keeps one lui of D_00189E20 in $v1 for both base
   computations, this cc1 copies it. Block-local pointers, direct reads, a reassigned
   parameter, an int result local and an inverted test all leave the copy or drop a lo. */
/* func_L03_002AB5C8 without the 0x22B4 early-out. */
int func_L01_002A7248(char *a0)
{
    if (a0 != 0) {
        char *s0 = D_00189E20;
        if (*(u8 *)(s0 + 0x22BA) != 0 && *(s16 *)(s0 + 0x24EC) == 0) {
            int idx = func_L00_002ADEA0(0);
            return ((WeaponEntry *)(D_L01_002637A0 + D_00139568[idx] * 224))->v;
        }
    }
    {
        char *p = D_00189E20;
        if (*(int *)(p + 0x24CC) != 1)
            return 0;
    }
    return 0x51;
}
