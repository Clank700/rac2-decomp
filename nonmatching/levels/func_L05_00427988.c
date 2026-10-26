/* Mid worker 7: near miss, flags -O2 -G8 -g -ffunction-sections -frac2-qcopy (own file L05_00427988-g8.c).
   Structure, gp loads, the flag ternaries, the lq/sq copy and all calls match; 412 B vs 404 B. Residual: the six
   stores into the state record come out in a different order than retail (0x18,0x28,0x10,0x20,0x14,0x1C; tried all 720
   source orders, none gives it), which keeps the arguments live one register longer (s7 used) and hoists
   `addiu s1,s3,0xC0` into the divide-latency slot instead of retail's call delay slot. */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char *func_328508(int id);
extern int func_307778(float value);
extern void func_003068F8(char *dst, char *src, float scale);
extern void func_00306748(char *dst, char *a, char *b);
extern float D_L05_001B154C __attribute__((sda));
extern float D_L05_001B1550 __attribute__((sda));
extern int D_L05_001B1554 __attribute__((sda));
extern float D_L05_001B155C __attribute__((sda));
extern float D_L05_001B1560 __attribute__((sda));

char *func_L05_00427988(char *pos, char *vec, int a2, char *a3, int flag)
{
    char *obj = func_328508(0x1191);

    if (obj != 0) {
        char *st = *(char **)(obj + 0x68);
        float f20;
        float f21;
        float f22;

        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0x1FF;
        *(unsigned char *)(obj + 0x20) = 1;
        *(unsigned char *)(obj + 0x31) = 1;
        *(int *)(st + 0x24) = flag;
        f22 = (flag ? D_L05_001B1550 : D_L05_001B154C) * (1.0f / 120.0f);
        f21 = (flag ? D_L05_001B1560 : D_L05_001B155C) / f22;
        f20 = 1.0f;
        *(int *)(st + 0x18) = func_307778(f21);
        *(int *)(st + 0x28) = D_L05_001B1554;
        *(int *)(st + 0x10) = a2;
        *(char **)(st + 0x20) = a3;
        *(int *)(st + 0x14) = 0;
        *(float *)(st + 0x1C) = f20 / f21;
        *(unsigned short *)(obj + 0x34) = *(unsigned short *)(obj + 0x34) | 0x100;
        *(TI128 *)(obj + 0x10) = *(TI128 *)pos;
        func_003068F8(st, vec, f22);
        func_003068F8(obj + 0xC0, st, f20);
        func_00306748(obj + 0xD0, obj + 0xC0, a3 + 0xE0);
        func_003068F8(obj + 0xD0, obj + 0xD0, f20);
        func_00306748(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    }
    return obj;
}
