#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

typedef struct {
    u8 pad00[0x40];
    u32 w40;
    u32 w44;
    u32 w48;
    u32 w4c;
    u32 w50;
    u32 w54;
    u32 w58;
    f32 f5c;
    f32 f60;
    u32 w64;
    f32 f68;
    f32 f6c;
    u64 l70;
    u64 l78;
    u64 l80;
    u64 l88;
} Pkt_00303070;

extern char D_00189EA0[];
extern int func_002ACBC8(void *, int);
extern u64 func_0027C878(int);
extern void func_00303738(void *, void *, int, int, int);
extern void func_00280B90(void *, void *, int);

void func_00303070(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    int v = *(int *)(p + 0x44);

    if (v != -1 && func_002ACBC8(D_00189EA0, v) != 0 && (*(u32 *)(p + 0x4C) & 4) == 0) {
        Pkt_00303070 pk;
        int i = 0;
        int j;

        pk.w50 = 0;
        pk.w40 = 0x80808080;
        pk.f6c = 1.0f;
        pk.w4c = 0x80808080;
        pk.w48 = 0x80808080;
        pk.w44 = 0x80808080;
        pk.w54 = 0;
        pk.w58 = 0;
        pk.f5c = 1.0f;
        pk.f60 = 1.0f;
        pk.w64 = 0;
        pk.f68 = 1.0f;
        pk.l78 = func_0027C878(*(int *)(p + 0x48) + 0x3F);
        pk.l80 = 0xFF9000000260ULL;
        pk.l88 = 0x8000000088ULL;
        pk.l70 = 0;
        do {
            j = 0;
            do {
                func_00303738(obj, &pk, j, i, 0);
                func_00303738(obj, &pk, j + 1, i, 1);
                func_00303738(obj, &pk, j, i + 1, 2);
                func_00303738(obj, &pk, j + 1, i + 1, 3);
                func_00280B90(&pk, 0, 0);
                j = j + 1;
            } while (j < 7);
            i = i + 1;
        } while (i < 7);
    }
}
