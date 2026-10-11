#include "include_asm.h"

extern char *func_L00_0032A088(int a0, int a1);

extern char *func_L00_0032A0B8(int a0, int a1);

extern int func_00282978(char *a0);

extern float func_00283B98(float a0, float a1);

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

extern void func_002FDBD8_6(float scale, Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context,
                                    float *vector, int mode);

INCLUDE_ASM("asm/levels", func_L00_003F5390);

void func_L00_003F5658(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_003F5660);

INCLUDE_ASM("asm/levels", func_L00_003F56F0);

INCLUDE_ASM("asm/levels", func_L00_003F5750);

INCLUDE_ASM("asm/levels", func_L00_003F5870);

INCLUDE_ASM("asm/levels", func_L00_003F59F0);

INCLUDE_ASM("asm/levels", func_L00_003F5B10);

INCLUDE_ASM("asm/levels", func_L00_003F5F90);

INCLUDE_ASM("asm/levels", func_L00_003F6168);

INCLUDE_ASM("asm/levels", func_L00_003F6308);

INCLUDE_ASM("asm/levels", func_L00_003F6900);

/* Walks 120 records of 64 bytes from a base resolved through two descriptor lookups; for each live record it calls an update helper and, when that reports zero, counts it and advances a float pair by one step, clearing the record's live flag otherwise. */
int func_L00_003F6A58(int *a0)
{
    int i;
    int count = 0;
    char *base;
    char *rec;
    char *obj;

    rec = *(char **)((char *)a0 + 104);
    base = func_L00_0032A088(3076, *(short *)(rec + 26));
    base = base + *(int *)(func_L00_0032A0B8(3076, *(short *)(rec + 26)) + 4);
    obj = base + 16;
    rec = base;

    for (i = 119; i >= 0; i--) {
        if (*(short *)(rec + 18) != 0) {
            if (func_00282978(obj) != 0) {
                *(short *)(rec + 18) = 0;
            } else {
                count++;
                *(float *)(rec + 24) = func_00283B98(*(float *)(rec + 24), *(float *)(rec + 28));
            }
        }
        obj += 64;
        rec += 64;
    }
    return count;
}

INCLUDE_ASM("asm/levels", func_L00_003F6B10);

INCLUDE_ASM("asm/levels", func_L00_003F71E8);

INCLUDE_ASM("asm/levels", func_L00_003F7268);

INCLUDE_ASM("asm/levels", func_L00_003F8280);

INCLUDE_ASM("asm/levels", func_L00_003F87B0);

INCLUDE_ASM("asm/levels", func_L00_003F89F8);

INCLUDE_ASM("asm/levels", func_L00_003F8DC8);

INCLUDE_ASM("asm/levels", func_L00_003F8E08);

INCLUDE_ASM("asm/levels", func_L00_003F9040);

INCLUDE_ASM("asm/levels", func_L00_003F9368);

INCLUDE_ASM("asm/levels", func_L00_003F94F8);

INCLUDE_ASM("asm/levels", func_L00_003F9570);

INCLUDE_ASM("asm/levels", func_L00_003F9A30);

INCLUDE_ASM("asm/levels", func_L00_003FA858);

INCLUDE_ASM("asm/levels", func_L00_003FBF78);

void func_L00_003FC100(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_003FC108);

INCLUDE_ASM("asm/levels", func_L00_003FC228);

INCLUDE_ASM("asm/levels", func_L00_003FC468);

INCLUDE_ASM("asm/levels", func_L00_003FC820);

INCLUDE_ASM("asm/levels", func_L00_003FCA40);

INCLUDE_ASM("asm/levels", func_L00_003FCB70);

INCLUDE_ASM("asm/levels", func_L00_003FCDB0);

INCLUDE_ASM("asm/levels", func_L00_003FD178);

INCLUDE_ASM("asm/levels", func_L00_003FD6B0);

INCLUDE_ASM("asm/levels", func_L00_003FD700);

INCLUDE_ASM("asm/levels", func_L00_003FDB20);

INCLUDE_ASM("asm/levels", func_L00_003FDE48);

INCLUDE_ASM("asm/levels", func_L00_003FE280);

INCLUDE_ASM("asm/levels", func_L00_003FE2D0);

INCLUDE_ASM("asm/levels", func_L00_003FE310);

/* When the context flag at offset 0x24 is nonzero, pass scale 1.0, the context, its vector at offset 0x10 and mode zero to the bound helper; original game role is unknown. */
void func_L00_003FE490(Rac2Native_9cdc323a4d0c2fbd_AnalysisOwner *owner)
{
    Rac2Native_9cdc323a4d0c2fbd_AnalysisConditionalContext *context = owner->context_68;
    if (context->active_24 != 0) {
        func_002FDBD8_6(1.0f, context, context->vector_10, 0);
    }
}

INCLUDE_ASM("asm/levels", func_L00_003FE4C8);

INCLUDE_ASM("asm/levels", func_L00_003FE8D0);

INCLUDE_ASM("asm/levels", func_L00_003FE920);

INCLUDE_ASM("asm/levels", func_L00_003FEAC8);

INCLUDE_ASM("asm/levels", func_L00_003FEBA0);

INCLUDE_ASM("asm/levels", func_L00_003FED60);
