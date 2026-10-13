#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_002A7750(void *, s32, s32);

extern void func_002833F0(void *, void *);

extern void func_00283738(void *, void *, void *);

extern void func_002830C0(void *, void *, void *);

extern s32 D_L16_001B18F0 __attribute__((sda));

extern s32 D_L16_001B18E0 __attribute__((sda));

/* Raises the handle's measured flag, rebuilds the motion record from the level's
   pair of measured vectors and submits both halves of the sub-object. */
void func_L16_00413690(u8 *arg0, u8 *arg1)
{
    u8 buf[0x30];

    func_002A7750(arg0, 1, -1);
    *(u16 *)(arg0 + 0x34) |= 0x100;
    func_002833F0(buf, &D_L16_001B18F0);
    func_00283738(arg0 + 0xC0, arg1, buf);
    func_002830C0(arg0 + 0x10, &D_L16_001B18E0, arg1);
}
