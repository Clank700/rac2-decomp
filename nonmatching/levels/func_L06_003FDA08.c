/* func_L06_003FDA08 (1200 bytes, 1 place: level 06_notak) - byte-exact under tools/check.py,
 * NOT PLACEABLE: the switch's jump table.
 *
 * Built as a function of src/levels/06_notak/L06_0033BDC0-g8.c (it takes the $gp addresses of
 * three small-data objects), this body is 1200 bytes, retail's size, and
 * `python3 tools/check.py func_L06_003FDA08 --diff` prints "06_notak: OK" and "1 of 1 places
 * match". It is not a match, because the object's switch (five states, `jr $a0` through a table)
 * puts its table in the object's .rodata and the code loads it through `lui`/`addiu` relocations
 * against that section: tools/build.py drops .rodata and rejects the function with "needs .rodata
 * at its place, which is not C" (docs/COMPILER-NOTES.md, the jump-table wall of func_00118CC8).
 * Placement.derive on this object asks for the `.rodata` section symbol to be 0x2E1DA0, which is
 * exactly where retail's table is, so only the placement step refuses. Retail's table (in the
 * level's data) holds {+0x44, +0x5C, +0x388, +0x498, +0x2C0} for the states 0, 1, 2, 3, 4, so
 * the case bodies come in the order 0, 1, 4, 2 and entry 3 is the end label. An explicit empty
 * `case 3: break;` is what makes cc1 choose a table at all (four case values in a range of five
 * give a compare tree).
 *
 * What the C needed beyond the obvious (each measured):
 *   - separate variables for separate roles: `e` for case 1's walk, `q`/`p4` for case 4's, `t`
 *     for the 0x70-byte table entry (shared names turned the entity into $a0 in one walk);
 *   - `D_L06_001B281C_abs[3] __attribute__((sda))`: a three-word array stays absolute in this -G8
 *     unit and keeps the bare `lui`/`lw` the walks have (the unit's own D_L06_001B281C is the
 *     $gp form for func_L06_00403F60);
 *   - the toggle of case 1 as two separate stores (`w44 = w48` in one arm, `w44 = 5` in the other)
 *     so the constant is scheduled before the `sh`;
 *   - the four stores that close case 1 in the order 0x38, 0x14, 0x58, 0x98 (brute-forced);
 *   - `vec` declared before `buf` (the zeroed quadword at $sp+0x20, buf at $sp+0x30);
 *   - float spellings that encode retail's bits in this assembler: 3.141593f (0x40490FDC),
 *     0.0200000014f (0x3CA3D70B), 0.7853982f, 0.95f, 1.02f, 0.041666668f, 0.083333336f.
 *
 * What would unblock it: a way to reach the level's own jump table from plain C (the
 * `goto *table[sel]` form the yeedil notes describe is not allowed), or a build that places a
 * compiler-generated .rodata at the retail address.
 *
 * Callees (level 6 addresses -> names): 0x3FDEB8 func_L06_003FDEB8 (takes the group byte),
 * 0x36A2A8 func_L00_00329520, 0x35A550 func_002A7750, 0x3FE178 func_L06_003FE178, 0x3A0948
 * func_002E5CF8, 0x32D238 func_00282948, 0x35CBA0 func_002A9640, 0x36AFE0 func_L00_0032A258,
 * 0x439FD8 func_0032C700, 0x32E5D0 func_00283B98, 0x32DE28 func_002833F0, 0x35A620 func_002A77E0,
 * 0x364F80 func_L01_0031A278, 0x32B948 func_L01_002E1680. The three sda objects passed to
 * func_L00_0032A258 are the words at 0x1AFC68, 0x1AFC70 and 0x1AFC80; the count is the $gp word
 * 0x1B2838 and the group table D_L06_001FB3A0.
 */

#include "include_asm.h"

extern void func_002A7750(void *, int, int);
extern int func_002A9640(void *, int, int);
extern void func_L00_0032A258(void *, void *, void *, void *, int, int, int, int,
                               int, int, int);
extern void func_L01_0031A278(char *, float *, float, float, float);
extern int func_002E5CF8(int, int, char *);
extern float func_00283B98(float, float);
extern unsigned char D_00188660[];

extern void func_L06_003FDEB8(int);
extern void func_L06_003FE178(char *);
extern int func_L00_00329520(void *, int);
extern int func_00282948(void *);
extern int func_002A77E0(int);
extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);
extern void func_002833F0(void *, void *);
extern void func_L01_002E1680(float *, float *, int, int, int, float, float, float);

extern int D_L06_001B2838 __attribute__((sda));
extern char *D_L06_001B281C_abs[3] __attribute__((sda));
extern unsigned short *D_L06_001FB3A0[];
extern char D_L06_001B9840[];
extern int D_L06_001AFC80 __attribute__((sda));
extern int D_L06_001AFC70 __attribute__((sda));
extern int D_L06_001AFC68 __attribute__((sda));

