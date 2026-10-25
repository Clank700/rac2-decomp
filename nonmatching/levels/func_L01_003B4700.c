/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 728/728 bytes; 0/1 USA v1.01 and USA v2.00 places.
 * The canonical function is absent from the PAL catalogue.
 * Remaining: The measured early GP and final absolute reads of the one object-table pointer
 * now use honest same-symbol extern views. All preceding code agrees; at +0x27C
 * the attached pointer and subsequent LUI temporary exchange registers.
 * Reopen with: Independent tail-pointer lifetime evidence. No-split-addresses falls back
 * to GP access; a pointer-to-256-byte-slot difference gives identical bytes.
 */

#include "common.h"
typedef int OozlaQuad __attribute__((mode(TI)));
extern char *D_L01_001B255C __attribute__((sda));
/* Retail uses both GP-relative and absolute accesses to this one pointer. */
extern char *oozla_objects_absolute __asm__("D_L01_001B255C") NOT_SDA;
extern float func_00282E80(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282FB8(void *, void *, float);
extern void func_00283698(void *, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
void func_L01_003B4700(char *object)
{
    float position[4], offset[4], matrix[16];
    char *state = *(char **)(object + 0x68);
    char *target;
    int index = *(int *)(state + 0x384);
    if (index != -1) {
        target = D_L01_001B255C + (index << 8);
        if (target == 0) return;
        if (*(short *)(target + 0xAA) == 0xA56) {
            if (func_00282E80(object + 0x10, target + 0x10) > 1.0f) {
                func_00282CF0(offset, object + 0x10, target + 0x10);
                func_00282F20(offset, offset, 1.0f);
                func_00282CC0(position, target + 0x10, offset);
            } else {
                qcopy(position, (object + 0x10));
            }
            if (position[2] < *(float *)(target + 0x18) + 0.01f)
                position[2] = *(float *)(target + 0x18) + 0.011f;
        } else if (*(short *)(target + 0xAA) == 0xA53) {
            func_00283698(matrix, target + 0xC0);
            func_00282CF0(offset, object + 0x10, target + 0x10);
            func_002830C0(offset, offset, matrix);
            if (offset[0] > 2.0f) offset[0] = 2.0f;
            else if (offset[0] < -2.0f) offset[0] = -2.0f;
            if (offset[1] > 5.0f) offset[1] = 5.0f;
            else if (offset[1] < -5.0f) offset[1] = -5.0f;
            if (offset[2] < 0.01f) offset[2] = 0.01f;
            func_00283098(offset, offset, target + 0xC0);
            func_00282CC0(position, target + 0x10, offset);
        } else {
            qcopy(position, (object + 0x10));
        }
        func_00282CF0(offset, position, object + 0x10);
        func_00282FB8(offset, offset, 0.10000001f);
        func_00282CC0(object + 0x10, object + 0x10, offset);
    } else {
        char *attached = *(char **)(state + 0x198);
        if (attached && (*(short *)(attached + 0xAA) == 0xA56 || *(short *)(attached + 0xAA) == 0xA53))
            *(int *)(state + 0x384) = (attached - oozla_objects_absolute) >> 8;
    }
}
