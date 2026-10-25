/* Retained manual C reconstruction; not linked or counted.
 * Retail: 576 bytes, 1 place (14:00423000).
 * Checked trial profile: -O2 -G0 -ffunction-sections -frac2-qcopy.
 * us: 0/1 placements; the candidate also reaches 576 bytes without -frac2-qcopy, and
 * 620 bytes with -O1.
 * Residual: the whole field list and both call sites are present and the frame/size agree
 * with -frac2-qcopy, but the independent field stores are emitted in a different order
 * (first difference +0x2c) and the entry float constants are materialised in another
 * order (retail loads 0.5f before 0.1f and 1/240 before 1/120). The tail's n==3 guard is
 * also laid out differently (retail uses beql for the 0x730 == -1 test).
 * Reopen with the original statement order for the field block, or measured evidence that
 * retail's schedule is reachable from a grouped source; no artificial barriers.
 *
 * The ASM marker was restored in src/levels/14_aranos_prison/L14_003F4F98.c after the checks.
 */

typedef int L14_TI128 __attribute__((mode(TI)));

extern void func_335B78(float, float, float, float);
extern int func_331260(char *, int, void *, int);
extern int func_322028(int);
extern void func_321F58(char *, int, int);

typedef struct {
    unsigned char pad00[0x20];
    float f20;
    unsigned short h24;
    unsigned char pad26[0x28 - 0x26];
    unsigned char b28;
    unsigned char pad29[0x70 - 0x29];
    unsigned char b70;
    unsigned char b71;
    unsigned char b72;
    unsigned char pad73[0x76 - 0x73];
    unsigned char b76;
    unsigned char b77;
    unsigned char pad78[0x7C - 0x78];
    float f7C;
    float f80;
    float f84;
    float f88;
    float f8C;
    float f90;
    float f94;
    unsigned char pad98[0x9C - 0x98];
    float f9C;
    unsigned char padA0[0xA8 - 0xA0];
    int iA8;
    unsigned char padAC[0xCC - 0xAC];
    unsigned char bCC;
    unsigned char bCD;
    unsigned char bCE;
    unsigned char bCF;
    unsigned char padD0[0xD2 - 0xD0];
    unsigned char bD2;
    unsigned char bD3;
    unsigned char padD4[0x110 - 0xD4];
    float f110;
    float f114;
    float f118;
    float f11C;
    float f120;
    unsigned char pad124[0x13C - 0x124];
    float f13C;
    float f140;
    float f144;
    unsigned char pad148[0x14C - 0x148];
    int i14C;
    unsigned char pad150[0x158 - 0x150];
    char *p158;
    char *p15C;
    unsigned char pad160[0x200 - 0x160];
    char area200[0x100];
    char pad300[0x600 - 0x300];
    char area600[0x80];
    char area680[0x90];
    L14_TI128 vec710;
    unsigned char pad720[0x730 - 0x720];
    int i730;
    int i738;
    int i73C;
    float f740;
    unsigned char pad744[0x750 - 0x744];
    int i750;
    unsigned char pad754[0x774 - 0x754];
    short h774;
    unsigned char pad776[0x77C - 0x776];
    short h77C;
} L14State_423000;

void func_L14_00423000(char *a0)
{
    L14State_423000 *s = *(L14State_423000 **)(a0 + 0x68);
    short n;

    s->b70 = 8;
    s->iA8 = 4;
    s->f80 = 0.06666667014360428f;
    s->b76 = 0x12;
    s->f88 = 0.008333333767950535f;
    s->f20 = 16.0f;
    s->b72 = 0x11;
    s->b77 = 0x13;
    s->f8C = 0.004166666883975267f;
    s->bCF = 6;
    s->bD2 = 0xD;
    s->bD3 = 0x1A;
    s->h24 = 0x10;
    s->b28 = 3;
    s->b71 = 0x11;
    s->f7C = 0.10000000894069672f;
    s->f84 = 0.004166666883975267f;
    s->f90 = 0.5f;
    s->f94 = 0.5f;
    s->f9C = 0.4000000059604645f;
    s->bCC = 3;
    s->bCD = 6;
    s->bCE = 3;
    *(unsigned char *)(a0 + 0x30) = 0xC8;
    *(unsigned short *)(a0 + 0x32) = 0xC8;
    s->f144 = 0.25f;
    s->f110 = 0.4000000059604645f;
    s->f11C = 0.5f;
    s->f140 = 0.2617994248867035f;
    s->f13C = 0.0055555556900799274f;
    s->f114 = 0.5f;
    s->f118 = 0.5f;
    s->i14C = -1;
    s->f120 = 3.141590118408203f;
    func_335B78(0.0033333334140479565f, 0.10000000894069672f,
                0.0034906589426100254f, 0.20943954586982727f);

    s->f740 = s->f740 * 0.01745329424738884f;
    s->p158 = s->area680;
    s->p15C = s->area600;
    if (s->i738 != -1)
        s->i14C = s->i738;
    s->i750 = func_331260(a0, s->i73C, s->area200, 0x20);
    s->h77C = func_322028(2);

    s->vec710 = *(L14_TI128 *)(a0 + 0x10);

    n = s->h774;
    if (n > 0) {
        if (n != 3)
            func_321F58(a0, n, 1);
        else if (s->i730 != -1)
            func_321F58(a0, 3, 1);
        else
            func_321F58(a0, 1, 1);
    } else {
        func_321F58(a0, 1, 1);
    }
}
