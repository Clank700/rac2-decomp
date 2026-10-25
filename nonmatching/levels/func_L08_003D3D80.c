/* Retained manual C reconstruction, 25 October 2026; not matching.
 * Profile: -O2 -G0 -ffunction-sections. US, USA v2.00 and PAL each match 0/1 placements.
 * 128/128 bytes; first mismatch +0x24 in the constant-1, source-byte and payload-pointer scratch
 * registers and initialization-store order. The approved qcopy itself reproduces the addressed
 * lq/sq pair.
 * Independent allocator/source-lifetime evidence for constructor initialization. Three
 * meaningful forms produced identical text bytes; do not repeat equivalent spellings or infer C
 * impossibility.
 * Only the measured prefix is modeled; it does not establish the complete object size. Original
 * TI drafts remain preserved privately and in Git history. No linked build or runtime validation
 * was run. The measured candidate body is retained below; this results header was added
 * afterwards.
 */

#include "common.h"

extern void *func_0029EFD0(s32 class_id);
extern void func_002A0F48(void *object);

/* Partial object view; only the constructor's measured fields are described. */
typedef struct SpawnedObjectPrefix {
    u8 reserved00[0x10];
    float position[4];
    u8 state;
    u8 reserved21[15];
    u8 unk30, unk31;
    u16 unk32;
    u8 reserved34[0x34];
    struct SpawnedObjectPrefix **payload;
    u8 reserved6C[0x10];
    u16 unk7C;
} SpawnedObjectPrefix;

void *func_L08_003D3D80(SpawnedObjectPrefix *source)
{
    SpawnedObjectPrefix *object = func_0029EFD0(0x987);
    if (object != 0) {
        SpawnedObjectPrefix **payload = object->payload;
        object->unk30 = source->unk30;
        object->unk31 = 1;
        object->unk32 = source->unk32;
        object->unk7C = 0x7F;
        object->state = 0;
        *payload = source;
        qcopy(object->position, source->position);
        func_002A0F48(object);
    }
    return object;
}
