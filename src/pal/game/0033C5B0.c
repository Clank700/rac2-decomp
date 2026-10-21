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

/* Measured target: byte-identical across all 27 levels. */
void func_PAL_0033C920(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x21C) = a1; }

extern int func_0033AB50(int);
extern void F7d9c8805_FUN_003361A8(int);
extern void F7d9c8805_FUN_00336968(int);

int func_PAL_0033CA78(int a0)
{
	char *p = (char *)a0 + 12;
	int i;

	for (i = 4; i != -1; i--) {
		F7d9c8805_FUN_003361A8(p);
		p += 76;
	}
	F7d9c8805_FUN_00336968(a0 + 408);
	F7d9c8805_FUN_00336968(a0 + 496);
	F7d9c8805_FUN_00336968(a0 + 584);
	return a0;
}

INCLUDE_ASM("asm/pal/game", func_PAL_0033CB00);

extern void func_0033AE18(unsigned char *owner, int value);

/* func_0033ABD8 is matched in 003399B0-g8.c (-G8 small data). */

/* Measured target: byte-identical across all 27 levels. */
void func_PAL_0033CD40(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x2C0) = a1; }

INCLUDE_ASM("asm/pal/game", func_PAL_0033CD48);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CD50);

INCLUDE_ASM("asm/pal/game", func_PAL_0033CE70);
