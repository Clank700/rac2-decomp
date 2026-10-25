/*
 * Retained complete manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * 176/176 bytes; 0/1 placements in us, us2 and pal.
 * Residual: The full position and 64-bit identity copy, pre-RNG rotation read and calls agree.
 * Inherited header loads/stores still differ at +0x34.
 * Reopen: Independent inherited-header field/lifetime evidence beyond the tied raw and typed
 * forms; preserve all 64 identity bits and pre-call sequencing.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"
typedef int CtorVector __attribute__((mode(TI)));
/* Accessed base-object fields, not the complete allocation extent. */
typedef struct {
    u8 unknown00[0x10];
    CtorVector position;
    u8 mode;
    u8 unknown21[0xF];
    u8 intensity, enabled;
    u16 colour;
    u8 unknown34[4];
    u64 ownerIdentity;
    u8 unknown40[0xB0];
    float rotationX, rotationY, rotationZ;
} CtorObject;
extern void *func_0029EFD0(int);
extern float func_002A7878(float, float);
extern void func_002A0F48(void *);

/* Install the full position and owner identity before activating the new object. */
CtorObject *func_L01_003BC490(CtorObject *owner, const CtorVector *position)
{
    CtorObject *object = func_0029EFD0(0xA26);
    if (object != 0) {
        u8 intensity = owner->intensity;
        u16 colour = owner->colour;
        object->intensity = intensity;
        object->mode = 1;
        object->colour = colour;
        object->enabled = 1;
        qcopy(&object->position, position);
        object->rotationX = owner->rotationX;
        object->rotationY = owner->rotationY;
        object->rotationZ = func_002A7878(-3.1415927f, 3.1415927f);
        object->ownerIdentity = owner->ownerIdentity;
        func_002A0F48(object);
    }
    return object;
}
