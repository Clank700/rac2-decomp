#include "common.h"
#include "structs.h"

   /* current buffer */
extern short r1_D_0015EDC4;

/* rac1-decomp src/core/989snd.c: func_0012EC30 */
/* snd_UnkFunction_0012eaf0 */
void func_00287E98(void) {
    *(int *)&r1_D_0015EDC4 = 1;
}

INCLUDE_ASM("asm/game", func_00287EA8);

INCLUDE_ASM("asm/game", func_00287EB0);

INCLUDE_ASM("asm/game", func_00287F60);

INCLUDE_ASM("asm/game", func_00287FF8);
