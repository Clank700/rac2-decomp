/* 0 of 1 places match - candidate is 540 bytes, retail 548. File:
   src/levels/02_maktar_nebula/L02_002ED7B0-g8.c (-O2 -G8 -ffunction-sections), placed
   between func_L02_00300738 and func_L02_003D02F0 (the marker sat before
   func_L02_003CB090). Checked at commit base 406e81e with the cc1 that carries the
   #238 flow fix; the score did not move with it.
   Everything up to the walk matches (path record, the func_00282D08 / func_00282E48 /
   func_002A7940 / func_00283180 / func_00283198 / func_00282CC0 / func_L02_0032EF10
   sequence, the +0x3C4 test) and the walk has retail's layout: `b TEST; BODY; INCR; TEST`
   with the two-sided `p != 0 && p[-1] >= 0 || p == table[g]` exit test and the $gp bound
   (the `for(;;)` + `goto test` + `continue` spelling below; the plain `for` with the
   guarded condition is also 540 bytes). What is left is the 16-byte copy
   `state+0x3A0 = self+0x10` and the registers it drags along:
     retail  lq $v0,0($s2) ; sq $v0,0($s4), with $s2 = self+0x10 and $s4 = state+0x3A0
             computed once at the top of each walk iteration and HELD (they are also the
             a1/a2 arguments of func_L01_00311C18: `daddu $a2,$s4,$zero`); that costs a
             second saved pair ($s7 = self, $s5 = state, $s4 = held pointer): frame 0x80
     ours    lq $v0,0x10($s5) ; sq $v0,0x3A0($s4) with the offsets folded into the quad
             ops, and the call argument rebuilt as `addiu $a2,$s4,0x3A0`: no held
             pointer, one saved register fewer, frame 0x70, $s5 = self, $s4 = state
   i.e. 8 bytes, and every register name after the prologue follows from them.
   Measured: writing the copy through `char *dst = state + 0x3A0; char *src = self + 0x10;`
   locals declared inside the walk gives the same 540 bytes (cse/combine still fold the
   plus form into the quad MEMs and into the argument setup); the same locals declared
   once at the top of the function give 536 bytes and a different shape; an aggregate
   copy comes out as ld/sd pairs or memcpy (docs/COMPILER-NOTES.md), not lq/sq:
   `typedef int TI128 __attribute__((mode(TI)))` is what reaches lq/sq at all.
   Next idea: find a spelling in which the two quad operands stay (reg) addresses at
   cse time (retail's pointers are used by a call AND by the quad copy, so their pseudos
   have two uses each; combine substitutes a 2-use pseudo into one of its uses, so look
   at which use survives) -- not an inline-asm copy; the fix has to be in the C. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int TI128 __attribute__((mode(TI)));
typedef struct {
    float x, y, z, w;
} Vec4;

extern Vec4 *D_L02_001FF1C0[];
extern u16 *D_L02_001FC060[];
extern u8 *D_L02_001B359C_1[] __attribute__((sda));
extern int D_L02_001B35B8 __attribute__((sda));

extern void func_00282D08(Vec4 *, Vec4 *, Vec4 *, float);
extern float func_00282E48(Vec4 *, Vec4 *);
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(char *, char *, Vec4 *);
extern void func_L02_0032EF10(Vec4 *, char *, char *, int, float);
extern void func_L01_00311C18(Vec4 *, char *, char *, u8 *);
extern float func_00282E80(void *, u8 *);

void func_L02_003CAE68(char *self) {
    char *state = *(char **)(self + 0x68);
    char *rec;
    Vec4 *path;
    Vec4 v, tmp;
    u16 *p;
    u8 *e;
    float len, ang;
    int g;

    rec = state + (*(int *)(state + 0x3C4) << 5);
    path = D_L02_001FF1C0[*(int *)(rec + 0x290)];
    func_00282D08(&v, path + 1, path + 1 + (*(int *)path >> 1), 0.5f);
    len = func_00282E48(&v, path + 1);
    ang = func_002A7940();
    *(float *)(state + 0x3A0) = func_00283180(ang) * len;
    *(float *)(state + 0x3A4) = func_00283198(ang) * len;
    *(int *)(state + 0x3A8) = 0;
    func_00282CC0(state + 0x3A0, state + 0x3A0, &v);
    func_L02_0032EF10(&v, state + 0x3A0, state + 0x3A0, *(int *)(rec + 0x290), 2.0f);
    if (*(int *)(state + 0x3C4) != 0)
        return;
    g = *(int *)(state + 0x39C);
    p = D_L02_001FC060[g];
    goto test;
    for (;;) {
        e = D_L02_001B359C_1[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return;
        func_L01_00311C18(&tmp, self + 0x10, state + 0x3A0, e + 0x10);
        if (func_00282E80(&tmp, e + 0x10) < 3.0f && func_00282E80(self + 0x10, e + 0x10) > 3.0f)
            *(TI128 *)(state + 0x3A0) = *(TI128 *)(self + 0x10);
        g = *(int *)(state + 0x39C);
        p++;
test:
        if ((u8)g != 0xFF && g <= D_L02_001B35B8 && p != 0) {
            if ((s16)p[-1] >= 0)
                continue;
            if (p == D_L02_001FC060[g])
                continue;
        }
        break;
    }
}
