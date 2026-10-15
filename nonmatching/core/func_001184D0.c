/* from src/core/001163B0.c: 120 bytes, matching retail instruction for instruction
   except one register assignment */
/*
 * In-place string reverse. Retail counts the length with `while (s[++len])`,
 * decrements, then swaps s[i] with s[len] while both counters close on each
 * other. The body below, under the *game* compiler (`-O2 -G2
 * -ffunction-sections`, no `sdk` prefix, in a file of its own), compiles to
 * exactly 120 bytes: same instructions, same order, same three `nop`s in the
 * first loop, same `bnel` with the increment in its delay slot, same frame-less
 * prologue and same `jr $ra`/`daddu $v0` - with one difference, in the whole
 * function: the base pointer. Retail copies the parameter to $t1 and counts in
 * $t0; this cc1 copies it to $t0 and counts in $t1.
 *
 * Measured witnesses for the tie:
 *  - the same C under the SDK profile (`sdk -O2 -G2 -ffunction-sections`, the
 *    unit's own line) loses `bnel`, the delay-slot increment and the whole
 *    register order (112 bytes) - this unit is a game-compiler unit;
 *  - `int len = 0; int i = 0;` with the block's `i = 0;` dropped flips the base
 *    to $t1 and the rest of the body then agrees word for word, but the two
 *    initialisations are then emitted in the entry block (a3 in the beqz delay
 *    slot becomes t0) and it is 120 bytes of the wrong layout;
 *  - adding the block's `i = 0;` back makes the compiler delete the entry one
 *    before register allocation, and the base returns to $t0 (exact 120-byte
 *    layout, wrong register);
 *  - `do { len++; } while (s[len])`, `for (len = 1; s[len]; len++)`, a `char *p
 *    = arg0;` base, and both declaration orders all give the same 120 bytes with
 *    $t0 / $t1.
 */
char *func_001184D0(char *arg0) {
    int len = 0;
    int i;
    char c;

    if (arg0[0] != 0) {
        while (arg0[++len] != 0) {
        }
    }
    len--;
    if (len > 0) {
        i = 0;
        do {
            c = arg0[i];
            arg0[i] = arg0[len];
            arg0[len] = c;
            i++;
            len--;
        } while (i < len);
    }
    return arg0;
}
