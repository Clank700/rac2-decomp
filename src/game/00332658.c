#include "include_asm.h"

extern void F7242f0a4_FUN_00282D30(char *out, void *source, float value);

extern void F7242f0a4_FUN_00334730(char *buffer, int mode);

extern void F7242f0a4_FUN_00334710(int value, char *buffer);

extern void F7242f0a4_FUN_00282CC0(char *first, char *second, char *third);

extern float F7242f0a4_FUN_00282DB0(void *owner, char *buffer);

extern int F7242f0a4_D_001B53A0[];

/* Measured partial layouts; original type and game roles are unknown. */
typedef struct Rac2Native_81be3b52930eb806_FallbackInterleavedFloat4Layout {
    unsigned char unknown_00[8];
    float first_0;
    float second_0;
    float first_1;
    float second_1;
    float first_2;
    float second_2;
    float first_3;
    float second_3;
} Rac2Native_81be3b52930eb806_FallbackInterleavedFloat4Layout;

typedef int s32;

typedef unsigned char u8;

/* func_0034CA68: owner ABI/declaration review retained. */
extern int func_00335E20(unsigned char *field);

typedef float f32;

#ifndef RAC2_T_OBJ_F7B2F1854
#define RAC2_T_OBJ_F7B2F1854
typedef struct Obj_F7b2f1854 {
    int *f0;
    int *f4;
    int *f8;
    int *f12;
    int *f16;
    int f20;
    int f24;
    int f28;
    int f32;
    int f36;
    int f40;
    int f44;
} Obj_F7b2f1854;
#endif

extern int *F7b2f1854_FUN_00336E40(int n);

extern int *F7b2f1854_FUN_00336DA8(int size, int *p);

extern void F7b2f1854_FUN_00335E68(Obj_F7b2f1854 *o, int v);

extern void F36efd143_FUN_00335FC8(char *a);

extern void *F36efd143_FUN_00336E40(char *a);

extern void *F36efd143_FUN_00336DA8(int size, void *b);

typedef unsigned int u32;

extern void F081de6c9_FUN_00335FC8(char *s, int a1, char *a2);

extern int F081de6c9_FUN_00336E40(int x);

extern int *F081de6c9_FUN_00336DA8(int n, int x);

extern void D_00115E38(char *assertion, int line, char *file);

extern char D_L00_001ADDD8[];

extern char D_L00_001ADDF8[];

typedef struct { unsigned int f0, f4, f8, f12, f16, f20; } T;

extern char D_L00_001ADDD8_1[];

extern char D_L00_001ADE20[];

extern void D_00115E38_1(char *a0, int a1, char *a2);

extern void func_0033AE18(unsigned char *owner, int value);

extern void F8ad956d6_FUN_00336320(char *target);

extern void F8ad956d6_FUN_002FC560(int marker, int code);

extern void F8ad956d6_FUN_00295F60(int first, int second);

extern void F8ad956d6_FUN_002DAF68(char *target);

extern void F8ad956d6_FUN_00336A78(char *target);

INCLUDE_ASM("asm/game", func_00332658);

INCLUDE_ASM("asm/game", func_00333048);

INCLUDE_ASM("asm/game", func_003334B0);

INCLUDE_ASM("asm/game", func_00333AF8);

INCLUDE_ASM("asm/game", func_00334050);

INCLUDE_ASM("asm/game", func_003340A8);

INCLUDE_ASM("asm/game", func_003340F0);

INCLUDE_ASM("asm/game", func_00334100);

INCLUDE_ASM("asm/game", func_00334160);

INCLUDE_ASM("asm/game", func_00334550);

INCLUDE_ASM("asm/game", func_00334710);

INCLUDE_ASM("asm/game", func_00334728);

INCLUDE_ASM("asm/game", func_00334730);

INCLUDE_ASM("asm/game", func_00334898);

INCLUDE_ASM("asm/game", func_003348A8);

void func_003349E8(void *owner, int flag, float value)
{
    char buffer[32];
    int *root = F7242f0a4_D_001B53A0;

    F7242f0a4_FUN_00282D30(buffer, root + 8, value);
    if (flag)
        F7242f0a4_FUN_00334730(buffer + 16, 1);
    else
        F7242f0a4_FUN_00334710(root[-4], buffer + 16);
    F7242f0a4_FUN_00282CC0(buffer, buffer, buffer + 16);
    F7242f0a4_FUN_00282D30(owner, root + 12, F7242f0a4_FUN_00282DB0(root + 12, buffer));
}

