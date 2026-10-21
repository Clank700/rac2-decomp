/* func_L23_00428CF8 (level 23, 928 bytes) -- NEAR MISS, not integrated.
   state: 924 bytes against retail's 928; tools/check.py: 0 of 1 places match ("924 bytes, expected
   928"). Built as a unit of its own with `-O2 -G8 -ffunction-sections -frac2-qcopy` (an `-g8` unit:
   retail's `lwc1 $f12,0x2AF4($gp)` is a plain $gp load).
   matches: everything but the order around the three 16-byte copies: the frame (0xF0; the locals
   sit at sp+0x20 the moved position, 0x30 the first hit record, 0x60 the vector, 0x70 the second
   hit record, declared in that order as float[4] / a 0x30-byte struct), the prologue, the state
   switch, the `||` of the two probes, the three-way class test, both arms and their cross-jumped
   `func_002A7750` tail, the rotation tail and the clamp. Measured on the way: the literal
   `moby + 0x10` at every use (no pointer variable) is what gives retail's two registers for it
   (s0 for the first two uses, a copy in s3 for the rest: most likely gcse's reaching register; one
   named pointer coalesces them); `5627.9248046875f` is retail's 0x45AFDF66 (5627.907f encodes
   0x45AFDF42); the global block is read through a local `u8 *base = D_L23_001C0A80;` (retail's
   `lui $v0 ; addiu $s5,$v0,0xA80`, the lui in the probes' delay slots); the hit records are
   locals filled by `func_002A8C00` and then patched at +0x18/+0x19/+0x1A.
   what still differs (17 words, all of it the position of the copies, wall (2) of the brief):
   retail's `lq $v0,0($s2) ; sq $v0,0($s0)` pair comes FIRST in both arms of the vector set-up,
   before the `lui/mtc1 $f12` constant and the `daddu $a0,$s0` of the next call (and, because the
   pair cannot sit in a delay slot, the third class test is a `beql` with a copy of the target's
   `lbu` in its slot); this cc1 schedules the pair after them (sched1 trace: the copy has priority
   13, the same as the two argument moves, and the later insns win ties; the constant has 14).
   In a SCRATCH copy of this file (build/, never src/) with the two arm copies and the copy-back
   written as `asm volatile ("lq $2,0(%1) ; sq $2,0(%0)" : : "r"(dst), "r"(src) : "$2", "memory")`
   the same C compiles to retail's 928 bytes with 0 words different: the barrier is the whole gap.
   tried: -fno-schedule-insns / -fno-schedule-insns2 / both on top of qcopy (932 bytes and 46 words
   off / 924 and 46 / 944 and 118, against 924 and 17), a TI temporary for the copy (separate lq and
   `sq $v0,0x60($sp)`: 928 bytes, 9 words off, but a different shape), named position pointers (one or
   two: wrong registers). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef int TI128 __attribute__((mode(TI)));

typedef struct Hit_00428CF8 {
    u8 pad00[0x18];
    u8 f18;
    u8 f19;
    u16 f1A;
    u8 pad1C[0x14];
} Hit_00428CF8;

extern float D_L23_001B1AE4 __attribute__((sda));

extern u8 D_L23_001C0A80[];

extern s32 D_0018C0B0 __attribute__((nosda));

extern void func_002A7750(u8 *, s32, s32);

extern void func_00282CC0(void *, void *, void *);

extern void func_002A8C00(void *, u8 *, s32, void *, float);

extern s32 func_002761F8(void *, void *, s32, u8 *, s32);

extern s32 func_00277258(void *, s32, u8 *, float);

extern s32 func_00277F48(void *, s32, u8 *, void *, float);

extern void func_00282D30(void *, void *, float);

extern void func_00282C88(void *);

extern s32 func_L00_0035F5A0(s32, s32, s32);

extern void func_0032C700(void *, s32, s32, s32, s32, s32, s32, s32, float, float, s32, s32, s32, s32);

extern void func_0029F338(u8 *);

extern void func_002ACEC0(void *, void *, void *, float);

extern void func_L00_002E6EF8(void *, u8 *);

extern void func_L13_0040DE50(u8 *);

/* Per-frame handler of a moving object: steps the state-0 object by its velocity, bounces or
   finishes on a hit, and in every other state rotates the two matrices and clamps the counter. */
