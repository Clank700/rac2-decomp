#include "include_asm.h"

extern int D_L02_001B04DC __attribute__((sda));

extern void func_L02_003DBA70();

extern void func_0029FCC0(char *arg0, int arg1, char *arg2);

extern char D_L02_001B0F60[4] __attribute__((sda));

extern int D_L02_001B0FA0 __attribute__((sda));

extern int D_L02_001B0FA4;

extern void func_2EEFB0(char *, int, char *, char *, int, int, int, int, float);

/* Hands the actor's four widget slots to the effect scheduler. */
void func_L02_003F16A8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    func_2EEFB0(D_L02_001B0F60, 4, state + 0x2A0, state + 0x3A0,
                *(int *)(state + 0x4D4), *(int *)(state + 0x4D0), D_L02_001B0FA0,
                D_L02_001B0FA4, *(float *)(state + 0x4D8));
}

/* Rebuild the four widget descriptions from the resident template. */
void func_L02_003DB9E0(char *arg0) {
    char buffer[16];

    func_0029FCC0(arg0, 2, buffer);
    func_L02_003DBA70(buffer, D_L02_001B04DC);
    func_0029FCC0(arg0, 4, buffer);
    func_L02_003DBA70(buffer, D_L02_001B04DC);
    func_0029FCC0(arg0, 8, buffer);
    func_L02_003DBA70(buffer, D_L02_001B04DC);
    func_0029FCC0(arg0, 6, buffer);
    func_L02_003DBA70(buffer, D_L02_001B04DC);
}

/* The entity array's base: `sda` with a size over 8 bytes gives the bare-symbol load, which the
   assembler expands to retail's one-register `lui`/`lw` pair instead of a $gp access. */
extern unsigned char *D_L02_001B359C[3] __attribute__((sda));

extern int D_L02_001B35B8 __attribute__((sda));

extern unsigned short *D_L02_001FC060[];

/* For each entity of the object's group that has class 0xAB0, sets its state byte (+0x20) from
   the first word of its private data: 1 gives 6, 2 gives 7, anything else 3. */
void func_L02_003EAD38(unsigned char *arg0) {
    unsigned short *q;
    unsigned char *e;

    if (arg0[0x21] == 0xFF)
        return;
    q = D_L02_001FC060[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L02_001B35B8 && q != 0 &&
           ((q != 0 && (short)q[-1] >= 0) || q == D_L02_001FC060[arg0[0x21]])) {
        e = D_L02_001B359C[0] + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(short *)(e + 0xAA) == 0xAB0) {
            int t = **(int **)(e + 0x68);

            e[0x20] = (t == 1) ? 6 : ((t == 2) ? 7 : 3);
        }
        q++;
    }
}

/* 0 when an entity of the object's group has class 0xAB0 and a state byte (+0x20) other than
   6 or 7, else 1. */
int func_L02_003EAFC8(unsigned char *arg0) {
    unsigned short *q;
    unsigned char *e;

    if (arg0[0x21] == 0xFF)
        return 1;
    q = D_L02_001FC060[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L02_001B35B8 && q != 0 &&
           ((q != 0 && (short)q[-1] >= 0) || q == D_L02_001FC060[arg0[0x21]])) {
        e = D_L02_001B359C[0] + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        q++;
        if (*(short *)(e + 0xAA) == 0xAB0 && (unsigned char)(e[0x20] - 6) >= 2)
            return 0;
    }
    return 1;
}

extern int D_L02_001B35B8 __attribute__((sda));

/* The word D_L02_001B359C, read here through $gp; the walks above reach it as a bare symbol. */
extern char *D_L02_001B359C_gp;

extern unsigned short *D_L02_001FC060[];

extern char D_00189E20[];

extern int func_002AD0B0(char *);

extern void func_002AD6F0(void *, void *, void *, void *);

/* For every entity of the object's group, copies the word at +0x10 of its +0x24 record into
   its word at +0x98. */
void func_L02_003EB098(unsigned char *a0) {
    unsigned short *p;
    char *e;

    for (p = D_L02_001FC060[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[a0[0x21]]);
         p++) {
        e = D_L02_001B359C_gp + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        *(int *)(e + 0x98) = *(int *)(*(char **)(e + 0x24) + 0x10);
    }
}

