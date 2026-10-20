/* func_L23_00423380 (level 23, 316 bytes) -- NEAR MISS, not integrated.
   state: 312 bytes against retail's 316 (79 instructions, this C 78); check.py: 0 of 1 places match.
   matches: the allocation, the object field stores, the 16-byte record copy, the level block
   stores (one absolute symbol per store, the `lui $at` form) and the tail with its three quadword copies.
   what still differs (four things, each measured once):
   - retail copies arg1 into $s3 before the allocation call; here the copy issues in the call's
     delay slot.
   - the chosen word pointer lives in $t0 in retail and in $a0 here (the movz is the same).
   - the field stores at +0x30, +0x31, +0x32 issue in the order +0x32, +0x31, +0x30 in retail.
   - retail re-reads the flag D_L23_001A8FF0 after the block with an absolute `lui $v0,0x1B` +
     `lw` pair; here both reads are gp-relative, one instruction shorter. That is the 4-byte gap.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern s32 D_L23_001B1958 __attribute__((sda));

extern s32 D_L23_001B1954 __attribute__((sda));

extern s32 D_0018C0B0 __attribute__((nosda));

typedef int TI128 __attribute__((mode(TI)));

extern s32 D_L23_001A8AB0 __attribute__((nosda));

extern s32 D_L23_001A8AB4 __attribute__((nosda));

extern long long D_L23_001A8AB8 __attribute__((nosda));

extern s32 D_L23_001A8AC0 __attribute__((nosda));

extern s32 D_L23_001A8AC4 __attribute__((nosda));

extern long long D_L23_001A8AC8 __attribute__((nosda));

extern s32 D_L23_001A8FF0 __attribute__((sda));

extern s16 func_00291308(TI128 *, s32, float, float);

extern u8 *func_0029EFD0(s32);

/* allocates the object, selects its word and fills its fields and the level block */
u8 *func_L23_00423380(u8 *arg0, TI128 *arg1) {
    u8 *obj;
    u8 *payload;
    s32 *word;

    obj = func_0029EFD0(0x1190);
    word = &D_L23_001B1958;
    if (arg0 == (u8 *)D_0018C0B0) {
        word = &D_L23_001B1954;
    }
    if (obj != 0 && *word == 0) {
        *(s16 *)(obj + 0x32) = 0xFF;
        *(u8 *)(obj + 0x31) = 1;
        *(u8 *)(obj + 0x30) = 0xFF;
        *(u8 **)(obj + 0xB8) = arg0;
        *(u8 *)(obj + 0x20) = 0;
        payload = *(u8 **)(obj + 0x68);
        *(TI128 *)(obj + 0x10) = *arg1;
        *word = (s32)obj;
        D_L23_001A8AB4 = 0xFF;
        D_L23_001A8AC4 = 0x00FFFFFF;
        D_L23_001A8AC8 = 0x1F00000042LL;
        D_L23_001A8AB8 = 0;
        D_L23_001A8AB0 = 0;
        D_L23_001A8AC0 = 0;
        *(s32 *)(payload + 0x10) = 0;
        *(s16 *)(payload + 0x2C) = func_00291308(arg1, 0, 0.0f, 0.0f);
    }
    if (D_L23_001A8FF0 == 0) {
        return 0;
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x100;
    *(TI128 *)(obj + 0xC0) = *(TI128 *)(arg0 + 0xC0);
    *(TI128 *)(obj + 0xD0) = *(TI128 *)(arg0 + 0xD0);
    *(TI128 *)(obj + 0xE0) = *(TI128 *)(arg0 + 0xE0);
    return obj;
}
