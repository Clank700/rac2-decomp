/* func_L08_0042F938 (392 bytes, 1 place) - NEAR MISS, 2 instructions (M22, 2026-10-26).
 *
 * Measured as its own unit src/levels/08_tabora/L08_0042F938-g8.c with
 * "-O2 -G8 -ffunction-sections -frac2-zero-ti-por" (the por qzero of the vector).
 * Ported from func_L06_00402440 / func_L20_00449178.  Every word matches except
 * the two constants of func_L00_0032A258's stack arguments: retail puts 0xFFFF in
 * $v1 and 0xFF in $v0, this C gives the siblings' $v0/$v1.  Not moved by 255,
 * a char parameter, u16/u8 parameters or the add's operand order.  Queued on the
 * permuter.
 */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(void *, int, int);
extern int func_002A9640(void *, int, int);
extern void func_00282CC0(void *, void *, void *);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern void func_L00_0032A258(void *, void *, void *, void *, int, int, int, int,
                              int, int, int);
extern void func_L00_00326110(void *, int, float);
extern void func_L00_00326620(void *, int, int);
extern void func_0029F338(void *);

extern float D_L08_001B1EE0 __attribute__((sda));
extern float D_L08_001B1EE8 __attribute__((sda));
extern float D_L08_001B1EF0 __attribute__((sda));

/* a moby's three states: idle, waiting for its model, and burst */
void func_L08_0042F938(char *obj)
{
    char *vars = *(char **)(obj + 0x68);
    float vec[4] __attribute__((aligned(16)));

    switch (*(unsigned char *)(obj + 0x20)) {
    case 0:
        func_002A7750(obj, 1, -1);
        break;
    case 1:
        if (func_002A9640(obj, 0x4010000, 0) != 0) {
            if (*(int *)vars == 0)
                func_002A7750(obj, 2, -1);
        }
        *(unsigned char *)(obj + 0xA8) = 0xFF;
        break;
    case 2:
        *(TI128 *)vec = 0;
        vec[2] = 7.0f;
        func_00282CC0(vec, obj + 0x10, vec);
        func_0032C700(vec, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.75f, 20.0f, 1, 1, 0, 0);
        func_L00_0032A258(obj, &D_L08_001B1EF0, &D_L08_001B1EE8, &D_L08_001B1EE0,
                          0xFFFF, 0, -1, 7, 0xFFFF, 0xFF, 0);
        func_L00_00326110(obj, 5, 4.0f);
        func_L00_00326620(obj, 0x12A0, 0);
        func_0029F338(obj);
        break;
    }
}
