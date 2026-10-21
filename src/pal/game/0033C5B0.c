#include "include_asm.h"

typedef float f32;
typedef unsigned char u8;

/* func_0033A688 is matched in 003399B0-g8.c (-G8 small data). */

/* func_0033A6D8 is matched in 003399B0-g8.c (-G8 small data). */

/* Measured target: byte-identical across all 27 levels. */
void func_PAL_0033C8F0(u8 *a0, f32 a1) { *(f32 *)(a0 + 0x214) = a1; }

typedef int s32;

/* lot6 -- measured bodies with sizes recorded in the catalogue. */
void func_PAL_0033C8F8(u8 *a0, s32 a1, s32 a2) { a0 += a1 * 4; *(s32 *)(a0 + 0x1C8) = a2; }

/* writes the value if it is below the maximum; byte-identical across all 27 levels. */
void func_PAL_0033C908(u8 *a0, s32 a1) { if (a1 < *(s32 *)(a0 + 0x208)) *(s32 *)(a0 + 0x218) = a1; }

INCLUDE_ASM("asm/pal/game", func_PAL_0033C920);

INCLUDE_ASM("asm/pal/game", func_PAL_0033C928);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CA78);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CB00);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CD40);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CD48);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CD50);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CE70);
