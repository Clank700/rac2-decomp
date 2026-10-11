#include "include_asm.h"

extern int func_00282978_5(char *handle);

extern void func_0029F338_2(char *object);

extern void func_00282CF0_9(char *local, char *first, char *second);

extern void func_00282CC0_15(char *target, char *first, char *local);

#ifndef RAC2_T_VEC16_FC936841D
#define RAC2_T_VEC16_FC936841D
typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec16_Fc936841d;
#endif

INCLUDE_ASM("asm/levels", func_L00_00408E58);

/* shared native body of family af5b3bc3a678ed5c */
void func_L00_00409420(char *object)
{
    char *o = object;
    int *q = *(int **)(o + 104);

    if (*(unsigned char *)(o + 32))
        return;

    q[2] = 64;
    q[4] = 50;
    q[0] = 0;
    q[3] = -1;
    q[5] = 0;
    *(unsigned char *)(o + 32) = 1;
    q[6] = -1;

    *(float *)(o + 44) = *(float *)(*(int *)(o + 36) + 36) * 0.8f;
}

INCLUDE_ASM("asm/levels", func_L00_00409480);

INCLUDE_ASM("asm/levels", func_L00_00409558);

INCLUDE_ASM("asm/levels", func_L00_004096B0);

INCLUDE_ASM("asm/levels", func_L00_00409E48);

INCLUDE_ASM("asm/levels", func_L00_0040A4A8);

INCLUDE_ASM("asm/levels", func_L00_0040AFB8);

INCLUDE_ASM("asm/levels", func_L00_0040B098);

INCLUDE_ASM("asm/levels", func_L00_0040B2C0);

INCLUDE_ASM("asm/levels", func_L00_0040B330);

INCLUDE_ASM("asm/levels", func_L00_0040B398);

INCLUDE_ASM("asm/levels", func_L00_0040B838);

INCLUDE_ASM("asm/levels", func_L00_0040BA30);

INCLUDE_ASM("asm/levels", func_L00_0040C7D8);

INCLUDE_ASM("asm/levels", func_L00_0040CCA0);

INCLUDE_ASM("asm/levels", func_L00_0040D058);

INCLUDE_ASM("asm/levels", func_L00_0040DC08);

/* Tests the handle cached in the object and, while the handle reports itself already released, drops the next sub-handle, otherwise runs the object's destroy helper. */
void func_L00_0040DF00(char *object)
{
    char *handle = *(char **)(object + 104);

    if (func_00282978_5(handle) == 0)
        func_00282978_5(handle + 4);
    else
        func_0029F338_2(object);
}

INCLUDE_ASM("asm/levels", func_L00_0040DF58);

INCLUDE_ASM("asm/levels", func_L00_0040F6A0);

INCLUDE_ASM("asm/levels", func_L00_00410178);

INCLUDE_ASM("asm/levels", func_L00_00410430);

INCLUDE_ASM("asm/levels", func_L00_00410508);

INCLUDE_ASM("asm/levels", func_L00_00410690);

INCLUDE_ASM("asm/levels", func_L00_00410840);

INCLUDE_ASM("asm/levels", func_L00_00410888);

void func_L00_00410D18(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_00410D20);

INCLUDE_ASM("asm/levels", func_L00_004110D8);

INCLUDE_ASM("asm/levels", func_L00_004115A8);

INCLUDE_ASM("asm/levels", func_L00_004115E8);

INCLUDE_ASM("asm/levels", func_L00_004117B8);

INCLUDE_ASM("asm/levels", func_L00_004118A8);

INCLUDE_ASM("asm/levels", func_L00_00411B30);

INCLUDE_ASM("asm/levels", func_L00_00411F48);

/* resets a state record: zero words, plus/minus one float flags and two 64-bit fields in the retail store order */
void func_L00_00412088(char *p)
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

INCLUDE_ASM("asm/levels", func_L00_00412110);

INCLUDE_ASM("asm/levels", func_L00_00412230);

/* Derives a 16-byte element at index-1 from its index-2 and index-3 neighbours through two bound helpers; original game role is unknown. */
void func_L00_00412408(Vec16_Fc936841d *object, int index)
{
    char local[16];

    func_00282CF0_9(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    func_00282CC0_15((char *)&object[index - 1], (char *)&object[index - 2], local);
}
