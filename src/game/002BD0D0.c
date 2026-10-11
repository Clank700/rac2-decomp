#include "include_asm.h"

extern int F3c007b59_FUN_00282978(void *p);

extern void F3c007b59_FUN_002B9180(void *p);

extern unsigned int F3c007b59_FUN_00283CF0(float x);

#ifndef RAC2_T_OBJ_F3C007B59
#define RAC2_T_OBJ_F3C007B59
typedef struct {
    unsigned char pad0[4];
    unsigned int w04;
    unsigned char c08;
    unsigned char c09;
    unsigned char c10;
    unsigned char c11;
    float f12;
    unsigned char pad16[8];
    float f24;
    unsigned char pad28[4];
    float f36;
    float f40;
    float f44;
} OBJ_F3c007b59;
#endif

extern int Fc10c1216_FUN_00282978(char *);

extern void Fc10c1216_FUN_002B9180(char *);

extern int Fc10c1216_FUN_00283CF0(float);

extern void Fc10c1216_FUN_00282CC0(char *, char *, char *);

extern int func_00282978_9(char *p);

extern void func_002B9180_13(char *self);

extern float func_00283CE0_2(int v);

extern int func_00283CF0_6(float f);

extern void func_00282CC0_17(char *dst, char *src, char *vec);

extern void func_00300190_4(char *dst, char *src);

extern void func_00282D30_12(char *dst, char *table, float scale);

extern char D_0018A0E0_1[];

extern void Fa2a84657_FUN_00282D48(float *tmp, char *v, float k);

extern void Fa2a84657_FUN_00282CD8(float *tmp, char *a, char *v);

extern int Fa2a84657_FUN_00282978(char *field);

extern void Fa2a84657_FUN_002B9180(unsigned char *p);

extern void F15a8b7f0_FUN_00282D30(char *first, char *second, float blend);

extern void F15a8b7f0_FUN_00282CC0(char *first, char *second, char *third);

extern void F15a8b7f0_FUN_002B9180(char *object);

typedef unsigned char u8;

extern void func_00282CC0_19(void *out, void *in, void *src);

extern int func_00282978_11(void *p);

extern void func_002B9180_15(void *self);

extern float func_00283CE0_4(int n);

extern int func_00283D38_3(int handle, int previous, float ratio);

extern char D_00189E20_18[];

extern void Fccb147a4_FUN_002B9180(char *a, char *b);

extern void Fccb147a4_FUN_00300190(char *a, char *b);

extern void Fa03721e9_FUN_00282CC0(char *a, char *b, char *c);

extern void Fa03721e9_FUN_002B9180(char *p);

INCLUDE_ASM("asm/game", func_002BD0D0);

INCLUDE_ASM("asm/game", func_002BD390);

void func_002BD398(OBJ_F3c007b59 *o)
{
    float *p = (float *)((char *)o + 32);
    float f;
    float y;

    f = p[1] + p[3] * 1.3000000268220901489258e-02f;
    p[1] = f;
    if (f <= 0.0f || F3c007b59_FUN_00282978(&o->c10) != 0) {
        F3c007b59_FUN_002B9180(o);
    } else {
        f = p[1];
        if (2.1999999880790710449219e-01f <= f) {
            y = p[3];
            y = -y;
            p[3] = y;
            p[1] = f + y * 1.3000000268220901489258e-02f;
        }
        o->f12 = o->f12 + 8.1900000000000000000000e+03f;
        o->w04 = (o->w04 & 0xFFFFFFu) |
                 (F3c007b59_FUN_00283CF0(p[1] * 2.5500000000000000000000e+02f) << 24);
        p[2] = p[2] + 1.2000000104308128356934e-02f;
        if (p[2] > 1.0f)
            p[2] = p[2] - 1.0f;
        o->c08 = (unsigned char)(p[2] * 2.5500000000000000000000e+02f);
        o->f24 = o->f24 - 1.9999999552965164184570e-02f;
    }
}

INCLUDE_ASM("asm/game", func_002BD500);

INCLUDE_ASM("asm/game", func_002BD5B0);

INCLUDE_ASM("asm/game", func_002BD8B0);

INCLUDE_ASM("asm/game", func_002BD9B0);

INCLUDE_ASM("asm/game", func_002BDBC0);

