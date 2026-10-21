#include "include_asm.h"

typedef float f32;

typedef unsigned char u8;

typedef int s32;

typedef short s16;

typedef unsigned short u16;

typedef unsigned int u32;

/* Dispatches an indexed polygon query through the already integrated helper. */
typedef struct { s32 field00; u8 remainder[12]; } JobaPolygonHeaderView;

extern JobaPolygonHeaderView *D_L11_001FF580[];

extern s32 func_002A8AF0(f32 *point, f32 *vertices, s32 count);

/* Consumes one positive counter selected by the measured class identifier. */
typedef struct {
    u8 prefix[0xe0];
    s32 fielde0, fielde4, fielde8, fieldec, fieldf0, fieldf4;
} JobaClassCounterView;

INCLUDE_ASM("asm/levels", func_L11_0043E1A0);

/* bumps the 0xFFFF-saturated counter, then starts the state's timer and reports the object */
extern u8 D_L11_004465F8[];
extern void func_300150(void *);
extern void func_2F8AD0(void *, void *);
extern void func_31F338(void);

void func_L11_00440160(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    u16 *counter = (u16 *)(obj + 0x96);
    if (*counter <= 0xFFFE) {
        *counter = *counter + 1;
    }
    func_300150(state + 0x190);
    func_2F8AD0(D_L11_004465F8, obj);
    func_31F338();
}

/* clears the state's six-word block and its counters, then restarts the object */
extern void func_32C9E0();

void func_L11_004401C0(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    s32 *p = (s32 *)(state + 0x134);
    *(s16 *)(state + 0x1F0) = -1;
    *(s16 *)(state + 0x1E8) = 0;
    *(s16 *)(state + 0x1F2) = -1;
    for (i = 5; i >= 0; i--) {
        *p = 0;
        p--;
    }
    *(s32 *)(state + 0x18C) = 0;
    *(s32 *)(state + 0x180) = 0;
    func_32C9E0(obj, 1, -1);
    *(float *)(state + 0x1BC) = 1.0f;
    *(s32 *)(state + 0x170) = 0;
}

INCLUDE_ASM("asm/levels", func_L11_00440238);
INCLUDE_ASM("asm/levels", func_L11_00440360);

INCLUDE_ASM("asm/levels", func_L11_00440790);

/* Finds the class entry the identifier names and hands it to that class's handler. */
extern u8 *D_L11_001FC420[];

extern u8 *D_L11_001B359C __attribute__((section(".sdata")));

extern void func_L11_003F2F38(u8 *);

extern void func_L11_00439950(u8 *);

INCLUDE_ASM("asm/levels", func_L11_00440868);

/* func_L11_00440970 lives in the sibling small-data unit (L11_0043E1A0-g8.c). */

INCLUDE_ASM("asm/levels", func_L11_00440B28);

/* Returns the state's 0x200 halfword. */
s16 func_L11_00440C80(u8 *obj) {
    return *(s16 *)(*(u8 **)(obj + 0x68) + 0x200);
}

INCLUDE_ASM("asm/levels", func_L11_00440C90);

/* func_L11_00440E18 lives in the sibling small-data unit (L11_0043E1A0-g8.c). */

/* Walks the state's 0x120 slots in order and renews each live entry through the two shared helpers. */
extern s32 func_417238(s32);

extern void func_4172E8(s32);

void func_L11_00441090(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    for (i = 0; i <= *(s32 *)(state + 0x18C); i++) {
        s32 *slot = (s32 *)(state + 0x120 + i * 4);
        if (slot[0] == 0) {
            continue;
        }
        if (func_417238(slot[0]) == 0) {
            continue;
        }
        func_4172E8(slot[0]);
    }
}

/* Clears the state's 0x120 slot table once every live entry has been accepted. */
extern s32 func_417270(s32);

void func_L11_00441108(u8 *obj) {
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    s32 accepted = 1;
    for (i = 0; i <= *(s32 *)(state + 0x18C); i++) {
        s32 *slot = (s32 *)(state + 0x120 + i * 4);
        if (slot[0] == 0) {
            continue;
        }
        if (func_417270(slot[0]) != 0) {
            continue;
        }
        accepted = 0;
        break;
    }
    if (accepted != 0) {
        s32 j;
        for (j = 0; j <= *(s32 *)(state + 0x18C); j++) {
            *(s32 *)(state + 0x120 + j * 4) = 0;
        }
        *(s32 *)(state + 0x18C) = 0;
    }
}

/* hands every entry of the class list to its measured handler */
extern u8 *D_L11_001FC420[];

extern u8 *D_L11_001B359C;

extern void func_L11_00449878(u8 *);

extern void func_L11_0044C4F0(u8 *);

extern void func_L11_00452DF8(u8 *);

extern void func_L11_00454DD8(u8 *);

extern void func_L11_00456540(u8 *);

extern void func_L11_00436A78(u8 *);

extern void func_L11_00439BF0(u8 *);

extern void func_L11_0043AB28(u8 *);

extern void func_L11_003F3098(u8 *);

INCLUDE_ASM("asm/levels", func_L11_004411C8);

