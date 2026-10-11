#include "include_asm.h"

typedef float f32;

extern int F7cacd225_FUN_00282978(short *p);

extern void F7cacd225_FUN_002B9180(char *o);

extern float F7cacd225_FUN_00283CE0(int n);

extern int F7cacd225_FUN_00283D38(int a, int b, float q);

#ifndef RAC2_T_OBJ_F7CACD225
#define RAC2_T_OBJ_F7CACD225
typedef struct {
    int pad0;
    int f4;
    short pad8;
    short s10;
    float f12;
    float f16;
    float f20;
    float f24;
    int pad28;
    int f32;
} Obj_F7cacd225;
#endif

#ifndef RAC2_T_V4_FC3CB9262
#define RAC2_T_V4_FC3CB9262
typedef int V4_Fc3cb9262 __attribute__((mode(TI)));
#endif

extern void Fc3cb9262_FUN_00282CC0(char *a, char *b, char *c);

extern int Fc3cb9262_FUN_00283CF0(float f);

extern int Fc3cb9262_FUN_00282978(char *a);

extern void Fc3cb9262_FUN_002B9180(char *a);

extern int F250fbfa4_FUN_00282978(char *p);

extern void F250fbfa4_FUN_002B9180(char *p);

extern void F250fbfa4_FUN_00282CC0(char *p0, char *p1, char *p2);

extern int Ff4dd22f3_FUN_00282978(char *p);

extern void Ff4dd22f3_FUN_002B9180(char *p);

extern void Ff4dd22f3_FUN_00282CC0(char *p, char *q, float *v);

extern void Fbdd4a4aa_FUN_00300190(char *a, char *b);

extern void Fbdd4a4aa_FUN_00282CC0(char *a, char *b, char *c);

extern void Fbdd4a4aa_FUN_00282D30(char *a, char *b, float f);

extern void Fbdd4a4aa_FUN_002FE8D8(char *a, char *b);

extern int Fbdd4a4aa_FUN_00283D38(unsigned int a, int b, float f);

extern void Fbdd4a4aa_FUN_002B9180(char *a);

/* Frozen Batch A A15-struct-pad-20; acknowledged claim 6d4515f9ca5619f8d02349c6c2ad116dc989f5a4c317c4d31105f9a9271aa080. */
typedef unsigned char BatchA_A15_u8;

typedef unsigned int BatchA_A15_u32;

extern BatchA_A15_u8 D_L15_001FF640[];

/* Frozen Batch A A10-twin-base-32; acknowledged claim b588059f8808a6607867ee41ec367b24cfb85d2f4cc33273a4392842e34233d5. */
typedef unsigned char BatchA_A10_u8;

typedef unsigned int BatchA_A10_u32;

extern BatchA_A10_u8 D_L03_001FF8C0[];

extern BatchA_A10_u8 D_L03_001FFAC0[];

typedef int s32;

typedef unsigned int u32;

typedef int BatchA_A12_s32;

typedef struct { BatchA_A12_s32 a; BatchA_A12_s32 b; } BatchA_A12_BatchA24;

extern BatchA_A12_BatchA24 D_L08_001FF980;

typedef unsigned char u8;

INCLUDE_ASM("asm/game", func_002C5120);

INCLUDE_ASM("asm/game", func_002C5400);

void func_002C5550(Obj_F7cacd225 *o)
{
    int v;

    if (o->f16 < 2.0f || o->f16 > 1021.0f ||
        o->f20 < 2.0f || o->f20 > 1021.0f ||
        o->f24 < 2.0f || o->f24 > 1021.0f ||
        F7cacd225_FUN_00282978(&o->s10) != 0) {
        F7cacd225_FUN_002B9180((char *)o);
        return;
    }
    v = o->f32;
    if (v != 0) {
        o->f12 = o->f12 * 0.99f;
        o->f4 = F7cacd225_FUN_00283D38(0x30FFFFFF, o->f4, F7cacd225_FUN_00283CE0(o->s10 - 1) / F7cacd225_FUN_00283CE0(o->s10));
    } else {
        o->f12 = o->f12 * 0.95f;
        o->f4 = F7cacd225_FUN_00283D38(0x603F1008, o->f4, F7cacd225_FUN_00283CE0(o->s10 - 1) / F7cacd225_FUN_00283CE0(o->s10));
    }
}

INCLUDE_ASM("asm/game", func_002C56B0);

