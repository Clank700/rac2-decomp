#include "include_asm.h"

extern int ref_L00_002FC030_00 __attribute__((sda));

extern int ref_L00_002FC048_00 __attribute__((sda));

void func_00290730(void)
{
    if (ref_L00_002FC030_00 == 0)
        ref_L00_002FC030_00 = 1;
}

int func_00290748(void)
{
    return ref_L00_002FC048_00 == 3;
}

INCLUDE_ASM("asm/game", func_00290758);

INCLUDE_ASM("asm/game", func_002908D0);

INCLUDE_ASM("asm/game", func_00290978);

INCLUDE_ASM("asm/game", func_00290A40);

INCLUDE_ASM("asm/game", func_00290AA8);

INCLUDE_ASM("asm/game", func_00290AB0);

INCLUDE_ASM("asm/game", func_00290B48);

INCLUDE_ASM("asm/game", func_00290C60);

INCLUDE_ASM("asm/game", func_00291108);

INCLUDE_ASM("asm/game", func_00291128);

INCLUDE_ASM("asm/game", func_00291148);

INCLUDE_ASM("asm/game", func_00291158);

INCLUDE_ASM("asm/game", func_00291268);

INCLUDE_ASM("asm/game", func_002912E8);
