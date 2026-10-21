/* Near miss from src/levels/20_yeedil/L20_00449178-g8.c: 172 bytes, retail 180.
   The attempt belongs in the -G8 unit (the body reaches three $gp-relative
   floats: D_L20_001B2410, D_L20_001B2414, D_L20_001B241C).

   Everything but the 128-bit copy is the retail instruction for instruction:
   the prologue, the three $gp loads, the two calls, the flag test, the
   branch offsets and the epilogue all match.  The copy is the wall: retail
   materialises the two addresses into registers
       addiu $a0, $s0, 0x10 ; addiu $v1, $s1, 0x180 ;
       lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
   while this cc1 folds the constant offsets into the lq/sq operands
       lq $v0, 0x180($s1) ; sq $v0, 0x10($s0)
   which is 8 bytes short.

   WHERE THE FOLD HAPPENS (measured in the compiler source, 2026-10-20).
   The address of a TI access is (mem:TI (plus:SI (reg:SI base) (const_int
   off)) 0).  Two passes can fold the constant into the lq/sq operand:
     (1) the reload pass.  GO_IF_LEGITIMATE_ADDRESS (config/mips/mips.h)
         accepts plus(reg, const_int) for TImode while
             INTVAL(const) >= -32768 && INTVAL(const) + 16 - 1 <= 32767,
         so strict_memory_address_p() (reload.c) finds the address legal,
         does not reload it into a register, and print_operand_address()
         (config/mips/mips.c) then prints the constant as the displacement.
     (2) the CSE.  With the pointer in a C variable the address is a
         register, and find_best_addr() (gcc/cse.c) replaces it by the
         equivalent plus, because mips_address_cost() gives "register plus a
         small constant" the cost 1 and a plain register the cost 4.
   The retail's own compiler is the same ee-gcc 2.9, so the difference is
   the source, not the flags.

   THE ONE MEASURED ESCAPE, and why it is not usable here.  An offset
   outside [-32768, 32752] is not a legal TImode displacement, so the
   reload pass materialises the address:
       *(TI128 *)(arg0 + 32753) = v;
   compiles to
       addu $4, $4, 32753 ; sq $5, 0($4)
   which is the retail's exact shape - the retail's `addiu $a0, $s0, 0x10`
   is this cc1's `addu $4, $16, 16` (measured: gas 2.9-ee-991111 rewrites
   `addu rd, rs, imm` into the R5900 three-operand addiu encoding 0x25, so
   `addu $4,$16,16` assembles to 0x26040010, the retail's word).  But the
   immediate has to be the real offset, and 0x10 (and 0x180) are inside the
   legal range, so the only way to reach the escape is to bias the base by
   32743, which costs the extra instruction the retail does not have.

   SPELLINGS MEASURED AND FOUND TO FOLD (2026-10-20, this wave): a TI128
   pointer variable; the pointer used twice; the pointer live across a call;
   two C names for one pointer; a struct member; an array index; a union; a
   volatile store; a volatile pointer object (this one reaches a plain
   register address, `sw`/`lw` round trip and a zero-displacement `sq`, but
   costs the stack store and the reload, 8 bytes over); a 64-bit pointer
   (`daddu` plus a `dsll`/`dsra` sign-extension pair); a 16-bit, 8-bit or
   int base; the offset out of range (above); a static __inline__ copy
   helper (2 and 4 parameters); __builtin_memcpy; and the per-file flags
   -g, -mno-split-addresses, -fno-schedule-insns, -fno-schedule-insns2,
   -fno-expensive-optimizations and -O1 (none changes the shape).

   TWO SHAPES THAT DO REACH A ZERO-DISPLACEMENT sq, for the record: a
   pointer that is LOADED from memory (`lw $v1, 0x68($a0) ; lq $v0, 0($a1)
   ; sq $v0, 0($v1)`, the matched func_L08_004356A0), and a pointer that is
   carried by a loop and incremented at the end of the body, where the
   store's address register has no plus in its class at the store (the
   matched func_002E5FE0).  Neither can express "base + 0x10" with an
   addiu.

   History: an earlier attempt in this file was 184 bytes (the copy alone was
   two instructions instead of four); the body below is the 172-byte one,
   which matches the retail instruction for instruction everywhere but the
   copy. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B2410 __attribute__((sda));
extern float D_L20_001B2414 __attribute__((sda));
extern float D_L20_001B241C __attribute__((sda));

extern float func_00283B98(float, float);
extern float func_00283198(float);
extern void func_002A9288(char *, float);
extern void func_L20_0044AA88(char *);

void func_L20_0044A838(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    u16 n = *(u16 *)(arg0 + 0x96);
    float r;

    *(u16 *)(arg0 + 0x96) = n + 1;
    if (*(u8 *)(arg0 + 0x31)) {
        *(TI128 *)(arg0 + 0x10) = *(TI128 *)(state + 0x180);
        r = func_00283B98(*(float *)(state + 0x1A0),
                          D_L20_001B2414 * 0.000290888245f);
        *(float *)(state + 0x1A0) = r;
        r = func_00283198(r);
        *(float *)(arg0 + 0x18) = *(float *)(arg0 + 0x18) + D_L20_001B2410 * r;
        func_002A9288(arg0, D_L20_001B241C);
    }
    if (((*(u16 *)(arg0 + 0x34)) ^ 1) & 1) {
        func_L20_0044AA88(arg0);
    }
}

/* WAVE 3 (2026-10-20, worker 09, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one; this wave
   measured exactly what the compiler does with the 16-byte copy, and where.

   THE FOLD HAPPENS IN THE CSE, NOT IN COMBINE.  Measured with `cc1 -dall'
   on a small file: the front end builds the copy as
       (set (reg/v:SI 86) (plus:SI (reg/v:SI 84) (const_int 16)))
       (set (reg:TI 88) (mem:TI (reg/v:SI 87) 0))
       (set (mem:TI (reg/v:SI 86) 0) (reg:TI 88))
   - the MEM's address IS a pseudo in the .rtl dump.  The .cse dump already
   shows (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0): the CSE
   replaced the pseudo with the plus.  (In this compiler the CSE runs
   BEFORE combine: toplev.c has cse_main at 3854, gcse_main at 3899,
   cse2_main at 3980 and combine_instructions at 4093.)
   The rule is find_best_addr() in gcc/cse.c: CSE_ADDRESS_COST(REG) is
   ADDRESS_COST(REG) = 1 (config/mips/mips.h:3826) and
   CSE_ADDRESS_COST(plus(reg, small const)) is mips_address_cost(plus) = 1
   (config/mips/mips.c:2646, SMALL_INT -> 1).  A TIE, broken by
   ((p->cost + 1) >> 1 > best_rtx_cost), and rtx_cost(plus) = 2 +
   rtx_cost(reg) + rtx_cost(const) = 4 against the register's 0 or 1 - so
   the plus wins.
   The reload then sees (mem:TI (plus (reg) const) 0), which IS a legitimate
   TImode address (GO_IF_LEGITIMATE_ADDRESS, the offset inside
   [-32768, 32751]), so the offset becomes the displacement.
   => The retail's shape (an addiu plus a zero-displacement lq/sq) is
      EXACTLY what the reload produces when the MEM's address is still the
      pseudo.  Only the CSE's cost tie takes it away.  A tie that went to
      the register would give the retail's bytes for every 16-byte copy in
      the game.

   WHAT MAKES THE ADDRESS SURVIVE THE CSE (all measured):  the pseudo's
   value must not be a `plus' of a register and a small constant, because
   that is the only shape with an address cost of 1.
   - a SYMBOL base: plus(symbol, const) has address cost 3, the pseudo
     survives, the reload materialises it and the access gets a ZERO
     displacement:
       lui $3,%hi(SYM+16) ; addiu $3,$3,%lo(SYM+16) ;
       lq $2,368($3) ; sq $2,0($3)
     This is the only plain-C spelling measured that reaches the retail's
     zero-displacement 16-byte access, and it needs a symbol address - the
     copies here have runtime pointer bases.
   - a MEM base (plus(mem, const), cost 4): the pseudo survives, but the
     reload keeps the offset on the loaded register, so it folds anyway:
       lw $3,104($4) ; sq $2,384($3)
   - a volatile pointer object (the value goes through memory): the pseudo
     survives and the reload materialises it:
       addiu $v0,$s0,0x10 ; sw $v0,0($sp) ; lw $v1,0($sp) ;
       lq $2,0x180($s1) ; sq $2,0($v1)
     MEASURED ON THIS FUNCTION: 184 bytes against the retail's 180 - one
     instruction OVER, because the frame grows by 16 bytes and the copy
     costs three instructions where the retail has one (the addiu).  The
     wave-3 hint ("escape B lands on a body that is already a few bytes
     short") does NOT hold here: the body is 8 bytes short and escape B
     costs 12.
   - an offset outside [-32768, 32752]: the reload materialises, but with
     the wrong immediate.

   THE COMMON FILE'S RULE "the retail materialises a 128-bit address when
   the address is used more than once" DOES NOT HOLD IN THIS COMPILER.
   Measured: a pointer used twice in one block (two 16-byte copies to it
   and from it) and a pointer live across a call are all still folded:
       sq $2,16($4) ; sq $2,272($4) ; sq $2,16($18)
   The retail's shape in this function is the two addiu's of the copy, and
   the difference in the float registers below follows from it.

   THE FLOAT REGISTER ORDER IS A SCHEDULING DIFFERENCE, NOT A SOURCE
   SHAPE: this cc1 materialises the literal 0x00029088 into $f0 and loads
   the $gp float into $f13 (mul.s $f13,$f13,$f0), the retail loads the $gp
   float into $f0 and materialises the literal into $f13 (mul.s
   $f13,$f0,$f13).  -fno-schedule-insns moves the materialisation, but it
   BREAKS the two bodies already matched in the unit (func_L20_00449AE8:
   "instruction at +0x60 differs", func_L20_0044AA88: "instruction at
   +0xc differs"), so it cannot go on this file. */

