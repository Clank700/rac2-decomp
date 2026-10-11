#include "include_asm.h"

/* Measured partial C views; original types and object ownership are unknown. */
typedef unsigned char QwenRecovery_a2544d80ec96_AbiByte22;

extern void func_00342F70(QwenRecovery_a2544d80ec96_AbiByte22 *owner, const QwenRecovery_a2544d80ec96_AbiByte22 *table);

extern int func_00342BC0(unsigned char *owner);

extern void func_00343058(unsigned char *owner);

typedef int s32;

typedef unsigned char u8;

typedef unsigned int u32;

extern void F449e2f67_FUN_003361A8(char *p);

extern void F449e2f67_FUN_00336968(char *p);

extern void F449e2f67_FUN_003366D0(char *p);

/* Update the observed two-axis selection fields and their combined index. */
typedef struct {
    unsigned char gap0[0x43c];
    int column, row, index, mode;
} DobboGridState312;

extern int func_002E5E58(int, unsigned int, void *);

extern void F6402b823_FUN_00336320(char *a);

extern void F6402b823_FUN_00336A78(char *a);

extern void F6402b823_FUN_00335E68(char *a, int b);

extern void F6402b823_FUN_00345268(char *a);

extern void F6402b823_FUN_00345088(char *a);

extern void F6402b823_FUN_00344F98(char *a);

extern void F6402b823_FUN_00345178(char *a);

extern void F6402b823_FUN_00344938(char *a);

extern void Fd1c2476b_FUN_00336320(char *p);

extern void Fd1c2476b_FUN_00336A78(char *p);

extern void Fd1c2476b_FUN_003462A8(char *p);

extern void Fd1c2476b_FUN_003463C8(char *p);

extern void Fd1c2476b_FUN_003464D0(char *p);

extern void F5a9e4f98_FUN_003361A8(char *p);

extern void F5a9e4f98_FUN_003363D0(char *p);

extern void F5a9e4f98_FUN_00336968(char *p);

extern void F5a9e4f98_FUN_003366D0(char *p);

extern unsigned long long func_00347EA0(unsigned long long);

extern unsigned long long func_00336968(unsigned long long);

typedef float f32;

extern void func_00348068(unsigned char *owner, float *records);

extern int func_00348128(unsigned char *);

extern void Faac80289_FUN_003361A8(char *p);

extern void Faac80289_FUN_00336968(char *p);

extern char *D_L00_001A904C_3 __attribute__((sda));

extern void func_00336390(char *dst, char *src, int value);

typedef struct { f32 x, y, z, w; } JammingParameterRow;

typedef struct {
    u8 prefix[0x30];
    JammingParameterRow rows[4];
    f32 weights[3];
} JammingParameterRows;

typedef struct { f32 x, y, z, w; } JammingGridRow;

typedef struct { JammingGridRow rows[3]; } JammingGridGroup;

typedef struct { u8 prefix[0x2c]; JammingGridGroup groups[2]; } JammingGridObject;

/* Measured partial layouts; original type and game roles are unknown. */
typedef struct Rac2Native_79744baad5ad7f65_ScalarChange48Owner {
    unsigned int field_00;
    int value_04;
    unsigned char gap_08[0x3ec];
    int counter_3f4;
    int counter_3f8;
    int previous_3fc;
} Rac2Native_79744baad5ad7f65_ScalarChange48Owner;

extern unsigned char D_0018C0D4[];

void func_00343538(QwenRecovery_a2544d80ec96_AbiByte22 *p1, const QwenRecovery_a2544d80ec96_AbiByte22 *table)
{
    func_00342F70(p1 + 0x298, table);
}

INCLUDE_ASM("asm/game", func_00343558);

int func_00343560(unsigned char *owner)
{
    return func_00342BC0(owner + 0x298);
}

void func_00343580(unsigned char *owner)
{
    func_00343058(owner + 0x298);
}

/* Measured target: byte-identical across all 27 levels. */
void func_003435A0(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x330) = a1; }

/* Measured target: byte-identical across all 27 levels. */
s32 func_003435A8(u8 *a0) { return *(s32 *)(a0 + 0x330); }

void func_003435B0(u8 *a0, u32 a1) {
    if (a1 < 4) *(u32 *)(a0 + 0x294) = a1;
    *(s32 *)(a0 + 0x1a0) = 0;
}

INCLUDE_ASM("asm/game", func_003435C8);

INCLUDE_ASM("asm/game", func_00343638);

INCLUDE_ASM("asm/game", func_00343798);

INCLUDE_ASM("asm/game", func_003438E0);

