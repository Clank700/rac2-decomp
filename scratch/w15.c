typedef char s8;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));

extern float func_00283180(char *a, char *b, float f);
extern float func_00283198(float f);
extern void func_L04_0033CC00(char *a, char *b, float *v, float *w, float f);

/* u1: source pointer taken first, TI128 copy */
void u1(char *a0, char *a1) {
    float v[4];
    float w[4];
    float *src = (float *)(a0 + 0x10);

    *(TI128 *)v = *(TI128 *)src;
    v[0] += func_00283180(a0, a1, *(float *)(a0 + 0xF8)) * 100.0f;
    v[1] += func_00283198(*(float *)(a0 + 0xF8)) * 100.0f;
    func_L04_0033CC00(a0, a1, v, w, 1.0f);
}

/* u2: the copy written element-wise through the pointer */
void u2(char *a0, char *a1) {
    float v[4];
    float w[4];
    float *src = (float *)(a0 + 0x10);
    s32 i;

    for (i = 0; i < 4; i++)
        v[i] = src[i];
    v[0] += func_00283180(a0, a1, *(float *)(a0 + 0xF8)) * 100.0f;
    v[1] += func_00283198(*(float *)(a0 + 0xF8)) * 100.0f;
    func_L04_0033CC00(a0, a1, v, w, 1.0f);
}

/* u3: copy straight from the object, no named source pointer */
void u3(char *a0, char *a1) {
    float v[4];
    float w[4];

    *(TI128 *)v = *(TI128 *)(a0 + 0x10);
    v[0] += func_00283180(a0, a1, *(float *)(a0 + 0xF8)) * 100.0f;
    v[1] += func_00283198(*(float *)(a0 + 0xF8)) * 100.0f;
    func_L04_0033CC00(a0, a1, v, w, 1.0f);
}
