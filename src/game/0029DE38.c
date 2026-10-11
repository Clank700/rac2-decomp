#include "include_asm.h"

/* Measured partial layouts; original type and game roles are unknown. */
typedef unsigned int Rac2Native_abf21065e887d7a9_FallbackU32;

typedef struct Rac2Native_abf21065e887d7a9_FallbackPredicate112Layout {
    unsigned char unknown_00[0x90];
    Rac2Native_abf21065e887d7a9_FallbackU32 flags_90;
    Rac2Native_abf21065e887d7a9_FallbackU32 unknown_94;
    Rac2Native_abf21065e887d7a9_FallbackU32 flags_98;
} Rac2Native_abf21065e887d7a9_FallbackPredicate112Layout;

extern Rac2Native_abf21065e887d7a9_FallbackPredicate112Layout D_00139768;

typedef unsigned char u8;

extern u8 D_L03_001D2540[];

extern void Ff2d8e5ad_FUN_002A3110(unsigned char *a, int b, unsigned char *c);

extern void Ff2d8e5ad_FUN_00283130(unsigned char *a, long long v);

extern void Ff2d8e5ad_FUN_002830C0(unsigned char *a, unsigned char *b, unsigned char *c);

extern void Ff2d8e5ad_FUN_00282D30(unsigned char *a, unsigned char *b, float f);

extern void Ff2d8e5ad_FUN_00283098(unsigned char *a, unsigned char *b, unsigned char *c);

extern void Ff2d8e5ad_FUN_00282CC0(unsigned char *a, unsigned char *b, unsigned char *c);

extern float Ff2d8e5ad_FUN_00282E48(unsigned char *a, unsigned char *b);

typedef float f32;

typedef unsigned int u32;

extern void *D_L00_001B1E00[16];

extern u32 D_L00_001B1E40[16];

typedef struct {
    unsigned char key;
    unsigned char reserved01[11];
    int target;
} Row16b52b2850;

typedef struct {
    unsigned char reserved00[32];
    Row16b52b2850 *rows;
} ListObjectb52b2850;

typedef struct {
    short first;
    short second;
} Pairb52b2850;

extern int D_L03_001DE1C0[];

extern ListObjectb52b2850 *D_L03_001DAB80[];

extern Pairb52b2850 D_L03_001DDA00[];

void func_00282A60(unsigned int *dst, unsigned int val, int size);

/* Return whether both flag bit 0x10000 at data offset 0x90 and flag bit 0x04000000 at offset 0x98 are set, retaining the measured early rejection path. */
int func_0029DE38(void)
{
    if ((D_00139768.flags_90 & 0x10000u) == 0 &&
        (D_00139768.flags_98 & 0x04000000u) != 0)
        return 0;
    if ((D_00139768.flags_90 & 0x10000u) != 0 &&
        (D_00139768.flags_98 & 0x04000000u) != 0)
        return 1;
    return 0;
}

INCLUDE_ASM("asm/game", func_0029DEA8);

INCLUDE_ASM("asm/game", func_0029EFC0);

INCLUDE_ASM("asm/game", func_0029EFD0);

INCLUDE_ASM("asm/game", func_0029F0C8);

INCLUDE_ASM("asm/game", func_0029F338);

/* shared native body of family d1172b6afb7d978b */
void func_0029F390(u8 *param_1)
{
    if (param_1[66] != 255) {
        u8 *tbl = (u8 *)(*(volatile int *)(param_1 + 36) + 72);

        *(int *)(param_1 + 88) = *(int *)(*(int *)(tbl + (*(volatile u8 *)(param_1 + 66) << 2)) + (param_1[64] << 2) + 28);
        param_1[110] = *(u8 *)(*(int *)(tbl + (*(volatile u8 *)(param_1 + 66) << 2)) + 18);
        param_1[108] = *(u8 *)(*(int *)(tbl + (*(volatile u8 *)(param_1 + 66) << 2)) + 17);
    } else {
        param_1[108] = 255;
        param_1[110] = 0;
        *(int *)(param_1 + 88) = (int)(D_L03_001D2540 + (param_1[64] << 11));
    }

    *(int *)(param_1 + 92) = *(int *)(*(int *)(*(volatile int *)(param_1 + 36) + (param_1[67] << 2) + 72) + (param_1[65] << 2) + 28);
}

INCLUDE_ASM("asm/game", func_0029F450);

INCLUDE_ASM("asm/game", func_0029F528);

INCLUDE_ASM("asm/game", func_0029F530);

INCLUDE_ASM("asm/game", func_0029F628);

INCLUDE_ASM("asm/game", func_0029F648);

