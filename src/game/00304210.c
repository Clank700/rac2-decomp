#include "include_asm.h"

extern int F6eb4f363_FUN_002A77E0(int mode);

extern float F6eb4f363_FUN_002A90F8(char *object, char *local);

extern void F6eb4f363_FUN_00282D30(char *local, int value, float scale);

extern float F6eb4f363_FUN_002A7878(float low, float high);

extern void F6eb4f363_FUN_002BF728(char *object, char *local, float amount, float base);

#ifndef RAC2_T_WORKER_F9E2CD219
#define RAC2_T_WORKER_F9E2CD219
typedef struct {
    unsigned char pad00[76];
    short field4C;
    unsigned char pad4E[2];
    int field50;
    float field54;
    float field58;
} Worker_F9e2cd219;
#endif

#ifndef RAC2_T_OWNER_F9E2CD219
#define RAC2_T_OWNER_F9E2CD219
typedef struct {
    unsigned char pad00[104];
    Worker_F9e2cd219 *child;
} Owner_F9e2cd219;
#endif

extern float F9e2cd219_FUN_002A7798(float value);

extern void F9e2cd219_FUN_002ACF68(void *out, void *in, void *tmp, int mode, float value);

extern void F9e2cd219_FUN_00305310(void *owner, void *out);

extern void F9e2cd219_FUN_00307AD0(void *owner, void *out);

INCLUDE_ASM("asm/game", func_00304210);

INCLUDE_ASM("asm/game", func_00304AD0);

void func_00304B68(char *object)
{
    char local[16];
    float base;
    int value = *(int *)(object + 104);

    if (F6eb4f363_FUN_002A77E0(5))
        return;
    base = F6eb4f363_FUN_002A90F8(object + 16, local);
    F6eb4f363_FUN_00282D30(local, value, 0.25f);
    F6eb4f363_FUN_002BF728(object + 16, local, F6eb4f363_FUN_002A7878(0.05f, 0.1f) * 210000.0f, base);
}

INCLUDE_ASM("asm/game", func_00304C18);

INCLUDE_ASM("asm/game", func_00304C78);

INCLUDE_ASM("asm/game", func_00304D38);

INCLUDE_ASM("asm/game", func_00304F28);

INCLUDE_ASM("asm/game", func_00305058);

void func_00305228(Owner_F9e2cd219 *self)
{
    Worker_F9e2cd219 *child = self->child;

    F9e2cd219_FUN_002ACF68((char *)child + 48, (char *)child + 16, (char *)child + 32, 0,
            F9e2cd219_FUN_002A7798(child->field54));

    child->field54 = child->field54 + child->field58;
    F9e2cd219_FUN_00305310(self, (char *)child + 48);

    if (child->field54 > 0.9f)
        child->field50 = 1;
    else
        child->field50 = 0;

    if (child->field54 >= 1.0f) {
        child->field54 = 1.0f;
        child->field4C = 1;
    }
}

INCLUDE_ASM("asm/game", func_00305310);

INCLUDE_ASM("asm/game", func_00305408);

INCLUDE_ASM("asm/game", func_00305418);

INCLUDE_ASM("asm/game", func_00305438);

INCLUDE_ASM("asm/game", func_003054E8);

INCLUDE_ASM("asm/game", func_00305798);

void func_00305838(char *p)
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
    *(long long *)(p + 128) = 0x0000FF9000000260LL;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/game", func_003058C8);

INCLUDE_ASM("asm/game", func_00305910);

INCLUDE_ASM("asm/game", func_00305C10);

INCLUDE_ASM("asm/game", func_00306040);

INCLUDE_ASM("asm/game", func_00306318);

INCLUDE_ASM("asm/game", func_00306680);

INCLUDE_ASM("asm/game", func_00306A40);

INCLUDE_ASM("asm/game", func_00307298);

void func_00307330(char *object)
{
    char local[16];
    float base;
    int value = *(int *)(object + 104);

    if (F6eb4f363_FUN_002A77E0(5))
        return;
    base = F6eb4f363_FUN_002A90F8(object + 16, local);
    F6eb4f363_FUN_00282D30(local, value, 0.25f);
    F6eb4f363_FUN_002BF728(object + 16, local, F6eb4f363_FUN_002A7878(0.05f, 0.1f) * 210000.0f, base);
}

INCLUDE_ASM("asm/game", func_003073E0);

INCLUDE_ASM("asm/game", func_00307440);

INCLUDE_ASM("asm/game", func_00307500);

INCLUDE_ASM("asm/game", func_003076F0);

INCLUDE_ASM("asm/game", func_00307808);

void func_003079E8(Owner_F9e2cd219 *self)
{
    Worker_F9e2cd219 *child = self->child;

    F9e2cd219_FUN_002ACF68((char *)child + 48, (char *)child + 16, (char *)child + 32, 0,
            F9e2cd219_FUN_002A7798(child->field54));

    child->field54 = child->field54 + child->field58;
    F9e2cd219_FUN_00307AD0(self, (char *)child + 48);

    if (child->field54 > 0.9f)
        child->field50 = 1;
    else
        child->field50 = 0;

    if (child->field54 >= 1.0f) {
        child->field54 = 1.0f;
        child->field4C = 1;
    }
}

INCLUDE_ASM("asm/game", func_00307AD0);

INCLUDE_ASM("asm/game", func_00307BD0);

INCLUDE_ASM("asm/game", func_00307BF0);

void func_00307C30(char *p)
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
    *(long long *)(p + 128) = 0x0000FF9000000260LL;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/game", func_00307CC0);

INCLUDE_ASM("asm/game", func_00307FC0);

INCLUDE_ASM("asm/game", func_003083F8);

INCLUDE_ASM("asm/game", func_00308408);

INCLUDE_ASM("asm/game", func_003085C8);

INCLUDE_ASM("asm/game", func_00308600);

INCLUDE_ASM("asm/game", func_00308768);

INCLUDE_ASM("asm/game", func_00308DB8);

INCLUDE_ASM("asm/game", func_003092A0);

INCLUDE_ASM("asm/game", func_00309718);

INCLUDE_ASM("asm/game", func_0030A188);

INCLUDE_ASM("asm/game", func_0030A348);

INCLUDE_ASM("asm/game", func_0030BA38);

INCLUDE_ASM("asm/game", func_0030BBA0);
