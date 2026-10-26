/* Mid worker 11 near miss (func_L00_00417218).
   Profile: -O2 -G0 -ffunction-sections.
   Status: one instruction pair: retail hoists 0.0f into $f25 out of the loop (mtc1 $zero,$f25) and ours loads it inline; everything else equal. */
extern float func_002EE7A8(float, float);
extern float func_0031A820(float, float);
extern void func_002EF250(float);
extern float func_002EF0F8(float, float);
extern float func_002EE6E0(float);
extern float func_002EE6F8(float);
extern void func_L00_0033FFB8(void *, void *, int);
extern char D_L00_001A8F20[] __attribute__((sda));
extern struct { char pad[0x140]; float x, y; } D_L00_001B8C80;

void func_L00_00417218(char *object) {
    float v[8];
    float angle;
    int i;

    for (i = 24; i >= 0; i--) {
        angle = func_002EE7A8(D_L00_001B8C80.x - *(float *)(object + 0x10),
                              D_L00_001B8C80.y - *(float *)(object + 0x14));
        func_002EF250(func_0031A820(1.0f, 2.0f));
        v[0] = *(float *)(object + 0x10) + func_0031A820(-0.25f, 0.25f);
        v[1] = *(float *)(object + 0x14) + func_0031A820(-0.25f, 0.25f);
        v[2] = *(float *)(object + 0x18) + func_0031A820(-0.25f, 0.25f);
        angle = func_002EF0F8(angle, func_0031A820(0.0f, -1.5707964f));
        v[4] = func_002EE6E0(angle) * 0.016666668f * 4.0f;
        v[5] = func_002EE6F8(angle) * 0.016666668f * 4.0f;
        v[6] = 0.075f;
        func_L00_0033FFB8(v, D_L00_001A8F20, 300);
    }
}
