/* wave 6 lvl-04 batch 1: candidates with retail disassembly in hand */

extern char D_L01_00189E20[];
extern char D_L01_00139A28[];
extern char D_L01_002637A0[];
extern char D_L01_001A79F0;
extern float D_L01_001A7DC0;
extern void func_2B4380(int a0, float f12);
extern int func_2AE958(int a0);
extern void func_3022C8(void *a0, void *a1, int a2);
extern int D_L01_001A90C8 __attribute__((sda));
extern float D_L01_001A90C4 __attribute__((sda));
extern int D_L01_001A90D0 __attribute__((sda));
extern int D_L01_001A90CC __attribute__((sda));
extern int D_L01_001ADF40[8] __attribute__((sda));

/* ---------------- func_L01_002B46A0 (100 bytes, 5 places) ---------------- */
void func_L01_002B46A0(void) {
    float v;
    func_2B4380(0, 1.0f);
    v = *(float *)(D_L01_00189E20 + 0x1B0);
    if (v > 0.0f)
        *(float *)(D_L01_00189E20 + 0x1B0) =
            D_L01_001A7DC0 * (*(float *)(D_L01_00189E20 + 0x24B8) * (1.0f / 60.0f));
}

void func_L01_002B46A0_v1(void) {
    char *b = D_L01_00189E20;
    float v;
    func_2B4380(0, 1.0f);
    v = *(float *)(b + 0x1B0);
    if (v > 0.0f)
        *(float *)(b + 0x1B0) = D_L01_001A7DC0 * (*(float *)(b + 0x24B8) * (1.0f / 60.0f));
}

void func_L01_002B46A0_v2(void) {
    char *b = D_L01_00189E20;
    float v;
    float t;
    func_2B4380(0, 1.0f);
    v = *(float *)(b + 0x1B0);
    if (v > 0.0f) {
        t = *(float *)(b + 0x24B8) * (1.0f / 60.0f);
        *(float *)(b + 0x1B0) = D_L01_001A7DC0 * t;
    }
}

void func_L01_002B46A0_v3(void) {
    float v;
    func_2B4380(0, 1.0f);
    v = *(float *)(D_L01_00189E20 + 0x1B0);
    if (v > 0.0f) {
        float t = *(float *)(D_L01_00189E20 + 0x24B8) * (1.0f / 60.0f);
        *(float *)(D_L01_00189E20 + 0x1B0) = D_L01_001A7DC0 * t;
    }
}

/* ---------------- func_L01_002F14E8 (156 bytes, 5 places) ---------------- */
void func_L01_002F14E8(int a0, int a1, float f12) {
    float v = f12;
    if (D_L01_001A90C8 == 0)
        func_3022C8((void *)0x002F1888, (void *)0x002F1588, 0);
    D_L01_001A90C8 = 5;
    D_L01_001A90C4 = v;
    if (v > 1.0f)
        D_L01_001A90C4 = 1.0f;
    else if (v < 0.0f)
        D_L01_001A90C4 = 0.0f;
    D_L01_001A90D0 = a1;
    D_L01_001A90CC = a0;
}

void func_L01_002F14E8_v1(int a0, int a1, float f12) {
    if (D_L01_001A90C8 == 0)
        func_3022C8((void *)0x002F1888, (void *)0x002F1588, 0);
    D_L01_001A90C8 = 5;
    D_L01_001A90C4 = f12;
    if (f12 > 1.0f)
        D_L01_001A90C4 = 1.0f;
    else if (f12 < 0.0f)
        D_L01_001A90C4 = 0.0f;
    D_L01_001A90D0 = a1;
    D_L01_001A90CC = a0;
}

void func_L01_002F14E8_v2(int a0, int a1, float f12) {
    float v = f12;
    if (D_L01_001A90C8 == 0)
        func_3022C8((void *)0x002F1888, (void *)0x002F1588, 0);
    D_L01_001A90C8 = 5;
    D_L01_001A90C4 = v;
    if (v > 1.0f)
        D_L01_001A90C4 = 1.0f;
    if (v < 0.0f)
        D_L01_001A90C4 = 0.0f;
    D_L01_001A90D0 = a1;
    D_L01_001A90CC = a0;
}

/* ---------------- func_L01_00367F78 (92 bytes, 17 places) ---------------- */
void func_L01_00367F78(void) {
    char *b = D_L01_00139A28;
    int k = D_L01_001A79F0;
    int *p = D_L01_001ADF40;
    int n = 1;

    while (n < 5) {
        if (k == *p && n < 8)
            *(unsigned char *)(b + 0x8D) |= 1 << n;
        n++;
        p++;
    }
}

void func_L01_00367F78_v1(void) {
    char *b = D_L01_00139A28;
    int k = D_L01_001A79F0;
    int *p = D_L01_001ADF40;
    int n = 1;

    do {
        if (k == p[0] && n < 8)
            *(unsigned char *)(b + 0x8D) |= 1 << n;
        n++;
        p++;
    } while (n < 5);
}

void func_L01_00367F78_v2(void) {
    unsigned char *f = (unsigned char *)D_L01_00139A28 + 0x8D;
    int k = D_L01_001A79F0;
    int *p = D_L01_001ADF40;
    int n = 1;

    while (n < 5) {
        if (k == *p && n < 8)
            *f |= 1 << n;
        n++;
        p++;
    }
}

/* ---------------- func_L01_002A7248 (128 bytes, 4 places) ---------------- */
int func_L01_002A7248(int a0) {
    char *b = D_L01_00189E20;
    if (a0 != 0 && *(unsigned char *)(b + 0x22BA) != 0 && *(short *)(b + 0x24EC) == 0) {
        unsigned char c = *(unsigned char *)(D_L01_00139A28 + func_2AE958(0));
        return *(int *)(D_L01_002637A0 + c * 0xE0 + 0x28);
    }
    return *(int *)(b + 0x24CC) == 1 ? 0x51 : 0;
}

int func_L01_002A7248_v1(int a0) {
    char *b = D_L01_00189E20;
    int r = 0x51;
    if (a0 != 0 && *(unsigned char *)(b + 0x22BA) != 0 && *(short *)(b + 0x24EC) == 0) {
        unsigned char c = *(unsigned char *)(D_L01_00139A28 + func_2AE958(0));
        return *(int *)(D_L01_002637A0 + c * 0xE0 + 0x28);
    }
    if (*(int *)(b + 0x24CC) != 1)
        r = 0;
    return r;
}

int func_L01_002A7248_v2(int a0) {
    char *b = D_L01_00189E20;
    if (a0 != 0) {
        if (*(unsigned char *)(b + 0x22BA) != 0) {
            if (*(short *)(b + 0x24EC) == 0) {
                unsigned char c = *(unsigned char *)(D_L01_00139A28 + func_2AE958(0));
                return *(int *)(D_L01_002637A0 + c * 0xE0 + 0x28);
            }
        }
    }
    return *(int *)(b + 0x24CC) == 1 ? 0x51 : 0;
}
