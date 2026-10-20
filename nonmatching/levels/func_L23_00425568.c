/* func_L23_00425568 (392 bytes, 1 place: 23:00425568) -- NEAR MISS, not integrated.
   This C compiles to 380 bytes against retail's 392: twelve short, three instructions.
   check.py (23_damosel_orbit, the -G0 unit) reports "380 bytes, expected 392".
   Right: the frame, the two calls to func_L23_004260F0 (matched in src/), the reloads of obj+0x10
   and s0->0x20, the sample loop and the outer loop with its branch.
   What still differs, all allocation and scheduling:
   - the vector locals' addresses sit in other saved registers: retail keeps &loc[3] in $s4,
     &loc[2] in $s5, &loc[1] in $s6, &loc[4] in $s7 and i+1 in $fp; this cc1 gives $s4 to &loc[2],
     $s5 to &loc[1], $fp to &loc[3], $s6 to &loc[4] and $s7 to i+1, and the prologue's save order
     follows the allocation;
   - retail's sample-loop arm for j == 4 stores the loop-carried vector back into loc[3]
     (`sq $a0,0($s4)`). With the reload spelled at the top of the loop this cc1 proves the store
     redundant and drops it (this file); spelled at the join it moves the store into the other arm.
     Neither spelling keeps it where retail has it.
*/

typedef unsigned char u8;

typedef int s32;

typedef int TI16 __attribute__((mode(TI)));

extern void func_00282CF0(float *, float *, float *);

extern float func_00282DF0(float *);

extern TI16 func_L00_0031AA28(float *, float *, float *, float *, float *, float);

void func_L23_004260F0(u8 *obj, float *dst, TI16 *src1, TI16 *src2, float scale);

/* combines the object's vectors twice, then blends five samples into the table at its cursor */
void func_L23_00425568(u8 *obj) {
    TI16 loc[5];
    TI16 va;
    TI16 vb;
    TI16 acc;
    TI16 tmp;
    float *q10;
    float f20;
    float f;
    u8 *s0;
    TI16 *p;
    s32 i;
    s32 j;
    s32 fp;

    i = 0;
    q10 = (float *)(obj + 0x10);
    s0 = *(u8 **)(obj + 0x68);
    do {
        func_00282CF0((float *)&loc[0], *(float **)(s0 + 0x20), (float *)(obj + 0x10));
        fp = i + 1;
        j = 0;
        f = func_00282DF0((float *)&loc[0]);
        p = (TI16 *)(s0 + 0x30);
        f20 = f * *(float *)(s0 + 0x1C);
        vb = *(TI16 *)(obj + 0x10);
        va = **(TI16 **)(s0 + 0x20);
        loc[4] = vb;
        loc[3] = va;
        func_L23_004260F0(obj, (float *)&loc[1], &loc[3], &loc[4], f20);
        vb = *(TI16 *)(obj + 0x10);
        loc[3] = vb;
        va = **(TI16 **)(s0 + 0x20);
        loc[4] = va;
        func_L23_004260F0(obj, (float *)&loc[2], &loc[3], &loc[4], f20);
        do {
            acc = loc[3];
            f = (float)j * 0.2f;
            if (j == 4) {
                tmp = **(TI16 **)(s0 + 0x20);
                loc[3] = acc;
            } else {
                tmp = func_L00_0031AA28((float *)&loc[3], q10, *(float **)(s0 + 0x20), (float *)&loc[1],
                                        (float *)&loc[2], f);
            }
            *p = tmp;
            j++;
            p++;
        } while (j < 5);
        i = fp;
    } while (i <= 0);
}
