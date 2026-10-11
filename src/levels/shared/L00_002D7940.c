#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

typedef float f32;

extern void func_002B00D8(char *a, char *b, char *c, f32 d);

extern void func_00282CC0_5(char *a, char *b, char *c);

extern void func_00283098_1(char *a, char *b, char *c);

extern void func_00283958(char *a, char *b);

extern void func_00283738(char *a, char *b, char *c);

extern void func_00282CF0_4(char *a, char *b, char *c);

#ifndef RAC2_T_V4_F4778F810
#define RAC2_T_V4_F4778F810
typedef struct {
    f32 x, y, z, w;
} V4_F4778f810;
#endif

#ifndef RAC2_T_SUB_F4778F810
#define RAC2_T_SUB_F4778F810
typedef struct {
    u8 pad000[0x10];
    u8 at010[0x10];
    u8 at020[0x28];
    f32 f048;
} Sub_F4778f810;
#endif

#ifndef RAC2_T_OBJ_F4778F810
#define RAC2_T_OBJ_F4778F810
typedef struct {
    u8 pad000[0x10];
    u8 at010[0x58];
    char *p068;
    u8 pad06C[0xC0 - 0x6C];
    u8 at0C0[0x10];
} Obj_F4778f810;
#endif

extern void func_00284EA8(void);

typedef long s64;

extern void func_002CBC58(s64);

/* clear five object fields; independently qualified in this overlay */
void func_L00_002D7940(s32 *object) {
    object[0]=0; object[1]=0; object[2]=0; object[3]=0; object[4]=0;
}

INCLUDE_ASM("asm/levels", func_L00_002D7958);

INCLUDE_ASM("asm/levels", func_L00_002D7D58);

INCLUDE_ASM("asm/levels", func_L00_002D8208);

INCLUDE_ASM("asm/levels", func_L00_002D9D48);

INCLUDE_ASM("asm/levels", func_L00_002D9D98);

INCLUDE_ASM("asm/levels", func_L00_002D9E80);

INCLUDE_ASM("asm/levels", func_L00_002DA0B8);

INCLUDE_ASM("asm/levels", func_L00_002DA1E0);

INCLUDE_ASM("asm/levels", func_L00_002DA390);

INCLUDE_ASM("asm/levels", func_L00_002DB350);

INCLUDE_ASM("asm/levels", func_L00_002DB4B8);

/* Return the constant signed integer one. */
/* Returns the constant integer 1. Matches FUN_0012F940 disassembly and decompilation. */
int func_L00_002DC3D0(void) {
    return 1;
}

/* Return the constant signed integer one. */
/* Returns the constant integer 1. Matches FUN_0012F940 disassembly and decompilation. */
int func_L00_002DC3D8(void) {
    return 1;
}

/* Drives eight calls over a parameter object: loads the pointer at +104, builds four 16-byte stack scratch records at sp+0/+16/+32/+48, and passes the object's +16 and +192 regions to the callees. */
void func_L00_002DC3E0(Obj_F4778f810 *obj)
{
    V4_F4778f810 tmp[6];
    Sub_F4778f810 *p = (Sub_F4778f810 *)obj->p068;

    func_002B00D8((char *)obj + 0x10, (char *)p, (char *)p, p->f048);
    func_00282CC0_5((char *)obj + 0x10, (char *)obj + 0x10, (char *)p);
    func_00283098_1((char *)&tmp[0], (char *)p + 0x20, (char *)obj + 0xC0);
    func_00283958((char *)p + 0x10, (char *)&tmp[3]);
    func_00283738((char *)obj + 0xC0, (char *)&tmp[3], (char *)obj + 0xC0);
    func_00283098_1((char *)&tmp[1], (char *)p + 0x20, (char *)obj + 0xC0);
    func_00282CF0_4((char *)&tmp[2], (char *)&tmp[1], (char *)&tmp[0]);
    func_00282CF0_4((char *)obj + 0x10, (char *)obj + 0x10, (char *)&tmp[2]);
}

/* Drives eight calls over a parameter object: loads the pointer at +104, builds four 16-byte stack scratch records at sp+0/+16/+32/+48, and passes the object's +16 and +192 regions to the callees. */
void func_L00_002DC4C0(Obj_F4778f810 *obj)
{
    V4_F4778f810 tmp[6];
    Sub_F4778f810 *p = (Sub_F4778f810 *)obj->p068;

    func_002B00D8((char *)obj + 0x10, (char *)p, (char *)p, p->f048);
    func_00282CC0_5((char *)obj + 0x10, (char *)obj + 0x10, (char *)p);
    func_00283098_1((char *)&tmp[0], (char *)p + 0x20, (char *)obj + 0xC0);
    func_00283958((char *)p + 0x10, (char *)&tmp[3]);
    func_00283738((char *)obj + 0xC0, (char *)&tmp[3], (char *)obj + 0xC0);
    func_00283098_1((char *)&tmp[1], (char *)p + 0x20, (char *)obj + 0xC0);
    func_00282CF0_4((char *)&tmp[2], (char *)&tmp[1], (char *)&tmp[0]);
    func_00282CF0_4((char *)obj + 0x10, (char *)obj + 0x10, (char *)&tmp[2]);
}

INCLUDE_ASM("asm/levels", func_L00_002E0200);

INCLUDE_ASM("asm/levels", func_L00_002E2048);

