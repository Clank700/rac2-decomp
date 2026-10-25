/* Nonmatching C: Build the raycast vectors and handle the collision result.
 * Tested profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * Measured US size: 692 bytes; retail: 692 bytes.
 * Placement checks: US and US2: 0/1 each; PAL: absent from the catalogue.
 * Remaining: The first placed instruction difference is at +0x10c; branch layout, vector base lifetimes and floating-point scheduling still differ.
 * Reopen when the retail branch layout and normal/position pointer lifetimes can be expressed naturally without fabricated aliases or dependencies.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float D_L23_001B36A4 __attribute__((nosda));
extern int D_L23_001AFA54 __attribute__((sda));

extern TI128 D_L23_001C0AA0[];
extern char D_00189ED0[];

extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_L22_002F3B38(void *, void *, void *);
extern int func_002761F8(void *, void *, int, int, int);

#define F(i, k) (((float *)&loc[i])[k])

int func_L23_003C1420(char *obj) {
    TI128 loc[8];
    char *state = *(char **)(obj + 0x68);
    int r;
    TI128 *pg;
    TI128 *pl;
    TI128 *ps;
    TI128 *pd;

    loc[1] = 0;
    F(1, 2) = *(float *)(state + 0x54) + *(float *)(state + 0x50);
    loc[2] = 0;
    F(2, 0) = 4.0f;
    loc[0] = loc[1];
    r = func_002A77E0(8);
    F(2, 1) = (float)r * 0.4285714626f + -1.5f;
    F(2, 2) = *(float *)(state + 0x54) + *(float *)(state + 0x50);
    loc[1] = loc[2];
    func_00282D30(&loc[0], obj + 0xE0, F(0, 2));
    func_00282CC0(&loc[0], &loc[0], obj + 0x10);
    func_00283098(&loc[1], &loc[1], obj + 0xC0);
    func_00282CC0(&loc[1], &loc[1], obj + 0x10);
    if (func_002761F8(&loc[0], &loc[1], 0x12, 0, 0) == 0)
        return 0;
    pg = &D_L23_001C0AA0[2];
    pl = &loc[2];
    qcopy(pl, pg);
    loc[5] = 0;
    F(5, 0) = 0.0009765625f;
    F(5, 1) = 0.0009765625f;
    F(5, 2) = 0.0009765625f;
    func_L22_002F3B38(pl, pl, &loc[5]);
    pg -= 2;
    func_00282F20(pl, pl, 1.0f);
    func_00282CF0(&loc[3], &loc[0], pg);
    func_00282D30(&loc[4], pl, func_00282DB0(&loc[3], pl));
    func_00282CF0(&loc[6], &loc[3], &loc[4]);
    func_00282F20(&loc[6], &loc[6], -30.0f);
    ps = (TI128 *)(state + 0x2D0);
    pd = &loc[7];
    func_00282CC0(ps, obj + 0x10, &loc[6]);
    func_00282CF0(pd, ps, D_00189ED0);
    func_00282F20(pd, pd, D_L23_001B36A4);
    func_00282CC0(pd, pd, D_00189ED0);
    qcopy(ps, pd);
    *(short *)(state + 0x26C) = 1;
    r = D_L23_001AFA54;
    *(unsigned short *)(state + 0x26E) = (unsigned short)D_L23_001AFA54 + func_002A7820(-r / 2, r / 2);
    func_00282F20(pl, pl, 10.0f);
    func_00282CC0(pl, pl, pg);
    return 1;
}
