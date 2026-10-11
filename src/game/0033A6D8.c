#include "include_asm.h"

typedef float f32;

typedef unsigned char u8;

typedef int s32;

extern void func_0033AE18(unsigned char *owner, int value);

extern void F624a0727_FUN_00336A78(char *target);

#ifndef RAC2_T_ENTRY_F624A0727
#define RAC2_T_ENTRY_F624A0727
typedef struct { char pad[8]; short n; void (*fn)(char *); } ENTRY_F624a0727;
#endif

extern void F8b17817c_FUN_003361A8(char *block);

extern void F8b17817c_FUN_00336968(char *block);

extern void F8b17817c_FUN_003366D0(char *block);

extern void Ffb202470_FUN_0033AB50(char *p);

extern void Fe524d931_FUN_0033AE28(char *p);

extern void Fe524d931_FUN_0033B018(char *p, float x, float y);

extern void Fe524d931_FUN_002E5E58(int a, int b, int c);

extern void Fe524d931_FUN_00284E40(void);

extern short Fe524d931_D_001A6480[];

extern void Fc558ca70_FUN_0033AE28(char *p);

extern void Fc558ca70_FUN_0033B018(char *p, float a, float b);

extern void Fc558ca70_FUN_002E5E58(int a, int b, int c);

extern volatile unsigned char Fc558ca70_D_001A7B95 __attribute__((sda));

extern volatile unsigned char Fc558ca70_D_001A7B94 __attribute__((sda));

extern void Fb7feb893_FUN_0033AE28(char *p);

extern void Fb7feb893_FUN_0033B018(char *p, float a, float b);

extern void Fb7feb893_FUN_002E5E58(int a, int b, int c);

extern volatile unsigned char Fb7feb893_D_001A7BB2 __attribute__((sda));

extern volatile unsigned char Fb7feb893_D_001A7BB3 __attribute__((sda));

extern void Fb1bbe20c_FUN_0033AE28(char *p);

extern void Fb1bbe20c_FUN_0033B018(char *p, float x, float y);

extern int Fb1bbe20c_FUN_002E5E58(int a, int b, int c);

extern volatile unsigned char Fb1bbe20c_D_001A7BB2 __attribute__((sda));

INCLUDE_ASM("asm/game", func_0033A6D8);

/* Measured target: byte-identical across all 27 levels. */
void func_0033A9C8(u8 *a0, f32 a1) { *(f32 *)(a0 + 0x204) = a1; }

/* lot6 -- measured bodies with sizes recorded in the catalogue. */
void func_0033A9D0(u8 *a0, s32 a1, s32 a2) { a0 += a1 * 4; *(s32 *)(a0 + 0x1B8) = a2; }

/* writes the value if it is below the maximum; byte-identical across all 27 levels. */
void func_0033A9E0(u8 *a0, s32 a1) { if (a1 < *(s32 *)(a0 + 0x1F8)) *(s32 *)(a0 + 0x208) = a1; }

/* Measured target: byte-identical across all 27 levels. */
void func_0033A9F8(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x20c) = a1; }

INCLUDE_ASM("asm/game", func_0033AA00);

INCLUDE_ASM("asm/game", func_0033AB50);

INCLUDE_ASM("asm/game", func_0033ABD0);

INCLUDE_ASM("asm/game", func_0033ABD8);

/* Measured target: byte-identical across all 27 levels. */
void func_0033AE18(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x290) = a1; }

/* Measured target: byte-identical across all 27 levels. */
void func_0033AE20(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x294) = a1; }

INCLUDE_ASM("asm/game", func_0033AE28);

void func_0033AF48(char *object)
{
    char *r = object + 12;
    char *q = object + 60;
    char *p = object + 392;
    int i;

    for (i = 4; i >= 0; i--) {
        if (*(short *)p != 0) {
            ENTRY_F624a0727 *t = *(ENTRY_F624a0727 **)q;
            t->fn(r + t->n);
        }
        r += 76;
        q += 76;
        p += 2;
    }
    if (*(int *)(object + 656) != 0) {
        F624a0727_FUN_00336A78(object + 408);
        if (*(int *)(object + 660) != 0) {
            if (*(int *)(object + 668) != 0)
                F624a0727_FUN_00336A78(object + 552);
            if (*(int *)(object + 664) != 0)
                F624a0727_FUN_00336A78(object + 480);
        }
    }
}

INCLUDE_ASM("asm/game", func_0033B018);

