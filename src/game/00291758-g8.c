#include "include_asm.h"

extern int D_001B1B40 __attribute__((section(".sdata")));
extern int D_001B1B44 __attribute__((section(".sdata")));
extern unsigned char D_001CE4E0[];
extern short D_001CE300[];
extern char *D_001CDB80[];
extern int D_001D0E00[];
extern void func_002B65B8(int, int);
extern void func_002934F8(char *, int, int, int);

void func_00293890(char *object, int a, int b, int id)
{
    if (object == 0) {
        func_002B65B8(id, 1);
        D_001CE4E0[id] = *(unsigned char *)&D_001B1B44;
        D_001B1B44 = D_001B1B44 + 1;
    } else {
        D_001CE300[D_001B1B40] = id;
        D_001CE4E0[id] = *(unsigned char *)&D_001B1B40;
        D_001CDB80[D_001B1B40] = object;
        D_001D0E00[D_001B1B40] = (unsigned char)object[0x2D] << 10;
        if ((unsigned char)object[0x2D] == 255)
            D_001D0E00[D_001B1B40] = 0x100000;
        func_002B65B8(id, 0);
        ++D_001B1B40;
        func_002934F8(object, a, b, id);
    }
}
