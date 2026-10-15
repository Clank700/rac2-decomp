/* from src/core/001163B0.c: C that compiles longer than retail's 112 bytes */
/*
 * A decimal counter advanced in place, right to left: with a zero length
 * nothing happens and 1 is returned; the last digit is set to '0' when it is
 * '5' or above, the 9s below it are cleared, and the first digit that is not a
 * 9 is incremented (returning 1) or 0 is returned when that digit is a 9.
 *
 * Retail's control flow is a peeled loop: the length test at +0, the digit
 * test at +0x10, one `sb` of '0' at +0x20, then the 9s loop as a
 * `beql $v0,$a2` back edge at +0x3C, the digit at +0x4C and the two returns
 * at +0x58 and +0x60. The attempt below reproduces the logic and every
 * comparison, but this cc1 orders the loop tests and the pointer updates
 * differently and comes out five instructions long; the shapes tried were the
 * `for (;;)` with two breaks and a `while` with the length test in it.
 */
int func_00118460(char *buf, int len) {
    if (len <= 0)
        return 1;
    len--;
    if (buf[len] < '5')
        return 1;
    buf[len] = '0';
    for (;;) {
        len--;
        if (len <= 0)
            break;
        if (buf[len] != '9')
            break;
        buf[len] = '0';
    }
    buf += len;
    if (*buf != '9')
        return 0;
    *buf = *buf + 1;
    return 1;
}
