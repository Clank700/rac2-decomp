/* 0 of 1 places match - candidate is 436 bytes = retail (109 instructions), word-for-word
   identical except the position of ONE load: retail emits `lwc1 $f0,0x3C($s2)` right after
   `sq $zero,0($sp)`, before `addiu $s0,$sp,0x10 ; daddu $a1,$sp,$zero ; daddu $a0,$s0,$zero`;
   this cc1 emits the three ALU instructions first and the load last, just before the jal
   (+0x40..+0x4C, 4 words). File: src/levels/02_maktar_nebula/L02_003DB310-g8.c (-O2 -G8
   -ffunction-sections), before func_L02_003F16A8; checked at commit base 406e81e with the
   #238 flow-fix cc1 (unchanged by it). Frame, registers, the loop, every branch and every
   $gp/absolute access match.
   Cause (-fsched-verbose-2 on x.i.sched2): the `sq` is a store on the r5900 memory unit
   (ready cost 2, mips.md: `(eq_attr "type" "store") ... 2 1`), and the load from
   [$s2+0x3C] is a true dependence on it ([$sp+0] vs an unknown loaded base: base_alias_check
   returns "may alias"), so sched2 queues the load 2 cycles ("insn 31 into queue with
   cost=2") and the three ALU insns take its place. In sched1 the load follows the sq at
   once (cost 1). Retail's sched2 kept the load second.
   This is systematic in retail: the same head -- `sq $zero,0($sp)`, `lwc1` of a state
   field (or a $gp float), the call-argument ALU insns, `jal`, `swc1 $f0,N($sp)` in the
   delay slot -- is in func_L00_003BFF68 (shared across levels), func_L04_00419918,
   func_L17_003BCC30, func_L17_003BCEC0 (twice), func_L17_003C45A0, func_L02_003EA4E0 and
   func_L13_0040A3B0 (found with a scan for `sq $zero,N($sp)` followed by an lwc1), so the
   right spelling of the idiom unlocks several functions.
   Tried (all give this same 4-word difference unless noted): `float a[4]` + `*(TI128 *)a
   = 0; a[2] = *(float *)(state + 0x3C)` (this file); the load as a struct member read
   (`((StT *)state)->f3C`); a const-qualified read; a pointer variable for `a`; a `struct
   { float x, y, z, w; } a` with `.z`; `TI128 a[1], b[3], c[4], d[1], f[1]` locals as the
   matched game code uses; the load written first into a local (order becomes lwc1,
   addiu, sq: wrong); a scalar `TI128 a` local (the slot moves to sp+0x90, because addressof'd scalars
   are given their slot last, and the layout breaks); `float a[4] = {0,0,0,0}` and a
   16-byte-aligned struct initialiser (memset call or sw stores: 444-476 bytes, no sq); and,
   as a diagnostic only, reading the float from self+0x3C (alias analysis then separates
   the two and the load goes BEFORE the sq: also wrong). The order is a pure sched2
   decision: with the sq -> load arc at cost 1 the load (longer critical path than the ALU
   insns) would take the second slot, exactly as retail has it.
   Compiler-side hypothesis (not measured): mips.md's movti_internal has no store
   alternative that takes a constant (stores are `R,d` / `m,d`; J only on the register
   destinations), so reload materialises the zero in $v0 and rac2_fold_zero_ti_store turns
   the store back into `sq $zero`; sched1 sees the pre-reload store at cost 1 and sched2 the
   folded one as a `store` (ready cost 2). If this is a compiler lever rather than a
   source spelling, the family above is the witness set for it. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int TI128 __attribute__((mode(TI)));

extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C_1[] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));

extern void func_002833F0(float *, float *);
extern void func_00283698(float *, float *);
extern void func_00282CF0(float *, float *, float *);
extern void func_00283098(float *, float *, float *);
extern float func_00282C48(float);

int func_L02_003EAE10(char *self) {
    char *state = *(char **)(self + 0x68);
    float a[4];
    float b[12];
    float c[16];
    float d[4];
    float f[4];
    float limit;
    u16 *p;
    u8 *e;

    if (*(u8 *)(self + 0x21) == 0xFF)
        return 1;
    *(TI128 *)a = 0;
    a[2] = *(float *)(state + 0x3C);
    func_002833F0(b, a);
    func_00283698(c, b);
    func_00282CF0(d, (float *)(state + 0x30), (float *)(self + 0x10));
    func_00283098(d, d, c);
    limit = func_00282C48(d[1]);
    for (p = D_L02_001FC060[*(u8 *)(self + 0x21)];
         *(u8 *)(self + 0x21) != 0xFF && *(u8 *)(self + 0x21) <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L02_001FC060[*(u8 *)(self + 0x21)]);
         p++) {
        e = D_L02_001B359C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e != (u8 *)self && *(short *)(e + 0xAA) == 0xAB0 && e[0x20] == 3) {
            func_00282CF0(f, (float *)(*(char **)(e + 0x68) + 0x30), (float *)(e + 0x10));
            func_00283098(f, f, c);
            if (limit < func_00282C48(f[1]))
                return 0;
        }
    }
    return 1;
}
