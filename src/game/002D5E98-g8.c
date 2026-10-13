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
