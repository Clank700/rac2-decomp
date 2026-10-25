/* Nonmatching C: Dispatch the five object states, transfer the destination position and register the ring callback.
 * Tested profile: -O2 -G16 -Wa,-G16 -ffunction-sections.
 * Measured US size: 1000 bytes; retail: 1004 bytes.
 * Placement checks: US: 0/2; US2 and PAL: absent from their catalogues.
 * Remaining: Object/context register allocation, resident addressing and state-machine scheduling still differ.
 * Reopen with independent state and context lifetime evidence; retain the real 12-byte motion settings and the used compiler-owned const label table.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } Vector;
typedef struct { float acceleration, deceleration, speed; } MotionSettings;
extern int D_001A79F0 __attribute__((sda));
extern unsigned char D_0019B2E8[];
extern char *D_0018A15C;
extern short D_0018A16E;
extern unsigned int D_00138324;
extern int D_L13_001A8FB4 __attribute__((sda));
extern char *D_L13_001B291C;
extern unsigned char D_0018C0D5;
extern MotionSettings D_L13_001B16D8 __attribute__((sda));
extern void func_L13_0041BA60(char *);
extern int func_002E5CF8(int, int, char *);
extern void func_L00_002D40A0(Vector *, int, float);
extern int func_002A8C28(void *,void *,int,int,int,int,float,float,float);
extern int func_L00_002D40F0(void);
extern void func_L00_002B9D60(void *, void *, int, int);
extern void func_00288CB0(int, int);
extern void func_L13_0041BAE0(void *);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern float func_002AA2E8(float *, float, float);
extern float func_002AA548(float *, float *, float, float, float, float);

void func_L13_0041B670(char *object) {
    static void *const modes[5] = {&&idle, &&ready, &&waiting, &&opening, &&closing};
    float position[4] __attribute__((aligned(16)));
    char *state = *(char **)(object + 0x68);
    char *destination;
    char *target_state;
    int code;
    unsigned int mode;
    if (*(int *)(state + 0x38) == 0) return;
    mode = *(unsigned char *)(object + 0x20);
    if (mode < 5) goto *modes[mode];
    return;
ready:
    if (*(int *)(state + 8) >= 0 &&
        !(D_0019B2E8[*(int *)(state + 8) + D_001A79F0 * 16] & 0x80)) return;
    if (*(int *)state == -1 && *(int *)(state + 0x40) == 0 && *(int *)(state + 0x3C) == 0) return;
    if (D_0018A15C != object || D_0018A16E != 0) return;
    func_L13_0041BA60(object);
    if (!(D_00138324 & 0x10)) return;
    if (D_L13_001A8FB4 == 11) {
        func_002E5CF8(0, 0, object);
        *(unsigned char *)(object + 0x20) = 2;
        *(int *)(state + 0x2C) = 0;
        *(int *)(state + 0x28) = 0;
        func_L00_002D40A0((Vector *)(object + 0x10), 0, *(float *)(object + 0xF8));
        func_002A8C28(object,object+0x10,0x10000,0,1,0,1.5f,20.0f,1.0f);
    }
    return;
waiting:
    code = func_L00_002D40F0();
    if (code == 2) {
        *(float *)(state + 0x34) = 1.95f;
        *(unsigned char *)(object + 0x20) = 3;
    } else if (code == 0) {
        *(unsigned char *)(object + 0x20) = 4;
    }
    return;
opening:
    if (*(float *)(state + 0x34) == 0.0f) {
        if (*(int *)(state + 0x3C) == 0 && *(int *)(state + 0x40) == 0) {
            destination = D_L13_001B291C + *(int *)state * 256;
            if (*(int *)(state + 4) != -1 &&
                (D_0019B2E8[*(int *)(state + 0xC) + D_001A79F0 * 16] & 0x80))
                destination = D_L13_001B291C + *(int *)(state + 4) * 256;
            target_state = *(char **)(destination + 0x68);
            qcopy(position, destination + 0x10);
            position[2] += 0.2f;
            func_L00_002B9D60(position, destination + 0xF0, 0, 1);
            D_0018C0D5 = 1;
            *(unsigned char *)(destination + 0x20) = 4;
            *(float *)(target_state + 0x34) = 0.0f;
            *(int *)(target_state + 0x28) = 0;
            *(int *)(target_state + 0x2C) = 0;
            *(float *)(target_state + 0x24) = 1.0f;
            *(float *)(target_state + 0x20) = 1.0f;
            func_002E5CF8(1, 0, destination);
            *(unsigned char *)(object + 0x20) = 1;
            *(float *)(state + 0x34) = 1.95f;
            *(int *)(state + 0x20) = 0;
            *(int *)(state + 0x24) = 0;
            *(int *)(state + 0x28) = 0;
            *(int *)(state + 0x2C) = 0;
        } else {
            code = (*(int *)(state + 0x3C) && !*(int *)(state + 0x40)) ? 21 : 13;
            func_00288CB0(code, 1);
        }
        return;
    }
    func_L00_002E6CF0(func_L13_0041BAE0, object);
    func_002AA2E8((float *)(state + 0x34), 0.0f, 0.06666667f);
    return;
closing:
    if (*(float *)(state + 0x34) < 1.95f) {
        func_L00_002E6CF0(func_L13_0041BAE0, object);
        func_002AA2E8((float *)(state + 0x34), 1.95f, 0.06666667f);
        return;
    }
    if (*(float *)(state + 0x24) > 0.0f) {
        func_002AA548((float *)(state + 0x24), (float *)(state + 0x28), 0.0f,
            D_L13_001B16D8.acceleration * 0.00027777778f,
            D_L13_001B16D8.deceleration * 0.00027777778f,
            D_L13_001B16D8.speed * 0.016666668f);
        return;
    }
    if (*(float *)(state + 0x20) > 0.0f) {
        func_002AA548((float *)(state + 0x20), (float *)(state + 0x2C), 0.0f,
            D_L13_001B16D8.acceleration * 0.00027777778f,
            D_L13_001B16D8.deceleration * 0.00027777778f,
            D_L13_001B16D8.speed * 0.016666668f);
        return;
    }
idle:
    *(unsigned char *)(object + 0x20) = 1;
}
