#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern int D_L10_001B1648 __attribute__((sda));

extern u8 D_L10_0042BEE0[];

extern int func_003179F0(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);
extern f32 func_00309B38(f32 f12, f32 f13);
extern void func_00301B98(void *a0, void *a1);

/* Two-state start-up for a cloud puff: state 0 lays the record at +0x10 out (position
   reset, colour limits, the builder call, its handle in the $gp variable), and states 0
   and 1 both fade the +0xF8 value down; anything else goes straight to the update. */
void func_L10_0042BE20(u8 *a0) {
    u8 *s0 = a0;
    u8 state = *(u8 *)(s0 + 0x20);
    f32 v;

    switch (state) {
    case 0:
        *(int *)(s0 + 0x1C) = 0;
        *(u8 *)(s0 + 0x20) = 1;
        v = *(f32 *)(s0 + 0x1C);
        *(u16 *)(s0 + 0x32) = 0x1FF;
        *(u8 *)(s0 + 0x30) = 0xFF;
        *(f32 *)(s0 + 0x10) = 512.0f;
        *(f32 *)(s0 + 0x14) = 512.0f;
        *(f32 *)(s0 + 0x18) = 512.0f;
        D_L10_001B1648 = func_003179F0(s0 + 0x10, 40.0f, v, v, v, 1.0f);
    case 1:
        *(f32 *)(s0 + 0xF8) =
            func_00309B38(*(f32 *)(s0 + 0xF8), 0.00981747824699f);
        break;
    default:
        break;
    }
    func_00301B98(D_L10_0042BEE0, s0);
}

extern int func_002A7820(int low, int high);
extern f32 func_002A7878(f32 low, f32 high);
extern f32 func_002A7940(void);
extern void func_00281EB8(void *at, int kind, unsigned int colour, int count, f32 size,
                          f32 rate, f32 spin);
extern f32 func_00283CE0(int);
extern u8 D_L10_001C7800[];

/* The cloud puff's burst: three layers of particles at the object's position, coloured
   0x800000, 0x808080 and 0x804040 under random alphas, then the entry of D_L10_001C7800
   named by D_L10_001B1648 takes half of a value for the first alpha at +0x1C. */
void func_L10_0042BEE0(u8 *object)
{
    int alpha;
    u8 *entry;

    alpha = func_002A7820(1, 0x80) << 24;
    object += 0x10;
    func_00281EB8(object, 0xB, (func_002A7820(0x20, 0x80) << 24) | 0x800000, 1,
                  func_002A7878(8.0f, 15.0f), 0.01f, func_002A7940());
    func_00281EB8(object, 0xB, alpha | 0x808080, 1, func_002A7878(4.0f, 12.0f), 0.025f,
                  func_002A7940());
    func_00281EB8(object, 0xB, (func_002A7820(0, 0x80) << 24) | 0x804040, 1,
                  func_002A7878(8.0f, 17.0f), 0.05f, func_002A7940());
    entry = D_L10_001C7800 + (D_L10_001B1648 << 5);
    *(f32 *)(entry + 0x1C) = func_00283CE0(alpha >> 24) * 0.5f;
}
