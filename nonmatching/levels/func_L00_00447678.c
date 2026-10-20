/* func_L00_00447678, 48 bytes, 27 placements.  ABANDON - needs its own compile unit.
   A one-line thunk with `return 1`: it loads the resident pointer word at 0x1B272C, adds
   0xD9090, and calls the first sub-object's lookup helper with it.
   Exact with `-mno-split-addresses` on the unit (`func_L00_00447678: 27 of 27 places match`,
   measured 2026-10-20, wave 8); without it the constant's `lui` is scheduled between retail's
   `lui $v0,%hi` / `lw $v0,%lo($v0)` pair and the load goes to $v1 (three words).
   See func_L00_00444D18.c for the measured spellings and why the flag cannot cover the whole
   source file. */

#include "include_asm.h"

extern char *D_L00_001B272C[];
extern void func_00350DC8(char *);

int func_L00_00447678(void)
{
    func_00350DC8(D_L00_001B272C[0] + 0xD9090);
    return 1;
}
