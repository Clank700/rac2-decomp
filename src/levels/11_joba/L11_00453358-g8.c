#include "common.h"

/* Small-data unit: the bodies whose state lives at $gp-relative offsets. */

extern void func_00281EB8(void *a0, void *a1, void *a2, float f12, float f13, float f14,
                          int a3);

extern float func_002A7940(void);

extern int func_002A7820(int a0, int a1);

extern float func_002A7878(float a, float b);

extern void func_L11_00458DF0(char *a0, void *a1, void *a2, int a3, int t0, float f12,
                              float f13);

extern void func_00282F20(char *a0, void *a1, float f12);

extern void func_002AB668(void *a0, void *a1, float f12);

extern void func_00282D30(char *a0, void *a1, float f12);

extern void func_002ACDE8(void *a0, void *a1, void *a2);

extern void func_00282CC0(void *a0, void *a1, void *a2);

extern float func_00283BE0(float a, float b);

extern void func_L00_002E6CF0(void *a0, void *a1);

extern void func_L11_00459E48(char *p);

extern void func_L11_00459EA0(char *p);

extern void func_L11_0045A8C0(char *p, float *v);

extern void func_00282D08(float *out, char *a, char *b, float k);

extern float func_00282E80(char *p, float *v);

extern float func_00283248(float a, float b);

extern void func_00283410(float *matrix, float *quat);

extern void func_00280B90(char *pkt, float *matrix, int mode);

extern int func_001163B0(void);

extern int D_L11_001B2014 __attribute__((sda));

extern int D_L11_001B2020 __attribute__((sda));

/* The vector the aim helpers read, at 0x001BA780 in joba. */
typedef struct {
    char pad_000[0x140];
    float x_140;
    float y_144;
    float z_148;
} L11AimVector;

extern L11AimVector D_L11_001BA780;

extern void *D_L11_001B1DB4 __attribute__((sda));

extern void *D_L11_001B1DB8 __attribute__((sda));

extern float D_L11_001B1DBC __attribute__((sda));

extern void *D_L11_001B1FBC __attribute__((sda));

extern void *D_L11_001B1FC0 __attribute__((sda));

extern float D_L11_001B1FC8 __attribute__((sda));

extern float D_L11_001B1FCC __attribute__((sda));

extern float D_L11_001B1FFC __attribute__((sda));


/* Rebuilds the state's offset block from its rotation and installs the next handler. */
void func_L11_00459D48(char *p)
{
    char *q = *(char **)(p + 0x68);
    float v[4];

    func_00282F20((char *)v, q + 0x40, 1.0f);
    func_002AB668(v, v, *(float *)(q + 0x30));
    func_00282D30(q + 0x10, q, *(float *)(q + 0x60));
    func_002ACDE8(q + 0x10, q + 0x10, v);
    *(float *)(q + 0x20) = -*(float *)(q + 0x10);
    *(float *)(q + 0x24) = -*(float *)(q + 0x14);
    *(float *)(q + 0x28) = -*(float *)(q + 0x18);
    func_00282CC0(q + 0x10, p + 0x10, q + 0x10);
    func_00282CC0(q + 0x20, p + 0x10, q + 0x20);
    *(float *)(q + 0x30) = func_00283BE0(*(float *)(q + 0x30),
                                         D_L11_001B1FFC * 0.000290888245f);
    func_L00_002E6CF0(func_L11_00459E48, p);
}

/* Aims the object's stage at the level's aim vector and dispatches the resulting packet. */
void func_L11_0045A578(char *p)
{
    char pkt[144];
    float m[16];
    float quat[4];
    float v[4];
    char *q = *(char **)(p + 0x68);
    float s;
    int r;
    int top;

    func_L11_00459EA0(pkt);
    func_00282D08(v, q + 0x10, q + 0x20, func_002A7878(0.0f, 1.0f));

    v[0] += func_002A7878(-0.1f, 0.1f) * *(float *)(q + 0x60);
    v[1] += func_002A7878(-0.1f, 0.1f) * *(float *)(q + 0x60);
    v[2] += func_002A7878(-0.1f, 0.1f) * *(float *)(q + 0x60);

    *(long long *)(pkt + 120) = func_0027C878((char *)0xB);
    *(long long *)(pkt + 128) = 0x0000FF9000000260LL;
    *(long long *)(pkt + 112) = 0LL;

    r = func_001163B0();
    *(long long *)(pkt + 136) = ((long long)((r % 2) + 1) << 2) | 0x8000000040LL;
    top = func_002A7820(0x40, 0x7F) << 24;
    *(int *)(pkt + 76) = (D_L11_001B2014 & 0xFFFFFF) + top;
    *(int *)(pkt + 72) = (D_L11_001B2014 & 0xFFFFFF) + top;
    *(int *)(pkt + 68) = (D_L11_001B2014 & 0xFFFFFF) + top;
    *(int *)(pkt + 64) = (D_L11_001B2014 & 0xFFFFFF) + top;

    quat[3] = 0.0f;
    quat[2] = func_00283248(D_L11_001BA780.x_140 - v[0], D_L11_001BA780.y_144 - v[1]);
    quat[1] = -func_00283248(func_00282E80((char *)v, &D_L11_001BA780.x_140),
                             D_L11_001BA780.z_148 - v[2]);
    quat[0] = func_002A7940();
    func_00283410(m, quat);

    m[12] = v[0];
    m[13] = v[1];
    m[14] = v[2];
    m[15] = 1.0f;

    s = func_002A7878(0.05f, 0.15f) * *(float *)(q + 0x60);
    func_00282D30(pkt, pkt, s);
    func_00282D30(pkt + 16, pkt + 16, s);
    func_00282D30(pkt + 32, pkt + 32, s);
    func_00282D30(pkt + 48, pkt + 48, s);
    func_00280B90(pkt, m, 0);

    *(int *)(pkt + 76) = (D_L11_001B2020 & 0xFFFFFF) + top;
    *(int *)(pkt + 72) = (D_L11_001B2020 & 0xFFFFFF) + top;
    *(int *)(pkt + 68) = (D_L11_001B2020 & 0xFFFFFF) + top;
    *(int *)(pkt + 64) = (D_L11_001B2020 & 0xFFFFFF) + top;

    func_00282D30(pkt, pkt, 0.5f);
    func_00282D30(pkt + 16, pkt + 16, 0.5f);
    func_00282D30(pkt + 32, pkt + 32, 0.5f);
    func_00282D30(pkt + 48, pkt + 48, 0.5f);
    func_00280B90(pkt, m, 0);

    func_L11_0045A8C0(p, v);
}
