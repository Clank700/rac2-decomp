/* Near miss from src/levels/20_yeedil/L20_00449178.c: 200 bytes, retail 204.
   This unit has no $gp access, so the body belongs here (-G0), not in the
   -G8 sibling.

   Everything matches but one instruction: the retail writes the 128-bit zero
   of the stack buffer with a materialised register
       por $v0, $zero, $zero ; sq $v0, 0x20($sp)
   while this cc1's rac2_fold_zero_ti_store pass folds that store to
       sq $zero, 0x20($sp)
   (4 bytes short).  The pass folds whenever the zero register is dead after
   the store, and it is dead here.

   Measured this wave (2026-10-20): the frame (0x50), the two saved
   registers, the 0.3f materialisation, the two float calls, the 14-argument
   func_0032C700 call with its four stack words, the branch-likely test and
   the epilogue are all the retail instructions.  The union spelling (float
   f[4] / TI128 q) is what puts the float at sp+0x28 and keeps the buffer
   address out of a callee-saved register, as the retail has it.

   Spellings tried for the zero, all of which fold to sq $zero: `v.q = 0`,
   `v = 0`, `v = {0}`, `*(volatile TI128 *)&v = 0`, the same store through a
   pointer, and a struct with a TI128 member.  The por survives only when the
   zero feeds two stores (measured: two stores of the same zero keep
   `por $2,$0,$0` and two `sq $2`), and the retail has one store.  The same
   wall is recorded for func_L00_002A75D8, func_L00_003ACC88,
   func_L13_0040A2C8 and func_L04_00422D40.

   Measured further this wave (2026-10-20, worker 10 of the level 20 wave):
   the fold is not the only mechanism - the shape of the store itself is
   decided before the pass.  The RTL of the store is
       (set (mem/s:TI (plus:SI (reg:SI 1 at) (const_int 32)) 0) (const_int 0))
   (the RTL dump, cc1 -dall, file x.i.regmove), i.e. the source is a
   TImode CONSTANT zero, and the movti_internal pattern of
   gcc/config/mips/mips.md has no alternative for a constant zero but a
   register: the reload then gives it register 0 and the pattern prints
   `sq $0,32($sp)`.  With two uses of the same constant the reload has to
   keep it in one register and the pattern's "d" alternative prints
   `por $2,$0,$0` (por rd,$zero,rs) followed by the two `sq $2`.  So the
   register form needs the value to be in a register, and this cc1 only
   puts a TImode constant there when the value has two or more uses.
   Further spellings measured, all of them `sq $0`: the union as a local, in
   a global, in a struct, in an array, the store through a pointer, through
   a volatile pointer, `*(TI128 *)&v = 0`, a TI128 local (`TI128 z = 0;`),
   a union with a float array, a TI128 value returned by a call, and the
   same store with the union at a non-zero stack offset.  A function that
   RETURNS a TI128 does keep the por (`por $2,$0,$0`, the return value in
   $v0/$v1), which is the only way measured to get the materialised zero
   into a register with one use.

   The wall is therefore the same for every body of this shape, and no
   matched function in the repository has a `por` + `sq` zero store (checked
   over every level's retail assembly against the matched functions in
   src/). 
   ------------------------------------------------------------------
   The `por` wall, measured again this wave (2026-10-21, worker 10 of the
   level 20 wave 5), with the answer to "is there a source shape that puts
   a call or a label between the materialisation and the store?".

   THE ANSWER IS NO, and the reason is in the reload, not in the source.
   `rac2_fold_zero_ti_store` (tools/compiler/transformers/fold_zero_ti_store.py)
   folds the materialisation into the store when (a) the store's source is
   a register, (b) that register is not READ before it is rewritten, and
   (c) the materialisation is at most TWELVE instructions above the store
   in the SAME block (a call, a jump or a label between them stops the
   backward scan).  But the materialisation is not something the source
   can place: the RELOAD emits it, as its own insn, IMMEDIATELY before the
   store that consumes it.  The RTL dump after the reload shows the two
   insns side by side:

       (insn 36 17 30 (set (reg:TI 2 v0) (const_int 0)) 239 {movti_internal}
       (insn 30 36 19 (set (mem:TI (reg:SI 29 sp) 0) (reg:TI 2 v0)) 239 {movti_internal}

   (cc1 -da, file x.i.greg; x.i.dbr and x.i.sched2 show the same pair).
   So the materialisation and the store are always adjacent and always in
   the same block: no source shape can separate them.  The only way to get
   a materialisation that is NOT adjacent to the store is a SECOND use of
   the same zero constant - and then there are two stores (the second use
   costs one), which is one `sq` more than the retail has.

   What the fold needs to be defeated, and why it cannot be:
   * the forward scan (`rac2_reg_live_after_store_p`) walks the insns
     after the store; it stops at the first insn that WRITES the register
     number (`single_set` + `REGNO`), and it returns "live" only for an
     insn that READS it (`reg_referenced_p` on the pattern).  In these
     bodies the register is written before it is read (the retail reuses
     $v0/$v1 for other values: in func_L20_0044AB68 the constant 1 is
     materialised into $v0 at 0x0044ABB4 and only read at 0x0044ABD4), so
     the scan returns "dead" and the store is folded;
   * a later READ of the register would keep the `por`, but the register
     is a 128-bit one and the only thing that reads it is another 128-bit
     store, which is the two-store case again.

   Re-measured this wave, all of them `sq $zero` (one store, folded):
   a local TI128, a union, a struct member, an array element, a volatile
   pointer, a volatile store, a global, a static local, a store through a
   pointer, a store of a variable the compiler knows is zero, and the
   store of a zero whose address is `plus(reg, const)`.  The compiler
   flags make no difference either: -O1, -O2, -O3, -G0, -G8,
   -fno-schedule-insns and -fno-schedule-insns2 all fold the same way
   (measured on `*(TI128 *)p = 0;`).

   The ONE spelling that keeps a materialised zero with a SINGLE store is
   the wave-4 note's: the zero is the FUNCTION VALUE, so the fold's guard
   sees the function-value use and refuses to fold -
   `int f(TI128 *p) { *p = 0; return 0; }` gives `por $2,$0,$0 ; j $31 ;
   sq $2,0($4)`.  It needs the store to be the LAST thing before the
   return: with a call in between (`*p = 0; g(); return 0;`) the compiler
   re-materialises the zero for the return (`move $2,$0`) and the store
   goes back to `sq $zero`.  These three bodies are void and their store is
   at the top, so the trick cannot reach them.

   THE FIX, in the project's own pass: the fold must not fire when the
   store's displacement is not zero.  The wave-4 note measured that rule
   over the compiled code of the matched corpus: there the zero register
   is the source of a 128-bit store only when the displacement is zero
   (2554 of 2554), and of the 1768 single stores with a non-zero
   displacement 1330 keep their materialisation.  The retail itself has
   both forms (in level 20: 147 `sq $zero,0x0($x)` against 85
   `sq $zero,off($x)` with a non-zero displacement), so the rule is not
   absolute - but the fold as it stands fires on a non-zero displacement
   here, and the retail's shape for these three bodies is
   `por $v0,$zero,$zero ; sq $v0,0x20($sp)`, the materialised form.
   A pass that folds only on a zero displacement keeps the `por` of these
   three bodies and they then match.
   The register allocation follows: with the `por` present the constant 1
   of func_L20_0044AB68 lands in $v0 (as in the retail) instead of $v1 -
   measured by giving the body a second zero store, which keeps the
   `por` and puts the constant in $v0.

   For the record, the whole of func_L20_0044AB68 is the retail's body
   except that one instruction (and the register the constant 1 lands
   in): with the near-miss C of this file, `tools/check.py
   func_L20_0044AB68 --diff` prints "20_yeedil: 200 bytes, expected 204"
   and the diff is the `por` alone.
*/

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002E59F8(int);
extern void func_0032C700(void *a0, int a1, int a2, int a3, int a4, int a5,
                           int a6, int a7, float f12, float f13, int s1, int s2,
                           int s3, int s4);

