/* func_L05_00432080: M3 2026-10-26: -frac2-qcopy unit: 208/208, 17 lines. Retail keeps the three-quadword copy loop counting up (slti 3); cc1 reverses it (int, unsigned, long, short, char counters tried).
 */
extern char * func_0029EFD0(int);

extern void func_002A0F48(void *);

typedef int TI128 __attribute__((mode(TI)));

char *func_L05_00432080(char *a0, float f12)
{
    char *obj = func_0029EFD0(0x10E3);

    if (obj != 0) {
        int i;

        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0xFF;
        *(unsigned char *)(obj + 0x31) = 1;
        *(unsigned char *)(obj + 0x23) = 0x60;
        *(unsigned short *)(obj + 0x34) = *(unsigned short *)(obj + 0x34) | 0x108;
        *(unsigned char *)(obj + 0x20) = 0;
        *(char **)(*(char **)(obj + 0x68)) = a0;
        *(TI128 *)(obj + 0x10) = *(TI128 *)(a0 + 0x10);
        {
            char *dst = obj + 0xC0;
            char *src = a0 + 0xC0;

            i = 0;
            do {
                *(TI128 *)dst = *(TI128 *)src;
                dst += 0x10;
                src += 0x10;
                i++;
            } while (i < 3);
        }
        *(float *)(obj + 0x2C) = *(float *)(*(char **)(obj + 0x24) + 0x24) * f12;
        func_002A0F48(obj);
    }
    return obj;
}
