/* Wave 6 lvl6-12 tour 2, round 4: func_L00_003206B8 with the global's address spelled
   as a literal, so the load uses its own destination register as the scratch. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern s32 func_2EE138(void *, void *, void *);
extern void func_2EE5B0(void *, void *, void *);
extern f32 func_2EE268(void *);

s32 func_L00_003206B8_v7(u8 *a0, s32 a1) {
    u8 *s0;
    f32 b1[4];
    f32 b2[4];

    if (a1 >= 0) {
        s0 = *(u8 **)0x001B1F9C + (a1 << 7);
        func_2EE138(b1, a0, s0 + 0x30);
        *(s32 *)((u8 *)b1 + 0xC) = 0;
        func_2EE5B0(b2, b1, s0 + 0x40);
        if (func_2EE268(b2) < 1.0f) {
            if (*(f32 *)((u8 *)b2 + 8) >= -1.0f) {
                if (*(f32 *)((u8 *)b2 + 8) <= 1.0f)
                    return 1;
            }
        }
    }
    return 0;
}
