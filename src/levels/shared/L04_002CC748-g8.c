#include "include_asm.h"
#include "common.h"

/* The angle pair, resident in the level's small data. */
extern f32 D_L04_001AD840 __attribute__((sda));

extern int func_00283CF0(float);

/* Packs the three position components and the two angles into the record at dst, each one
   offset by its own constant and scaled into 1/1024 units. */
void func_L04_0039FC28(char *src, char *dst) {
    *(int *)(dst + 0) = func_00283CF0((*(f32 *)(src + 0) + *(f32 *)0x001AD848) * 1024.0f);
    *(int *)(dst + 4) = func_00283CF0((*(f32 *)(src + 4) + *(f32 *)0x001AD84C) * 1024.0f);
    *(int *)(dst + 8) = func_00283CF0((*(f32 *)(src + 8) - 1.0f) * 1024.0f);
    *(short *)(dst + 0xC) = func_00283CF0(D_L04_001AD840 * 1024.0f);
    *(short *)(dst + 0xE) = func_00283CF0(D_L04_001AD840 * 1024.0f);
}
