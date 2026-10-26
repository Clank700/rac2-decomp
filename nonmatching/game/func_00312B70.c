/* near miss: 480/472 B with -frac2-qcopy -frac2-qcopy-barrier. Retail keeps the descriptor pointer in a2 (the call's third argument) and reuses a1 = -1 for both the call and the 0x64 store; this cc1 puts it in t0 and loads -1 into a3 separately (+8 B). Same stores, same order. */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern char *func_0029EFD0(int);
extern void func_002A0F48(char *, int, char *);
extern void func_002AB650(char *);

/* Spawns object 0x27F at the given position and fills its descriptor from a template record. */
char *func_00312B70(char *tmpl, TI128 *pos, int value, TI128 *origin)
{
    char *obj = func_0029EFD0(0x27F);
    char *d;

    if (obj != 0) {
        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned char *)(obj + 0x31) = 1;
        *(unsigned short *)(obj + 0x34) = *(unsigned short *)(obj + 0x34) | 1;
        *(unsigned char *)(obj + 0x20) = 0;
        *(unsigned char *)(obj + 0xBC) = 0;
        d = *(char **)(obj + 0x68);
        *(TI128 *)(obj + 0x10) = *pos;
        if (origin != 0)
            *(TI128 *)d = *origin;
        else
            *(TI128 *)d = *(TI128 *)tmpl;
        *(int *)(d + 0x20) = value;
        *(unsigned short *)(obj + 0x32) = *(unsigned char *)(tmpl + 0x3C);
        *(unsigned char *)(d + 0x24) = *(unsigned char *)(tmpl + 0x10);
        *(unsigned char *)(d + 0x25) = *(unsigned char *)(tmpl + 0x11);
        *(unsigned char *)(d + 0x26) = *(unsigned char *)(tmpl + 0x12);
        *(unsigned char *)(d + 0x27) = *(unsigned char *)(tmpl + 0x13);
        *(unsigned char *)(d + 0x28) = *(unsigned char *)(tmpl + 0x14);
        *(unsigned char *)(d + 0x29) = *(unsigned char *)(tmpl + 0x15);
        *(unsigned char *)(d + 0x68) = *(unsigned char *)(tmpl + 0x3D);
        *(unsigned short *)(d + 0x6C) = *(unsigned short *)(tmpl + 0x40);
        *(unsigned char *)(d + 0x2A) = *(unsigned char *)(tmpl + 0x16);
        *(unsigned char *)(d + 0x2B) = *(unsigned char *)(tmpl + 0x17);
        *(unsigned char *)(d + 0x2C) = *(unsigned char *)(tmpl + 0x18);
        *(unsigned char *)(d + 0x2D) = *(unsigned char *)(tmpl + 0x19);
        *(unsigned char *)(d + 0x2E) = *(unsigned char *)(tmpl + 0x1A);
        *(unsigned char *)(d + 0x69) = *(unsigned char *)(tmpl + 0x3E);
        *(unsigned short *)(d + 0x6E) = *(unsigned short *)(tmpl + 0x42);
        *(unsigned char *)(d + 0x2F) = *(unsigned char *)(tmpl + 0x1B);
        *(unsigned char *)(d + 0x30) = *(unsigned char *)(tmpl + 0x1C);
        *(unsigned char *)(d + 0x31) = *(unsigned char *)(tmpl + 0x1D);
        *(unsigned char *)(d + 0x32) = *(unsigned char *)(tmpl + 0x1E);
        *(unsigned char *)(d + 0x33) = *(unsigned char *)(tmpl + 0x1F);
        *(unsigned char *)(d + 0x6A) = *(unsigned char *)(tmpl + 0x3F);
        *(unsigned short *)(d + 0x70) = *(unsigned short *)(tmpl + 0x44);
        *(float *)(d + 0x34) = *(float *)(tmpl + 0x20);
        *(float *)(d + 0x38) = *(float *)(tmpl + 0x24);
        *(float *)(d + 0x3C) = *(float *)(tmpl + 0x28);
        *(float *)(d + 0x40) = *(float *)(tmpl + 0x2C);
        *(float *)(d + 0x44) = *(float *)(tmpl + 0x30);
        *(unsigned char *)(d + 0x6B) = *(unsigned char *)(tmpl + 0x48);
        *(unsigned short *)(d + 0x72) = *(unsigned short *)(tmpl + 0x46);
        *(int *)(d + 0x48) = *(int *)(tmpl + 0x34);
        *(int *)(d + 0x4C) = *(int *)(tmpl + 0x38);
        *(int *)(d + 0x64) = -1;
        *(unsigned char *)(d + 0x1C) = *(unsigned char *)(tmpl + 0x49);
        func_002A0F48(obj, -1, d);
        func_002AB650(obj);
    }
    return obj;
}
