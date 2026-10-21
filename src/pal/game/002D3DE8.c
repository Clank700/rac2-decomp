#include "include_asm.h"

typedef struct {
    char reserved00[0x14];
    char *source;
    int value;
    char reserved1c[0x118];
    int fallback;
} CallbackState;
extern CallbackState D_001F2840;
extern int D_00138344;
extern void func_0029C760(int);

int func_PAL_002D3DE8(void) {
    int result = 0;
    int flags = D_00138344;
    if (flags & 0x10) {
        int value = *(int *)(D_001F2840.source + 0xE0);
        if (value != 0)
            D_001F2840.value = value;
        else if (D_001F2840.fallback == 0) {
            value = -1;
            goto return_value;
        }
        value = 0;
return_value:
        return value;
    }
    if (flags & 0x900)
        result = 1;
    else
        func_0029C760(flags);
    return result;
}

INCLUDE_ASM("asm/pal/game", func_PAL_002D3E70);

INCLUDE_ASM("asm/pal/game", func_PAL_002D3EA0);

INCLUDE_ASM("asm/pal/game", func_PAL_002D3F28);

INCLUDE_ASM("asm/pal/game", func_PAL_002D3F58);

INCLUDE_ASM("asm/pal/game", func_PAL_002D3FE0);

INCLUDE_ASM("asm/pal/game", func_PAL_002D4010);

INCLUDE_ASM("asm/pal/game", func_PAL_002D4098);
