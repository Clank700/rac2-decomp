#include "include_asm.h"

extern char *D_001AF880 __attribute__((sda));

void func_00317390(void)
{
    char *p = D_001AF880;
    if (p != 0) {
        char *q = *(char **)(p + 0x68);
        *(int *)(q + 0x28) = 1;
    }
}

/* The engine's vector of four floats; its own type is not named here. */
typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec4f_0030F7B0;

/* The level's own settings: every program keeps them at its own addresses, so the
   names state the level 00 ones only. */
extern float D_L00_001B8DC0[4];
extern float D_L00_001AF4E4 __attribute__((sda));
extern float D_L00_001AF4E8 __attribute__((sda));
extern unsigned char D_L00_001AF4EC __attribute__((sda));
extern int D_L00_001AF4F0 __attribute__((sda));
extern int D_L00_001AF4F4 __attribute__((sda));
extern int D_L00_001AF4F8 __attribute__((sda));
extern float D_L00_001AF4FC __attribute__((sda));
extern float D_L00_001AF500 __attribute__((sda));
extern float D_0018A0E0[4];

extern void func_00282CF0(float *, float *, float *);
extern void func_00282D30(float *, float *, float);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern void func_002ACEC0(void *, void *, void *, float);
extern int func_002A77E0(int);
extern void func_002C3150(void *, void *, int, int, int, int, float);

void func_003130F0(unsigned char *self)
{
    Vec4f_0030F7B0 v0;
    Vec4f_0030F7B0 v1;
    Vec4f_0030F7B0 v2;
    unsigned char *data;
    unsigned char b;
    int val;
    int r;

    data = *(unsigned char **)(self + 0x68);
    func_00282CF0(&v0, D_L00_001B8DC0, (float *)(self + 0x10));
    func_00282D30(&v1, D_0018A0E0, func_002A7878(D_L00_001AF4E4 * 0.016666668f, D_L00_001AF4E8 * 0.016666668f));
    func_002ACEC0(&v2, &v1, &v0, func_002A7940());
    if (data[0x57] != 0)
        val = D_L00_001AF4F8;
    else
        val = D_L00_001AF4F0;
    b = D_L00_001AF4EC;
    r = func_002A77E0(255);
    func_002C3150(self + 0x10, &v2, val, b, r & 0xFF, 1, D_L00_001AF4FC);
    b = D_L00_001AF4EC;
    r = func_002A77E0(255);
    func_002C3150(self + 0x10, &v2, D_L00_001AF4F4, b, r & 0xFF, 1, D_L00_001AF500);
}
