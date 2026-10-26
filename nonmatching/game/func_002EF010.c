/* func_002EF010 (108 bytes, 28 places), closer M2: 100 bytes under -O2 -G8, without the
 * old nosda attribute (the limit byte is an incomplete array). The range test is a value
 * (retail's sltiu/xori), the then-arms come first as in retail, and the table scan is a
 * goto loop, which keeps retail's per-pass $gp address. Left: this cc1 gives the limit
 * and the table byte the same register, so the two "a0 -= x" exits are cross-jumped into
 * one (8 bytes); retail keeps the limit in $v1. Five spellings of the two types and the
 * test leave it. */
extern unsigned char ref_002EF010_00[8] __attribute__((sda));
extern unsigned char ref_002EF010_01[];

unsigned long func_002EF010(int a0)
{
    int i;
    unsigned char v;
    int limit;
    int out = (unsigned int)(a0 - 0x20) >= 0x91;

    if (!out) {
        limit = ref_002EF010_01[0];
        if (a0 >= limit) {
            a0 -= limit;
        } else {
            i = 0x1B;
        next:
            i--;
            if (i >= 0) {
                v = ref_002EF010_00[i];
                if (a0 < v)
                    goto next;
                a0 -= v;
            }
        }
    } else {
        a0 = (a0 < 0xB1) ? a0 : a0 - 0x91;
    }
    return a0;
}
