/* Near miss: two-line option row (y = 0x96 and 0xBE), built from one shared text
 * pair and the "%s: %s" format at D_L00_001ADDD0/D_L00_001ADDD8.
 *
 * wslcmp (boot): 0 of 28 places. The body is retail's line for line - the
 * 0x80D0D0D0/0x70808080 pair selected per line, the two func_00288FB8 string
 * ids (0x2DDF then 0x2DDE), the 0x1A7B95/0x1A7B94 index flags and the two
 * func_0027FAA8 draws - but the whole callee-saved allocation is shifted by one:
 * retail keeps `object` in $s6, the pair base in $s4, the format in $s5 and the
 * first string in $s2; this source gets $s5/$s3/$s4/$s7. The matched one-line
 * sibling func_0033D638 in the same file shows the shape (declaration order
 * buffer, pair, first, second, format, color) but does not reproduce it here.
 * Reopen by finding the declaration/statement order that gives the parameter $s6.
 */
typedef struct { int ids[2]; } SolTextPair2;
extern SolTextPair2 D_L00_001ADDD0;
extern char D_L00_001ADDD8[];
extern void func_0033AF48(void *);
extern char *func_00288FB8(int);
extern int func_00115DA8(char *, const char *, ...);
extern void func_0027FAA8(int, int, unsigned long, char *, int);

void func_0033CC20(char *object)
{
    char buffer[128];
    SolTextPair2 pair;
    char *first;
    char *second;
    char *format;
    int color;

    func_0033AF48(object + 8);
    color = *(int *)(object + 0x2A8) == 0 ? (int)0x80D0D0D0 : 0x70808080;
    pair = D_L00_001ADDD0;
    format = D_L00_001ADDD8;
    first = func_00288FB8(0x2DDF);
    second = func_00288FB8(pair.ids[*(unsigned char *)0x001A7B95 != 0]);
    func_00115DA8(buffer, format, first, second);
    func_0027FAA8(0x100, 0x96, color, buffer, -1);

    color = *(int *)(object + 0x2A8) == 1 ? (int)0x80D0D0D0 : 0x70808080;
    first = func_00288FB8(0x2DDE);
    second = func_00288FB8(pair.ids[*(unsigned char *)0x001A7B94 != 0]);
    func_00115DA8(buffer, format, first, second);
    func_0027FAA8(0x100, 0xBE, color, buffer, -1);
}
