#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

typedef float f32;

/* The campaign: call-bearing bodies reproduced by the reconstructed toolchain
   (2.9-ee + refined gas) -- sd saves in 8-byte slots,
   no sibcall, the s32 return prototype determines v0 versus v1, and || chains
   with a shared exit. Measurements and evidence: docs/COMPILER-NOTES.md. */

/* func_002A77E0 : random draw bounded by the argument */
extern s32 func_001163B0(void);

struct family_27f9_object {
    unsigned char reserved[248];
    float heading;
};

extern float F27f9be8e_FUN_00283BE0(float p, float x);

extern float F27f9be8e_FUN_00282C48(float t);

extern float F27f9be8e_FUN_00283B98(float x, float y);

typedef struct { f32 x,y,z,w; } MmiPoint;

/* The 16-byte store is written through a volatile quad pointer. Without the
   qualifier the compiler moves the quad store into the return's delay slot,
   which the retail build does not do; the qualifier is what keeps the store
   ahead of the return. The alternative idiom used by the RAC1 corpus is inline
   assembly, which the candidate gate refuses. */
/* The copy itself goes through a 128-bit integer type, not the aggregate:
   the reconstructed 2.9-ee compiler reaches lq/sq only through TImode (the
   aggregate path builds ld/sd pairs or a memcpy call). Same bytes as the
   retail (`lq $v0,0($a3); sq $v0,0($a0)`). */

typedef struct { int a, b, c, d; } __attribute__((aligned(16))) Quad16;

typedef int TI128 __attribute__((mode(TI)));

#ifndef RAC2_T_V4_F5621621C
#define RAC2_T_V4_F5621621C
typedef int V4_F5621621c __attribute__((mode(TI)));
#endif

extern float F5621621c_FUN_00283248(float a, float b);

extern float F5621621c_FUN_00283180(float a);

extern float F5621621c_FUN_00283198(float a);

extern void F5621621c_FUN_002A8E20(int v, void *rec);

#ifndef RAC2_T_VEC16_F5621621C
#define RAC2_T_VEC16_F5621621C
typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec16_F5621621c;
#endif

#ifndef RAC2_T_NODE_F5621621C
#define RAC2_T_NODE_F5621621C
typedef struct {
    char pad[16];
    float f16;
    float f20;
} Node_F5621621c;
#endif

#ifndef RAC2_T_REC_F5621621C
#define RAC2_T_REC_F5621621C
typedef struct {
    float f0;
    float f4;
    float f8;
    float f12;
    int i16;
    int i20;
    signed char b24;
    signed char b25;
    unsigned short h26;
    float f28;
    int i32;
} Rec_F5621621c;
#endif

extern float Ff454dd77_FUN_00282C48(float a);

#ifndef RAC2_T_OBJ_FF454DD77
#define RAC2_T_OBJ_FF454DD77
typedef struct {
    float f0;
} Obj_Ff454dd77;
#endif

extern void Fa5914967_FUN_00282F20(float *a, float *b, float c);

/* lot14 -- measured bodies with sizes recorded in the catalogue. */
extern u8 D_0018C0B0[];

extern float F500f9762_FUN_00283CE0(int index);

extern int F500f9762_FUN_00283CF0(float value);

extern void F500f9762_FUN_002A04B8(int first, char *a, char *b, char *c);

extern int D_L02_001B359C __attribute__((sda));

#ifndef RAC2_T_V4_F904CC63B
#define RAC2_T_V4_F904CC63B
typedef __attribute__((mode(TI))) int V4_F904cc63b;
#endif

extern char *F904cc63b_FUN_002AD0B0(char *p);

extern void F904cc63b_FUN_00283410(V4_F904cc63b *dst, char *src);

extern void F904cc63b_FUN_00282CC0(V4_F904cc63b *dst, V4_F904cc63b *a, char *b);

extern void F904cc63b_FUN_00282CF0(V4_F904cc63b *dst, V4_F904cc63b *a, char *b);

extern void F904cc63b_FUN_00283698(V4_F904cc63b *dst, V4_F904cc63b *src);

extern void F904cc63b_FUN_00283098(V4_F904cc63b *dst, V4_F904cc63b *a, V4_F904cc63b *b);

/* Family 0e7bb6a8908d30dc -- 244 bytes, 28 placements (1 boot + 27 levels). */

extern char *F0e7bb6a8_FUN_002AD0B0(char *a);

