typedef float f32;
typedef int s32;

extern f32 G_SDA __attribute__((sda));
extern f32 G_ALIAS __asm__("G_ALIAS_asm") __attribute__((section(".sdata")));
extern f32 D_L02_001B1234 __attribute__((sda));
extern f32 D_L02_001B1240 __asm__("D_L02_001B1240_asm") __attribute__((section(".sdata")));

f32 f1(void) { return G_SDA; }
f32 f2(void) { return G_ALIAS; }
f32 f3(void) { return D_L02_001B1234; }
f32 f4(void) { return D_L02_001B1240; }
