/* func_L23_003C00D0 (292 bytes, level 23 only) -- NEAR MISS, not integrated.
   Belongs in src/levels/23_damosel_orbit/L23_0035CE90.c (no $gp access).
   state: 276 bytes against retail's 292. Aligned word by word, the body is the same
   sequence up to the first division, and after it, except for four nops: retail has two
   nops between each load and the following div.s (`lhu $v0,0x36F0($v0)`, two nops,
   `div.s $f1,$f1,$f0`; `lw $a0,0x3B4($s0)`, two nops, `div.s $f2,$f2,$f0`). This toolchain
   emits the divisions straight after the loads. The division padding
   (tools/compiler/transformers/pad_div_erratum_nops.py) is keyed to a code label within two
   slots before the division, and no branch target that would make such a label is visible
   in the retail bytes around these divisions. No source shape measured here moves it.
*/

extern int D_L23_001B36F0 __attribute__((sda));

void func_L23_003C00D0(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    int none = -1;

    *(short *)(state + 0x178) = 0;
    *(unsigned short *)(arg0 + 0x34) = (*(unsigned short *)(arg0 + 0x34) & 0xFFBE) | 0x1000;
    *(int *)(arg0 + 0x98) = *(int *)(*(char **)(arg0 + 0x24) + 0x10);
    *(unsigned short *)(*(char **)(state + 0x2A0) + 0x34) &= 0xFFBE;
    *(unsigned short *)(*(char **)(state + 0x2A0) + 0x34) |= 0x1000;
    *(int *)(*(char **)(state + 0x2A0) + 0x98) = *(int *)(*(char **)(*(char **)(state + 0x2A0) + 0x24) + 0x10);
    *(short *)(state + 0x2B0) = 0;
    *(int *)(state + 0x25C) = 0;
    *(short *)(state + 0x26) = 2;
    *(float *)(state + 0x20) = (float)*(short *)(state + 0x24);
    func_L23_003BFFC0(arg0, 1, 0, 0, 3, 1.0f);
    {
        unsigned short d = D_L23_001B36F0;
        float f = (float)D_L23_001B36F0;

        *(short *)(state + 0x24) = d;
        *(float *)(state + 0x20) = f;
        *(short *)(state + 0x2A4) = 0;
        *(float *)(state + 0x19C) = 150.0f / f;
        *(float *)(state + 0x198) = 40.0f / f;
    }
    if (*(int *)(state + 0x3B4) != none) {
        func_367150(*(int *)(state + 0x3B4));
        *(int *)(state + 0x3B4) = none;
    }
}
