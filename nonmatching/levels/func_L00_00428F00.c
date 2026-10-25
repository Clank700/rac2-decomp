/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * 232/232 bytes; 0/27 placements in us and us2; pal has no catalogue entry.
 * Residual: Guard branch targets, the mode-store call slot and final clear/restore scheduling differ.
 * Reopen: Independent source-level control-flow or scheduling evidence for the guards and final stores.
 * Trial source markers and per-file flags are restored after checking.
 */

#include "common.h"
typedef struct {
    u8 unknown0000[0xAA4];
    int identityAA4;
    u8 unknown0AA8[0x2C];
    int identityAD4;
    u8 unknown0AD8[0x17BC];
    int mode;
} ResidentState;
extern ResidentState D_00189E20;
typedef struct {
    u8 unknown000[0x194];
    u8 *transform;
    u8 unknown198[0x17C];
    int mode;
} WorldState;
extern WorldState D_L00_001C8C80;
extern void func_L00_00428588(void *);
extern void func_L00_00428EB0(void *);
extern void func_L00_002DA1E0(void *, float);

/* Saves the owner's four aligned transform rows when the selected identity changes,
 * then refreshes the mode and fades the translation row. */
void func_L00_00428F00(u8 *owner)
{
    u8 *state = *(u8 **)(owner + 0x70) + 0xB8;
    int mode = D_00189E20.mode;
    u8 *translation;
    int current;
    int selected;
    u8 *world;
    if (mode == 0x2B) {
        current = *(int *)(state + 8);
        translation = owner + 0x30;
        selected = D_00189E20.identityAD4;
    } else if ((unsigned int)(mode - 0x23) < 3) {
        current = *(int *)(state + 8);
        translation = owner + 0x30;
        selected = D_00189E20.identityAA4;
    } else {
        return;
    }
    if (current != selected) {
        world = D_L00_001C8C80.transform;
        qcopy(world + 0x30, translation);
        qcopy(world, owner);
        qcopy(world + 0x10, owner + 0x10);
        qcopy(world + 0x20, owner + 0x20);
        func_L00_00428588(owner);
        D_L00_001C8C80.mode = 0x2D;
        func_L00_00428EB0(owner);
        func_L00_002DA1E0(translation, 0.5f);
        *(int *)(*(u8 **)(owner + 0x70) + 0x80) = 0;
    }
}
