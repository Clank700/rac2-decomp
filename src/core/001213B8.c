#include "common.h"
#include "structs.h"

extern void r1_func_0011D4A0(void);

INCLUDE_ASM("asm/core", func_001213B8);

INCLUDE_ASM("asm/core", func_00121450);

INCLUDE_ASM("asm/core", func_00121AB8);

/* rac1-decomp src/core/0011DD68.c: func_0011DD98 */
/* Tail call: retail is `j r1_func_0011D4A0` + nop, with no frame at all.
   2.9-ee emits it natively for a void function that ends in a call. */
void func_00121B18(void) {
    r1_func_0011D4A0();
}

INCLUDE_ASM("asm/core", func_00121B20);

INCLUDE_ASM("asm/core", func_001220F0);

INCLUDE_ASM("asm/core", func_00122630);

INCLUDE_ASM("asm/core", func_00122760);

INCLUDE_ASM("asm/core", func_00122800);

INCLUDE_ASM("asm/core", func_00122A40);

INCLUDE_ASM("asm/core", func_00122A98);

INCLUDE_ASM("asm/core", func_00122B00);

INCLUDE_ASM("asm/core", func_00122DA8);

INCLUDE_ASM("asm/core", func_00122F10);

INCLUDE_ASM("asm/core", func_00123028);

INCLUDE_ASM("asm/core", func_00123078);

INCLUDE_ASM("asm/core", func_00123130);

INCLUDE_ASM("asm/core", func_001231C8);
