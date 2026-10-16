/* wave 6 lvl-04 batch 3: targeted fixes from the batch1/batch2 diffs */

extern char D_L01_00189E20[];
extern float D_L01_001A7DC0;
extern void func_2B4380(int a0, float f12);

/* ---------------- func_L01_002B46A0: retail keeps the BASE in $v0 and uses both
   0x1B0 and 0x24B8 off it, so the base must not be a CSE'd field address -------- */
void func_L01_002B46A0_v4(void) {
    char *b;
    float v;
    func_2B4380(0, 1.0f);
    b = D_L01_00189E20;
    v = *(float *)(b + 0x1B0);
    if (v > 0.0f)
        *(float *)(b + 0x1B0) = D_L01_001A7DC0 * (*(float *)(b + 0x24B8) * (1.0f / 60.0f));
}

void func_L01_002B46A0_v5(void) {
    char *b;
    float v;
    float t;
    func_2B4380(0, 1.0f);
    b = D_L01_00189E20;
    v = *(float *)(b + 0x1B0);
    if (v > 0.0f) {
        t = *(float *)(b + 0x24B8) * (1.0f / 60.0f);
        *(float *)(b + 0x1B0) = D_L01_001A7DC0 * t;
    }
}

/* ---------------- func_L01_002F14E8: the same file already reaches $gp through
   section(".sdata") (see the r1_ declarations below), which the sda attribute did
   not give: that one came out as an absolute lui/lw ---------------------------- */
#define SDA __attribute__((section(".sdata")))
extern int D_L01_001A90C8_1 SDA;
extern float D_L01_001A90C4_1 SDA;
extern int D_L01_001A90D0_1 SDA;
extern int D_L01_001A90CC_1 SDA;
extern void func_3022C8(void *a0, void *a1, int a2);

void func_L01_002F14E8_v3(int a0, int a1, float f12) {
    float v = f12;
    if (D_L01_001A90C8_1 == 0)
        func_3022C8((void *)0x002F1888, (void *)0x002F1588, 0);
    D_L01_001A90C8_1 = 5;
    D_L01_001A90C4_1 = v;
    if (v > 1.0f)
        D_L01_001A90C4_1 = 1.0f;
    else if (v < 0.0f)
        D_L01_001A90C4_1 = 0.0f;
    D_L01_001A90D0_1 = a1;
    D_L01_001A90CC_1 = a0;
}

/* the named level form: D_L01_<address> states its address, so the build pins it */
extern int D_L01_001A90C8 SDA;
extern float D_L01_001A90C4 SDA;
extern int D_L01_001A90D0 SDA;
extern int D_L01_001A90CC SDA;

void func_L01_002F14E8_v4(int a0, int a1, float f12) {
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

extern int func_37BA88(void *a0);
extern int func_37CCB0(void *a0, int a1);
extern int func_37EFB8(void *a0);

/* ---------------- func_L10_004190F0: retail stores the 0x34 halfword before the
   0x2C float ---------------------------------------------------------------- */
void func_L10_004190F0_v1(char *a0) {
    char *p = *(char **)(a0 + 0x68);
    int r = func_37BA88(a0);

    *(int *)(r + 0x148) = 10;
    func_37CCB0(a0, 1);
    *(float *)(p + 0x180) = 10.0f;
    *(unsigned char *)(a0 + 0x20) = 1;
    *(unsigned char *)(a0 + 0x30) = 0xFF;
    *(unsigned short *)(a0 + 0x32) = 0x1FF;
    *(unsigned short *)(a0 + 0x34) |= 0x100;
    *(float *)(a0 + 0x2C) = 0.08f;
    *(int *)(p + 0x268) = 0;
    *(int *)(p + 0x26C) = -1;
    func_37EFB8(a0);
}

extern unsigned short *D_L10_001FB1E0[];
extern int D_L10_001B251C;

/* ---------------- func_L10_0037D200: the halfword goes in a variable that the
   loop test reuses (retail keeps it in $a1 and tests with sll+bgez) ------------ */
int func_L10_0037D200_v2(unsigned char *a0) {
    unsigned short *p = D_L10_001FB1E0[a0[0x21]];
    unsigned short h;
    int n = 0;

    if (p == 0)
        return 0;
    do {
        h = *p;
        {
            char *m = (char *)(((h & 0x7FFF) << 8) + D_L10_001B251C);
            if ((*(unsigned short *)(m + 0x34) & 0x20) != 0) {
                float *f = *(float **)(m + 0x68);
                if (f != 0 && *f > 0.0f)
                    n++;
            }
        }
        p++;
    } while ((short)h >= 0);
    return n;
}

int func_L10_0037D200_v3(unsigned char *a0) {
    unsigned short *p = D_L10_001FB1E0[a0[0x21]];
    unsigned short h;
    int n = 0;

    if (p == 0)
        return 0;
    do {
        char *m;
        h = *p;
        m = (char *)(((h & 0x7FFF) << 8) + D_L10_001B251C);
        if ((*(unsigned short *)(m + 0x34) & 0x20) != 0) {
            float *f = *(float **)(m + 0x68);
            if (f != 0 && *f > 0.0f)
                n++;
        }
        p++;
    } while ((short)h >= 0);
    return n;
}
