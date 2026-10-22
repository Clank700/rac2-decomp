#include "include_asm.h"

/* func_L00_00403D58 and func_L00_00404DD8 are a unit of their own: both need the opt-in
   quadword-copy profile and its scheduling barrier (-frac2-qcopy -frac2-qcopy-barrier,
   config/cflags.txt), which give retail's grouped `lq`/`sq` with register addresses and
   keep the instructions around the copy on their own side of it. */

typedef int TI128 __attribute__((mode(TI)));

extern void func_002EE108(char *a, int *b, char *c);
extern void func_0037F9A0(char *a, char *b);
extern void func_0037E1D8(int a, int *b, int c);
extern int func_002EDD48(char *a);
extern void func_002E6EF8(void (*f)(char *), char *arg);
extern void func_L00_00404168(char *arg);
extern void func_L00_00403F90(char *arg, void *p);
extern void func_0037E1B8(int a);
extern void func_00310440(char *arg);

void func_L00_00403D58(char *arg)
{
    int *o = *(int **)(arg + 104);
    unsigned char state = *(unsigned char *)(arg + 32);
    TI128 tmp;
    char *p;

    switch (state) {
    case 0:
        arg[32] = 1;
    case 1:
        p = arg + 16;
        *(TI128 *)&tmp = *(TI128 *)p;
        func_002EE108(p, o, p);
        func_0037F9A0(p, p);
        func_0037E1D8(o[7], o, 0);
        func_L00_00403F90(arg, &tmp);
        if (func_002EDD48((char *)o + 16) != 0)
            arg[32] = 2;
        break;
    case 2:
        func_0037E1B8(o[7]);
        func_00310440(arg);
        return;
    default:
        break;
    }
    func_002E6EF8(func_L00_00404168, arg);
}

extern void func_0035F450(int a, int b, void *c, int d);
extern int func_002DE4B0(void *a, void *b, int c, void *d, int e);
extern void func_00310440(char *arg);
extern TI128 D_L00_001BF220;

void func_L00_00404DD8(char *arg, void *a1)
{
    char *p;

    if (*(float *)(arg + 16) < 2.0f || *(float *)(arg + 16) > 1021.0f ||
        *(float *)(arg + 20) < 2.0f || *(float *)(arg + 20) > 1021.0f ||
        *(float *)(arg + 24) < 2.0f || *(float *)(arg + 24) > 1021.0f) {
        func_00310440(arg);
        return;
    }
    p = arg + 16;
    if (func_002DE4B0(a1, p, 0, arg, 0) != 0) {
        *(TI128 *)p = D_L00_001BF220;
        arg[32] = 2;
        func_0035F450(5, 0, arg, 3705);
    }
}
