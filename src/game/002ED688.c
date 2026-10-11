#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

/* func_002EE6A8: owner ABI/declaration review retained. */
extern int func_002ED688(unsigned char *owner);

/* func_002ED870: owner ABI/declaration review retained. */
extern unsigned int D_00214FCC;

s32 func_002ED688(u8 *a0) {
 if((*(unsigned short *)(a0+0x34)&0x20)==0) return 0;
 return (*(s32 **)(a0+0x68))[5];
}

INCLUDE_ASM("asm/game", func_002ED6B0);

INCLUDE_ASM("asm/game", func_002ED848);

unsigned int func_002ED870(void)
{
    return D_00214FCC;
}

INCLUDE_ASM("asm/game", func_002ED880);

INCLUDE_ASM("asm/game", func_002ED8A0);

INCLUDE_ASM("asm/game", func_002ED8F0);

INCLUDE_ASM("asm/game", func_002ED948);

INCLUDE_ASM("asm/game", func_002ED9A8);

INCLUDE_ASM("asm/game", func_002ED9C0);

INCLUDE_ASM("asm/game", func_002EDA10);

INCLUDE_ASM("asm/game", func_002EE000);

INCLUDE_ASM("asm/game", func_002EE238);

INCLUDE_ASM("asm/game", func_002EE3B0);

INCLUDE_ASM("asm/game", func_002EE610);
