#include "include_asm.h"
#include "common.h"

typedef int Quadword_0030DE88 __attribute__((mode(TI)));
typedef union {
    Quadword_0030DE88 bits;
    float f[4];
} Vec4_0030DE88;

extern float D_001AF044 __attribute__((sda));
extern char D_0018A550[];

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002A7A00(void *, float, float);
extern float func_00282C48(float);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern int func_0030CAA0(void);
extern void func_002C2210(void *, u32, u32, u32, s32, s32, s32, f32, f32, f32);

void func_0030DE88(u8 *obj, int count)
{
    Vec4_0030DE88 v;
    Vec4_0030DE88 w;
    int n;

    v.bits = 0;
    v.f[1] = -0.9f;
    func_00283098(&v, &v, obj + 0xC0);
    func_00282CC0(&v, &v, obj + 0x10);
    if (count > 0) {
        n = count;
        do {
            int r;
            float s;
            float t;
            func_002A7A00(&w, 0.0f, D_001AF044);
            n = n - 1;
            w.f[0] = func_00282C48(w.f[0]);
            func_00283098(&w, &w, D_0018A550);
            r = func_002A7820(-8, 8);
            s = func_002A7878(0.2f, 0.6f);
            t = s * 0.3f;
            func_002C2210(&v, 0xF, func_0030CAA0() | 0x7F000000, 0, r, (s32)&w, 0, t, s, 0.0f);
            func_002C2210(&v, 0xF, 0x307F7F7F, 0, -r, (s32)&w, 0, s * 0.15f, s * 0.5f, 0.0f);
        } while (n != 0);
    }
}
