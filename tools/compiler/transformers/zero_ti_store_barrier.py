#!/usr/bin/env python3
"""Make a 128-bit clear a scheduling barrier in gcc/haifa-sched.c, as the game's clear macro was.

In retail a cleared quadword is followed at once by the next most urgent instruction, never by
an independent one: func_L02_003EAE10 and its family (func_L00_003BFF68, func_L13_0040A3B0,
func_L04_00419918, func_L17_003BCC30, func_L17_003BCEC0, func_L17_003C45A0, func_L02_003EA4E0)
have `sq $zero,0($sp)` ; `lwc1 $f0,N($sN)` ; the call's argument moves. This cc1 put the moves
first. sched2 sees a `store` (ready cost 2 on the R5900 memory unit) and the load as dependent on
it (state+N may alias sp+0), and as the R5900 issues two instructions a cycle, a ready move takes
the store's own cycle whatever that cost is: with cost 1 the load comes third, not second. An
`asm volatile ("sq $0,0x0(%0)")`, the removed qzero helper, gives retail's bytes with the
unchanged compiler: both schedulers make a volatile asm a barrier (sched_analyze_2), an insn of
cost 1 and no unit that nothing crosses. Retail has that shape: every `sq $zero` of its compiled
code (360, outside the hand-written COP2/MMI routines) has displacement 0, an address register
as the macro's "r" operand gives, and after `sq $zero,0(reg)` a load that may alias it is followed
by an independent instruction that was ready before the store in 71 of 95 cases (sp-based: 14 of
14), against 43 of 1,499 plain stores in the functions this compiler already matches.

The C writes that clear as a TImode store of zero, which rac2_fold_zero_ti_store turns into
`sq $0` after reload when the zero is not shared (a zero shared by several stores stays `por` +
`sq`, the C form). This gives exactly those stores a volatile asm's dependences, cost and unit:
after reload a TImode store from $0, before reload a TImode store of const 0 that is the only one
between two calls, labels or jumps (one that reload will not share). Measured on 21 October
2026: the 768 files in src/ compile to the same objects with the old and the new cc1 (the 106
SDK units through the unchanged SDK cc1); of the 1,688 drafts in nonmatching/, 30 change and
func_L02_003EAE10 is then exact; func_L00_003BFF68 (12 places) and func_L13_0040A3B0 (3) match
too, prologue order included, with their call's float argument declared before the pointers."""
import sys
from pathlib import Path

path = Path(sys.argv[1])
source = path.read_text(encoding="utf-8")
old = ("/* Analyze an INSN with pattern X to find all dependencies.  */\n"
       "\n"
       "static void\n"
       "sched_analyze_insn (x, insn, loop_notes)\n"
       "     rtx x, insn;\n"
       "     rtx loop_notes;\n"
       "{\n"
       "  register RTX_CODE code = GET_CODE (x);\n"
       "  rtx link;\n"
       "  int maxreg = max_reg_num ();\n"
       "  int i;\n"
       "\n")
new = ("/* RAC2: the game cleared a quadword with an inline-asm macro, `sq $0,0x0(%0)', which both\n"
       "   schedulers treat as a volatile asm.  The C writes it as a TImode store of zero, folded\n"
       "   to `sq $0' after reload when the zero is not shared: before reload, the only TImode\n"
       "   store of const 0 between two calls, labels or jumps.  */\n"
       "\n"
       "static int\n"
       "rac2_const0_ti_store_p (x)\n"
       "     rtx x;\n"
       "{\n"
       "  return (GET_CODE (x) == SET\n"
       "\t  && GET_CODE (SET_DEST (x)) == MEM\n"
       "\t  && GET_MODE (SET_DEST (x)) == TImode\n"
       "\t  && SET_SRC (x) == const0_rtx);\n"
       "}\n"
       "\n"
       "static int\n"
       "rac2_zero_ti_barrier_p (x, insn)\n"
       "     rtx x, insn;\n"
       "{\n"
       "  rtx scan;\n"
       "\n"
       "  if (GET_CODE (x) != SET\n"
       "      || GET_CODE (SET_DEST (x)) != MEM\n"
       "      || GET_MODE (SET_DEST (x)) != TImode)\n"
       "    return 0;\n"
       "  if (reload_completed)\n"
       "    return GET_CODE (SET_SRC (x)) == REG && REGNO (SET_SRC (x)) == 0;\n"
       "  if (SET_SRC (x) != const0_rtx)\n"
       "    return 0;\n"
       "  for (scan = PREV_INSN (insn); scan; scan = PREV_INSN (scan))\n"
       "    {\n"
       "      if (GET_CODE (scan) == CODE_LABEL || GET_CODE (scan) == JUMP_INSN\n"
       "\t  || GET_CODE (scan) == CALL_INSN || GET_CODE (scan) == BARRIER)\n"
       "\tbreak;\n"
       "      if (GET_CODE (scan) == INSN && rac2_const0_ti_store_p (PATTERN (scan)))\n"
       "\treturn 0;\n"
       "    }\n"
       "  for (scan = NEXT_INSN (insn); scan; scan = NEXT_INSN (scan))\n"
       "    {\n"
       "      if (GET_CODE (scan) == CODE_LABEL || GET_CODE (scan) == JUMP_INSN\n"
       "\t  || GET_CODE (scan) == CALL_INSN || GET_CODE (scan) == BARRIER)\n"
       "\tbreak;\n"
       "      if (GET_CODE (scan) == INSN && rac2_const0_ti_store_p (PATTERN (scan)))\n"
       "\treturn 0;\n"
       "    }\n"
       "  return 1;\n"
       "}\n"
       "\n"
       "/* Analyze an INSN with pattern X to find all dependencies.  */\n"
       "\n"
       "static void\n"
       "sched_analyze_insn (x, insn, loop_notes)\n"
       "     rtx x, insn;\n"
       "     rtx loop_notes;\n"
       "{\n"
       "  register RTX_CODE code = GET_CODE (x);\n"
       "  rtx link;\n"
       "  int maxreg = max_reg_num ();\n"
       "  int i;\n"
       "\n"
       "  /* RAC2: the dependences of a volatile asm (sched_analyze_2), and its cost and unit.  */\n"
       "  if (rac2_zero_ti_barrier_p (x, insn))\n"
       "    {\n"
       "      int max_reg = max_reg_num ();\n"
       "      for (i = 0; i < max_reg; i++)\n"
       "\t{\n"
       "\t  rtx u;\n"
       "\t  for (u = reg_last_uses[i]; u; u = XEXP (u, 1))\n"
       "\t    add_dependence (insn, XEXP (u, 0), REG_DEP_ANTI);\n"
       "\t  reg_last_uses[i] = 0;\n"
       "\n"
       "\t  for (u = reg_last_sets[i]; u; u = XEXP (u, 1))\n"
       "\t    add_dependence (insn, XEXP (u, 0), 0);\n"
       "\n"
       "\t  for (u = reg_last_clobbers[i]; u; u = XEXP (u, 1))\n"
       "\t    add_dependence (insn, XEXP (u, 0), 0);\n"
       "\t}\n"
       "      reg_pending_sets_all = 1;\n"
       "      flush_pending_lists (insn, 0);\n"
       "      INSN_COST (insn) = 1;\n"
       "      INSN_UNIT (insn) = -1;\n"
       "    }\n"
       "\n")
assert source.count(old) == 1, ("the head of sched_analyze_insn", source.count(old))
path.write_text(source.replace(old, new), encoding="utf-8", newline="")
