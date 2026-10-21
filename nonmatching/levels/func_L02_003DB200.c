/* func_L02_003DB200, 236 bytes, 1 placement (level 2, 02_maktar_nebula). NEAR MISS: 232 bytes against retail's 236,
   about 7 words in other places. Compiled as a unit of its own, default flags plus -G8 (`-O2 -G8
   -ffunction-sections`: the five float words and the object address are `$gp` accesses outside a delay slot, so a
   `-g8.c` unit; D_L02_001B359C is the one absolute load, `lui $v1,0x1B ; lw $v1,0x359C($v1)`, so it is declared
   an incomplete array and read as [0]).

   Everything from the first call's delay slot on is exact. The head differs in one thing, the `por`: retail clears
   the first vector with `por $v0,$zero,$zero ... sq $v0,0($sp)` (the zero is hoisted to slot 1; $v0:$v1 hold it
   until the store) and this cc1 turns that pair into `sq $zero,0($sp)` (rac2_fold_zero_ti_store: the store has a
   bare-register address, the zero was materialised next to it, and its register pair is rewritten before
   anything references it). Losing the `por` frees slot 1, so the cc1 hoists the global's `lui` there instead of
   keeping the pair `lui $v1 ; lw $v1,0x359C($v1)` after the store, ahead of the state load:
       retail: por; sd s0; addiu a1,4; sd s1; sd ra; addiu s1,sp,0x10; sq $v0; daddu a2,s1; lui v1; lw v1; lw v0; ...
       mine:   lui v0; sd s0; addiu a1,4; sd s1; sd ra; addiu s1,sp,0x10; sq $zero; daddu a2,s1; lw a3,0(v0); lw v1; ...
   The rest of the head is already retail's schedule, and it is the by-default one: -frac2-zero-ti-barrier puts the
   state load first and is further off (13 words). Retail's `lui $v1 ; lw $v1,%lo($v1)` is the base == dest absolute
   load that `-mno-split-addresses` gives; with that flag (alone, in a unit of its own) the allocation is retail's
   ($v1 the global, $v0 the state pointer, $a0 the index), the order differs only by the missing `por` and by the
   global's pair sitting at the top of the function (10 words, 232 bytes). So the unit would be `-g8.c` with
   -mno-split-addresses once the `por` survives.
   The `por` is the open point. The fold skips a store whose address is not a bare register, or whose zero register
   is referenced (not just written) before $v0 is rewritten; retail's stream has neither, so only a compiler-side
   change (or a source shape this cc1 gives that retail's compiler gave by default) keeps it. Measured: `TI128 a = 0;`
   as the first local (address taken) puts the slot at sp+16, where the `por` survives (`por ; sq $2,16($sp)`), but
   retail's slot is 0($sp); with the three vectors as TI128 locals aliased by float pointers the slot is 0($sp) and
   the pair folds (232 bytes). `*(TI128 *)p = 0`, a named TI128 zero stored once or twice, a TI128 local, an aligned
   struct or array initialiser give `sq $zero`, a `por` at a displacement, or a call to memset.
   -fno-schedule-insns (13 words) and -fno-schedule-insns2 (18) are worse than the default (7). */

typedef int TI128 __attribute__((mode(TI)));

extern float D_L02_001B04B0 __attribute__((sda));
extern float D_L02_001B04C8 __attribute__((sda));
extern float D_L02_001B04CC __attribute__((sda));
extern float D_L02_001B04D0 __attribute__((sda));
extern float D_L02_001B04D4 __attribute__((sda));
extern float D_L02_001B04D8 __attribute__((sda));
extern int D_L02_001B359C[];
extern float D_L02_001BA500[4];

extern void *func_0029FCC0(char *, int, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002ACB48(void *, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_L02_003449D8(void *, void *, void *, int, int);

void func_L02_003DB200(char *arg0) {
    float a[4];
    float b[4];
    float c[4];

    *(TI128 *)a = 0;
    func_0029FCC0((char *)(D_L02_001B359C[0] + (*(int *)(*(char **)(arg0 + 0x68) + 0x244) << 8)), 4, b);
    b[2] = b[2] + D_L02_001B04D4;
    func_00282CF0(c, D_L02_001BA500, b);
    c[2] = 0.0f;
    func_00282F20(c, c, D_L02_001B04D8);
    func_00282CC0(b, b, c);
    func_002ACB48(b, D_L02_001B04C8);
    a[2] = func_002A7878(D_L02_001B04CC, D_L02_001B04D0) * 0.016666668f;
    func_L02_003449D8(b, a, &D_L02_001B04B0, func_002A77E0(2), 1);
}
