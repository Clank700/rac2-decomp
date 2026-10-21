/* func_L02_003D4E00, 208 bytes, 1 placement (level 2, 02_maktar_nebula). NEAR MISS: 212 bytes against retail's
   208. Compiled as a unit of its own, built with `-O2 -G8 -ffunction-sections -frac2-qcopy` (G8: the anchor
   vector is `addiu $a1,$gp,0x11C0` and `addiu $v1,$gp,0x11C0`, outside any delay slot, so a `-g8.c` unit).

   The body is right; only the scheduling around the three 16-byte copies differs (about 25 words, all moves
   of independent instructions, plus one extra `daddu $a2,$a0,$zero`):
     - sched1 hoists the call's argument moves (`daddu $a1,$sp,$zero`, `daddu $a0,$s0,$zero`, the three
       `lui/mtc1` float constants and `mov.s $f15,$f14`) above the copies, where retail keeps all of them
       after the second copy; arg0 then has to leave $a0 (`daddu $a2,$a0,$zero`, 212 bytes);
     - the prologue saves are interleaved with that first group instead of coming first.
   Retail's copies are scheduling barriers. Measured (diagnostic only, not admissible in src/): replacing each of
   the three copies by `__asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(dst), "r"(src) : "$2", "memory")`
   (dst and src the same addresses as below) and compiling WITHOUT -frac2-qcopy gives retail's 208 bytes exactly
   (the placement derive says OK at the one place); `: "$2"` alone does too. The same copy written as a
   non-volatile asm with a memory output (an ordinary insn) schedules like -frac2-qcopy, so it is the barrier,
   not the grouping, that retail has. -frac2-qcopy keeps the copies ordinary insns ("no memory barrier is
   added"). The model needs both schedulers: with it, -fno-schedule-insns leaves 2 words off and
   -fno-schedule-insns2 18. What would unblock it: a sched_analyze_insn selector for the rac2_qcopy parallel with
   the same treatment zero_ti_store_barrier.py gives the clear (the dependences, cost 1 and no unit of a volatile
   asm).
   Tried, none closer: the local as `TI128 vec = *(TI128 *)(ptr + 0x10)` read through a float pointer (208
   bytes only by accident: that first copy is then a plain `lq $v0,0x10($v1)` and a later `sq`, not the grouped
   pair with the materialised `addiu $v1,$v1,0x10`, which saves the instruction the extra `daddu` costs); a float
   array local with the TI128 casts (the C below, the grouped copy as retail has it, 212 bytes); named pointers
   for the destination and the source of the second copy (the compiler gives the same code); -fno-schedule-insns
   (208 bytes, but sched2 then hoists the same argument moves to the top of the function, 28 words);
   -fno-schedule-insns2; both together (212 bytes, 8 words: no scheduling at all, so the load-delay `nop`
   and the save order differ). */

typedef int TI128 __attribute__((mode(TI)));

extern int D_L02_001B01B0 __attribute__((sda));

extern float func_00282E80(char *, void *);

/* (out, source vector, 13.0f, 45.0f, 0.2f, 0.2f): its own draft is nonmatching/levels/func_L02_003D5E40.c. */
extern void func_L02_003D5E40(char *, float *, float, float, float, float);

void func_L02_003D4E00(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    float vec[4];

    *(TI128 *)vec = *(TI128 *)(*(char **)(state + 0x30C) + 0x10);
    vec[2] += 1.0f;
    *(TI128 *)(state + 0x2C0) = *(TI128 *)(arg0 + 0x10);
    func_L02_003D5E40(state + 0x2C0, vec, 13.0f, 45.0f, 0.2f, 0.2f);
    if (func_00282E80(state + 0x2C0, &D_L02_001B01B0) > 10.0f) {
        *(TI128 *)(state + 0x2C0) = *(TI128 *)&D_L02_001B01B0;
        *(float *)(state + 0x2C8) += 1.0f;
    }
}