INCLUDE_ASM("asm/game", func_002BDCE8);

INCLUDE_ASM("asm/game", func_002BDEB0);

INCLUDE_ASM("asm/game", func_002BE150);

INCLUDE_ASM("asm/game", func_002BE278);

INCLUDE_ASM("asm/game", func_002BE400);

INCLUDE_ASM("asm/game", func_002BE7E8);

INCLUDE_ASM("asm/game", func_002BE928);

void func_002BE9B8(char *p)
{
    float *q = (float *)(p + 32);

    if (0.0f < q[3])
        q[1] = q[1] + q[3] * 0.007f;
    else if (0.03f < q[1])
        q[1] = q[1] + q[3] * 0.007f;
    else {
        q[1] = q[1] + q[3] * 1.4000000664964318275452e-03f;
        *(float *)(p + 12) = *(float *)(p + 12) + 5460.0f;
    }

    if (q[1] <= 0.0244f || Fc10c1216_FUN_00282978(p + 10) != 0) {
        Fc10c1216_FUN_002B9180(p);
        return;
    }

    if (q[1] >= 0.12f) {
        q[3] = -q[3];
        q[1] = q[1] + q[3] * 0.007f;
    }
    *(float *)(p + 12) = *(float *)(p + 12) + 5460.0f;
    *(int *)(p + 4) = (*(int *)(p + 4) & 0xffffff) | (Fc10c1216_FUN_00283CF0(q[1] * 255.0f) << 24);
    q[2] = q[2] + 0.002f;
    if (q[2] > 1.0f)
        q[2] = q[2] - 1.0f;
    *(char *)(p + 8) = (char)(q[2] * 255.0f);
    Fc10c1216_FUN_00282CC0(p + 16, p + 16, (char *)(q + 4));
}

INCLUDE_ASM("asm/game", func_002BEBC0);

INCLUDE_ASM("asm/game", func_002BEE70);

INCLUDE_ASM("asm/game", func_002BF390);

INCLUDE_ASM("asm/game", func_002BF518);

INCLUDE_ASM("asm/game", func_002BF6F0);

INCLUDE_ASM("asm/game", func_002BF728);

INCLUDE_ASM("asm/game", func_002BF8F0);

INCLUDE_ASM("asm/game", func_002BFB38);

INCLUDE_ASM("asm/game", func_002BFC50);

INCLUDE_ASM("asm/game", func_002BFE80);

INCLUDE_ASM("asm/game", func_002BFFE8);

INCLUDE_ASM("asm/game", func_002C00F0);

INCLUDE_ASM("asm/game", func_002C01F8);

INCLUDE_ASM("asm/game", func_002C02F0);

INCLUDE_ASM("asm/game", func_002C04C0);

INCLUDE_ASM("asm/game", func_002C0C70);

INCLUDE_ASM("asm/game", func_002C0CC0);

INCLUDE_ASM("asm/game", func_002C0E50);

INCLUDE_ASM("asm/game", func_002C14D8);

INCLUDE_ASM("asm/game", func_002C16C0);

/* Updates one byte-addressed object by packing a converted short-ratio value with three bytes, applying the bound helper sequence to three stored floats, and accumulating one byte and one float. */
void func_002C1840(char *self)
{
    float vec[4];
    float tmp[4];
    char *s1;
    char *p;
    float f20;
    float t;
    unsigned int v;

    if (func_00282978_9(self + 10)) {
        func_002B9180_13(self);
        return;
    }
    s1 = self + 32;
    f20 = func_00283CE0_2(*(short *)(s1 + 30));
    t = func_00283CE0_2(*(short *)(s1 + 28));
    v = func_00283CF0_6(f20 * ((float)*(short *)(self + 10) / t));
    v = v << 24;
    v = v | (*(unsigned char *)(s1 + 19) << 16);
    v = v | (*(unsigned char *)(s1 + 18) << 8);
    v = v | *(unsigned char *)(s1 + 17);
    *(unsigned int *)(self + 4) = v;
    vec[3] = 0.0f;
    vec[0] = *(float *)(self + 32);
    vec[1] = *(float *)(s1 + 4);
    vec[2] = *(float *)(s1 + 8);
    func_00282CC0_17((char *)self + 16, (char *)self + 16, (char *)vec);
    if (*(float *)(self + 28) != 0.0f) {
        if (*(float *)(self + 28) == 2.0f)
            func_00300190_4((char *)self + 16, (char *)self + 16);
        *(float *)(self + 28) = 2.0f;
    }
    p = (char *)tmp;
    func_00282D30_12(p, D_0018A0E0_1, *(float *)(s1 + 12));
    func_00282CC0_17((char *)vec, (char *)vec, p);
    func_00282D30_12((char *)vec, (char *)vec, *(float *)(s1 + 24));
    *(float *)s1 = vec[0];
    *(float *)(s1 + 4) = vec[1];
    *(float *)(s1 + 8) = vec[2];
    *(unsigned char *)(self + 8) = *(unsigned char *)(self + 8) + *(unsigned char *)(s1 + 16);
    *(float *)(self + 12) = *(float *)(self + 12) + *(float *)(s1 + 20);
}