extern void F0e7bb6a8_FUN_00283410(char *dst, char *src);

extern void F0e7bb6a8_FUN_00283698(char *dst, char *src);

extern void F0e7bb6a8_FUN_00282CF0(char *dst, char *a, char *b);

extern void F0e7bb6a8_FUN_002830C0(char *a, char *b, char *c);

extern void F0e7bb6a8_FUN_00283788(char *a, char *b, char *c);

extern void F0e7bb6a8_FUN_002AB6D8(char *a, char *b);

extern float Fb5729173_FUN_00282E48(char *a, char *b);

extern float Fb5729173_FUN_00283248(float x, float y);

extern float Fb5729173_FUN_00283C80(float x, float y);

extern float Fb5729173_FUN_00282E80(char *a, char *b);

extern int Fb5729173_FUN_002ABB78(char *a);

void func_002A7750(u8 *a0,u8 a1,s32 a2) {
 u8 old=a0[0x20];a0[0x20]=a1;a0[0x94]=old;*(short *)(a0+0x96)=0;
 a0[0xbe]&=~1;
 if(a2!=-1){a0[0x95]=(u8)a2;a0[0xbe]&=~2;}
}

/* Measured target: byte-identical across all 27 levels. */
f32 func_002A7790(f32 a0) { return a0 * a0; }

f32 func_002A7798(f32 a0) {
 return 1.0f-(1.0f-a0)*(1.0f-a0);
}

INCLUDE_ASM("asm/game", func_002A77C0);

s32 func_002A77E0(s32 a0) {
    return (func_001163B0() >> 16 & 0x7fff) % a0;
}

s32 func_002A7820(s32 a0, s32 a1) {
    return (func_001163B0() >> 16 & 0x7fff) % ((a1 - a0) + 1) + a0;
}

f32 func_002A7878(f32 a0, f32 a1) {
    s32 r = func_001163B0();
    return a0 + (f32)(r >> 16 & 0x7FFF) * (a1 - a0) * 3.0517578125e-05f;
}

f32 func_002A78D8(f32 a0, f32 a1) {
    s32 r = func_001163B0();
    f32 result = a0 + (f32)(r >> 16 & 0xFFF) * (a1 - a0) * 0.000244140625f;
    if ((r >> 16 & 1) != 0) result = -result;
    return result;
}

f32 func_002A7940(void) {
    return (f32)((func_001163B0() >> 16 & 0xfff) - 0x800) * 0.0015339808f;
}

INCLUDE_ASM("asm/game", func_002A7988);

INCLUDE_ASM("asm/game", func_002A7A00);

float func_002A7AA8(float a, float b, float c, float d, float t) {
    float p = (d - c) - (a - b);
    float q = (a - b) - p;
    float t2 = t * t;
    float t3 = t2 * t;
    return p * t3 + q * t2 + (c - a) * t + b;
}

INCLUDE_ASM("asm/game", func_002A7AE0);

INCLUDE_ASM("asm/game", func_002A7C00);

INCLUDE_ASM("asm/game", func_002A7C98);

float func_002A7CA0(struct family_27f9_object *a0,
                                         float *a1,
                                         float p1, float p2, float p3, float p4)
{
    float t;
    float v;
    float f3;
    float out;

    t = F27f9be8e_FUN_00283BE0(p1, a0->heading);
    v = t * 6.3661971092224121093750e+00f;
    if (v > 1.0f) {
        v = 1.0f;
    } else {
        if (v < -1.0f) {
            v = -1.0f;
        }
    }
    f3 = a1[0];
    a1[0] = f3 + (p2 * v - p3 * f3);
    if (p4 != 0.0f) {
        if (a1[0] > p4) {
            a1[0] = p4;
        } else {
            if (a1[0] < -p4) {
                a1[0] = -p4;
            }
        }
    }
    if (F27f9be8e_FUN_00282C48(t) < a1[0]) {
        a1[0] = F27f9be8e_FUN_00282C48(t);
    } else {
        if (a1[0] < -F27f9be8e_FUN_00282C48(t)) {
            a1[0] = -F27f9be8e_FUN_00282C48(t);
        }
    }
    out = F27f9be8e_FUN_00283B98(a0->heading, a1[0]);
    a0->heading = out;
    return out;
}

INCLUDE_ASM("asm/game", func_002A7E08);

INCLUDE_ASM("asm/game", func_002A7E90);

INCLUDE_ASM("asm/game", func_002A7EA0);

