/*
 * Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 200 bytes; compiled: 200 bytes.
 * Final coverage: us: 0/1; us2: 0/1; pal: 0/1.
 * Residual: 200/200 bytes with the actual 16-byte vector, 48-byte matrix and 4-byte
 * damping state at offsets 0,0x10,0x40. The old pi constant and false extra GPR input to
 * the float absolute-value call are repaired. Five FP/GPR argument-setup words at
 * +0x50,+0x58,+0x60,+0x84,+0x88 still differ.
 * Reopen: A measured lifetime/scheduler witness for the truthful grouped argument setup
 * of func_002AAA00 and func_00283738. Separate versus combined damping storage and
 * explicit rotation pointers tied.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vector;

extern float func_002B04E0(char *, float *, char *);
extern void func_002AAA00(int *, float *, int, float, float, float, float);
extern void func_002833F0(void *, void *);
extern void func_00283738(void *, void *, void *);
extern float func_00282C48(float);

float func_L14_003D18C8(char *object, char *state, TI128 *input, char *transform) {
    /* Rotation construction writes three full rows after the local vector. */
    struct { Vector vector; TI128 matrix[3]; int damping; } work;
    TI128 *rotation;
    float value;
    work.vector.q = *input;
    value = func_002B04E0(object, work.vector.f, transform);
    work.damping = 0;
    func_002AAA00(&work.damping, (float *)(state + 0xB4), 0, value,
                 *(float *)(state + 0x14), *(float *)(state + 0x18), 3.141592653589793f);
    qzero(&work.vector);
    work.vector.f[2] = *(float *)(state + 0xB4);
    rotation = work.matrix;
    func_002833F0(rotation, &work.vector);
    object += 0xC0;
    func_00283738(object, object, rotation);
    value = func_00282C48(value);
    return value - func_00282C48(*(float *)(state + 0xB4));
}
