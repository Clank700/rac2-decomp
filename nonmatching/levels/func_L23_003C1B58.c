/* func_L23_003C1B58 (812 bytes, level 23 only, -G0) -- NEAR MISS, not integrated (21 October 2026).
 *
 * State: built as a unit of its own (src/levels/23_damosel_orbit/L23_003C1B58.c, one config/cflags.txt line
 * `-O2 -G0 -ffunction-sections -frac2-qcopy`), the C below is 812 bytes, retail's size, and `tools/check.py`
 * says 0 of 1 places: 19 of 203 words differ, all of them scheduling, none of them the dispatch.
 *   - 16 words in the prologue (+0x4..+0x40): cc1 schedules `mtc1 $zero,$f12` (the 0.0f of the first call)
 *     right after the `addiu $sp` and `sd $s5` third; retail keeps the `mtc1` after the grouped copy
 *     (`lq $v0,0($s0) ; sq $v0,0($a0) ; mtc1 $zero,$f12 ; jal`) and saves $s5 fifth (s0 s3 s1 s2 s5 ra f20 s4).
 *   - 3 words at the func_L23_0041C6B0 call (+0x264, +0x268, +0x270): retail sets the arguments in the order
 *     a0, a1, then `addiu $a2,$zero,1` in the jal slot; cc1 gives a1, a2 and `daddu $a0,$s0,$zero` in the slot.
 *
 * Cause, measured: with the two 16-byte copies written as `__asm__ volatile ("lq $2,0(%1)\n\tsq $2,0(%0)" : :
 * "r"(dst), "r"(src) : "$2", "memory")` (scratch only, not allowed in src/) the same C is exact, 0 of 203 words
 * differ. The whole residue is therefore the scheduling barrier of retail's grouped copy, which `-frac2-qcopy`
 * lacks (docs/COMPILER-NOTES.md "Grouped vector copies"; issue #248). A `volatile` access in place of the asm
 * does not give it (19 words, and 62 with both copies volatile), and neither does any scheduling flag: with
 * `-fno-schedule-insns` 201 words differ, `-fno-schedule-insns2` 44, `-fno-sched-interblock`, `-fno-sched-spec`
 * and `-mastra-keep-frame-order` change nothing. Loading `state` after the copy or after the first call
 * moved it to 19 and 22 words. Once a barrier variant of the copy exists, re-run check.py on this C in a unit
 * with that profile.
 *
 * The dispatch is retail's own table, decoded: eight words at 0x2AB170 of level 23's data (D_L23_002AB170),
 * {0x3C1BF0, 0x3C1C10, 0x3C1C30, 0x3C1C50, 0x3C1C70, 0x3C1CB0, 0x3C1CE8, 0x3C1D28} = the bodies of cases
 * 0..7 in the order they are written below (a value of 8 or more goes to the tail at 0x3C1D9C). The
 * computed goto (`goto *D_L23_002AB170[sel]`, labels kept alive by an unused `static void *cases[8]`)
 * gives retail's seven dispatch instructions, and the object has no .rodata.
 *
 * Recipes found: cases 4..7 need a block-local `char *b = D_00189E20;` (the base kept in $s0 with
 * `lw $a1,0x2290($s0)`), cases 0..3 the bare global `D_0018C0B0` (`lui $v0,0x19 ; lw $a1,-0x3F50($v0)`);
 * D_L23_001B1644/164C/36AC need `__attribute__((sda))` in this -G0 unit for retail's
 * `lui $v0,0x1B ; lw $v0,0x164C($v0)`. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282D30(void *, void *, float);

extern void func_00282CC0(void *, void *, void *);

extern char D_00189EA0[];

extern char D_00189E20[];

extern char *D_0018C0B0;

extern int D_L23_001B1644 __attribute__((sda));

extern int D_L23_001B164C __attribute__((sda));

extern int D_L23_001B36AC __attribute__((sda));

extern void *D_L23_002AB170[];

extern void func_L23_00418650(char *, float);

extern int func_002A77E0(int);

extern void func_L23_0041C6B0(char *, char *, int);

extern void func_L23_003C00D0(char *);

extern void func_002A7750(char *, int, int);

extern void func_L23_003BFFC0(char *, int, int, int, int, float);

/* Eight ways to place the offset vector v[6] (which of the two vectors at 0xC0 and 0xD0 of the
   target, or the average of two of them), picked by func_002A77E0(8). The dispatch reads the
   level's own jump table (eight code addresses in the level's data at 0x2AB170); `cases` only
   keeps the labels alive. */
