#include "include_asm.h"

extern char D_00189E20_9[];

extern float func_00282C88_1(float *buf);

extern float func_00282DF0(float *buf);

extern void F2c74c194_FUN_00282D30(char *dst, char *src, float scale);

extern void F8411efa9_FUN_00328CA8(char *pkt);

extern long long F8411efa9_FUN_0027C878(char *p);

extern float F8411efa9_FUN_00283248(float x, float y);

extern float F8411efa9_FUN_00282E20(char *p);

extern void F8411efa9_FUN_00283410(float *matrix, float *quat);

extern void F8411efa9_FUN_00282F20(float *off, char *src, float scale);

extern void F8411efa9_FUN_00328D30(char *pkt, float angle);

extern void F8411efa9_FUN_00280B90(char *pkt, float *matrix, int mode);

INCLUDE_ASM("asm/game", func_00322C10);

INCLUDE_ASM("asm/game", func_00322CC0);

INCLUDE_ASM("asm/game", func_003248A8);

INCLUDE_ASM("asm/game", func_003250F8);

INCLUDE_ASM("asm/game", func_00325158);

INCLUDE_ASM("asm/game", func_00325320);

void func_003253A0(char *p)
{
    *(long long *)(p + 112) = 0LL;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long long *)(p + 128) = 0x0000FF9000000260LL;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}

INCLUDE_ASM("asm/game", func_00325430);

INCLUDE_ASM("asm/game", func_00325638);

INCLUDE_ASM("asm/game", func_003258B8);

INCLUDE_ASM("asm/game", func_003258C0);

INCLUDE_ASM("asm/game", func_00325A88);

INCLUDE_ASM("asm/game", func_00325B28);

INCLUDE_ASM("asm/game", func_00325B70);

INCLUDE_ASM("asm/game", func_00325C50);

INCLUDE_ASM("asm/game", func_00325D30);

INCLUDE_ASM("asm/game", func_00325DA0);

INCLUDE_ASM("asm/game", func_00325EC0);

INCLUDE_ASM("asm/game", func_00326198);

INCLUDE_ASM("asm/game", func_00326A10);

INCLUDE_ASM("asm/game", func_00326BD0);

INCLUDE_ASM("asm/game", func_00326BD8);

INCLUDE_ASM("asm/game", func_00326CA8);

/* negates two floats read from a fixed global table, clamps each to [-1,1] into an object reached through the parameter's +104 pointer, packs the pair into a two-float stack buffer, passes it to two callees and stores the second callee's float return value at object+48 */
void func_00326CB8(char *obj)
{
    float buf[2];
    char *d = D_00189E20_9;
    char *e = *(char **)(obj + 104);
    float a, b, x;

    a = -*(float *)(d + 8112);
    *(float *)(e + 20) = a;
    b = -*(float *)(d + 8116);
    *(float *)(e + 16) = b;

    if (a > 1.0f) {
        *(float *)(e + 20) = 1.0f;
    } else if (a < -1.0f) {
        *(float *)(e + 20) = -1.0f;
    }

    x = *(float *)(e + 16);
    if (x > 1.0f) {
        *(float *)(e + 16) = 1.0f;
    } else if (x < -1.0f) {
        *(float *)(e + 16) = -1.0f;
    }
    func_00282C88_1(buf);
    buf[0] = *(float *)(e + 16);
    buf[1] = *(float *)(e + 20);
    *(float *)(e + 48) = func_00282DF0(buf);
}

INCLUDE_ASM("asm/game", func_00326D90);

INCLUDE_ASM("asm/game", func_00326EC0);

INCLUDE_ASM("asm/game", func_00327038);

INCLUDE_ASM("asm/game", func_00327380);

INCLUDE_ASM("asm/game", func_00327848);

INCLUDE_ASM("asm/game", func_00327A60);

INCLUDE_ASM("asm/game", func_00327B40);

INCLUDE_ASM("asm/game", func_00327D08);

INCLUDE_ASM("asm/game", func_00327D50);

