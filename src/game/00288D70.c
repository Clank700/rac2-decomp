#include "common.h"
#include "structs.h"

   /* current buffer */
extern short r1_D_0015EDC4;

/* rac1-decomp src/core/989snd.c: func_0012EC30 */
/* snd_UnkFunction_0012eaf0 */
void func_00288D70(void) {
    *(int *)&r1_D_0015EDC4 = 1;
}

INCLUDE_ASM("asm/game", func_00288D80);
