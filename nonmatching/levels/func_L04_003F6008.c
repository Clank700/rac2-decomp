/*
 * Near miss, wave 10 worker 06 (2026-10-25).
 * Profile: -O2 -G0 -ffunction-sections (04_barlow / 11_joba shared unit).
 * Retail: 504 bytes, 2 places (04_barlow at 0x003f6008, 11_joba at 0x003e1028).
 * Best measured C: 488 bytes, 0 of 2 places.
 *   wslcmp: func_L04_003F6008: 0 of 2 places match [04_barlow: 488 bytes, expected 504]
 * This is the +4 sibling of func_L04_003F9078: state arrays at +0x14/+0x24/
 * +0x34/+0x44 instead of +0x10/+0x20/+0x30/+0x40.  The rotations, the four
 * particle emissions, the colour wrap and the 0xFF- arithmetic match.
 * Remaining difference: retail keeps the q pointer (sp+0x10) in $s7, hence a
 * 0x90 frame with eight saved GPRs; this cc1 rematerialises sp+0x10 and saves
 * seven, 16 bytes short.  The data pointer and the callees differ per place
 * (11_joba uses func_300xxx), so both need ref_L04_003F6008_* symbols.
 */
typedef int V4_003F6008 __attribute__((mode(TI)));
extern unsigned char ref_L04_003F6008_00[];
extern void func_30EDC8(float *, void *, float *);
extern void func_30F090(float *, float *, float);
extern void func_30ED98(float *, float *, float *);
extern int func_30E9D8(void *);
extern float func_30FF88(int);
extern float func_30ECD8(float);
extern void *func_30FFE0(unsigned int, unsigned int, float);
extern int func_30FF98(float);
extern void func_35D650(void *, void *, int, int, int, int, int, float);

void func_L04_003F6008(unsigned char *a0)
{
    unsigned char *st = *(unsigned char **)(a0 + 0x68);
    float m[4];
    float q[4];
    float src[4];
    float *fp;
    int *ip;
    int i;

    *(V4_003F6008 *)src = *(V4_003F6008 *)(a0 + 0x10);
    src[2] += 0.25f;
    func_30EDC8(m, ref_L04_003F6008_00, src);
    func_30F090(m, m, -0.3f);
    func_30F090(q, m, 0.1f);
    func_30ED98(m, m, src);

    fp = (float *)(st + 0x14);
    ip = (int *)(st + 0x34);
    for (i = 0; i < 4; i++) {
        float v = fp[0] + ((float *)(st + 0x24))[i];

        if (v >= 255.0f)
            fp[0] = v - 255.0f;
        else if (v <= 0.0f)
            fp[0] = v + 255.0f;
        else
            fp[0] = v;

        if (func_30E9D8(&ip[i]))
            ip[i] = 0xFF;

        v = func_30ECD8(1.0f - func_30FF88(0xFF - ip[i]) * 0.0039215689f);
        {
            void *color = func_30FFE0(0x4040FFFF, 0x1040FFFF, v);

            func_35D650(m, color, func_30FF98(fp[0]) & 0xFF,
                        0x35, 1, 2, 0, ((float *)(st + 0x44))[i]);
        }
        fp++;
        func_30ED98(m, m, q);
    }
}
