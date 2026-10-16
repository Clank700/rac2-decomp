/* wave 6 lvl-04 batch 2: the small L10 trio and func_L01_003165E8 */

extern unsigned short *D_L10_001FB1E0[];
extern int D_L10_001B251C;

/* ---------------- func_L10_0037D200 (148 bytes, 2 places) ---------------- */
int func_L10_0037D200(unsigned char *a0) {
    unsigned short *p = D_L10_001FB1E0[a0[0x21]];
    int n = 0;

    if (p == 0)
        return 0;
    do {
        unsigned short h = *p;
        char *m = (char *)(((h & 0x7FFF) << 8) + D_L10_001B251C);
        if ((*(unsigned short *)(m + 0x34) & 0x20) != 0) {
            float *f = *(float **)(m + 0x68);
            if (f != 0 && *f > 0.0f)
                n++;
        }
    } while (*(short *)p++ >= 0);
    return n;
}

int func_L10_0037D200_v1(unsigned char *a0) {
    unsigned short *p = D_L10_001FB1E0[a0[0x21]];
    int n = 0;

    if (p == 0)
        return 0;
    while (*(short *)p >= 0) {
        unsigned short h = *p;
        char *m = (char *)(((h & 0x7FFF) << 8) + D_L10_001B251C);
        if ((*(unsigned short *)(m + 0x34) & 0x20) != 0) {
            float *f = *(float **)(m + 0x68);
            if (f != 0 && *f > 0.0f)
                n++;
        }
        p++;
    }
    return n;
}

extern int func_37BA88(void *a0);
extern int func_37CCB0(void *a0, int a1);
extern int func_37EFB8(void *a0);

/* ---------------- func_L10_004190F0 (152 bytes, 2 places) ---------------- */
void func_L10_004190F0(char *a0) {
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

extern int func_311B48(void *a0, void *a1, int a2);
extern int func_3163C8(void *a0, void *a1);
extern int func_316558(void *a0, void *a1);
extern int func_3164A0(void *a0, void *a1);
extern char *D_L01_001FE180[];

/* ---------------- func_L01_003165E8 (176 bytes, 2 places) ---------------- */
int func_L01_003165E8(char *a0, int a1, char *a2, char *a3, char *t0) {
    if (a1 >= 0) {
        char *p = D_L01_001FE180[a1];
        if (func_311B48(a0, p + 0x10, *(int *)p) != 0)
            return 1;
    }
    if (func_3163C8(a0, a2) != 0)
        return 2;
    if (func_316558(a0, a3) != 0)
        return 3;
    return func_3164A0(a0, t0) != 0 ? 4 : 0;
}

int func_L01_003165E8_v1(char *a0, int a1, char *a2, char *a3, char *t0) {
    if (a1 >= 0) {
        char *p = D_L01_001FE180[a1];
        if (func_311B48(a0, p + 0x10, *(int *)p))
            return 1;
    }
    if (func_3163C8(a0, a2))
        return 2;
    if (func_316558(a0, a3))
        return 3;
    if (func_3164A0(a0, t0))
        return 4;
    return 0;
}
