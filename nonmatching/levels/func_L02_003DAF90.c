/* func_L02_003DAF90, 156 bytes, 1 placement (level 2).  Closest candidate 152 bytes - ONE
   instruction short: the 16-byte lq/sq copy's destination stays folded on the frame pointer
   here (`lq $v1,0x0($sp); sq $v1,0x10($sp)`) where retail materialises it first
   (`addiu $v1,$sp,0x10; lq $v0,0x0($sp); sq $v0,0x0($v1)`).
   FIVE spellings of that copy were measured and all fold: a TImode cast, a named
   destination pointer, a union carrying a TImode member (that one also costs 8 bytes), an
   explicit +0 through a char base, and a pointer-to-source.  Everything else - the 0x90
   frame, the four scratch blocks at sp+0x00/0x10/0x20/0x60 with the 0x40-byte one in the
   middle, all five calls and their delay slots - is exact.  Same wall as
   func_L02_003DB158 and as the level-0 resident func_L00_00427BE8 (27 placements):
   this cc1 folds a constant destination into the `sq` displacement, retail holds a pointer.
   It needs the -G8 unit of src/levels/02_maktar_nebula/L02_003D26B0.c: the resident block
   base and the two floats are `$gp + 0x1450/0x1448/0x1444`, i.e. 0x001B0440 / 0x001B0438 /
   0x001B0434 with $gp pinned at 0x001AEFF0 (tools/build.py GP; confirmed against the matched
   func_L02_003D69F0, whose `$gp + 0x1354/0x1360/0x1370` are exactly the addresses its C
   names 0x001B0344/0x001B0350/0x001B0360).  Another near-miss of this family,
   func_L18_003F9E50, carries the same recipe.  Body measured in that unit: */

typedef int s32;
typedef float f32;
typedef int TQ __attribute__((mode(TI)));

extern f32 D_L02_001B0434 __attribute__((sda));
extern f32 D_L02_001B0438 __attribute__((sda));
extern s32 D_L02_001B0440 __attribute__((sda));

extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

typedef struct { f32 x, y, z, w; } V4;
typedef struct { f32 v[16]; } M4;

void func_L02_003DAF90(char *a0) {
    char *s2 = *(char **)(*(char **)(a0 + 0xB8) + 0x68);
    V4 src, copy;
    M4 block;
    V4 out;

    func_0029FCC0(a0, 4, &src);
    *(TQ *)&copy = *(TQ *)&src;
    func_0029FC20(a0, 4, &block);
    func_002830C0(&out, &D_L02_001B0440, &block);
    func_00282CC0(&src, &src, &out);
    func_L00_00325AE8(&src, *(s32 *)(s2 + 0x250), D_L02_001B0438, D_L02_001B0434);
}