INCLUDE_ASM("asm/game", func_003438E8);

char *func_003439A0(char *p)
{
    F449e2f67_FUN_003361A8(p);
    F449e2f67_FUN_003361A8(p + 76);
    F449e2f67_FUN_003361A8(p + 152);
    F449e2f67_FUN_003361A8(p + 228);
    F449e2f67_FUN_003361A8(p + 304);
    F449e2f67_FUN_003361A8(p + 380);
    F449e2f67_FUN_00336968(p + 456);
    F449e2f67_FUN_00336968(p + 528);
    F449e2f67_FUN_003366D0(p + 600);
    F449e2f67_FUN_00336968(p + 664);
    F449e2f67_FUN_00336968(p + 736);
    F449e2f67_FUN_00336968(p + 808);
    F449e2f67_FUN_00336968(p + 880);
    F449e2f67_FUN_00336968(p + 952);
    return p;
}

INCLUDE_ASM("asm/game", func_00343A30);

INCLUDE_ASM("asm/game", func_00343EE8);

INCLUDE_ASM("asm/game", func_00343FF8);

/* prioritized masks1000/4000/8000/2000 update signedcolumns43C/rows440 and mode448 with originalevent3 flags0/entitynull; index444=column+2row */
void func_00344160(DobboGridState312 *state, unsigned int buttons)
{
    if (buttons & 0x1000) {
        func_002E5E58(3, 0, 0);
        --state->row;
        if (state->row < 0) {
            if (state->column == 0) {
                state->mode = 2;
                state->row = 1;
                state->column = 3;
            } else if (state->column == 1) {
                state->row = state->column;
            }
        }
    } else if (buttons & 0x4000) {
        int row;
        func_002E5E58(3, 0, 0);
        row = state->row + 1;
        state->row = row > 1 ? 0 : row;
    } else if (buttons & 0x8000) {
        func_002E5E58(3, 0, 0);
        --state->column;
        if (state->column < 0) {
            state->column = 3;
            state->row = 1;
            state->mode = 2;
        }
    } else if (buttons & 0x2000) {
        func_002E5E58(3, 0, 0);
        ++state->column;
        if (state->column >= 2)
            state->column = 0;
    }
    state->index = state->column + state->row * 2;
}

INCLUDE_ASM("asm/game", func_00344298);

INCLUDE_ASM("asm/game", func_00344378);

INCLUDE_ASM("asm/game", func_00344478);

INCLUDE_ASM("asm/game", func_00344848);

INCLUDE_ASM("asm/game", func_00344938);

INCLUDE_ASM("asm/game", func_00344F98);

INCLUDE_ASM("asm/game", func_00345088);

INCLUDE_ASM("asm/game", func_00345178);

INCLUDE_ASM("asm/game", func_00345268);

void func_00345358(char *obj)
{
    if (*(int *)(obj + 1080) != 0) {
        char *s0 = obj + 456;

        F6402b823_FUN_00336320(obj);
        F6402b823_FUN_00336320(obj + 76);
        F6402b823_FUN_00336320(obj + 152);
        F6402b823_FUN_00336320(obj + 228);
        F6402b823_FUN_00336A78(s0);
        F6402b823_FUN_00336A78(obj + 664);
        F6402b823_FUN_00336A78(s0);
        F6402b823_FUN_00335E68(obj + 528, 0);
        F6402b823_FUN_00345268(obj);
        F6402b823_FUN_00345088(obj);
        F6402b823_FUN_00344F98(obj);
        F6402b823_FUN_00345178(obj);
        F6402b823_FUN_00344938(obj);
        F6402b823_FUN_00336320(obj + 380);
    }
}

char *func_00345400(char *p)
{
    F449e2f67_FUN_003361A8(p);
    F449e2f67_FUN_003361A8(p + 76);
    F449e2f67_FUN_003361A8(p + 152);
    F449e2f67_FUN_003361A8(p + 228);
    F449e2f67_FUN_003361A8(p + 304);
    F449e2f67_FUN_003361A8(p + 380);
    F449e2f67_FUN_00336968(p + 456);
    F449e2f67_FUN_00336968(p + 528);
    F449e2f67_FUN_003366D0(p + 600);
    F449e2f67_FUN_00336968(p + 664);
    F449e2f67_FUN_00336968(p + 736);
    F449e2f67_FUN_00336968(p + 808);
    F449e2f67_FUN_00336968(p + 880);
    F449e2f67_FUN_00336968(p + 952);
    return p;
}

INCLUDE_ASM("asm/game", func_00345490);