INCLUDE_ASM("asm/game", func_00334A88);

INCLUDE_ASM("asm/game", func_003351B0);

INCLUDE_ASM("asm/game", func_00335270);

INCLUDE_ASM("asm/game", func_00335370);

INCLUDE_ASM("asm/game", func_003353C8);

INCLUDE_ASM("asm/game", func_00335420);

INCLUDE_ASM("asm/game", func_00335438);

INCLUDE_ASM("asm/game", func_003355A8);

INCLUDE_ASM("asm/game", func_003356E8);

INCLUDE_ASM("asm/game", func_00335798);

INCLUDE_ASM("asm/game", func_00335840);

INCLUDE_ASM("asm/game", func_00335860);

INCLUDE_ASM("asm/game", func_00335870);

INCLUDE_ASM("asm/game", func_003358A0);

INCLUDE_ASM("asm/game", func_00335918);

INCLUDE_ASM("asm/game", func_00335960);

INCLUDE_ASM("asm/game", func_00335AC8);

INCLUDE_ASM("asm/game", func_00335AE0);

/* Interpolate four scalar float components from separate input arrays using (1.0f - factor) * first + factor * second, writing each component to the destination. */
void func_00335B10(float factor, void *context,
                                   float *destination,
                                   const float *first, const float *second)
{
    float complement = 1.0f - factor;
    destination[0] = complement * first[0] + factor * second[0];
    destination[1] = complement * first[1] + factor * second[1];
    destination[2] = complement * first[2] + factor * second[2];
    destination[3] = complement * first[3] + factor * second[3];
}

INCLUDE_ASM("asm/game", func_00335B80);

INCLUDE_ASM("asm/game", func_00335C10);

INCLUDE_ASM("asm/game", func_00335C60);

/* Interpolate four scalar float components from interleaved endpoint pairs at source offsets 0x08 through 0x24 using (1.0f - factor) * first + factor * second, writing each component to the destination. */
void func_00335CC0(float factor,
                                     const Rac2Native_81be3b52930eb806_FallbackInterleavedFloat4Layout *source,
                                     float *destination)
{
    float complement = 1.0f - factor;
    destination[0] = complement * source->first_0 + factor * source->second_0;
    destination[1] = complement * source->first_1 + factor * source->second_1;
    destination[2] = complement * source->first_2 + factor * source->second_2;
    destination[3] = complement * source->first_3 + factor * source->second_3;
}

INCLUDE_ASM("asm/game", func_00335D30);

INCLUDE_ASM("asm/game", func_00335D60);

INCLUDE_ASM("asm/game", func_00335D80);

INCLUDE_ASM("asm/game", func_00335DA0);

INCLUDE_ASM("asm/game", func_00335DC0);

INCLUDE_ASM("asm/game", func_00335E08);

/* Measured target: byte-identical across all 27 levels. */
s32 func_00335E10(u8 *a0) { return *(s32 *)(a0 + 0x0); }

/* Measured target: byte-identical across all 27 levels. */
s32 func_00335E18(u8 *a0) { return *(s32 *)(a0 + 0x4); }

/* Measured target: byte-identical across all 27 levels. */
s32 func_00335E20(u8 *a0) { return *(s32 *)(a0 + 0xc); }

INCLUDE_ASM("asm/game", func_00335E28);

void func_00335E38(u8 *a0,f32 f0,f32 f1,f32 f2,f32 f3) {
 (*(f32 **)a0)[0]=f0;(*(f32 **)a0)[1]=f1;
 (*(f32 **)a0)[2]=f2;(*(f32 **)a0)[3]=f3;
}

INCLUDE_ASM("asm/game", func_00335E60);

void func_00335E68(u8 *a0, s32 a1) {
 f32 *p=*(f32 **)(a0+0x10);
 *p=(a1!=0)?1.0f:0.0f;
}

s32 func_00335E88(u8 *a0) {
 return 0.0f<**(f32 **)(a0+0x10);
}

INCLUDE_ASM("asm/game", func_00335EB0);

INCLUDE_ASM("asm/game", func_00335F18);

INCLUDE_ASM("asm/game", func_00335F20);

void func_00335F88(u8 *a0,f32 f0,f32 f1,f32 f2,f32 f3) {
 (*(f32 **)(a0+4))[0]=f0;(*(f32 **)(a0+4))[1]=f1;
 (*(f32 **)(a0+4))[2]=f2;(*(f32 **)(a0+4))[3]=f3;
}

INCLUDE_ASM("asm/game", func_00335FB0);