INCLUDE_ASM("asm/game", func_002C58A8);

INCLUDE_ASM("asm/game", func_002C5B70);

INCLUDE_ASM("asm/game", func_002C5D00);

INCLUDE_ASM("asm/game", func_002C6360);

INCLUDE_ASM("asm/game", func_002C64D8);

INCLUDE_ASM("asm/game", func_002C65A0);

INCLUDE_ASM("asm/game", func_002C6748);

INCLUDE_ASM("asm/game", func_002C6868);

INCLUDE_ASM("asm/game", func_002C6A08);

INCLUDE_ASM("asm/game", func_002C6B68);

INCLUDE_ASM("asm/game", func_002C6DD8);

INCLUDE_ASM("asm/game", func_002C6EF0);

INCLUDE_ASM("asm/game", func_002C7050);

INCLUDE_ASM("asm/game", func_002C72A0);

void func_002C7538(char *a0)
{
    V4_Fc3cb9262 buf;
    char *s0 = a0 + 32;
    float f0;
    float f1;
    float f2;

    f1 = *(float *)(s0 + 16) + 1.0000000474974513053894e-03f;
    f2 = *(float *)(s0 + 8) - 3.0000000260770320892334e-03f;
    *(float *)(s0 + 16) = f1;
    *(float *)(s0 + 8) = f2;
    f0 = *(float *)(s0 + 20) * f1 * 2.1000000000000000000000e+05f;
    buf = *(V4_Fc3cb9262 *)s0;
    *(float *)(a0 + 12) = f0;
    Fc3cb9262_FUN_00282CC0(a0 + 16, a0 + 16, (char *)&buf);
    *(int *)(a0 + 4) = (Fc3cb9262_FUN_00283CF0((float)*(short *)(a0 + 10)) << 24) | 0x00FFD2D2;
    *(unsigned char *)(a0 + 8) = *(unsigned char *)(a0 + 8) + *(unsigned char *)(s0 + 24);
    if (Fc3cb9262_FUN_00282978(a0 + 10) != 0)
        Fc3cb9262_FUN_002B9180(a0);
}

INCLUDE_ASM("asm/game", func_002C7620);

INCLUDE_ASM("asm/game", func_002C7748);

INCLUDE_ASM("asm/game", func_002C7888);

INCLUDE_ASM("asm/game", func_002C7970);

void func_002C7AE8(char *a0)
{
    char local[16];
    char *s1 = a0;
    char *s0;
    int a1;
    int v1;
    char *p;

    if (F250fbfa4_FUN_00282978(a0 + 10) != 0) {
        F250fbfa4_FUN_002B9180(a0);
        return;
    }
    s0 = a0 + 32;
    a1 = *(int *)(s1 + 4);
    v1 = (a1 >> 24) + *(unsigned char *)(s0 + 20);
    *(int *)(s1 + 4) = (a1 & 0x00ffffff) | (v1 << 24);
    p = s1 + 16;
    *(float *)(local + 0) = *(float *)(s1 + 32);
    *(float *)(local + 4) = *(float *)(s0 + 4);
    *(float *)(local + 8) = *(float *)(s0 + 8);
    *(int *)(local + 12) = 0;
    F250fbfa4_FUN_00282CC0(p, p, local);
    *(float *)(s0 + 8) = *(float *)(s0 + 8) - *(float *)(s0 + 12);
    *(unsigned char *)(s1 + 8) = *(unsigned char *)(s1 + 8) + *(unsigned char *)(s0 + 21);
    *(float *)(s1 + 12) = *(float *)(s1 + 12) + *(float *)(s0 + 16);
}

INCLUDE_ASM("asm/game", func_002C7BB8);

void func_002C7D58(char *self)
{
    char *p = self + 32;
    float v[4];
    int a1;

    if (Ff4dd22f3_FUN_00282978(self + 10) != 0)
    {
        Ff4dd22f3_FUN_002B9180(self);
        return;
    }

    a1 = *(int *)(self + 4);
    *(int *)(self + 4) = (a1 & 0xffffff) | (((a1 >> 24) + (int)*(unsigned char *)(p + 20)) << 24);
    v[0] = *(float *)(self + 32);
    v[1] = *(float *)(p + 4);
    v[2] = *(float *)(p + 8);
    v[3] = 0.0f;
    Ff4dd22f3_FUN_00282CC0(self + 16, self + 16, v);
    *(unsigned char *)(self + 8) += *(unsigned char *)(p + 21);
    *(float *)(self + 12) += *(float *)(p + 16);
    *(float *)(p + 8) -= *(float *)(p + 12);
}

