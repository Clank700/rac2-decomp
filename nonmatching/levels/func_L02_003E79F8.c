/* Near miss (level 2, one place): 360 bytes against retail's 352. It needs a -g8 unit: the
 * weights are read through $gp (D_L02_001B0938 declared with `sda` and a size of at most 8
 * bytes, indexed past its declared size), the counter-table byte and the two reference
 * words are absolute.
 *
 * Right in this draft (88 instructions against retail's 86, 80 of them matching in order):
 * the prologue and epilogue, the two calls to func_0026FEB8, the walk over the six weights
 * (`sll`/`addiu $gp`/`addu`/`lw`/`subu`/`bgezl`, instruction for instruction, with the
 * annulled `addiu` of the index in the delay slot), the first weight read as `lw 0x1948($gp)`
 * ahead of the loop, the positive `bgez` in front of it, the hoisted `lui` of the table and of
 * the second func_0026FEB8 argument, the three nested tests on the state word, the triple
 * store in retail's order (+0x98, +0x94, +0x90), the three random rolls and the closing
 * loop with its pad `nop`.
 *
 * What differs: the rolled index is stored by the `break` of the loop, and jump.c's
 * duplicate_loop_exit_test copies everything from the loop test to the end of the loop in
 * front of it (the first iteration, W[0]); the copy carries the store as `sw $zero,0x5C($s1)`.
 * Retail's copy has no store on that path: it goes `b` straight to the join (the `lw` of the
 * state word is in its delay slot) and the store only follows the loop's closing branch. The
 * extra store also keeps the copy's else path a real block, so gcse puts the hoisted `lui`
 * pair at the end of that block and of the loop entry (four `lui` here, two in retail, which
 * has them above the front test in the first block), and `daddu $a1,$zero,$zero` lands in the
 * delay slot of the front test instead of before it.
 *
 * Tried: `while (r >= 0) { i++; if (i >= 6) goto done; r -= W[i]; }` followed by the store,
 * the same as `for (;;)` with a break, as a do-while inside `if (r >= 0)`, and with the store
 * after the loop under `if (i < 6)`, `if (r < 0)` and `if (i != 6)`: all of them let loop.c
 * strength-reduce the walk into a pointer increment (`addiu $a0,$gp,0 ... addiu $a0,$a0,4`),
 * where retail indexes with `sll`/`addu` each time because the front copy jumps into the loop
 * (loop.c skips a loop with a second entry); a goto-built loop gives retail's walk but a
 * `bltz` front test and no hoisted `lui`.
 *
 * Measured with the compiler source: with the store after the loop (the `break` block empty)
 * gcse's lazy code motion does put the two `lui` in the first block (it needs the front test's
 * fall-through to have no block of its own), but then jump.c folds `bgez LOOP ; b skip` into
 * `bltz skip`, the loop stays valid and loop.c strength-reduces it. A loop built from gotos
 * only (no loop notes) keeps retail's walk exactly, with `bltz` in front and $s0/$s1 swapped.
 *
 * What would unblock it: a spelling of the loop whose front copy has no store and still jumps
 * into the loop (`bgez LOOP ; b skip`), with the store on the closing branch's fall-through
 * only.
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
    *(int *)(state + 0x98) = *(int *)(state + 0x94) = *(int *)(state + 0x90) = v;
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