INCLUDE_ASM("asm/game", func_003458F8);

INCLUDE_ASM("asm/game", func_00345B78);

INCLUDE_ASM("asm/game", func_00345D58);

INCLUDE_ASM("asm/game", func_00345F70);

INCLUDE_ASM("asm/game", func_003462A8);

INCLUDE_ASM("asm/game", func_003463C8);

INCLUDE_ASM("asm/game", func_003464D0);

void func_003465D0(char *a0)
{
    if (*(int *)(a0 + 1160) == 0)
        return;
    Fd1c2476b_FUN_00336320(a0);
    Fd1c2476b_FUN_00336320(a0 + 76);
    Fd1c2476b_FUN_00336320(a0 + 152);
    Fd1c2476b_FUN_00336320(a0 + 228);
    Fd1c2476b_FUN_00336A78(a0 + 456);
    Fd1c2476b_FUN_003462A8(a0);
    Fd1c2476b_FUN_003463C8(a0);
    Fd1c2476b_FUN_003464D0(a0);
    Fd1c2476b_FUN_00336320(a0 + 380);
    Fd1c2476b_FUN_00336A78(a0 + 736);
    Fd1c2476b_FUN_00336A78(a0 + 664);
    Fd1c2476b_FUN_00336A78(a0 + 808);
    Fd1c2476b_FUN_00336A78(a0 + 880);
    Fd1c2476b_FUN_00336A78(a0 + 952);
}

void *func_00346670(char *p)
{
    F5a9e4f98_FUN_003361A8(p);
    F5a9e4f98_FUN_003361A8(p + 0x4c);
    F5a9e4f98_FUN_003361A8(p + 0x98);
    F5a9e4f98_FUN_003361A8(p + 0xe4);
    F5a9e4f98_FUN_003361A8(p + 0x130);
    F5a9e4f98_FUN_003361A8(p + 0x17c);
    F5a9e4f98_FUN_003363D0(p + 0x1c8);
    F5a9e4f98_FUN_00336968(p + 0x210);
    F5a9e4f98_FUN_00336968(p + 0x258);
    F5a9e4f98_FUN_00336968(p + 0x2a0);
    F5a9e4f98_FUN_00336968(p + 0x2e8);
    F5a9e4f98_FUN_00336968(p + 0x330);
    F5a9e4f98_FUN_003366D0(p + 0x378);
    F5a9e4f98_FUN_003361A8(p + 0x3b4);
    F5a9e4f98_FUN_003361A8(p + 0x400);
    F5a9e4f98_FUN_003361A8(p + 0x44c);

    return p;
}

INCLUDE_ASM("asm/game", func_00346710);

INCLUDE_ASM("asm/game", func_00346C60);

INCLUDE_ASM("asm/game", func_003472B8);

INCLUDE_ASM("asm/game", func_00347468);

INCLUDE_ASM("asm/game", func_003478F0);

unsigned long long func_00347EA0(unsigned long long value)
{
    func_00336968(value);
    return value;
}

INCLUDE_ASM("asm/game", func_00347EC8);

INCLUDE_ASM("asm/game", func_00347F80);

INCLUDE_ASM("asm/game", func_00348060);

void func_00348068(u8 *a0,f32 *a1) {
 f32 *end;
 *(f32 **)(a0+0x58)=a1;
 *(s32 *)(a0+0xb0)=0;
 end=a1+0x50;
 if(a1[0]>0.0f) {
  do {
   a1+=5;
   (*(s32 *)(a0+0xb0))++;
  } while(*a1>0.0f && (s32)a1<(s32)end);
 }
 if(*(s32 *)(a0+0x50)>=*(s32 *)(a0+0xb0)) *(s32 *)(a0+0x50)=0;
}

void func_003480D8(u8 *a0, s32 a1, s32 a2) { *(s32 *)(a0 + 0xa8) = a1; *(s32 *)(a0 + 0xac) = a2; }

void func_003480E8(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 0xb8) = param_2;
  return;
}

void func_003480F0(u8 *a0,f32 f0,f32 f1) {
 (*(f32 **)(a0+0x4c))[0]=f0;
 (*(f32 **)(a0+0x4c))[1]=f1;
 (*(s32 **)(a0+0x4c))[2]=0;
 (*(s32 **)(a0+0x4c))[3]=0;
}

/* Measured target: byte-identical across all 27 levels. */
void func_00348118(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x50) = a1; }

/* Measured target: byte-identical across all 27 levels. */
void func_00348120(u8 *a0, s32 a1) { *(s32 *)(a0 + 0xbc) = a1; }

