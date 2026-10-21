#include "include_asm.h"

typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef float f32;

/* Small-data controls: the four measured globals the level's script hooks share. */
extern s32 D_L11_001B1530 __attribute__((sda));

extern s32 D_L11_001B1540 __attribute__((sda));

extern s32 D_L11_001B1550 __attribute__((sda));

extern s32 D_L11_001B1560 __attribute__((sda));

extern void func_3004A8(void *);

extern void func_4882F0(void *, void *, s32, s32, s32);

extern void func_488268(s32, s32);

extern void func_4881A8(void *);

extern void func_488200(void *);

extern u32 D_L11_001B32E8[];

extern u8 D_L11_001BA8C0[];

extern u8 *D_L11_001B359C[3] __attribute__((sda));

extern u8 *D_L11_001FC420[];

extern float func_282E48(void *, void *);

extern void func_32C9E0();

extern void func_440C90(u8 *);

/* One class record of the measured class table: six halfwords, then the two flag
   bytes at 0x14 and 0x15.  The record is 26 bytes long. */
typedef struct {
    s16 half[6];
    u8 pad0[8];
    u8 flag14;
    u8 flag15;
    u8 pad1[4];
} JobaClassRecordView;

typedef struct {
    s32 count;
    JobaClassRecordView *records;
} JobaClassTableView;

/* The class table itself: an array of pointers to the per-class entries. */
extern u32 D_L11_001B14F8 __attribute__((sda));

/* Checks the state's six counters against the class record and reports whether the
   class may still be used. */
s32 func_L11_00442710(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    s32 index = *(s16 *)(state + 0x1F0);
    s32 cls = *(s16 *)(state + 0x1F2);
    JobaClassTableView *entry = ((JobaClassTableView **)&D_L11_001B14F8)[index];
    JobaClassRecordView *rec = &entry->records[cls];
    u32 *counters = (u32 *)(state + 0x100);
    s32 same = 1;
    s32 i;
    s32 result;
    for (i = 0; i < 6; i++) {
        same &= (counters[i] == (u32)rec->half[i]);
    }
    if (rec->flag14 != 0) {
        same &= *(u32 *)(state + 0x118);
    }
    if (rec->flag15 != 0) {
        same &= *(u32 *)(state + 0x11C);
    }
    result = 0;
    if (*(u32 *)(state + 0x140) == 0) {
        if (same != 0) {
            result = 1;
        }
    }
    return result;
}
/* The four angle and length constants the script reads through $gp. */
extern f32 D_L11_001B15AC __attribute__((sda));

extern f32 D_L11_001B15B0 __attribute__((sda));

extern f32 D_L11_001B15B4 __attribute__((sda));

extern f32 D_L11_001B15B8 __attribute__((sda));

extern float func_00283B98(float, float);

extern float func_00283180(float);

extern float func_00283198(float);

extern float func_002A7878(float, float);

extern void func_00282CC0(u8 *, u8 *, u8 *);

extern void func_002833F0(u8 *, u8 *);

extern u8 *func_L11_004417E8(u8 *);

extern void func_L11_00436910(char *, int, int);

extern void func_L11_004496A0(char *, int, int);

extern void func_L11_0044C328(char *, int, int);

extern void func_L11_00452C58(char *, int, int);

extern void func_L11_00454C78(char *, int, int);

/* arms the script bridge over the measured buffers and starts it on the shared slot */
void func_L11_00443380(void) {
    s32 buffer[4];
    func_3004A8(buffer);
    func_4882F0(&D_L11_001B1550, &D_L11_001B1560, 1, 0, 0);
    func_488268(2, 0x168);
    func_4881A8(&D_L11_001B1530);
    func_488200(&D_L11_001B1540);
}

/* Turns the script's angle around the actor, hands the result to the level's helpers
   and counts the class the script's identifier names. */
