/* Mid worker 7: near miss, 472 B vs retail 468 (shared unit L00_003D37E8.c flags). Everything matches except the
   dispatch stub: retail fills the `beq v1,1` delay slot with the case bodies' common `addiu a0,0x5F` (taken from the
   target) and the default `b` slot with `ld s0`; this cc1 fills the beq slot from the fall-through epilogue
   (`ld s0`) and the `b` slot with `ld s1`, one instruction longer. if/else-if gives 464 B (bnez layout, no match);
   `default:`, inline reread of 0x68 pointer (476 B) change nothing useful. Twin: func_L11_00450508 (different callee). */
extern int func_002A7820(int, int);
extern float func_002A7940(void);
extern void func_L00_003E0088_1(char *pos, int a1, int a2, int a3, int t0,
                                float fA, float fB, float fC);

void func_L00_003DFDC0(unsigned char *p)
{
    char *q = *(char **)(p + 0x68);

    switch (p[0x20]) {
    case 0:
        func_L00_003E0088_1((char *)p + 0x10, 0x103080, func_002A7820(95, 111), 11, 2,
                            *(float *)(p + 0x2C) * (*(float *)(q + 0x20) * 45.0f),
                            func_002A7940(), 1.0f);
        func_L00_003E0088_1((char *)p + 0x10, 0x3F3F3F, func_002A7820(111, 127), 11, 2,
                            *(float *)(p + 0x2C) * (*(float *)(q + 0x20) * 22.5f),
                            func_002A7940(), 1.0f);
        break;
    case 1:
        func_L00_003E0088_1((char *)p + 0x10, 0x103080, func_002A7820(95, 111), 11, 2,
                            *(float *)(p + 0x2C) * (*(float *)(q + 0x20) * 45.0f),
                            func_002A7940(), 1.0f);
        func_L00_003E0088_1((char *)p + 0x10, 0x3F3F3F, func_002A7820(111, 127), 11, 2,
                            *(float *)(p + 0x2C) * (*(float *)(q + 0x20) * 22.5f),
                            func_002A7940(), 1.0f);
        break;
    default:
        break;
    }
}
