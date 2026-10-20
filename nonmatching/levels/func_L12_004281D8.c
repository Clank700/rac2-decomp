/* func_L12_004281D8 (384 bytes, levels 12 and 13, src/levels/shared/L12_003E1CB0.c; it reads
 * three words through $gp, so it belongs in the -g8 sibling L12_003E1CB0-g8.c, after
 * func_L12_00428040, and was measured there).
 *
 * NEAR MISS: 384 of 384 bytes, and exactly four words differ, at +0xDC..+0xE8: the arguments
 * of the third call, func_00283D38(D_L12_001B21F0, D_L12_001B21F4[0], f). Retail has
 *     lwc1 $f12,0x34C($s0) ; lui $a1,0x1B ; lw $a1,0x21F4($a1) ; jal ; lw $a0,0x3200($gp)
 * i.e. the bare load of the second argument first and the $gp load of the first in the jal's
 * delay slot. This cc1 emits
 *     lwc1 $f12,0x34C($s0) ; lw $a0,D_L12_001B21F0 ; jal ; lw $a1,D_L12_001B21F4
 * so the one-instruction `lw $a1,sym` (an `sda` symbol the assembler expands to `lui`/`lw`,
 * which cc1 takes for a single instruction) fills the delay slot and the `lw` lands after the
 * call's slot: not even correct code. Why: -fsched-verbose-5 shows both argument loads with the
 * same priority (10) and the same number of dependents (3: the call, the next call and the
 * later write of $4 or $5), so both schedulers break the tie by insn order, and the argument
 * moves come out in register order ($4 before $5, whichever of the two is written first in the
 * source, through locals or not). The float load goes first in sched2 because it has four
 * dependents. Measured spellings of the second argument: `sda` array element, `sda` scalar
 * (also as a struct's first member, and the first argument as a one-element array), plain
 * scalar (the assembler then makes the slot load gp-relative), plain / `nosda` /
 * `section(".data")` array (split `lui` / `lw`; loop.c hoists the `lui` into a callee-saved
 * register, 392 bytes), `section(".sdata")` scalar (gp-relative, 380 bytes). The unit flag
 * `-mno-split-addresses` changes the table and frame too (400 bytes). None gives retail's
 * order; what would is anything that gives the load of $5 one more dependent than the load of
 * $4, or makes cc1 count `lw $5,sym` as two instructions so that the delay-slot filler passes
 * over it.
 *
 * The walk's other residue, the dead `lh $v0,-0x2($s1)` at its entry and the `nop` after it
 * (392 bytes, 8 over), went with the flow test of #238; with that compiler every other
 * instruction of this C but those four is retail's (checked word by word at both places).
 *
 * Measured spellings: the walk is the family's unrotated one (the p[-1] read guarded by a
 * second `p != 0`); the group id is written out as `a0[0x21]` in every term; the table, the
 * count and the base are read bare (`sda` arrays sized over 8 bytes: the count under a second
 * name, because func_L12_00428040 reads the same word through $gp from this file); the base
 * load stays in the loop (the calls keep it there); the first call's second argument is the
 * address of the 8-byte object at 0x001B21E0 (`addiu $a1,$gp,..`).
 */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_00282D30(void *dst, void *src, float value);
extern void func_002830C0(void *, void *, void *);
extern int func_00283D38(int, int, float);
extern void func_L00_00325AE8(void *, int, float, float);

extern unsigned short *D_L12_001FB960[];
extern int D_L12_001B2EB8_1[3] __attribute__((sda));
extern u8 *D_L12_001B2E9C[3] __attribute__((sda));
extern char D_L12_001B21E0[8] __attribute__((sda));
extern int D_L12_001B21F0 __attribute__((sda));
extern int D_L12_001B21F4[3] __attribute__((sda));

/* Rotates the entities of the object's group that are kind 0x11EB and in use (flag byte at
   +0x31 set, state byte at +0x20 not 0xFE or 0xFD): the first call turns the vector at
   D_L12_001B21E0 by the angle at +0x344 of the entity's private block into a local, the second
   applies the matrix at +0x240, the third mixes the two colours at D_L12_001B21F0 and
   D_L12_001B21F4 by the fraction at +0x34C, and the fourth uses the result. */
void func_L12_004281D8(u8 *a0)
{
    u16 *q;
    u16 *p;
    u8 *e;
    u8 *s0;
    float buf[4];
    int r;

    if (a0[0x21] == 0xFF)
        return;
    q = D_L12_001FB960[a0[0x21]];
    if (q == 0)
        return;
    for (p = q; a0[0x21] != 0xFF && a0[0x21] <= D_L12_001B2EB8_1[0] && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L12_001FB960[a0[0x21]]);
         p++) {
        e = D_L12_001B2E9C[0] + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x31] != 0 && *(s16 *)(e + 0xAA) == 0x11EB && e[0x20] != 0xFE && e[0x20] != 0xFD) {
            s0 = *(u8 **)(e + 0x68);
            func_00282D30(buf, D_L12_001B21E0, *(float *)(s0 + 0x344));
            func_002830C0(buf, buf, s0 + 0x240);
            r = func_00283D38(D_L12_001B21F0, D_L12_001B21F4[0], *(float *)(s0 + 0x34C));
            func_L00_00325AE8(buf, r, *(float *)(s0 + 0x344) * 0.2f, 0.08f);
        }
    }
}
