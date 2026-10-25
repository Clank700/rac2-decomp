/*
 * Updated manual-C near miss, 2026-10-25.
 * Measured unit: src/levels/02_maktar_nebula/L02_003EA4E0-g8.c
 * Profile: -O2 -G8 -ffunction-sections
 * Actual release coverage: US 0/1 (exit1); US2 0/1 (exit1); PAL absent (exit1).
 * Current residual: 1416/1416 bytes. The owned nine-label dispatch, full matrix extents,
 * qzero/qcopy and owner-flag prefix view are retained. At+0x94 the ushort postincrement
 * still emits ANDI instead of DADDU; later scheduling also differs. A separated
 * load/increment form gives 1412 bytes.
 * Reopen only for: A true counter/field semantics or scheduling explanation that retains
 * dispatch ownership and canonical integer/FP contracts.
 * Older notes below are historical. Marker and trial-only profiles were restored.
 */

/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-
 * barrier.
 * USA v1.01: 1412/1416 bytes, 0/1 carrying placements.
 * USA v2.00: 1412/1416 bytes, 0/1 carrying placements.
 * PAL: canonical name absent from the catalogue.
 * The ignored func_002AA2E8 result is declared float; its scalar-field address uses a float
 * pointer.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* Nonmatching: USA v1.01: 0/1 carrying places; USA v2.00: 0/1 carrying places; PAL: absent. Final C 1412/1416 retail bytes. Game -O2 -G8 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier. USA v1.01/v2.00 0/1 places, 1412/1416 bytes, PAL absent. Original 0xF0 frame. Three source trials: initial 1400 bytes, unsigned-int timer identical, corrected signed tick-to-float conversions final. Retail 9-entry table and canonical callees; remaining scheduling/copy allocation/field access. Reopen with state typing and control-flow hypothesis. No linked builds.  */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern void *D_L02_002A5420[9];
