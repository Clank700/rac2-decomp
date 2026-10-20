/* func_002ED4B8: 172 bytes compiled (-O2 -G8, the src/game/002ED260.c profile), retail 176.
   The loop, the flag (`addiu $a3,1` / `beqz` / `xori` / `sltu`), the scaling and the call match.
   Still differs: retail saves $s0 before $s1 (this cc1 saves $s1 first), and retail tests the
   owner with `beql` whose delay slot holds a copy of the loop decrement (`addiu $s0,$s0,-1`),
   where this cc1 emits `beqz` and one decrement after the call. */
#include "include_asm.h"

#ifndef RAC2_T_U32_FE8672EA5
#define RAC2_T_U32_FE8672EA5
typedef unsigned int u32_Fe8672ea5;
#endif

extern u32_Fe8672ea5 D_L04_001AC18C __attribute__((sda));
extern float D_L04_001AC190 __attribute__((sda));

extern void func_00281EB8(void *a0, u32_Fe8672ea5 a1, u32_Fe8672ea5 a2, int a3, float f12, float f13, float f14);

void func_002ED4B8(void)
{
    u32_Fe8672ea5 offset = 0;
    u32_Fe8672ea5 cursor;
    int i;

    if (D_L04_001AC18C == 0) {
        return;
    }
    for (i = 511; i >= 0; i--) {
        cursor = D_L04_001AC18C + offset;
        if (*(u32_Fe8672ea5 *)(cursor + 0x48) != 0) {
            float scaled = (float)*(int *)(cursor + 0x38) * D_L04_001AC190;
            int flag = 1;
            int x = *(int *)(cursor + 0x3C) >> 1;
            if (x != 0) {
                flag = (x ^ 1) != 0;
            }
            func_00281EB8((void *)cursor, *(u32_Fe8672ea5 *)(cursor + 0x4C),
                          *(u32_Fe8672ea5 *)(cursor + 0x30) | ((u32_Fe8672ea5)(int)scaled << 24),
                          flag,
                          *(float *)(cursor + 0x28), 0.001f, *(float *)(cursor + 0x24));
        }
        offset += 80;
    }
}
