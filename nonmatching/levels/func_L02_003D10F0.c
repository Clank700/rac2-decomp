/* NEAR MISS: 832 bytes, the size of retail's; exactly 2 words differ: two adjacent stores of the init block are
   swapped (retail `sh $zero,0x2F4($s0)` then `swc1 $f20,0x2E8($s0)`; here the float store first). Level 2 only.
   The state-0 step of the actor (marked in place of its marker in L02_002ED7B0.c when it matches): it fills the
   state record (about 25 constants), queues func_L02_003D2390 and then, while the actor is drawn, runs the
   per-frame part (pulse test against D_L02_001BA500, the 0x15/0x10 animation switch, func_L02_003D2488 and
   func_L02_003D1998).
   Findings that matter:
   - the 23 constant stores are an arbitrary permutation of the source order: cc1 hoists every constant load
     (li / li.s) to the top of the block and then issues the stores by its own priority, so the source order was
     found by a simulated-annealing search (move/swap statements, score = differing words, 14 compiles in
     parallel); the order below is its best. Measured: the float store `swc1 $f20,0x2E8` is always issued before
     the zero store `sh $zero,0x2F4` (both have priority 4 and no predecessor in the block), wherever the `sh`
     statement is put in the block and in a small test with the offsets exchanged; retail has the zero first;
   - the second constant of each pair (1.3f at 0x80/0x84, 0.3f at 0x108/0x10C, 2 at 0x69/0x1E8, 3 at 0x28/0x1E9)
     comes out in the reverse of the source order;
   - func_002A9640's result is passed as a SECOND argument to func_L02_003D1880 (`daddu $a1,$v0,$zero` in the
     branch slot), which the matched definition (one parameter) cannot take: it is called through an asm-name
     alias, as other units do;
   - float spellings: 0.017453294f, 1.5707965f and 0.52359885f give retail's bits (the nearest decimals do not).
   Tried for the last swap: the statement moved to every position of the block, `ang` through a ternary, the 1.0f
   later in the function sharing `ang`'s variable (so it is not dead at the store). */
extern int func_00283CF0(float);

extern float func_002A7878(float, float);

extern float func_00282E48(void *, void *);

extern void func_002A93B0(char *);

extern void *func_002A9640(char *, int, int);

extern void func_002B0ED8(char *, char *, int);

extern void func_L02_003D1FA0(char *, int);

extern void func_L02_003D2488(char *, int, int);

extern void func_L02_003D1998(char *);

extern char D_L02_001BA500;

extern int func_L02_003D1880_2(char *, void *) __asm__("func_L02_003D1880");

void func_L02_003D10F0(char *self) {
    char *s = *(char **)(self + 0x68);
    float ang;
    char *p;

    if (*(unsigned char *)(self + 0x20) == 0) {
        *(char **)(s + 0x18) = s + 0x100;
        *(unsigned char *)(s + 0x48) = func_00283CF0(15.0f);
        *(unsigned char *)(s + 0x4A) = func_00283CF0(16.0f);
        ang = func_002A7878(10.0f, 30.0f) * 0.017453294f;
        if (func_002A77E0(2) != 0)
            ang = -ang;
        *(unsigned char *)(s + 0x60) = 0x14;
        *(int *)(s + 0x98) = 7;
        *(float *)(s + 0x80) = 1.3f;
        *(float *)(s + 0x84) = 1.3f;
        *(unsigned char *)(s + 0x69) = 2;
        *(unsigned char *)(s + 0x1E9) = 3;
        *(float *)(s + 0x8C) = 0.4f;
        *(float *)(s + 0x2E8) = ang;
        *(unsigned char *)(s + 0x1E6) = 5;
        *(float *)(s + 0x108) = 0.3f;
        *(unsigned char *)(s + 0x1E8) = 2;
        *(float *)(s + 0x1D4) = 0.5f;
        *(float *)(s + 0x100) = 1.0f;
        *(float *)(s + 0x104) = 0.2f;
        *(float *)(s + 0x10C) = 0.3f;
        *(float *)(s + 0x110) = 1.5707965f;
        *(float *)(s + 0x130) = 0.52359885f;
        *(short *)(s + 0x2F4) = 0;
        *(float *)(s + 0x134) = 0.01f;
        *(float *)(s + 0x12C) = 0.0055555557f;
        *(unsigned char *)(s + 0x28) = 3;
        *(unsigned char *)(s + 0x29) = 1;
        *(float *)(s + 0x30) = 0.75f;
        if (func_002A77E0(2) == 0)
            *(unsigned short *)(self + 0x34) |= 0x8000;
        *(int *)(s + 0x2E4) = 0;
        func_L02_003D2390(self);
    }
    if (*(unsigned char *)(self + 0x31) != 0) {
        if (func_00282E48(self + 0x10, &D_L02_001BA500) < 24.0f) {
            func_002A93B0(self);
            *(unsigned char *)(self + 0x6F) = 0x16;
        }
        if (*(unsigned char *)(self + 0x31) != 0 && *(unsigned char *)(self + 0x20) >= 3) {
            *(float *)(s + 0xFC) = 1.0f;
            p = func_002A9640(self, 0x10000, 1);
            if (p != 0) {
                *(float *)(s + 0xFC) = 1.0f;
                if (func_L02_003D1880_2(self, p) != 0) {
                    *(unsigned char *)(s + 0x60) = 0x13;
                    func_002B0ED8(self, s + 0x50, 1);
                    *(unsigned char *)(s + 0x60) = 0x14;
                    if (*(int *)(s + 0x2E4) != 0 && *(short *)(s + 0x2F4) == 0 &&
                        *(unsigned char *)(self + 0x31) != 0) {
                        func_L02_003D1FA0(*(char **)(s + 0x2E4) + 0x10, 2);
                        *(short *)(s + 0x2F4) = 0x3C;
                    }
                } else {
                    func_002B0ED8(self, s + 0x50, 0);
                }
            } else {
                func_002B0ED8(self, s + 0x50, 0);
            }
            if (*(float *)(s + 0x20) <= 0.0f && *(unsigned char *)(self + 0x20) != 0x15) {
                func_002A7750(self, 0x15, 7);
                if (*(unsigned char *)(self + 0x43) != 0x10)
                    func_002A7470(self, 0x10, 0, 0);
            }
            if (*(unsigned char *)(self + 0x20) >= 2 && *(unsigned char *)(s + 0x2E) == 2)
                func_L02_003D2488(self, 1, 1);
            func_L02_003D1998(self);
        }
    }
}
