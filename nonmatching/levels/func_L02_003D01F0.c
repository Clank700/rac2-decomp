/* func_L02_003D01F0 (72 bytes, 1 place, 02:003D01F0) - near miss, measured 21 October 2026.

   The twin of func_L02_003CADA8 (state 4, offset 0xB0), with the same result: plain C below,
   in a unit of its own (src/levels/02_maktar_nebula/L02_003D01F0.c, cflags line
   `-O2 -G0 -ffunction-sections -frac2-qcopy`), is 72 bytes against retail's 72, 0 of 1 places.
   Everything is retail's except four words at +0x2C..+0x3C: sched2 issues the independent
   `ld $ra,0x10($sp)` (an unchanging stack-slot load, no dependence on the copy's store) in the
   cycle after the call, next to `addiu $s0,$s0,0xB0`, before the qcopy insn, which waits for
   that add. Retail's copy behaves as a scheduling barrier (the restores follow it in s0, s1, ra
   order); see func_L02_003CADA8's record for the dump reading and the asm-volatile diagnosis.
   What would unblock it: the opt-in barrier variant of -frac2-qcopy discussed on #248.

   The earlier record used the asm `qcopy` helper; this version is plain C. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(char *, int, int);

/* Sets the object's state to 4, then copies the 16-byte vector at A1 into its state at +0xB0. */
void func_L02_003D01F0(char *arg0, char *arg1) {
    char *state = *(char **)(arg0 + 0x68);

    func_002A7750(arg0, 4, -1);
    *(TI128 *)(state + 0xB0) = *(TI128 *)arg1;
}
