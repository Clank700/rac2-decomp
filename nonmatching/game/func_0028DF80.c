/* near miss: 428/436 B at -O2 -G0 (also with -fno-gcse). Retail loads the table pointer first (lui/lw a1 before the prologue stores), keeps t->f4 loads at the end of each arm and tests case 1 first with delay-slot loads; this cc1 hoists t->f4 into a2/a3 and gives 428 B. The switch is 0-3 with case 3 re-arming fC through func_002A77E0(30)+10. */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Anim28DF80_Frame {
    u16 f0;
    u16 f2;
    u16 f4;
    u8 pad6;
    u8 f7;
} Anim28DF80_Frame;

typedef struct Anim28DF80_State {
    short f0;
    u8 f2;
    s32 f4;
    char pad8[4];
    s32 fC;
} Anim28DF80_State;

extern Anim28DF80_Frame *D_001B188C;
extern s32 D_001B1688;
extern s32 func_002A77E0(s32);

/* Picks the frame of an animation record: clamp, loop, ping-pong or one-shot. */
s32 func_0028DF80(Anim28DF80_State *a0) {
    s32 r = 0;
    s32 i;
    Anim28DF80_Frame *t = D_001B188C + a0->f0;

    if (t->f0 != 0xFFFF) {
        switch (a0->f2) {
        case 0:
            r = t->f4;
            break;
        case 1:
            r = t->f4 + (D_001B1688 - a0->fC) / t->f7 % t->f2;
            break;
        case 2:
            i = (D_001B1688 - a0->fC) / t->f7 % (t->f2 * 2 - 2);
            if (i >= t->f2)
                i = t->f2 * 2 - (i + 2);
            r = i + t->f4;
            break;
        case 3:
            if (a0->fC < D_001B1688) {
                i = (D_001B1688 - a0->fC) / t->f7;
                if (i < t->f2 * 2 - 2) {
                    if (i >= t->f2)
                        i = t->f2 * 2 - (i + 2);
                    r = i + t->f4;
                } else {
                    r = t->f4;
                    a0->fC = t->f2 * 2 + (func_002A77E0(30) + 10);
                }
            } else {
                r = a0->f4;
            }
            break;
        }
    }
    a0->f4 = r;
    return r;
}