/* Measured target: byte-identical across all 27 levels. */
s32 func_00348128(u8 *a0) { return *(s32 *)(a0 + 0x50); }

/* Measured target: byte-identical across all 27 levels. */
s32 func_00348130(u8 *a0) { return *(s32 *)(a0 + 0xb0); }

INCLUDE_ASM("asm/game", func_00348138);

char *func_003484C8(char *a0)
{
    char *p = a0 + 536;
    int i;

    Faac80289_FUN_003361A8(a0);
    Faac80289_FUN_003361A8(a0 + 76);
    Faac80289_FUN_003361A8(a0 + 152);
    Faac80289_FUN_003361A8(a0 + 228);
    Faac80289_FUN_003361A8(a0 + 304);
    Faac80289_FUN_003361A8(a0 + 380);
    Faac80289_FUN_003361A8(a0 + 456);

    for (i = 6; i != -1; i--) {
        Faac80289_FUN_00336968(p);
        p += 72;
    }
    return a0;
}

INCLUDE_ASM("asm/game", func_00348568);

/* Measured target: byte-identical across all 27 levels. */
void func_00348570(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x448) = a1; }

/* Measured target: byte-identical across all 27 levels. */
void func_00348578(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x44c) = a1; }

/* Forwards one shared global pointer plus a fixed byte offset, together with five distinct fixed offsets of the first object, into the same callee five times, reading one distinct word of the second object each call. */
void func_00348580(char *object, int *values)
{
    func_00336390(object,       D_L00_001A904C_3 + 0x8710, values[0]);
    func_00336390(object + 304, D_L00_001A904C_3 + 0x8710, values[2]);
    func_00336390(object + 76,  D_L00_001A904C_3 + 0x8710, values[4]);
    func_00336390(object + 152, D_L00_001A904C_3 + 0x8710, values[8]);
    func_00336390(object + 228, D_L00_001A904C_3 + 0x8710, values[6]);
}

void func_00348630(u8 *a0, s32 a1, s32 a2) { a0 += a1 * 4; *(s32 *)(a0 + 0x418) = a2; }

INCLUDE_ASM("asm/game", func_00348640);

INCLUDE_ASM("asm/game", func_003486A8);

INCLUDE_ASM("asm/game", func_003489E0);

INCLUDE_ASM("asm/game", func_003489E8);

INCLUDE_ASM("asm/game", func_00348EC0);

INCLUDE_ASM("asm/game", func_00349148);

void func_00349150(s32 *a0) {
 u8 *p=(u8 *)a0+0x50; s32 value=-1; s32 i=15;
 a0[0]=0;a0[0x52]=0;
 do {
  *(s32 *)(p-12)=value;*(s32 *)(p-8)=value;*(s32 *)(p-4)=value;*(s32 *)p=value;
  i--;p+=16;
 }while(i>=0);
 a0[0x54]=0;a0[0x55]=0;
}

INCLUDE_ASM("asm/game", func_00349190);

void func_00349488(int *param_1)
{
    param_1[0x150 / sizeof(int)] = 0;
}

/* Measured target: byte-identical across all 27 levels. */
void func_00349490(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x144) = a1; }

u8 *func_00349498(u8 *a0) {
 s32 *p=(s32 *)(a0+0x30);s32 i=3;
 do {
  p[0]=0;p[1]=0;p[2]=0;p[3]=0;
  i--;p+=4;
 }while(i!=-1);
 return a0;
}

INCLUDE_ASM("asm/game", func_003494D0);

INCLUDE_ASM("asm/game", func_00349588);

/* Measured target: byte-identical across all 27 levels. */
void func_00349590(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x2c) = a1; }

INCLUDE_ASM("asm/game", func_00349598);

INCLUDE_ASM("asm/game", func_003495A0);

INCLUDE_ASM("asm/game", func_003495B8);

/* Measured target: byte-identical across all 27 levels. */
void func_003495C0(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x80) = a1; }

s32 func_003495C8(u8 *a0, s32 a1) { s32 vieux = *(s32 *)(a0 + 0x28); *(s32 *)(a0 + 0x28) = a1; return vieux; }

/* Store an indexed four-component parameter row and its float weight */
void func_003495D8(f32 weight, f32 x, f32 y, f32 z, f32 w, JammingParameterRows *object, s32 index) {
    object->rows[index].x = x;
    object->rows[index].y = y;
    object->rows[index].z = z;
    object->rows[index].w = w;
    object->weights[index] = weight;
}

INCLUDE_ASM("asm/game", func_00349610);

