/* 0 of 1 places match.  Needs a unit built with `-O2 -G8 -ffunction-sections` (a `-g8` file: the
   $gp reads of D_L02_001B143C..1460 and 1470 are outside delay slots).  This body compiles to
   688 bytes against retail's 696 and a 0xE0 frame against retail's 0xF0: retail saves FIVE
   callee-saved GPRs (s0..s3 and ra) and this saves four, see below.  Beyond that the diff is
   scheduling and register roles from the very first instructions (the prologue, the order of the
   func_0027F640 arguments, the func_002802E0 argument set-up), so this is a structural near miss
   and about 140 of the 174 words differ by tools/check.py's alignment.  Tried: about 45 compiles
   over the spellings listed below.

   What is established (each measured, each moved the diff):
   - the draws: func_0027F640(colour, text, x, y, scale, len, font, style), func_002802E0(ctx, ...
     nine arguments, the ninth on the stack), func_00280270 / func_00280190(ctx, colour, text,
     strlen(text)), func_00115DA8 (the sprintf) and func_00288FB8 (the text lookup); ctx is the
     0x20-byte block at sp+0x10 (declared FIRST: declared after buf2 it sits at sp+0x80), buf2 the
     0x70-byte string buffer at sp+0x30.
   - the text lookups are statements of their own (`text = func_00288FB8(...)` before the call
     that uses them, `msg` too): inside the argument list the address arguments (the format string,
     buf2) are evaluated first and live across the lookup in callee-saved registers.
   - the colour arguments are `long long` in the prototypes (func_0027F640's first, the second of
     func_00280270 / func_00280190): a plain load argument is only loaded at the call, a 64-bit
     one is a pseudo made before the next call, which is retail's `lw $s0,0x244C($gp)` in front
     of func_0027C878 and `lw $s0,0x2458($gp)` in front of the strlen.
   - the order of func_0027F640's int and float parameters sets the order the arguments are
     evaluated in (text call, then the float chains, then the font call): the floats sit between
     the text and the font.
   - FP callee-saved registers f20/f21/f22 come out as retail's (0.5 in f22) with the default
     scheduler; -fno-schedule-insns permutes them.
   - the three `(int)(x * scale + 0.5f)` arguments are written as steps on ONE float variable
     (`t = (float)D; t = t * scale; t = t + 0.5f; r = (int)t;`): any one-expression spelling lets
     sched1 interleave the three chains (loads first, then the multiplies, ...), retail's chains are
     strictly one after the other (the same f0/f1/f2).

   What still differs:
   - retail keeps every global read of the func_002802E0 call in the order the arguments are
     processed: the three chains, then `addiu v0,zero,3`, then the loads of D_L02_001B1468 / 146C /
     the t1 and t3 words, and the stack store in the call's delay slot.  Here the scheduler hoists
     those four loads (and the `sw`) into the chains' latency gaps; no source spelling tried moves
     them back.  (Declaring the data volatile would probably keep them in order; not tried, a
     volatile is not allowed in src/.)
   - retail's prologue: `daddu $s0,$a0,$zero` right after the `sd $s0` and `swc1 $f20` in the first
     call's delay slot; here `daddu $s0,$a0` is the delay slot.
   - retail saves FOUR callee-saved GPRs (s0..s3) and never touches s2: `state` is in $s3 and $s2
     is only saved and restored, which looks like a pseudo that was given $s2 by the allocator and
     then rematerialised (the address of ctx, `addiu $a0,$sp,0x10`, at all five uses).  This body
     saves three, so it is 8 bytes shorter for that alone.  A `char *ctx = buf1` variable gives
     the pointer to $s2 and `state` to $s3, but keeps `addiu $s2,$sp,0x10` and moves the five
     arguments from it (700 bytes).
     A second name for the incoming object (`self = a0`), a second name for `state`, and a second
     load of `*(a0 + 0x68)` for the +0x118 test do not provoke it either (688, 688 and 700 bytes).
   - the text lookup result is moved (`daddu $s1,$v0,$zero`) later than retail by the scheduler,
     and the first block's order of `lw $s0,..($gp)` / the f21 load differs by a few words.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef float f32;

extern void func_L02_003FDDE8(char *, int);
extern char *func_00288FB8(int);
extern long long func_0027C878(int);
extern void func_0027F640(long long, char *, float, float, float, int, long long, char *);
extern void func_002802E0(char *, int, int, int, int, int, int, int, int);
extern int func_L02_003F9B70(int);
extern unsigned int func_001157AC(char *);
extern void func_00280270(char *, long long, char *, int);
extern void func_00280190(char *, long long, char *, int);
extern void func_00115DA8(char *, char *, ...);

extern float D_L02_001B1438 __attribute__((sda));
extern int D_L02_001B143C __attribute__((sda));
extern int D_L02_001B1440 __attribute__((sda));
extern int D_L02_001B1444 __attribute__((sda));
extern int D_L02_001B1448 __attribute__((sda));
extern int D_L02_001B144C __attribute__((sda));
extern int D_L02_001B1450 __attribute__((sda));
extern int D_L02_001B1454 __attribute__((sda));
extern int D_L02_001B1458 __attribute__((sda));
extern int D_L02_001B145C __attribute__((sda));
extern int D_L02_001B1460 __attribute__((sda));
extern int D_L02_001B1464;
extern int D_L02_001B1468;
extern int D_L02_001B146C;
extern int D_L02_001B1470 __attribute__((sda));
extern float D_L02_001B3E04;
extern char D_L02_001B1228[];
extern char D_L02_0028E990[];
extern u8 D_001395B8[0x100];

void func_L02_003FF6E8(char *a0) {
    char buf1[0x20];
    char buf2[0x70];
    char *state;
    char *text;
    char *msg;
    float t;
    int r1;
    int r2;
    int r3;

    func_L02_003FDDE8(a0, 0);
    state = *(char **)(a0 + 0x68);
    text = func_00288FB8(0x2F45);
    func_0027F640(D_L02_001B143C, text, (float)D_L02_001B1440,
                  (float)(int)((float)D_L02_001B1444 * D_L02_001B3E04 + 0.5f), D_L02_001B1438, -1,
                  func_0027C878(1), D_L02_0028E990);
    t = (float)D_L02_001B1460;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r1 = (int)t;
    t = (float)D_L02_001B1464;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r2 = (int)t;
    t = (float)D_L02_001B1450;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r3 = (int)t;
    func_002802E0(buf1, r1, r2, D_L02_001B1468, D_L02_001B146C, D_L02_001B144C, r3,
                  D_L02_001B1470, 3);
    if (*(s16 *)(state + 0x118) == 0 && D_001395B8[func_L02_003F9B70(0)] < 2) {
        text = func_00288FB8(0x2F46);
        func_00280270(buf1, D_L02_001B1448, text, func_001157AC(text));
    } else {
        text = func_00288FB8(0x2F62);
        msg = func_00288FB8(0x2F5E);
        func_00115DA8(buf2, D_L02_001B1228, text, *(int *)(state + 0x110), msg);
        func_00280270(buf1, D_L02_001B1448, buf2, func_001157AC(buf2));
    }
    text = func_00288FB8(0x2F47);
    t = (float)D_L02_001B1460;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r1 = (int)t;
    t = (float)D_L02_001B1464;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r2 = (int)t;
    t = (float)D_L02_001B145C;
    t = t * D_L02_001B3E04;
    t = t + 0.5f;
    r3 = (int)t;
    func_002802E0(buf1, r1, r2, D_L02_001B1468, D_L02_001B146C, D_L02_001B1458, r3,
                  D_L02_001B1470, 3);
    func_00280190(buf1, D_L02_001B1454, text, func_001157AC(text));
}
