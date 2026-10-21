#include "include_asm.h"

typedef unsigned int u32;
typedef int TI128 __attribute__((mode(TI)));

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 32 bytes; 28-byte candidate; 0/1.
    (Replaces an earlier draft from commit adcbd51, which used the inline-assembly `qcopy`
    helper that AGENTS.md's "Plain C" rule forbids; that draft is in that commit.)
    The only difference left is the 128-bit copy: retail materialises the destination
    pointer first (`addiu $v1,$a0,0x10; lq $v0,0($a1); sq $v0,0($v1)`) while this cc1 folds
    the constant offset into the store (`sq $v0,0x10($a0)`).  Measured again in this wave with
    about twenty further spellings, all of which fold the offset: a TI128 pointer variable, an
    array index, a struct member, a union, `volatile`, `aligned(1)`/`aligned(4)` TI types, an
    integer cast (signed and unsigned), a `short` truncation (which does keep the address in a
    register, but adds `sll`/`sra` and costs three instructions), a `unsigned long long` address
    (which keeps the address in a register, but adds `daddu` plus `dsll`/`dsra`), a pointer
    loaded from memory, a pointer used twice, two C names for the same pointer, and a pointer
    kept across a call.      The rule that holds: this cc1 folds a constant offset into the
    `lq`/`sq` whenever the address is a `plus` of a register; the address only stays in a
    register when it comes from something that is not a `plus` (a load, a call result) or when a
    mode conversion forces it (which then costs extra instructions).
    Same wall as the other TI copies in this level.

    Wave 20 (this worker) measured the same wall once more and adds what the retail does
    with the same shape: the retail folds the constant offset into the `lq`/`sq` in
    func_L08_003391C0 (`lq $v1,0x10($a0)`, matched), in func_L20_0043F510
    (`lq $v0,0x10($s0)`, matched) and in func_L20_00302D50 (all six accesses folded), and it
    materialises it in this function (`addiu $v1,$a0,0x10; lq $v0,0($a1); sq $v0,0($v1)`),
    in func_L20_0039E158, in func_L20_0039DCF8 (both stores) and in func_L20_004395B0 (both
    loads and one store).  So the retail has both behaviours and this cc1 only has the
    folding one; about thirty spellings were measured, in this function and in the other TI
    copies of this level, and all of them fold: a TI128 pointer variable (one and two of
    them), a struct member, an array index, a union, `volatile`, `aligned(1)`/`aligned(4)`
    TI types, an integer cast (signed and unsigned), a `short` truncation (which does keep
    the address in a register, but adds `sll`/`sra` and costs three instructions), a 64-bit
    address (which keeps the address in a register, but adds `daddu` plus `dsll`/`dsra`), a
    pointer loaded from memory, a pointer used twice, two C names for the same pointer, a
    pointer kept across a call and a `__builtin_memcpy` of 16 bytes (which comes out as
    `ldl`/`ldr`/`sdl`/`sdr`).
    The per-file flags do not help: `-g`, `-mno-split-addresses`, `-fno-schedule-insns` and
    `-fno-schedule-insns2` leave the fold exactly as it is.

    Wave 21 (this worker) measured the wall once more and adds three things the next
    worker can use:

    1. THE ASSEMBLER TURNS `addu rd,rs,imm` INTO `addiu rd,rs,imm`.  cc1 emits the
       materialised 128-bit address as a 64-bit `addu rd,rs,imm`, and the game's assembler
       (gas, tc-mips.c) rewrites it into the 32-bit `addiu` when the immediate fits in 16
       bits - so the retail's `addiu $v1,$a0,0x10` and this cc1's `addu $v1,$a0,16` are the
       same four bytes.  The same holds for `move rd,rs`, which becomes `daddu rd,rs,$zero`.
       Two consequences: (a) a 32-bit `addiu` in the retail is NOT evidence that the source
       did 32-bit arithmetic, and (b) a candidate that differs from the retail only in
       `addu`/`addiu` and `move`/`daddu` is NOT a difference - compare the objects, not
       the .s text (tools/check.py does; the listings do not).
    2. THE OUT-OF-RANGE OFFSET ESCAPE REALLY MATERIALISES THE ADDRESS, in the retail's
       instruction form.  `*(TI128 *)((char *)arg0 + 32753) = v;` compiles to
       `addu $v0,$v0,32753` -> `addiu $v0,$v0,0x7FF1` and `sq $v3,0($v0)`: the address stays
       in a register and the `sq` gets a ZERO displacement, exactly the retail's shape,
       because the TImode displacement range is [-32768, 32752] (measured: 0x7FF0 still
       folds, 0x7FF1 does not).  The immediate is wrong (0x7FF1 instead of the retail's
       0x10), and no bias of the base can fix it: the immediate in the instruction IS the
       offset the compiler used.  So the escape cannot land a body whose retail offset is
       inside the range, but it proves that the reload pass is what materialises the
       address - the retail's shape cannot come from the reload with an in-range offset,
       so it comes from the game's inline-assembly `qcopy` macro, whose operand must live
       in a register.
    3. The `volatile`-pointer escape (a `volatile` pointer OBJECT) reaches the zero
       displacement too, but it costs the stack round trip: `subu $sp,$sp,16 ; addu
       $v1,$a0,16 ; sw $v1,0($sp) ; lq $v0,0($a1) ; lw $v1,0($sp) ; sq $v0,0($v1)` - four
       instructions and sixteen bytes more than the retail's single `addiu`, so it can only
       land a body that is several bytes short. */
void func_L20_0039F210(char *arg0, char *arg1, int arg2) {
    char *dst = arg0 + 0x10;
    char *state;

    *(TI128 *)dst = *(TI128 *)arg1;
    state = *(char **)(arg0 + 0x68);
    *(int *)state = 5;
    *(int *)(state + 0xC) = arg2;
}

/* ---- level-20 wave 4, worker 05 (2026-10-20): the copy wall measured once more ----
 *
 * The state stores and the frame are the retail's; the copy is the only difference:
 * the retail materialises the destination pointer (`addiu $v1,$a0,0x10 ; lq $v0,0($a1)
 * ; sq $v0,0($v1)`) and this cc1 folds the offset into the store (`sq $v0,0x10($a0)`).
 *
 * This wave added these spellings to the list above (all of them fold): the
 * destination in a `char *`, a `TI128 *`, a `void *` and an `u8 *` variable, the
 * destination computed by `+=`, the destination copied through a second variable, the
 * destination assigned in one branch and in the other (the "different values in two
 * branches" escape: it keeps the address in a register but costs a second `addiu` and
 * a `movn`), a `do {...} while (0)` around the copy (the loop is removed again and the
 * fold comes back), a `for` loop that carries the pointer (it keeps the address in a
 * register - `addu $4,$4,16 ; ... ; sq $2,0($4)` - but the loop costs 32 bytes over),
 * a `volatile` store, a `volatile` pointer object, a 16-byte struct assignment
 * (ldl/ldr/sdl/sdr), a struct with a TI128 member (the same lq/sq, still folded), and
 * the per-file flags `-O1`, `-O3`, `-G8`, `-fno-expensive-optimizations`, `-fno-gcse`,
 * `-fno-strength-reduce`, `-mno-split-addresses`, `-fno-schedule-insns` and
 * `-fno-schedule-insns2` (none of them changes the shape).
 *
 * Two things this wave measured that the next worker can use:
 *
 *  1. THE RELOAD IS WHAT MATERIALISES THE ADDRESS.  With the pointer in a variable the
 *     front end builds the MEM's address as a pseudo (cc1 -da shows
 *     `(set (mem:TI (reg/v:SI 87) 0) ...)`) and the CSE's find_best_addr() replaces the
 *     pseudo by the `plus` (the .cse dump shows
 *     `(set (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0) ...)`); the reload then
 *     prints the constant as the displacement.  The retail's shape is the one the reload
 *     prints when the address is still the pseudo, and the pseudo's value is then
 *     computed by an `addiu` of its own.
 *
 *  2. THE CSE'S TIE IS A COIN FLIP.  find_best_addr() substitutes the `plus` only when
 *     the class member it finds is not more expensive than the class head; the class
 *     holds the pseudo and the `plus`, and which of the two the hash lookup returns
 *     decides whether the substitution happens at all.  That is why the same expression
 *     folds in one function and not in another, and it is why a spelling that changes
 *     the class (an extra use of the pointer, a second name for it, a different order of
 *     the statements) can flip it.  Measured: in func_L20_0039E158 the copy's two
 *     addresses both fold, and adding a third use of one of them does not change that.
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through $gp. */

/* ---- level-20 wave 5, worker 05 (2026-10-21): the copy wall, measured from the
 * compiler's own source ----
 *
 * The wall is not a spelling problem: it is the CSE.  With the tree under
 * build/downloads/gnu-ee-binutils-gcc-1.1.tar.gz unpacked and
 * tools/compiler/patches/ applied, the mechanism is in gcc/cse.c's
 * find_best_addr() and in gcc/config/mips/mips.h:
 *
 *  1. The front end builds the address of a 128-bit access as the pointer's
 *     pseudo: `(set (mem:TI (reg/v:SI 86) 0) (reg:TI 88))` (cc1 -da, the .rtl
 *     dump), and the pseudo's value is
 *     `(set (reg/v:SI 86) (plus:SI (reg/v:SI 84) (const_int 16)))`.
 *  2. The CSE puts the pseudo and the plus in ONE equivalence class (the
 *     class is kept sorted by COST(): a pseudo costs 1, a hard register 2 and
 *     a non-register notreg_cost() = rtx_cost()*2, so the plus costs 10).
 *  3. find_best_addr() replaces the address with the class member that has
 *     the highest rtx cost among the members whose CSE_ADDRESS_COST equals
 *     the address's own.  ADDRESS_COST(REG) is 1 and
 *     mips_address_cost(plus(reg,small const)) is also 1 (SMALL_INT is the
 *     whole 16-bit range on MIPS), so the plus wins on the rtx cost and the
 *     offset is folded into the instruction.
 *  4. The reload then prints the offset as the displacement, because
 *     GO_IF_LEGITIMATE_ADDRESS accepts plus(reg,const_int) for TImode while
 *     the offset is in [-32768, 32752].
 *
 * So the address stays in a register exactly when the plus is NOT in the
 * class of the address pseudo, that is when the pointer's value is not a
 * plus of a register.  Everything else follows from that, and it is what
 * this wave measured:
 *
 *  * a SYMBOL base: `*(TI128 *)(SYM + 0x10)` gives
 *    `lui $2,%hi(SYM+16); addiu $2,$2,%lo(SYM+16); sq $3,0($2)` - the address
 *    IS materialised, because mips_address_cost(plus(symbol,16)) is 3 and not
 *    1 and because GO_IF_LEGITIMATE_ADDRESS rejects a constant address for
 *    TImode on the R5900 (`! (TARGET_MIPS5900 && mode == TImode)`);
 *  * a pointer LOADED FROM MEMORY: `TI128 *d = *(TI128 **)(arg0 + 0x68);`
 *    gives `lw $3,0($a0); lq $2,0($a1); sq $2,0($3)` - the load's value is
 *    not a plus, so it is not in the class;
 *  * a CALL RESULT: `TI128 *d = getp();` gives the same shape;
 *  * a pointer CARRIED BY A LOOP: `for (i=0;i<2;i++) *d = v;` gives
 *    `addu $4,$4,16; lq $2,0($a1); sq $2,0($4)` - the address stays in a
 *    register, but the loop costs 32 bytes over the retail.
 *
 * This wave also measured, and all of them FOLD (the offset goes into the
 * instruction): a pointer variable of type char *, TI128 *, void *, u8 * and
 * long long *; the pointer assigned with `=`, with `+=` and copied through a
 * second variable; two C names for one pointer; the pointer used twice, three
 * times and kept across a call; the pointer assigned in one branch and in the
 * other; the pointer defined in one basic block and used in another (the
 * CSE's jump equivalence carries the value across); a `do {} while (0)`; a
 * 16-byte struct assignment (ldl/ldr/sdl/sdr) and a 16-byte aligned struct
 * assignment (ld/sd); a struct with a TI128 member; a union; `volatile` on
 * the store, on the pointee and on the pointer object (the pointer object
 * costs a stack round trip: `subu $sp,$sp,16; addu $v1,$a0,16; sw $v1,0($sp);
 * lq $v0,0($a1); lw $v1,0($sp); sq $v0,0($v1)`); an integer cast (signed and
 * unsigned); a `long long` address (daddu plus dsll/dsra); a stack buffer
 * addressed as `buf + 0x20` (with the buffer in a variable and with the
 * variable's address taken, and with the pointer passed to a call as well -
 * the call's argument setup materialises the address in its own register and
 * the store still folds: `addu $4,$sp,16; lq $2,0($a1); sq $2,16($sp)`); and
 * the per-file flags -O1, -O3, -G8, -fno-expensive-optimizations, -fno-gcse,
 * -fno-strength-reduce, -fforce-addr, -fforce-mem, -mno-split-addresses,
 * -fno-schedule-insns and -fno-schedule-insns2 (none of them changes the
 * shape).  This compiler has no -fno-cse.
 *
 * The conclusion is that the retail's shape here is the game's own inline
 * assembly copy macro (its operand has to live in a register) and that src/,
 * which forbids inline assembly, cannot spell it.  The compiler-side way out
 * would be to make find_best_addr() keep the pseudo for a TImode address -
 * a change in tools/compiler/, not in the source.
 *
 * The rest of this body IS reachable: the frame is empty, the state pointer
 * is `*(char **)(arg0 + 0x68)`, the two stores are `*(int *)(state + 0xC) =
 * arg2` and `*(int *)state = 5`, and the only difference left is the copy.
 * The retail puts the state pointer in $a1 and the constant 5 in $v0; a
 * candidate that writes the two stores in the order
 * `*(int *)(state + 0xC) = arg2;` then `*(int *)state = 5;` gets the state
 * pointer into $a1 but the constant into $v1 instead of $v0, and the
 * opposite order gets the constant into $a1 and the pointer into $v1.
 *
 * This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
