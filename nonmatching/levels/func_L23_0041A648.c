/* func_L23_0041A648 (340 bytes, level 23 only, uses $gp: belongs in L23_00416388-g8.c) -- NEAR MISS, not integrated.
   state: 344 bytes against retail's 340 (tools/check.py, src/levels/23_damosel_orbit/L23_00416388-g8.c, -O2 -G8).
   Still different, all register allocation and loop shape:
   - one instruction more: ours computes i + 1 at the top of the first loop and copies i into $v1 for
     the bound test at the bottom; retail keeps the counter in $s2 and computes it once at the bottom;
   - the state pointer is in $s3 (retail: $s4) and the constant 12 of the second loop is in $s4
     (retail: $s3); the rest of the register numbering follows from that;
   - the prologue saves s3 and s4 in the other order.
   Tried, and not better: a running offset next to the index (352 bytes: the induction variables are
   copied through $a0 and $v1 at the loop bottom), the same with a do-while outer loop (352, same copies).
   Right: the three handle loops (8 x 3 slots at 0x259320, 4 slots at 0x1B3790, 8 x 3 slots at 0x259380),
   the release through func_0029F338 under each non-zero test, the func_002E59F8 and func_00291450 calls
   under their -1 guards, the store of -1 to each global (inside its guard), and the cleared word at +0x5B0. */

typedef int s32;

extern void func_0029F338(void *);

extern void func_002E59F8(int);

extern void func_00291450(int);

extern int D_L23_001B1418 __attribute__((sda));

extern short D_L23_001B146C __attribute__((sda));

extern char D_L23_00259320[];

extern char D_L23_00259380[];

extern char D_L23_001B3790[];

/* Releases the three measured handles of the level state, then clears the slots they came from. */
void func_L23_0041A648(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    void **p;
    int i;
    int j;

    if (D_L23_001B1418 != -1) {
        func_002E59F8(D_L23_001B1418);
        D_L23_001B1418 = -1;
    }
    if (D_L23_001B146C != -1) {
        func_00291450(D_L23_001B146C);
        D_L23_001B146C = -1;
    }
    if (*(int *)(state + 0x5B0) != 0) {
        *(int *)(state + 0x5C4) = 0;
        p = (void **)D_L23_00259320;
        for (i = 0; i < 8; i++) {
            for (j = 2; j >= 0; j--) {
                if (*p != 0) {
                    func_0029F338(*p);
                    *p = 0;
                }
                p++;
            }
        }
        p = (void **)D_L23_001B3790;
        for (j = 3; j >= 0; j--) {
            if (*p != 0) {
                func_0029F338(*p);
                *p = 0;
            }
            p++;
        }
        for (i = 0; i < 8; i++) {
            p = (void **)(D_L23_00259380 + i * 12);
            for (j = 2; j >= 0; j--) {
                if (*p != 0) {
                    func_0029F338(*p);
                    *p = 0;
                }
                p++;
            }
        }
        *(int *)(state + 0x5B0) = 0;
    }
}
