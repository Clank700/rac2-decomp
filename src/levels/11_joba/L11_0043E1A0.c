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

extern u8 *D_L11_001B359C;

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

INCLUDE_ASM("asm/levels", func_L11_00440E18);

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

INCLUDE_ASM("asm/levels", func_L11_00441A58);

INCLUDE_ASM("asm/levels", func_L11_00441D08);

INCLUDE_ASM("asm/levels", func_L11_00441FB8);

INCLUDE_ASM("asm/levels", func_L11_00442170);

INCLUDE_ASM("asm/levels", func_L11_004423F8);

INCLUDE_ASM("asm/levels", func_L11_004425C8);

INCLUDE_ASM("asm/levels", func_L11_004427B8);

INCLUDE_ASM("asm/levels", func_L11_00442B60);

INCLUDE_ASM("asm/levels", func_L11_00442C80);

INCLUDE_ASM("asm/levels", func_L11_00442E38);

/* func_L11_00443380 and func_L11_004433D8 live in the sibling small-data unit
   (L11_0043E1A0-g8.c): they reach the level's globals through $gp. */

INCLUDE_ASM("asm/levels", func_L11_00443498);

INCLUDE_ASM("asm/levels", func_L11_00443940);

/* maps the class index to its measured identifier */
extern u32 D_L11_002BB0E0[];

/* The level's own jump table: the address of each case body. */
extern void *jtbl_002BB0E0[13];

s32 func_L11_00443CE0(s32 a) {
    static void * volatile tab[] = {
        &&c0, &&c1, &&c2, &&c3, &&c4, &&c5, &&c6, &&c7,
        &&c8, &&c9, &&c10, &&c11, &&c12
    };

    if ((u32)a >= 13) {
        goto def;
    }
    goto *jtbl_002BB0E0[a];
c0:
    return 0x2F66;
c1:
    return 0x2F67;
c2:
    return 0x2F68;
c3:
    return 0x2F69;
c4:
    return 0x2F6A;
c5:
    return 0x2F6B;
c6:
    return 0x2F6C;
c7:
    return 0x2F6D;
c8:
    return 0x2F70;
c9:
    return 0x2F71;
c10:
    return 0x3243;
c11:
    return 0x3244;
c12:
    return 0x3245;
def:
    return 0x2F66;
}

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

s32 func_L11_00445D28(u8 *obj, s32 idx) {
    u8 *state = *(u8 **)(obj + 0x68);
    s32 v;

    if ((u32)idx >= 0x27) {
        return 0;
    }
    if (idx < 0x14) {
        s32 *p = (s32 *)((u8 *)state + idx * 4);
        v = p[0x84];
    } else {
        s32 *p = (s32 *)((u8 *)state + (idx - 0x14) * 4);
        v = p[0x98];
    }
    {
        JobaCallSlotView *slot = (JobaCallSlotView *)D_001A63A8;

        if (slot->field68 != 0) {
            goto fail;
        }
        if (slot->field24 != -1) {
            goto fail;
        }
        slot->field24 = (v & 0x3FFF) + 0x7D0;
        slot->field28 = 0;
        {
            s16 *p = (s16 *)((u8 *)state + idx * 2 + 0x2A0);
            *p = 1;
        }
    }
    return 1;
fail:
    return 0;
}
INCLUDE_ASM("asm/levels", func_L11_00445DF8);

INCLUDE_ASM("asm/levels", func_L11_00446020);

/* hands the state's 0x1C4 field to the shared helper, after the caller's argument */
extern void func_332CE8();

void func_L11_004461C0(u8 *object, u8 *arg) {
    u8 *state = *(u8 **)(object + 0x68);
    func_332CE8(arg, *(u8 **)(state + 0x1C4));
}

INCLUDE_ASM("asm/levels", func_L11_004461E8);