void func_00335FC8(Obj_F7b2f1854 *o, int a1, int count)
{
    int *p;
    int n;

    o->f44 = count;
    if (count != 0) {
        p = F7b2f1854_FUN_00336DA8(16, F7b2f1854_FUN_00336E40(count));
        n = o->f44;
        o->f0 = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;

        p = F7b2f1854_FUN_00336DA8(16, F7b2f1854_FUN_00336E40(n));
        n = o->f44;
        o->f8 = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;

        p = F7b2f1854_FUN_00336DA8(16, F7b2f1854_FUN_00336E40(n));
        n = o->f44;
        o->f4 = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;

        p = F7b2f1854_FUN_00336DA8(16, F7b2f1854_FUN_00336E40(n));
        n = o->f44;
        o->f12 = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;

        p = F7b2f1854_FUN_00336DA8(16, F7b2f1854_FUN_00336E40(n));
        o->f16 = p;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
    }
    o->f40 = a1;
    o->f32 = 0;
    o->f20 = 0;
    o->f28 = 0;
    o->f24 = 0;
    o->f36 = 0;
    F7b2f1854_FUN_00335E68(o, 1);
}

INCLUDE_ASM("asm/game", func_003360F0);

INCLUDE_ASM("asm/game", func_003360F8);

INCLUDE_ASM("asm/game", func_003361A8);

void func_003361E0(char *obj)
{
    int *p;
    int x;
    F36efd143_FUN_00335FC8(obj);
    if (*(int *)(obj + 44) != 0) {
        p = (int *)F36efd143_FUN_00336DA8(16, F36efd143_FUN_00336E40(*(int *)(obj + 44)));
        *(int *)(obj + 52) = (int)p;
        x = *(int *)(obj + 44);
        p[1] = 0; p[2] = 0; p[3] = 0; p[0] = 0;
        p = (int *)F36efd143_FUN_00336DA8(16, F36efd143_FUN_00336E40(x));
        *(int *)(obj + 56) = (int)p;
        {
            float *f = (float *)*(int *)(obj + 4);
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
            p[0] = 0;
            f[0] = 1.0f;
            *(float *)(*(int *)(obj + 4) + 4) = 1.0f;
            *(float *)(*(int *)(obj + 4) + 8) = 1.0f;
        }
    }
    *(int *)(obj + 68) = 0;
    *(int *)(obj + 72) = 0;
}

INCLUDE_ASM("asm/game", func_00336288);

INCLUDE_ASM("asm/game", func_00336308);

/* Measured target: byte-identical across all 27 levels. */
s32 func_00336318(u8 *a0) { return *(s32 *)(a0 + 0x38); }

INCLUDE_ASM("asm/game", func_00336320);

INCLUDE_ASM("asm/game", func_00336390);

void func_003363C0(u8 *a0, f32 a1) { f32 *p = *(f32 **)(a0 + 0x38); *p = a1; }

INCLUDE_ASM("asm/game", func_003363D0);

INCLUDE_ASM("asm/game", func_00336408);

INCLUDE_ASM("asm/game", func_00336468);

/* lot12 -- measured bodies with sizes recorded in the catalogue. */
void func_00336498(u8 *a0, s32 a1, s32 a2) {
    *(s32 *)*(u8 **)(a0 + 0xc) = a1;
    *(s32 *)(*(u8 **)(a0 + 0xc) + 0x4) = a2;
}

void func_003364B0(u8 *a0, s32 a1, s32 a2) {
    *(s32 *)(*(u8 **)(a0 + 0xc) + 0x8) = a1;
    *(s32 *)(*(u8 **)(a0 + 0xc) + 0xc) = a2;
}

void func_003364C8(u8 *a0, s32 a1, s32 a2) {
    u8 *o = a0;
    *(u32 *)*(u8 **)(o + 0xC) = (*(u32 *)*(u8 **)(o + 0xC) & 0x00FFFFFF) | (u32)(a1 << 24);
    *((u32 *)*(u8 **)(o + 0xC) + 1) = (*((u32 *)*(u8 **)(o + 0xC) + 1) & 0x00FFFFFF) | (u32)(a2 << 24);
}

void func_00336508(u8 *a0, s32 a1, s32 a2) {
    u8 *o = a0;
    *((u32 *)*(u8 **)(o + 0xC) + 2) = (*((u32 *)*(u8 **)(o + 0xC) + 2) & 0x00FFFFFF) | (u32)(a1 << 24);
    *((u32 *)*(u8 **)(o + 0xC) + 3) = (*((u32 *)*(u8 **)(o + 0xC) + 3) & 0x00FFFFFF) | (u32)(a2 << 24);
}

