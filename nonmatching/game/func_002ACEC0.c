/* func_002ACEC0 in its own unit: it copies a 128-bit vector with both
   addresses in registers, the compiler's opt-in grouped copy
   (config/cflags.txt gives this file -frac2-qcopy). */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_00282C48(void *, void *);
extern void func_00282F20(float *, float *, float);
extern void func_002AB668(float *, float *, float);
extern void func_002ACDE8(void *, void *, float *);

/* Blends dst towards src along the axis axis by amount; when the two are
   already (almost) the same point dst is just set to src. */
void func_002ACEC0(void *dst, void *src, float *axis, float amount)
{
    float v[4];

    if (func_00282C48(dst, src) < 1e-5f) {
        *(TI128 *)dst = *(TI128 *)src;
    } else {
        func_00282F20(v, axis, 1.0f);
        func_002AB668(v, v, amount);
        func_002ACDE8(dst, src, v);
    }
}
