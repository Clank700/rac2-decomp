/* Near miss: 644 bytes, retail's size (check.py first differs at +0x74).  The walk over the id list
 * (the rotated `for` with the `bgezl` and the `bc1fl` slot), the draw loop and both frames are
 * retail's word for word; what differs is 26 words: the two vector blocks and the sentinel
 * constant -1.
 *
 * It needs a unit of its own, `src/levels/02_maktar_nebula/L02_004388A0.c`, with one line in
 * config/cflags.txt:
 *     -O2 -G0 -ffunction-sections -frac2-qcopy
 * (the `lq $v0,0($fp) ; sq $v0,0($sp)` copy of the 16-byte point, `$fp` holding &tmp for the whole
 * loop).  Spellings that matter, each measured:
 *   - the level block is a struct: `D_L02_001BE200.timer` gives `lui ; addiu ; lw 0x34($v0)`, a
 *     char array gives `lui ; lw %lo(D+0x34)`;
 *   - the two range tests of each block are nested `if`s (`&&` is folded into one `sltiu` range
 *     test);
 *   - the table symbols are `sda`, which keeps the address of the corner table one `la` macro
 *     (`lui $s3 ; addiu $s3,$s3,0x2640` into the same register);
 *   - the draw loop counts up (`k < 4`), which loop.c turns into retail's `bgez $s2` count-down
 *     with both pointers walking up.
 *
 * What differs:
 *   - In each block retail loads the three constants $f0,$f1,$f2 in the order x,y,z, stores them
 *     x,y,z, copies, and only then sets the index (`addiu $s5,$zero,0x3F/0x40`).  This cc1 gives
 *     the first constant the highest register and moves `addiu $s5` up between the loads.
 *   - The constant -1 for the `idx == -1` test is `$v1` in three places (the two delay slots and
 *     the fall-through) and in the `beq` that reads it, where retail has `$v0`; $v1 holds the
 *     counter at the second test, so this cc1 needs a `bnel` there.
 *
 * Cause, measured, as for func_L02_004216F0: retail's 16-byte copy is a scheduling barrier.  With
 *     __asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(pt), "r"(tmp) : "$2", "memory");
 * in place of `*(TI128 *)pt = *(TI128 *)tmp;` (forward order of the three stores, same flags) the
 * two vector blocks are word for word retail's and only the sentinel remains (5 words: the three
 * `addiu` and the two branches, $v1 for $v0).  A `continue` in place of the `if`, a do-while for
 * the outer loop, an unsigned index and moving `bestid = -1` did not change it.  The compiler-side
 * candidate is the same as for func_L02_004216F0: an opt-in barrier variant of the `rac2_qcopy`
 * pattern.  `-frac2-zero-ti-barrier` on the clears makes this body worse (35 differing words
 * against 27 here, before the sentinel count). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

typedef int TI128 __attribute__((mode(TI)));

typedef struct { u8 pad[0x34]; int timer; } L02_State;
extern L02_State D_L02_001BE200;
extern void func_00282CC0(void *, void *, void *);

extern unsigned short **D_L02_001A9014 __attribute__((sda));
extern u8 *D_L02_001B3C1C __attribute__((sda));
extern float D_L02_001B2640[] __attribute__((sda));
extern float func_00282E80(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_L01_002E2608(void *, int, int, int, int);

void func_L02_004388A0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    float pt[4];
    float tmp[4];
    float m[16];
    unsigned short *q;
    u8 *e;
    u8 *rec;
    float best;
    float d;
    int idx;
    int bestid;
    int i;
    int k;

    for (i = 0; i < 2; i++) {
        idx = -1;
        if (i == 0) {
            if (D_L02_001BE200.timer >= 0x3B6) {
                if (D_L02_001BE200.timer < 0x547) {
                    *(TI128 *)tmp = 0;
                    tmp[0] = 495.0f;
                    tmp[1] = 587.0f;
                    tmp[2] = 513.0f;
                    *(TI128 *)pt = *(TI128 *)tmp;
                    idx = 0x3F;
                }
            }
        }
        if (i == 1) {
            if (D_L02_001BE200.timer >= 0x4E2) {
                if (D_L02_001BE200.timer < 0x5DD) {
                    *(TI128 *)tmp = 0;
                    tmp[0] = 515.0f;
                    tmp[1] = 596.0f;
                    tmp[2] = 512.0f;
                    *(TI128 *)pt = *(TI128 *)tmp;
                    idx = 0x40;
                }
            }
        }
        if (idx != -1) {
            bestid = -1;
            best = 99999.0f;
            for (q = D_L02_001A9014[*(int *)st];
                 q != 0 && ((short)q[-1] >= 0 || q == D_L02_001A9014[*(int *)st]) &&
                 (e = D_L02_001B3C1C + ((*q & 0x7FFF) << 6)) != 0;
                 q++) {
                d = func_00282E80(e + 0x30, pt);
                if (d < best) {
                    best = d;
                    bestid = *q & 0x7FFF;
                }
            }
            if (bestid != -1) {
                rec = D_L02_001B3C1C + (bestid << 6);
                for (k = 0; k < 4; k++) {
                    func_00283098(m + k * 4, D_L02_001B2640 + k * 4, rec);
                    func_00282CC0(m + k * 4, m + k * 4, rec + 0x30);
                }
                func_L01_002E2608(m, idx, 2, 0xFF808080, 0);
            }
        }
    }
}
