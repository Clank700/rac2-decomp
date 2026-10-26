/* Opus big34, 2026-10-26. Spark projectile update (states 0/1 fly + trail, 2 impact burst).
 * PERMUTE-FLAGS: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Unit: its own file src/levels/shared/L00_003DB118-g8.c with those flags (marker in L00_003D37E8.c).
 * Level 0 first draft: 903 of 910 instructions, 320 lines differ (129 ignoring registers and
 * stack offsets). Frame 0x120 vs retail 0x110: retail's state-2 `pick[2]` table shares the
 * state-1 slot at sp+0x30 (block-local slots; see the func_L00_00406150 header for the
 * address-taken preserve rule) and its HitInfo block is 0x30 bytes at sp+0x50.
 * Retail also forms the collision record three ways (col pointer in s5, a fresh 0x1BF220
 * address in the non-qualifying-object arm, %hi of 0x1BF240 hoisted for the spark loops).
 * Callee prototypes here follow the matched units (func_002BDCE8 from L03_003F09C0-g8.c,
 * func_L00_00340CF8, func_L00_003DCAC8 from their own files).
 */
#include "include_asm.h"
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
typedef struct { char pad[112]; float scale; char tail[108]; } TableEntry;
typedef struct {
    char state[24];
    char *object;
    unsigned int detail;
    Vec position;
    Vec unk30;
    Vec normal;
} CollisionResult;
typedef struct {
    Vec pos;
    char pad10[8];
    unsigned char kind;
    unsigned char flag;
    unsigned short type;
    char pad1c[4];
    int count;
    char pad24[12];
} HitInfo;

extern unsigned char D_0013957F[];
extern char D_L00_00262570[];
extern CollisionResult D_L00_001BF200;
extern char *D_0018C0B0;
extern float D_L00_001B03E4 __attribute__((sda));
extern float D_L00_001A8F20;