/* WAVE 4 (2026-10-21, worker 11, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  This wave
   measured what the wall really is and found the rule the retail follows.

   1. THE RULE (this replaces the common file's "used more than once"
      rule, which does not hold).  The retail materialises EVERY 128-bit
      address into a register and uses a ZERO displacement:
          addiu $a0, $s0, 0x10 ; lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
      Plain C reproduces that when the address is
        - a PLAIN POINTER (a parameter, a loaded pointer, a pointer
          variable that holds a pointer).  The matched witness is
          src/levels/shared/L00_002D3798.c: `*out = *in;` with TI-mode
          pointer parameters gives the retail's `lq $v0,0($s2)`;
        - a SYMBOL.  The matched witness is src/game/002C1EF0-rc2.c:
          `TI v = D_001BAFA0;` gives the retail's
          `lui $v0,%hi(S) ; addiu $v0,$v0,%lo(S) ; lq $v1,0($v0)`;
        - a STACK SLOT.  The matched witness is this level's
          func_L20_0043F510, whose `sq $v0,0x0($sp)` is the frame pointer
          (find_best_addr never touches a frame-pointer address).
      It does NOT reproduce it when the address is base+const with a
      runtime base.  MEASURED over the whole game (every catalogue row,
      every level): the retail's shape - an addiu whose destination is
      the base of a zero-displacement lq/sq - occurs 43,255 times, 2,210
      of them in level 20, and in NONE of the 3,855 functions that are
      already C in src/.  => The retail's copy is the original source's
      inline-asm copy macro ("lq $v0,0(%1); sq $v0,0(%0)" with "r"
      operands - which is also the order the retail's two addiu's are in:
      the destination's address first, then the source's), and src/ does
      not allow inline asm.  The level-2 record
      nonmatching/levels/func_L02_003F52B0.c reached the same conclusion
      from the other side.

   2. WHERE THE FOLD HAPPENS, exactly (measured with `cc1 -da`):
      - the front end builds the copy as
          (set (reg/v:SI 86) (plus:SI (reg/v:SI 84) (const_int 16)))
          (set (reg:TI 88) (mem:TI (reg/v:SI 87) 0))
          (set (mem:TI (reg/v:SI 86) 0) (reg:TI 88))
        so the MEM's address IS a pseudo; the .cse dump already shows
        (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0).
      - the CSE's find_best_addr() (gcc/cse.c:2690) substitutes the class
        member that ties on the address cost: ADDRESS_COST(REG) = 1
        (config/mips/mips.h:3826) and mips_address_cost(plus(reg, const))
        = 1 (config/mips/mips.c:2660; SMALL_INT is [-32768, 32767],
        mips.h:2099) - a TIE, and the tie-break
        ((p->cost + 1) >> 1 > best_rtx_cost) favours the plus, whose
        COST is rtx_cost(plus,SET)*2 against the pseudo's 1.
      - the reload then sees (mem:TI (plus (reg) const) 0), which IS a
        legitimate TImode address (GO_IF_LEGITIMATE_ADDRESS,
        config/mips/mips.h:3055: the offset in [-32768, 32752]), so
        find_reloads_address_1 (gcc/reload.c:4632) returns without
        reloading and the offset becomes the displacement.
      => The retail's shape is EXACTLY what the reload produces when the
         MEM's address is still the pseudo.  Only the CSE's cost tie
         takes it away.
      - find_best_addr() returns EARLY, without touching the address, for
        an address based on the frame pointer (gcc/cse.c:2716) and for a
        constant address (CONSTANT_ADDRESS_P) - that is the stack and the
        symbol escape above.

   3. SPELLINGS MEASURED THIS WAVE, ALL FOLD (the mem's address stays a
      plus and the reload folds it):
      - the pointer as a C variable, computed before the if-block or
        inside it, used once or twice;
      - `p = p + const` in place, with a known or an unknown base: the
        CSE's canon_reg rewrites plus(p,16) into plus(base,16) when it
        knows the base, and the invalidation does not take the plus out
        of the class;
      - the pointer carried by a loop: the address IS materialised, but
        at the pointer's definition site, before the loop (measured
        `beq $v0,$0,$L ; addu $4,$4,16 ; ... ; sq $v2,0($4)`);
      - the pointer computed in one basic block and used in another: the
        copy is hoisted into the branch's delay slot, back into the block
        that holds the address;
      - do { ... } while (0);
      - a struct with a TI-mode member (the copy of two plain pointers
        gives the retail's zero displacement; base+const still folds);
      - the volatile pointer object and the out-of-range offset, both
        measured before, both change the shape.

   4. THE FLAG.  This body wants -fno-schedule-insns, and it needs a unit of
      its own: with the flag the ONLY difference left is the copy.
      Measured with a unit of its own
        src/levels/20_yeedil/L20_0044A838-g8.c
          -O2 -G8 -ffunction-sections -fno-schedule-insns
      the body is 172 bytes against the retail's 180 and the diff is
      exactly the copy: the retail's
          addiu $a0, $s0, 0x10 ; addiu $v1, $s1, 0x180 ;
          lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
      against this cc1's
          lq $v0, 0x180($s1) ; sq $v0, 0x10($s0)
      (the only other difference is the branch offset that counts the
      two missing instructions).  Every other instruction matches: the
      frame, the three $gp loads, the float registers, the calls, the
      branches, the epilogue.  Without the flag the float order is wrong
      as well (this cc1 materialises the literal 0x00029088 into $f0 and
      loads the $gp float into $f13, the retail does the opposite, so
      `mul.s $f13,$f13,$f0` against the retail's `mul.s $f13,$f0,$f13`),
      which is why the wave-3 record could not use the flag: it breaks
      the two bodies already matched in the shared unit
      (func_L20_00449AE8, func_L20_0044AA88).  The flag therefore needs
      a file of its own, and the config/cflags.txt row for it is
      src/levels/20_yeedil/L20_0044A838-g8.c
        -O2 -G8 -ffunction-sections -fno-schedule-insns

/* WAVE 5 (2026-10-21, worker 11, unit src/levels/20_yeedil/L20_00449178-g8.c).
   The attempt above is unchanged and is still the best one.  This wave
   settled the mechanism, settled the disputed point of wave 4, and
   measured that the wall is a SOURCE-level macro, not a compiler rule.

   1. THE MECHANISM, SETTLED.  The two stories of the last wave are both
      right, about two different steps, and the order matters.

      (a) For the direct spelling `*(TI128 *)(base + off)' the CSE is NOT
          involved.  The front end builds the address as a PLUS EXPRESSION
          (measured with `cc1 -da', the .rtl dump):
              (set (mem:TI (plus:SI (reg/v:SI 84) (const_int 16)) 0)
                    (reg:TI 86))
          and the RELOAD folds the constant into the displacement:
          GO_IF_LEGITIMATE_ADDRESS (config/mips/mips.h) accepts
          plus(reg, const_int) as a TImode address while
              INTVAL(const) >= -32768 && INTVAL(const) + 16 - 1 <= 32767,
          so strict_memory_address_p() (gcc/reload.c) finds the address
          legal, does not reload it into a register, and the printer prints
          the constant as the displacement.  DECISIVE MEASUREMENT: the
          offset 32752 folds (`sq $2,32752($4)') and 32753, one past the
          TImode range, makes the reload materialise the address
          (`addu $4,$4,32753 ; sq $2,0($4)').

      (b) For the pointer-VARIABLE spelling (`char *p = base + off;'
          `*(TI128 *)p = v;') the front end builds the address as the
          PSEUDO p (the .rtl dump: `(set (mem:TI (reg/v:SI 84) 0) ...)'),
          and the CSE's find_best_addr() (gcc/cse.c) substitutes the class
          member plus(base, off), because mips_address_cost()
          (config/mips/mips.c) gives "register plus a small constant" the
          cost 1 and ADDRESS_COST(REG) is 1 too - a tie, and the tie-break
          (the rtx cost, gcc/cse.c) goes to the plus.  The reload then
          folds it as in (a).

      So the fold is in the RELOAD in both spellings; the CSE only decides
      whether the reload ever sees a plus.  No flag changes it (measured on
      the same body: -fno-gcse, -fno-expensive-optimizations,
      -fno-schedule-insns, -mno-split-addresses, -g and -fno-strength-reduce
      all give the same folded lq/sq).

   2. THE DISPUTED POINT, SETTLED: a pointer LOADED FROM MEMORY SURVIVES.
      `char *p = *(char **)q; *(TI128 *)p = v;' gives
          lw $3,0($5) ; lq $2,0($3) ; sq $2,0($3)
      - the address is a register and the displacement is zero.  But it
      does NOT survive an offset added afterwards: `*(TI128 *)(p + 0x10)'
      gives `sq $2,16($3)', folded.  The escape only applies when the
      offset is already inside the loaded value.

   3. THE WALL IS A SOURCE-LEVEL MACRO, NOT A COMPILER RULE.  Measured in
      level 20: of the adjacent lq/sq pairs (a 16-byte copy), 2,421
      materialise BOTH addresses (the addiu and a zero displacement) and
      28 do not.  The 28 that fold are the field-by-field copies of ONE
      struct - the two addresses have the same relative layout (the
      matched witness below copies 0xC0/0xC0, 0xD0/0xD0 and 0xE0/0xE0) -
      while the 2,421 that materialise are copies of a single value.
      THE PROJECT HAS EXACTLY THAT MATCHED: func_L00_00395240
      (src/levels/shared/L00_0038F178.c) - `*(TI128 *)(object + 0xC0) =
      *(TI128 *)(p + 0xC0);' and two more - matches in 27 of 27 places,
      and the retail's bytes are the FOLDED
          lq $v0,0xC0($a0) ; sq $v0,0xC0($s0)
      => Plain C folds, and the retail folds too where the source is plain
      C.  The materialised places are the game's own copy macro - the PS2
      idiom `lq $v0,0(%1); sq $v0,0(%0)' with "r" operands, which forces
      both addresses into registers and sets the DESTINATION's address up
      first (the order the retail shows).  src/ does not allow inline asm
      (AGENTS.md), so those bodies are not reachable from C.
      => The wave-4 "matched witnesses" (L00_002D3798, 002C1EF0-rc2,
      func_L20_0043F510) are NOT evidence for an escape: in all three the
      address is a plain register, a symbol or a stack slot, where plain C
      and the macro agree.  The witness for the FOLD is func_L00_00395240.

   3b. HOW MANY OF THE MATERIALISED COPIES ARE REACHABLE AT ALL.  Of the
       2,421 adjacent materialised copies in level 20, 1,640 have a
       base+const address (the macro form, not reachable from plain C) and
       781 have plain-register addresses - a parameter, a pointer loaded
       from memory, or a callee-saved register that already holds the
       pointer (the plain-C form, reachable, and the shape the wave-4
       witnesses have).  So the "43,255 places game-wide" of the last
       wave counts the base+const shape alone; the plain-register copies
       are a separate, matchable population, and the 28 struct copies are
       a third.

   4. THE ESCAPES, all re-measured, and what each one costs:
        - a plain pointer (a parameter): the zero displacement.  FREE,
          but only when the address has no offset.
        - a pointer loaded from memory: the zero displacement.  FREE, and
          only when the offset is inside the loaded value.
        - a call result: the zero displacement.  FREE, same condition.
        - a symbol: materialised as lui/addiu (a constant address is
          illegitimate for TImode on the R5900, GO_IF_LEGITIMATE_ADDRESS).
          The retail's own form for D_00189E20 + 0xD0 is
          `lui %hi(D) ; addiu %lo(D) ; addiu 0xD0 ; lq $v0,0($v1)', which
          the C spelling cannot give (the front end folds the constant
          into the symbol's address).
        - a stack slot at offset 0: `sq $v0,0($sp)'.  FREE, no offset.
        - a volatile pointer object: the right shape, at the price of a
          sw/lw round trip and a frame.
        - an offset outside [-32768, 32752]: the right shape, with the
          wrong immediate (`addu $4,$4,32753 ; sq $2,0($4)').
        - NEW: a 64-bit address keeps the copy in a register (`sq $3,0($2)')
          but costs dsll/dsrl/daddu/dsll/dsra where the retail has one
          addiu.
        - NEW: `plus(const_int, reg)' (the constant on the left) is NOT a
          legitimate TImode address in the reload and would be
          materialised - but the front end canonicalises the constant to
          the right, so it cannot be spelled in C (measured: `16 +
          (u32)arg0' gives the same folded `sq $2,16($4)').
      => NONE of them applies to base+const with a runtime base, which is
      what these bodies need.

   5. THIS BODY.  The retail's copy is
          addiu $a0, $s0, 0x10 ; addiu $v1, $s1, 0x180 ;
          lq $v0, 0x0($v1) ; sq $v0, 0x0($a0)
      against this cc1's
          lq $v0, 0x180($s1) ; sq $v0, 0x10($s0)
      - the destination's address is set up first and the source's second,
      the macro's operand order.  Everything else in the body is the retail
      instruction: the prologue, the three $gp loads, the two calls, the
      flag test, the branch offsets and the epilogue.  With the flag in a
      unit of its own (src/levels/20_yeedil/L20_0044A838-g8.c,
      -O2 -G8 -ffunction-sections -fno-schedule-insns) the body is 172
      bytes against the retail's 180 and the difference is exactly the
      copy - the branch offset counts the two missing instructions.
      The wave-4 attempt stands; the body cannot be matched from C.
