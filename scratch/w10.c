typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u32 D_L08_001FB660[];
extern void func_L08_00328B80(s32, s32, s32, s32);

/* p1: while on the entry's sign bit, increment at the end of the body */
void p1(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *p = (u16 *)D_L08_001FB660[a0];

    if (p != 0) {
        while (*(s16 *)p >= 0) {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
            p++;
        }
    }
}

/* p2: the same walk written as a for loop */
void p2(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *p = (u16 *)D_L08_001FB660[a0];

    if (p != 0) {
        for (; *(s16 *)p >= 0; p++) {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
        }
    }
}

/* p3: break driven */
void p3(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *p = (u16 *)D_L08_001FB660[a0];

    if (p != 0) {
        for (;;) {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
            if (*(s16 *)p < 0)
                break;
            p++;
        }
    }
}

/* p4: do-while, the test on the entry just called */
void p4(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *p = (u16 *)D_L08_001FB660[a0];

    if (p != 0) {
        do {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
        } while (*(s16 *)p++ >= 0);
    }
}
