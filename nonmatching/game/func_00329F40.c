/* Near miss (mid-15): default -G0 flags, 496/496 bytes, registers and layout equal. Differences: the 0.0f compare loads the zero before the value (retail: lwc1 f1 value, mtc1 zero f0, nop, c.eq.s f1,f0) and cc1 fills the bc1f with a likely delay; D_001B22D0/D_001B22D8 are plain incomplete arrays (split lui/lw, retail uses tied lui a0 / lw a0,lo(a0)). */
#include "include_asm.h"

extern unsigned char *D_001BAF98[];
extern char D_001A63A8[];
extern char D_001B01F0[];
extern int D_001B22D0[];
extern int D_001B22D8[];

extern int func_002B6D28(void);
extern void func_002A8598(int, int);
extern void func_0026FEB8(const char *, ...);
extern int func_002FD828(float *, float *, float, float, float);
extern void func_002FD1B8(float, float, float, float, int, int, int);
extern int func_0026F800(void);

void func_00329F40(char *self)
{
    unsigned char *target = D_001BAF98[0];
    char *state = *(char **)(self + 0x68);
    unsigned char *object;
    unsigned char *obj_state;
    float aux[4];
    float result[4];
    char *context;
    int mode;

    if (target == 0) {
        if (*(int *)(state + 0x38) != 2)
            return;
    }
    mode = *(int *)(state + 0x38);
    object = target;
    if (mode == 2)
        object = *(unsigned char **)(state + 0x48);
    if (*(short *)(*(char **)(object + 0x24) + 0x46) == 18) {
        obj_state = *(unsigned char **)(object + 0x68);
        if (obj_state != 0) {
            if (*(short *)(obj_state + 0x16) == 0) {
                *(int *)&result[0] = 0;
                if (mode != 2)
                    func_002FD828(result, aux, *(float *)(self + 0x10), *(float *)(self + 0x14), *(float *)(self + 0x18));
                else
                    func_002FD828(result, aux, *(float *)(state + 0x20), *(float *)(state + 0x24), *(float *)(state + 0x28));
                if (*(float *)(self + 0x18) > result[0] && *(float *)(*(char **)(object + 0x68) + 0xC) == 0.0f) {
                    *(unsigned char **)(state + 0x48) = object;
                    *(int *)(state + 0x38) = 2;
                    return;
                }
                if (obj_state[0x14] == 0) {
                    func_002FD1B8(*(float *)(self + 0x10), *(float *)(self + 0x14), 0.5f, -0.03f, D_001B22D0[0], D_001B22D8[0], 1);
                    if (func_0026F800() == 0) {
                        object[0xBC] += 1;
                        if (object[0xBC] >= 25) {
                            context = D_001A63A8;
                            if (*(short *)(context + 0x72) == 3 && *(short *)(context + 0x6C) < 6000)
                                func_002B6D28();
                        }
                        if (object[0x21] != 255)
                            func_002A8598(object[0x21], object[0xBC]);
                    }
                }
                *(int *)(state + 0x44) = 0;
            } else {
                *(int *)(state + 0x44) = 1;
            }
        } else {
            func_0026FEB8(D_001B01F0, *(short *)(object + 0xAA));
        }
        *(int *)(state + 0x38) = 1;
    } else {
        *(int *)(state + 0x38) = 0;
    }
}