void func_L23_00428CF8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    float move[4];
    Hit_00428CF8 hit1;
    float vec[4];
    Hit_00428CF8 hit2;
    s32 v;

    if (moby[0xBC] == 0) {
        *(s32 *)(vars + 0x24) = *(s32 *)(vars + 0x24) + 1;
        if (*(s32 *)(vars + 0x24) > 0xF0) {
            if (moby[0xBC] == 0) {
                func_002A7750(moby, 1, -1);
            }
        }
        switch (moby[0x20]) {
        case 0:
            func_00282CC0(move, moby + 0x10, vars);
            func_002A8C00(&hit1, moby, 0x80003, vars, *(float *)(vars + 0x14));
            hit1.f1A = *(u16 *)(moby + 0xAA);
            if (func_002761F8(moby + 0x10, move, 0, moby, 0) != 0 || func_00277258(moby + 0x10, 0, moby, 0.3f) != 0) {
                u8 *base = D_L23_001C0A80;

                if (*(u8 **)(base + 0x18) != 0) {
                    s16 cls = *(s16 *)(*(u8 **)(base + 0x18) + 0xAA);

                    if (cls != 0x7E5 && cls != 0xF7F && cls != 0xF7E) {
                        *(TI128 *)vec = *(TI128 *)vars;
                        func_00282D30(vec, vec, 1.5f);
                        vec[2] = 1.0f;
                        vec[3] = 5627.9248046875f;
                        func_002A8C00(&hit2, moby, 0x90003, vec, *(float *)(vars + 0x14));
                        hit2.f19 = 1;
                        hit2.f1A = *(u16 *)(moby + 0xAA);
                        hit2.f18 = 0;
                        if (*(s32 *)(base + 0x18) == D_0018C0B0) {
                            func_L00_0035F5A0(0x20, 0, 0);
                        }
                        func_00277F48(moby + 0x10, 0, moby, &hit2, 0.6f);
                        if (moby[0xBC] == 0) {
                            func_002A7750(moby, 1, -1);
                        }
                        return;
                    }
                } else {
                    *(TI128 *)vec = *(TI128 *)vars;
                    func_00282D30(vec, vec, 3.0f);
                    vec[2] = 1.0f;
                    vec[3] = 5627.9248046875f;
                    func_002A8C00(&hit2, moby, 0x90003, vec, *(float *)(vars + 0x14));
                    hit2.f19 = 1;
                    hit2.f1A = *(u16 *)(moby + 0xAA);
                    hit2.f18 = 0;
                    if (moby[0xBC] == 0) {
                        func_002A7750(moby, 1, -1);
                    }
                    return;
                }
            }
            if (moby[0xBC] == 0) {
                *(TI128 *)(moby + 0x10) = *(TI128 *)move;
            }
            func_00282D30(vec, vars, -0.5f);
            func_00282C88(&hit2);
            break;
        case 1:
            func_0032C700(moby + 0x10, 0, 25, 25, 25, 25, 0, 0, 1.0f, 20.0f, 1, 0, 0, 0);
            func_0029F338(moby);
            return;
        }
    }
    func_002ACEC0(moby + 0xE0, moby + 0xE0, moby + 0xD0, D_L23_001B1AE4 * 0.017453294f);
    func_002ACEC0(moby + 0xC0, moby + 0xC0, moby + 0xD0, D_L23_001B1AE4 * 0.017453294f);
    func_L00_002E6EF8((void *)func_L13_0040DE50, moby);
    v = *(s32 *)(vars + 0x2C) + 2;
    *(s32 *)(vars + 0x2C) = v;
    if (v > 0x40) {
        *(s32 *)(vars + 0x2C) = 0x40;
    } else if (v < 0) {
        *(s32 *)(vars + 0x2C) = 0;
    }
}