extern int D_L02_001B0D50 __attribute__((sda));
extern int D_L02_001B0D54 __attribute__((sda));
extern float D_L02_001B0D58 __attribute__((sda));
extern float D_L02_001B0D5C __attribute__((sda));
extern int D_L02_001B30C8;
/* Prefix view of the shared owner flag; the whole object remains unqualified. */
typedef struct { unsigned char pad[3]; unsigned char active; } OwnerFlagView;
extern OwnerFlagView D_001395B8 __attribute__((nosda));
extern char D_00188660[], D_00189F10[];
extern void func_L02_003EAA68(void *);
extern int func_002B38B8(void *);
extern void func_0029B3E0(int, int);
extern int func_002E5CF8(int, int, void *);
extern void func_L02_003EAD38(void *);
extern float func_00282C48(float);
extern int func_L02_003EAE10(void *);
extern void func_002A7750(void *, int, int);
extern int func_002B3868(void *);
extern void func_002833F0(void *, void *);
extern void func_00283698(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_002AA548(void *, void *, float, float, float, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D08(void *, void *, void *, float);
extern float func_00283B98(float, float);
extern int func_L02_003EAFC8(void *);
extern void func_002E59F8(int);
extern void func_L02_003EB098(void *);
extern float func_002AA2E8(float *, float, float);
extern void func_00282F20(void *, void *, float);
extern int func_L02_003EB138(void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_L00_002E6CF0(void (*)(char *), void *);
extern void func_L02_003EB258(char *);
/* Updates the platform's activation, swing, travel and scrolling surface. */
void func_L02_003EA4E0(char *actor) {
    static void *cases[] = {&&start, &&done, &&activate, &&wait, &&swing, &&travel, &&done, &&release, &&moving};
    char *state = *(char **)(actor + 0x68);
    float angles[4], rotation[12], inverse[16], offset[4];
    float speed, distance, target;
    unsigned int mode = *(unsigned char *)(actor + 0x20);
    if (mode >= 9) return;
    goto *cases[mode];
start:
    func_L02_003EAA68(actor);
    return;
activate:
    if (D_L02_001B0D50 == 0) {
        int timer;
        if (!func_002B38B8(actor)) return;
        timer = (*(unsigned short *)(actor + 0x96))++;
        if ((unsigned int)timer < 6) return;
    }
    if (*(int *)(state + 4)) { D_001395B8.active = 1; func_0029B3E0(0, -1); }
    *(int *)(state + 0x2C) = func_002E5CF8(0, 4, actor);
    func_L02_003EAD38(actor);
    return;
wait:
    if (func_00282C48((float)D_L02_001B30C8 - **(float **)(state + 0x28)) <= 10.0f) return;
    if (func_L02_003EAE10(actor)) {
        **(float **)(state + 0x28) = (float)D_L02_001B30C8;
        func_002A7750(actor, 4, -1);
        *(unsigned short *)(actor + 0x34) = (*(unsigned short *)(actor + 0x34) & 0xFFBE) | 0x1000;
        *(int *)(actor + 0x98) = *(int *)(*(char **)(actor + 0x24) + 0x10);
        *(float *)(state + 0xC) = 0;
    }
    return;
swing:
    speed = 0.016666668f;
    if (func_002B3868(actor)) speed = 60.0f;
    qzero(angles);
    angles[2] = *(float *)(state + 0x3C);
    func_002833F0(rotation, angles);
    func_00283698(inverse, rotation);
    func_00282CF0(offset, actor + 0x10, state + 0x30);
    func_00283098(offset, offset, inverse);
    distance = func_00282C48(offset[1]);
    if (distance <= func_00282C48(*(float *)(state + 0xC))) {
        offset[1] = 0;
        func_002A7750(actor, 5, -1);
    } else func_002AA548(offset + 1, state + 0xC, 0.0f, speed, speed, 1.0f);
    func_00283098(offset, offset, rotation);
    func_00282CC0(actor + 0x10, state + 0x30, offset);
    return;
travel:
    if (func_002B3868(actor)) {
        qcopy(state + 0x40, actor + 0x10);
        *(float *)(state + 0x10) = 0;
        *(float *)(state + 0xC) = 0;
    }
    distance = func_00282C48(*(float *)(state + 0x10) - 1.0f);
    if (distance < func_00282C48(*(float *)(state + 0xC))) {
        *(float *)(state + 0x10) = 1.0f;
        func_002A7750(actor, 6, -1);
    } else func_002AA548(state + 0x10, state + 0xC, 1.0f, 0.0027777778f, 0.0027777778f, 0.16666667f);
    func_00282D08(actor + 0x10, state + 0x40, state + 0x30, *(float *)(state + 0x10));
    *(float *)(actor + 0xF8) = func_00283B98(*(float *)(state + 0x3C), (1.0f - *(float *)(state + 0x10)) * 1.5707965f);
    *(float *)(actor + 0xF0) = (1.0f - *(float *)(state + 0x10)) * 3.1415927f;
    return;
release:
    if (func_L02_003EAFC8(actor)) {
        int index = *(int *)(state + 0x2C);
        char *slot = D_00188660 + index * 0x70;
        if (index != -1 && *(char **)(slot + 0x88) == actor && *(unsigned char *)(slot + 0x74)) func_002E59F8(index);
        *(int *)(state + 0x2C) = -1;
        func_L02_003EB098(actor);
        func_002A7750(actor, 8, -1);
    }
    return;
moving:
    target = (float)D_L02_001B0D54 * 0.06666667f;
    func_002AA2E8(&D_L02_001B0D58, target, 0.0044444446f);
    func_00282F20(angles, actor + 0xD0, D_L02_001B0D58);
    if (func_L02_003EB138(actor, angles)) {
        if (D_L02_001B0D58 == target) {
            if (func_00282DB0(D_00189F10, angles) < -0.001f) {
                if (++*(int *)(state + 0x20) > 30) D_L02_001B0D54 = -D_L02_001B0D54;
            } else *(int *)(state + 0x20) = 0;
        } else *(int *)(state + 0x20) = 0;
    }
    *(float *)(state + 0x14) = func_00283B98(*(float *)(state + 0x14), D_L02_001B0D5C * 0.00029088825f);
    *(float *)(state + 0x18) += D_L02_001B0D58 * 0.5f;
    if (*(float *)(state + 0x18) > 1.0f) *(float *)(state + 0x18) -= 1.0f;
    else if (*(float *)(state + 0x18) < -1.0f) *(float *)(state + 0x18) += 1.0f;
    func_002AA2E8((float *)(state + 0x1C), 1.0f, 0.016666668f);
    func_L00_002E6CF0(func_L02_003EB258, actor);
done:
    return;
}
