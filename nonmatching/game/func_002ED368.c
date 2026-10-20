/* func_002ED368: 332 bytes compiled (-O2 -G8, the src/game/002ED260.c profile), retail 336.
   The body matches instruction for instruction (the calls, the float constants, the stores and
   the owner test with its bnel). The loop does not: this cc1 counts it down (`addiu $s2,-1` /
   `bgez`, offset in $s3), where retail counts up (`addiu $s3,+1` / `slti` / `bnez`, offset in
   $s2). Tried: u32 and int counters, `<= 511`, `!= 512`, a limit variable, and deriving the offset
   from the counter (which gives a `mult` instead of the 0x50 step). */
#include "include_asm.h"

#ifndef RAC2_T_U32_FE8672EA5
#define RAC2_T_U32_FE8672EA5
typedef unsigned int u32_Fe8672ea5;
#endif

extern u32_Fe8672ea5 D_L04_001AC18C __attribute__((sda));
extern float D_L04_001AC190 __attribute__((sda));

extern float func_00283CE0(int value);
extern int func_00283CF0(float value);
extern int func_00283D38(int a, int b, float c);
extern float func_00283B98(float a, float b);
extern float func_002A7878(float a, float b);
extern void func_00282CC0(void *a0, void *a1, void *a2);
extern void func_00282D30(void *a0, void *a1, float scale);
extern int func_00282948(void *a0);

void func_002ED368(u32_Fe8672ea5 owner)
{
    u32_Fe8672ea5 offset = 0;
    u32_Fe8672ea5 rec;
    int i;
    float f20;

    if (D_L04_001AC18C == 0) {
        return;
    }
    for (i = 0; i < 512; i++) {
        rec = D_L04_001AC18C + offset;
        if (*(u32_Fe8672ea5 *)(rec + 0x48) == owner) {
            float ratio = func_00283CE0(*(int *)(rec + 0x40));
            float delta;
            f20 = ratio / func_00283CE0(*(int *)(rec + 0x44));
            *(int *)(rec + 0x38) = func_00283CF0((float)*(int *)(rec + 0x34) * f20);
            *(u32_Fe8672ea5 *)(rec + 0x30) = *(u32_Fe8672ea5 *)(rec + 0x2C);
            *(int *)(rec + 0x30) = func_00283D38(0x003F3F3F, *(int *)(rec + 0x2C), (f20 * f20) * f20);
            *(float *)(rec + 0x24) = func_00283B98(*(float *)(rec + 0x24), *(float *)(rec + 0x20));
            if (*(int *)(rec + 0x3C) != 0) {
                delta = func_002A7878(0.001f, 0.003f);
                *(float *)(rec + 0x28) = *(float *)(rec + 0x28) + delta;
            }
            func_00282CC0((void *)rec, (void *)rec, (void *)(rec + 0x10));
            func_00282D30((void *)(rec + 0x10), (void *)(rec + 0x10), 0.99f);
            if (func_00282948((void *)(rec + 0x40)) != 0) {
                *(u32_Fe8672ea5 *)(rec + 0x48) = 0;
            }
        }
        offset += 80;
    }
}