INCLUDE_ASM("asm/game", func_003280C8);

INCLUDE_ASM("asm/game", func_003281F0);

INCLUDE_ASM("asm/game", func_003285C0);

INCLUDE_ASM("asm/game", func_003286D0);

INCLUDE_ASM("asm/game", func_00328758);

INCLUDE_ASM("asm/game", func_00328848);

INCLUDE_ASM("asm/game", func_00328918);

INCLUDE_ASM("asm/game", func_00328A20);

INCLUDE_ASM("asm/game", func_00328B68);

void func_00328CA8(char *p)
{
    *(long long *)(p + 112) = 0LL;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -1.0f;
    *(float *)(p + 24) = 1.0f;
    *(float *)(p + 40) = -1.0f;
    *(float *)(p + 56) = 1.0f;
    *(float *)(p + 4) = -1.0f;
    *(float *)(p + 36) = 1.0f;
    *(float *)(p + 52) = 1.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long long *)(p + 128) = 280993940374112LL;
    *(float *)(p + 20) = -1.0f;
    *(float *)(p + 60) = 1.0f;
}

void func_00328D30(char *p, float scale)
{
    F2c74c194_FUN_00282D30(p, p, scale);
    F2c74c194_FUN_00282D30(p + 16, p + 16, scale);
    F2c74c194_FUN_00282D30(p + 32, p + 32, scale);
    F2c74c194_FUN_00282D30(p + 48, p + 48, scale);
}

void func_00328D98(char *pos, int a1, int a2, char *a3, int t0,
                                        char *src, float f12, float f13)
{
    char pkt[144];
    float m[16];
    float quat[4];
    float off[4];
    long long r;

    F8411efa9_FUN_00328CA8(pkt);
    r = F8411efa9_FUN_0027C878(a3);

    *(int *)(pkt + 76) = a1 + (a2 << 24);
    *(int *)(pkt + 72) = a1 + (a2 << 24);
    *(int *)(pkt + 68) = a1 + (a2 << 24);
    *(int *)(pkt + 64) = a1 + (a2 << 24);
    *(long long *)(pkt + 112) = 0LL;
    *(long long *)(pkt + 120) = r;
    *(long long *)(pkt + 128) = 280993940374112LL;
    *(long long *)(pkt + 136) = ((long long)t0 << 2) | 0x8000000040LL;

    quat[3] = 0.0f;
    quat[2] = F8411efa9_FUN_00283248(*(float *)(src + 0), *(float *)(src + 4));
    quat[1] = -F8411efa9_FUN_00283248(F8411efa9_FUN_00282E20(src), *(float *)(src + 8));
    quat[0] = f13;

    F8411efa9_FUN_00283410(m, quat);
    F8411efa9_FUN_00282F20(off, src, 0.025f);

    m[12] = *(float *)(pos + 0) + off[0];
    m[13] = *(float *)(pos + 4) + off[1];
    m[14] = *(float *)(pos + 8) + off[2];
    m[15] = 1.0f;

    F8411efa9_FUN_00328D30(pkt, f12);
    F8411efa9_FUN_00280B90(pkt, m, 0);
}

INCLUDE_ASM("asm/game", func_00328F18);

INCLUDE_ASM("asm/game", func_003290D0);

INCLUDE_ASM("asm/game", func_00329328);

INCLUDE_ASM("asm/game", func_00329488);

INCLUDE_ASM("asm/game", func_00329630);

INCLUDE_ASM("asm/game", func_00329768);

INCLUDE_ASM("asm/game", func_00329CB8);

INCLUDE_ASM("asm/game", func_00329DC0);

INCLUDE_ASM("asm/game", func_00329E60);

INCLUDE_ASM("asm/game", func_00329F40);

INCLUDE_ASM("asm/game", func_0032A130);

INCLUDE_ASM("asm/game", func_0032A140);

INCLUDE_ASM("asm/game", func_0032A978);

INCLUDE_ASM("asm/game", func_0032AA30);
