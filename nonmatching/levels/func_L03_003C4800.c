/* Nonmatching C: Visit the object group and emit an effect at each class-specific transformed point.
 * Tested profile: -O2 -G8 -ffunction-sections.
 * Measured US size: 556 bytes; retail: 524 bytes.
 * Placement checks: US, US2 and PAL: 0/2 each.
 * Remaining: Truthful table declarations do not reproduce the observed table addressing; inner-loop setup scheduling also differs.
 * Reopen with independent data-layout evidence for the id and vector tables and a supported way to express their observed small-data addressing without disguising arrays as scalar integers.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L03_001B2A38 __attribute__((sda));
extern unsigned char *D_L03_001B2A1C;
extern unsigned short *D_L03_001FB5A0[];

extern void func_0029FC20(char *, int, char *);
extern void func_002830C0(void *, void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

extern int D_L03_001AFF60[] __attribute__((sda));
extern int D_L03_001AFF78[] __attribute__((sda));
extern int D_L03_001AFF88[] __attribute__((sda));
extern int D_L03_001AFF98[] __attribute__((sda));
extern TI128 D_L03_001AFFB0[] __attribute__((sda));
extern TI128 D_L03_001AFFE0[] __attribute__((sda));
extern TI128 D_L03_001B0010[] __attribute__((sda));
extern TI128 D_L03_0029A880[5];


void func_L03_003C4800(unsigned char *a0) {
    unsigned short *q;
    unsigned char *e;
    int *ids;
    TI128 *vecs;
    int n;
    int j;
    float w;
    float m[16] __attribute__((aligned(16)));
    float v[4] __attribute__((aligned(16)));
    float *vp;

    for (q = D_L03_001FB5A0[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L03_001B2A38 && q != 0 &&
         ((q != 0 && (short)q[-1] >= 0) || q == D_L03_001FB5A0[a0[0x21]]);
         q++) {
        e = D_L03_001B2A1C + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x31] == 0)
            continue;
        if (e[0x20] == 0xFE)
            continue;
        if (e[0x20] == 0xFD)
            continue;
        switch (*(short *)(e + 0xAA)) {
        case 0x940:
            ids = D_L03_001AFF88;
            vecs = D_L03_001AFFE0;
            n = 3;
            break;
        case 0x93C:
            ids = D_L03_001AFF78;
            vecs = D_L03_001AFFB0;
            n = 3;
            break;
        case 0x964:
            ids = D_L03_001AFF60;
            vecs = D_L03_0029A880;
            n = 5;
            break;
        default:
            ids = D_L03_001AFF98;
            vecs = D_L03_001B0010;
            n = 3;
            break;
        }
        vp = v;
        for (j = 0; j < n; j++) {
            func_0029FC20((char *)e, ids[j], (char *)m);
            qcopy(vp, &vecs[j]);
            w = v[3];
            v[3] = 1.0f;
            func_002830C0(vp, vp, m);
            func_L00_00325AE8(vp, *(int *)(e + 0x78), w, 0.08f);
        }
    }
}