INCLUDE_ASM("asm/game", func_002C19D8);

INCLUDE_ASM("asm/game", func_002C1B38);

INCLUDE_ASM("asm/game", func_002C1C88);

INCLUDE_ASM("asm/game", func_002C1DB0);

INCLUDE_ASM("asm/game", func_002C1E50);

INCLUDE_ASM("asm/game", func_002C1EF0);

INCLUDE_ASM("asm/game", func_002C1FC0);

void func_002C2080(unsigned char *p)
{
    float tmp[4];
    char *v;
    int n;

    v = (char *)p + 32;
    Fa2a84657_FUN_00282D48(tmp, v, 9.4999998807907104492188e-01f);
    *(float *)(v + 8) = *(float *)(v + 8) + 1.3888889225199818611145e-03f;
    Fa2a84657_FUN_00282CD8(tmp, (char *)p + 16, v);

    n = *(int *)(p + 4) + (int)0xFE000000;
    *(int *)(p + 4) = n;
    if (((unsigned)(n & 0xFF000000) - 1) > 0x5EFFFFFFu || Fa2a84657_FUN_00282978((char *)p + 10) != 0) {
        Fa2a84657_FUN_002B9180(p);
    } else {
        float f0;
        float f1;

        f1 = *(float *)(p + 12);
        f0 = 2.1000000000000000000000e+05f - f1;
        f0 = f0 * 7.0000000298023223876953e-02f;
        f1 = f1 + f0;
        *(float *)(p + 12) = f1;
        p[8] = p[8] + 1;
    }
}

INCLUDE_ASM("asm/game", func_002C2170);

INCLUDE_ASM("asm/game", func_002C2210);

INCLUDE_ASM("asm/game", func_002C23B8);

INCLUDE_ASM("asm/game", func_002C2658);

INCLUDE_ASM("asm/game", func_002C27B0);

void func_002C28F8(char *object)
{
    int count;
    int low;
    int high;

    F15a8b7f0_FUN_00282D30(object + 32, object + 32, 0.975f);
    F15a8b7f0_FUN_00282CC0(object + 16, object + 16, object + 32);
    *(float *)(object + 12) += 6300.0f;
    count = *(unsigned char *)(object + 4) - 4;
    if (count <= 0)
        F15a8b7f0_FUN_002B9180(object);
    else {
        low = (count << 8) | 0x60000000;
        high = (count << 16) | low;
        *(int *)(object + 4) = high | count;
    }
}

INCLUDE_ASM("asm/game", func_002C29A0);

INCLUDE_ASM("asm/game", func_002C2A88);

INCLUDE_ASM("asm/game", func_002C2C80);

INCLUDE_ASM("asm/game", func_002C2FD8);

INCLUDE_ASM("asm/game", func_002C30F8);

INCLUDE_ASM("asm/game", func_002C3150);

