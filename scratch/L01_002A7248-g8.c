/* Test of the -G8 unit route for the two functions that need $gp. The file name ends in
   -g8 so config/cflags.txt gives it "-O2 -G8 -ffunction-sections" (tools/build.py
   flags_for), which makes the small scalars gp-relative; the resident word that the
   retail reads absolutely gets nosda. */
extern char D_L01_00189E20[];
extern char D_L01_00139A28[];
extern int D_L01_001A79F0 __attribute__((nosda));
extern int D_L01_001ADF40[8];
extern int D_L01_001A90C8;
extern float D_L01_001A90C4;
extern int D_L01_001A90D0;
extern int D_L01_001A90CC;
extern void func_3022C8(void *a0, void *a1, int a2);

/* 92 bytes, 17 places: walks the gp table at 0x001ADF40, setting bit n of
   D_00139A28[0x8D] for every entry equal to D_001A79F0. */
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

/* 156 bytes, 5 places: arms the timer, stores 5 in the gp word at 0x1A90C8, clamps
   the incoming float into 0x1A90C4 and keeps the two arguments. */
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
