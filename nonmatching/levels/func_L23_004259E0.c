/* func_L23_004259E0 (280 bytes, 1 place: 23:004259E0) -- NEAR MISS, not integrated.
   This C compiles to 268 bytes against retail's 280: twelve short, three instructions.
   check.py (23_damosel_orbit, the -G8 unit) reports "268 bytes, expected 280".
   Right: the prologue and its save order, the early-exit arm, the register assignment of the object
   and of its sub-record, the $gp constants and the first two argument sets.
   What still differs:
   - retail's two argument sets of the first call (the `obj[0x2B]` test) both branch into one
     shared `jal`, the arm that jumps leaving its $f14 load in the branch delay slot. This cc1 instead
     merges the arms' last loads into one tail, so the block is three instructions short.
     Hoisting the differing words into locals gave 248 bytes; two explicit calls kept both jumps and
     gave 284 bytes with the wrong registers for the object and the sub-record;
   - the early-exit arm's loads come in another order: retail loads the $t1 word first and the
     $f12..$f14 arguments before the $t0 word, this cc1 starts with $f14 and loads $t0 before $f12.
*/

typedef unsigned char u8;

typedef short s16;

typedef int s32;

extern s32 D_L23_001B19C4 __attribute__((sda));

extern s32 D_L23_001B19C8 __attribute__((sda));

extern float D_L23_001B19CC __attribute__((sda));

extern float D_L23_001B19D0 __attribute__((sda));

extern float D_L23_001B19D4 __attribute__((sda));

extern s32 D_L23_001B19D8 __attribute__((sda));

extern void func_L23_00425AF8(void *obj, s32 a, s32 b, s32 c, s32 d, s32 e, float x, float y, float z);

void func_L23_004259E0(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);

    if (obj[0x2A] == 0) {
        func_L23_00425AF8(obj + 0x30, obj[0x28], obj[0x29], 5, *(s32 *)obj, *(s32 *)(obj + 4),
                          *(float *)(obj + 0x10), *(float *)(obj + 0x14), *(float *)(obj + 0x18));
        return;
    }
    if (obj[0x2B] != 0) {
        func_L23_00425AF8(obj + 0x30, obj[0x28], obj[0x29], 5, D_L23_001B19D8, D_L23_001B19D8,
                          *(float *)(obj + 0x10), *(float *)(obj + 0x14), *(float *)(obj + 0x18));
    } else {
        func_L23_00425AF8(obj + 0x30, obj[0x28], obj[0x29], 5, *(s32 *)obj, *(s32 *)(obj + 4),
                          *(float *)(obj + 0x10), *(float *)(obj + 0x14), *(float *)(obj + 0x18));
    }
    func_L23_00425AF8(obj + 0x30, obj[0x28] * D_L23_001B19C4, obj[0x29] * D_L23_001B19C8, 5, *(s32 *)obj, *(s32 *)(obj + 4),
                      *(float *)(obj + 0x10) * D_L23_001B19CC, *(float *)(obj + 0x14) * D_L23_001B19D0,
                      *(float *)(obj + 0x18) * D_L23_001B19D4);
}
