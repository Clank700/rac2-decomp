/* func_L23_00422540 (level 23, 292 bytes) -- NEAR MISS, not integrated.
   state: 284 bytes against retail's 292 (73 instructions); check.py: 0 of 1 places match.
   matches: the prologue with the $f20 save, the four calls, the record copies, the float
   stores through one float register and the `mtc1 $zero` / `nop` / `swc1` sequence.
   what still differs: retail keeps the address of the second local in $s2 across the first
   call (`addiu $s2,$sp,0x10`, passed on as `daddu $a0,$s2`, reloaded through $s2). The
   compiler folds every spelling of that pointer back to `sp+0x10`, so two instructions are
   missing. The 1.0f load also issues after the copies in retail, before them here.
*/

typedef unsigned char u8;
typedef int s32;
typedef short s16;

typedef int TI128 __attribute__((mode(TI)));

extern void func_002AFFD8(void *, void *, s32);

extern u8 *func_0029EFD0(s32);

extern void func_00282F20(float, void *, void *);

extern void func_00282DD8(void *, void *, void *);

/* builds the object from the two records and the float, then sets its three floats */
u8 *func_L23_00422540(u8 *arg0, TI128 *arg1, float *arg2) {
    TI128 local1;
    TI128 local2;
    u8 *obj;
    u8 *payload;
    float value;
    TI128 *second;

    func_002AFFD8(arg0, &local1, 1);
    obj = func_0029EFD0(0x118E);
    if (obj != 0) {
        value = *arg2;
        payload = *(u8 **)(obj + 0x68);
        *(float *)(payload + 0x1C) = value;
        *(s32 *)(payload + 0x10) = 0x3C;
        *(u8 *)(obj + 0x30) = 0xFF;
        *(s16 *)(obj + 0x32) = 0xFF;
        *(u8 *)(obj + 0x20) = 0;
        *(TI128 *)(obj + 0x10) = *(TI128 *)arg0;
        *(TI128 *)payload = *arg1;
        *(s32 *)(payload + 0x14) = 0;
        *(s32 *)(payload + 0x18) = 0;
        second = &local2;
        func_00282F20(1.0f, second, arg1);
        *(TI128 *)(obj + 0xC0) = *second;
        func_00282DD8(obj + 0xD0, obj + 0xC0, &local1);
        func_00282F20(1.0f, obj + 0xD0, obj + 0xD0);
        func_00282DD8(obj + 0xE0, obj + 0xD0, obj + 0xC0);
        value = 0.0f;
        *(float *)(obj + 0xCC) = value;
        *(float *)(obj + 0xEC) = value;
        *(float *)(obj + 0xDC) = value;
    }
    return obj;
}
