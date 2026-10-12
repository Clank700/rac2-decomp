#include "include_asm.h"

/* Big level-side array: keep the absolute materialisation (`lui+addiu`), never $gp. */
extern unsigned char D_L03_00189E20[] __attribute__((nosda));

extern float D_L03_001AEF64 __attribute__((sda));

extern int D_L03_001B2548;
extern int D_L03_001A9028;
extern int D_L03_001A9024;
extern int D_L03_001C63A8[] __attribute__((nosda));

extern void func_2EF020(unsigned char *, unsigned char *, float);

extern void func_2EEFB0(unsigned char *, unsigned char *, unsigned char *);

void func_L03_0038A9D0(unsigned char *a0, unsigned char *a1) {
    unsigned char *q = a1;
    unsigned char *p = a0;

    func_2EF020(q, p + 0xC0, D_L03_001AEF64);
    func_2EEFB0(q, q, p + 0x10);
}

void func_L03_0032AD10(int a0) {
    if (D_L03_001B2548 != D_L03_001A9028) {
        D_L03_001A9028 = D_L03_001B2548;
        D_L03_001A9024 = 0;
    }
    if (D_L03_001A9024 < 0x20) {
        D_L03_001C63A8[D_L03_001A9024] = a0;
        D_L03_001A9024 = D_L03_001A9024 + 1;
    }
}