typedef int TI128 __attribute__((mode(TI)));

#define GROUP (*(unsigned char *)(s1 + 0x21))
#define FOR_EACH_ID(p) \
    for (p = D_L06_001FB3A0[GROUP]; \
         GROUP != 0xFF && GROUP <= D_L06_001B2838 && p != 0 && \
         ((p != 0 && (short)p[-1] >= 0) || p == D_L06_001FB3A0[GROUP]); \
         p++)

/* An object with five states, state 0 to 4 */
void func_L06_003FDA08(char *a0)
{
    char *s1 = a0;
    char *s2;
    unsigned short *p;
    char *e;
    char *t;
    char *q;
    unsigned short *p4;
    int cls;
    float vec[4];
    float buf[4];

    s2 = *(char **)(s1 + 0x68);
    switch (*(unsigned char *)(s1 + 0x20)) {
    case 0:
        *(unsigned char *)(s1 + 0x30) = 0xFE;
        func_L06_003FDEB8(*(unsigned char *)(s1 + 0x21));
        break;
    case 1:
        if (*(int *)(s2 + 0x64) != -1 && func_L00_00329520(D_L06_001B9840, *(int *)(s2 + 0x64)) != 0) {
            FOR_EACH_ID(p) {
                e = D_L06_001B281C_abs[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                *(unsigned char *)(e + 0x31) = 0;
                *(unsigned short *)(e + 0x34) |= 1;
            }
            func_002A7750(s1, 4, -1);
        }
        func_L06_003FE178(s1);
        t = D_00188660 + *(int *)(s2 + 0x54) * 0x70;
        if (*(int *)(t + 0x88) != (int)s1 || *(unsigned char *)(t + 0x74) == 0)
            *(int *)(s2 + 0x54) = func_002E5CF8(0, 4, s1);
        if (*(unsigned char *)(s1 + 0x31) == 0)
            break;
        if (func_00282948(s2 + 0x44)) {
            if (*(unsigned short *)(s1 + 0x34) & 0x10) {
                *(unsigned short *)(s1 + 0x34) &= 0xFFEF;
                *(int *)(s2 + 0x44) = *(int *)(s2 + 0x48);
            } else {
                *(unsigned short *)(s1 + 0x34) |= 0x10;
                *(int *)(s2 + 0x44) = 5;
            }
        }
        if (func_002A9640(s1, 0x4010000, 0)) {
            cls = *(short *)(s1 + 0xAA) == 0x86B ? 2 : 3;
            func_L00_0032A258(s1, &D_L06_001AFC80, &D_L06_001AFC70, &D_L06_001AFC68, 0xFFFF, 1, cls, 0, 0xFFFF,
                              0xFF, 0);
            *(short *)(s1 + 0x7C) = (1 << cls) - 0x8000;
            func_0032C700(s1 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 1, 1.0f, 20.0f, 1, 0, 0, 0);
            func_002A7750(s1, 2, -1);
            *(int *)(s2 + 0x38) = 0;
            *(int *)(s2 + 0x14) = 0;
            *(int *)(s2 + 0x58) = 0xB4;
            *(int *)(s1 + 0x98) = 0;
        }
        *(unsigned char *)(s1 + 0xA8) = 0xFF;
        *(float *)(s1 + 0xF8) = func_00283B98(*(float *)(s1 + 0xF8), 3.141593f);
        func_002833F0(s1 + 0xC0, s1 + 0xF0);
        break;
    case 4:
        if (func_L00_00329520(D_L06_001B9840, *(int *)(s2 + 0x64)) == 0) {
            FOR_EACH_ID(p4) {
                q = D_L06_001B281C_abs[0] + ((*p4 & 0x7FFF) << 8);
                if (q == 0)
                    break;
                *(unsigned char *)(q + 0x31) = 1;
                *(unsigned short *)(q + 0x34) &= 0xFFFE;
            }
            func_002A7750(s1, 1, -1);
        }
        break;
    case 2:
        *(float *)(s1 + 0xF4) = (*(float *)(s1 + 0xF4) - 0.7853982f) * 0.95f + 0.7853982f;
        func_002833F0(s1 + 0xC0, s1 + 0xF0);
        *(float *)(s1 + 0x18) = *(float *)(s1 + 0x18) - 0.0200000014f;
        if (func_002A77E0(4) == 0 && *(short *)(s1 + 0xAA) == 0x86B) {
            *(TI128 *)vec = 0;
            vec[2] = 0.083333336f;
            func_L01_0031A278(s1, buf, -1.5f, 0.0f, 1.0f);
            func_L01_002E1680(buf, vec, 1, 0x40F0E0D0, 0, 0.041666668f, 2.0f, 1.02f);
        }
        if (func_00282948(s2 + 0x58)) {
            *(unsigned char *)(s1 + 0x31) = 0;
            *(unsigned short *)(s1 + 0x34) |= 1;
            func_002A7750(s1, 3, -1);
        }
        break;
    case 3:
        break;
    }
}
