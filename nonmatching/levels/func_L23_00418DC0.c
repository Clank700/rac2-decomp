/* func_L23_00418DC0 (360 bytes, level 23 only) -- NEAR MISS, not integrated.
   state: 356 bytes against retail's 360 (tools/check.py, src/levels/23_damosel_orbit/L23_00416388.c, -O2 -G0).
   Still different, all register allocation and instruction order:
   - the table entry and the loop counter trade registers: ours keeps obj in $s1 and k in $s2,
     retail keeps obj in $s2 and k in $s1 (declaration order and statement order did not change it);
   - retail's `nop` after `addiu $s0,$s2,0x10` (the entry pointer) is absent in ours, so the rest
     of the body is one instruction early (356 against 360 bytes);
   - the prologue saves and the state load (`lw $s6,0x68($s5)`) come in a different order: ours
     loads the state after the copy of arg0+0x10, retail before it;
   - the constant 30000.0f is loaded before the first vector call in ours, between the first and the
     second call in retail.
   Right: the 0x80 frame, the TI128 copy at sp+0 and the float[4] at sp+0x10, the three vector calls,
   the predicate loop, the best-distance branch, and the store of k as s16 into state+0x396.
   func_L23_00419088 is called unprototyped: a prototype with an s16 parameter makes the caller narrow
   the index with sll/sra, which retail does not do. */

typedef int s32;
typedef short s16;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CF0(float *, const float *, const float *);

extern void func_00282F20(char *, char *, float);

extern void func_00282CC0(char *, char *, char *);

extern float func_00282E48(char *, char *);

extern char D_00189EA0[];

extern int *D_L23_001FF300[];

extern s32 func_L23_00419CA0(s32 arg0);

/* Picks the nearest entry of the object each measured slot names, and stores the index found. */
void func_L23_00418DC0(char *arg0, s32 arg1) {
    extern void func_L23_00419088();
    struct {
        TI128 a;
        float b[4];
    } loc;
    char *src = arg0 + 0x10;
    char *state;
    s32 *tbl;
    float best;
    float d;
    s32 k;
    char *obj;
    char *entry;
    s32 i;

    loc.a = *(TI128 *)src;
    state = *(char **)(arg0 + 0x68);
    tbl = (s32 *)(state + 0x230);
    func_00282CF0(loc.b, (float *)src, (float *)D_00189EA0);
    best = 30000.0f;
    func_00282F20((char *)loc.b, (char *)loc.b, 4.0f);
    func_00282CC0((char *)&loc.a, (char *)&loc.a, (char *)loc.b);
    for (i = 0; i < 0x2F; i++) {
        if (arg1 != 0 && func_L23_00419CA0(i) == 0)
            continue;
        k = 0;
        obj = (char *)D_L23_001FF300[tbl[i]];
        if (*(s32 *)obj > 0) {
            entry = obj + 0x10;
            do {
                d = func_00282E48(entry, (char *)&loc.a);
                if (d < best) {
                    best = d;
                    func_L23_00419088(arg0, i);
                    *(s16 *)(state + 0x396) = k;
                }
                entry += 0x10;
                k++;
            } while (k < *(s32 *)obj);
        }
    }
}
