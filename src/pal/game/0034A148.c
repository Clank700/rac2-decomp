#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_0034A148);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A230);

typedef int s32;
typedef unsigned char u8;

void func_PAL_0034A2A0(u8 *a0, s32 a1, s32 a2) { *(s32 *)(a0 + 0xB8) = a1; *(s32 *)(a0 + 0xBC) = a2; }

void func_PAL_0034A2B0(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 0xC8) = param_2;
  return;
}

typedef float f32;

void func_PAL_0034A2B8(u8 *a0,f32 f0,f32 f1) {
 (*(f32 **)(a0+0x5C))[0]=f0;
 (*(f32 **)(a0+0x5C))[1]=f1;
 (*(s32 **)(a0+0x5C))[2]=0;
 (*(s32 **)(a0+0x5C))[3]=0;
}

/* Measured target: byte-identical across all 27 levels. */
void func_PAL_0034A2E0(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x60) = a1; }

/* Measured target: byte-identical across all 27 levels. */
void func_PAL_0034A2E8(u8 *a0, s32 a1) { *(s32 *)(a0 + 0xCC) = a1; }

INCLUDE_ASM("asm/pal/game", func_PAL_0034A2F0);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A2F8);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A300);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A690);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A738);

INCLUDE_ASM("asm/pal/game", func_PAL_0034A740);
