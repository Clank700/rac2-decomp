/* wave 6 lvl-04 batch 5 (tour 2) */

extern void func_L03_0038B2E8(void *a0, void *a1, int a2);
extern void func_00282CF0(void *a0, void *a1, void *a2);
extern void func_00282CC0(void *a0, void *a1, void *a2);
extern char *D_L03_001FE700[];

/* ---------------- func_L03_0038B408 (224 bytes, 2 places) ---------------- */
void func_L03_0038B408(char *a0) {
    char *p = *(char **)(a0 + 0x68);
    int buf[4];
    int i;
    int j;
    int n;

    for (i = 0; i < 4; i++) {
        char *q = D_L03_001FE700[*(int *)(p + 0x28 + i * 4)];
        if (q == 0)
            continue;
        func_L03_0038B2E8(buf, q, *(int *)(p + 0x38));
        n = *(int *)(p + 0x38);
        for (j = 0; j < n; j++) {
            q += 0x10;
            func_00282CF0(q, q, buf);
            func_00282CC0(q, q, p + 0xE0);
        }
    }
}

void func_L03_0038B408_v1(char *a0) {
    char *p = *(char **)(a0 + 0x68);
    int buf[4];
    int i;
    int j;
    char *q;
    char *v;
    int n;

    for (i = 0; i < 4; i++) {
        q = D_L03_001FE700[*(int *)(p + 0x28 + i * 4)];
        if (q == 0)
            continue;
        func_L03_0038B2E8(buf, q, *(int *)(p + 0x38));
        n = *(int *)(p + 0x38);
        if (n <= 0)
            continue;
        v = q;
        for (j = 0; j < n; j++) {
            v += 0x10;
            func_00282CF0(v, v, buf);
            func_00282CC0(v, v, p + 0xE0);
        }
    }
}

extern void func_002E5CF8(int a0, int a1, void *a2);
extern void func_L00_00410508(void *a0, void *a1);
extern void func_L00_002D3F30(int a0, int a1);
extern int D_L00_001B2D58;
extern char D_L00_001B8F20[];
extern int func_L00_003AB9C0(void *a0, void *a1, int a2, void *a3,
                             float f12, float f13, float f14, float f15);

/* ---------------- func_L00_00410430 (216 bytes, 27 places) ---------------- */
void func_L00_00410430(char *a0, void *a1, int a2) {
    char *p = *(char **)(a0 + 0x68);
    int r;

    if (a2 != 0) {
        *(int *)(p + 0x34) = a2;
        *(int *)(p + 0x2C) = a2 - 1;
        func_002E5CF8(5, 0, a0);
        *(int *)(p + 0x28) = a2 - 1;
        func_L00_00410508(a0, a1);
        return;
    }
    func_002E5CF8(5, 0, a0);
    r = func_L00_003AB9C0(a0, a1, *(int *)p, D_L00_001B8F20,
                          *(float *)(p + 8), 2.0f, 5.0f, 0.6f);
    if (r != 0) {
        func_L00_002D3F30(-1, 1);
        D_L00_001B2D58 = 1;
        *(void **)(r + 0xB8) = a0;
    }
}

void func_L00_00410430_v1(char *a0, void *a1, int a2) {
    char *p = *(char **)(a0 + 0x68);
    int r;

    if (a2 != 0) {
        *(int *)(p + 0x34) = a2;
        *(int *)(p + 0x2C) = a2 - 1;
        func_002E5CF8(5, 0, a0);
        *(int *)(p + 0x28) = a2 - 1;
        func_L00_00410508(a0, a1);
    } else {
        func_002E5CF8(5, 0, a0);
        r = func_L00_003AB9C0(a0, a1, *(int *)p, D_L00_001B8F20,
                              *(float *)(p + 8), 2.0f, 5.0f, 0.6f);
        if (r != 0) {
            func_L00_002D3F30(-1, 1);
            D_L00_001B2D58 = 1;
            *(void **)(r + 0xB8) = a0;
        }
    }
}
