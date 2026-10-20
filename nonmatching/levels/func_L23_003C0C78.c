/* func_L23_003C0C78 (380 bytes, level 23 only) -- NEAR MISS, not integrated.
   Belongs in src/levels/23_damosel_orbit/L23_0035CE90.c (no $gp access).
   state: 376 bytes against retail's 380. The frame (0x80), the 16-byte copy through
   `TI16` (lq/sq), the helper calls and the loop shape are the same. What differs is
   register allocation: retail keeps arg0 in $s5, the state in $s6, the count in $s7 and
   i/bucket in $s3/$s2, where this cc1 gives $s6, $s7, $s5 and $s2/$s3. The prologue save
   order differs too, and retail copies the count into $s7 in the delay slot of its `blez`
   (one more instruction). Passing i to func_L23_003C0F48 through its `short` parameter
   makes this cc1 sign-extend it (sll/sra); an unprototyped extern conflicts with the
   file's short definition. Declaration order, a struct for the two vectors, a shared
   output pointer and a late state load were measured; none moved the allocation.
*/

typedef int TI16 __attribute__((mode(TI)));

extern int func_419CA0(int);

extern char D_00189EA0[];

extern int D_L23_001B1684 __attribute__((sda));

extern int *D_L23_001B36A8 __attribute__((sda));

extern int *D_L23_001FF300[];

extern void func_00282CC0(char *, char *, char *);

extern void func_00282CF0(char *, char *, char *);

extern void func_00282F20(char *, char *, float);

extern float func_00282E48(char *, char *);

extern void func_L23_003C0F48(char *, short);

void func_L23_003C0C78(char *arg0, int arg1) {
    char *state;
    struct {
        TI16 in;
        TI16 out;
    } buf;
    char *o = (char *)&buf.out;
    char *e;
    float best;
    int i;
    int count;

    state = *(char **)(arg0 + 0x68);
    buf.in = *(TI16 *)(arg0 + 0x10);
    func_00282CF0(o, (char *)&buf.in, D_00189EA0);
    best = 30000.0f;
    func_00282F20(o, o, 4.0f);
    func_00282CC0((char *)&buf.in, (char *)&buf.in, o);
    count = D_L23_001B1684;
    for (i = 0; i < count; i++) {
        if (arg1 == 0 || func_419CA0(i) != 0) {
            int *s2 = D_L23_001FF300[D_L23_001B36A8[i]];
            int j;

            e = (char *)s2 + 0x10;
            for (j = 0; j < *s2; j++) {
                float f = func_00282E48(e, (char *)&buf.in);

                if (f < best) {
                    best = f;
                    func_L23_003C0F48(arg0, i);
                    *(short *)(state + 0x2B6) = j;
                }
                e += 16;
            }
        }
    }
}
