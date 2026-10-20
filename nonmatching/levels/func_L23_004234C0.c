/* func_L23_004234C0 (level 23, 196 bytes) -- NEAR MISS, not integrated.
   state: 196 bytes against retail's 196; check.py: instruction at +0x6c differs.
   matches: the two gp-relative word selections, the 16-byte record copy into a local, the call
   to func_L23_00423380 with the local's address, the two gp-relative stores of the
   func_L00_0035F5A0 results, and the payload stores (in retail's order).
   what still differs: retail loads the object pointer into $v0, tests it, then copies it to
   $a1 (`lw $v0; beqz $v0; daddu $a1,$v0,$zero`); this C loads straight into $a1, and the
   payload branch is a branch-likely here (`bnel`) where retail has `bne` with the payload
   load in its delay slot. Splitting the pointer into two C variables moved the difference
   without removing it.
*/

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_L23_001B1958 __attribute__((sda));

extern s32 D_L23_001B1954 __attribute__((sda));

typedef int TI128 __attribute__((mode(TI)));

extern s32 D_L23_001B194C __attribute__((sda));

extern s32 D_L23_001B1950 __attribute__((sda));

extern u8 *func_L23_00423380(u8 *, TI128 *);

extern s32 func_L00_0035F5A0(s32, s32, s32);

void func_L23_004234C0(u8 *arg0, TI128 *arg1, s32 arg2) {
    s32 *word = &D_L23_001B1958;
    TI128 local;
    TI128 *copy = &local;
    u8 *obj;
    u8 *payload;

    if (arg2 != 0) {
        word = &D_L23_001B1954;
    }
    local = *arg1;
    if (*word == 0) {
        func_L23_00423380(arg0, &local);
        if (arg2 != 0) {
            D_L23_001B194C = func_L00_0035F5A0(0x14, 0, 0);
        } else {
            D_L23_001B1950 = func_L00_0035F5A0(0x14, 0, 0);
        }
        obj = (u8 *)*word;
        if (obj == 0) {
            return;
        }
        if (*(s16 *)(obj + 0xAA) == 0x1190) {
            payload = *(u8 **)(obj + 0x68);
            *(s16 *)(payload + 0x40) = arg2;
            *(s32 *)(payload + 0x48) = 0;
            *(s32 *)(payload + 0x44) = 0;
        }
    }
    obj = (u8 *)*word;
    *(TI128 *)(obj + 0x10) = *copy;
    payload = *(u8 **)(obj + 0x68);
    *(s16 *)(payload + 0x2E) = 1;
}