INCLUDE_ASM("asm/game", func_002A8238);

INCLUDE_ASM("asm/game", func_002A8240);

INCLUDE_ASM("asm/game", func_002A84E0);

INCLUDE_ASM("asm/game", func_002A8508);

INCLUDE_ASM("asm/game", func_002A8598);

INCLUDE_ASM("asm/game", func_002A85F0);

INCLUDE_ASM("asm/game", func_002A8600);

INCLUDE_ASM("asm/game", func_002A86E8);

INCLUDE_ASM("asm/game", func_002A8850);

int func_002A8860(int *p, int b) {
    int w = *p;
    int v = (w >> 24) - b;
    if (v < 0) v = 0;
    *p = (w & 0xFFFFFF) | (v << 24);
    return v == 0;
}

INCLUDE_ASM("asm/game", func_002A8898);

INCLUDE_ASM("asm/game", func_002A88A0);

INCLUDE_ASM("asm/game", func_002A89A8);

INCLUDE_ASM("asm/game", func_002A8A20);

INCLUDE_ASM("asm/game", func_002A8A48);

s32 func_002A8A50(const f32 *a0,const MmiPoint *a1,s32 a2) {
    s32 i;
    for(i=0;i<a2;i++) {
        f32 x=a1[i].x,y=a1[i].y;
        if((a1[(i+1)%a2].x-x)*(a0[1]-y)-(a1[(i+1)%a2].y-y)*(a0[0]-x)>0.0f) return i+1;
    }
    return 0;
}

