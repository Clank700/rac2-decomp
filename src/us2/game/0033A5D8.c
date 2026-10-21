#include "include_asm.h"

extern void func_00336320_1(char *a);
extern void func_00336A78_1(char *a);

/* early-returns when a 32-bit field is zero, otherwise calls one helper four times and another three times with fixed byte offsets off the argument pointer. */
void func_US2_0033A5D8(char *a0)
{
    if (*(int *)(a0 + 728) == 0)
        return;
    func_00336320_1(a0 + 8);
    func_00336320_1(a0 + 84);
    func_00336320_1(a0 + 160);
    func_00336320_1(a0 + 236);
    func_00336A78_1(a0 + 312);
    func_00336A78_1(a0 + 400);
    func_00336A78_1(a0 + 488);
}

char *func_US2_0033A640(char *object)
{
    extern void func_0033AB50(void *);
    extern void *func_003361A8(void *);
    func_0033AB50(object + 8);
    func_003361A8(object + 0x2D8);
    return object;
}

INCLUDE_ASM("asm/us2/game", func_US2_0033A678);

INCLUDE_ASM("asm/us2/game", func_US2_0033A7A8);

INCLUDE_ASM("asm/us2/game", func_US2_0033A7B8);

INCLUDE_ASM("asm/us2/game", func_US2_0033A7D8);

INCLUDE_ASM("asm/us2/game", func_US2_0033A7E0);

INCLUDE_ASM("asm/us2/game", func_US2_0033A860);

INCLUDE_ASM("asm/us2/game", func_US2_0033A8F0);

INCLUDE_ASM("asm/us2/game", func_US2_0033A9F8);

INCLUDE_ASM("asm/us2/game", func_US2_0033AA80);

INCLUDE_ASM("asm/us2/game", func_US2_0033AB18);

INCLUDE_ASM("asm/us2/game", func_US2_0033AF70);

INCLUDE_ASM("asm/us2/game", func_US2_0033B428);
