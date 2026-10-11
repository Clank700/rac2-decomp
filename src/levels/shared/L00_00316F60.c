#include "include_asm.h"

typedef int s32;

typedef float f32;

typedef int BatchA_A06_s32;

typedef short BatchA_A06_BatchAs16;

/* Measured partial layouts; original type and game roles are unknown. */
typedef struct Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner {
    unsigned char prefix_00[0x120];
    void *slots_120[10];
    int count_148;
    int active_14c;
} Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner;

extern void func_0029F338_3(void *object);

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 prefix[0x40];
    void *payload;
    u32 unused44;
    short key;
    u8 marker;
    u8 unused4b;
    u8 selector;
    u8 tail[3];
} GornRecordWrite64;

INCLUDE_ASM("asm/levels", func_L00_00316F60);

/* computes a scalar complement-power curve by repeated multiplication */
f32 func_L00_0031A6C8(f32 value, s32 count) {
    f32 factor = 1.0f - value;
    f32 product = factor;
    for (; count > 1; --count)
        product = product * factor;
    return 1.0f - product;
}

INCLUDE_ASM("asm/levels", func_L00_0031A710);

INCLUDE_ASM("asm/levels", func_L00_0031AA28);

INCLUDE_ASM("asm/levels", func_L00_0031ABE0);

INCLUDE_ASM("asm/levels", func_L00_0031AC60);

INCLUDE_ASM("asm/levels", func_L00_0031AD40);

INCLUDE_ASM("asm/levels", func_L00_0031AFF0);

INCLUDE_ASM("asm/levels", func_L00_0031B398);

INCLUDE_ASM("asm/levels", func_L00_0031B750);

INCLUDE_ASM("asm/levels", func_L00_0031B9F8);

INCLUDE_ASM("asm/levels", func_L00_0031BC48);

INCLUDE_ASM("asm/levels", func_L00_0031BDC0);

INCLUDE_ASM("asm/levels", func_L00_0031BE88);

INCLUDE_ASM("asm/levels", func_L00_0031C0F8);

INCLUDE_ASM("asm/levels", func_L00_0031C3D0);

INCLUDE_ASM("asm/levels", func_L00_0031C978);

INCLUDE_ASM("asm/levels", func_L00_0031C998);

INCLUDE_ASM("asm/levels", func_L00_0031CAC8);

INCLUDE_ASM("asm/levels", func_L00_0031CDD0);

INCLUDE_ASM("asm/levels", func_L00_0031D618);

INCLUDE_ASM("asm/levels", func_L00_0031D620);

INCLUDE_ASM("asm/levels", func_L00_0031D670);

INCLUDE_ASM("asm/levels", func_L00_0031D958);

INCLUDE_ASM("asm/levels", func_L00_0031EC88);

INCLUDE_ASM("asm/levels", func_L00_0031F1C0);

INCLUDE_ASM("asm/levels", func_L00_0031F220);

/* One fixed ordinary scalar query. Signed halfword width, offset and
   equality constant are measured; no original class or field-name claim. */
int func_L00_0031F2B0(const unsigned char *entity) {
    return *(const signed short *)(entity + 0xAA) == 0x0CDB;
}

INCLUDE_ASM("asm/levels", func_L00_003200F8);

INCLUDE_ASM("asm/levels", func_L00_00320460);

INCLUDE_ASM("asm/levels", func_L00_003206B8);

INCLUDE_ASM("asm/levels", func_L00_003207F8);

INCLUDE_ASM("asm/levels", func_L00_00320B70);

INCLUDE_ASM("asm/levels", func_L00_00321878);

INCLUDE_ASM("asm/levels", func_L00_00322428);

INCLUDE_ASM("asm/levels", func_L00_00322A10);

INCLUDE_ASM("asm/levels", func_L00_00322A18);

/* A06-inline-init-40 freshly exact-verified under family reservation */
void func_L00_00322A98(void *a0, char *a1){
    if (*(BatchA_A06_s32 *)(a1 + 0x14C) == 0) {
        *(void **)(a1 + 0x144) = a0;
        *(BatchA_A06_s32 *)(a1 + 0x14C) = 1;
        *(BatchA_A06_BatchAs16 *)(a1 + 0x142) = 0;
        *(BatchA_A06_s32 *)(a1 + 0x148) = 0;
        *(BatchA_A06_BatchAs16 *)(a1 + 0x140) = 0;
    }
}

INCLUDE_ASM("asm/levels", func_L00_00322AC0);

INCLUDE_ASM("asm/levels", func_L00_00322BE0);

