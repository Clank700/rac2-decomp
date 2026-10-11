#include "include_asm.h"

extern char D_L00_001BF220_1[];

extern void func_00282CF0_7(char *local, char *data);

extern float func_00282DB0_1(char *local, char *p);

extern void func_00282F20_1(char *a0, char *a1, float f);

extern void func_00282D30_5(char *a0, char *a1, float f);

extern void func_00282CC0_4(char *a0, char *a1, char *a2);

extern char D_00189E20_6[];

extern char D_00189EA0[];

extern void func_L00_002DA0B8(char *first, char *second, char *third);

extern float func_00283B98_6(float value, float reference);

extern void func_00283410_5(char *out, char *source);

extern void func_00283678(char *object, char *out);

extern void func_L00_002D7940_1(char *p);

extern void func_L00_002EE0C0(char *p);

extern void func_L00_00427B40_1(char *p);

extern char D_L00_001B8C80_1[];

extern char D_00189E20_3[];

extern float func_00283248_1(float a, float b);

extern float func_00283C80(float a, float b);

extern float func_00282E48(char *a, char *b);

/* Measured partial layouts; original type and game roles are unknown. */
typedef struct Rac2Native_6af85cabb56d3b41_SmallConditional52Owner {
    unsigned char unknown_00[0x7d];
    unsigned char value_7d;
    short value_7e;
    unsigned char unknown_80[6];
    short identity_86;
} Rac2Native_6af85cabb56d3b41_SmallConditional52Owner;

typedef struct Rac2Native_6af85cabb56d3b41_SmallConditional52Global {
    unsigned char unknown_00[0x2294];
    int mode_2294;
    unsigned char unknown_2298[0x208];
    int identity_24a0;
} Rac2Native_6af85cabb56d3b41_SmallConditional52Global;

extern Rac2Native_6af85cabb56d3b41_SmallConditional52Global D_00189E20_20;

INCLUDE_ASM("asm/levels", func_L00_004224D0);

INCLUDE_ASM("asm/levels", func_L00_00423038);

INCLUDE_ASM("asm/levels", func_L00_00423290);

INCLUDE_ASM("asm/levels", func_L00_004233F8);

INCLUDE_ASM("asm/levels", func_L00_004237C8);

INCLUDE_ASM("asm/levels", func_L00_004239A8);

INCLUDE_ASM("asm/levels", func_L00_00423BB0);

INCLUDE_ASM("asm/levels", func_L00_00423BC0);

INCLUDE_ASM("asm/levels", func_L00_00423CA8);

/* Returns 0 unless the second argument equals 1; then it takes a pointer out of the first argument's field at +112, adds 352 to it, passes a 16-byte stack buffer and a data symbol to one routine, passes the same buffer and the shifted pointer to a second routine that returns a float, and returns 1 only when that float is below zero. */
int func_L00_00424070(int a0, int a1)
{
    char local[16];
    int s0;
    int r;

    if (a1 != 1) {
        r = 0;
    } else {
        s0 = *(int *)(a0 + 112) + 352;
        func_00282CF0_7(local, D_L00_001BF220_1);
        r = func_00282DB0_1(local, (char *)s0) < 0.0f ? 1 : 0;
    }
    return r;
}

INCLUDE_ASM("asm/levels", func_L00_004240D8);

INCLUDE_ASM("asm/levels", func_L00_004243C0);

INCLUDE_ASM("asm/levels", func_L00_00424940);

INCLUDE_ASM("asm/levels", func_L00_00424978);

INCLUDE_ASM("asm/levels", func_L00_00424A08);

INCLUDE_ASM("asm/levels", func_L00_00424A50);

INCLUDE_ASM("asm/levels", func_L00_00424A88);

INCLUDE_ASM("asm/levels", func_L00_00424AD8);

INCLUDE_ASM("asm/levels", func_L00_00424B20);

INCLUDE_ASM("asm/levels", func_L00_00424B48);

INCLUDE_ASM("asm/levels", func_L00_00424B70);

INCLUDE_ASM("asm/levels", func_L00_00424BB8);

INCLUDE_ASM("asm/levels", func_L00_00424C00);

INCLUDE_ASM("asm/levels", func_L00_00424C28);

INCLUDE_ASM("asm/levels", func_L00_00424C60);

INCLUDE_ASM("asm/levels", func_L00_00424C90);

