#include "include_asm.h"

extern int func_002A77E0_3(int x);

INCLUDE_ASM("asm/levels", func_L00_003FEEA0);

INCLUDE_ASM("asm/levels", func_L00_003FF530);

/* takes the float array at +104 and writes four values returned by a call with argument 255, then four float constants (-1.0, -2.25, 1.25, 2.5) at +16..+28, a descending count 255/191/127/63 into the ints at +44..+32 and 2.5/3.0 pairs at +48..+60 */
void func_L00_003FF7B8(char *self)
{
    float *p = *(float **)(self + 104);
    float *q = p;
    int *w;
    int c;
    int i;
    int j;

    for (i = 3; i >= 0; i--)
    {
        *q = (float)func_002A77E0_3(255);
        q++;
    }

    p[4] = -1.0000000000000000000000e+00f;
    p[5] = -2.2500000000000000000000e+00f;
    p[6] = 1.2500000000000000000000e+00f;
    p[7] = 2.5000000000000000000000e+00f;

    j = 3;
    w = (int *)(p + 11);
    c = 255;
    for (; j >= 0; j--)
    {
        *w = c;
        w--;
        c -= 64;
    }

    p[12] = 2.5000000000000000000000e+00f;
    p[13] = 3.0000000000000000000000e+00f;
    p[15] = 2.5000000000000000000000e+00f;
    p[14] = 3.0000000000000000000000e+00f;
}

INCLUDE_ASM("asm/levels", func_L00_003FF890);

INCLUDE_ASM("asm/levels", func_L00_003FFA70);

INCLUDE_ASM("asm/levels", func_L00_003FFBA0);

INCLUDE_ASM("asm/levels", func_L00_004003F0);

INCLUDE_ASM("asm/levels", func_L00_004005B0);

INCLUDE_ASM("asm/levels", func_L00_00400F30);

INCLUDE_ASM("asm/levels", func_L00_00400F38);

INCLUDE_ASM("asm/levels", func_L00_00401168);

INCLUDE_ASM("asm/levels", func_L00_00401668);

INCLUDE_ASM("asm/levels", func_L00_00401D50);

INCLUDE_ASM("asm/levels", func_L00_00401E28);

INCLUDE_ASM("asm/levels", func_L00_00402068);

INCLUDE_ASM("asm/levels", func_L00_004028C0);

INCLUDE_ASM("asm/levels", func_L00_004029E8);

INCLUDE_ASM("asm/levels", func_L00_00402DB8);

INCLUDE_ASM("asm/levels", func_L00_00402DD8);

INCLUDE_ASM("asm/levels", func_L00_00402E50);

INCLUDE_ASM("asm/levels", func_L00_00403730);

INCLUDE_ASM("asm/levels", func_L00_00403BF8);

INCLUDE_ASM("asm/levels", func_L00_00403C30);

INCLUDE_ASM("asm/levels", func_L00_00403CB8);

INCLUDE_ASM("asm/levels", func_L00_00403D58);

INCLUDE_ASM("asm/levels", func_L00_00403F90);

INCLUDE_ASM("asm/levels", func_L00_00404168);

INCLUDE_ASM("asm/levels", func_L00_00404368);

INCLUDE_ASM("asm/levels", func_L00_004045E8);

INCLUDE_ASM("asm/levels", func_L00_00404B48);

INCLUDE_ASM("asm/levels", func_L00_00404DD8);

INCLUDE_ASM("asm/levels", func_L00_00404ED8);

INCLUDE_ASM("asm/levels", func_L00_004051C8);

INCLUDE_ASM("asm/levels", func_L00_00405808);

INCLUDE_ASM("asm/levels", func_L00_00406040);

INCLUDE_ASM("asm/levels", func_L00_00406150);

INCLUDE_ASM("asm/levels", func_L00_00406FB0);

INCLUDE_ASM("asm/levels", func_L00_004073D8);

INCLUDE_ASM("asm/levels", func_L00_004079C8);

INCLUDE_ASM("asm/levels", func_L00_00407C18);

INCLUDE_ASM("asm/levels", func_L00_00407E38);

INCLUDE_ASM("asm/levels", func_L00_00408800);
