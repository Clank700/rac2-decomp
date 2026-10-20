/* 332 bytes against retail's 336 (0 of 28 places); from src/game/0033BE98.c, default flags.
   What differs is the float section: retail loads x into $f1, keeps 170.0f in $f0 and 0.5f in $f2, and
   has a nop between the mtc1 of 379.0f and the mul.s that reads it. This build puts x in $f0, hoists the
   constants, and has no such nop, so it is 4 bytes short. Tried: operands swapped, 0.5f on the other side
   of the add, the two conversions in locals, -mno-split-addresses (320 bytes). Prologue, calls, and the
   struct copy match. */
struct SolIds {
    int ids[2];
};
extern struct SolIds D_001ADDD0;
extern char D_001ADDD8[];
extern int D_001A7340;
extern int D_001A7BB8;
extern float D_001B23A4 __attribute__((sda));
extern void func_0033AF48(void *);
extern char *func_00288FB8(int);
extern int func_00115DA8(char *, const char *, ...);
extern void func_0027FAA8(int, int, unsigned long, char *, int);
extern void func_002802E0(void *, int, int, int, int, int, int, int, int);
extern void func_00280190(void *, unsigned long, int, int);

void func_0033C028(char *object)
{
    char buffer[64];
    struct SolIds pair;
    char scratch[32];
    char *format;
    char *first;
    char *second;
    float x;

    func_0033AF48(object + 8);
    pair = D_001ADDD0;
    format = D_001ADDD8;
    first = func_00288FB8(0x31E5);
    second = func_00288FB8(pair.ids[D_001A7BB8 != 0]);
    func_00115DA8(buffer, format, first, second);
    func_0027FAA8(D_001A7340 >> 1, 0x8C, 0x80F0F0F0UL, buffer, -1);
    x = D_001B23A4;
    func_002802E0(scratch, (int)(x * 170.0f + 0.5f), (int)(x * 379.0f + 0.5f), 44, 468, 254, 222, 20, 3);
    func_00280190(scratch, 0x80F0F0F0UL, func_00288FB8(0x32A8), -1);
}
