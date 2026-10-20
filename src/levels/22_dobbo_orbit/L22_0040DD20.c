#include "include_asm.h"

typedef int s32;

typedef int TI128 __attribute__((mode(TI)));

extern void func_3300E8();

void func_L22_0040DD20(s32 a0) {
    TI128 buf = 0;

    func_3300E8(a0, &buf);
}
