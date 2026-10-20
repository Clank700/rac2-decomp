/* func_L23_0041C6B0 (292 bytes, 1 place: level 23) -- NEAR MISS, not integrated.
   state: 288 bytes against retail's 292. Checked as tools/check.py does, in the -G8 unit
   (the file name *-g8.c gives the flags). Everything up to the inner loop's compare matches,
   except where j = 0 is placed (see below), and the outer loop tail matches.
   What matches: the prologue and saves, the table address in $fp, the state+0x230 pointer in
   $s6 (a local `int *slots` gives retail's registers; folding `state[0x230 + i]` gave others),
   the predicate call, the 16-byte lq/sq copy, the outer loop, and the count reload at the
   inner loop's join.
   What differs: the inner loop's compare branch. Retail is `bc1fl` (annulled when not taken),
   with the count reload `lw $v0,0($s1)` in its delay slot, and `addiu $s2,$s2,1` (j++) stays
   after the join. This cc1 emits a plain `bc1f` and moves j++ into its delay slot, which drops
   the duplicated reload (one instruction, 4 bytes). The `daddu $s2,$zero,$zero` (j = 0) also
   sits before the `lw` where retail has it in the blez delay slot.
   Tried, all 288 bytes: a while loop; a do-while behind a `> 0` guard; j and p advanced in the
   loop header; the other guard polarity (`best > d`); j and p declared in the other order.
   This is the annulled-slot scheduling wall recorded in docs/COMPILER-NOTES.md.
*/

typedef int TI128 __attribute__((mode(TI)));

extern float func_00282E48(char *, char *);

extern int *D_L23_001FF300[];

extern char *D_L23_001B1484 __attribute__((sda));

extern int func_L23_00419CA0(int);

void func_L23_0041C6B0(char *arg0, char *arg1, int arg2) {
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    int *slots = (int *)(state + 0x230);
    float best = 30000.0f;
    int i;

    for (i = 0; i < 0x2F; i++) {
        if (arg2 == 0 || func_L23_00419CA0(i) != 0) {
            int *list = D_L23_001FF300[slots[i]];
            char *p = (char *)list + 0x10;
            int j;

            for (j = 0; j < *list; j++) {
                float d = func_00282E48(p, arg1);
                if (d < best) {
                    best = d;
                    *(TI128 *)arg0 = *(TI128 *)p;
                }
                p += 0x10;
            }
        }
    }
}