s32 func_L11_00440970(u8 *object, u8 *arg) {
    u8 *state = *(u8 **)(object + 0x68);
    f32 step = D_L11_001B15B4;
    f32 v;

    v = func_00283B98(*(f32 *)(state + 0x19C), step);
    *(f32 *)(state + 0x19C) = v;
    v = func_00283180(v);
    *(f32 *)(arg + 0x10) = D_L11_001B15B8 * v;
    v = func_00283198(*(f32 *)(state + 0x19C));
    *(f32 *)(arg + 0x14) = D_L11_001B15B8 * v;
    func_00282CC0(arg + 0x10, arg + 0x10, func_L11_004417E8(object));
    *(f32 *)(arg + 0x18) = func_002A7878(D_L11_001B15AC, D_L11_001B15B0);
    *(f32 *)(arg + 0xF4) = -1.570796489715576171875f;
    *(s32 *)(arg + 0xF0) = 0;
    *(f32 *)(arg + 0xF8) = *(f32 *)(state + 0x19C);
    func_002833F0(arg + 0xC0, arg + 0xF0);
    switch (*(s16 *)(arg + 0xAA)) {
    case 0xD98:
        func_L11_004496A0(arg, 0, 1);
        *(s32 *)(state + 0x100) += 1;
        break;
    case 0xDCF:
        func_L11_0044C328(arg, 0, 1);
        *(s32 *)(state + 0x104) += 1;
        break;
    case 0xDF4:
        func_L11_00452C58(arg, 0, 1);
        *(s32 *)(state + 0x108) += 1;
        break;
    case 0xDF7:
        func_L11_00454C78(arg, 0, 1);
        *(s32 *)(state + 0x10C) += 1;
        break;
    case 0xD37:
        func_L11_00436910(arg, 0, 1);
        *(s32 *)(state + 0x114) += 1;
        break;
    }
    return 1;
}

extern s32 D_L11_001B35B8[] __attribute__((sda));
extern f32 D_L11_001B1614 __attribute__((sda));
extern f32 D_L11_001B1618 __attribute__((sda));
extern s32 func_00312B58(u8 *);
extern s32 func_L02_00416800(u8 *);
extern s32 func_002A77E0(s32);
extern void func_L02_00416720(u8 *, u8 *, f32, f32);

#define GROUP(off) (*(s32 *)(state + (off)))
/* Leaves the function when the group is 0xFF or empty; the braces it opens close in END_IDS. */
#define FOR_EACH_ID(p, off) \
    if (GROUP(off) == 0xFF) \
        return; \
    { u16 *q = (u16 *)D_L11_001FC420[GROUP(off)]; \
    if (q == 0) \
        return; \
    for (p = q; (GROUP(off) & 0xFF) != 0xFF && GROUP(off) <= D_L11_001B35B8[0] && p != 0 && \
         ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L11_001FC420[GROUP(off)]); \
         p++)
#define END_IDS }
/* One half: collect the entities of group OFF for which func_00312B58 holds (counting the
   others in m), then, up to 1000 passes over the group at state word 0x17C while m is below
   the record's limit, hand one collected entity at a time to func_L02_00416720 with an entity
   of that group. */
#define HALF(limit, off) \
    { \
        s32 n, m, i, k; \
        if (*(s16 *)(rec + (limit)) != 0) { \
            m = 0; \
            n = 0; \
            for (k = 15; k >= 0; k--) \
                buf[k] = 0; \
            FOR_EACH_ID(p, off) { \
                e = D_L11_001B359C[0] + ((*p & 0x7FFF) << 8); \
                if (e == 0) \
                    break; \
                if (func_00312B58(e) == 0) { \
                    m++; \
                } else { \
                    buf[n] = e; \
                    n++; \
                } \
            } END_IDS \
            if (n != 0) { \
                for (i = 0; i < 1000 && m < *(s16 *)(rec + (limit)); i++) { \
                    FOR_EACH_ID(p, 0x17C) { \
                        e = D_L11_001B359C[0] + ((*p & 0x7FFF) << 8); \
                        if (e == 0) \
                            break; \
                        if (n <= 0) \
                            break; \
                        if (func_L02_00416800(e) != 0 && func_002A77E0(6) == 0) { \
                            n--; \
                            func_L02_00416720(e, buf[n], D_L11_001B1614 * 0.016666668f, \
                                              D_L11_001B1618 * 2.908882452175021e-4f); \
                            m++; \
                            break; \
                        } \
                    } END_IDS \
                } \
            } \
        } \
    }

/* For each of the object's two groups (state words 0x178 and 0x174), gathers the entities
   func_00312B58 accepts and counts the ones it refuses; then, while that count is below the
   limit of the class record the state names (the halfword at 0x10, at 0x12 for the second
   group), hands the gathered entities, last first, to func_L02_00416720 together with entities
   of the group at state word 0x17C. */
void func_L11_00442E38(u8 *object) {
    u8 *state = *(u8 **)(object + 0x68);
    JobaClassTableView *entry =
        ((JobaClassTableView **)&D_L11_001B14F8)[*(s16 *)(state + 0x1F0)];
    u8 *rec = (u8 *)&entry->records[*(s16 *)(state + 0x1F2)];
    u8 *buf[16];
    u16 *p;
    u8 *e;

    HALF(0x10, 0x178)
    HALF(0x12, 0x174)
}
