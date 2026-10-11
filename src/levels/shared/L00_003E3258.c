#include "include_asm.h"

extern void func_002833F0_1(char *a, char *b);

extern float func_00283198_1(float value);

extern void func_00282D30_3(char *a, char *b, float value);

extern float func_00283B98_3(float value, float scale);

extern int func_002ABB78(char *object);

extern float *func_002AB1F0(char *object);

extern void func_00282D30_2(char *dst, char *src, float scale);

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

extern void func_002FDBD8_4(float scale, Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context,
                                    float *vector, int mode);

INCLUDE_ASM("asm/levels", func_L00_003E3258);

INCLUDE_ASM("asm/levels", func_L00_003E3668);

/* Family 40487154aa250cc8: fixed-field addend writes into one resource record. */
void func_L00_003E3890(char *object)
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
int func_L00_003E39B8(char *object)
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

INCLUDE_ASM("asm/levels", func_L00_003E3A18);

INCLUDE_ASM("asm/levels", func_L00_003E4508);

INCLUDE_ASM("asm/levels", func_L00_003E4948);

INCLUDE_ASM("asm/levels", func_L00_003E4968);

INCLUDE_ASM("asm/levels", func_L00_003E4B80);

INCLUDE_ASM("asm/levels", func_L00_003E4BF0);

INCLUDE_ASM("asm/levels", func_L00_003E51C0);

INCLUDE_ASM("asm/levels", func_L00_003E5328);

INCLUDE_ASM("asm/levels", func_L00_003E5330);

INCLUDE_ASM("asm/levels", func_L00_003E5340);

INCLUDE_ASM("asm/levels", func_L00_003E55B0);

INCLUDE_ASM("asm/levels", func_L00_003E5650);

INCLUDE_ASM("asm/levels", func_L00_003E5710);

INCLUDE_ASM("asm/levels", func_L00_003E5978);

INCLUDE_ASM("asm/levels", func_L00_003E5BD8);

INCLUDE_ASM("asm/levels", func_L00_003E6030);

INCLUDE_ASM("asm/levels", func_L00_003E64F8);

INCLUDE_ASM("asm/levels", func_L00_003E6628);

INCLUDE_ASM("asm/levels", func_L00_003E6710);

INCLUDE_ASM("asm/levels", func_L00_003E6778);

INCLUDE_ASM("asm/levels", func_L00_003E6C10);

INCLUDE_ASM("asm/levels", func_L00_003E6F48);

/* resets a state record: zero words, plus/minus one float flags and two 64-bit fields in the retail store order */
void func_L00_003E6FC8(char *p)
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
void func_L00_003E7050(char *p, float scale)
{
    func_00282D30_2(p, p, scale);
    func_00282D30_2(p + 16, p + 16, scale);
    func_00282D30_2(p + 32, p + 32, scale);
    func_00282D30_2(p + 48, p + 48, scale);
}

INCLUDE_ASM("asm/levels", func_L00_003E70B8);

INCLUDE_ASM("asm/levels", func_L00_003E7270);

INCLUDE_ASM("asm/levels", func_L00_003E7650);

void func_L00_003E7760(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_003E7C88);

INCLUDE_ASM("asm/levels", func_L00_003E7E40);

INCLUDE_ASM("asm/levels", func_L00_003E80A8);

INCLUDE_ASM("asm/levels", func_L00_003E8150);

INCLUDE_ASM("asm/levels", func_L00_003E8180);

INCLUDE_ASM("asm/levels", func_L00_003E8A98);

INCLUDE_ASM("asm/levels", func_L00_003E9490);

INCLUDE_ASM("asm/levels", func_L00_003E9540);

/* Shared native body; original game role is unknown. */
void func_L00_003E9660(int unused, float *p, int n)
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

INCLUDE_ASM("asm/levels", func_L00_003E9780);

INCLUDE_ASM("asm/levels", func_L00_003E9928);

INCLUDE_ASM("asm/levels", func_L00_003E9930);

/* Derives a 16-byte element at index-1 from its index-2 and index-3 neighbours through two bound helpers; original game role is unknown. */
void func_L00_003E9A98(Vec16_Fc936841d *object, int index)
{
    char local[16];

    func_00282CF0_9(local, (char *)&object[index - 2], (char *)&object[index - 3]);
    func_00282CC0_15((char *)&object[index - 1], (char *)&object[index - 2], local);
}

INCLUDE_ASM("asm/levels", func_L00_003E9B00);

INCLUDE_ASM("asm/levels", func_L00_003E9B90);

INCLUDE_ASM("asm/levels", func_L00_003EA048);

/* straight-line constant-store body (no calls, no branches, no loads) */
void func_L00_003EA050(char *p)
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

INCLUDE_ASM("asm/levels", func_L00_003EA0E0);

INCLUDE_ASM("asm/levels", func_L00_003EA188);

INCLUDE_ASM("asm/levels", func_L00_003EA408);

INCLUDE_ASM("asm/levels", func_L00_003EA540);

INCLUDE_ASM("asm/levels", func_L00_003EA7D0);

/* shared native body of family 5a97ab89858c */
void func_L00_003EA860(char *p)
{
    *(long long *)(p + 112) = 0;
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
    *(long long *)(p + 128) = 0x0000FF9000000260LL;
    *(float *)(p + 20) = -1.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/levels", func_L00_003EA8C8);

INCLUDE_ASM("asm/levels", func_L00_003EAA58);

/* When the context flag at offset 0x24 is nonzero, pass scale 1.0, the context, its vector at offset 0x10 and mode zero to the bound helper; original game role is unknown. */
void func_L00_003EAC88(Rac2Native_9cdc323a4d0c2fbd_AnalysisOwner *owner)
{
    Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context = owner->context_68;
    if (context->active_24 != 0) {
        func_002FDBD8_4(1.0f, context, context->vector_10, 0);
    }
}

INCLUDE_ASM("asm/levels", func_L00_003EAEF8);

INCLUDE_ASM("asm/levels", func_L00_003EB0C0);

INCLUDE_ASM("asm/levels", func_L00_003EB400);

INCLUDE_ASM("asm/levels", func_L00_003EB610);

INCLUDE_ASM("asm/levels", func_L00_003EB7B8);

INCLUDE_ASM("asm/levels", func_L00_003EB7C0);
