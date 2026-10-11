#include "include_asm.h"

extern void func_002833F0_1(char *a, char *b);

extern float func_00283198_1(float value);

extern void func_00282D30_3(char *a, char *b, float value);

extern float func_00283B98_3(float value, float scale);

extern int func_002ABB78(char *object);

extern float *func_002AB1F0(char *object);

/* Measured partial layouts; original type and game roles are unknown. */
typedef struct Rac2Native_9cdc323a4d0c2fbd_AnalysisOwner {
    unsigned char prefix_00[0x68];
    void *context_68;
} Rac2Native_9cdc323a4d0c2fbd_AnalysisOwner;

typedef struct Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext {
    unsigned char prefix_00[0x10];
    float vector_10[4];
    unsigned int field_20;
    unsigned int active_24;
} Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext;

extern void func_002FDBD8_5(float scale, Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context,
                                    float *vector, int mode);

extern void func_00282D30_2(char *dst, char *src, float scale);

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

INCLUDE_ASM("asm/levels", func_L00_003EB8E8);

INCLUDE_ASM("asm/levels", func_L00_003EBC68);

INCLUDE_ASM("asm/levels", func_L00_003EC078);

INCLUDE_ASM("asm/levels", func_L00_003EC140);

INCLUDE_ASM("asm/levels", func_L00_003ECB00);

INCLUDE_ASM("asm/levels", func_L00_003ECB38);

INCLUDE_ASM("asm/levels", func_L00_003ECC88);

INCLUDE_ASM("asm/levels", func_L00_003ECC90);

INCLUDE_ASM("asm/levels", func_L00_003ECD80);

INCLUDE_ASM("asm/levels", func_L00_003ED198);

INCLUDE_ASM("asm/levels", func_L00_003ED850);

INCLUDE_ASM("asm/levels", func_L00_003EDB98);

INCLUDE_ASM("asm/levels", func_L00_003EDEE0);

/* Family 40487154aa250cc8: fixed-field addend writes into one resource record. */
void func_L00_003EE100(char *object)
{
    char *data;
    float x;
    float y;
    float z;

    data = *(char **)(object + 104);
    func_002833F0_1(object + 192, object + 240);
    x = func_00283198_1(*(float *)(data + 4)) * 0.15f + 0.35000002f;
    y = func_00283198_1(*(float *)(data + 8)) * 0.15f + 0.35000002f;
    z = func_00283198_1(*(float *)(data + 12)) * 0.15f + 0.35000002f;
    func_00282D30_3(object + 192, object + 192, x);
    func_00282D30_3(object + 208, object + 208, y);
    func_00282D30_3(object + 224, object + 224, z);
    *(float *)(data + 4) = func_00283B98_3(*(float *)(data + 4), 0.5f);
    *(float *)(data + 8) = func_00283B98_3(*(float *)(data + 8), 0.5f);
    *(float *)(data + 12) = func_00283B98_3(*(float *)(data + 12), 0.5f);
}

