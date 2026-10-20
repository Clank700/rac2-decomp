/* 364 bytes against retail's 360 (0 of 28 places); from src/game/003399B0.c, default flags.
   Everything but one word agrees: the calls, the table stores, the float constants and the object stores.
   The word is in the (float)(int) round trip after the allocation: retail writes the mtc1 into $f0 and
   has no nop after the mfc1; this build writes $f1 and gets a nop after the mfc1. Tried: float and int
   temporaries, the chain spelled three ways, -mno-split-addresses (364 again). */
typedef float f32;
typedef unsigned char u8;
typedef int s32;
extern void func_00336710(void *a0, void *a1, void *a2);
extern void func_00335F88(void *a0, f32 a1, f32 a2, f32 a3, f32 a4);
extern int *func_00335E20(void *a0);
extern void func_003369A8(void *a0, void *a1, void *a2);
extern int *func_00336DA8(int a0, int a1);
extern int func_00336E40(void *a0);
extern char D_001ADC88[];
extern f32 D_001B23A4 __attribute__((sda));

void func_0033A520(u8 *obj, void *arg)
{
    *(s32 *)(obj + 0x1F8) = 0;
    *(void **)(obj + 0x200) = arg;
    if (arg != 0) {
        s32 *alloc = func_00336DA8(16, func_00336E40(arg));
        *(s32 **)(obj + 0x1FC) = alloc;
        alloc[0] = 0;
        alloc[1] = 0;
        alloc[2] = 0;
        alloc[3] = 0;
    }
    ((f32 *)*(s32 **)(obj + 0x1FC))[0] = 70.0f;
    ((f32 *)*(s32 **)(obj + 0x1FC))[1] = (f32)(s32)(D_001B23A4 * 300.0f + 0.5f);
    func_00336710(obj + 0x134, D_001ADC88, *(void **)(obj + 0x200));
    func_00335F88(obj + 0x134, 24.0f, 24.0f, 0.0f, 0.0f);
    *func_00335E20(obj + 0x134) = 0x60F0F0B0;
    *(f32 *)(obj + 0x204) = 65.0f;
    func_003369A8(obj + 0x170, D_001ADC88, *(void **)(obj + 0x200));
    *func_00335E20(obj + 0x170) = 0x80F0F0F0;
    func_00335F88(obj + 0x170, 0.7f, 0.7f, 0.0f, 0.0f);
}
