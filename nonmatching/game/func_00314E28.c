/* Mid worker 11 near miss (func_00314E28).
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy.
   Status: every instruction equal to retail except the saved registers of the two pointer parameters: retail keeps target in s1 and origin in s0, ours the reverse. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern float func_002EE2B0(void);
extern void func_002EE138(float *, float *, float *);
extern void func_002EE3D0(float *, float *, float);
extern void func_002EE108(float *, float *, float *);
extern float func_002EE2E8(float *, float *);
extern float func_002EE7A8(float, float);
extern float func_002EE010(float);
extern float func_002EE6E0(float);
extern float func_002EE6F8(float);

void func_00314E28(float *target, float *origin, float *out, float g, float min_range, float limit) {
    float d[4] __attribute__((aligned(16)));
    float half = g * limit * 0.5f;
    float range;
    float rise;
    float yaw;
    float v;
    float t;

    if (limit < func_002EE2B0()) {
        func_002EE138(d, origin, target);
        func_002EE3D0(d, d, limit - 0.01f);
        func_002EE108(d, d, target);
    } else {
        *(TI128 *)d = *(TI128 *)origin;
    }
    range = func_002EE2E8(target, d);
    rise = d[2] - target[2];
    yaw = func_002EE7A8(d[0] - target[0], d[1] - target[1]);
    if (range < min_range) {
        range = min_range;
    }
    if (range <= rise) {
        rise = range - 0.01f;
    }
    t = g * range * range / (2.0f * (range - rise));
    if (half < t) {
        t = half;
    }
    v = func_002EE010(t);
    out[0] = func_002EE6E0(yaw) * v;
    out[1] = func_002EE6F8(yaw) * v;
    out[2] = v;
}
