#include "include_asm.h"

INCLUDE_ASM("asm/levels", func_L00_0042A908);

INCLUDE_ASM("asm/levels", func_L00_0042AB40);

void func_L00_0042AB48(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_0042ABF8);

INCLUDE_ASM("asm/levels", func_L00_0042AC18);

INCLUDE_ASM("asm/levels", func_L00_0042AD98);

INCLUDE_ASM("asm/levels", func_L00_0042B038);

INCLUDE_ASM("asm/levels", func_L00_0042B688);

INCLUDE_ASM("asm/levels", func_L00_0042B6A8);

INCLUDE_ASM("asm/levels", func_L00_0042B6C8);

INCLUDE_ASM("asm/levels", func_L00_0042B730);

INCLUDE_ASM("asm/levels", func_L00_0042B840);

INCLUDE_ASM("asm/levels", func_L00_0042BA18);

INCLUDE_ASM("asm/levels", func_L00_0042BAD0);

INCLUDE_ASM("asm/levels", func_L00_0042BC30);

INCLUDE_ASM("asm/levels", func_L00_0042BCF8);

INCLUDE_ASM("asm/levels", func_L00_0042BFF8);

INCLUDE_ASM("asm/levels", func_L00_0042C030);

INCLUDE_ASM("asm/levels", func_L00_0042C290);

INCLUDE_ASM("asm/levels", func_L00_0042C2C8);

/* Store the supplied unsigned 32-bit word at owner byte offset 0x 44. */
void func_L00_0042C358(int param_1, unsigned int param_2)
{
  *(unsigned int*)(param_1 + 0x44) = param_2;
  return;
}

/* Store the supplied unsigned 32-bit word at owner byte offset 0x 40. */
void func_L00_0042C360(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 0x40) = param_2;
  return;
}

INCLUDE_ASM("asm/levels", func_L00_0042C398);

/* Store the supplied unsigned 32-bit word at owner byte offset 0x 40. */
void func_L00_0042C4B8(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 0x40) = param_2;
  return;
}

/* Store the supplied unsigned 32-bit word at owner byte offset 0x 44. */
void func_L00_0042C608(int param_1, unsigned int param_2)
{
  *(unsigned int*)(param_1 + 0x44) = param_2;
  return;
}

void func_L00_0042C6C8(void)
{
}

/* Return the complete supplied unsigned-long 64-bit value unchanged. */
/* Target: FUN_003427B0 — identity function returning its first argument */
/* Disassembly: jr ra; move v0,a0 (MIPS delay slot) */
/* Compiled with: -O2 -G0 -ffunction-sections */

unsigned long func_L00_0042C6D8(unsigned long param_1)
{
  return param_1;
}

INCLUDE_ASM("asm/levels", func_L00_0042C760);
