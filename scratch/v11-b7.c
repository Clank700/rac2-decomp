/* worker lvl6-11 -- round 7: func_L23_0041E5B0 with a 16-byte-aligned vector type. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct {
    u32 w[4];
} __attribute__((aligned(16))) V16;

extern void func_002A8F70(void *, void *, void *, f32, V16 *);
extern void func_002A90C8(void *, void *, void *, f32, V16 *);
extern s32 D_L23_001B13D4 __attribute__((sda));

/* f2: aligned copy (retail copies with lq/sq) */
void f2(void *a0, s32 a1, s32 a2, V16 *a3, s32 a4, s32 a5) {
    V16 v = *a3;

    if (a4 == 0)
        func_002A8F70((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    else
        func_002A90C8((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    if ((a1 & 4) != 0 || a5 != 0)
        *(s32 *)0x001B3718 = D_L23_001B13D4;
}

/* f3: same with the vector declared first and the float conversion through a local */
void f3(void *a0, s32 a1, s32 a2, V16 *a3, s32 a4, s32 a5) {
    V16 v = *a3;
    f32 f = (f32)a2;

    if (a4 == 0)
        func_002A8F70((void *)0x0018C0B0, a0, (void *)a1, f, &v);
    else
        func_002A90C8((void *)0x0018C0B0, a0, (void *)a1, f, &v);
    if ((a1 & 4) != 0 || a5 != 0)
        *(s32 *)0x001B3718 = D_L23_001B13D4;
}

/* f4: unaligned-looking source (retail's lq/sq kept by a union read) */
typedef union {
    u32 w[4];
    f32 f[4];
} __attribute__((aligned(16))) V16U;

extern void func_002A8F70u(void *, void *, void *, f32, V16U *);
extern void func_002A90C8u(void *, void *, void *, f32, V16U *);

void f4(void *a0, s32 a1, s32 a2, V16U *a3, s32 a4, s32 a5) {
    V16U v = *a3;

    if (a4 == 0)
        func_002A8F70u((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    else
        func_002A90C8u((void *)0x0018C0B0, a0, (void *)a1, (f32)a2, &v);
    if ((a1 & 4) != 0 || a5 != 0)
        *(s32 *)0x001B3718 = D_L23_001B13D4;
}
