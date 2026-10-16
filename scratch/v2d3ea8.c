/* shape variants for func_L00_002D3EA8 (retail: 136 bytes, 34 instructions) */
typedef int V4 __attribute__((mode(TI)));

typedef struct {
    float f0;
    float f1;
    float f2;
    float f3;
} Q;

extern char g_base[];

extern float func_2EE268(char *);
extern float func_2EE7A8(float, float);
extern void func_2EE5D8(void *, void *, char *);

float a1(char *in)
{
    char *p = g_base;
    int mode = *(unsigned char *)(p + 8899);
    V4 local;

    if (mode == 0)
        return func_2EE7A8(*(float *)(in + 8), func_2EE268(in));
    if (mode < 0)
        return 0.0f;
    if (mode >= 3)
        return 0.0f;
    local = *(V4 *)in;
    func_2EE5D8(&local, &local, p + 64);
    return func_2EE7A8(*(float *)((char *)&local + 8), func_2EE268((char *)&local));
}

float a2(char *in)
{
    char *p = g_base;
    int mode = *(unsigned char *)(p + 8899);
    V4 local = *(V4 *)in;

    if (mode == 0)
        return func_2EE7A8(*(float *)(in + 8), func_2EE268(in));
    if (mode < 0)
        return 0.0f;
    if (mode >= 3)
        return 0.0f;
    func_2EE5D8(&local, &local, p + 64);
    return func_2EE7A8(*(float *)((char *)&local + 8), func_2EE268((char *)&local));
}

float a3(char *in)
{
    char *p = g_base;
    int mode = *(unsigned char *)(p + 8899);
    Q local;

    if (mode == 0)
        return func_2EE7A8(*(float *)(in + 8), func_2EE268(in));
    if (mode < 0)
        return 0.0f;
    if (mode >= 3)
        return 0.0f;
    local = *(Q *)in;
    func_2EE5D8(&local, &local, p + 64);
    return func_2EE7A8(local.f2, func_2EE268((char *)&local));
}

float a4(char *in)
{
    char *p = g_base;
    int mode = *(unsigned char *)(p + 8899);
    float local[4];

    if (mode == 0)
        return func_2EE7A8(*(float *)(in + 8), func_2EE268(in));
    if (mode < 0)
        return 0.0f;
    if (mode >= 3)
        return 0.0f;
    *(V4 *)local = *(V4 *)in;
    func_2EE5D8(local, local, p + 64);
    return func_2EE7A8(local[2], func_2EE268((char *)local));
}