/* When active field 0x14C is nonzero, iterate the slots beginning at 0x120 using count 0x148, call the bound helper for each non-null slot, clear each processed slot, and reset the active field. Original game role is unknown. */
void func_L00_00322EC8(Rac2Native_5b4b17178a13f443_SmallSlotReset128Owner *owner)
{
    int index;
    if (owner->active_14c != 0) {
        for (index = 0; index < owner->count_148; ++index) {
            if (owner->slots_120[index] != 0) {
                func_0029F338_3(owner->slots_120[index]);
                owner->slots_120[index] = 0;
            }
        }
        owner->active_14c = 0;
    }
}

INCLUDE_ASM("asm/levels", func_L00_00322F48);

INCLUDE_ASM("asm/levels", func_L00_00323338);

INCLUDE_ASM("asm/levels", func_L00_00323448);

INCLUDE_ASM("asm/levels", func_L00_00323958);

/* Write a payload pointer in the first selector/key record before the list terminator */
void func_L00_00323E48(GornRecordWrite64 *record, u32 selector,
                            int key, void *payload)
{
    if (record->marker != 0) {
        u8 marker;
        do {
            if (record->selector == selector && record->key == key) {
                record->payload = payload;
                return;
            }
            marker = record->marker;
            ++record;
        } while (marker != 1);
    }
}

INCLUDE_ASM("asm/levels", func_L00_00323F28);

INCLUDE_ASM("asm/levels", func_L00_00323F70);

INCLUDE_ASM("asm/levels", func_L00_00324120);

INCLUDE_ASM("asm/levels", func_L00_00324D18);

INCLUDE_ASM("asm/levels", func_L00_00324E48);

INCLUDE_ASM("asm/levels", func_L00_00324F10);

INCLUDE_ASM("asm/levels", func_L00_00324F18);

INCLUDE_ASM("asm/levels", func_L00_003252A8);

INCLUDE_ASM("asm/levels", func_L00_003252C8);

INCLUDE_ASM("asm/levels", func_L00_00325300);

INCLUDE_ASM("asm/levels", func_L00_003253A0);

INCLUDE_ASM("asm/levels", func_L00_003255A0);

INCLUDE_ASM("asm/levels", func_L00_00325600);

INCLUDE_ASM("asm/levels", func_L00_00325760);

INCLUDE_ASM("asm/levels", func_L00_00325AE8);

INCLUDE_ASM("asm/levels", func_L00_00325CC0);

INCLUDE_ASM("asm/levels", func_L00_00325FC0);

INCLUDE_ASM("asm/levels", func_L00_00325FC8);

INCLUDE_ASM("asm/levels", func_L00_00326048);

INCLUDE_ASM("asm/levels", func_L00_00326080);

INCLUDE_ASM("asm/levels", func_L00_00326108);

INCLUDE_ASM("asm/levels", func_L00_00326110);

INCLUDE_ASM("asm/levels", func_L00_00326200);

INCLUDE_ASM("asm/levels", func_L00_003263D0);

INCLUDE_ASM("asm/levels", func_L00_00326620);

INCLUDE_ASM("asm/levels", func_L00_003266D8);

INCLUDE_ASM("asm/levels", func_L00_003268E8);

INCLUDE_ASM("asm/levels", func_L00_00326950);

/* One fixed ordinary scalar source hypothesis. Byte offset and mask are
   measured; no original object/class/field name or allocation claim. The
   observed callers pass scalar one and ignore the result. */
void func_L00_003294F0(unsigned char *entity, int enabled) {
    if (enabled)
        entity[0xBE] |= 4;
    else
        entity[0xBE] &= 0xFB;
}

INCLUDE_ASM("asm/levels", func_L00_00329520);

INCLUDE_ASM("asm/levels", func_L00_003296C0);

INCLUDE_ASM("asm/levels", func_L00_00329E90);

INCLUDE_ASM("asm/levels", func_L00_00329FF0);

INCLUDE_ASM("asm/levels", func_L00_0032A088);

INCLUDE_ASM("asm/levels", func_L00_0032A0B8);

INCLUDE_ASM("asm/levels", func_L00_0032A0E8);

INCLUDE_ASM("asm/levels", func_L00_0032A138);

INCLUDE_ASM("asm/levels", func_L00_0032A170);

INCLUDE_ASM("asm/levels", func_L00_0032A1A8);

INCLUDE_ASM("asm/levels", func_L00_0032A258);

INCLUDE_ASM("asm/levels", func_L00_0032A530);

INCLUDE_ASM("asm/levels", func_L00_0032AA68);

INCLUDE_ASM("asm/levels", func_L00_0032B268);