void func_0029F6A0(
    unsigned char *obj, unsigned int index, unsigned char *dest)
{
    unsigned char m0[16];
    unsigned char m1[16];
    unsigned char *base;
    unsigned char *p;
    short n;

    base = *(unsigned char **)(obj + 36);
    p = base + ((unsigned int)*(unsigned char *)(base + 44) << 4);
    p = p + ((index << 4) + 64u);
    n = *(short *)(p + 6);
    if (n < *(short *)(p + 14))
        n = *(short *)(p + 14);
    if (n >= 0)
        Ff2d8e5ad_FUN_002A3110(obj, n + 1, (unsigned char *)0x80000000u);
    Ff2d8e5ad_FUN_00283130(m0, *(long long *)(p));
    Ff2d8e5ad_FUN_00283130(m1, *(long long *)(p + 8));
    *(float *)(m0 + 12) = 1.0f;
    *(float *)(m1 + 12) = 1.0f;
    if (n >= 0) {
        Ff2d8e5ad_FUN_002830C0(m0, m0, (unsigned char *)
            (((unsigned int)*(short *)(p + 6) << 6) + 0x70000000u));
        Ff2d8e5ad_FUN_002830C0(m1, m1, (unsigned char *)
            (((unsigned int)*(short *)(p + 14) << 6) + 0x70000000u));
    }
    Ff2d8e5ad_FUN_00282D30(m0, m0, *(float *)(obj + 44) * 0.0009765625f);
    Ff2d8e5ad_FUN_00282D30(m1, m1, *(float *)(obj + 44) * 0.0009765625f);
    Ff2d8e5ad_FUN_00283098(m0, m0, obj + 192);
    Ff2d8e5ad_FUN_00283098(m1, m1, obj + 192);
    Ff2d8e5ad_FUN_00282CC0(m0, m0, obj + 16);
    Ff2d8e5ad_FUN_00282CC0(m1, m1, obj + 16);
    Ff2d8e5ad_FUN_00282CC0(dest, m0, m1);
    Ff2d8e5ad_FUN_00282D30(dest, dest, 0.5f);
    *(float *)(dest + 12) = Ff2d8e5ad_FUN_00282E48(dest, m0);
}

INCLUDE_ASM("asm/game", func_0029F840);

INCLUDE_ASM("asm/game", func_0029F960);

void func_0029F978(u8 *a0,u32 a1,u8 *a2) {
 u8 *p;
 if(a2[1]!=0) return;
 a2[0]=a1; a2[1]=1;
 *(f32 *)(a2+0x1c)=1.0f;
 *(f32 *)(a2+0x20)=1.0f;
 *(f32 *)(a2+0x24)=1.0f;
 *(f32 *)(a2+0x28)=1.0f;
 p=*(u8 **)(*(u8 **)(*(u8 **)(a0+0x24)+0x1c)+a2[0]*4+4);
 *(u32 *)(a2+4)=p[p[0]+4]*0x40+0x70000000;
 *(u8 **)(a2+8)=*(u8 **)(a0+0x54);
 *(u8 **)(a0+0x54)=a2;
}

INCLUDE_ASM("asm/game", func_0029F9F0);

/* Reserve or reuse an object slot, reset its associated state and return signed slot index */
int func_0029FA88(void *object)
{
    int index;
    for (index = 0; index < 16; ++index) {
        if (D_L00_001B1E00[index] == 0 ||
            D_L00_001B1E00[index] == object) {
            D_L00_001B1E00[index] = object;
            D_L00_001B1E40[index] = 0;
            return index;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/game", func_0029FAE0);

INCLUDE_ASM("asm/game", func_0029FB20);

INCLUDE_ASM("asm/game", func_0029FC20);

INCLUDE_ASM("asm/game", func_0029FCC0);

INCLUDE_ASM("asm/game", func_0029FD48);

INCLUDE_ASM("asm/game", func_0029FDE8);

INCLUDE_ASM("asm/game", func_0029FDF0);

/* shared native body of family b52b2850e37f2b40 */
void func_0029FEE0(void)
{
    int *selected;
    ListObjectb52b2850 *object;
    Row16b52b2850 *row;
    unsigned char *keys;
    unsigned int *dst;
    Pairb52b2850 *pair;
    int *next;

    selected = D_L03_001DE1C0;
    while (*selected >= 0) {
        next = selected + 1;
        object = D_L03_001DAB80[*selected];
        row = object->rows;
        for (;;) {
            keys = (unsigned char *)row;
            dst = (unsigned int *)(row->target & 0x7FFFFFFF);
            if (*keys != 255) {
                do {
                    pair = &D_L03_001DDA00[*keys];
                    if (pair->first != 0) {
                        dst[12] = (dst[12] & 0xFFFFC000u) | pair->first;
                    }
                    keys++;
                    if (pair->second != 0) {
                        dst[16] = (dst[16] & 0xFFFFC000u) | pair->second;
                    }
                    dst += 16;
                } while (*keys != 255);
            }
            if (row->target < 0) {
                goto out;
            }
            row++;
        }
out:
        ;
        selected = next;
    }
}

INCLUDE_ASM("asm/game", func_0029FFB8);

INCLUDE_ASM("asm/game", func_002A0048);

INCLUDE_ASM("asm/game", func_002A0180);

void func_002A01C8(void)
{
    func_00282A60((unsigned int *)0x70003A00, 0x40000000, 0x3C0);
}

INCLUDE_ASM("asm/game", func_002A01F0);

INCLUDE_ASM("asm/game", func_002A0220);

INCLUDE_ASM("asm/game", func_002A0250);

INCLUDE_ASM("asm/game", func_002A0300);

INCLUDE_ASM("asm/game", func_002A0380);

INCLUDE_ASM("asm/game", func_002A03C0);
