#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

/* 128-bit copies reach lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_002B3BA8(char *, int, float, float, int, int);

extern char *func_L20_004448A8(char *, char *);

/* Near miss from src/levels/20_yeedil/L20_0039C448.c: 140 bytes; 132-byte candidate; 0/1.
    (Replaces an earlier draft from commit adcbd51, which used the inline-assembly `qcopy`
    helper that AGENTS.md's "Plain C" rule forbids; that draft is in that commit.)
    Everything is the retail's: the frame (0x20), the two calls with their argument
    registers (the float pair in $f12/$f13 comes before the last int argument, so the
    `mov.s $f13,$f12` sits before the `jal` and the `daddu $a3,$zero,$zero` in its delay
    slot), the `bnez` with the store of the pointer in its delay slot, the reload of
    +0x280 after the two stores and the store of it at +0x200.
    The only difference left is the 128-bit copy: the retail materialises both addresses
    (`addiu $a1,$s0,0x1F0; addiu $a0,$v1,0x10; lq $v0,0($a0); sq $v0,0($a1)`) while this
    cc1 folds each constant offset into the `lq`/`sq` (`lq $v0,0x10($v1)`,
    `sq $v0,0x1F0($s0)`).  That is two instructions, the eight bytes of difference.
    Measured in this wave with about thirty spellings, all of them fold: a TI128 pointer
    variable (one and two of them), a struct member, an array index, a `volatile` load,
    two C names for the same pointer, a pointer used twice and a pointer kept across a
    call, an integer cast (signed and unsigned) and a 64-bit address (which keeps the
    address in a register but costs `daddu` plus `dsll`/`dsra`).
    The rule that holds: this cc1 folds a constant offset into the `lq`/`sq` whenever the
    address is a `plus` of a register; the address only stays in a register when it comes
    from something that is not a `plus` (a load, a call result) or when a mode conversion
    forces it (which then costs extra instructions).  The retail does both: it folds the
    offset in func_L08_003391C0 (`lq $v1,0x10($a0)`) and in func_L20_0043F510
    (`lq $v0,0x10($s0)`), and it materialises it here and in func_L20_0039F210,
    func_L20_0039DCF8 and func_L20_004395B0.  Same wall as the other TI copies in this
    level. */
void func_L20_0039E158(char *arg0) {
    char *s1 = arg0;
    char *s0 = *(char **)(s1 + 0x68);
    char *v;
    int p;

    if (*(int *)(s0 + 0x27C) != 0) {
        *(int *)(s0 + 0x280) = 0;
        func_002B3BA8(arg0, *(int *)(s0 + 0x230), 0.0f, 0.0f, 0, 0);
    } else {
        v = func_L20_004448A8(*(char **)(s1 + 0xB8), s1);
        *(int *)(s0 + 0x280) = (int)v;
        if (v == 0) {
            *(int *)(s0 + 0x280) = *(int *)(s1 + 0xB8);
        }
        p = *(int *)(s0 + 0x280);
        *(int *)(s0 + 0x200) = p;
        *(TI128 *)(s0 + 0x1F0) = *(TI128 *)((char *)p + 0x10);
    }
}

/* ---- level-20 wave 4, worker 05 (2026-10-20): the copy wall measured once more ----
 *
 * Everything but the copy is the retail's, instruction for instruction: the frame
 * (0x20), the two saved registers, the branch on `*(s32 *)(state + 0x27C)`, the
 * `daddu $a2,$zero,$zero` in its delay slot, the float pair (`mtc1 $zero,$f12`,
 * `mov.s $f13,$f12`) before the call, the `daddu $a3,$zero,$zero` in the call's delay
 * slot, the `bnez` with the store of the pointer in its delay slot, the reload of
 * `*(s32 *)(s1 + 0xB8)` after the two stores and the store of it at +0x200.
 *
 * The copy: the retail materialises BOTH addresses
 *     addiu $a1,$s0,0x1F0 ; addiu $a0,$v1,0x10 ; lq $v0,0($a0) ; sq $v0,0($a1)
 * and this cc1 folds each constant offset back into the `lq`/`sq`
 *     lq $v0,0x10($v1) ; sq $v0,0x1F0($s0)
 * - two instructions, the eight bytes of difference.
 *
 * This wave added the following spellings to the list above (all of them fold):
 * a `char *`/`TI128 *`/`u8 *` destination variable, a source variable of the same three
 * types, the destination and the source each in their own variable, a `volatile` store
 * through a variable, a `volatile` pointer object, a pointer copied through a second
 * variable, a pointer computed by `+=`, a pointer assigned in one branch and in the
 * other (the "different values in two branches" escape: it does keep the address in a
 * register, but it costs a second `addiu` and a `movn`), a loop that carries the
 * pointer and increments it at the end of the body (it does keep the address in a
 * register - `addu $4,$4,16 ; ... ; sq $2,0($4)` - but the loop costs 36 bytes over),
 * a `do {...} while (0)` around the copy (the loop is removed again and the fold comes
 * back), the store before the call and after the call, and the per-file flags `-O1`,
 * `-O3`, `-G8`, `-fno-expensive-optimizations`, `-fno-gcse`, `-fno-strength-reduce`,
 * `-mno-split-addresses`, `-fno-schedule-insns` and `-fno-schedule-insns2` (none of
 * them changes the shape).
 *
 * The rule that holds, measured in the compiler source: the reload pass accepts
 * `plus(reg,const_int)` for TImode while the offset is in [-32768, 32752]
 * (GO_IF_LEGITIMATE_ADDRESS in config/mips/mips.h), so the address is folded into the
 * displacement; the CSE's find_best_addr() replaces the pseudo of a pointer variable by
 * the same `plus`, because ADDRESS_COST(REG) and mips_address_cost(plus(reg,small
 * const)) are both 1 and the rtx-cost tie-break goes to the plus.  The retail's shape
 * is the one the reload prints when the address is still the pseudo - and the only
 * escape that reaches it (an offset outside [-32768, 32752], or a base that is not a
 * register) carries the wrong immediate.
 *
 * This body belongs in the `-G8` unit?  No: it reaches no global through $gp. */

/* ---- level-20 wave 5, worker 05 (2026-10-21): the copy wall, from the compiler's
 * own source ----
 *
 * The wall and every escape measured are written down in the note on
 * func_L20_0039E770 in this directory: the CSE's find_best_addr() folds the
 * offset of a `plus` of a register into the lq/sq, and the address only
 * stays in a register when the pointer's value is not a plus of a register
 * (a symbol, a load, a call result, or a pointer carried by a loop).
 *
 * Two spellings measured this wave that the earlier notes do not list, and
 * both fold:
 *
 *  * the offset does not matter: 0x10, 0x80, 0x100, 0x1F0 and 0x230 all
 *    fold (mips_address_cost() counts a 16-bit offset as cheap on MIPS,
 *    SMALL_INT is the whole signed 16-bit range);
 *  * a stack buffer addressed as `buf + 0x20`, with the buffer in a
 *    variable, with the variable's address taken, with the pointer passed to
 *    a call, and with the same pointer passed to two calls: the address is
 *    hoisted into the argument register (`addu $4,$sp,16`) and the 128-bit
 *    store still folds (`sq $2,16($sp)`), also when the pointer is then kept
 *    in $s0.
 *
 * The two addresses of this body's copy are `state + 0x1F0` and `p + 0x10`,
 * both with a runtime base, so neither escape applies.
 *
 * This body belongs in the -G8 unit?  No: it reaches no global through $gp. */
