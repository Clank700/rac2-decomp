/* 0 of 1 places match - candidate is 668 bytes = retail, 167 instructions, and every one of
   them is identical but for ONE register swap: retail keeps `self` in $s5 and `state` in $s4
   (prologue `sd $s5,0x28($sp)` first, `daddu $s5,$a0,$zero`, `lw $s4,0x68($s5)`), this cc1
   gives `self` $s4 and `state` $s5. File: src/levels/02_maktar_nebula/L02_002ED7B0-g8.c
   (-O2 -G8 -ffunction-sections), after func_L02_003D18D8; checked at commit base 406e81e
   with the #238 flow-fix cc1 (unchanged by it).
   Cause, measured with `-dg` (global.c orders allocnos by floor_log2(refs)*refs/live_length):
     pseudo 84 (self)   refs 18, live length 100 -> 4*18/100 = 0.720
     pseudo 85 (state)  refs 21, live length 121 -> 4*21/121 = 0.694
   self is allocated first and takes the lower s-register; retail needs state first (state at
   22 refs would be 0.727, self at 17 refs 0.680, or self's range 4 insns longer). Every other
   pseudo already lands in retail's register ($s0..$s3, $s6, $s7).
   Layout facts that were needed to get here (all in the source below): the walk is the
   rolled `b TEST; BODY; INCR; TEST` form via the guarded `for` condition (inner `p != 0`
   guard); `u8 *other` (a `char *` makes `!= 0xFE` constant-true); nested ifs for the
   0xFE/0xFD and 0/1 tests (`!= a && != b` is range-merged by fold-const); `os` loaded once
   before the tests; the fail block's stores written 2E0 then 2F6.
   Tried without moving the swap: all 1440 orderings of the six success-block stores (x os
   load first / at the first os store). The one thing that DID flip the priorities: `int g`
   for the group byte read once in the loop test, `(g = *(u8 *)(self + 0x21)) != 0xFF && g <=
   count ...` (self loses a ref), but then gcse PRE hoists the loop-test lbu into the INCR
   block and 24 diff lines remain (kept in build only). Next idea: a
   spelling that gives `state` one more pre-allocation reference (or `self` one fewer)
   without moving a load: look for a state/self use that survives to local-alloc but not to
   the final code. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C;
extern int D_L02_001B35B8 __attribute__((sda));

extern int func_002B3BA8(char *, int, float, float, int, int);
extern int func_L02_003FC0D0(int, short);
extern float func_00282E80(void *, u8 *);

void func_L02_003D1998(char *self) {
    char *state = *(char **)(self + 0x68);
    u8 *other;
    u16 *p;
    u8 *e;
    u8 *best;
    float min;

    if (*(u8 *)(self + 0x20) < 4) {
        *(int *)(state + 0x2E0) = 0;
        goto done;
    }
    if (*(short *)(state + 0x2F6) == 1) {
        *(short *)(state + 0x2FA) =
            func_002B3BA8(self, *(int *)(state + 0x2F0), 100.0f, 100.0f, 0, 0);
        *(int *)(state + 0x2E0) = *(int *)(state + 0x200);
    } else if (func_L02_003FC0D0(*(int *)(self + 0xB8), *(short *)(self + 0xAA)) != 0) {
        *(short *)(state + 0x2F6) = 1;
        *(short *)(state + 0x2FA) =
            func_002B3BA8(self, *(int *)(state + 0x2F0), 100.0f, 100.0f, 0, 0);
        *(int *)(state + 0x2E0) = *(int *)(state + 0x200);
    } else if (*(short *)(state + 0x2F6) == 2 && *(char **)(state + 0x2E0) != 0) {
        char *os;

        other = *(u8 **)(state + 0x2E0);
        os = *(char **)(other + 0x68);
        if (other[0x20] != 0xFE) {
            if (other[0x20] != 0xFD) {
                if (other[0x95] != 0) {
                    if (other[0x95] != 1 && *(short *)(os + 0x2F6) == 2 &&
                        *(char **)(os + 0x2E0) == self) {
                        *(short *)(state + 0x2FA) = 2;
                        *(short *)(os + 0x2FA) = 2;
                        return;
                    }
                }
            }
        }
        *(int *)(state + 0x2E0) = 0;
        *(short *)(state + 0x2F6) = 0;
    } else {
        min = 1000.0f;
        best = 0;
        for (p = D_L02_001FC060[*(u8 *)(self + 0x21)];
             *(u8 *)(self + 0x21) != 0xFF && *(u8 *)(self + 0x21) <= D_L02_001B35B8 && p != 0 &&
             ((p != 0 && (s16)p[-1] >= 0) || p == D_L02_001FC060[*(u8 *)(self + 0x21)]);
             p++) {
            e = D_L02_001B359C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (e[0x20] != 0xFE) {
                if (e[0x20] != 0xFD && e != (u8 *)self && e[0x20] >= 3 && *(short *)(e + 0xAA) == 0x9CA &&
                    *(short *)(*(char **)(e + 0x68) + 0x2F6) == 0) {
                    if (func_00282E80(self + 0x10, e + 0x10) < min) {
                        best = e;
                        min = func_00282E80(self + 0x10, e + 0x10);
                    }
                }
            }
        }
        if (best == 0)
            goto done;
        *(u8 **)(state + 0x2E0) = best;
        *(short *)(state + 0x2F6) = 2;
        *(short *)(state + 0x2FA) = 2;
        {
            char *os = *(char **)(best + 0x68);

            *(short *)(os + 0x2F6) = 2;
            *(char **)(os + 0x2E0) = self;
            *(short *)(os + 0x2FA) = 2;
        }
    }
    return;
done:
    *(short *)(state + 0x2F6) = 0;
}
