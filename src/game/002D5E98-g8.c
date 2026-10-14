#include "include_asm.h"
extern void func_0028FC48(int, int, int, int, unsigned long, int);
extern int func_0028E588(int, int);
extern void func_0028E868(int, int, int, int, int, int);
extern int D_001AA43C __attribute__((sda));

void func_002D9CF8(int x, int y, int show)
{
    func_0028FC48(x - 5, y - 5, x + 5, y + 5, 0x80FFA888UL, 0);
    func_0028FC48(x - 4, y - 4, x + 4, y + 4, D_001AA43C, 0);
    if (show)
        func_0028E868(func_0028E588(0xE99D, 1), x - 13, y - 18, 30, 30, 128);
}

extern int ref_L00_002D68D8_00 __attribute__((sda));
extern int func_00283D38(int, int, float);
int func_002D68D8(int start, int first, int second)
{
    int count;
    float fraction;
    if (start < 0) start = 0;
    if (first == -1) first = (int)0x80FFA888u;
    if (second == -1) second = (int)0x8020FFFFu;
    count = ref_L00_002D68D8_00;
    if (count >= start)
        fraction = 1.0f - (float)(count - start) / (float)count;
    else
        fraction = 1.0f;
    return func_00283D38(first, second, fraction);
}

extern int func_002DE3A0(int);
extern int func_002DE550(int);
extern int func_002C9A60(void);
extern void func_00287E80(void);
extern void func_00339760(void *);
extern volatile int D_001A8C88;
extern char *D_001A8CFC __attribute__((sda));

int func_002DCAB8(char *object)
{
    func_002DE3A0(1);
    *(int *)(object + 0x48) = func_002DE550(0);
    *(int *)(object + 0x4C) = 0;
    func_002C9A60();
    func_00287E80();
    if (D_001A8C88 != 0 && D_001A8CFC != 0)
        func_00339760(D_001A8CFC + 0x3CAA8);
    return 0;
}