void func_0033B030(u8 *a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6) {
    *(f32 *)(a0 + 0x278) = a1;
    *(f32 *)(a0 + 0x27C) = a2;
    *(f32 *)(a0 + 0x288) = a3;
    *(f32 *)(a0 + 0x28C) = a4;
    *(f32 *)(a0 + 0x280) = a5;
    *(f32 *)(a0 + 0x284) = a6;
}

INCLUDE_ASM("asm/game", func_0033B050);

/* Measured target: byte-identical across all 27 levels. */
void func_0033B0A8(u8 *a0, f32 a1) { *(f32 *)(a0 + 0x274) = a1; }

INCLUDE_ASM("asm/game", func_0033B0B0);

char *func_0033B0B8(char *object)
{
    int index;
    char *block;

    F8b17817c_FUN_003361A8(object);
    F8b17817c_FUN_003361A8(object + 76);
    F8b17817c_FUN_003361A8(object + 152);
    block = object + 228;
    for (index = 2; index != -1; index--) {
        F8b17817c_FUN_003361A8(block);
        block += 76;
    }
    F8b17817c_FUN_00336968(object + 472);
    F8b17817c_FUN_00336968(object + 544);
    F8b17817c_FUN_00336968(object + 616);
    F8b17817c_FUN_003366D0(object + 688);
    F8b17817c_FUN_003366D0(object + 748);
    return object;
}

INCLUDE_ASM("asm/game", func_0033B160);

INCLUDE_ASM("asm/game", func_0033B170);

INCLUDE_ASM("asm/game", func_0033B538);

INCLUDE_ASM("asm/game", func_0033B540);

INCLUDE_ASM("asm/game", func_0033B910);

char *func_0033BD38(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033BD68);

INCLUDE_ASM("asm/game", func_0033BD70);

int func_0033BE98(char *object, int mask)
{
    char *sub = object + 8;
    short oldx;
    short oldy;
    int *v;

    Fe524d931_FUN_0033AE28(sub);
    v = *(int **)(object + 684);
    Fe524d931_FUN_0033B018(sub, *(float *)v, *(float *)(v + 1));
    if ((mask & 0x40) != 0 && *(int *)(object + 680) == 0)
        Fe524d931_FUN_002E5E58(4, 0, 0);
    if ((mask & 0xf000) != 0) {
        short *p = Fe524d931_D_001A6480;
        oldx = p[180];
        oldy = p[181];
        if ((mask & 0x1000) != 0) {
            ((unsigned short *)p)[181] = ((unsigned short *)p)[181] - 1;
            if ((short)((unsigned short *)p)[181] < -32)
                p[181] = -32;
        }
        if ((mask & 0x4000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[181] = q[181] + 1;
            if ((short)q[181] > 32)
                ((short *)q)[181] = 32;
        }
        if ((mask & 0x8000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[180] = q[180] - 1;
            if ((short)q[180] < -40)
                ((short *)q)[180] = -40;
        }
        if ((mask & 0x2000) != 0) {
            unsigned short *q = (unsigned short *)Fe524d931_D_001A6480;
            q[180] = q[180] + 1;
            if ((short)q[180] > 40)
                ((short *)q)[180] = 40;
        }
        {
            short *q = Fe524d931_D_001A6480;
            if (oldx != q[180] || oldy != q[181])
                Fe524d931_FUN_002E5E58(4, 0, 0);
        }
        Fe524d931_FUN_00284E40();
    }
    return (mask >> 6) & 1;
}

INCLUDE_ASM("asm/game", func_0033C028);

char *func_0033C178(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033C1A8);

INCLUDE_ASM("asm/game", func_0033C1B0);

INCLUDE_ASM("asm/game", func_0033C2D8);

INCLUDE_ASM("asm/game", func_0033C378);

char *func_0033C430(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033C460);

INCLUDE_ASM("asm/game", func_0033C468);

INCLUDE_ASM("asm/game", func_0033C590);

INCLUDE_ASM("asm/game", func_0033C738);

char *func_0033C9B8(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033C9E8);

INCLUDE_ASM("asm/game", func_0033C9F0);

int func_0033CB18(char *a0, int a1)
{
    char *p = a0 + 8;
    float *q;
    int v;

    Fc558ca70_FUN_0033AE28(p);
    q = *(float **)(a0 + 684);
    Fc558ca70_FUN_0033B018(p, q[0], q[1]);
    if (a1 & 0x1000) {
        Fc558ca70_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 680);
        *(int *)(a0 + 680) = (v + 1) % 2;
    } else if (a1 & 0x4000) {
        Fc558ca70_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 680);
        *(int *)(a0 + 680) = (v + 1) % 2;
    } else if (a1 & 0x40) {
        Fc558ca70_FUN_002E5E58(4, 0, 0);
        switch (*(int *)(a0 + 680)) {
        case 0:
            Fc558ca70_D_001A7B95 = Fc558ca70_D_001A7B95 == 0;
            break;
        case 1:
            Fc558ca70_D_001A7B94 = Fc558ca70_D_001A7B94 == 0;
            break;
        }
    }
    return (a1 >> 6) & 1;
}

