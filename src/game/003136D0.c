#include "include_asm.h"

extern void Fc936841d_FUN_00282CF0(char *local, char *first, char *second);

extern void Fc936841d_FUN_00282CC0(char *target, char *first, char *local);

#ifndef RAC2_T_VEC16_FC936841D
#define RAC2_T_VEC16_FC936841D
typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec16_Fc936841d;
#endif

extern char F669d6320_D_001BAFC0[];

extern void F669d6320_FUN_00282F20(void *out, void *in, float scale);

extern void F669d6320_FUN_00282CC0(void *out, void *in1, void *in2);

extern int F669d6320_FUN_002761F8(void *a, void *b, int mode, void *self, int flag);

extern void F669d6320_FUN_00282D30(void *out, void *in, float scale);

INCLUDE_ASM("asm/game", func_003136D0);

INCLUDE_ASM("asm/game", func_003146C0);

INCLUDE_ASM("asm/game", func_00314CF8);

INCLUDE_ASM("asm/game", func_00314E28);

INCLUDE_ASM("asm/game", func_00314FD0);

INCLUDE_ASM("asm/game", func_00315890);

INCLUDE_ASM("asm/game", func_003158A8);

INCLUDE_ASM("asm/game", func_003159D0);

INCLUDE_ASM("asm/game", func_00315C50);

INCLUDE_ASM("asm/game", func_00315C78);

INCLUDE_ASM("asm/game", func_00315E20);

INCLUDE_ASM("asm/game", func_00316248);

INCLUDE_ASM("asm/game", func_00316400);

INCLUDE_ASM("asm/game", func_003166C8);

INCLUDE_ASM("asm/game", func_003169D0);

void func_00316B40(char *p)
{
    *(long long *)(p + 112) = 0LL;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -1.0f;
    *(float *)(p + 24) = 1.0f;
    *(float *)(p + 40) = -1.0f;
    *(float *)(p + 56) = 1.0f;
    *(float *)(p + 4) = -1.0f;
    *(float *)(p + 36) = 1.0f;
    *(float *)(p + 52) = 1.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long long *)(p + 128) = 280993940374112LL;
    *(float *)(p + 20) = -1.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/game", func_00316BC8);

void func_00316DA0(Vec16_Fc936841d *object, int index)
{
    char local[16];

    Fc936841d_FUN_00282CF0(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    Fc936841d_FUN_00282CC0((char *)&object[index - 1], (char *)&object[index - 2], local);
}

INCLUDE_ASM("asm/game", func_00316E08);

INCLUDE_ASM("asm/game", func_003172D0);

INCLUDE_ASM("asm/game", func_00317390);

INCLUDE_ASM("asm/game", func_003173B0);

INCLUDE_ASM("asm/game", func_00317D78);

INCLUDE_ASM("asm/game", func_003181E0);

INCLUDE_ASM("asm/game", func_00318200);

INCLUDE_ASM("asm/game", func_003182C0);

INCLUDE_ASM("asm/game", func_00318340);

INCLUDE_ASM("asm/game", func_00319780);

INCLUDE_ASM("asm/game", func_00319B38);

INCLUDE_ASM("asm/game", func_00319EC0);

INCLUDE_ASM("asm/game", func_00319F38);

INCLUDE_ASM("asm/game", func_00319FB8);

INCLUDE_ASM("asm/game", func_0031A098);

INCLUDE_ASM("asm/game", func_0031A158);

INCLUDE_ASM("asm/game", func_0031A340);

INCLUDE_ASM("asm/game", func_0031A580);

INCLUDE_ASM("asm/game", func_0031A628);

INCLUDE_ASM("asm/game", func_0031A708);

INCLUDE_ASM("asm/game", func_0031A718);

INCLUDE_ASM("asm/game", func_0031A848);

void func_0031A998(char *self, char *p1, int p2)
{
    float a[4];
    float b[4];

    F669d6320_FUN_00282F20(a, self + 224, 0.1f);
    F669d6320_FUN_00282F20(b, self + 224, -3.0f);
    F669d6320_FUN_00282CC0(a, a, self + 16);
    F669d6320_FUN_00282CC0(b, b, self + 16);

    if (F669d6320_FUN_002761F8(a, b, 2, self, 0))
        F669d6320_FUN_00282F20(p1, F669d6320_D_001BAFC0, 1.0f);
    else
        F669d6320_FUN_00282F20(p1, self + 224, -1.0f);

    if (p2 == 0)
        F669d6320_FUN_00282D30(p1, p1, -1.0f);
}

INCLUDE_ASM("asm/game", func_0031AAB0);

unsigned int func_0031AB08(unsigned int param_1)
{
    unsigned int inner_ptr;
    unsigned int result;

    inner_ptr = *(unsigned int *)(param_1 + 0x68);
    result = *(unsigned int *)(inner_ptr + 0x18);
    return result;
}

INCLUDE_ASM("asm/game", func_0031AB18);
