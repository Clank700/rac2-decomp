/* func_L00_00444D18, 44 bytes, 27 placements.  ABANDON - needs its own compile unit.
   A one-line thunk: it loads the resident pointer word at 0x1B272C, adds 0xD9100, and calls
   the update helper with it.
   The body is exact: with `-mno-split-addresses` on the unit, tools/check.py reports
   `func_L00_00444D18: 27 of 27 places match` (measured 2026-10-20, wave 8). Without it this
   cc1 schedules the `lui` of the constant between retail's `lui $v0,%hi` / `lw $v0,%lo($v0)`
   pair and loads into $v1, so +0x4 and +0x8 are swapped and the `addu` differs at +0x1C
   (three words). Six spellings were measured by wave 5 with the same result; `sda`, `nosda`,
   an array of pointers and a `volatile` load were measured here with the same result too.
   The split is the lever, and it cannot be a file-wide flag: `func_L00_004450C0` in the same
   source file matches only with the default profile (`0 of 27` under this flag). The four
   thunks therefore need a sibling unit of their own carrying
   `-O2 -G0 -ffunction-sections -mno-split-addresses`. */

#include "include_asm.h"

extern char *D_L00_001B272C[];
extern int func_0034FAE8(char *);

int func_L00_00444D18(void)
{
    return func_0034FAE8(D_L00_001B272C[0] + 0xD9100);
}
