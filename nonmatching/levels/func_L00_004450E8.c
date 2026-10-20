/* func_L00_004450E8, 44 bytes, 27 placements.  ABANDON - needs its own compile unit.
   The release twin of func_L00_00444D18: load the resident pointer word at 0x1B272C, add
   0xD9100, and hand it to the release helper.
   Exact with `-mno-split-addresses` on the unit (`func_L00_004450E8: 27 of 27 places match`,
   measured 2026-10-20, wave 8); without it the constant's `lui` is scheduled between retail's
   `lui $v0,%hi` / `lw $v0,%lo($v0)` pair and the load goes to $v1 (three words).
   See func_L00_00444D18.c for the measured spellings and why the flag cannot cover the whole
   source file. */

#include "include_asm.h"

extern char *D_L00_001B272C[];
extern void func_0034FAF8(int *);

void func_L00_004450E8(void)
{
    func_0034FAF8((int *)(D_L00_001B272C[0] + 0xD9100));
}
