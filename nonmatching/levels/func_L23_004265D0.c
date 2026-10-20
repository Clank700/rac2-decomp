/* func_L23_004265D0 (456 bytes, 1 place: level 23) -- NEAR MISS, not integrated.
   state: 456 bytes against retail's 456 (114 instructions); 25 words differ, the first at +0x28.
   Checked as tools/check.py does, in the -G8 unit (the file name *-g8.c gives the flags: the
   float decrement at the end is a bare `$gp` access). It belongs in L23_0041E418-g8.c.
   What matches: the frame and the save set ($s0..$s3, $ra), the whole control structure, the four
   `c.olt.s` tests on func_00282E48's result (200, 100, 25, 0 and the four stores 4.0, 2.0, 1.0,
   0.5), the func_00282978 pair, the registration of func_L05_00428518, the `$gp` float read in
   the first branch's delay slot, the `sb` in the first call's delay slot, and the order of the three
   stores (float, int, byte).
   What differs, all of it hard-register choice and the order it follows:
   - the temporaries of the first block. Retail: index in $v0, first table address in $a0, second
     table address in $t0, 0xFF in $a3, the constant 1 in $a2. This cc1: index in $v1, first table in
     $v0, second table in $a2, 0xFF in $t0, 1 in $a3. Cause, from the -dl dump (the first table's
     high and lo_sum share a register, so do index, shift and sum) and local-alloc's priority
     formula, floor_log2(refs) * refs / live length: the table pair (four references, five insns
     long) ranks just above the index chain (six references, eight insns long), so it takes $v0.
     Retail has the chain winning. The `lui`/`addiu` of the second table and the 0xFF constant also
     issue before the first store in retail and after it here;
   - the tail: retail issues `lui $v1; addiu $v1` and then `lw $v0,0x3C($s0)`, this cc1 puts the `lw`
     between the two.
   About 350 compiles changed nothing that matters: all six orders of the three stores (with and
   without the else arm's two statements swapped), explicit index and pointer locals, `&tab[i]`,
   `*(tab + i)` and `*(float *)((u8 *)tab + (i << 2))` spellings, a named pointer for the table
   address, the position of the locals. Most compile to the same bytes. The order (byte, int, float)
   is the closest by alignment (14 mismatched words against 18) but stores in an order retail does
   not have, so the C here keeps retail's order. The ranking looks like local-alloc's, which no
   source shape moved: a compiler-side question.
*/

typedef unsigned char u8;

typedef int s32;

extern float D_L23_001B38E8[6];

extern s32 D_L23_001B3900[6];

extern s32 D_L23_001B3918[6];

extern float D_L23_001BA640[];

extern float D_L23_001B19FC __attribute__((sda));

extern float func_00282E48(void *, void *);

extern s32 func_00282978(void *);

extern void func_L00_002E6DB8(void *, void *);

extern void func_L05_00428518(void *);

extern void func_0029F338(u8 *);

/* first update of a spawned effect: records the slot, grades the distance to the reference point,
   then either hands the object to the shared updater or releases it and gives the slot back */
void func_L23_004265D0(u8 *obj) {
    u8 *pl = *(u8 **)(obj + 0x68);

    if (obj[0x20] == 0) {
        D_L23_001B38E8[*(s32 *)(pl + 0x3C)] = 0.01f;
        D_L23_001B3900[*(s32 *)(pl + 0x3C)] = 0xFF;
        obj[0x20] = 1;
        if (200.0f < func_00282E48(obj + 0x10, D_L23_001BA640)) {
            *(float *)(pl + 0x40) = 4.0f;
        } else if (100.0f < func_00282E48(obj + 0x10, D_L23_001BA640)) {
            *(float *)(pl + 0x40) = 2.0f;
        } else if (25.0f < func_00282E48(obj + 0x10, D_L23_001BA640)) {
            *(float *)(pl + 0x40) = 1.0f;
        } else if (0.0f < func_00282E48(obj + 0x10, D_L23_001BA640)) {
            *(float *)(pl + 0x40) = 0.5f;
        }
    }
    if (func_00282978(pl) == 0) {
        func_00282978(pl + 4);
        func_L00_002E6DB8((void *)func_L05_00428518, obj);
    } else {
        D_L23_001B3918[*(s32 *)(pl + 0x3C)] = 0;
        D_L23_001B19FC = D_L23_001B19FC - 1.0f;
        func_0029F338(obj);
    }
}
