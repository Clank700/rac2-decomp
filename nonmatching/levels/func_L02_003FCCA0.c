/* Near miss (level 2, one place). It needs a -g8 unit: D_001A79F8 is a plain extern int, which
 * the assembler turns into the absolute lui/lw pair outside a delay slot and into a $gp access
 * inside one, as retail has it. As written below (a `switch`, retail's structure) it is 340 bytes
 * against 344; with the dispatch as an if/else-if chain instead it is 344 bytes, 61 of 86
 * instructions in place (the chain is in the comment after the function).
 *
 * Fixed in this draft, each measured against the previous record:
 *  - the D_001A7A0C store: declared as the second word of an 8-byte object, D_001A7A08[1].
 *    cc1 counts a small symbol plus an offset as two instructions (mips.c's
 *    simple_memory_operand), so the store stays out of the func_L02_003FCDF8 slot, the
 *    argument move fills it, and the plain declaration keeps the assembler's absolute
 *    `lui $at ; sw` (retail's shape). A 16-byte D_001A7A00[4] materialises the address instead.
 *  - the closing table update as `+= 1`: the call comes first with `daddu $a0,$s2` in its slot,
 *    then `addiu $v1,$s4,%lo`. `D[...]++` and `++D[...]` form the address before the call (in a
 *    callee-saved register); a local index or a pointer to the element behave like `+= 1`.
 *  - the hero word is read through the unit's D_00189E20 (a struct in L02_003F5430-g8.c).
 *
 * What still differs, both compiler-side:
 *  1. `lui $s4,%hi(D_001395B8)` in the entry block. This cc1 runs gcse's block LCM (patch 0016
 *     makes -fno-edge-lcm the default) after gcse.c's compute_preds_succs(..., 1) has split the
 *     critical edge from the `bnez $s2` test into the shared else label (flow.c, "CYGNUS LOCAL
 *     edge splitting/law"; the label is reached only by jumps), so the high half is inserted on
 *     that split edge (`lui $s4` before the dispatch) and copied from the first test's own
 *     `lui $s0` (`daddu $s4,$s0,$zero`); the prologue then saves $s0 before $s4. Measured: with
 *     the outer test inverted (`if (a1 != 0 || D_001395B8[...] != 0) { else part } else
 *     { hero }`), the else label gets a fall-through predecessor, the edge is not split, and the
 *     entry block, the prologue order and the `addiu $s0,$s4,%lo` slot come out as retail's (the
 *     blocks are then in the wrong order). Retail's layout, with the hero block between the
 *     first test and the dispatch ending in `b`, cannot give that label a fall-through. Same wall
 *     as func_L02_003E79F8, func_L23_0041B9F0 and func_002CD720.
 *  2. The dispatch. Retail is this switch: `beq $s2,6 ; beql $s2,0xB ; b default ; nop`, then the
 *     bodies of 6, 0xB and the default. Here cygnus_merge_blocks (flow.c, after the first jump
 *     pass, "CYGNUS LOCAL law") moves the default body up behind the dispatch: it is the only
 *     successor of the block holding `goto default`, has no other predecessor and is not the last
 *     block, which holds for any switch whose default is its last case (and for the same
 *     `goto` chain). The if/else-if chain keeps the bodies in order but tests each value before
 *     its body with `bne`. A second label on the default (`case 0: default:`) adds tests.
 *
 * Tried before (previous record): the default last, `case 0` falling into the default (368), the
 * nested `if (a1 == 0) { if (...) }` with a goto to the tail, the table as a local pointer at the
 * top (320: it is kept in $s3), the two-names form of the counters.
 */

extern unsigned char D_001395B8[0x100];

extern int D_001A7A08[2];

extern int D_001A79F8;

extern int func_L02_003F9B70(int);

extern int func_L02_00400650(char *, int);

extern void func_00288308(int);

extern void func_002AD860(int);

extern int func_002A77E0(int);

extern int func_L02_003FCF08(int);

extern int func_L02_003FCDF8(int);

extern void func_L00_0030C7F8(int);

extern void func_0029B3E0(int, int);

/* D_00189E20 is the unit's own `extern L02_003F5710_Hero D_00189E20;` (L02_003F5430-g8.c). */

void func_L02_003FCCA0(char *a0, int a1) {
    char *state = *(char **)(a0 + 0x68);
    int saved;
    char *hero;
    int v;

    if (a1 == 0 && D_001395B8[func_L02_003F9B70(0)] == 0) {
        hero = (char *)&D_00189E20;
        saved = *(int *)(hero + 0x22C8);
        func_L02_00400650(a0, 7);
        func_00288308(0x26);
        func_002AD860(0x26);
        *(int *)(hero + 0x22C8) = saved;
    } else {
        switch (a1) {
        case 6:
            func_L02_00400650(a0, 8);
            break;
        case 0xB:
            func_L02_00400650(a0, 9);
            break;
        default:
            func_L02_00400650(a0, func_002A77E0(5) + 2);
            break;
        }
        D_001A7A08[1] = D_001A7A08[1] + func_L02_003FCF08(a1);
        v = func_L02_003FCDF8(a1);
        *(int *)(state + 0x110) = v;
        D_001A79F8 = D_001A79F8 + v;
        func_L00_0030C7F8(0x168);
    }
    D_001395B8[func_L02_003F9B70(a1)] += 1;
    func_0029B3E0(0, -1);
}

/* The chain form (344 bytes; replaces the switch above):
 *
 *     if (a1 == 6) {
 *         func_L02_00400650(a0, 8);
 *     } else if (a1 == 0xB) {
 *         func_L02_00400650(a0, 9);
 *     } else {
 *         func_L02_00400650(a0, func_002A77E0(5) + 2);
 *     }
 */
