/* Near miss for func_0028DF80 (boot 0x0028DF80, 436 bytes, 28 places: boot and 27
 * levels).  Best local check: 444 bytes, `func_0028DF80: 0 of 28 places match`
 * (size differs, so the checker never compares instructions).
 *
 * Retail body, recovered: look the object's record up in the 8-byte-entry table
 * D_001B188C at (s16)object[0]; a tag of 0xFFFF means "no record" and the object's
 * value becomes 0.  Otherwise a four-way switch on the u8 state at +2 selects an
 * animation phase from the record's +4 base, +2 count, +7 period and the object's
 * +0xC clock against the game-time word D_001B1688:
 *   case 0: result = base;
 *   case 1: result = base + (D - clock) / period % count;
 *   case 2: r = (D - clock) / period % (count*2 - 2);
 *           result = base + (r < count ? r : count*2 - (r + 2));
 *   case 3: if (clock < D) { r = (D - clock) / period;
 *               if (r < count*2 - 2) result = base + (r < count ? r : count*2 - (r+2));
 *               else { result = base; clock = 2*count + func_002A77E0(30) + 10; } }
 *           else result = object->value;
 * The shared tail stores result at object+4 and returns it.
 *
 * What this draft reproduces: the whole decision tree, both 8-byte-entry tables,
 * the switch's duplicated default tails and every load/divide/compare, including
 * retail's cross-jumped `base + (count*2 - (r+2))` tail shared by cases 2 and 3.
 *
 * Remaining difference (measured): 444 bytes in 111 instructions against retail's
 * 436/109.  This cc1 gives `rec` the first saved register ($s0) and `result` the
 * second ($s1); retail has result in $s0 and rec in $s1.  With the swap, the two
 * identical case-2/case-3 else tails would also cross-jump into one copy, which is
 * exactly the two instructions of overrun.  The declaration order of result/rec
 * (first, last, initialised) did not change the allocation; the body shapes tried
 * were (a) an `r` local with `if (r >= count) r = ...; result = base + r;` (which
 * this cc1 if-converts to movz where retail branches), and (b) a separate if/else
 * assigning result in each arm (which loads the base twice and does not merge the
 * tails).  The retained draft is (c): both arms write `result` itself, which gives
 * retail's single shared add but still the swapped saved registers.
 *
 * Next experiment: a source shape that raises `result`'s allocation priority above
 * `rec`'s -- e.g. if the original stored the record through a separate local for
 * the tag check only, or if result is live from an earlier point -- with the
 * case-2/case-3 else arms kept identical so the cross-jump can merge them.
 */
extern unsigned short *D_001B188C;

extern int D_001B1688;

extern int func_002A77E0(int);

int func_0028DF80(char *object)
{
    char *rec = (char *)D_001B188C + *(short *)object * 8;
    int result = 0;
    int count;

    if (*(unsigned short *)rec != 0xFFFF) {
        switch (*(unsigned char *)(object + 2)) {
        case 0:
            result = *(unsigned short *)(rec + 4);
            break;
        case 1:
            result = *(unsigned short *)(rec + 4) +
                     ((D_001B1688 - *(int *)(object + 0xC)) / *(unsigned char *)(rec + 7)) %
                     *(unsigned short *)(rec + 2);
            break;
        case 2:
            count = *(unsigned short *)(rec + 2);
            result = ((D_001B1688 - *(int *)(object + 0xC)) / *(unsigned char *)(rec + 7)) % (count * 2 - 2);
            if (result < count)
                result = *(unsigned short *)(rec + 4) + result;
            else
                result = *(unsigned short *)(rec + 4) + (count * 2 - (result + 2));
            break;
        case 3:
            if (*(int *)(object + 0xC) < D_001B1688) {
                count = *(unsigned short *)(rec + 2);
                result = (D_001B1688 - *(int *)(object + 0xC)) / *(unsigned char *)(rec + 7);
                if (result < count * 2 - 2) {
                    if (result < count)
                        result = *(unsigned short *)(rec + 4) + result;
                    else
                        result = *(unsigned short *)(rec + 4) + (count * 2 - (result + 2));
                } else {
                    result = *(unsigned short *)(rec + 4);
                    *(int *)(object + 0xC) = func_002A77E0(30) + 10 + *(unsigned short *)(rec + 2) * 2;
                }
            } else {
                result = *(int *)(object + 4);
            }
            break;
        }
    }
    *(int *)(object + 4) = result;
    return result;
}
