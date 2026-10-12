#include "include_asm.h"

/* Measured partial layouts; original type and game roles are unknown. */
typedef unsigned int Rac2Native_3e18d05650488ad4_FallbackU32;

extern Rac2Native_3e18d05650488ad4_FallbackU32 D_001A7424;

extern int D_001A7420_1;

extern void func_L00_00309AE8(void);

extern void func_L00_00309B10(void);

extern void func_L00_00309B80(void);

extern int D_L00_001A904C;

extern void func_0028A2F8(int);

extern int D_L00_001A904C;

extern void func_0028A670(int);

void func_L00_00309AE8(void)
{
    int flags = (int)D_001A7424;
    if ((flags & 0x40) == 0) {
        D_001A7420_1 = 3;
    }
}

void func_L00_00309B10(void)
{
    int flags = (int)D_001A7424;
    if ((flags & 0x40) == 0) {
        D_001A7420_1 = 3;
    }
}

void func_L00_00309B80(void)
{
    int flags = (int)D_001A7424;
    if ((flags & 0x40) == 0) {
        D_001A7420_1 = 3;
    }
}

void func_L00_0030DC30(int argument)
{
    if (D_L00_001A904C != 0) {
        func_0028A2F8(argument);
    }
}

void func_L00_0030DC58(int argument)
{
    if (D_L00_001A904C != 0) {
        func_0028A670(argument);
    }
}