INCLUDE_ASM("asm/levels", func_L00_00424EB0);

INCLUDE_ASM("asm/levels", func_L00_00424F00);

INCLUDE_ASM("asm/levels", func_L00_00424F58);

INCLUDE_ASM("asm/levels", func_L00_00424F98);

INCLUDE_ASM("asm/levels", func_L00_00425118);

INCLUDE_ASM("asm/levels", func_L00_00425490);

INCLUDE_ASM("asm/levels", func_L00_00425560);

INCLUDE_ASM("asm/levels", func_L00_00425A98);

INCLUDE_ASM("asm/levels", func_L00_00425CD0);

INCLUDE_ASM("asm/levels", func_L00_00426248);

INCLUDE_ASM("asm/levels", func_L00_00426340);

INCLUDE_ASM("asm/levels", func_L00_004263A8);

INCLUDE_ASM("asm/levels", func_L00_004263B8);

void func_L00_00426478(void)
{
}

/* selects one of three scale factors from a flag byte in a fixed global table, builds two 16-byte stack values through two callees, then applies two transforms rooted at object+48 against two fixed global tables */
void func_L00_00426480(char *object)
{
    char local[16];
    char buf[16];
    char *p = D_00189E20_6;
    unsigned char v;

    func_00282F20_1(local, (char *)(*(int *)(p + 8848) + 224), 1.0f);
    v = *(unsigned char *)(p + 8884);
    if (v == 2) {
        func_00282D30_5(buf, local, 9.5f);
    } else if (v == 1) {
        func_00282D30_5(buf, local, 0.75f);
    } else {
        func_00282D30_5(buf, local, 1.6f);
    }
    func_00282CC0_4(object + 48, D_00189EA0, buf);
    func_00282CC0_4(object + 48, D_00189EA0 + 208, object + 48);
}

INCLUDE_ASM("asm/levels", func_L00_00426560);

INCLUDE_ASM("asm/levels", func_L00_00426680);

INCLUDE_ASM("asm/levels", func_L00_004266E8);

INCLUDE_ASM("asm/levels", func_L00_00426C78);

INCLUDE_ASM("asm/levels", func_L00_00427008);

INCLUDE_ASM("asm/levels", func_L00_00427078);

INCLUDE_ASM("asm/levels", func_L00_004270C0);

INCLUDE_ASM("asm/levels", func_L00_00427290);

INCLUDE_ASM("asm/levels", func_L00_004272A0);

INCLUDE_ASM("asm/levels", func_L00_00427620);

INCLUDE_ASM("asm/levels", func_L00_004276E8);

unsigned int func_L00_00427AD8(void)
{
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_00427AE0);

void func_L00_00427B38(void)
{
}

/* Refreshes a child sub-structure through a setup helper, folds four float pairs (one measured against a fixed half-turn constant) through a shared two-float helper, and hands the resulting four-field block to a second helper. */
void func_L00_00427B40(char *object)
{
    float local[16];
    char *child = *(char **)(object + 112);

    child += 176;
    func_L00_002DA0B8(object + 48, object + 80, child);
    *(float *)(object + 80) = func_00283B98_6(*(float *)(object + 80), *(float *)(child + 24));
    *(int *)(object + 64) = 0;
    *(float *)(object + 68) = func_00283B98_6(*(float *)(object + 84), *(float *)(object + 92));
    *(float *)(object + 72) = func_00283B98_6(3.14159265f, *(float *)(object + 80));
    *(float *)(object + 72) = func_00283B98_6(*(float *)(object + 72), *(float *)(object + 96));
    *(int *)(object + 76) = 0;
    func_00283410_5((char *)local, object + 64);
    func_00283678(object, (char *)local);
}

INCLUDE_ASM("asm/levels", func_L00_00427BE8);