INCLUDE_ASM("asm/levels", func_L00_002E2958);

INCLUDE_ASM("asm/levels", func_L00_002E2C30);

INCLUDE_ASM("asm/levels", func_L00_002E30B8);

INCLUDE_ASM("asm/levels", func_L00_002E3340);

INCLUDE_ASM("asm/levels", func_L00_002E3520);

INCLUDE_ASM("asm/levels", func_L00_002E36F8);

INCLUDE_ASM("asm/levels", func_L00_002E3898);

/* evaluates (b-a)*(t*t)+a*t and converts the measured float result to a signed word */
s32 func_L00_002E3A68(f32 a,f32 b,f32 t) {
 f32 difference=b-a;
 f32 squared=t*t;
 a=a*t;
 difference=difference*squared;
 a=a+difference;
 return (s32)a;
}

INCLUDE_ASM("asm/levels", func_L00_002E3A90);

INCLUDE_ASM("asm/levels", func_L00_002E3B38);

INCLUDE_ASM("asm/levels", func_L00_002E3BA0);

INCLUDE_ASM("asm/levels", func_L00_002E3DB8);

INCLUDE_ASM("asm/levels", func_L00_002E54E0);

/* calls the measured no-argument callee */
void func_L00_002E5918(void) {
 func_00284EA8();
}

INCLUDE_ASM("asm/levels", func_L00_002E6348);

INCLUDE_ASM("asm/levels", func_L00_002E6400);

INCLUDE_ASM("asm/levels", func_L00_002E6440);

/* calls the measured callee with zero */
void func_L00_002E6448(void) {
 func_002CBC58(0);
}

INCLUDE_ASM("asm/levels", func_L00_002E6CF0);

INCLUDE_ASM("asm/levels", func_L00_002E6D40);

INCLUDE_ASM("asm/levels", func_L00_002E6DB8);

INCLUDE_ASM("asm/levels", func_L00_002E6E08);

INCLUDE_ASM("asm/levels", func_L00_002E6E80);

INCLUDE_ASM("asm/levels", func_L00_002E6EF8);

INCLUDE_ASM("asm/levels", func_L00_002E6F48);

INCLUDE_ASM("asm/levels", func_L00_002E73E0);

INCLUDE_ASM("asm/levels", func_L00_002E7F98);

INCLUDE_ASM("asm/levels", func_L00_002E8120);

INCLUDE_ASM("asm/levels", func_L00_002E8428);

INCLUDE_ASM("asm/levels", func_L00_002E8DD8);

INCLUDE_ASM("asm/levels", func_L00_002E9098);

INCLUDE_ASM("asm/levels", func_L00_002E90A8);

INCLUDE_ASM("asm/levels", func_L00_002E9100);

INCLUDE_ASM("asm/levels", func_L00_002E9120);

INCLUDE_ASM("asm/levels", func_L00_002E9140);

INCLUDE_ASM("asm/levels", func_L00_002E9210);

INCLUDE_ASM("asm/levels", func_L00_002E94B8);

INCLUDE_ASM("asm/levels", func_L00_002E95C0);

INCLUDE_ASM("asm/levels", func_L00_002E9AA0);

INCLUDE_ASM("asm/levels", func_L00_002EA318);

INCLUDE_ASM("asm/levels", func_L00_002EA600);

INCLUDE_ASM("asm/levels", func_L00_002EA660);

INCLUDE_ASM("asm/levels", func_L00_002EA668);

INCLUDE_ASM("asm/levels", func_L00_002EA708);

INCLUDE_ASM("asm/levels", func_L00_002EBE88);

INCLUDE_ASM("asm/levels", func_L00_002EC230);

INCLUDE_ASM("asm/levels", func_L00_002EC248);

INCLUDE_ASM("asm/levels", func_L00_002EC608);

INCLUDE_ASM("asm/levels", func_L00_002EC970);

INCLUDE_ASM("asm/levels", func_L00_002ECFE8);

INCLUDE_ASM("asm/levels", func_L00_002ED3F0);

void func_L00_002ED420(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_002ED7F8);

INCLUDE_ASM("asm/levels", func_L00_002ED808);

INCLUDE_ASM("asm/levels", func_L00_002EDC90);

INCLUDE_ASM("asm/levels", func_L00_002EDCB8);

INCLUDE_ASM("asm/levels", func_L00_002EDCC8);

INCLUDE_ASM("asm/levels", func_L00_002EDCF0);

INCLUDE_ASM("asm/levels", func_L00_002EDD00);

INCLUDE_ASM("asm/levels", func_L00_002EDD28);

INCLUDE_ASM("asm/levels", func_L00_002EDD38);

INCLUDE_ASM("asm/levels", func_L00_002EE050);

INCLUDE_ASM("asm/levels", func_L00_002EE058);

INCLUDE_ASM("asm/levels", func_L00_002EE078);

INCLUDE_ASM("asm/levels", func_L00_002EE0C0);

INCLUDE_ASM("asm/levels", func_L00_002EE290);

INCLUDE_ASM("asm/levels", func_L00_002EE340);

INCLUDE_ASM("asm/levels", func_L00_002EE4D8);

INCLUDE_ASM("asm/levels", func_L00_002EE660);

INCLUDE_ASM("asm/levels", func_L00_002EF548);

INCLUDE_ASM("asm/levels", func_L00_002EF688);

INCLUDE_ASM("asm/levels", func_L00_002F0498);