INCLUDE_ASM("asm/game", func_0033CC20);

INCLUDE_ASM("asm/game", func_0033CD80);

INCLUDE_ASM("asm/game", func_0033CDC0);

INCLUDE_ASM("asm/game", func_0033CDC8);

INCLUDE_ASM("asm/game", func_0033D028);

INCLUDE_ASM("asm/game", func_0033D2C0);

char *func_0033D440(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033D470);

INCLUDE_ASM("asm/game", func_0033D478);

INCLUDE_ASM("asm/game", func_0033D5A0);

INCLUDE_ASM("asm/game", func_0033D638);

char *func_0033D708(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033D738);

INCLUDE_ASM("asm/game", func_0033D740);

int func_0033D868(char *a0, int a1)
{
    char *p = a0 + 8;
    float *q;
    int v;

    Fb7feb893_FUN_0033AE28(p);
    q = *(float **)(a0 + 684);
    Fb7feb893_FUN_0033B018(p, q[0], q[1]);
    if (a1 & 0x1000) {
        Fb7feb893_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 680);
        *(int *)(a0 + 680) = (v + 1) % 2;
    } else if (a1 & 0x4000) {
        Fb7feb893_FUN_002E5E58(3, 0, 0);
        v = *(int *)(a0 + 680);
        *(int *)(a0 + 680) = (v + 1) % 2;
    } else if (a1 & 0x40) {
        Fb7feb893_FUN_002E5E58(4, 0, 0);
        switch (*(int *)(a0 + 680)) {
        case 0:
            Fb7feb893_D_001A7BB2 = Fb7feb893_D_001A7BB2 == 0;
            break;
        case 1:
            Fb7feb893_D_001A7BB3 = Fb7feb893_D_001A7BB3 == 0;
            break;
        }
    }
    return (a1 >> 6) & 1;
}

INCLUDE_ASM("asm/game", func_0033D970);

char *func_0033DAD0(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033DB00);

INCLUDE_ASM("asm/game", func_0033DB08);

int func_0033DC30(char *object, int flags)
{
    float *vec;

    Fb1bbe20c_FUN_0033AE28(object + 8);
    vec = *(float **)(object + 684);
    Fb1bbe20c_FUN_0033B018(object + 8, vec[0], vec[1]);

    if ((flags & 0x40) && *(int *)(object + 680) == 0) {
        int discarded = Fb1bbe20c_FUN_002E5E58(4, 0, 0);
        (void)discarded;
        Fb1bbe20c_D_001A7BB2 = (Fb1bbe20c_D_001A7BB2 < 1);
    }

    return (flags >> 6) & 1;
}

INCLUDE_ASM("asm/game", func_0033DCC8);

char *func_0033DD80(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033DDB0);

INCLUDE_ASM("asm/game", func_0033DDB8);

int func_0033DEE0(char *object, int flags)
{
    float *vec;

    Fb1bbe20c_FUN_0033AE28(object + 8);
    vec = *(float **)(object + 684);
    Fb1bbe20c_FUN_0033B018(object + 8, vec[0], vec[1]);

    if ((flags & 0x40) && *(int *)(object + 680) == 0) {
        int discarded = Fb1bbe20c_FUN_002E5E58(4, 0, 0);
        (void)discarded;
        Fb1bbe20c_D_001A7BB2 = (Fb1bbe20c_D_001A7BB2 < 1);
    }

    return (flags >> 6) & 1;
}

char *func_0033DF78(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/game", func_0033DFA8);

INCLUDE_ASM("asm/game", func_0033DFB0);

int func_0033E0D8(char *object, int flags)
{
    float *vec;

    Fb1bbe20c_FUN_0033AE28(object + 8);
    vec = *(float **)(object + 684);
    Fb1bbe20c_FUN_0033B018(object + 8, vec[0], vec[1]);

    if ((flags & 0x40) && *(int *)(object + 680) == 0) {
        int discarded = Fb1bbe20c_FUN_002E5E58(4, 0, 0);
        (void)discarded;
        Fb1bbe20c_D_001A7BB2 = (Fb1bbe20c_D_001A7BB2 < 1);
    }

    return (flags >> 6) & 1;
}