void func_00349628(int param_1, int param_2) {
    *(int *)(param_1 + 0x84) = param_2;
}

void func_00349630(u8 *a0,s32 a1) {
 *(s32 *)(a0+0x1c)=a1;
 if(*(s32 *)(a0+0x28)==0) {
  if(a1==1) *(f32 *)(a0+0x18)=0.0f;
  else *(f32 *)(a0+0x18)=1.0f;
  *(s32 *)(a0+0x28)=1;
 }
}

void func_00349670(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 32) = param_2;
  return;
}

/* Measured target: byte-identical across all 27 levels. */
void func_00349678(u8 *a0, f32 a1) { *(f32 *)(a0 + 0x24) = a1; }

INCLUDE_ASM("asm/game", func_00349680);

u8 *func_00349918(u8 *a0) {
 s32 *p=(s32 *)(a0+0x2c); s32 i=1;
 do {
  s32 *end=p+12;
  s32 next=i-1;
  s32 j=2;
  do {
   p[0]=0;p[1]=0;p[2]=0;p[3]=0;
   j--;p+=4;
  } while(j!=-1);
  i=next;p=end;
 } while(i!=-1);
 return a0;
}

INCLUDE_ASM("asm/game", func_00349968);

INCLUDE_ASM("asm/game", func_00349970);

INCLUDE_ASM("asm/game", func_00349A58);

void func_00349A60(u8 *a0, s32 a1, s32 a2) { a0 += a1 * 4; *(s32 *)(a0 + 0x20) = a2; }

/* Store four float components in a selected row of a parameter group */
void func_00349A70(f32 x, f32 y, f32 z, f32 w, JammingGridObject *object, s32 row, s32 group) {
    object->groups[group].rows[row].x = x;
    object->groups[group].rows[row].y = y;
    object->groups[group].rows[row].z = z;
    object->groups[group].rows[row].w = w;
}

void func_00349AA8(u8 *a0, s32 a1, s32 a2) { a0 += a1 * 4; *(s32 *)(a0 + 0x8C) = a2; }

void func_00349AB8(u8 *a0,s32 a1) {
 if(a1!=0) *(f32 *)(a0+0x10)=1.0f;
 else *(f32 *)(a0+0x10)=0.0f;
 *(s32 *)(a0+0x14)=1;
 *(s32 *)(a0+0x1c)=1;
}

void func_00349AE0(u8 *a0,s32 a1) {
 if(a1!=0) *(f32 *)(a0+0x10)=0.0f;
 else *(f32 *)(a0+0x10)=1.0f;
 *(s32 *)(a0+0x14)=-1;
 *(s32 *)(a0+0x1c)=1;
}

/* Measured target: byte-identical across all 27 levels. */
void func_00349B18(u8 *a0, f32 a1) { *(f32 *)(a0 + 0x18) = a1; }

INCLUDE_ASM("asm/game", func_00349B20);

INCLUDE_ASM("asm/game", func_00349CB8);

INCLUDE_ASM("asm/game", func_00349D50);

INCLUDE_ASM("asm/game", func_00349D58);

INCLUDE_ASM("asm/game", func_0034A4A0);

/* Measured target: byte-identical across all 27 levels. */
void func_0034A4A8(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x0) = a1; }

/* Replace the value at offset 0x04 and, when it changes while the bound debug byte is zero, retain the previous value and set the two counters to 180 and 300; original game role is unknown. */
void func_0034A4B0(Rac2Native_79744baad5ad7f65_ScalarChange48Owner *owner, int value)
{
    int previous = owner->value_04;
    if (previous != value && D_0018C0D4[0] == 0) {
        owner->previous_3fc = previous;
        owner->counter_3f8 = 180;
        owner->counter_3f4 = 300;
    }
    owner->value_04 = value;
}

INCLUDE_ASM("asm/game", func_0034A4E0);

INCLUDE_ASM("asm/game", func_0034A808);

INCLUDE_ASM("asm/game", func_0034AA30);

INCLUDE_ASM("asm/game", func_0034AC10);

INCLUDE_ASM("asm/game", func_0034AD10);

void func_0034AFE8(u8 *a0, f32 a1, f32 a2) {
    *(f32 *)*(u8 **)(a0 + 0x8) = a1;
    *(f32 *)(*(u8 **)(a0 + 0x8) + 0x4) = a2;
}

INCLUDE_ASM("asm/game", func_0034B000);

INCLUDE_ASM("asm/game", func_0034B068);

INCLUDE_ASM("asm/game", func_0034B070);
