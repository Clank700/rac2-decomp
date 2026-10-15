/* from src/core/001163B0.c: C that compiles to 276 bytes where retail has 264.
 *
 * The stream writer the two newlib printf engines use for a FILE without the
 * 0x200 (string) flag. Structure, statement order and every instruction in
 * both the flush path and the loop match retail; what differs is twelve bytes
 * of register pressure, the same wall its twin func_00118BC0 hit (see
 * nonmatching/core/func_00118BC0.c).
 *
 * This cc1 materialises the full address of both globals into callee-saved
 * registers (`lui $s3,%hi; lw $v1,%lo($s3)`) and keeps two copies of the
 * staging buffer (one in $s7, one copied to $s1 for the call argument), so it
 * needs ten saved slots and a 0xA0 frame where retail uses eight and 0x80;
 * retail keeps only the page base in the register and folds the offset into
 * the access (`lw $a0,0x4674($s1)`, one `lui $s1,0x13` outside the loop).
 * Count and pointer are therefore $s2/$s3 here against $s2/$s1 in retail.
 *
 * Tried and rejected: passing the count as a literal (folds to 0x80 in the
 * call, retail keeps the register), an unnamed ++ expression, a named local
 * `n` for the incremented count, signed vs unsigned len (unsigned is right:
 * it gives retail's `beqz` guard and `sltu` loop test), the array spelling of
 * both globals. Unblocked by a source shape in which this cc1 leaves the
 * symbolic address in the $hi/$lo pair instead of computing it.
 */
extern char D_0013C180[];

extern int D_00134670;

extern char *D_00134674;

extern int func_0011B1E8(int arg0, char *buf, int count);

int func_00119AC0(int arg0, char *src, unsigned int len, int flush) {
    unsigned int i;
    int n;

    if (flush == 1) {
        func_0011B1E8(arg0, D_0013C180, D_00134670);
        D_00134670 = 0;
        D_00134674 = D_0013C180;
        return 0;
    }
    for (i = 0; i < len; i++) {
        *D_00134674++ = src[i];
        n = ++D_00134670;
        if (n == 0x80) {
            if (func_0011B1E8(arg0, D_0013C180, n) == 0)
                return 0;
            D_00134674 = D_0013C180;
            D_00134670 = 0;
        }
    }
    return i;
}
