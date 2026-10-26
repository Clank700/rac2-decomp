/* func_00302848: near miss (about 12 instructions off, 472 B vs 468): structure, calls and constants match. Left over: retail splits the D_001F2638 load into lui + lw with a distinct destination and fills the beqz delay slot with the lui, keeps the call result in $a1, and issues "sq $zero" before the first gp load. Own unit with -O2 -G8 -ffunction-sections -mno-split-addresses. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } V4_F302848;

extern s32 D_001AE930 __attribute__((sda));
extern s32 D_001AE900 __attribute__((sda));
extern s32 D_001AE928 __attribute__((sda));
extern float D_001AE920 __attribute__((sda));
extern s32 D_001AE92C __attribute__((sda));
extern float D_001AE8F0 __attribute__((sda));
extern float D_001AE8E8 __attribute__((sda));
extern s32 D_001AE904[];
extern float D_001AE924[];
extern char D_001A8BD0[];
extern u8 *D_001F0000[];
extern s32 D_001B1688;
extern float D_001AE8EC[];
extern s32 D_001AE914[];
extern s32 D_001AE918[];
extern s32 D_001AE908[];
extern s32 D_001AE90C[];
extern float D_001AE8F8[];

extern s32 func_002A77E0();
extern void func_002C2210(char *, s32, s32, s32, float, float, float, s32, char *, s32);
extern char *func_002C2FD8(char *, s32, s32, s32, s32, s32, s32, float);
extern void func_002A7A00(void *, float, float);
extern void func_00282CC0(void *, void *, char *);
extern float func_002A7878(float, float);
extern s32 func_002A7820(s32, s32);
extern s32 func_00283D38(s32, s32, float);
extern void func_002C3150(void *, void *, s32, s32, float, s32, s32);

/* Spawns the object's trail puff; when not suppressed and flag one of the resident word is set it also emits the tinted streak. */
void func_00302848(char *obj, s32 quiet)
{
    V4_F302848 zero;
    V4_F302848 vec;
    char *rec = *(char **)(obj + 0x68);
    char *puff;
    char *pos;
    s32 tint, color, k;

    zero.q = 0;
    if (func_002A77E0(D_001AE930) == 0) {
        char *first = obj + 0x10;
        if (func_002A77E0(1, D_001AE900) != 0)
            k = -D_001AE928;
        else
            k = D_001AE928;
        func_002C2210(first, D_001AE92C, D_001AE904[0], 2, D_001AE920, D_001AE924[0], 0.0f, k, D_001A8BD0, 0);
    }
    pos = obj + 0x10;
    puff = func_002C2FD8(pos, D_001AE900, *(u8 *)(rec + 0x41), 0, 0, 2, 0, D_001AE8F0);
    if (puff != 0)
        puff[2] = *D_001F0000[0x98E];
    if (quiet == 0 && (D_001B1688 & 1)) {
        func_002A7A00(&vec, 0.0f, 0.05f);
        func_00282CC0(&vec, &vec, pos);
        vec.f[2] = -(func_002A7878(D_001AE8E8, D_001AE8EC[0]) * 0.016666668f);
        tint = func_002A7820(D_001AE914[0], D_001AE918[0]) & 0xFF;
        color = func_00283D38(D_001AE908[0], D_001AE90C[0], func_002A7878(0.0f, 1.0f));
        func_002C3150(&vec, &zero, color, tint, D_001AE8F8[0], func_002A77E0(0xFF) & 0xFF, 0);
    }
}