/* calls two guards and returns 1 only when both succeed and the object's float field is not positive */
int func_L00_003EE228(char *object)
{
    float *p;

    if (func_002ABB78(object) != 0)
        return 0;
    p = func_002AB1F0(object);
    if (p == 0)
        return 0;
    if (0.0f < *p)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/levels", func_L00_003EE4C0);

/* When the context flag at offset 0x24 is nonzero, pass scale 1.0, the context, its vector at offset 0x10 and mode zero to the bound helper; original game role is unknown. */
void func_L00_003EE8E8(Rac2Native_9cdc323a4d0c2fbd_AnalysisOwner *owner)
{
    Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context = owner->context_68;
    if (context->active_24 != 0) {
        func_002FDBD8_5(1.0f, context, context->vector_10, 0);
    }
}

INCLUDE_ASM("asm/levels", func_L00_003EE920);

INCLUDE_ASM("asm/levels", func_L00_003EED10);

INCLUDE_ASM("asm/levels", func_L00_003EEE20);

INCLUDE_ASM("asm/levels", func_L00_003EEE90);

INCLUDE_ASM("asm/levels", func_L00_003EF3E0);

INCLUDE_ASM("asm/levels", func_L00_003EF548);

INCLUDE_ASM("asm/levels", func_L00_003EF550);

INCLUDE_ASM("asm/levels", func_L00_003EF560);

INCLUDE_ASM("asm/levels", func_L00_003EFA00);

INCLUDE_ASM("asm/levels", func_L00_003EFA98);

INCLUDE_ASM("asm/levels", func_L00_003EFD00);

INCLUDE_ASM("asm/levels", func_L00_003EFF58);

INCLUDE_ASM("asm/levels", func_L00_003F00A0);

INCLUDE_ASM("asm/levels", func_L00_003F0130);

INCLUDE_ASM("asm/levels", func_L00_003F0198);

INCLUDE_ASM("asm/levels", func_L00_003F0680);

INCLUDE_ASM("asm/levels", func_L00_003F09A0);

/* resets a state record: zero words, plus/minus one float flags and two 64-bit fields in the retail store order */
void func_L00_003F0A20(char *p)
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

/* Scales four consecutive 16-byte XYZ vectors in place by one scalar through a vector helper. */
void func_L00_003F0AA8(char *p, float scale)
{
    func_00282D30_2(p, p, scale);
    func_00282D30_2(p + 16, p + 16, scale);
    func_00282D30_2(p + 32, p + 32, scale);
    func_00282D30_2(p + 48, p + 48, scale);
}

INCLUDE_ASM("asm/levels", func_L00_003F0B10);

INCLUDE_ASM("asm/levels", func_L00_003F0CC8);

INCLUDE_ASM("asm/levels", func_L00_003F1300);

INCLUDE_ASM("asm/levels", func_L00_003F1448);

/* resets a state record: zero words, plus/minus one float flags and two 64-bit fields in the retail store order */
void func_L00_003F1DC8(char *p)
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

/* Scales four consecutive 16-byte XYZ vectors in place by one scalar through a vector helper. */
void func_L00_003F1E50(char *p, float scale)
{
    func_00282D30_2(p, p, scale);
    func_00282D30_2(p + 16, p + 16, scale);
    func_00282D30_2(p + 32, p + 32, scale);
    func_00282D30_2(p + 48, p + 48, scale);
}

INCLUDE_ASM("asm/levels", func_L00_003F1EB8);

INCLUDE_ASM("asm/levels", func_L00_003F26C8);

/* Derives a 16-byte element at index-1 from its index-2 and index-3 neighbours through two bound helpers; original game role is unknown. */
void func_L00_003F28A0(Vec16_Fc936841d *object, int index)
{
    char local[16];

    func_00282CF0_9(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    func_00282CC0_15((char *)&object[index - 1], (char *)&object[index - 2], local);
}

INCLUDE_ASM("asm/levels", func_L00_003F3160);

INCLUDE_ASM("asm/levels", func_L00_003F34D8);

INCLUDE_ASM("asm/levels", func_L00_003F3518);

INCLUDE_ASM("asm/levels", func_L00_003F37A0);

INCLUDE_ASM("asm/levels", func_L00_003F37E8);

INCLUDE_ASM("asm/levels", func_L00_003F3A88);

INCLUDE_ASM("asm/levels", func_L00_003F3AD0);

INCLUDE_ASM("asm/levels", func_L00_003F3D70);

INCLUDE_ASM("asm/levels", func_L00_003F4210);

INCLUDE_ASM("asm/levels", func_L00_003F4B68);

INCLUDE_ASM("asm/levels", func_L00_003F4C68);

INCLUDE_ASM("asm/levels", func_L00_003F4EC8);

INCLUDE_ASM("asm/levels", func_L00_003F51A0);

INCLUDE_ASM("asm/levels", func_L00_003F5238);
