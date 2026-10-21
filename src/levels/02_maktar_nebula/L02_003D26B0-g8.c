#include "include_asm.h"

extern float func_00282E80(char *, void *);

extern void func_002830C0(void *, void *, void *);

extern void func_0029FC20(char *, int, void *);

extern void *func_0029FCC0(char *, int, void *);

extern int func_002A77E0(int);

extern void func_L00_00325AE8(void *, int, float, float);

extern void func_00282C88(void *);

extern int D_L02_001B01B0 __attribute__((sda));

extern int D_L02_001B0344 __attribute__((sda));

extern int D_L02_001B0350 __attribute__((sda));

extern int D_L02_001B0360 __attribute__((sda));

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C_1[] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern float D_L02_001B016C __attribute__((sda));
extern float D_L02_001B0170 __attribute__((sda));
extern float D_L02_001B0174 __attribute__((sda));

extern void func_00282CF0(float *, float *, float *);
extern int func_L02_003D7300(u8 *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_002ACEC0(float *, float *, char *, float);
extern void func_00282CC0(float *, float *, u8 *);
extern void func_L01_00321178(char *, float *);

/* Looks through the entities of the object's group for one that passes func_L02_003D7300, lies
   within the first bound and inside the cone of the second.  The first such one is aimed at:
   the offset to it is turned around the object's axis by the third angle (its sign follows the
   side the target is on) and handed to the mover, with the state's float at +0x134 lowered
   for the call.  Answers 1 when one was found, else 0. */
int func_L02_003D26B0(char *self) {
    char *state = *(char **)(self + 0x68);
    float buf[4];
    u16 *p;
    char *e;
    float saved;
    float r;
    char *ax;

#define GROUP (*(int *)(state + 0x2EC))
/* The heading of the target, from the object's position. */
#define ANGLE()                                                                       \
    func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),                    \
                  *(float *)(e + 0x14) - *(float *)(self + 0x14))
    if (GROUP == -1)
        return 0;
    for (p = D_L02_001FC060[GROUP];
         (GROUP & 0xFF) != 0xFF && GROUP <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L02_001FC060[GROUP]);
         p++) {
        e = (char *)D_L02_001B359C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L02_003D7300(e) == 0)
            continue;
        if (!(func_00282E80(self + 0x10, e + 0x10) < D_L02_001B016C))
            continue;
        if (!(func_00283C80(*(float *)(self + 0xF8), ANGLE()) < D_L02_001B0170 * 0.017453294f))
            continue;
        /* A statement that compiles to nothing, as in its twins func_L02_003F1BA8 and
           func_L02_0040BBD8: its loop notes end cse's extended basic block, so the second
           `e + 0x10` is a copy of the first, in a saved register of its own, as retail has it. */
        do {
        } while (0);
        func_00282CF0(buf, (float *)(self + 0x10), (float *)(e + 0x10));
        ax = self + 0xE0;
        r = D_L02_001B0174 * 0.017453294f;
        func_002ACEC0(buf, buf, ax,
                      0.0f <= func_00283BE0(*(float *)(self + 0xF8), ANGLE()) ? -r : r);
        func_00282CC0(buf, buf, e + 0x10);
        saved = *(float *)(state + 0x134);
        *(float *)(state + 0x134) = 0.0001f;
        func_L01_00321178(self, buf);
        *(float *)(state + 0x134) = saved;
        return 1;
    }
#undef ANGLE
#undef GROUP
    return 0;
}

void func_L02_003D69F0(void) {
    D_L02_001B0344 = 0;
    func_00282C88(&D_L02_001B0360);
    func_00282C88(&D_L02_001B0350);
}

int func_L02_003D4D68(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    short timer;
    int delta;

    if (func_00282E80(arg0 + 0x10, &D_L02_001B01B0) > 18.0f) {
        return 0;
    }
    timer = *(short *)(state + 0x32E);
    if (timer < 0x1F4) {
        return 0;
    }
    if (timer < 0x385) {
        delta = 0x384 - *(short *)(state + 0x32A);
        if (delta > 0) {
            if (func_002A77E0(delta) != 0) {
                return 0;
            }
        }
    }
    *(short *)(state + 0x32A) = 0;
    *(short *)(state + 0x32E) = 0;
    return 1;
}
