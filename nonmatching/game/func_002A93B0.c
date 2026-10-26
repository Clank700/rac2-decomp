#include "common.h"
/* func_002A93B0 (404 bytes, boot only), mid worker 1, 25 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses (the integer global read
 * lui $v0 / lw $v0,lo($v0) only comes out with that flag, so it needs a file of its own).
 * 408/404 bytes: control flow, the shared o[0x70]/o[0x74] store tail and the 0x70/0x74 zero
 * stores in retail order are all right. Remaining: the float global at 0x1BAFA8 is read by
 * retail as `lui $v0,0x1C` (in the delay slot of the beqz) + `lwc1 $f0,-0x5058($v0)`, while
 * -mno-split-addresses emits `lui $at` + `lwc1`; the beqz also comes out as beql with the
 * zero store in its slot. Tried: scalar, incomplete array, [2] of the vector, pointer local.
 */

extern int D_001A8CA0[];
extern float D_001BAFA0[];
extern float D_001BAFA8[];
extern void func_00282D60(float, float *, char *);
extern void func_00282D30(float, float *, float *);
extern void func_00282CC0(float *, float *, float *);
extern void func_00282CF0(float *, float *, char *);
extern float func_00282DB0(float *, float *);
extern int func_002761F8(float *, float *, int, int, int);

void func_002A93B0(char *o)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    float c[4] __attribute__((aligned(16)));
    float x;
    float y;

    if (D_001A8CA0[0] == 0) {
        if (*(float *)(o + 0xE8) < 0.9f) {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
            return;
        }
        qcopy(a, o + 0x10);
        a[2] = a[2] - 16.0f;
        if (a[2] < 0.5f)
            a[2] = 0.5f;
        qcopy(b, o + 0x10);
        b[2] = b[2] + 0.5f;
        if (func_002761F8(b, a, 0x22, 0, 0) != 0) {
            y = *(float *)(o + 0xC) * 0.000244140625f;
            x = D_001BAFA0[2] - *(float *)(o + 0x18);
            goto store;
        } else {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
        }
    } else {
        func_00282D60(0.0009765625f, a, o);
        func_00282D30(-8.0f, b, (float *)(o + 0xE0));
        func_00282CC0(b, a, b);
        if (func_002761F8(a, b, 0x22, 0, 0) != 0) {
            func_00282CF0(c, D_001BAFA0, o + 0x10);
            x = func_00282DB0(c, (float *)(o + 0xE0));
            *(unsigned char *)(o + 0xBD) = 0xFF;
            y = 0.2f;
        store:
            *(float *)(o + 0x70) = x;
            *(float *)(o + 0x74) = y;
        } else {
            *(float *)(o + 0x70) = 0.0f;
            *(float *)(o + 0x74) = 0.0f;
        }
    }
}
