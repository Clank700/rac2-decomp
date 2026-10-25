/* 0 of 2 places match - last line: 08_tabora and 17_smolg: instruction at +0x60 differs
   (544 bytes, the same size as retail). The state-4 guard, the aim helper's distance
   and its per-frame step, the 0x78/0x7C turn pair scaled through func_32A4D0 (the
   16-byte input block is a TImode copy of s2+0x10 and the helper's float result is
   the first half of a four-float local, index 0 in the turn branch and index 1 in the
   state-4 branch), the 1.0f <= distance test with its func_327478(self, 2, 0, 0),
   the state-4 flags/0xFA/0xB0/0xB4 stores and the func_326C60 tail all match.
   Remaining difference: at +0x60 the outer `0.0f < distance` branch delay slot holds
   `addiu $a1,$s0,0x50` in retail (the false path calls func_32D090 with s0 + 0x50)
   where this C gives `addiu $v0,$zero,0xFF`, and the final `sb self[0xA8]` /
   `a1 = s0` order in the func_32D090 block is swapped with it. Written as a shared
   tail with `s0 += 0x50` in both arms the cc1 emits a bc1fl and 552 bytes; as two
   separate tails it does not merge and gives 568. Next: a source shape that makes
   the false path pass `s0 + 0x50` while the true path increments s0 and both share
   one func_32D090 call. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern char *func_32A170(char *, int, int);
extern float func_32A1D0(char *, void *);
extern void func_32A4D0(char *, char *, char *, char *);
extern void func_32C0D8(char *, char *, int, int, int, float);
extern void func_327478(char *, int, int, int);
extern void func_326C60(char *, int, int);
extern void func_32CFD0(char *, char *);
extern void func_32D090(char *, char *);

void func_L08_003F6348(char *self, char *a1)
{
    char *s0 = a1;
    char *s2;
    struct { TI128 in; float out[4]; } l;
    float v;
    float f;

    if (*(u8 *)(self + 0x20) == 4)
        return;
    s2 = func_32A170(self, 0xC30000, 0);
    f = func_32A1D0(self, s2);
    if (0.0f < f) {
        v = *(float *)(s0 + 0x20) - *(float *)(s2 + 0x2C);
        *(float *)(s0 + 0x20) = v;
        if (0.0f < v) {
            *(float *)(s0 + 0x78) = 0.13333334028720856f;
            *(float *)(s0 + 0x7C) = 0.11666667461395264f;
            l.in = *(TI128 *)(s2 + 0x10);
            func_32A4D0((char *)&l.in, (char *)l.out, s0 + 0x78, s0 + 0x7C);
            func_32C0D8(self, s0 + 0x60, 3, 1, 0, l.out[0]);
            if (1.0f <= f) {
                *(u8 *)(s0 + 0x57) = 0x78;
                *(u8 *)(self + 0x20) = 3;
                func_327478(self, 2, 0, 0);
            } else {
                *(u8 *)(s0 + 0x57) = 0x78;
            }
        } else {
            *(u16 *)(self + 0x34) &= 0xEFFF;
            *(u8 *)(s0 + 0x57) = 0xFA;
            *(u8 *)(self + 0x20) = 4;
            *(float *)(s0 + 0x78) = 0.18333333730697632f;
            *(float *)(s0 + 0x7C) = 0.11666667461395264f;
            l.in = *(TI128 *)(s2 + 0x10);
            func_32A4D0((char *)&l.in, (char *)(l.out + 1), s0 + 0x78, s0 + 0x7C);
            func_32C0D8(self, s0 + 0x60, 3, 1, 0, l.out[1]);
            *(float *)(s0 + 0xB0) = 5.0f;
            *(float *)(s0 + 0xB4) = 10.0f;
            if (*(u8 *)(self + 0x43) != 3)
                func_327478(self, 3, 0, 0);
            func_326C60(self, 0, 3);
        }
        s0 += 0x50;
        func_32CFD0(self, s0);
    }
    *(u8 *)(self + 0xA8) = 0xFF;
    func_32D090(self, s0);
}

