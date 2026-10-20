/* 0 of 1 places match - candidate is 552 bytes, retail 556. File:
   src/levels/02_maktar_nebula/L02_003D26B0-g8.c (-O2 -G8 -ffunction-sections), placed before
   func_L02_003D69F0 (the marker sat in L02_003D26B0.c). Checked at commit base 406e81e with
   the #238 flow-fix cc1 (unchanged by it).
   The walk (rolled `b TEST; BODY; INCR; TEST`, guarded `for` exit test, $gp bound and the
   four $gp floats), the call sequence and all the float constants are word-for-word retail
   apart from three places, and all three come from ONE thing: retail holds a second copy
   of `e + 0x10` ($s5) that this cc1 never creates.
     +0x00  addiu $sp,$sp,-0x60 | retail -0x70 (one more saved register: $s5 = the copy,
            $s6 = state, $s7 = table hi; ours $s5 = state, $s6 = table hi)
     +0xA8  ours  bc1fl ->p++ with `addiu $s2,$s2,2` in the slot
            retail bc1f  ->p++ with `daddu $s5,$s4,$zero` in the slot (the copy, hoisted
            into the slot by dbr from the end of the block)
     +0xFC  ours  daddu $a0,$sp,$zero ; daddu $a2,$s4,$zero   (3rd arg of func_00282CF0)
            retail daddu $a2,$s5,$zero ; daddu $a0,$sp,$zero   (reads the copy)
   Retail keeps `$s4 = e + 0x10` for the first distance call AND for the last call
   (`func_00282CC0(local, local, e + 0x10)`: `daddu $a2,$s4,$zero`), and only the middle
   call (`func_00282CF0(local, self + 0x10, e + 0x10)`) reads `$s5`. In gcse terms the
   middle occurrence was NOT merged by cse1 and is a fully redundant PRE occurrence:
   "PRE: redundant insn N (expression E) ... PRE/HOIST: end of bb B, copying expression E
   to reg R" puts `R = epos` after the first addiu. Here cse1 merges all three occurrences
   (no label between them on the fall-through path; the ternary join label is skipped by
   cse's skip_blocks "AROUND" path), so PRE finds nothing; the only PRE in this function
   is the table-address `high` (the `$s7` copy at +0x5C), which matches.
   Tried (all 552 bytes unless noted): epos/spos as locals (this file); plain `e + 0x10`
   everywhere (50 diff lines); epos for the first and third use only; epos for the first
   and second; `tpos = epos` copy for the second use; epos/spos computed before the
   func_L02_003D7300 call (548 bytes, different shape); the success block placed after
   the loop behind a goto (layout changes); a second `||` condition or a live if/else
   diamond before the success block to put a label in front of it (564 / 572 bytes: it
   changes the code, not the PRE); plain `for` with the guarded condition instead of the
   `for(;;)` + `goto test` spelling (same bytes). Next idea: find what keeps the second
   `e + 0x10` out of cse1's equivalence class in the original (a different base pseudo, or
   an expression cse cannot see as `e + 16`), then check that gcse prints the PRE copy. */

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
