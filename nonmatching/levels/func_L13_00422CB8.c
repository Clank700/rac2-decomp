/* func_L13_00422CB8 (src/levels/13_boldan/L13_00306F38.c), 1016 bytes: this C is retail's
   instruction for instruction (`tools/check.py func_L13_00422CB8` prints "1 of 1 places match"),
   but the build cannot place it, so the marker stays in src/.

   The state byte at +0x20 selects the body through a jump table: `sltiu v0,v1,5 ; lui v0,0x2B ;
   addiu v0,v0,-0x2300 ; sll ; addu ; lw a0,0(v1) ; jr a0`. The table is in the level's data
   (0x2ADD00: five words, the addresses of cases 0, 1, the epilogue for case 2, 3 and 4). cc1
   builds a table for a switch of five labels (`case 2: break;` is what brings it to the
   threshold; four labels give a compare chain), but puts it in the object's .rodata, and the
   function reaches it with a `%hi/%lo` pair on the .rodata section symbol: tools/build.py has no
   place for that section and refuses the function ("needs .rodata at its place, which is not
   C"), the wall of docs/COMPILER-NOTES.md that also keeps func_00118CC8 here. Reaching the
   level's own table needs a computed goto, which src/ does not allow.

   How the C got to retail's words (kept for the next table-less attempt): the two slot tests
   take the record pointer from a lazily assigned `slot` (`idx == -1 || *(slot = ...) ...`, and a
   nested if in case 1) with a variable of its own per case (`idx` in case 1, `id` in case 3: one
   shared variable puts the index in $a1 in case 3 where retail has $a0); written with the +0x88 and
   +0x74 offsets inside one expression the compiler folds them into the symbol and the loads
   become `lbu v1,-0x14(v0)`. In case 0 the stores at +0x24 and +0x28 are written in that
   order (the other order swaps the two loads and the store left in the jal's delay slot). The
   two walks of cases 3 and 4 are the unrotated form with the second `p != 0`; the count
   D_L13_001B2938 is read in their delay slots ($gp) and the group word state[0] is read again at
   each test, as the stores may alias it. The unit's own -G0 flags are needed (the `sda` externs
   give bare lui/lw outside the delay slots). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u32 D_L13_001B291C[] __attribute__((sda));
extern char D_00189EA0[];
extern u16 *D_L13_001FB420[];
extern s32 D_L13_001B2938 __attribute__((sda));
extern u8 D_00188660[];
extern u8 D_L13_001B1C20[];
extern u8 D_L13_001B1C48[];
extern void func_0026FEB8(void *);
extern void func_0029F338(void *);
extern void func_002A7750(u8 *, s32, s32);
extern s32 func_002ACBC8(u8 *, s32);
extern s32 func_002B3868(u8 *);
extern void func_002E59F8(s32);
extern s32 func_L00_0035F5A0(s32, s32, u8 *);
extern s32 func_00282948(u8 *);

void func_L13_00422CB8(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    u8 *slot;
    s32 idx;
    s32 id;

    switch (a0[0x20]) {
    case 0:
        *(s32 *)(state + 0x2C) = -1;
        if (D_L13_001FB420[*(s32 *)state] == 0) {
            func_0026FEB8(D_L13_001B1C20);
            func_0029F338(a0);
            return;
        }
        if (*(s32 *)(state + 4) == -1) {
            func_0026FEB8(D_L13_001B1C48);
            func_0029F338(a0);
            return;
        }
        *(s32 *)(state + 0x18) = 0;
        *(s32 *)(state + 0x14) = 0;
        *(s32 *)(state + 0x24) = *(s32 *)(state + 8);
        *(s32 *)(state + 0x28) = *(s32 *)(state + 0xC);
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (func_002ACBC8((u8 *)D_00189EA0, *(s32 *)(state + 0x10)) != 0)
            func_002A7750(a0, 3, -1);
        idx = *(s32 *)(state + 0x2C);
        if (idx != -1) {
            slot = D_00188660 + idx * 0x70;
            if (*(u8 **)(slot + 0x88) == a0 && slot[0x74] != 0)
                func_002E59F8(idx);
        }
        *(s32 *)(state + 0x2C) = -1;
        break;
    case 2:
        break;
    case 3:
        func_002B3868(a0);
        id = *(s32 *)(state + 0x2C);
        if (id == -1 || *(u8 **)((slot = D_00188660 + id * 0x70) + 0x88) != a0 || slot[0x74] == 0)
            *(s32 *)(state + 0x2C) = func_L00_0035F5A0(0x13, 4, a0);
        if (func_00282948(state + 0x24) != 0 && *(s32 *)(state + 0x14) == 0) {
            for (p = D_L13_001FB420[*(s32 *)state];
                 (*(s32 *)state & 0xFF) != 0xFF && *(s32 *)state <= D_L13_001B2938 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L13_001FB420[*(s32 *)state]);
                 p++) {
                e = (u8 *)D_L13_001B291C[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (*(s16 *)(e + 0xAA) == 0xEE7)
                    *(s32 *)(*(u8 **)(e + 0x68) + 0x628) = 1;
            }
            *(s32 *)(state + 0x14) = 1;
        }
        if (func_00282948(state + 0x28) != 0 && *(s32 *)(state + 0x18) == 0) {
            *(s32 *)(*(u8 **)((u8 *)D_L13_001B291C[0] + (*(s32 *)(state + 4) << 8) + 0x68) + 0x3C) = 1;
            *(s32 *)(state + 0x18) = 1;
        }
        if (*(s32 *)(state + 0x18) != 0 && *(s32 *)(state + 0x14) != 0) {
            *(s32 *)(state + 0x28) = *(s32 *)(state + 0x1C);
            *(s32 *)(state + 0x24) = *(s32 *)(state + 0x20);
            func_002A7750(a0, 4, -1);
        }
        break;
    case 4:
        if (func_00282948(state + 0x24) != 0 && *(s32 *)(state + 0x14) != 0) {
            for (p = D_L13_001FB420[*(s32 *)state];
                 (*(s32 *)state & 0xFF) != 0xFF && *(s32 *)state <= D_L13_001B2938 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L13_001FB420[*(s32 *)state]);
                 p++) {
                e = (u8 *)D_L13_001B291C[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (*(s16 *)(e + 0xAA) == 0xEE7)
                    *(s32 *)(*(u8 **)(e + 0x68) + 0x628) = 0;
            }
            *(s32 *)(state + 0x14) = 0;
        }
        if (func_00282948(state + 0x28) != 0 && *(s32 *)(state + 0x18) != 0) {
            *(s32 *)(*(u8 **)((u8 *)D_L13_001B291C[0] + (*(s32 *)(state + 4) << 8) + 0x68) + 0x3C) = 0;
            *(s32 *)(state + 0x18) = 0;
        }
        if (*(s32 *)(state + 0x18) == 0 && *(s32 *)(state + 0x14) == 0) {
            *(s32 *)(state + 0x24) = *(s32 *)(state + 8);
            *(s32 *)(state + 0x28) = *(s32 *)(state + 0xC);
            func_002A7750(a0, 1, -1);
        }
        break;
    }
}
