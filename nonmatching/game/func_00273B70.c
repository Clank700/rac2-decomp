/* Near miss (mid-16): one register differs. Structure and every instruction match except the hi half of the D_001B1688 load: ours uses lui $v1, retail lui $v0. Variants tried: array [0], unsigned, nested ifs, local copy.
   Needs the unit flags: default (-O2 -G0 -ffunction-sections) */
#include "common.h"

extern unsigned D_001B1688[];

extern int func_00274C90(char *, void *, int);
extern int func_0029F840(char *, void *, void *, int);
extern int func_00273D10(char *);
extern int func_00273E98(char *);
extern int func_00274118(char *);
extern int func_00274120(char *);
extern int func_00282978(void *);

int func_00273B70(char *self)
{
    unsigned char *s0 = *(unsigned char **)(self + 0x68);
    char buf[0x200];
    char vec[0x10];
    int s2 = 0;

    switch (s0[0x5D]) {
    case 0:
    case 2:
        if (s0[0x5D] == 0)
            s0[0x58] = func_00274C90(self, buf, 0x20);
        else
            func_0029F840(self, vec, buf, *(short *)(s0 + 0x36));
        *(char **)(s0 + 0x30) = buf;
        s2 = func_00273D10(self);
        if (s0[0x5C] == 0 && (D_001B1688[0] & 3) != 0) {
        } else if (func_00282978(s0 + 0x34) != 0)
            s2 = 1;
        *(int *)(s0 + 0x30) = 0;
        break;
    case 4:
        s2 = func_00274118(self);
        break;
    case 5:
        s2 = func_00274120(self);
        break;
    case 1:
    case 3:
        s2 = func_00273E98(self);
        if (func_00282978(s0 + 0x34) != 0)
            s2 = 1;
        break;
    }
    if (*(float *)(self + 0x10) < 2.0f || *(float *)(self + 0x10) > 1021.0f
        || *(float *)(self + 0x14) < 2.0f || *(float *)(self + 0x14) > 1021.0f
        || *(float *)(self + 0x18) < 2.0f || *(float *)(self + 0x18) > 1021.0f)
        return 1;
    return s2;
}