extern void func_00300190(void *, void *);
extern void func_002FEE70(int, void *, int);
extern void func_002FEE50(int);
extern void func_002FE880(void *a, void *b, float c);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D08(void *, void *, void *, float);
extern float func_00283B98(float, float);
extern void func_00282C88(void *);
extern void func_002833F0(void *, void *);
extern float func_00283198(float);
extern float func_00283180(float);
extern int func_002A7820(int, int);
extern void func_00282D30(void *, void *, float);
extern int func_001163B0(void);
extern float func_002A7878(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_002BE278(void *, void *, int, float);
extern int func_00282948(void *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002A8C00(void *, void *, int, void *, float);
extern void func_002A8E20(char *, void *);
extern void func_0032D758(void *, int, int);
extern void func_L00_003DC3E0(char *, int, void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float func_002A7940(void);
extern void func_002ACEC0(void *, void *, void *, float);
extern unsigned char *func_L00_00340CF8(void *, void *, void *, int, int, float);
extern void func_L00_003DCAC8(char *, int, int, int, int, char *, float, float);
extern int func_002A77E0(int);
extern u8 *func_002BDCE8(void *p, float f0, float f1, float f2, int z, void *local,
                         float f3, int v, int t);
extern int func_00283CF0(float);
extern void func_L00_003DC2D0(char *);
extern int func_002B4038(int, int);
extern void func_L00_002E6EF8(void *, void *);
extern void func_L00_003DC640();
extern void func_0029F338(void *);

void func_L00_003DB118(char *self)
{
    Vec ray;
    Vec scale3;
    Vec push;
    Vec a30;
    Vec a40;
    HitInfo hit;
    Vec spark;
    char *timer;
    char *pv;
    char *pos;
    int i;
    u8 *p;

    pv = *(char **)(self + 0x68);
    if (*(unsigned char *)(self + 0x20) != 0) {
        func_00300190(self + 0x10, self + 0x10);
        for (i = 3; i >= 0; i--) {
            func_00300190(pv + 0x10 + (3 - i) * 0x10, pv + 0x10 + (3 - i) * 0x10);
        }
    }
    switch (*(unsigned char *)(self + 0x20)) {
    case 0:
        for (i = 0; i < 4; i++) {
            *(Quad *)(pv + 0x10 + i * 0x10) = *(Quad *)(self + 0x10);
        }
        *(unsigned char *)(self + 0x20) = 1;
    case 1:
        pos = self + 0x10;
        ray.q = *(Quad *)pos;
        timer = pv + 0x60;
        func_002FEE70(*(int *)(pv + 0x78), pv, 0);
        func_00282CC0(pos, pos, pv);
        func_002FE880(pos, pv, D_L00_001B03E4 * 0.00027777778f);
        for (i = 3; i > 0; i--) {
            func_00282D08(pv + 0x10 + i * 0x10, pv + 0x10 + i * 0x10, pv + i * 0x10, 0.2f);
        }
        *(Quad *)(pv + 0x10) = *(Quad *)pos;
        *(float *)(pv + 0x64) = func_00283B98(*(float *)(pv + 0x64), *(float *)(pv + 0x68));
        func_00282C88(&scale3);
        scale3.f[1] = *(float *)(pv + 0x64) * 0.5f;
        scale3.f[0] = *(float *)(pv + 0x64) * 0.25f;
        scale3.f[2] = *(float *)(pv + 0x64) * 0.375f;
        func_002833F0(self + 0xC0, &scale3);
        *(float *)(self + 0xC0) = *(float *)(self + 0xC0) * 0.4f * (func_00283198(*(float *)(pv + 0x64)) + 2.0f);
        *(float *)(self + 0xD4) = *(float *)(self + 0xD4) * 0.5f * (func_00283180(*(float *)(pv + 0x64)) + 2.0f);
        *(float *)(self + 0xE8) = *(float *)(self + 0xE8) * 0.75f * (func_00283198(*(float *)(pv + 0x64)) + 2.0f);
        {
            int c = func_002A7820(0x7F, 0xFF);
            *(int *)(self + 0x78) = ((c << 16) + (c << 8) + c) | 0x7F000000;
        }
        func_00282D30(&push, pv, -0.125f);
        if (func_001163B0() % 10 == 0) {
            func_00282C88(&a40);
            a30.f[0] = *(float *)(self + 0x10) + func_002A7878(-0.15f, 0.15f);
            a30.f[1] = *(float *)(self + 0x14) + func_002A7878(-0.15f, 0.15f);
            a30.f[2] = *(float *)(self + 0x18) + func_002A7878(-0.025f, 0.025f);
            a40.f[0] = func_002A7878(-0.025f, 0.025f);
            a40.f[1] = func_002A7878(-0.025f, 0.025f);
            a40.f[2] = func_002A7878(0.0f, 0.025f);
            func_00282F20(&a40, &a40, 0.05f);
            func_002BE278(&a30, &a40, 0, -1.0f);
        }
        if (func_00282948(timer) != 0) goto kill;
        if (func_002761F8(&ray, pos, 0, self, 0) != 0 || func_00277258(pos, 0, self, 0.05f) != 0) {
            CollisionResult *col = &D_L00_001BF200;
            char *obj = col->object;
            if (obj != 0) {
                char *hero;
                if ((*(long long *)(obj + 0x30) & ((long long)0xA000 << 31)) && obj != (hero = D_0018C0B0)
                    && *(short *)(obj + 0xAA) != 0x5C9) {
                    func_00282CF0(&a30, obj + 0x10, hero + 0x10);
                    func_00282F20(&a30, &a30, 1.0f);
                    func_00282F20(&hit, &hit, 0.116666675f);
                    func_002A8C00(&hit, self, 0x910000, &a30, ((TableEntry *)D_L00_00262570)[D_0013957F[0]].scale);
                    hit.pos.q = a30.q;
                    hit.kind = 5;
                    hit.pos.f[3] = 5627.925f;
                    hit.count = 1;
                    hit.flag = 1;
                    hit.type = *(unsigned short *)(col->object + 0xAA);
                    func_002A8E20(col->object, &hit);
                    func_0032D758(col->object, 0x3F, *(int *)(self + 0xB8));
                    a40.q = *(Quad *)(col->object + 0x10);
                    a40.f[2] = a40.f[2] + 5.0f;
                    a30.q = a40.q;
                    a30.f[2] = a30.f[2] - 10.0f;
                    *(Quad *)pos = col->normal.q;
                    *(unsigned char *)(self + 0x20) = 2;
                    *(unsigned short *)(self + 0x34) |= 0x41;
                    *(Quad *)(pv + 0x50) = col->normal.q;
                    *(int *)(pv + 0x7C) = 1;
                    for (i = 2; i >= 0; i--) {
                        func_00282F20(&spark, &D_L00_001BF200.normal, func_002A7878(0.16666667f, 0.33333334f));
                        spark.f[0] += func_002A7878(-0.15f, 0.15f);
                        spark.f[1] += func_002A7878(-0.15f, 0.15f);
                        spark.f[2] += func_002A7878(-0.15f, 0.15f);
                        func_00282F20(&spark, &spark, func_002A7878(0.033333335f, 0.10000001f));
                        func_002BE278(pos, &spark, 0, -1.0f);
                    }
                } else {
                    *(Quad *)pos = col->position.q;
                    *(unsigned char *)(self + 0x20) = 2;
                    *(unsigned short *)(self + 0x34) |= 0x41;
                    *(Quad *)(pv + 0x50) = col->normal.q;
                    for (i = 5; i >= 0; i--) {
                        func_00282F20(&a30, &D_L00_001BF200.normal, func_002A7878(0.16666667f, 0.33333334f));
                        a30.f[0] += func_002A7878(-0.15f, 0.15f);
                        a30.f[1] += func_002A7878(-0.15f, 0.15f);
                        a30.f[2] += func_002A7878(-0.15f, 0.15f);
                        func_00282F20(&a30, &a30, func_002A7878(0.033333335f, 0.10000001f));
                        func_002BE278(pos, &a30, 0, -1.0f);
                    }
                }
            } else {
                *(Quad *)pos = col->position.q;
                *(unsigned char *)(self + 0x20) = 2;
                *(unsigned short *)(self + 0x34) |= 0x41;
                *(Quad *)(pv + 0x50) = col->normal.q;
                for (i = 5; i >= 0; i--) {
                    func_00282F20(&a30, &D_L00_001BF200.normal, func_002A7878(0.16666667f, 0.33333334f));
                    a30.f[0] += func_002A7878(-0.15f, 0.15f);
                    a30.f[1] += func_002A7878(-0.15f, 0.15f);
                    a30.f[2] += func_002A7878(-0.15f, 0.15f);
                    func_00282F20(&a30, &a30, func_002A7878(0.033333335f, 0.10000001f));
                    func_002BE278(pos, &a30, 0, -1.0f);
                }
            }
            *(int *)(pv + 0x60) = 15;
            func_L00_003DC3E0(self, 15, pos, &D_L00_001BF200.normal, 0.083333336f);
        }
        break;
    case 2:
        {
            int pick[2];
            float life;
            pick[1] = 0x48;
            pick[0] = 0x44;
            func_00282F20(&a40, pv, 2.0f);
            pos = self + 0x10;
            func_00282CC0(&a40, &a40, pos);
            func_00282DD8(&hit, pos, &a40);
            func_00282F20(&hit, &hit, 1.0f);
            func_002ACEC0(&hit, &hit, pv, func_002A7940());
            life = func_002A7878(0.008333334f, 0.050000004f);
            func_L00_00340CF8(pos, pv, &hit, pick[func_001163B0() % 2], func_002A7820(0x1E, 0x32), life);
            life = func_002A7878(0.75f, 1.2f);
            func_L00_003DCAC8(pos, 0x103080, func_002A7820(0x3F, 0x5F), 0xB, 2, pv, life, func_002A7940());
            life = func_002A7878(0.75f, 1.2f) * 0.75f;
            func_L00_003DCAC8(pos, 0x103080, func_002A7820(0x4F, 0x6F), 0xB, 2, pv, life, func_002A7940());
            life = func_002A7878(0.75f, 1.2f) * 0.5f;
            func_L00_003DCAC8(pos, 0x103080, func_002A7820(0x5F, 0x7F), 0xB, 2, pv, life, func_002A7940());
            if (func_00282948(pv + 0x60) != 0) goto kill;
            if (*(int *)(pv + 0x7C) == 0) {
                for (i = 3; i > 0; i--) {
                    func_00282D08(pv + 0x10 + i * 0x10, pv + 0x10 + i * 0x10, pv + i * 0x10, 0.2f);
                }
            } else {
                for (i = 3; i > 0; i--) {
                    func_00282D08(pv + 0x10 + i * 0x10, pv + 0x10 + i * 0x10, pv + i * 0x10, 0.5f);
                }
            }
            *(Quad *)(pv + 0x10) = *(Quad *)pos;
            *(float *)(self + 0x2C) = *(float *)(self + 0x2C) + 0.0005f;
        }
        break;
    }
    if (*(unsigned char *)(self + 0x20) == 1) {
        pos = self + 0x10;
        for (i = 3; i >= 0; i--) {
            int n = func_002A77E0(5);
            p = func_002BDCE8(pos, 0.2f, 1.0f, 0.9f, func_002A77E0(2) ? -n : n, &D_L00_001A8F20, 210000.0f, 0x7F204080, 1);
            if (p) {
                *(unsigned short *)(p + 0xA) = 5;
                p[9] = func_00283CF0(4.0f) + 0x40;
                *(int *)(p + 0x24) = 2;
                p[0x2A] = 0x30;
                p[0x2B] = p[0xA];
            }
        }
        for (i = 2; i >= 0; i--) {
            int n = func_002A77E0(3);
            p = func_002BDCE8(pos, 0.05f, 1.0f, 0.9f, func_002A77E0(2) ? -n : n, &D_L00_001A8F20, 157500.0f, 0x7F4080FF, 1);
            if (p) {
                *(unsigned short *)(p + 0xA) = 2;
                p[9] = func_00283CF0(4.0f) + 0x40;
                *(int *)(p + 0x24) = 2;
                p[0x2A] = 0x40;
                p[0x2B] = p[0xA];
            }
        }
        for (i = 1; i >= 0; i--) {
            int n = func_002A77E0(3);
            p = func_002BDCE8(pos, 0.05f, 1.0f, 0.9f, func_002A77E0(2) ? -n : n, &D_L00_001A8F20, 105000.0f, 0x7FFFFFFF, 1);
            if (p) {
                *(unsigned short *)(p + 0xA) = 2;
                p[9] = func_00283CF0(4.0f) + 0x40;
                *(int *)(p + 0x24) = 2;
                p[0x2A] = 0x60;
                p[0x2B] = p[0xA];
            }
        }
    }
    func_L00_003DC2D0(self);
    if (func_002B4038(*(int *)(pv + 0x74), *(int *)(pv + 0x70)) != 0) {
        func_L00_002E6EF8(func_L00_003DC640, self);
        return;
    }
kill:
    func_002FEE50(*(int *)(pv + 0x78));
    func_0029F338(self);
}