/* advances three floats of a sub-object by a resident offset triple, calls a three-pointer update, subtracts the offsets back out, rejects the result when any coordinate leaves the 2.0..1021.0 band, and otherwise rescales a 24-bit handle by the ratio of two helper lookups over a signed halfword index */
void func_002C3280(u8 *self)
{
    char *s2 = (char *)self + 32;
    int n;
    float a;
    float b;

    if (*(int *)(s2 + 28) == 1) {
        char *base = D_00189E20_18;
        *(float *)(self + 16) = *(float *)(base + 128) + *(float *)(s2 + 16);
        *(float *)(self + 20) = *(float *)(base + 132) + *(float *)(s2 + 20);
        *(float *)(self + 24) = *(float *)(base + 136) + *(float *)(s2 + 24);
        func_00282CC0_19(self + 16, self + 16, s2);
        *(float *)(s2 + 16) = *(float *)(self + 16) - *(float *)(base + 128);
        *(float *)(s2 + 20) = *(float *)(self + 20) - *(float *)(base + 132);
        *(float *)(s2 + 24) = *(float *)(self + 24) - *(float *)(base + 136);
    } else {
        func_00282CC0_19(self + 16, self + 16, s2);
    }

    if (*(float *)(self + 16) < 2.0f || *(float *)(self + 16) > 1021.0f
        || *(float *)(self + 20) < 2.0f || *(float *)(self + 20) > 1021.0f
        || *(float *)(self + 24) < 2.0f || *(float *)(self + 24) > 1021.0f) {
        func_002B9180_15(self);
        return;
    }

    if (func_00282978_11((char *)self + 10) != 0) {
        func_002B9180_15(self);
        return;
    }

    n = *(int *)(self + 4) & 0xFFFFFF;
    a = func_00283CE0_4(*(short *)(self + 10) - 1);
    b = func_00283CE0_4(*(short *)(self + 10));
    *(int *)(self + 4) = func_00283D38_3(n, *(int *)(self + 4), a / b);
}

INCLUDE_ASM("asm/game", func_002C3430);

INCLUDE_ASM("asm/game", func_002C36D0);

void func_002C37E0(char *obj)
{
    char *sub = obj + 32;
    int w;
    int n;

    switch (*(unsigned char *)(sub + 2)) {
    case 2:
        *(float *)(obj + 16) = *(float *)(*(char **)(sub + 4) + 16) + *(float *)(sub + 16);
        *(float *)(obj + 20) = *(float *)(*(char **)(sub + 4) + 20) + *(float *)(sub + 20);
        *(float *)(obj + 24) = *(float *)(*(char **)(sub + 4) + 24) + *(float *)(sub + 24);
        break;
    case 1:
        goto tail;
    }
    w = *(int *)(obj + 4);
    n = (w >> 24);
    n = n - *(short *)(obj + 32);
    if (n <= 0) {
        Fccb147a4_FUN_002B9180(obj, sub);
        return;
    }
    *(int *)(obj + 4) = (w & 0xffffff) | (n << 24);
tail:
    if (*(unsigned char *)(sub + 3) != 0) {
        obj += 16;
        Fccb147a4_FUN_00300190(obj, obj);
    }
}

INCLUDE_ASM("asm/game", func_002C38A0);

INCLUDE_ASM("asm/game", func_002C38E0);

INCLUDE_ASM("asm/game", func_002C3B08);

INCLUDE_ASM("asm/game", func_002C3D80);

void func_002C3EE8(char *p)
{
    char *q = p + 32;

    Fa03721e9_FUN_00282CC0(p + 16, p + 16, q);
    *(float *)(p + 12) = *(float *)(p + 12) + *(float *)(q + 16);
    *(unsigned char *)(p + 8) = *(unsigned char *)(p + 8) + 1;
    if (--*(short *)(p + 10) == 0) {
        *(unsigned int *)(p + 4) = *(unsigned int *)(p + 4) + 0xff000000;
        *(short *)(p + 10) = 2;
    }
    if ((*(unsigned int *)(p + 4) & 0xff000000) == 0)
        Fa03721e9_FUN_002B9180(p);
}

INCLUDE_ASM("asm/game", func_002C3F88);

INCLUDE_ASM("asm/game", func_002C4100);

INCLUDE_ASM("asm/game", func_002C43C8);

INCLUDE_ASM("asm/game", func_002C4500);

INCLUDE_ASM("asm/game", func_002C4788);

INCLUDE_ASM("asm/game", func_002C47E8);

INCLUDE_ASM("asm/game", func_002C4B10);

INCLUDE_ASM("asm/game", func_002C4B50);

INCLUDE_ASM("asm/game", func_002C4D18);

INCLUDE_ASM("asm/game", func_002C4F08);

INCLUDE_ASM("asm/game", func_002C5020);

INCLUDE_ASM("asm/game", func_002C5068);
