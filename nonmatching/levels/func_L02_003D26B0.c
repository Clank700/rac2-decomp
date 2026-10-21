/* 0 of 1 places match - candidate is 552 bytes, retail 556. File:
   src/levels/02_maktar_nebula/L02_003D26B0-g8.c (-O2 -G8 -ffunction-sections), placed before
   func_L02_003D69F0 (the marker sits in L02_003D26B0.c). Rechecked on 21 October 2026 with the
   #238 flow-fix cc1: unchanged.
   What differs: retail holds a second copy of `e + 0x10`. $s4 = e + 0x10 is computed before
   the first distance call and read by calls 1 (func_00282E80) and 3 (func_00282CC0);
   `daddu $s5,$s4,$zero` sits in the delay slot of the distance test's `bc1f` (+0xAC) and only
   call 2 (func_00282CF0) reads $s5. Here every use reads one register, so the frame is 0x60
   against 0x70 (one saved register fewer), the `bc1f` at +0xA8 becomes a `bc1fl` with `p++`
   in its slot, and call 2 reads $s4.
   The mechanism, measured (Opus retry, 21 October 2026): the copy is gcse's PRE.
   - If cse1 has not merged call 2's `e + 0x10`, PRE finds it fully redundant and inserts
     `R = e + 0x10` at the END of the distance block ("PRE/HOIST: end of bb 7"), which is
     exactly where retail's copy is; cse2 then turns it into `R = $s4`, i.e. retail's `daddu`.
   - cse1 merges call 2's `e + 0x10` whenever no CODE_LABEL lies between the two uses, and
     cse2 re-merges the copy unless a label still lies between it and call 2 (make_regs_eqv
     keeps $s4 canonical: it lives longer than the copy, so call 2 would read $s4 again).
   - Witness: adding `|| *(int *)(state + 0x2F0) == 7 || *(int *)(state + 0x2F4) == 9` to the
     DISTANCE test (a label with two jump uses at the start of the angle block) gives retail's
     registers exactly: e + 0x10 in one register for calls 1 and 3, the copy in the `bc1f` slot
     at +0xAC, call 2 reading the copy, DEG2RAD kept in $f21 (584 bytes only because of the two
     extra tests). The same two tests on the ANGLE test put the label at the start of the
     success block: the copy appears too, but DEG2RAD is then loaded twice where retail loads it
     once, so retail's break is at the start of the angle block. With one extra `||` only,
     cse's skip-blocks AROUND path follows the label and merges again (no copy).
   - So retail's source has, between the distance test and the angle computation, something
     that is a control-flow join for cse1 and cse2 and leaves no instruction. Not found. Tried
     (no copy unless noted): the walk as `for(;;)` + `goto test` or as the FOR_EACH_ID `for`;
     epos/spos locals in any combination for calls 1-3 (epos for 1 and 3 with `e + 0x10` for 2
     is what the PRE needs, this draft); nested ifs, `&&`, `if (!(...)) continue/goto`; the
     angle test as an int temp or a static inline helper, the distance test as a static inline
     helper (each materialises the boolean: 560-564 bytes); the rotate call duplicated in an
     if/else for the ternary (556 bytes, 127 lines: the join comes before call 3, so PRE copies
     for call 3 and cse2 then gives calls 2 AND 3 the copy). Flags, each alone, on this draft:
     -g, -gstabs, -fno-cse-follow-jumps, -fno-cse-skip-blocks (both), -fedge-lcm, -fno-gcse,
     -fno-rerun-cse-after-loop (also loses the PRE copy of the table's %hi in $s7, which needs
     cse2), -fno-expensive-optimizations, -fno-force-mem, -fno-regmove, -fno-schedule-insns{,2},
     -fno-thread-jumps, -fno-strength-reduce, -fno-rerun-loop-opt, -fno-caller-saves,
     -fno-peephole2, -fno-sched-interblock, -fno-sched-spec, -fno-strict-aliasing,
     -fno-defer-pop, -fforce-addr, -fno-function-cse, -fno-edge-sm, -fno-edge-lm,
     -mno-split-addresses: none gets nearer than 30 lines. A dead if/else at that spot would do
     it (flow deletes it after cse2), but that is a steering construct, not allowed in src/.
   - The idiom is shared: func_L02_003F1BA8 and func_L02_0040BBD8 are this function with other
     offsets, and func_L11_00436D08, func_L11_00449C70, func_L11_0044C850, func_L11_004530E0 and
     func_L11_004566C0 carry the same loop. Of the 8,606 catalogue functions, 16 keep two saved
     registers on one `addiu` address after a delay-slot copy and none of them has C yet
     (3,541 functions do), so this may be a difference of the reconstructed cse/gcse rather
     than a source shape. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C_1[] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern float D_L02_001B016C __attribute__((sda));
extern float D_L02_001B0170 __attribute__((sda));
extern float D_L02_001B0174 __attribute__((sda));

extern float func_00282E80(char *, void *);
extern void func_00282CF0(float *, float *, float *);
extern int func_L02_003D7300(u8 *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_002ACEC0(float *, float *, char *, float);
extern void func_00282CC0(float *, float *, u8 *);
extern void func_L01_00321178(char *, float *);

int func_L02_003D26B0(char *self) {
    char *state = *(char **)(self + 0x68);
    u16 *p;
    u8 *e;
    char *spos;
    u8 *epos;
    u8 *tpos;
    float local[4];
    float ang;

    if (*(int *)(state + 0x2EC) == -1)
        return 0;
    p = D_L02_001FC060[*(int *)(state + 0x2EC)];
    goto test;
    for (;;) {
        e = D_L02_001B359C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L02_003D7300(e) != 0) {
            epos = e + 0x10;
            spos = self + 0x10;
            if (func_00282E80(spos, epos) < D_L02_001B016C) {
                if (func_00283C80(*(float *)(self + 0xF8),
                                  func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),
                                                *(float *)(e + 0x14) - *(float *)(self + 0x14))) <
                    D_L02_001B0170 * 0.017453294f) {
                    float saved;

                    func_00282CF0(local, (float *)spos, (float *)(e + 0x10));
                    ang = D_L02_001B0174 * 0.017453294f;
                    func_002ACEC0(local, local, self + 0xE0,
                                  func_00283BE0(*(float *)(self + 0xF8),
                                                func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),
                                                              *(float *)(e + 0x14) - *(float *)(self + 0x14))) >= 0.0f
                                      ? -ang
                                      : ang);
                    func_00282CC0(local, local, epos);
                    saved = *(float *)(state + 0x134);
                    *(float *)(state + 0x134) = 0.0001f;
                    func_L01_00321178(self, local);
                    *(float *)(state + 0x134) = saved;
                    return 1;
                }
            }
        }
        p++;
test:
        if ((*(int *)(state + 0x2EC) & 0xFF) != 0xFF && *(int *)(state + 0x2EC) <= D_L02_001B35B8 && p != 0) {
            if ((s16)p[-1] >= 0)
                continue;
            if (p == D_L02_001FC060[*(int *)(state + 0x2EC)])
                continue;
        }
        break;
    }
    return 0;
}
