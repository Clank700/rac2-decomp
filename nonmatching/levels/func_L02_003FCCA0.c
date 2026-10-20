/* Near miss (level 2, one place): 340 bytes against retail's 344 (the switch form of the same
 * body is 336). It needs a -g8 unit: the two counters below are plain extern ints, which the
 * assembler turns into the absolute lui/lw pair outside a delay slot and into a $gp access
 * inside one, as retail has them.
 *
 * Right in this draft: the hero save/restore path (the word at +0x22C8 read before the call
 * and put back after func_00288308/func_002AD860), the counter D_001A79F8 (absolute load,
 * `sw ...,-0x75F8($gp)` in the delay slot of func_L00_0030C7F8), the loads of D_001A7A0C and
 * of the hero fields, the shared tail and the epilogue.
 *
 * What differs:
 *  1. The message selection. Retail has the dispatch first with positive branches
 *     (`beq $s2,6`, `beql $s2,0xB`, `b default; nop`), then the bodies of 6, 0xB and the
 *     default. As a `switch` this cc1 puts the default body right after the dispatch: -O2 runs
 *     cygnus_merge_blocks (gcc/flow.c) after the first jump pass, and it moves a block that is
 *     the only successor of its predecessor and has no other predecessor up behind it, so the
 *     `b default` disappears and the layout becomes dispatch, default, 6, 0xB. A `default` kept
 *     in place needs a second predecessor; a second case value aliasing it (`case 0: default:`)
 *     adds `slti`/`bne` to the dispatch that retail does not have. The if/else-if chain below
 *     keeps the body order but uses negative branches (`bne $s2,6`).
 *  2. Retail has `lui $s4,0x14` in the entry block and forms the table address with
 *     `addiu $s0,$s4,-0x6A48` in the delay slot of the first call (before the call), and again
 *     `addiu $v1,$s4,-0x6A48` after the last call. Here gcse inserts a copy of the `lui` in the
 *     first block and a fresh one on the other edge (`daddu $s4,$s0,$zero`), and the first
 *     address is formed after the call; the prologue then saves $s0 before $s4.
 *  3. D_001A7A0C's store: retail keeps `lui $at ; sw $v1,0x7A0C($at)` before the call to
 *     func_L02_003FCDF8 and puts the argument move `daddu $a0,$s2,$zero` in the call's delay
 *     slot; here the scheduler places the argument move earlier (it fills the load-use gap),
 *     so the store becomes the delay-slot filler and assembles as a $gp access.
 *
 * Tried: the switch with the default last (336 bytes), with `case 0` falling into the default
 * (368), the nested `if (a1 == 0) { if (...) }` with a goto to the tail, the table as a local
 * pointer at the top (320: it is kept in $s3), and the two-names form of the counters
 * (D_001A79F8 declared again with an asm label: both names get the larger `.extern` and come
 * out absolute).
 */

extern unsigned char D_001395B8[0x100];

extern char D_00189E20[];

extern int D_001A7A0C;

extern int D_001A79F8;

extern int func_L02_003F9B70(int);

extern int func_L02_00400650(char *, int);

extern void func_00288308(int);

extern void func_002AD860(int);

extern int func_002A77E0(int);

extern int func_L02_003FCF08(int);

extern int func_L02_003FCDF8(int);

extern void func_L00_0030C7F8(int);

extern void func_0029B3E0(int, int);

void func_L02_003FCCA0(char *a0, int a1) {
    char *state = *(char **)(a0 + 0x68);
    int saved;
    char *hero;
    int v;

    if (a1 == 0 && D_001395B8[func_L02_003F9B70(0)] == 0) {
        hero = D_00189E20;
        saved = *(int *)(hero + 0x22C8);
        func_L02_00400650(a0, 7);
        func_00288308(0x26);
        func_002AD860(0x26);
        *(int *)(hero + 0x22C8) = saved;
    } else {
        if (a1 == 6) {
            func_L02_00400650(a0, 8);
        } else if (a1 == 0xB) {
            func_L02_00400650(a0, 9);
        } else {
            func_L02_00400650(a0, func_002A77E0(5) + 2);
        }
        D_001A7A0C = D_001A7A0C + func_L02_003FCF08(a1);
        v = func_L02_003FCDF8(a1);
        *(int *)(state + 0x110) = v;
        D_001A79F8 = D_001A79F8 + v;
        func_L00_0030C7F8(0x168);
    }
    D_001395B8[func_L02_003F9B70(a1)]++;
    func_0029B3E0(0, -1);
}
