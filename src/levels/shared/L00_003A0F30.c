#include "include_asm.h"

extern float func_00283B98_2(float, float);

extern float func_00283180(float);

extern float func_00283198(float);

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

INCLUDE_ASM("asm/levels", func_L00_003A0F30);

INCLUDE_ASM("asm/levels", func_L00_003A1580);

INCLUDE_ASM("asm/levels", func_L00_003A1F68);

INCLUDE_ASM("asm/levels", func_L00_003A2018);

/* Shared native body; original game role is unknown. */
void func_L00_003A2138(int unused, float *p, int n)
{
    float *v;
    int count;
    if (n <= 0)
        return;
    v = p;
    count = n;
    do {
        v[0] = func_00283B98_2(v[0], v[3]);
        v[1] = func_00283B98_2(v[1], v[4]);
        v[2] = func_00283B98_2(v[2], v[5]);
        v[9] = func_00283B98_2(v[9], v[12]);
        v[10] = func_00283B98_2(v[10], v[13]);
        v[11] = func_00283B98_2(v[11], v[14]);
        v[20] = func_00283180(v[0]) * v[6];
        v[21] = func_00283198(v[1]) * v[7];
        v[22] = -func_00283198(v[2]) * v[8];
        v[24] = func_00283180(v[9]) * v[15];
        v[25] = func_00283198(v[10]) * v[16];
        v[26] = -func_00283198(v[11]) * v[17];
        v += 32;
    } while (--count != 0);
}

INCLUDE_ASM("asm/levels", func_L00_003A2258);

INCLUDE_ASM("asm/levels", func_L00_003A2400);

INCLUDE_ASM("asm/levels", func_L00_003A2408);

/* Derives a 16-byte element at index-1 from its index-2 and index-3 neighbours through two bound helpers; original game role is unknown. */
void func_L00_003A2570(Vec16_Fc936841d *object, int index)
{
    char local[16];

    func_00282CF0_9(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    func_00282CC0_15((char *)&object[index - 1], (char *)&object[index - 2], local);
}

INCLUDE_ASM("asm/levels", func_L00_003A25D8);

INCLUDE_ASM("asm/levels", func_L00_003A2668);

INCLUDE_ASM("asm/levels", func_L00_003A2B20);

/* straight-line constant-store body (no calls, no branches, no loads) */
void func_L00_003A2B28(char *p)
{
    *(long long *)(p + 112) = 0LL;
    *(int *)(p + 80) = 0;
    *(int *)(p + 88) = 0;
    *(float *)(p + 96) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(int *)(p + 84) = 0;
    *(float *)(p + 92) = 1.0f;
    *(int *)(p + 100) = 0;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long long *)(p + 128) = 280993940374112LL;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/levels", func_L00_003A2BB8);

INCLUDE_ASM("asm/levels", func_L00_003A2C60);

INCLUDE_ASM("asm/levels", func_L00_003A2EE0);

INCLUDE_ASM("asm/levels", func_L00_003A3B58);

INCLUDE_ASM("asm/levels", func_L00_003A3F30);

INCLUDE_ASM("asm/levels", func_L00_003A41F0);

INCLUDE_ASM("asm/levels", func_L00_003A4480);

INCLUDE_ASM("asm/levels", func_L00_003A48D0);

INCLUDE_ASM("asm/levels", func_L00_003A5368);

INCLUDE_ASM("asm/levels", func_L00_003A5370);

INCLUDE_ASM("asm/levels", func_L00_003A53E8);

INCLUDE_ASM("asm/levels", func_L00_003A5DC0);

INCLUDE_ASM("asm/levels", func_L00_003A5FC0);

INCLUDE_ASM("asm/levels", func_L00_003A6538);

INCLUDE_ASM("asm/levels", func_L00_003A6C30);

INCLUDE_ASM("asm/levels", func_L00_003A78B0);

INCLUDE_ASM("asm/levels", func_L00_003A7AF0);

INCLUDE_ASM("asm/levels", func_L00_003A7C30);

INCLUDE_ASM("asm/levels", func_L00_003A7E78);

INCLUDE_ASM("asm/levels", func_L00_003A8060);

INCLUDE_ASM("asm/levels", func_L00_003A80F8);

INCLUDE_ASM("asm/levels", func_L00_003A8238);

INCLUDE_ASM("asm/levels", func_L00_003A8508);

INCLUDE_ASM("asm/levels", func_L00_003A85A0);

INCLUDE_ASM("asm/levels", func_L00_003A8618);

INCLUDE_ASM("asm/levels", func_L00_003A8670);

INCLUDE_ASM("asm/levels", func_L00_003A87D8);

INCLUDE_ASM("asm/levels", func_L00_003A8940);
