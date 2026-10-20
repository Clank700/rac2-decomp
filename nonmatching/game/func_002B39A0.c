/* func_002B39A0 (boot function, 384 bytes; 19 levels, 20 places in all).
 * Near miss: compiles to 384 bytes, retail is 384, and tools/check.py reports
 * 0 of 20 places match. The prologue, the early returns, the loop and the
 * return match. What still differs is the register pairing in the first 0x30
 * bytes: the table header pointer, the 0x30 constant, the record address and
 * the table load sit in $a0/$v1 where retail has them in $v1/$a0, so the
 * store of 10 and the table load come out in the other order. Tried without
 * success: the early returns as one || chain, as nested ifs and as separate
 * ifs; the header pointer as int * and char *; the record offset in a local;
 * the operands of 0x30 * index; the function in 002B3868-g8.c (-G8), where
 * every table access becomes $gp-relative, which retail does not do.
 */
typedef struct {
    char *target;
    unsigned char count;
    unsigned char value;
} Pick8_2B39A0;
extern Pick8_2B39A0 **D_001B17BC __attribute__((sda));
extern char *D_001B17C0;
extern int D_001B1688 __attribute__((sda));

char *func_002B39A0(char *self, int index, int *out)
{
    int i;
    char *result;
    float best;

    if (index < 0 || !(index < *(int *)D_001B17C0) || D_001B1688 < 2)
        return 0;
    *(short *)(D_001B17C0 + 0x30 * index + 0x3A) = 10;
    if (D_001B17BC[index]->count == 0)
        return 0;
    if (D_001B17BC[index]->count == 1) {
        *out = D_001B17BC[index]->value;
        return D_001B17BC[index]->target;
    }
    best = 9999999.0f;
    result = 0;
    for (i = 0; i < D_001B17BC[index]->count; i++) {
        if (D_001B17BC[index][i].target != 0) {
            float d = func_002B38C8(self, D_001B17BC[index][i].target);
            if (d < best) {
                best = d;
                result = D_001B17BC[index][i].target;
                *out = D_001B17BC[index][i].value;
            }
        }
    }
    return result;
}
