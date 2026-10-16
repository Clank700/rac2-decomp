typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u32 D_L08_001FB660[];
extern void func_L08_00328B80(s32, s32, s32, s32);

/* q1: the loaded pointer held under two names, copy for the loop */
void q1(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *q = (u16 *)D_L08_001FB660[a0];

    if (q != 0) {
        u16 *p = q;
        do {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
        } while (*(s16 *)p++ >= 0);
    }
}

/* q2: assignment inside the guard */
void q2(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *p;

    if ((p = (u16 *)D_L08_001FB660[a0]) != 0) {
        do {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
        } while (*(s16 *)p++ >= 0);
    }
}

/* q3: copy taken before the guard, walk on the copy */
void q3(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *q = (u16 *)D_L08_001FB660[a0];
    u16 *p = q;

    if (p != 0) {
        do {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
        } while (*(s16 *)p++ >= 0);
    }
}

/* q4: guard on the loaded value, then the loop variable assigned from it */
void q4(s32 a0, s32 a1, s32 a2, s32 a3) {
    u16 *q = (u16 *)D_L08_001FB660[a0];
    u16 *p;

    if (q != 0) {
        p = q;
        while (*(s16 *)p >= 0) {
            func_L08_00328B80(p[0] & 0x7FFF, a1, a2, a3);
            p++;
        }
    }
}
