/* Mid worker 7: near miss, boot func_002BCF18 (440 B), own unit, flags -O2 -G8 -ffunction-sections -frac2-qcopy.
   Same size and every instruction except three in the tail: after the func_001163B0 call retail schedules
   `lui a1,0x1F ; xori a2,s2,3 ; addiu v1,s0,0x20 ; lw a0,0x2580(a1)` and the movz select on the table pointer; this
   cc1 emits `xori ; addiu ; lui v0` (different temp register) so one instruction and its register differ.
   Tried: ternary spelling both ways, tab in a local before/after q, statement order, indexed select. */
typedef int TI128 __attribute__((mode(TI)));

extern float D_001B168C;
extern unsigned char *D_001F2580;
extern int func_002A77E0(int);
extern char *func_002B9030(int);
extern int func_00283CF0(float);
extern char func_001163B0(void);

char *func_002BCF18(char *a0, char *a1, int a2, int a3, int t0, int t1, float f12)
{
    char *p;

    if (t0 == 0)
        return 0;
    if (D_001B168C > 0.9f && func_002A77E0(3) == 0)
        return 0;
    if (D_001B168C > 0.95f && func_002A77E0(2) == 0)
        return 0;
    if (D_001B168C > 1.0f && func_002A77E0(1) == 0)
        return 0;
    p = func_002B9030(0x10);
    if (p != 0) {
        char *q;
        unsigned char *tab;
        int t;

        *(TI128 *)(p + 0x10) = *(TI128 *)a0;
        *(int *)(p + 4) = a2;
        t = func_00283CF0(4.0f) + 0x40;
        p[1] = 0;
        *(float *)(p + 0xC) = f12;
        p[3] = 0x44;
        p[9] = t;
        p[8] = func_001163B0();
        q = p + 0x20;
        tab = D_001F2580;
        p[2] = *((t1 != 3) ? tab + t1 : tab);
        *(short *)(p + 0xA) = t0;
        *(short *)(q + 0x18) = t0;
        *(float *)(q + 0x1C) = f12;
        *(int *)(q + 0x10) = a2;
        *(int *)(q + 0x14) = a3;
        *(short *)(q + 0x1A) = t1;
        *(TI128 *)q = *(TI128 *)a1;
        *(float *)(q + 0xC) = *(float *)(a0 + 8) - 0.5f;
    }
    return p;
}
