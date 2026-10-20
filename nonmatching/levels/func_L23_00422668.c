/* func_L23_00422668 (level 23, 300 bytes) -- NEAR MISS, not integrated.
   state: 308 bytes against retail's 300 (75 instructions, this C 77); check.py: 0 of 1 places match.
   matches: the first call's early return, the object-type test against 0x7E5, the two calls
   with the float argument, the 0x8B0003 call, the table lookup against D_0018C0B0 and the
   tail `arg0->0x20 = 2`.
   what still differs: the frame. Retail saves six callee-saved registers (no $s5) and places
   the locals at sp+0 (the call's first pointer is $sp itself), sp+0x10 and sp+0x28; this C
   takes one more saved register for arg0+0x10 and puts the locals at other offsets, so the
   prologue and every frame reference differ. Retail also issues `ori $a2,$a2,3` before the
   call (here it fills the call's delay slot). Declaration order did not change the layout.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef int TI128 __attribute__((mode(TI)));

extern void func_00282F20(float, void *, void *);

typedef struct {
    u8 pad[0x18];
    u8 *f18;
} L23Block1C0A80;

extern L23Block1C0A80 D_L23_001C0A80;

typedef struct {
    u8 b28;
    u8 b29;
    u16 h2A;
} L23Small;

extern s32 D_0018C0B0;

extern s32 func_002761F8(void *, void *, s32, void *, s32);

extern void func_002A8C00(float, void *, void *, s32, void *);

extern void func_002A8E20(void *, void *);

extern void func_L00_002D6900(s32);

extern void func_L22_0040E2B0(void *, s32, s32);

/* the object's first record is set up against the table entry, then its marker byte is set */
void func_L23_00422668(u8 *arg0, void *arg1) {
    L23Small small;
    TI128 local2;
    TI128 local1;
    u8 *payload;
    u8 *obj;

    payload = *(u8 **)(arg0 + 0x68);
    if (func_002761F8(arg1, arg0 + 0x10, 0, arg0, 0) == 0) {
        return;
    }
    obj = D_L23_001C0A80.f18;
    if (obj != 0) {
        if (*(s16 *)(obj + 0xAA) == 0x7E5) {
            return;
        }
        func_00282F20(1.0f, &local1, payload);
        func_002A8C00(*(float *)(payload + 0x1C), &local2, arg0, 0x8B0003, &local1);
        obj = D_L23_001C0A80.f18;
        small.b28 = 5;
        small.b29 = 3;
        small.h2A = *(u16 *)(arg0 + 0xAA);
        if (obj == (u8 *)D_0018C0B0) {
            func_002A8E20(obj, &local2);
            func_L00_002D6900(0x2B);
        }
        func_L22_0040E2B0(arg0 + 0x10, 0xA, 1);
    } else {
        local1 = *(TI128 *)(arg0 + 0x10);
        func_L22_0040E2B0(&local1, 0xF, 0);
    }
    *(u8 *)(arg0 + 0x20) = 2;
}
