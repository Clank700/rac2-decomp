/* func_L02_003CADA8 (72 bytes, 1 place, 02:003CADA8) - near miss, measured 21 October 2026.

   Plain C below, in a unit of its own (src/levels/02_maktar_nebula/L02_003CADA8.c, cflags line
   `-O2 -G0 -ffunction-sections -frac2-qcopy`): 72 bytes against retail's 72, 0 of 1 places.
   The prologue, the call and `addiu $s0,$s0,0xF0` + `lq $v0,0($s1)` + `sq $v0,0($s0)` are
   retail's; the only difference is the order of four words at +0x2C..+0x3C: this cc1 emits
   `ld $ra,0x10($sp)` before the copy, retail emits it after `ld $s0` / `ld $s1`.

   Why (sched2, -fsched-verbose-5): the restore of $ra is a load from an unchanging stack slot,
   so alias.c gives it no dependence on the copy's store; after the call (cycle 6) the ready list
   of cycle 7 is the address add (prio 7) and that restore (prio 5), and both issue there; the
   qcopy insn depends on the add and only issues in cycle 8. Retail's copy behaves as a
   scheduling barrier: a scratch compile (diagnosis only, not admissible in src/) of the same
   body with the copy written as an `asm volatile` lq/sq gives retail's 18 words exactly. The
   tie-break after the copy (s0, s1, ra) also needs the ra restore to depend on the copy (an
   independent insn wins the class test against the two anti-dependent restores).
   Tried: -fno-schedule-insns2 (copy and restores right, but the prologue comes out
   unscheduled: 5 words off). No plain-C spelling moves the restore: it depends only on the
   call. What would unblock it: the opt-in barrier variant of -frac2-qcopy discussed on #248.

   The earlier record used the asm `qcopy` helper; this version is plain C. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(char *, int, int);

/* Sets the object's state to 7, then copies the 16-byte vector at A1 into its state at +0xF0. */
void func_L02_003CADA8(char *arg0, char *arg1) {
    char *state = *(char **)(arg0 + 0x68);

    func_002A7750(arg0, 7, -1);
    *(TI128 *)(state + 0xF0) = *(TI128 *)arg1;
}
