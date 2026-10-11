#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

/* lot10: privately byte-gated bodies. */
extern s32 func_00126470(u8 *, s32, s32, s32, s32, s32, s32, s32);

extern s32 func_0011AEA0(s32);

extern s32 func_00126730(u8 *, u8 *);

extern s32 D_001A72E0[] __attribute__((sda));

extern s32 D_001A7340[] __attribute__((sda));

void func_00285708(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4) {
    u8 image[112];
    func_00126470(image, (D_001A72E0[0]<<8)>>16, (D_001A7340[0]<<10)>>16,
                0x30,(short)a0,(short)a1,(short)a2,(short)a3);
    func_0011AEA0(0);
    func_00126730(image,a4);
}

INCLUDE_ASM("asm/game", func_00285788);

INCLUDE_ASM("asm/game", func_002857B0);

INCLUDE_ASM("asm/game", func_002857B8);
