#include "include_asm.h"

/* Bodies whose retail bytes reach their globals through $gp: this file is built -G8.
   Measured here: cc1 emits `sw $r,SYM` as a macro and GAS expands it. Outside a delay
   slot it always becomes `lui $at,%hi ; sw %lo($at)` (HI16/LO16) whatever the attribute;
   inside a delay slot (.set nomacro: one instruction only) it becomes the $gp-relative
   form with a GPREL16 relocation, whose symbol must therefore be named GP + the retail
   displacement. `sda` only adds `.extern SYM,size`. */

extern unsigned int D_L04_001A8ED0;

extern unsigned int D_L04_001B0908 __attribute__((sda));

void func_L04_0040AC80(void)
{
    D_L04_001A8ED0 = 2;
    D_L04_001B0908 = 1;
}

extern unsigned int D_L04_001B0910 __attribute__((sda));

void func_L04_0040AC98(void)
{
    D_L04_001B0910 = 1;
}

/* func_L04_0040AC30 reaches its globals off $gp too, but its body is not matched
   yet; its marker stays in L04_00402D90.c and the attempt is in the wave-8 drafts. */
