/* Retained complete C; not linked or counted. Updated25 October2026.
 * B04E0 receives an optional48-byte matrix pointer as its third GPR (null here).
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por.
 * 648/644 bytes. The joint producer writes64 bytes; the last row is later
 * reused as a16-byte scratch. A genuine union preserves joint[4] versus
 * rotation[3]+scratch[1], both complete48-byte rotation matrices and
 * every16-byte vector. AAA00 returns float on both calls.
 * Frame0xD0 agrees but an extra saved GPR and object/matrix address lifetimes
 * remain. A complete aggregate workspace was object-identical. Do not revert
 * the joint output to an undersized48-byte array.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L23_001AFA74 __attribute__((sda));
extern char D_00189EA0[];

extern void func_0029FCC0(void *, int, void *);
extern void func_002AF1D0(void *, void *, int, int);
extern void func_0029FC20(void *, int, void *);
extern void func_00283098(void *, void *, void *);
extern float func_002B04E0(void *, void *, void *);
extern float func_002AAA00(void *, void *, int, float, float, float, float);
extern void func_002833F0(void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_002A05A8(void *);
extern void func_002A0F48(void *);
extern void func_00282D30(void *, void *, float);
extern void func_002B0408(void *, void *, void *);
extern int func_00282978(short *);
extern void func_00282CF0(void *, void *, void *);

void func_L23_003C16D8(char *obj) {
    TI128 v0[1];
    union { TI128 joint[4]; struct { TI128 rows[3], scratch[1]; } rotation; } phase;
    TI128 u[1], r3[3], r4[1];
    float fz0, fz1;
    char *state = *(char **)(obj + 0x68);
    float r;
    float a1;
    float b1;
    float c1;

    if (*(unsigned char *)(obj + 0x95) == 2 || *(short *)(state + 0x2A6) != 0)
        func_0029FCC0(obj, 1, *(char **)(state + 0x2A0) + 0x10);
    else
        func_002AF1D0(obj, *(char **)(state + 0x2A0), 1, 0);
    if (*(unsigned char *)(obj + 0x95) == 2) {
        if (*(short *)(state + 0x2A6) == 0)
            *(int *)(state + 0x2AC) = 0;
        func_00282CF0(v0, D_00189EA0, *(char **)(state + 0x2A0) + 0x10);
        r = func_002B04E0(*(char **)(state + 0x2A0), v0, 0);
        b1 = *(float *)(state + 0x68) + *(float *)(state + 0x68);
        a1 = *(float *)(state + 0x64);
        c1 = *(float *)(state + 0x6C);
        fz0 = 0;
        func_002AAA00(&fz0, state + 0x2AC, 0, r, a1, b1, c1);
        qzero(phase.rotation.scratch);
        ((float *)phase.rotation.scratch)[2] = *(float *)(state + 0x2AC);
        func_002833F0(phase.rotation.rows, phase.rotation.scratch);
        func_00283738(*(char **)(state + 0x2A0) + 0xC0, *(char **)(state + 0x2A0) + 0xC0, phase.rotation.rows);
        func_002A05A8(*(char **)(state + 0x2A0));
        *(unsigned short *)(*(char **)(state + 0x2A0) + 0x34) |= 0x106;
        func_002A0F48(*(char **)(state + 0x2A0));
        func_00282D30(u, state + 0x280, -1.0f);
        func_002B0408(*(char **)(state + 0x2A0) + 0xC0, u, 0);
        *(short *)(state + 0x2A6) = D_L23_001AFA74;
        return;
    }
    {
        short v = *(short *)(state + 0x2A6);

        if (v != 0) {
            if (v == D_L23_001AFA74)
                *(int *)(state + 0x2AC) = 0;
            *v0 = 0;
            ((float *)v0)[0] = 1.0f;
            ((float *)v0)[3] = 1.0f;
            func_0029FC20(obj, 1, phase.joint);
            qzero(phase.rotation.scratch);
            func_00283098(v0, v0, phase.rotation.rows);
            r = func_002B04E0(*(char **)(state + 0x2A0), v0, 0);
            a1 = *(float *)(state + 0x64) + *(float *)(state + 0x64);
            c1 = *(float *)(state + 0x6C);
            b1 = *(float *)(state + 0x68) * 4.0f;
            fz1 = 0;
            func_002AAA00(&fz1, state + 0x2AC, 0, r, a1, b1, c1);
            qzero(u);
            ((float *)u)[2] = *(float *)(state + 0x2AC);
            func_002833F0(r3, u);
            func_00283738(*(char **)(state + 0x2A0) + 0xC0, *(char **)(state + 0x2A0) + 0xC0, r3);
            func_002A05A8(*(char **)(state + 0x2A0));
            *(unsigned short *)(*(char **)(state + 0x2A0) + 0x34) |= 0x106;
            func_002A0F48(*(char **)(state + 0x2A0));
            func_00282D30(r4, state + 0x280, -1.0f);
            func_002B0408(*(char **)(state + 0x2A0) + 0xC0, r4, 0);
            func_00282978((short *)(state + 0x2A6));
        }
    }
}
