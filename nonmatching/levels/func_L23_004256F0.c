/* func_L23_004256F0 (340 bytes, 1 place: 23:004256F0) -- NEAR MISS, not integrated.
   This C compiles to 340 bytes, the retail size; check.py reports "instruction at +0x8 differs".
   What still differs:
   - the callee-saved registers of the object pointer and of the eighth argument are swapped
     ($s3 and $s4 here, retail $s4 and $s3), which moves the first saves and the stores through them;
   - the first stack argument is loaded into the beqz delay slot, where retail puts the constant
     `addiu $a1,$zero,0xFF`; retail loads the stack words after the sub-record pointer and the
     constant-stores;
   - the 128-bit copy into the record: retail loads the object's vector into $a0 and stores $v0
     through $a2 = s0+0x10 (`lq $a0,0($s4)`, `sq $v0,0($a2)`); this cc1 keeps one register for
     the copy and folds the 0x10 into the store (`sq $v0,0x10($s0)`). That is the known
     constant-offset wall for quadword stores; a pointer variable for s0+0x10 did not change it.
   Stack arguments are declared 32-bit: as u8 this cc1 read them into callee-saved registers at entry.
*/

typedef unsigned char u8;

typedef short s16;

typedef int s32;

typedef int TI16 __attribute__((mode(TI)));

extern void *func_0029EFD0(int size);

extern float func_002A7940(void);

/* allocates the record, fills its sub-record from the arguments, then draws three samples into it */
void *func_L23_004256F0(u8 *obj, u8 *a1, u8 *a2, u8 a3, u8 a4, s16 a5, s16 a6, s32 a7, float f1, float f2,
                        float f3, float f4, s32 a9, s32 a10, s32 a11, s32 a12) {
    u8 *s0;
    u8 *v1;

    s0 = func_0029EFD0(0x11AC);
    if (s0 == 0) {
        return s0;
    }
    v1 = *(u8 **)(s0 + 0x68);
    v1[0x28] = a3;
    v1[0x29] = a4;
    *(float *)(v1 + 0x10) = f1;
    *(float *)(v1 + 0x14) = f2;
    *(float *)(v1 + 0x18) = f3;
    *(float *)(v1 + 0x1C) = f4;
    *(s16 *)(v1 + 0xC) = a5;
    *(s16 *)(v1 + 0xE) = a6;
    *(s32 *)v1 = a7;
    *(s32 *)(v1 + 4) = a9;
    v1[0x2A] = a10;
    *(s32 *)(v1 + 0x2C) = a11;
    v1[0x2B] = a12;
    s0[0x30] = 0xFF;
    *(u8 **)(s0 + 0xB8) = a1;
    s0[0x20] = 0;
    *(u8 **)(v1 + 0x20) = a2;
    *(u8 **)(v1 + 0x24) = obj;
    *(TI16 *)(s0 + 0x10) = *(TI16 *)obj;
    *(float *)(s0 + 0xF0) = func_002A7940();
    *(float *)(s0 + 0xF4) = func_002A7940();
    *(float *)(s0 + 0xF8) = func_002A7940();
    s0[0x20] = 0;
    return s0;
}
