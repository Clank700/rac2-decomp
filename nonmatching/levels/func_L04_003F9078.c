/*
 * Near miss, wave 10 worker 06 (2026-10-25).
 * Profile: -O2 -G0 -ffunction-sections (04_barlow / 11_joba shared unit).
 * Retail: 504 bytes, 2 places (04_barlow at 0x003f9078, 11_joba at 0x003e1068).
 * Best measured C: 488 bytes, 0 of 2 places.
 *   wslcmp: func_L04_003F9078: 0 of 2 places match [04_barlow: 488 bytes, expected 504]
 * Body reproduced: the two 16-byte calls, the -0.3f/0.1f rotations, the four
 * 0x35/1/2/0 particle emissions, the [255,0] colour wrap and the 0xFF- colour
 * arithmetic.  The reference data pointer differs per place and is declared as
 * ref_L04_003F9078_00; the callees also differ per place (11_joba uses
 * func_300xxx instead of func_30Exxx), so those need ref symbols too.
 * Remaining difference: retail keeps the q pointer (sp+0x10) in $s7, hence a
 * 0x90 frame with eight saved GPRs; this cc1 rematerialises sp+0x10 and saves
 * seven, 16 bytes short.  The wrap branch and the $s4/$s3 induction also differ.
 * Reopen with an address-liveness model that keeps the q pointer in a
 * callee-saved register across the loop.
 */
typedef int V4_003F9078 __attribute__((mode(TI)));
extern unsigned char ref_L04_003F9078_00[];
extern void func_00282CF0(float *, void *, float *);
extern void func_00282F20(float *, float *, float);
extern void func_00282CC0(float *, float *, float *);
extern int func_00282948(void *);
extern float func_00283CE0(int);
extern float func_00282C48(float);
extern void *func_00283D38(unsigned int, unsigned int, float);
extern int func_00283CF0(float);
extern void func_002C2FD8(void *, void *, int, int, int, int, int, float);

void func_L04_003F9078(unsigned char *a0)
{
    unsigned char *st = *(unsigned char **)(a0 + 0x68);
    float m[4];
    float q[4];
    float src[4];
    float *fp;
    int *ip;
    int i;

    *(V4_003F9078 *)src = *(V4_003F9078 *)(a0 + 0x10);
    src[2] += 0.25f;
    func_00282CF0(m, ref_L04_003F9078_00, src);
    func_00282F20(m, m, -0.3f);
    func_00282F20(q, m, 0.1f);
    func_00282CC0(m, m, src);

    fp = (float *)(st + 0x10);
    ip = (int *)(st + 0x30);
    for (i = 0; i < 4; i++) {
        float v = fp[0] + ((float *)(st + 0x20))[i];

        if (v >= 255.0f)
            fp[0] = v - 255.0f;
        else if (v <= 0.0f)
            fp[0] = v + 255.0f;
        else
            fp[0] = v;

        if (func_00282948(&ip[i]))
            ip[i] = 0xFF;

        v = func_00282C48(1.0f - func_00283CE0(0xFF - ip[i]) * 0.0039215689f);
        {
            void *color = func_00283D38(0x4040FFFF, 0x1040FFFF, v);

            func_002C2FD8(m, color, func_00283CF0(fp[0]) & 0xFF,
                        0x35, 1, 2, 0, ((float *)(st + 0x40))[i]);
        }
        fp++;
        func_00282CC0(m, m, q);
    }
}
