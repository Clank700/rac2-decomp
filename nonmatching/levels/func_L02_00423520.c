/* func_L02_00423520 (788 bytes, 1 place: level 02) -- NEAR MISS, not integrated.
   state: 784 bytes against retail's 788 (197 instructions) in a -G8 unit of its own
   (L02_00423520-g8.c: it reads $gp data outside a delay slot); check.py: 0 of 1 places.
   Why it stops: the known wall (0). Every instruction matches except retail's 16-byte clear of the
   vector at sp+0, which is `por $v0,$zero,$zero ... sq $v0,0($sp)` (the `por` four instructions
   above the `sq`, after the mtc1 of -0.8f); this cc1 folds it into `sq $zero,0($sp)`, one
   instruction fewer, and the scheduler then orders the vector's `daddu $a0`/`$a1` and the stores
   one slot differently. Measured: `-frac2-zero-ti-barrier` keeps the `sq $zero` (it changes where
   the clear sits, not its form); in a SCRATCH copy only, forcing the zero into a register
   (`TI128 z = 0; __asm__ ("" : "+r" (z)); *(TI128 *)v = z;`) gives 788 bytes with the `por`, one
   slot early. A zero that two stores share keeps its `por`, but retail has one store.
   What the function does: a switch on the byte at +0x20. State 0 reads the two words func_0029F648
   returns, keeps the first as the halfword at +0x7C, sets bit 0x1000 of the halfword at +0x34 and
   asks func_002A7750 for state 1. State 1 waits for func_002A9640 (0x4010000), drops the $gp
   counter D_L02_001AEC78 and asks for state 2. State 2 arms the sub-object (+0x68) with 0x78,
   throws one effect (func_00273730) for each set bit of the 16-bit mask from func_0029F648, then
   builds a vector, calls func_L00_003263D0 and the 20-spark spray func_L02_00423838 (-1/12,
   -0.25) and asks for state 3. Every state ends by storing 0xFF at +0xA8.
   Facts worth keeping:
   - the float table at 0x1B2020..0x1B204C is read through two small `$gp` symbols (0x1B2020 and
     0x1B2040, the latter in a jal delay slot) and absolute `lui $at ; lwc1 off($at)` pairs for the
     other ten words. Declared as two small sda scalars plus, for the offsets, second names
     (`D_L02_001B2020_1[8]`, `D_L02_001B2040_1[4]`, sda, larger than 8 bytes): cc1 counts a
     symbol+offset load as two instructions (so it stays out of delay slots) and gas makes it
     absolute. Measured and refused: offsets of one 8-byte sda symbol (gas makes them `$gp`
     relative too), sda arrays used bare (cc1 puts the macro in a delay slot and gas then splits
     it), plain arrays (cc1 splits them and hoists the `lui`s into callee-saved registers);
   - `float k` for 1/60 must not be a local (it moves the constant into the prologue): the literal
     in each of the three products is hoisted by the loop pass to where retail has it;
   - the stores `sh $zero,0x7C($s0)` then `sw $v0,0($a0)` need that statement order, and the
     sub-object pointer is a local read at the top (retail loads it in the first beq's slot);
   - func_00273730 is declared with its int 0xFF last (retail's `addiu $t3` sits in the call's
     slot) and func_L00_003263D0 with the interleaved int/float order of the matched caller in
     L00_003B9CB8.c. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L02_001AEC78 __attribute__((sda));
extern float D_L02_001B2020 __attribute__((sda));
extern float D_L02_001B2020_1[8] __attribute__((sda));
extern float D_L02_001B2040 __attribute__((sda));
extern float D_L02_001B2040_1[4] __attribute__((sda));

extern void func_0029F648(void *, void *, void *);
extern void func_002A7750(void *, int, int);
extern void *func_002A9640(void *, int, int);
extern void func_L00_00326110(void *, int, float);
extern int func_002E5CF8(int, int, void *);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern char *func_00273730(char *, int, int, int, char *, char *, float *, float, float, int);
extern void func_L00_003263D0(char *, char *, float, int, int, char *, float, int, int, float, float);
extern void func_L02_00423838(u8 *, float, float);

void func_L02_00423520(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    float v[4];
    float w[4];
    int p20, p24, p28, p2c;
    int i;
    float r1, r2;

    switch (a0[0x20]) {
    case 0:
        func_0029F648(a0, &p20, &p24);
        *(u16 *)(a0 + 0x7C) = p20;
        *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | 0x1000;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002A9640(a0, 0x4010000, 0) != 0) {
            D_L02_001AEC78 = D_L02_001AEC78 - 1;
            func_002A7750(a0, 2, -1);
        }
        break;
    case 2:
        *(u16 *)(a0 + 0x7C) = 0;
        *(int *)state = 0x78;
        *(int *)(a0 + 0x98) = 0;
        func_L00_00326110(a0, 1, 1.0f);
        func_0029F648(a0, &p28, &p2c);
        func_002E5CF8(0, 0, a0);
        for (i = 0; i < 16; i++) {
            if ((p28 >> i) & 1) {
                r1 = func_002A7878(D_L02_001B2040, D_L02_001B2040_1[1]);
                r2 = func_002A7878(D_L02_001B2040_1[2], D_L02_001B2040_1[3]);
                v[0] = func_002A7878(D_L02_001B2020, D_L02_001B2020_1[4]) * 0.016666668f;
                v[1] = func_002A78D8(D_L02_001B2020_1[1], D_L02_001B2020_1[5]) * 0.016666668f;
                v[2] = func_002A7878(D_L02_001B2020_1[2], D_L02_001B2020_1[6]) * 0.016666668f;
                func_00283098(v, v, a0 + 0xC0);
                func_00273730((char *)a0, 2, 0xD0D, i, (char *)(a0 + 0x10), (char *)(a0 + 0xF0), v, r2, r1, 0xFF);
            }
        }
        *(TI128 *)v = 0;
        v[0] = -0.8f;
        v[2] = 1.5f;
        func_00283098(v, v, a0 + 0xC0);
        func_00282CC0(v, v, a0 + 0x10);
        func_00282F20(w, a0 + 0xC0, -0.083333336f);
        func_L00_003263D0((char *)a0, (char *)v, 0.25f, 4, 1, (char *)w, 5.0f, 0x50404040, 0, 0.5f, 1.0f);
        func_L02_00423838(a0, -0.083333336f, -0.25f);
        func_002A7750(a0, 3, -1);
        break;
    }
    a0[0xA8] = 0xFF;
}
