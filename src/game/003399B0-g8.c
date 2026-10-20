#include "include_asm.h"

extern int func_00336E40(void *);
extern int *func_00336DA8(int, int);
extern void func_003361E0(void *, void *, void *);
extern void func_003369A8(void *, void *, void *);
extern void func_00336A30(void *, int);
extern int *func_00335E20(void *);
extern void func_00336390(void *, void *, int);
extern int func_00288FB8(int);
extern void func_00336A38(void *, int);
extern int func_00339F28(void *, int);
extern char D_001ADC10[], D_001ADC18[], D_001ADC20[], D_001ADC28[], D_001ADC30[];
extern char D_001ADC38[], D_001ADC40[], D_001ADC50[];
extern char D_001ADCA8[], D_001ADCB8[], D_001ADCC0[], D_001ADCC8[], D_001ADCD0[];
extern char *D_001A8CFC[] __attribute__((sda));
extern char D_001ADCA0[8] __attribute__((sda));

/* Binds the screen to its owner: allocates the 16-byte position block, initialises the four
   76-byte and nine 72-byte widgets by name ("0".."3", "title", "missions", ...), sets their
   colours, fonts and labels, marks the "  Exit" label with glyph 0x12 and lays them out.
   The block's four zero stores are written 1, 2, 3, 0 for retail's 0, 4, 8, C order. */
void func_00339AD0(char *obj, void *arg)
{
    *(void **)obj = arg;
    *(int *)(obj + 0x400) = 1;
    if (arg) {
        int *p = func_00336DA8(16, func_00336E40(arg));
        *(int **)(obj + 4) = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
    }
    (*(float **)(obj + 4))[0] = 256.0f;
    (*(float **)(obj + 4))[1] = 198.0f;
    func_003361E0(obj + 0x8, D_001ADC10, arg);
    func_003361E0(obj + 0x54, D_001ADC18, arg);
    func_003361E0(obj + 0xA0, D_001ADC20, arg);
    func_003361E0(obj + 0xEC, D_001ADC28, arg);
    func_003369A8(obj + 0x138, D_001ADC30, arg);
    func_003369A8(obj + 0x180, D_001ADCA8, arg);
    func_003369A8(obj + 0x1C8, D_001ADCB8, arg);
    func_003369A8(obj + 0x210, D_001ADCC0, arg);
    func_003369A8(obj + 0x258, D_001ADCC8, arg);
    func_003369A8(obj + 0x2A0, D_001ADCD0, arg);
    func_003369A8(obj + 0x2E8, D_001ADC38, arg);
    func_003369A8(obj + 0x330, D_001ADC40, arg);
    func_003369A8(obj + 0x378, D_001ADC50, arg);
    func_00336A30(obj + 0x180, 0);
    func_00336A30(obj + 0x1C8, 0);
    func_00336A30(obj + 0x210, 0);
    func_00336A30(obj + 0x258, 0);
    func_00336A30(obj + 0x2A0, 0);
    func_00336A30(obj + 0x2E8, 0);
    func_00336A30(obj + 0x330, 0);
    func_00336A30(obj + 0x378, 2);
    *func_00335E20(obj + 0x8) = 0x60442D00;
    *func_00335E20(obj + 0x54) = 0x60241700;
    *func_00335E20(obj + 0xA0) = 0x55F0C070;
    *func_00335E20(obj + 0xEC) = 0x55F0C070;
    *func_00335E20(obj + 0x138) = 0x80F0F0F0;
    *func_00335E20(obj + 0x180) = 0x80F0F0F0;
    *func_00335E20(obj + 0x1C8) = 0x80F0F0F0;
    *func_00335E20(obj + 0x210) = 0x80F0F0F0;
    *func_00335E20(obj + 0x258) = 0x80F0F0F0;
    *func_00335E20(obj + 0x2A0) = 0x80F0F0F0;
    *func_00335E20(obj + 0x2E8) = 0x80F0F0F0;
    *func_00335E20(obj + 0x330) = 0x80F0F0F0;
    *func_00335E20(obj + 0x378) = 0x80F0F0F0;
    func_00336390(obj + 0x8, D_001A8CFC[0] + 0x8710, 0x5F);
    func_00336390(obj + 0x54, D_001A8CFC[0] + 0x8710, 0x60);
    func_00336390(obj + 0xA0, D_001A8CFC[0] + 0x8710, 0x61);
    func_00336390(obj + 0xEC, D_001A8CFC[0] + 0x8710, 0x62);
    D_001ADCA0[0] = 0x12;
    func_00336A38(obj + 0x138, func_00288FB8(0x2D65));
    func_00336A38(obj + 0x180, func_00288FB8(0x2D5D));
    func_00336A38(obj + 0x1C8, func_00288FB8(0x3293));
    func_00336A38(obj + 0x210, func_00288FB8(0x2D69));
    func_00336A38(obj + 0x258, func_00288FB8(0x2D6A));
    func_00336A38(obj + 0x2A0, func_00288FB8(0x2D6B));
    func_00336A38(obj + 0x2E8, func_00288FB8(0x2D4F));
    func_00336A38(obj + 0x330, (int)(obj + 0x3C0));
    func_00339F28(obj, 0);
}

/* The X bias lives in small data, so this file is built with -G8. */
extern float ref_L00_0033A688_00 __attribute__((sda));
extern float D_001ADD0C;
extern void func_00335E38(char *, float, float, float, float);

/* Offsets the record position by the two resident biases and hands it to the
   shared spawn helper with no rotation. */
void func_0033A688(char *a0)
{
    if (*(int *)(a0 + 0x20C) != 0) {
        float *position = *(float **)(a0 + 0x1FC);

        func_00335E38(a0 + 0x170, position[0] + ref_L00_0033A688_00,
                      position[1] + D_001ADD0C, 0.0f, 0.0f);
    }
}
