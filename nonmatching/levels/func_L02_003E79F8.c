/* Near miss (level 2, one place): 360 bytes against retail's 352 (90 instructions against 88;
 * 79 of retail's 88 in order). It needs a -g8 unit: the weights are read through $gp
 * (D_L02_001B0938 declared with `sda` and a size of at most 8 bytes, indexed past its declared
 * size), the counter-table byte and the two reference words are absolute.
 *
 * Right in this draft: everything after the peeled front test - the prologue and epilogue, the
 * two calls to func_0026FEB8, the loop itself (retail's indexed walk with `addiu $gp` inside the
 * loop and the annulled `addiu` of the index in the `bgezl` slot: loop.c ignores the loop, "Loop
 * at 33 ignored due to multiple entry points", because the front copy jumps into it - retail's
 * loop is just as unoptimised), the three nested tests on the state word, the triple store in
 * retail's order (+0x98, +0x94, +0x90: the chain below is written in the reverse order), the three
 * random rolls and the closing loop with its pad `nop`. The natural `for` with the store in the
 * `break` block is the right source.
 *
 * What differs is only the front copy (jump.c's duplicate_loop_exit_test peels `r -= W[0];
 * if (r >= 0) goto loop; state->5C = 0; goto join`), and the cause is measured: it is where
 * gcse puts the high halves of D_001395B8 and D_L02_001B09F0.
 *  - This cc1 runs gcse's block LCM (patch 0016 makes -fno-edge-lcm the default). Before it,
 *    gcse.c's compute_preds_succs(..., 1) (flow.c, "CYGNUS LOCAL edge splitting/law") splits the
 *    critical edge from the copy's `bgez` into the loop header, because the header is reached
 *    only by jumps. Both successors of the first block are then "delayed" blocks with a single
 *    predecessor, so LATEIN/ISOOUT make the end of the copy's else block and the end of the split
 *    block the insertion points: four `lui` (dump: "PRE/HOIST: end of bb 1 ... end of bb 2").
 *    Without that split the loop header (with its back edge) is a direct successor of the first
 *    block, ISOOUT(bb 0) is 0, and the end of bb 0 is optimal: retail's two `lui` above the front
 *    test (worked through lcm.c's pre_lcm by hand; -fedge-lcm gives the same split placement).
 *  - With the `lui` pair out of the copy's else block, that block is `sw $zero,0x5C($s1) ; b
 *    join`: reorg fills the `b` slot with the store, relax_delay_slots finds it redundant with the
 *    first `sw $zero,0x5C($s1)` (reorg.c's redundant_insn) and deletes it, and the `b` is refilled
 *    from its target, `lw $v1,0x5C($s1)` (a filled slot is also why reorg's own fold of
 *    `bgez L ; b M ; L:` into `bltz` does not apply). That is exactly retail's `bgez $s0,loop ;
 *    lui $a3 ; b join+4 ; lw $v1,0x5C($s1)`. Verified on a scratch function with an explicit redundant
 *    store in such a block: it survives to .jump2 and disappears in .dbr.
 *  So the 8 bytes are the split critical edge: the same wall as func_L23_0041B9F0 and
 *  func_002CD720 (and func_L02_003FCCA0's `lui $s4`), a compiler-side lever, not a source shape.
 *
 * Tried (all measured): the `for` as here (360), a `while (i < 6)` with the increment at the end
 * (identical), `if ((r -= W[i]) < 0)` (identical), `i <= 5` (identical), a do-while (328: valid
 * loop, strength-reduced), a `goto` out of the loop instead of `break` (328, same), the store after
 * the loop under `if (i < 6)` (the copy folds to `bltz`, so its fall-through has no block: gcse
 * does place the `lui` pair at the end of bb 0, but the loop is valid, loop.c hoists `&W` and
 * strength-reduces the walk, and the `lui` pair comes out at its uses again),
 * `if (r < 0)` after the loop (same), compare before subtracting (376), and -fedge-lcm. No flag
 * turns loop.c off, and every spelling whose copy does not jump into the loop lets loop.c hoist
 * `&W` out of it where retail computes it inside, so the copy with its store is required.
 */

extern unsigned char D_001395B8[0x100];

extern int D_0018C2EC __attribute__((nosda));

extern int D_001A7A00;

extern int D_L02_001B0938[2] __attribute__((sda));

extern char D_L02_001B09E0[];

extern char D_L02_001B09F0[];

extern void func_0026FEB8(const char *, ...);

extern int func_002A77E0(int);

extern int func_002A7820(int, int);

void func_L02_003E79F8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    int r;
    int i;
    int v;

    r = func_002A77E0(1000);
    func_0026FEB8(D_L02_001B09E0, r);
    *(int *)(state + 0x5C) = 0;
    for (i = 0; i < 6; i++) {
        r -= D_L02_001B0938[i];
        if (r < 0) {
            *(int *)(state + 0x5C) = i;
            break;
        }
    }
    if (*(int *)(state + 0x5C) == 4) {
        if (D_0018C2EC == D_001A7A00)
            *(int *)(state + 0x5C) = 1;
    }
    if (D_001395B8[0x8F] < 4) {
        if (*(int *)(state + 0x5C) == 5)
            *(int *)(state + 0x5C) = 1;
    }
    v = *(int *)(state + 0x5C);
    *(int *)(state + 0x90) = *(int *)(state + 0x94) = *(int *)(state + 0x98) = v;
    func_0026FEB8(D_L02_001B09F0, v);
    if (*(int *)(state + 0x5C) == 0) {
        int a;

        *(int *)(state + 0x90) = func_002A7820(1, 5);
        *(int *)(state + 0x94) = func_002A7820(1, 5);
        do {
            a = func_002A7820(1, 5);
            *(int *)(state + 0x98) = a;
        } while (*(int *)(state + 0x90) == *(int *)(state + 0x94) &&
                 *(int *)(state + 0x90) == a);
    }
}
