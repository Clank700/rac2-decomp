#include "include_asm.h"

extern float D_L00_001AFA40 __attribute__((sda));

typedef struct OBJ2 {
    char pad0[0x28];
    int f28;
    char pad1[0x68 - 0x2C];
    struct OBJ2 *f68;
} OBJ2;

extern OBJ2 *D_L00_001AFBC0 __attribute__((sda));

typedef struct OBJ3 {
    char pad0[0x98];
    int f98;
} OBJ3;

extern int D_L00_001AFD7C __attribute__((sda));

extern OBJ3 *D_L00_0023DBA0[];

extern int D_L00_0023DCA0[];

void func_L00_003B7260(float x, float y, float *p, float *q)
{
    float s = -(D_L00_001AFA40 * 0.000277777785f) / (x * x + y * y);

    *p = *p + x * s;
    *q = *q + y * s;
}

void func_L00_003B8138(void)
{
    OBJ2 *p = D_L00_001AFBC0;
    if (p != 0)
        p->f68->f28 = 1;
}

void func_L00_003B92D0(void)
{
    int n = D_L00_001AFD7C;
    int i;

    for (i = 0; i < n; i++)
        D_L00_0023DBA0[i]->f98 = D_L00_0023DCA0[i];
}