void func_L20_0044AB68(char *arg0) {
    union {
        TI128 q;
        float f[4];
    } v;
    char *state;

    v.q = 0;
    v.f[2] = 0.3f;
    func_00283098(&v, &v, arg0 + 0xC0);
    func_00282CC0(&v, &v, arg0 + 0x10);
    func_0032C700(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 0.666f, 20.0f, 1, 0,
                  0, 0);
    state = *(char **)(arg0 + 0x68);
    if (*(int *)(state + 0x1B8) != -1) {
        func_002E59F8(*(int *)(state + 0x1B8));
        *(int *)(state + 0x1B8) = -1;
    }
}

   ------------------------------------------------------------------
   Third attempt (wave w21, worker 10): the same wall, measured again
   from the compiler side, with one addition.  The RTL of the store
   after reload is
       (insn:TI ... (set (mem:TI (reg:SI 4 a0) 0) (reg:TI 0 $0)))
   (cc1 -dR, file x.i.sched2), i.e. the source of the store is the ZERO
   REGISTER, not a pseudo: `rac2_fold_zero_ti_store` never fires on this
   body (its guard sees register 0 referenced by the next instruction,
   `daddu $s0,$a0,$zero`, so the register reads as live), and the
   `sq $zero` comes from `movti_internal`'s store alternative itself
   (gcc/config/mips/mips.md: alternative 4, `sq %1,%0`, with %1 the zero
   register).  The retail's `por $v0,$zero,$zero` + `sq $v0,0x20($sp)` is
   alternative 0 (`por %0,$0,%1`), which needs the source of the store to
   be a real register - and this cc1 only puts a TImode constant in a
   register when the constant has two or more uses.  Measured again: one
   store folds to `sq $0`; two stores of the same constant keep
   `por $2,$0,$0` and two `sq $2` (one store too many for this body).
   A `volatile` store, a `volatile` pointer, a TI128 local, a union, a
   struct member and a store through a pointer were re-measured: all
   `sq $0`.  The wall stands; the body needs a compiler change, not a
   different spelling.

   ------------------------------------------------------------------
   The `por` wall, measured again this wave (2026-10-20, worker 10 of
   the level 20 wave 4).  The retail's `por $v0,$zero,$zero` is a 128-bit
   zero materialised in the MMI register 2: cc1 prints that instruction
   `por $2,$0,$0` (the retail's listing prints the MMI register with the
   GPR names, so its `$v0` is the field 2, i.e. $f2).  Three measured
   facts:

   * THIS cc1 puts a TImode constant zero in a REGISTER only when the
     constant has TWO OR MORE uses.  With one use the reload assigns the
     value to register 0 - the RTL after reload is
     `(set (mem:TI ...) (reg:TI 0 $0))` (cc1 -dall, file x.i.sched2) -
     and emits no `por` at all: the store prints `sq $0`.  With two uses
     the reload picks register 2 and the body prints `por $2,$0,$0` plus
     one `sq $2` per use.  Measured: `*p = 0;` -> `sq $0,0($4)`;
     `*p = 0; *q = 0;` -> `por $2,$0,$0` + two `sq $2`.

   * The chain's `rac2_fold_zero_ti_store` deletes that materialisation
     again when the register is dead after the store.  Its guard scans
     FORWARD from the store and refuses to fold when a later instruction
     references the register - and the comparison is on the whole rtx, so
     the MODE matters: a later 32-bit use of the same register number
     does NOT keep the `por`, a later TImode use does.  Its backward
     scan looks for the materialisation in the same block, at most twelve
     instructions above the store; a call, a jump or a label between them
     stops the scan, so a store in another block than the materialisation
     keeps its `por` (that is the retail's shape in func_L20_00449178:
     the `por` sits in the delay slot of the `beqz` and the `sq` is in
     the block that branch goes to).

   * The ONE spelling that gets a materialised zero with a SINGLE store
     is the shared materialisation with the function value: with
     `int f(TI128 *p) { *p = 0; return 0; }` cc1 prints
     `por $2,$0,$0 ; j $31 ; sq $2,0($4)` - the `por` IS the return value
     (regno 2 is $v0), the store uses the same register, and the fold's
     guard sees the function-value use and refuses to fold.  It needs NO
     call between the store and the return: with one in between
     (`*p = 0; g(); return 0;`) the compiler re-materialises the zero for
     the return (`move $2,$0`) and the store goes back to `sq $0`.

   So the three bodies of this file keep their `por` only if the retail's
   source had a second use of the zero constant that costs no
   instruction of its own, or if the store sits in another block than the
   materialisation and the constant had two uses.  No spelling of that
   second use was found; the wall stands.
