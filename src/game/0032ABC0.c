#include "include_asm.h"

extern void F2c74c194_FUN_00282D30(char *dst, char *src, float scale);

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

typedef unsigned char u8;

typedef int s32;

/* Finds the first matching object in the thirty resident records. */
typedef struct {
    u8 field00[0x14];
    void *field14;
    u8 field18[8];
} NativeObjectSearchRecord32;

extern NativeObjectSearchRecord32 D_L00_002533B0[];

INCLUDE_ASM("asm/game", func_0032ABC0);

INCLUDE_ASM("asm/game", func_0032ACF0);

INCLUDE_ASM("asm/game", func_0032AE30);

INCLUDE_ASM("asm/game", func_0032AF50);

INCLUDE_ASM("asm/game", func_0032B0A8);

INCLUDE_ASM("asm/game", func_0032B190);

void func_0032B2F0(char *p)
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

void func_0032B378(char *p, float scale)
{
    F2c74c194_FUN_00282D30(p, p, scale);
    F2c74c194_FUN_00282D30(p + 16, p + 16, scale);
    F2c74c194_FUN_00282D30(p + 32, p + 32, scale);
    F2c74c194_FUN_00282D30(p + 48, p + 48, scale);
}

INCLUDE_ASM("asm/game", func_0032B3E0);

INCLUDE_ASM("asm/game", func_0032B598);

INCLUDE_ASM("asm/game", func_0032B7D0);

INCLUDE_ASM("asm/game", func_0032BA88);

INCLUDE_ASM("asm/game", func_0032BBF0);

void func_0032BDC8(Vec16_Fc936841d *object, int index)
{
    char local[16];

    Fc936841d_FUN_00282CF0(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    Fc936841d_FUN_00282CC0((char *)&object[index - 1], (char *)&object[index - 2], local);
}

INCLUDE_ASM("asm/game", func_0032BE30);

INCLUDE_ASM("asm/game", func_0032C2E8);

INCLUDE_ASM("asm/game", func_0032C688);

INCLUDE_ASM("asm/game", func_0032C700);

INCLUDE_ASM("asm/game", func_0032CA40);

INCLUDE_ASM("asm/game", func_0032D6F0);

/* finds the first matching object pointer in thirty resident32-byte records or returns-1 */
s32 func_0032D700(void *object) {
    s32 result = -1;
    s32 index;
    for (index = 0; index < 30; index++) {
        if (D_L00_002533B0[index].field14 == object) {
            result = index;
            break;
        }
    }
    return result;
}

INCLUDE_ASM("asm/game", func_0032D758);

INCLUDE_ASM("asm/game", func_0032DA50);

INCLUDE_ASM("asm/game", func_0032DA58);

INCLUDE_ASM("asm/game", func_0032DD40);

INCLUDE_ASM("asm/game", func_0032E4E8);

INCLUDE_ASM("asm/game", func_0032E4F0);

INCLUDE_ASM("asm/game", func_0032E568);

INCLUDE_ASM("asm/game", func_0032E588);

INCLUDE_ASM("asm/game", func_0032E700);

INCLUDE_ASM("asm/game", func_0032EB28);

INCLUDE_ASM("asm/game", func_0032F3D0);

INCLUDE_ASM("asm/game", func_0032F590);

INCLUDE_ASM("asm/game", func_0032F598);

INCLUDE_ASM("asm/game", func_0032FDC0);

INCLUDE_ASM("asm/game", func_0032FDD0);

INCLUDE_ASM("asm/game", func_0032FEA8);

INCLUDE_ASM("asm/game", func_0032FFD8);

INCLUDE_ASM("asm/game", func_00330150);

INCLUDE_ASM("asm/game", func_003304D8);

INCLUDE_ASM("asm/game", func_003309A0);

INCLUDE_ASM("asm/game", func_00330BC0);

INCLUDE_ASM("asm/game", func_00330CA0);

INCLUDE_ASM("asm/game", func_00330E48);

INCLUDE_ASM("asm/game", func_00330EC0);

INCLUDE_ASM("asm/game", func_00331238);

INCLUDE_ASM("asm/game", func_003313E0);

INCLUDE_ASM("asm/game", func_00331580);

INCLUDE_ASM("asm/game", func_00331718);

INCLUDE_ASM("asm/game", func_003317E0);

INCLUDE_ASM("asm/game", func_00331800);

INCLUDE_ASM("asm/game", func_003320E8);

INCLUDE_ASM("asm/game", func_003320F0);

INCLUDE_ASM("asm/game", func_003323F0);

INCLUDE_ASM("asm/game", func_00332440);

INCLUDE_ASM("asm/game", func_00332588);

INCLUDE_ASM("asm/game", func_00332590);
