#include "include_asm.h"

extern void func_L00_002AED68(void);

extern void func_L00_002AF860(void);

extern void func_L00_002AEB18(void);

extern char D_00189E20_12[];

extern void func_0029F338_1(char *entry);

typedef unsigned char u8;

typedef int s32;

typedef float f32;

extern u8 D_00189E20_1[];

typedef struct { u8 prefix[0xc38]; f32 plane; f32 depth; } GornFloatInterval64;

/* calls three measured no-argument functions in sequence */
void func_L00_002AFBC0(void) {
 func_L00_002AED68();
 func_L00_002AF860();
 func_L00_002AEB18();
}

INCLUDE_ASM("asm/levels", func_L00_002AFBF0);

INCLUDE_ASM("asm/levels", func_L00_002B0480);

INCLUDE_ASM("asm/levels", func_L00_002B0528);

INCLUDE_ASM("asm/levels", func_L00_002B0968);

/* for one fixed 80-byte slot: stores a value, rewrites a state word, dispatches through a function pointer at entry+100 unless the entry is null or carries a 253/254 sentinel, then releases two stored entry pointers, skipping the second when the slot index is 3 */
void func_L00_002B1230(int slot, int value)
{
    char *e;
    void (*fn)(char *);

    {
        char *p = D_00189E20_12 + slot * 80;

        *(int *)(p + 4660) = value;
        if (*(int *)(p + 4676) != 3) {
            *(int *)(p + 4676) = 3;
            e = *(char **)(p + 4640);
            if (e != 0) {
                if (*(unsigned char *)(e + 32) != 254) {
                    if (*(unsigned char *)(e + 32) != 253) {
                        fn = *(void (**)(char *))(e + 100);
                        if (fn != 0)
                            fn(e);
                    }
                }
            }
        }
    }
    {
        char *q = D_00189E20_12 + slot * 80;

        e = *(char **)(q + 4640);
        *(int *)(q + 4676) = 0;
        *(int *)(q + 4680) = 0;
        if (e != 0) {
            func_0029F338_1(e);
            *(char **)(q + 4640) = 0;
        }
        e = *(char **)(q + 4644);
        if (e != 0 && slot != 3) {
            func_0029F338_1(e);
            *(char **)(q + 4644) = 0;
        }
    }
}

INCLUDE_ASM("asm/levels", func_L00_002B1308);

INCLUDE_ASM("asm/levels", func_L00_002B1350);

INCLUDE_ASM("asm/levels", func_L00_002B1F90);

INCLUDE_ASM("asm/levels", func_L00_002B2120);

INCLUDE_ASM("asm/levels", func_L00_002B2200);

INCLUDE_ASM("asm/levels", func_L00_002B2318);

INCLUDE_ASM("asm/levels", func_L00_002B2A40);

INCLUDE_ASM("asm/levels", func_L00_002B2BD0);

INCLUDE_ASM("asm/levels", func_L00_002B2C50);

INCLUDE_ASM("asm/levels", func_L00_002B2C58);

INCLUDE_ASM("asm/levels", func_L00_002B2CC8);

INCLUDE_ASM("asm/levels", func_L00_002B30E8);

/* tests the signed short identifier at offset 0xaa of a nonnull object against 71 */
s32 func_L00_002B3248(u8 *object) {
 if(object==0) return 0;
 return *(short *)(object+0xaa)==71;
}

INCLUDE_ASM("asm/levels", func_L00_002B3268);

INCLUDE_ASM("asm/levels", func_L00_002B32F8);

INCLUDE_ASM("asm/levels", func_L00_002B35A0);

INCLUDE_ASM("asm/levels", func_L00_002B36E0);

INCLUDE_ASM("asm/levels", func_L00_002B3900);

/* Test whether a scalar lies below a plane within its configured depth, rejecting unordered values */
int func_L00_002B3998(f32 value)
{
    GornFloatInterval64 *root = (GornFloatInterval64 *)D_00189E20_1;
    if (value < root->plane) {
        if (root->plane - value <= root->depth)
            return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_002B39D8);

INCLUDE_ASM("asm/levels", func_L00_002B39F0);

INCLUDE_ASM("asm/levels", func_L00_002B3D10);

INCLUDE_ASM("asm/levels", func_L00_002B3DC0);

INCLUDE_ASM("asm/levels", func_L00_002B3E40);

INCLUDE_ASM("asm/levels", func_L00_002B3EF8);

INCLUDE_ASM("asm/levels", func_L00_002B3F60);

INCLUDE_ASM("asm/levels", func_L00_002B3F68);

INCLUDE_ASM("asm/levels", func_L00_002B41B8);

INCLUDE_ASM("asm/levels", func_L00_002B4208);

INCLUDE_ASM("asm/levels", func_L00_002B42D8);

INCLUDE_ASM("asm/levels", func_L00_002B4308);

INCLUDE_ASM("asm/levels", func_L00_002B4458);

INCLUDE_ASM("asm/levels", func_L00_002B47A8);

INCLUDE_ASM("asm/levels", func_L00_002B4900);

INCLUDE_ASM("asm/levels", func_L00_002B5250);

INCLUDE_ASM("asm/levels", func_L00_002B54F8);

INCLUDE_ASM("asm/levels", func_L00_002B5590);

INCLUDE_ASM("asm/levels", func_L00_002B55F0);

INCLUDE_ASM("asm/levels", func_L00_002B5A88);

INCLUDE_ASM("asm/levels", func_L00_002B5B60);

INCLUDE_ASM("asm/levels", func_L00_002B6118);

INCLUDE_ASM("asm/levels", func_L00_002B6198);

INCLUDE_ASM("asm/levels", func_L00_002B6560);

INCLUDE_ASM("asm/levels", func_L00_002B6BC8);

INCLUDE_ASM("asm/levels", func_L00_002B75A0);

INCLUDE_ASM("asm/levels", func_L00_002B7718);
