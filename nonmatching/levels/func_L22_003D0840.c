/* Near miss from src/levels/22_dobbo_orbit/L22_00358778.c: the build refuses this body at its
   place — 64 bytes, expected 60. Kept as a starting point;
   not linked, not counted. */

/* Standalone declarations recovered from src/levels/22_dobbo_orbit/L22_00358778.c. */
typedef unsigned char u8;

typedef unsigned short u16;

typedef int s32;

extern void func_31FBB8();

void func_L22_003D0840(s32 a0) {
    s32 p = a0;

    if (*(u8 *)(p + 0x20) != 0)
        return;
    *(u16 *)(p + 0x34) |= 0x41;
    func_31FBB8(a0, 1, -1, p);
}