INCLUDE_ASM("asm/game", func_00336548);

INCLUDE_ASM("asm/game", func_003366D0);

INCLUDE_ASM("asm/game", func_00336708);

void func_00336710(char *s1, int a1, char *a2)
{
    F081de6c9_FUN_00335FC8(s1, a1, a2);
    if (a2 != 0) {
        int *v = F081de6c9_FUN_00336DA8(16, F081de6c9_FUN_00336E40(*(int *)(s1 + 44)));

        *(int **)(s1 + 52) = v;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
        v[0] = 0;
    }
    ((int *)*(int **)(s1 + 52))[0] = 0;
    ((int *)*(int **)(s1 + 52))[1] = 0;
    *(float *)(*(char **)s1 + 0) = 100.0f;
    *(float *)(*(char **)s1 + 4) = 100.0f;
    *(float *)(*((char **)s1 + 1) + 0) = 64.0f;
    *(float *)(*((char **)s1 + 1) + 4) = 64.0f;
    *(int *)(s1 + 56) = 0;
}

/* Measured target: byte-identical across all 27 levels. */
s32 func_003367B8(u8 *a0) { return *(s32 *)(a0 + 0x34); }

INCLUDE_ASM("asm/game", func_003367C0);

INCLUDE_ASM("asm/game", func_00336828);

void func_00336920(u8 *a0,s32 a1,s32 a2) {
 **(f32 **)(a0+0x34)=(f32)a1;
 (*(f32 **)(a0+0x34))[1]=(f32)a2;
}

/* reads a float through double indirection and returns its integer value; byte-identical across all 27 levels. */
s32 func_00336950(u8 *a0) { return (s32)*(f32 *)(*(u8 **)(a0 + 0x34)); }

INCLUDE_ASM("asm/game", func_00336968);

INCLUDE_ASM("asm/game", func_003369A0);

INCLUDE_ASM("asm/game", func_003369A8);

INCLUDE_ASM("asm/game", func_00336A08);

void func_00336A30(int param_1, unsigned int param_2)
{
  *(unsigned int*)(param_1 + 0x44) = param_2;
  return;
}

void func_00336A38(int param_1, unsigned int param_2)
{
  *(unsigned int *)(param_1 + 0x40) = param_2;
  return;
}

INCLUDE_ASM("asm/game", func_00336A40);

INCLUDE_ASM("asm/game", func_00336A70);

INCLUDE_ASM("asm/game", func_00336A78);

/* Complete boot bodies from liolu PRs #72 and #75; refreshed in one combined batch. */
void func_00336B90(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x40) = a1; }

INCLUDE_ASM("asm/game", func_00336B98);

/* Measured target: byte-identical across all 27 levels. */
void func_00336CC0(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x38) = a1; }

void func_00336CC8(u8 *a0,s32 a1) {
 (*(f32 **)(a0+4))[1]=(f32)a1;
}

INCLUDE_ASM("asm/game", func_00336CE0);

INCLUDE_ASM("asm/game", func_00336CE8);

s32 func_00336D50(u8 *a0,s32 a1) {
 s32 count=*(s32 *)(a0+0x18); s32 i,out=0;u8 *base=a0+0x1c;
 for(i=0;i<count;i++) {
  s32 *p=(s32 *)((i<<3)+(u32)base);
  if(p[0]==a1) {out=p[1];break;}
 }
 return out;
}

void func_00336DA0(void)
{
}

void *func_00336DA8(void *first, void *second) { (void) first; return second; }

INCLUDE_ASM("asm/game", func_00336DB0);

/* shared native body of family 5b6bba31 */
void func_00336DB8(int *p, unsigned int a1, int a2, int a3)
{
    if (a1 < 4)
        D_00115E38(D_L00_001ADDD8, 37, D_L00_001ADDF8);
    p[1] = a3;
    p[2] = a1;
    p[4] = 0;
    p[5] = 0;
    p[3] = 0;
    p[0] = a2;
}

INCLUDE_ASM("asm/game", func_00336E38);

/* a bump/free-list allocator. `p` (the parameter, moved to `$a1`) is a six-word */
void *func_00336E40(T *p)
{
    unsigned int off, size;
    void *r;

    if (p->f20 != 0)
    {
        unsigned int *x = (unsigned int *)p->f20;

        p->f20 = x[0];
        p->f16 = p->f16 + 1;
        return x;
    }
    off = p->f12;
    size = p->f8;
    if (p->f4 < off + size)
    {
        D_00115E38_1(D_L00_001ADDD8_1, 83, D_L00_001ADE20);
        return 0;
    }
    r = (void *)(p->f0 + off);
    p->f12 = off + size;
    p->f16 = p->f16 + 1;
    return r;
}

