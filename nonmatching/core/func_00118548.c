/* from src/core/001163B0.c: C that compiles to 160 (or 140) bytes where retail has 156 */
/*
 * Itoa, and the unsigned arithmetic is settled: retail divides with `divu`
 * and negates with `negu` + `movz $a0,$v1,$v0` (v0 = base ^ 10), which only
 * the unsigned spellings produce - a signed `int value` compiles to `div` and
 * `movn`. The retained draft is the unsigned one, and it is 160 bytes.
 *
 * What is left is one register and one scheduling choice. Retail keeps the
 * quotient in $a0 (the value's own register) and the length in $a3, and its
 * loop back-edge is `bnel $a0,$zero,loop` with the next `divu` in the delay
 * slot; this cc1 keeps the value in $a3, copies the quotient back with an
 * extra `daddu $a3,$a0,$zero`, keeps the length in $t0 (and the table base in
 * $t4), and hoists the `divu` out of the delay slot. Tried: `len` as an index
 * with the division as a statement, and `*p++` with `while (value /= base)` -
 * the second is 140 bytes and loses the retail structure entirely.
 */
extern char D_00134640[];

extern char *func_001184D0(char *arg0);

char *func_00118548(unsigned int value, char *buf, unsigned int base) {
    unsigned int neg = value >> 31;
    int len = 0;

    if (neg && base == 10)
        value = -value;
    do {
        buf[len++] = D_00134640[value % base];
        value /= base;
    } while (value != 0);
    if (neg)
        buf[len++] = '-';
    buf[len] = '\0';
    return func_001184D0(buf);
}
