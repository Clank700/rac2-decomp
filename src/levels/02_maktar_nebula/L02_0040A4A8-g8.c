#include "include_asm.h"

extern unsigned short *D_L02_001FC060[];
extern unsigned char *D_L02_001B359C[3] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));
extern float D_L02_001B1918 __attribute__((sda));
extern float D_L02_001B191C __attribute__((sda));
extern float D_L02_001B1920 __attribute__((sda));
extern int func_L02_003D7300(char *);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_L01_00321178(char *, void *);

/* Looks through the entities of the object's group for one that passes func_L02_003D7300, lies
   within the first bound and inside the cone of the second.  The first such one is aimed at:
   the offset to it is turned around the object's axis by the third angle (its sign follows the
   side the target is on) and handed to the mover, with the state's float at +0x134 lowered
   for the call.  Answers 1 when one was found, else 0. */
int func_L02_0040BBD8(char *self) {
    char *state = *(char **)(self + 0x68);
    float buf[4];
    unsigned short *p;
    char *e;
    float saved;
    float r;
    char *ax;

#define GROUP (*(int *)(state + 0x2D0))
/* The heading of the target, from the object's position. */
#define ANGLE()                                                                       \
    func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),                    \
                  *(float *)(e + 0x14) - *(float *)(self + 0x14))
    if (GROUP == -1)
        return 0;
    for (p = D_L02_001FC060[GROUP];
         (GROUP & 0xFF) != 0xFF && GROUP <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[GROUP]);
         p++) {
        e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L02_003D7300(e) == 0)
            continue;
        if (!(func_00282E80(self + 0x10, e + 0x10) < D_L02_001B1918))
            continue;
        if (!(func_00283C80(*(float *)(self + 0xF8), ANGLE()) < D_L02_001B191C * 0.017453294f))
            continue;
        /* A statement that compiles to nothing, as in its twins func_L02_003D26B0 and func_L02_003F1BA8: its loop notes end
           cse's extended basic block, so the second `e + 0x10` is a copy of the first, in a
           saved register of its own, as retail has it. */
        do {
        } while (0);
        func_00282CF0(buf, self + 0x10, e + 0x10);
        ax = self + 0xE0;
        r = D_L02_001B1920 * 0.017453294f;
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
