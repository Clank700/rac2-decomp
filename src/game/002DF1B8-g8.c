#include "include_asm.h"

/* -G8 sibling for src/game/002DF1B8.c: the two argument words go out through
   $gp, so this body needs the small-data addressing mode. */

extern void func_002B49E0(int, int, int, int, int);

extern void func_00284E18(int, int, int);

extern int D_001ABD80 __attribute__((sda));
extern int D_001ABD84 __attribute__((sda));

extern int D_001B1608[] __attribute__((sda));
extern char *D_001B1B5C;
extern char *D_001B1B64;

void func_002DF2E0(int a0, int a1)
{
    char *start;
    char *end;
    char *p;

    func_002B49E0(7, 1, 0, 0, 0);
    D_001ABD84 = a1;
    D_001ABD80 = a0;
    D_001B1608[0] = 0;
    func_00284E18(0, 0, 0);
    start = D_001B1B5C;
    end = D_001B1B64;
    for (p = start; p < end; p += 0x100) {
        *(unsigned short *)(p + 0x34) |= 0x80;
    }
}
