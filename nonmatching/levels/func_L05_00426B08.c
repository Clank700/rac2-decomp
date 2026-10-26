/* func_L05_00426B08: M3 2026-10-26: -G8 -frac2-qcopy -frac2-qcopy-barrier unit, store order 0x30/0x32/0x31: 212/212, 9 lines. Left: the 0xF8 store against the $gp read, the 0xFBF compare kept in a register (xor), and the tied D_L05_001B2528 read.
 */
typedef int TI128 __attribute__((mode(TI)));

extern char * func_0029EFD0(int);

extern void func_00282C88(void *);

extern float func_002A7940(void);

extern int D_L05_001B1504 __attribute__((sda));

extern int D_L05_001B2528 __attribute__((nosda));

extern void func_L05_00426D98(int);

int func_L05_00426B08(int a0)
{
    int s1 = a0;
    int s0 = func_0029EFD0(0x117F);

    if (s0 != 0) {
    *(unsigned char *)(s0 + 0x30) = 0xFF;
    *(unsigned short *)(s0 + 0x32) = 0xFF;
    *(unsigned char *)(s0 + 0x31) = 1;
    *(TI128 *)(s0 + 0x10) = *(TI128 *)(s1 + 0x10);
    func_00282C88(s0 + 0xF0);
    *(float *)(s0 + 0xF8) = func_002A7940();
    if (D_L05_001B1504 == 0) {
        int p = D_L05_001B2528;

        if (p != 0) {
            int r = 0;
            int id = 0xFBF;

            do {
                if (*(short *)(p + 0xAA) == id)
                    r = p;
                p = *(int *)(p + 0x28);
            } while (p != 0);
            D_L05_001B1504 = r;
        }
    }
        func_L05_00426D98(s0);
        *(float *)(s0 + 0x2C) = *(float *)(*(int *)(s0 + 0x24) + 0x24);
        return s0;
    }
    return 0;
}
