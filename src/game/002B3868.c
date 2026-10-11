#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

s32 func_002B3868(u8 *a0) {
 u8 flags=a0[0xbe];
 if(((flags^1)&1)!=0) {a0[0xbe]=flags|1;return 1;}
 return 0;
}

INCLUDE_ASM("asm/game", func_002B3890);

INCLUDE_ASM("asm/game", func_002B38B8);

INCLUDE_ASM("asm/game", func_002B38C8);

INCLUDE_ASM("asm/game", func_002B39A0);

INCLUDE_ASM("asm/game", func_002B3B20);

INCLUDE_ASM("asm/game", func_002B3BA8);

INCLUDE_ASM("asm/game", func_002B4028);

INCLUDE_ASM("asm/game", func_002B4038);

INCLUDE_ASM("asm/game", func_002B4068);

INCLUDE_ASM("asm/game", func_002B4090);

INCLUDE_ASM("asm/game", func_002B41A0);

INCLUDE_ASM("asm/game", func_002B41A8);

INCLUDE_ASM("asm/game", func_002B44C0);

INCLUDE_ASM("asm/game", func_002B49A0);

INCLUDE_ASM("asm/game", func_002B49B0);

INCLUDE_ASM("asm/game", func_002B49C0);

INCLUDE_ASM("asm/game", func_002B49C8);

INCLUDE_ASM("asm/game", func_002B49E0);

INCLUDE_ASM("asm/game", func_002B4B70);

INCLUDE_ASM("asm/game", func_002B4BE8);

INCLUDE_ASM("asm/game", func_002B4C18);

INCLUDE_ASM("asm/game", func_002B4FF0);

INCLUDE_ASM("asm/game", func_002B50D8);

INCLUDE_ASM("asm/game", func_002B50E0);

INCLUDE_ASM("asm/game", func_002B5258);
