#include "include_asm.h"

typedef unsigned char u8;

typedef int s32;

typedef struct {
 u8 prefix[0x30];s32 state;u8 gap0[0x1c];u8 *current;u8 gap1[0x138];s32 bank[2];
} NativeContext;

extern NativeContext D_L24_001BC3C0;

extern u8 D_L24_0028AAC0[];

INCLUDE_ASM("asm/game", func_002E9110);

INCLUDE_ASM("asm/game", func_002E9268);

INCLUDE_ASM("asm/game", func_002EA8E8);

INCLUDE_ASM("asm/game", func_002EA968);

INCLUDE_ASM("asm/game", func_002EAAA8);

INCLUDE_ASM("asm/game", func_002EAB18);

INCLUDE_ASM("asm/game", func_002EB150);

INCLUDE_ASM("asm/game", func_002EB158);

INCLUDE_ASM("asm/game", func_002EB1E0);

INCLUDE_ASM("asm/game", func_002EB598);

INCLUDE_ASM("asm/game", func_002EB7E8);

INCLUDE_ASM("asm/game", func_002EBAA8);

INCLUDE_ASM("asm/game", func_002EBC70);

INCLUDE_ASM("asm/game", func_002EBDF0);

INCLUDE_ASM("asm/game", func_002EC1C0);

INCLUDE_ASM("asm/game", func_002EC408);

INCLUDE_ASM("asm/game", func_002ECB70);

/* selects the level data bank when the resident context is in state 9 */
void func_002ED058(void) {
 s32 index=-1;
 if(D_L24_001BC3C0.state==9) index=1;
 if(index!=-1) {
  D_L24_001BC3C0.current=D_L24_0028AAC0;
  *(s32 *)(D_L24_0028AAC0+0x68)=D_L24_001BC3C0.bank[index];
 }
}

INCLUDE_ASM("asm/game", func_002ED0A0);
