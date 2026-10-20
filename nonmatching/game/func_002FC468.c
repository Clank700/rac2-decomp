/* func_002FC468: 160 bytes compiled (-O2 -G0 in its own file), retail 164.
   Still differs: the constant 0x01000404 goes to $a1 where retail uses $a3, and retail has one
   dead `daddu $a2,$s0,$zero` after `sll $s0,$s0,4` (the 4-byte gap). A -G0 file is needed:
   src/game/002FC3C0.c is -G8 by config, which turns the absolute lui/lw loads of D_001B22A8 into
   $gp accesses. The gp store `sw $v0,0x32B8($gp)` in the jal delay slot does match. */
#include "include_asm.h"

extern char *D_001B22A8 __attribute__((sda));
extern void func_00282B50(void *target);

void func_002FC468(unsigned int a0, unsigned int unused, unsigned int count)
{
    unsigned int bytes = count << 4;
    *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 0) = 0x10000000u | count;
    *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 4) = 0;
    *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 8) = 0x01000404u;
    *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 12) = a0 | (count << 16) | 0x6C000000u;
    {
        char *next = *(char * volatile *)&D_001B22A8 + 16;
        D_001B22A8 = next;
        func_00282B50(next);
    }
    *(char * volatile *)&D_001B22A8 = *(char * volatile *)&D_001B22A8 + bytes;
}