/* Walks the entities of the actor's group (D_L02_001FC060[actor[0x21]], ids masked with 0x7FFF,
   0x100-byte records at D_L02_001B359C, the list ends after an id with bit 15 set). Each entity
   of class 0xAAF has its effect (func_002AD0B0) handed to func_002AD6F0; the result says whether
   one of them is the entity D_00189E20 tracks at +0x33C while its flag at +0x340 is set.

   The loop condition tests p twice, the second time as the guard of the p[-1] read, as a list
   macro written on top of a pointer check produces. That second test is what makes retail's
   loop: its `||` leaves a label in the exit test, so jump.c keeps the test at the bottom instead
   of copying it in front of the loop (retail enters with `b test`); GCSE's %hi copy then lands
   after the loop note, which makes loop.c skip the loop (no hoisted constants) and the
   scheduler leave the copy last (the delay slot of `b test`); the loop depth puts that copy in
   $s3 and a1 in $s4. CSE removes the repeated test afterwards. Without it the test is copied in
   front of the loop and the function grows to 364 bytes. */
int func_L02_003EB138(unsigned char *a0, void *a1) {
    int result = 0;
    unsigned short *p;
    char *e;

    for (p = D_L02_001FC060[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[a0[0x21]]);
         p++) {
        e = D_L02_001B359C_gp + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(short *)(e + 0xAA) == 0xAAF) {
            char *g = D_00189E20;
            void *v;

            if (e == *(char **)(g + 0x33C)) {
                if (*(int *)(g + 0x340) != 0)
                    result = 1;
            }
            v = (void *)func_002AD0B0(e);
            if (v != 0)
                func_002AD6F0(v, a1, a0 + 0xF0, a0 + 0xF0);
        }
    }
    return result;
}

extern float D_L02_001B0FA8 __attribute__((sda));
extern float D_L02_001B0FAC __attribute__((sda));
extern float D_L02_001B0FB0 __attribute__((sda));
extern int func_L02_003D7300(char *);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_00283BE0(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_L01_00321178(char *, void *);

/* Looks through the entities of the object's group for one that passes func_L02_003D7300, lies
   within the first bound and inside the cone of the second.  The first such one is aimed at:
   the offset to it is turned around the object's axis by the third angle (its sign follows the
   side the target is on) and handed to the mover, with the state's float at +0x144 lowered
   for the call.  Answers 1 when one was found, else 0. */
int func_L02_003F1BA8(char *self) {
    char *state = *(char **)(self + 0x68);
    float buf[4];
    unsigned short *p;
    char *e;
    float saved;
    float r;
    char *ax;

#define GROUP (*(int *)(state + 0x4E0))
/* The heading of the target, from the object's position. */
#define ANGLE()                                                                       \
    func_00283248(*(float *)(e + 0x10) - *(float *)(self + 0x10),                    \
                  *(float *)(e + 0x14) - *(float *)(self + 0x14))
    if (GROUP == -1)
        return 0;
    for (p = D_L02_001FC060[GROUP];
         (GROUP & 0xFF) != 0xFF && GROUP <= D_L02_001B35B8 && p != 0 &&
         ((p != 0 && (short)p[-1] >= 0) || p == D_L02_001FC060[GROUP]);
         p++) {
        e = (char *)D_L02_001B359C[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L02_003D7300(e) == 0)
            continue;
        if (!(func_00282E80(self + 0x10, e + 0x10) < D_L02_001B0FA8))
            continue;
        if (!(func_00283C80(*(float *)(self + 0xF8), ANGLE()) < D_L02_001B0FAC * 0.017453294f))
            continue;
        /* A statement that compiles to nothing, as in its twins func_L02_003D26B0 and func_L02_0040BBD8: its loop notes end
           cse's extended basic block, so the second `e + 0x10` is a copy of the first, in a
           saved register of its own, as retail has it. */
        do {
        } while (0);
        func_00282CF0(buf, self + 0x10, e + 0x10);
        ax = self + 0xE0;
        r = D_L02_001B0FB0 * 0.017453294f;
        func_002ACEC0(buf, buf, ax,
                      0.0f <= func_00283BE0(*(float *)(self + 0xF8), ANGLE()) ? -r : r);
        func_00282CC0(buf, buf, e + 0x10);
        saved = *(float *)(state + 0x144);
        *(float *)(state + 0x144) = 0.0001f;
        func_L01_00321178(self, buf);
        *(float *)(state + 0x144) = saved;
        return 1;
    }
#undef ANGLE
#undef GROUP
    return 0;
}