void func_00336ED0(u8 *a0, u8 *a1) {
    *(u8 **)(a1 + 0) = *(u8 **)(a0 + 0x14);
    *(u8 **)(a0 + 0x14) = a1;
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) - 1;
}

INCLUDE_ASM("asm/game", func_00336EF0);

INCLUDE_ASM("asm/game", func_00336EF8);

INCLUDE_ASM("asm/game", func_00336F20);

INCLUDE_ASM("asm/game", func_00337210);

INCLUDE_ASM("asm/game", func_00337BD8);

INCLUDE_ASM("asm/game", func_00337C10);

INCLUDE_ASM("asm/game", func_00337E28);

INCLUDE_ASM("asm/game", func_00337E30);

INCLUDE_ASM("asm/game", func_00337E98);

INCLUDE_ASM("asm/game", func_00338040);

INCLUDE_ASM("asm/game", func_003380A8);

INCLUDE_ASM("asm/game", func_003380B0);

INCLUDE_ASM("asm/game", func_003384C0);

INCLUDE_ASM("asm/game", func_00338718);

INCLUDE_ASM("asm/game", func_003387A0);

void func_00338808(void)
{
}

INCLUDE_ASM("asm/game", func_00338810);

void func_00338A58(void)
{
}

INCLUDE_ASM("asm/game", func_00338A60);

INCLUDE_ASM("asm/game", func_00338AD8);

void func_00338F50(void)
{
}

INCLUDE_ASM("asm/game", func_00338F58);

INCLUDE_ASM("asm/game", func_00339008);

INCLUDE_ASM("asm/game", func_00339070);

INCLUDE_ASM("asm/game", func_00339078);

INCLUDE_ASM("asm/game", func_00339320);

INCLUDE_ASM("asm/game", func_00339590);

INCLUDE_ASM("asm/game", func_003395F8);

INCLUDE_ASM("asm/game", func_00339630);

void func_00339760(u8 *a0) {s32 v=1;*(s32 *)(a0+0x300)=v;}

void func_00339770(unsigned char *owner, int value)
{
    func_0033AE18(owner + 8, value);
}

/* Measured target: byte-identical across all 27 levels. */
void func_00339790(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x2f8) = a1; }

INCLUDE_ASM("asm/game", func_00339798);

INCLUDE_ASM("asm/game", func_00339818);

INCLUDE_ASM("asm/game", func_003398A0);

INCLUDE_ASM("asm/game", func_003398A8);

INCLUDE_ASM("asm/game", func_003399B0);

INCLUDE_ASM("asm/game", func_00339A38);

INCLUDE_ASM("asm/game", func_00339AC8);

INCLUDE_ASM("asm/game", func_00339AD0);

INCLUDE_ASM("asm/game", func_00339F20);

INCLUDE_ASM("asm/game", func_00339F28);

void func_0033A3E0(char *object)
{
    char *s0 = object;

    if (*(int *)(s0 + 1024) == 0)
        return;
    F8ad956d6_FUN_00336320(s0 + 8);
    F8ad956d6_FUN_00336320(s0 + 84);
    F8ad956d6_FUN_002FC560(66, 68);
    F8ad956d6_FUN_002FC560(71, 11);
    F8ad956d6_FUN_00295F60(0, 1);
    F8ad956d6_FUN_002DAF68(0);
    F8ad956d6_FUN_00336320(s0 + 160);
    F8ad956d6_FUN_00336320(s0 + 236);
    F8ad956d6_FUN_00336A78(s0 + 312);
    F8ad956d6_FUN_00336A78(s0 + 384);
    F8ad956d6_FUN_00336A78(s0 + 456);
    F8ad956d6_FUN_00336A78(s0 + 528);
    F8ad956d6_FUN_00336A78(s0 + 600);
    F8ad956d6_FUN_00336A78(s0 + 672);
    F8ad956d6_FUN_00336A78(s0 + 744);
    F8ad956d6_FUN_00336A78(s0 + 816);
    F8ad956d6_FUN_00336A78(s0 + 888);
}

INCLUDE_ASM("asm/game", func_0033A4A0);

INCLUDE_ASM("asm/game", func_0033A518);

INCLUDE_ASM("asm/game", func_0033A520);

INCLUDE_ASM("asm/game", func_0033A688);