INCLUDE_ASM("asm/levels", func_L11_00441350);

INCLUDE_ASM("asm/levels", func_L11_004417A0);

/* arms the one-shot flag block when it is idle and the state agrees */
typedef struct { u8 pad[0x284]; s32 field284; s32 field288; } JobaFlagBlockView;

extern JobaFlagBlockView D_L11_001BA780;

void func_L11_004417A8(u8 *object, s32 value) {
    u8 *state = *(u8 **)(object + 0x68);
    if (D_L11_001BA780.field284 == *(s32 *)(state + 0x184)) {
        D_L11_001BA780.field284 = 0;
    }
    if (value != 0 && D_L11_001BA780.field284 == 0) {
        D_L11_001BA780.field284 = value;
        D_L11_001BA780.field288 = 0;
    }
    *(s32 *)(state + 0x184) = value;
}

/* returns the 128-byte entry selected by the state index, at its 0x30-byte payload */
extern u8 *D_L11_001B368C __attribute__((sda));

u8 *func_L11_004417E8(u8 *object) {
    u8 *state = *(u8 **)(object + 0x68);
    return D_L11_001B368C + (*(s32 *)(state + 0x168) << 7) + 0x30;
}

/* returns zero for a missing state polygon index or dispatches its point query to the integrated crossing-parity helper */
s32 func_L11_00441808(u8 *object, f32 *point) {
    u8 *state = *(u8 **)(object + 0x68);
    s32 index = *(s32 *)(state + 0x164);
    JobaPolygonHeaderView *header;
    s32 result;
    if (index == -1) {
        result = 0;
    } else {
        header = D_L11_001FF580[index];
        result = func_002A8AF0(point, (f32 *)(header + 1), header->field00);
    }
    return result;
}

/* Returns the state's 0xC0 word. */
s32 func_L11_00441858(u8 *obj) {
    return *(s32 *)(*(u8 **)(obj + 0x68) + 0xC0);
}

/* consumes one positive signed state counter selected by a measured class identifier and reports success */
s32 func_L11_00441868(u8 *object, s32 class_id) {
    JobaClassCounterView *state = *(JobaClassCounterView **)(object + 0x68);
    switch (class_id) {
        case 0xd98:
            if (state->fielde0 > 0) { state->fielde0--; return 1; }
            break;
        case 0xdcf:
            if (state->fielde4 > 0) { state->fielde4--; return 1; }
            break;
        case 0xdf4:
            if (state->fielde8 > 0) { state->fielde8--; return 1; }
            break;
        case 0xdf7:
            if (state->fieldec > 0) { state->fieldec--; return 1; }
            break;
        case 0xdf9:
            if (state->fieldf0 > 0) { state->fieldf0--; return 1; }
            break;
        case 0xd37:
            if (state->fieldf4 > 0) { state->fieldf4--; return 1; }
            break;
    }
    return 0;
}

/* increments one signed state counter selected by a measured class identifier */
/* Increments the state counter selected by the measured class identifier. */
void func_L11_00441978(u8 *object, s32 class_id) {
    JobaClassCounterView *state = *(JobaClassCounterView **)(object + 0x68);
    switch (class_id) {
        case 0xd98: state->fielde0++; break;
        case 0xdcf: state->fielde4++; break;
        case 0xdf4: state->fielde8++; break;
        case 0xdf7: state->fieldec++; break;
        case 0xdf9: state->fieldf0++; break;
        case 0xd37: state->fieldf4++; break;
    }
}

/* Each group word of the object's state names an id list in D_L11_001FC420: halfwords whose low
   15 bits index the 256-byte records of D_L11_001B359C, the last one with its sign bit set. A
   walk stops when the group word (re-read after every callback) is 0xFF or above the limit
   kept at D_L11_001B35B8. */
extern s32 D_L11_001B35B8[] __attribute__((sda));

#define GROUP(off) (*(s32 *)(state + (off)))
#define FOR_EACH_ID(p, off) \
    for (p = (u16 *)D_L11_001FC420[GROUP(off)]; \
         (GROUP(off) & 0xFF) != 0xFF && GROUP(off) <= D_L11_001B35B8[0] && p != 0 && \
         ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L11_001FC420[GROUP(off)]); \
         p++)

extern s16 func_L02_004024A0(u8 *);
extern void func_L02_004024B0(u8 *);
extern void func_L02_004024C0(u8 *);

/* Counts the entities of the object's group (state word 0xC8) for which func_L02_004024A0
   holds, then sets (func_L02_004024B0) or clears (func_L02_004024C0) entities until the count
   equals the second argument. */
void func_L11_00441A58(u8 *object, s32 count) {
    u8 *state = *(u8 **)(object + 0x68);
    u16 *p;
    u8 *e;
    s32 n = 0;

    FOR_EACH_ID(p, 0xC8) {
        e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (func_L02_004024A0(e))
            n++;
    }
    if (n < count) {
        FOR_EACH_ID(p, 0xC8) {
            e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (!func_L02_004024A0(e)) {
                func_L02_004024B0(e);
                n++;
                if (n >= count)
                    break;
            }
        }
    } else if (n > count) {
        FOR_EACH_ID(p, 0xC8) {
            e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (func_L02_004024A0(e)) {
                func_L02_004024C0(e);
                n--;
                if (n <= count)
                    break;
            }
        }
    }
}