INCLUDE_ASM("asm/game", func_002C7E28);

INCLUDE_ASM("asm/game", func_002C7F78);

INCLUDE_ASM("asm/game", func_002C8268);

INCLUDE_ASM("asm/game", func_002C8348);

INCLUDE_ASM("asm/game", func_002C8428);

INCLUDE_ASM("asm/game", func_002C85D8);

INCLUDE_ASM("asm/game", func_002C8610);

void func_002C87B0(char *a0)
{
    char local[16];
    char *s1 = a0;
    char *s0;
    int a1;
    int v1;
    char *p;

    if (F250fbfa4_FUN_00282978(a0 + 10) != 0) {
        F250fbfa4_FUN_002B9180(a0);
        return;
    }
    s0 = a0 + 32;
    a1 = *(int *)(s1 + 4);
    v1 = (a1 >> 24) + *(unsigned char *)(s0 + 20);
    *(int *)(s1 + 4) = (a1 & 0x00ffffff) | (v1 << 24);
    p = s1 + 16;
    *(float *)(local + 0) = *(float *)(s1 + 32);
    *(float *)(local + 4) = *(float *)(s0 + 4);
    *(float *)(local + 8) = *(float *)(s0 + 8);
    *(int *)(local + 12) = 0;
    F250fbfa4_FUN_00282CC0(p, p, local);
    *(float *)(s0 + 8) = *(float *)(s0 + 8) - *(float *)(s0 + 12);
    *(unsigned char *)(s1 + 8) = *(unsigned char *)(s1 + 8) + *(unsigned char *)(s0 + 21);
    *(float *)(s1 + 12) = *(float *)(s1 + 12) + *(float *)(s0 + 16);
}

INCLUDE_ASM("asm/game", func_002C8880);

INCLUDE_ASM("asm/game", func_002C8A38);

INCLUDE_ASM("asm/game", func_002C8CA0);

void func_002C8F40(int *obj)
{
    char *a = (char *)obj + 16;
    char *b = (char *)obj + 32;
    char tmp[16];

    Fbdd4a4aa_FUN_00300190(a, a);
    *(int *)(b + 16) = *(int *)(b + 16) - 1;
    if (*(int *)(b + 16) < 0)
        *(int *)(b + 16) = 0;
    *(unsigned char *)((char *)obj + 8) = *(unsigned char *)((char *)obj + 8) + 1;
    Fbdd4a4aa_FUN_00282CC0(a, b, a);
    *(float *)((char *)obj + 12) = *(float *)((char *)obj + 12) + 1.5750000000000000000000e+03f;
    Fbdd4a4aa_FUN_00282D30(b, b, 9.9000000953674316406250e-01f);
    Fbdd4a4aa_FUN_002FE8D8(a, tmp);
    if ((*(int *)((char *)obj + 4) & 0xFF) < 32) {
        Fbdd4a4aa_FUN_00282D30(tmp, tmp, 1.5000000130385160446167e-03f);
        Fbdd4a4aa_FUN_00282CC0(b, b, tmp);
    } else {
        Fbdd4a4aa_FUN_00282D30(tmp, tmp, -7.5000000651925802230835e-04f);
        Fbdd4a4aa_FUN_00282CC0(b, b, tmp);
    }
    *(int *)((char *)obj + 4) = Fbdd4a4aa_FUN_00283D38(*(unsigned int *)((char *)obj + 4) & 0x00FFFFFF, 0, 2.5000000372529029846191e-02f)
        | (*(int *)(b + 16) << 24);
    if (*(int *)(b + 16) == 0)
        Fbdd4a4aa_FUN_002B9180((char *)obj);
}

INCLUDE_ASM("asm/game", func_002C9098);

INCLUDE_ASM("asm/game", func_002C91E0);

INCLUDE_ASM("asm/game", func_002C9218);

INCLUDE_ASM("asm/game", func_002C94C8);

INCLUDE_ASM("asm/game", func_002C96F8);

INCLUDE_ASM("asm/game", func_002C9820);

INCLUDE_ASM("asm/game", func_002C9828);

INCLUDE_ASM("asm/game", func_002C9A40);

INCLUDE_ASM("asm/game", func_002C9A50);

