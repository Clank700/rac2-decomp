/* Not C: the body is handwritten assembly (28 placements).
 *
 * Evidence, from the retail body at 0x002A0A28 (352 bytes):
 *  - $at is a working register: `addi $at,$t7,0xD00`, `lbu $a0,0($at)`,
 *    `addi $at,$at,1`, `addi $at,$t7,0x800` (trapping `addi`, not `addiu`);
 *  - four `j func_2A0A68`/`j func_2A0B38` absolute jumps to local labels: the
 *    compiler emits `b` for a local target, never `j`;
 *  - `beq $at,$v0` guards a forward skip over a loop body, with `nop` padding
 *    in the branch slots;
 *  - the loop counters are the `t` registers with hand-placed `nop`s.
 * Every one of these is outside this cc1's output.
 *
 * No C is retained: AGENTS.md asks for ASM_FUNC only with maintainer review,
 * so the INCLUDE_ASM marker stays in src/game/002A0430.c.
 */
