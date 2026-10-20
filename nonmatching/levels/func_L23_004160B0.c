/* func_L23_004160B0 (724 bytes, level 23 only, uses $gp: belongs in L23_0035CE90-g8.c) -- NEAR MISS, not integrated.
   state: 716 bytes against retail's 724 (tools/check.py, -O2 -G8). Everything is in retail's order and registers
   (conditions, the tail call, the $s0 particle counter, $s4..$s6 and $f20..$f24, the frame, every call and delay slot)
   except two things, 8 words in all:
   - retail has two `nop` between `mtc1 $at,$f3` (the 10.0f of the particle count) and `div.s $f0,$f2,$f0` at +0x148.
     Nothing in this C moves them: the assembler's branch-group/label floors for div.s do not fire here (the block starts
     four slots after the branch). Same wall as the other `nop; nop; div.s` rows (docs/COMPILER-NOTES.md, wave 7).
   - the loop-invariant 0.017453294f ($f24) is emitted three words early, first in the preheader, retail has it after
     the `addiu $s5` of func_00310C88 and before `addiu $s4,$zero,1`. Retail's order means loop.c moved it in its second
     pass, like the `1`; that needs the loop to be at most 58 insns in pass 2 (threshold 61, minus 3 per moved insn; this
     body is 61 and cannot be shrunk without changing the output). The local `k` set at the top of the loop body is the
     only spelling found that hoists it at all (an inline literal stays in the loop and costs the 0x80 frame, 708 bytes).
   Recipes that were needed (each measured): `0.017453294f` is the spelling for 0x3C8EFA36 (0.017453293f gives ...FA35);
   `hit = 0` must follow `if (f()) g();` or the delay slot of the call takes it; `char *base = D_L23_001BA500;` inside the
   loop gives the hoisted `lui/addiu` base and `lwc1 $f13,0x158($s6)`; func_00273730 declared with its int 0xFF argument
   last (floats before it) puts `addiu $t3,$zero,0xFF` in the jal slot; D_L23_001B13CC is read as a variable (0.0f constant
   pool entry), not written as 0.0f.
   Needs for L23_0035CE90-g8.c: the sda externs below (D_L23_001B13CC and D_L23_001B1484 are new; D_L23_001B13C8 exists). */
extern float D_L23_001B13C8 __attribute__((sda));

extern float D_L23_001B13CC __attribute__((sda));

extern char *D_L23_001B1484 __attribute__((sda));

extern char D_L23_001BA500[];

extern char *func_002A9640(char *, int, int);

extern void func_00282978(char *);

extern int func_L23_0041B948(void);

extern void func_L23_0041E570(void);

extern void func_002AB800(char *, char *);

extern void func_002AB8C0(char *, char *);

extern void func_L23_0041C578(char *);

extern void func_L23_0041BE70(char *);

extern float func_002A78D8(float, float);

extern float func_00283B98(float, float);

extern float func_002A7878(float, float);

extern float func_00283180(float);

extern float func_00283198(float);

extern char *func_00273730(char *, int, int, int, char *, char *, float *, float, float, int);

extern void func_00310C88(void);

void func_L23_004160B0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    char *hit;
    int n;
    int i;
    float k;
    float vec[3];

    hit = func_002A9640(arg0, 0x30000, 1);
    *(unsigned char *)(arg0 + 0xA8) = 0xFF;
    func_00282978(state + 0x26);
    if (hit != 0) {
        if (*(short *)(state + 0x26) != 0 || (D_L23_001B1484 != 0 && func_L23_0041B948() != 0)) {
            if (func_L23_0041B948() != 0)
                func_L23_0041E570();
            hit = 0;
        }
    }
    if (hit != 0) {
        *(unsigned char *)(state + 0x147) = 0xFF;
        func_002AB800(arg0, state + 0x140);
        func_L23_0041C578(*(char **)(hit + 0x20));
        if (*(float *)(state + 0x20) <= D_L23_001B13CC) {
            func_L23_0041BE70(hit);
            *(float *)(state + 0x20) = D_L23_001B13CC;
        } else {
            *(float *)(state + 0x20) = *(float *)(state + 0x20) - *(float *)(hit + 0x2C);
        }
        if (*(float *)(state + 0x20) <= D_L23_001B13CC)
            *(float *)(state + 0x20) = D_L23_001B13CC;
        if (*(short *)(*(char **)(hit + 0x20) + 0xAA) != 0x118F)
            *(short *)(state + 0x26) = 0x14;
        if (*(unsigned short *)(arg0 + 0x7C) != 0) {
            n = 10 - (int)(*(float *)(state + 0x20) / D_L23_001B13C8 * 10.0f);
            if (*(float *)(state + 0x20) <= D_L23_001B13CC)
                n = 10;
            for (i = 0; i < n; i++) {
                int mask = *(unsigned short *)(arg0 + 0x7C);

                k = 0.017453294f;

                if ((mask >> i) & 1) {
                    float angle, speed;
                    char *p;
                    char *base = D_L23_001BA500;

                    *(unsigned short *)(arg0 + 0x7C) = mask & ~(1 << i);
                    angle = func_00283B98(func_002A78D8(90.0f, 120.0f) * k,
                                          *(float *)(base + 0x158));
                    speed = func_002A7878(2.0f, 4.0f) * 0.016666668f;
                    vec[0] = func_00283180(angle) * speed;
                    vec[1] = func_00283198(angle) * speed;
                    vec[2] = 0.0f;
                    vec[2] = func_002A7878(5.0f, 8.0f) * 0.016666668f;
                    p = func_00273730(arg0, 1, *(short *)(arg0 + 0xAA), i, arg0 + 0x10, arg0 + 0xF0,
                                      vec, 90.0f, 15.0f, 0xFF);
                    if (p != 0)
                        *(void (**)(void))(p + 0x64) = func_00310C88;
                }
            }
        }
    }
    func_002AB8C0(arg0, state + 0x140);
}