int func_002A8AF0(float *p, float *v, int n) {
    int r = 0;
    int i = 0;
    int k;
    for (k = 0; k < n; k++) {
        float y1 = v[k * 4 + 1];
        i++;
        if (i == n) i = 0;
        if ((y1 < p[1] && p[1] <= v[i * 4 + 1]) || (v[i * 4 + 1] < p[1] && p[1] <= y1)) {
            if (v[k * 4] + (p[1] - v[k * 4 + 1]) / (v[i * 4 + 1] - v[k * 4 + 1]) * (v[i * 4] - v[k * 4]) < p[0]) {
                r = !r;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/game", func_002A8BC0);

INCLUDE_ASM("asm/game", func_002A8BD0);

void func_002A8C00(char *a, int b, int c, float d, Quad16 *q) {
    *(int *)(a + 0x10) = b;
    *(int *)(a + 0x14) = c;
    *(float *)(a + 0x1C) = d;
    *(int *)(a + 0x20) = 1;
    *(volatile TI128 *)a = *(TI128 *)q;
}

INCLUDE_ASM("asm/game", func_002A8C28);

INCLUDE_ASM("asm/game", func_002A8D70);

INCLUDE_ASM("asm/game", func_002A8E18);

INCLUDE_ASM("asm/game", func_002A8E20);

INCLUDE_ASM("asm/game", func_002A8F70);

INCLUDE_ASM("asm/game", func_002A90C8);

INCLUDE_ASM("asm/game", func_002A90F0);

INCLUDE_ASM("asm/game", func_002A90F8);

INCLUDE_ASM("asm/game", func_002A91F0);

INCLUDE_ASM("asm/game", func_002A9288);

INCLUDE_ASM("asm/game", func_002A93B0);

INCLUDE_ASM("asm/game", func_002A9548);

INCLUDE_ASM("asm/game", func_002A9568);

INCLUDE_ASM("asm/game", func_002A9588);

INCLUDE_ASM("asm/game", func_002A9640);

INCLUDE_ASM("asm/game", func_002A9698);

INCLUDE_ASM("asm/game", func_002A96A0);

void func_002A9850(void *a0, Vec16_F5621621c *src, int *p, int n,
                                        int t0, int t1, int t2, int t3,
                                        float f1, float f2, float f3)
{
    Vec16_F5621621c vec;
    Vec16_F5621621c *vp = &vec;
    Rec_F5621621c rec;
    int i;
    int *q;

    *(V4_F5621621c *)&vec = *(V4_F5621621c *)src;
    if (n <= 0) return;
    for (q = p, i = n; i != 0; i--, q++) {
        Node_F5621621c *v = (Node_F5621621c *)*q;
        float t;
        if ((int)*q == t0) continue;
        rec.i16 = (int)a0;
        rec.h26 = *(unsigned short *)((char *)a0 + 170);
        rec.i20 = t1;
        rec.f28 = f1;
        rec.i32 = t1;
        rec.b24 = t2;
        rec.b25 = t3;
        t = F5621621c_FUN_00283248(v->f16 - vp->x, v->f20 - vp->y);
        rec.f0 = F5621621c_FUN_00283180(t) * f2;
        rec.f4 = F5621621c_FUN_00283198(t) * f2;
        rec.f8 = f3;
        rec.f12 = 5.6279248046875000000000e3f;
        F5621621c_FUN_002A8E20(*q, &rec);
    }
}

INCLUDE_ASM("asm/game", func_002A99A0);

INCLUDE_ASM("asm/game", func_002AA130);

f32 func_002AA140(f32 a, f32 b, f32 t) { return a + (b - a) * t; }

INCLUDE_ASM("asm/game", func_002AA150);

void func_002AA198(Obj_Ff454dd77 *o, float a, float b, float c, float d)
{
    if (Ff454dd77_FUN_00282C48(a) < o->f0)
        o->f0 = Ff454dd77_FUN_00282C48(a);
    else if (o->f0 < -Ff454dd77_FUN_00282C48(a))
        o->f0 = -Ff454dd77_FUN_00282C48(a);

    o->f0 = o->f0 + (b * a - c * o->f0);
    if (0.0f < d) {
        if (d < o->f0)
            o->f0 = d;
        else if (o->f0 < -d)
            o->f0 = -d;
    }

    if (Ff454dd77_FUN_00282C48(a) < o->f0)
        o->f0 = Ff454dd77_FUN_00282C48(a);
    else if (o->f0 < -Ff454dd77_FUN_00282C48(a))
        o->f0 = -Ff454dd77_FUN_00282C48(a);
}

INCLUDE_ASM("asm/game", func_002AA2E8);

INCLUDE_ASM("asm/game", func_002AA340);

INCLUDE_ASM("asm/game", func_002AA3A0);

INCLUDE_ASM("asm/game", func_002AA3A8);

INCLUDE_ASM("asm/game", func_002AA458);

INCLUDE_ASM("asm/game", func_002AA548);

INCLUDE_ASM("asm/game", func_002AA738);

INCLUDE_ASM("asm/game", func_002AA800);

INCLUDE_ASM("asm/game", func_002AA898);

INCLUDE_ASM("asm/game", func_002AAA00);

INCLUDE_ASM("asm/game", func_002AAC80);

INCLUDE_ASM("asm/game", func_002AAE98);

void func_002AAF40(int *a, int *b, int *c, int mask) {
    int x, y;
    if (mask & 1) { x = *b; y = *a; *a = x; *b = y; }
    if (mask & 2) { x = *c; y = *b; *b = x; *c = y; }
    if (mask & 4) { x = *a; y = *c; *c = x; *a = y; }
}

INCLUDE_ASM("asm/game", func_002AAFA0);

void func_002AB028(float (*m)[4])
{
    int k;
    int i;
    float v[4];

    for (k = 0; k < 3; k++) {
        v[3] = 0.0f;
        for (i = 0; i < 3; i++)
            v[i] = m[i][k];
        Fa5914967_FUN_00282F20(v, v, 1.0f);
        for (i = 0; i < 3; i++)
            m[i][k] = v[i];
    }
}

INCLUDE_ASM("asm/game", func_002AB0E8);

INCLUDE_ASM("asm/game", func_002AB168);

s32 func_002AB1F0(u8 *a0) {
 if(a0==0) return 0;
 if((*(unsigned short *)(a0+0x34)&0x20)!=0) return (*(s32 **)(a0+0x68))[0];
 return 0;
}

s32 func_002AB220(u8 *a0) {
 if(a0==0) return 0;
 if((*(unsigned short *)(a0+0x34)&0x20)!=0) return (*(s32 **)(a0+0x68))[4];
 return 0;
}

INCLUDE_ASM("asm/game", func_002AB250);

INCLUDE_ASM("asm/game", func_002AB378);

INCLUDE_ASM("asm/game", func_002AB600);

void func_002AB650(u8 *a0) {
    u8 *p = *(u8 **)D_0018C0B0;
    *(long *)(a0 + 0x38) = *(long *)(p + 0x38);
}

INCLUDE_ASM("asm/game", func_002AB668);

INCLUDE_ASM("asm/game", func_002AB6D0);

INCLUDE_ASM("asm/game", func_002AB6D8);

void func_002AB800(int first, char *object)
{
    char *s0 = object;
    short s1 = *(short *)(s0 + 0);
    unsigned short total;
    float limit;
    int result;

    if (s1 != 0 && *(short *)(s0 + 2) == 0)
        return;
    total = *(unsigned short *)(s0 + 12);
    *(short *)(s0 + 2) = 0;
    *(short *)(s0 + 0) = total;
    if (s1 != 0) {
        limit = F500f9762_FUN_00283CE0(*(short *)(s0 + 14));
        result = F500f9762_FUN_00283CF0((float)*(short *)(s0 + 12) * ((float)s1 / limit));
        *(short *)(s0 + 0) = (short)result;
        if ((short)result <= 0)
            *(short *)(s0 + 0) = 1;
    } else {
        int a, b, c;
        F500f9762_FUN_002A04B8(first, (char *)&a, (char *)&b, (char *)&c);
        *(char *)(s0 + 4) = (unsigned char)a;
        *(char *)(s0 + 5) = (unsigned char)b;
        *(char *)(s0 + 6) = (unsigned char)c;
    }
}

INCLUDE_ASM("asm/game", func_002AB8C0);

INCLUDE_ASM("asm/game", func_002ABB10);

INCLUDE_ASM("asm/game", func_002ABB18);

INCLUDE_ASM("asm/game", func_002ABB70);

INCLUDE_ASM("asm/game", func_002ABB78);

INCLUDE_ASM("asm/game", func_002ABBB8);

INCLUDE_ASM("asm/game", func_002AC728);

INCLUDE_ASM("asm/game", func_002AC9F0);

INCLUDE_ASM("asm/game", func_002AC9F8);

INCLUDE_ASM("asm/game", func_002ACA48);

/* shared native body of family 354e785cbdee35b5 */
void func_002ACA50(int param_1, short *param_2, short param_3)
{
    int i;

    param_1 = (param_1 - *(int *)0x001B359C) << 8 >> 16;
    for (i = 1; i <= param_2[0]; i++) {
        if (param_2[i] == param_1) return;
    }
    if (param_2[0] < param_3) {
        param_2[0] = param_2[0] + 1;
        param_2[param_2[0]] = param_1;
    }
}

/* shared native body of family bef45185f2ede0ad */
void func_002ACAD0(int param_1, unsigned short *param_2)
{
    int i;

    for (i = 1; i <= (short)param_2[0]; i++) {
        if (D_L02_001B359C + ((short)param_2[i] << 8) == param_1) {
            param_2[i] = param_2[(short)param_2[0]];
            param_2[0] = param_2[0] - 1;
            return;
        }
    }
}

INCLUDE_ASM("asm/game", func_002ACB48);

INCLUDE_ASM("asm/game", func_002ACBC8);

INCLUDE_ASM("asm/game", func_002ACCA0);

INCLUDE_ASM("asm/game", func_002ACCA8);

INCLUDE_ASM("asm/game", func_002ACD30);

INCLUDE_ASM("asm/game", func_002ACD38);

INCLUDE_ASM("asm/game", func_002ACDC8);

INCLUDE_ASM("asm/game", func_002ACDE8);

INCLUDE_ASM("asm/game", func_002ACE78);

INCLUDE_ASM("asm/game", func_002ACEC0);

INCLUDE_ASM("asm/game", func_002ACF68);

INCLUDE_ASM("asm/game", func_002AD0A8);

s32 func_002AD0B0(u8 *a0) {
 if(a0==0) return 0;
 if((*(unsigned short *)(a0+0x34)&0x20)==0) return 0;
 return (*(s32 **)(a0+0x68))[2];
}

INCLUDE_ASM("asm/game", func_002AD0E0);

INCLUDE_ASM("asm/game", func_002AD250);

int func_002AD330(char *a0, char *a1, char *a2, char *a3)
{
    V4_F904cc63b b0[4];
    V4_F904cc63b b1[1];
    V4_F904cc63b b2[4];
    V4_F904cc63b b3[4];
    char *p;

    p = F904cc63b_FUN_002AD0B0(a1);
    if (p == 0)
    {
        *(V4_F904cc63b *)a3 = 0;
        return 0;
    }
    F904cc63b_FUN_00283410(b0, p);
    F904cc63b_FUN_00282CC0(b1, (V4_F904cc63b *)a2, p + 16);
    F904cc63b_FUN_00282CF0(b1, b1, a1 + 16);
    if (*(int *)(p + 60) & 2)
    {
        F904cc63b_FUN_00283410(b3, p + 32);
        F904cc63b_FUN_00283698(b2, b3);
        F904cc63b_FUN_00283098(b1, b1, b2);
        F904cc63b_FUN_00283098(b1, b1, (V4_F904cc63b *)(a1 + 192));
    }
    else
    {
        F904cc63b_FUN_00283098(b1, b1, b0);
    }
    F904cc63b_FUN_00282CC0(b1, b1, a1 + 16);
    F904cc63b_FUN_00282CF0((V4_F904cc63b *)a3, b1, a2);
    return 1;
}

INCLUDE_ASM("asm/game", func_002AD470);

int func_002AD5F8(char *unused, char *obj, char *arg2, char *arg3, char *arg4, char *arg5)
{
    char buf0[64];
    char buf1[16];
    char buf2[64];
    char *p;

    p = F0e7bb6a8_FUN_002AD0B0(obj);
    if (p == 0)
        return 0;
    if (*(int *)(p + 60) & 0x40) {
        F0e7bb6a8_FUN_00283410(buf0, obj + 240);
        F0e7bb6a8_FUN_00283698(buf0, buf0);
    } else {
        F0e7bb6a8_FUN_00283698(buf0, obj + 192);
    }
    F0e7bb6a8_FUN_00282CF0(buf1, arg2, obj + 16);
    F0e7bb6a8_FUN_002830C0(arg4, buf1, buf0);
    F0e7bb6a8_FUN_00283410(buf2, arg3);
    F0e7bb6a8_FUN_00283788(buf2, buf0, buf2);
    F0e7bb6a8_FUN_002AB6D8(buf2, arg5);
    return 1;
}

INCLUDE_ASM("asm/game", func_002AD6F0);

INCLUDE_ASM("asm/game", func_002AD7B8);

INCLUDE_ASM("asm/game", func_002AD860);

INCLUDE_ASM("asm/game", func_002AD980);

INCLUDE_ASM("asm/game", func_002ADB78);

INCLUDE_ASM("asm/game", func_002AE728);

INCLUDE_ASM("asm/game", func_002AE730);

INCLUDE_ASM("asm/game", func_002AE838);

INCLUDE_ASM("asm/game", func_002AE8C0);

INCLUDE_ASM("asm/game", func_002AEAE0);

INCLUDE_ASM("asm/game", func_002AEB60);

INCLUDE_ASM("asm/game", func_002AEBF0);

INCLUDE_ASM("asm/game", func_002AEC18);

INCLUDE_ASM("asm/game", func_002AEC48);

INCLUDE_ASM("asm/game", func_002AEE70);

INCLUDE_ASM("asm/game", func_002AEF28);

INCLUDE_ASM("asm/game", func_002AEFF0);

INCLUDE_ASM("asm/game", func_002AF000);

INCLUDE_ASM("asm/game", func_002AF0A0);

INCLUDE_ASM("asm/game", func_002AF0A8);

INCLUDE_ASM("asm/game", func_002AF1D0);

float func_002AF2E8(char *a0, char *a1, int *a2,
                                       float p1, float p2, float p3, float p4)
{
    float best = p4;
    float hi = p3;
    float radius;
    float reach = p2;
    float far;
    float near;
    float tmp;

    *a2 = 0;
    far = Fb5729173_FUN_00282E48(a0, a1 + 16);
    if (reach < far) {
        *a2 = 1;
    }

    reach = 0.0f;
    radius = Fb5729173_FUN_00283C80(Fb5729173_FUN_00283248(((float *)(a1 + 16))[0] - ((float *)a0)[0],
                             ((float *)(a1 + 16))[1] - ((float *)a0)[1]), p1);
    near = Fb5729173_FUN_00282E80(a0, a1 + 16);
    tmp = Fb5729173_FUN_00283C80(Fb5729173_FUN_00283248(near, ((float *)(a1 + 16))[2] - ((float *)a0)[2]), 0.0f);

    if (reach < hi) {
        if (hi < radius) {
            *a2 = 1;
        }
    }
    if (0.0f < best) {
        if (best < tmp) {
            *a2 = 1;
        }
    }

    reach = far + radius * far;
    if (Fb5729173_FUN_002ABB78(a1) != 0) {
        reach = reach + 8.0f;
    }
    return reach;
}

INCLUDE_ASM("asm/game", func_002AF460);