/* A15-struct-pad-20 freshly exact-verified under family reservation */
void func_002C9A60(void) {
    BatchA_A15_u8 *p = D_L15_001FF640;
    *(BatchA_A15_u32 *)(p + 0xF0) = 0;
    *(BatchA_A15_u32 *)(p + 0x1F0) = 0;
}

/* A10-twin-base-32 freshly exact-verified under family reservation */
void func_002C9A78(void) {
    BatchA_A10_u8 *p = D_L03_001FF8C0;
    *(BatchA_A10_u32 *)(p + 0xF0) = (BatchA_A10_u32)D_L03_001FFAC0;
    *(BatchA_A10_u32 *)(p + 0x1F0) = 1;
}

void func_002C9A98(s32 *a0) {
 s32 *base=a0+3; s32 v;
 do {
  v=--a0[1];
  if(v<=0) v=a0[0];
  a0[1]=v;
 } while(*(s32 *)((u32)base+(v<<2))==0);
}

void func_002C9AD8(s32 *a0) {
 s32 limit=a0[0]; s32 *base=a0+3; s32 v;
 do {
  v=a0[1]+1;
  if(limit<v) v=0;
  a0[1]=v;
 } while(*(s32 *)((u32)base+(v<<2))==0);
}

INCLUDE_ASM("asm/game", func_002C9B18);

INCLUDE_ASM("asm/game", func_002C9B50);

INCLUDE_ASM("asm/game", func_002C9B88);

INCLUDE_ASM("asm/game", func_002C9C20);

INCLUDE_ASM("asm/game", func_002C9C60);

INCLUDE_ASM("asm/game", func_002C9C90);

INCLUDE_ASM("asm/game", func_002C9CF8);

INCLUDE_ASM("asm/game", func_002C9E60);

INCLUDE_ASM("asm/game", func_002C9F68);

INCLUDE_ASM("asm/game", func_002CA070);

INCLUDE_ASM("asm/game", func_002CA5D0);

INCLUDE_ASM("asm/game", func_002CA790);

INCLUDE_ASM("asm/game", func_002CA8A8);

INCLUDE_ASM("asm/game", func_002CAA58);

/* A12-struct-2field-24 freshly exact-verified under family reservation */
void func_002CAA88(void) {
    BatchA_A12_BatchA24 *p = &D_L08_001FF980;
    p->a = 3;
    p->b = 0;
}

INCLUDE_ASM("asm/game", func_002CAAA0);

INCLUDE_ASM("asm/game", func_002CAB00);

INCLUDE_ASM("asm/game", func_002CADB0);

INCLUDE_ASM("asm/game", func_002CAF18);

s32 func_002CB4E8(s32 a0) {
 s32 result=0;
 if(a0<0x15 || a0==0x18) result=1;
 return result;
}

INCLUDE_ASM("asm/game", func_002CB510);

INCLUDE_ASM("asm/game", func_002CB648);

INCLUDE_ASM("asm/game", func_002CB7D0);

INCLUDE_ASM("asm/game", func_002CB820);

INCLUDE_ASM("asm/game", func_002CB8A0);

INCLUDE_ASM("asm/game", func_002CB950);

INCLUDE_ASM("asm/game", func_002CBA58);

INCLUDE_ASM("asm/game", func_002CBAE0);

INCLUDE_ASM("asm/game", func_002CBC58);

INCLUDE_ASM("asm/game", func_002CC490);

INCLUDE_ASM("asm/game", func_002CC528);

INCLUDE_ASM("asm/game", func_002CC550);

INCLUDE_ASM("asm/game", func_002CC690);

INCLUDE_ASM("asm/game", func_002CC698);

s32 func_002CC6A0(u8 *p) { *(s32 *)(p + 0x44) = -1; return 0; }

INCLUDE_ASM("asm/game", func_002CC6B0);

/* shared native body of family 330e1aef */
void func_002CCED0(void)
{
    *(short *)0x001AA8C2 = *(unsigned char *)0x001A7BC9 ? 3 : 0;
    *(short *)0x001AA8DA = *(unsigned char *)0x001A7BCA ? 3 : 0;
    *(short *)0x001AA8F2 = *(unsigned char *)0x001A7BCB ? 3 : 0;
    *(short *)0x001AA90A = *(unsigned char *)0x001A7BCC ? 3 : 0;
    *(short *)0x001AA922 = *(unsigned char *)0x001A7BCE ? 3 : 0;
}

INCLUDE_ASM("asm/game", func_002CCF68);