/* resets a sub-object reached through field +112 of its argument: two int zeros through a pointer 176 bytes in, twelve float constants (0.3/0.04/0.07/1.0/0.99) and three int zeros over offsets 40..172, then four calls (sub-object, +80, +144, the argument) and a 16-bit zero at +126 */
void func_L00_00427C78(char *self)
{
    char *q = (char *)*(int **)(self + 112) + 176;
    float *f;

    *(int *)(q + 64) = 0;
    f = (float *)*(int **)(self + 112);
    f[40] = 3.0000001192092895507812e-01f;
    f[41] = 3.0000001192092895507812e-01f;
    f[39] = 0.0f;
    f[42] = 0.0f;
    *(int *)(q + 68) = 0;
    f[43] = 0.0f;
    f[18] = 9.9000000953674316406250e-01f;
    f[15] = 3.9999999105930328369141e-02f;
    f[16] = 3.9999999105930328369141e-02f;
    f[17] = 3.9999999105930328369141e-02f;
    f[10] = 7.0000000298023223876953e-02f;
    f[11] = 1.0000000000000000000000e+00f;
    f[19] = 3.9999999105930328369141e-02f;
    f[12] = 7.0000000298023223876953e-02f;
    f[13] = 1.0000000000000000000000e+00f;
    f[14] = 7.0000000298023223876953e-02f;

    func_L00_002D7940_1((char *)f + 80);
    func_L00_002D7940_1((char *)f);
    func_L00_002EE0C0((char *)f + 144);
    func_L00_00427B40_1(self);

    *(short *)(self + 126) = 0;
}

INCLUDE_ASM("asm/levels", func_L00_00427D50);

INCLUDE_ASM("asm/levels", func_L00_00428000);

INCLUDE_ASM("asm/levels", func_L00_004282F0);

/* Reads two floats from a data block, differences them against two globals, calls a two-float helper with the difference pair, refines the returned float through a second helper, then selects one of two small state codes and clears a flag byte according to two float thresholds. */
void func_L00_004283C8(char *o)
{
    char *B = D_L00_001B8C80_1;
    char *D = D_00189E20_3;
    float *p = *(float **)(D + 8848);
    float r = func_00283C80(*(float *)(B + 344),
                      func_00283248_1(p[4] - *(float *)(B + 320),
                              p[5] - *(float *)(B + 324)));

    if (r < 0.5585054f) {
        r = func_00282E48(D + 128, B + 320);
        if (r < 8.0f) {
            *(char *)(B + 659) = 0;
            *(short *)(o + 126) = 2;
            *(float *)(B + 692) = 0.018f;
            *(float *)(B + 680) = 0.018f;
        } else {
            *(short *)(o + 126) = 4;
        }
    } else {
        *(short *)(o + 126) = 4;
    }
    *(char *)(o + 125) = 0;
}

INCLUDE_ASM("asm/levels", func_L00_004284A8);

INCLUDE_ASM("asm/levels", func_L00_004284B0);

INCLUDE_ASM("asm/levels", func_L00_00428560);

void func_L00_00428580(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_00428588);

INCLUDE_ASM("asm/levels", func_L00_004287E8);

INCLUDE_ASM("asm/levels", func_L00_00428CE0);

INCLUDE_ASM("asm/levels", func_L00_00428EB0);

INCLUDE_ASM("asm/levels", func_L00_00428EE0);

INCLUDE_ASM("asm/levels", func_L00_00428F00);

/* When the global identity differs from the signed owner identity at offset 0x86 and the global mode is not 6, clear the owner byte at offset 0x7D and write signed short value 3 at offset 0x7E. */
void func_L00_00428FE8(Rac2Native_6af85cabb56d3b41_SmallConditional52Owner *owner)
{
    if (D_00189E20_20.identity_24a0 != owner->identity_86 &&
        D_00189E20_20.mode_2294 != 6) {
        owner->value_7d = 0;
        owner->value_7e = 3;
    }
}

INCLUDE_ASM("asm/levels", func_L00_00429020);

INCLUDE_ASM("asm/levels", func_L00_00429048);

INCLUDE_ASM("asm/levels", func_L00_004290C0);

INCLUDE_ASM("asm/levels", func_L00_004291A0);

INCLUDE_ASM("asm/levels", func_L00_00429568);

INCLUDE_ASM("asm/levels", func_L00_00429C18);

void func_L00_00429CE0(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_00429CE8);

INCLUDE_ASM("asm/levels", func_L00_00429F68);

INCLUDE_ASM("asm/levels", func_L00_0042A460);

INCLUDE_ASM("asm/levels", func_L00_0042A4E8);

INCLUDE_ASM("asm/levels", func_L00_0042A500);

INCLUDE_ASM("asm/levels", func_L00_0042A520);

INCLUDE_ASM("asm/levels", func_L00_0042A698);