void func_L23_003C1B58(char *arg0) {
    static void *cases[8] = {&&c0, &&c1, &&c2, &&c3, &&c4, &&c5, &&c6, &&c7};
    char *state = *(char **)(arg0 + 0x68);
    TI128 v[7];
    unsigned int sel;

    v[1] = *(TI128 *)D_00189EA0;
    func_L23_00418650((char *)&v[1], 0.0f);
    func_00282D30((char *)&v[0], *(char **)(D_00189EA0 + 0x2210) + 0xE0, -80.0f);
    sel = func_002A77E0(8);
    if (sel < 8)
        goto *D_L23_002AB170[sel];
    goto tail;
c0:
    func_00282D30((char *)&v[6], D_0018C0B0 + 0xC0, 50.0f);
    goto tail;
c1:
    func_00282D30((char *)&v[6], D_0018C0B0 + 0xC0, -50.0f);
    goto tail;
c2:
    func_00282D30((char *)&v[6], D_0018C0B0 + 0xD0, 50.0f);
    goto tail;
c3:
    func_00282D30((char *)&v[6], D_0018C0B0 + 0xD0, -50.0f);
    goto tail;
c4: {
    char *b = D_00189E20;

    func_00282D30((char *)&v[4], *(char **)(b + 0x2290) + 0xD0, 50.0f);
    func_00282D30((char *)&v[2], *(char **)(b + 0x2290) + 0xC0, 50.0f);
    func_00282CC0((char *)&v[6], (char *)&v[4], (char *)&v[2]);
    func_00282D30((char *)&v[6], (char *)&v[6], 0.5f);
    goto tail;
}
c5: {
    char *b = D_00189E20;

    func_00282D30((char *)&v[2], *(char **)(b + 0x2290) + 0xC0, 50.0f);
    func_00282D30((char *)&v[5], *(char **)(b + 0x2290) + 0xD0, -50.0f);
    func_00282CC0((char *)&v[6], (char *)&v[2], (char *)&v[5]);
    func_00282D30((char *)&v[6], (char *)&v[6], 0.5f);
    goto tail;
}
c6: {
    char *b = D_00189E20;

    func_00282D30((char *)&v[5], *(char **)(b + 0x2290) + 0xD0, -50.0f);
    func_00282D30((char *)&v[3], *(char **)(b + 0x2290) + 0xC0, -50.0f);
    func_00282CC0((char *)&v[6], (char *)&v[5], (char *)&v[3]);
    func_00282D30((char *)&v[6], (char *)&v[6], 0.5f);
    goto tail;
}
c7: {
    char *b = D_00189E20;

    func_00282D30((char *)&v[3], *(char **)(b + 0x2290) + 0xC0, -50.0f);
    func_00282D30((char *)&v[4], *(char **)(b + 0x2290) + 0xD0, 50.0f);
    func_00282CC0((char *)&v[6], (char *)&v[3], (char *)&v[4]);
    func_00282D30((char *)&v[6], (char *)&v[6], 0.5f);
}
tail:
    func_00282CC0((char *)&v[0], (char *)&v[0], (char *)&v[6]);
    func_00282CC0((char *)&v[0], (char *)&v[0], (char *)&v[1]);
    func_L23_0041C6B0(arg0 + 0x10, (char *)&v[0], 1);
    func_L23_00418650(arg0 + 0x10, 0.0f);
    *(TI128 *)(state + 0x290) = *(TI128 *)(arg0 + 0x10);
    func_L23_003C00D0(arg0);
    func_002A7750(arg0, 5, 0);
    func_L23_003BFFC0(arg0, 3, 0, 0x14, 3, 1.0f);
    D_L23_001B164C = (D_L23_001B164C + 1) % D_L23_001B1644;
    D_L23_001B36AC = D_L23_001B36AC + 1;
}