extern s32 func_L02_003D7300(u8 *);
extern void func_L02_003D7310(u8 *);
extern void func_L02_003D7320(u8 *);

/* Counts the entities of the object's group (state word 0xCC) for which func_L02_003D7300
   holds, then sets (func_L02_003D7310) or clears (func_L02_003D7320) entities until the count
   equals the second argument. */
void func_L11_00441D08(u8 *object, s32 count) {
    u8 *state = *(u8 **)(object + 0x68);
    u16 *p;
    u8 *e;
    s32 n = 0;

    FOR_EACH_ID(p, 0xCC) {
        e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (func_L02_003D7300(e))
            n++;
    }
    if (n < count) {
        FOR_EACH_ID(p, 0xCC) {
            e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (!func_L02_003D7300(e)) {
                func_L02_003D7310(e);
                n++;
                if (n >= count)
                    break;
            }
        }
    } else if (n > count) {
        FOR_EACH_ID(p, 0xCC) {
            e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (func_L02_003D7300(e)) {
                func_L02_003D7320(e);
                n--;
                if (n <= count)
                    break;
            }
        }
    }
}

INCLUDE_ASM("asm/levels", func_L11_00441FB8);

INCLUDE_ASM("asm/levels", func_L11_00442170);

INCLUDE_ASM("asm/levels", func_L11_004423F8);

INCLUDE_ASM("asm/levels", func_L11_004425C8);

INCLUDE_ASM("asm/levels", func_L11_004427B8);

INCLUDE_ASM("asm/levels", func_L11_00442B60);

extern void func_L02_003A6F78(u8 *);

/* Runs func_L02_003A6F78 on every entity of the object's two groups (state words 0x178 and
   0x174); an empty group, or a group word of 0xFF, ends the function. */
void func_L11_00442C80(u8 *object) {
    u8 *state = *(u8 **)(object + 0x68);
    u16 *p;
    u16 *q;
    u8 *e;

    if (GROUP(0x178) == 0xFF)
        return;
    q = (u16 *)D_L11_001FC420[GROUP(0x178)];
    if (q == 0)
        return;
    for (p = q; (GROUP(0x178) & 0xFF) != 0xFF && GROUP(0x178) <= D_L11_001B35B8[0] && p != 0 &&
                ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L11_001FC420[GROUP(0x178)]);
         p++) {
        e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        func_L02_003A6F78(e);
    }
    if (GROUP(0x174) == 0xFF)
        return;
    q = (u16 *)D_L11_001FC420[GROUP(0x174)];
    if (q == 0)
        return;
    for (p = q; (GROUP(0x174) & 0xFF) != 0xFF && GROUP(0x174) <= D_L11_001B35B8[0] && p != 0 &&
                ((p != 0 && (s16)p[-1] >= 0) || p == (u16 *)D_L11_001FC420[GROUP(0x174)]);
         p++) {
        e = D_L11_001B359C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        func_L02_003A6F78(e);
    }
}

/* func_L11_00442E38 lives in the sibling small-data unit (L11_0043E1A0-g8.c). */

/* func_L11_00443380 lives in the sibling small-data unit (L11_0043E1A0-g8.c). */

INCLUDE_ASM("asm/levels", func_L11_004433D8);

INCLUDE_ASM("asm/levels", func_L11_00443498);

INCLUDE_ASM("asm/levels", func_L11_00443940);

/* maps the class index to its measured identifier */
extern u32 D_L11_002BB0E0[];

INCLUDE_ASM("asm/levels", func_L11_00443CE0);

INCLUDE_ASM("asm/levels", func_L11_00443D78);

INCLUDE_ASM("asm/levels", func_L11_00444400);

INCLUDE_ASM("asm/levels", func_L11_004456A0);

INCLUDE_ASM("asm/levels", func_L11_00445990);

INCLUDE_ASM("asm/levels", func_L11_00445B30);

/* Claims the shared call slot for the state entry the identifier names. */
typedef struct {
    u8 pad0[0x24];
    s32 field24;
    s32 field28;
    u8 pad2[0x3C];
    s32 field68;
} JobaCallSlotView;

extern u8 D_001A63A8[];

/* Claims the shared call slot for the state entry the caller's class identifier
   selects, unless the slot is already busy or waiting. */

INCLUDE_ASM("asm/levels", func_L11_00445D28);
INCLUDE_ASM("asm/levels", func_L11_00445DF8);

INCLUDE_ASM("asm/levels", func_L11_00446020);

/* hands the state's 0x1C4 field to the shared helper, after the caller's argument */
extern void func_332CE8();

void func_L11_004461C0(u8 *object, u8 *arg) {
    u8 *state = *(u8 **)(object + 0x68);
    func_332CE8(arg, *(u8 **)(state + 0x1C4));
}

INCLUDE_ASM("asm/levels", func_L11_004461E8);
