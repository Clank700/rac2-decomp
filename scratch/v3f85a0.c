/* store-order variants for func_L22_003F85A0 */
typedef unsigned char u8;
typedef float f32;
typedef int V4 __attribute__((mode(TI)));

extern u8 *func_315688(int);
extern void func_3180D8(u8 *);
extern f32 g_f;

u8 *b1(int a0, u8 *a1)
{
    u8 *o = func_315688(3413);
    if (o != 0) {
        u8 *p;
        *(u8 *)(o + 49) = 1;
        *(u8 *)(o + 48) = 0xFF;
        *(unsigned short *)(o + 50) = 0xFF;
        *(u8 *)(o + 32) = 0;
        *(f32 *)(o + 44) = *(f32 *)(*(int *)(o + 36) + 36) * g_f;
        p = *(u8 **)(o + 104);
        *(int *)(p + 16) = a0;
        *(V4 *)p = *(V4 *)a1;
        *(V4 *)(o + 16) = *(V4 *)a1;
        *(int *)(p + 20) = 0;
        func_3180D8(o);
    }
    return o;
}

u8 *b2(int a0, u8 *a1)
{
    u8 *o = func_315688(3413);
    if (o != 0) {
        u8 *p;
        *(u8 *)(o + 49) = 1;
        *(unsigned short *)(o + 50) = 0xFF;
        *(u8 *)(o + 48) = 0xFF;
        *(u8 *)(o + 32) = 0;
        *(f32 *)(o + 44) = *(f32 *)(*(int *)(o + 36) + 36) * g_f;
        p = *(u8 **)(o + 104);
        *(int *)(p + 16) = a0;
        *(V4 *)p = *(V4 *)a1;
        *(V4 *)(o + 16) = *(V4 *)a1;
        *(int *)(p + 20) = 0;
        func_3180D8(o);
    }
    return o;
}

u8 *b3(int a0, u8 *a1)
{
    u8 *o = func_315688(3413);
    if (o != 0) {
        u8 *p;
        *(u8 *)(o + 48) = 0xFF;
        *(u8 *)(o + 49) = 1;
        *(unsigned short *)(o + 50) = 0xFF;
        *(u8 *)(o + 32) = 0;
        *(f32 *)(o + 44) = *(f32 *)(*(int *)(o + 36) + 36) * g_f;
        p = *(u8 **)(o + 104);
        *(int *)(p + 16) = a0;
        *(V4 *)p = *(V4 *)a1;
        *(V4 *)(o + 16) = *(V4 *)a1;
        *(int *)(p + 20) = 0;
        func_3180D8(o);
    }
    return o;
}

u8 *b4(int a0, u8 *a1)
{
    u8 *o = func_315688(3413);
    if (o != 0) {
        u8 *p;
        *(u8 *)(o + 49) = 1;
        *(u8 *)(o + 48) = 0xFF;
        *(u8 *)(o + 32) = 0;
        *(unsigned short *)(o + 50) = 0xFF;
        *(f32 *)(o + 44) = *(f32 *)(*(int *)(o + 36) + 36) * g_f;
        p = *(u8 **)(o + 104);
        *(int *)(p + 16) = a0;
        *(V4 *)p = *(V4 *)a1;
        *(V4 *)(o + 16) = *(V4 *)a1;
        *(int *)(p + 20) = 0;
        func_3180D8(o);
    }
    return o;
}
