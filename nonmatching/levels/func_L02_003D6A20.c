/* func_L02_003D6A20, 396 bytes, 1 placement (level 2).  Near miss with the opt-in `-frac2-qcopy`
   profile (#262) plus `-g`, in a -G8 unit of its own (src/levels/02_maktar_nebula/
   L02_003D6A20-g8.c, flags `-O2 -G8 -ffunction-sections -frac2-qcopy -g`; -G8 for D_L02_001B0344,
   D_L02_001B0370 and D_L02_001B0374 at `$gp + 0x1354 / 0x1380 / 0x1384`): the C below is retail's
   396 bytes and every word up to the first copy of the loop is exact: the frame (0xF0, ten saved
   registers s0-s7/fp/ra and $f20), the prologue, the struct at $sp (0x90 bytes: four 16-byte
   vectors, the 0x40-0x6C fields, an untouched tail), `lw v0,0x1354($gp) ; nop ; nop ; div.s`, the
   guard `blez`, and the loop's set-up, which is the rotated loop's four strength-reduced pointers
   (s3 = T1[i], s4 = T2[i], s1 = T1[i+1], s2 = T2[i+1] by `daddu s4,v0` / `daddu s3,v1` /
   `addiu s2,v0,0x10` / `addiu s1,v1,0x10` after the guard) and the three address registers
   fp/s7/s6.  15 of its 99 words differ (tools/check.py: 0 of 1 places match, first difference at
   +0xD8, the instruction after the first of the four copies in the loop).
   The one difference left is wall (2).  Retail:
        lq/sq (s3 -> sp) ; lq/sq (s4 -> fp) ; lq/sq (s1 -> s7) ; lq/sq (s2 -> s6) ; daddu a0,s0 ; jal ;
        addiu s2,s2,0x10 ; addiu s0,s0,1 ; mul.s ; lw a0 ; lw a1 ; addiu s1 ; addiu s4 ; addiu s3 ; jal
   this unit moves `daddu a0,s0`, `addiu s0,s0,1` and `addiu s4,s4,0x10` up between the copies:
        lq/sq ; daddu a0,s0 ; lq/sq ; addiu s0,s0,1 ; lq/sq ; addiu s4,s4,0x10 ; lq/sq ; jal ;
        addiu s1 ; addiu s2 ; mul.s ; lw ; lw ; addiu s3 ; jal
   Retail's copy was a volatile asm, a barrier for both scheduling passes, and `rac2_qcopy` is an
   ordinary insn.  Measured in a scratch copy (not allowed in src/): with
   `__asm__ __volatile__("" : : : "memory");` after each of the four copies the loop body and what
   follows it are exact (the scratch then moves three preheader address insns, an effect of the
   asm statements in the loop; the C below has them in retail's order).
   The two nops before the division are the assembler's padding of a `div.s` that follows a code
   label by fewer than two slots (docs/COMPILER-NOTES.md, "Debug line labels pad divisions"): cc1
   has no label between the `lw` and the `div.s`, and `-g` puts a line label before each source
   line, so the unit takes `-g` and the division stays on a line of its own.  Without `-g` the build
   is 388 bytes, the two nops short; no source shape measured gives them (the loop as `for`,
   `while` or `do` after an `if`, an early `return`, the divisor in a float of its own, the guard
   written out, `i`/`prev` set in the for-init: all identical).  Of retail's 1,744 `div.s`, 1,020
   have the two nops and only 162 of those a branch target within two slots, so most of its
   division padding has a cause this assembler does not model.
   Source notes found on the way (all measured):
   - the base pointers must be C pointers set INSIDE the loop (`t1 = D_L02_002415C0` as the first
     statement of the body): `D_L02_002415C0[i]` written directly is not strength-reduced (372
     bytes, an `sll`/`addu` per access and per iteration), and the pointers set before the loop put
     the two `lui` pairs above the guard instead of after it, as retail has them;
   - `prev` must stay out of the stores of the call result: `r = call(); ...; prev = r;` after the
     two stores of `r` keeps the stores on $v0 and gives `prev` the low priority that puts it in
     $s5 (with `prev = r` before the two stores they use $s1 and the four pointers shift down);
   - the two adjacent stores of `prev` are written `s.e1` first, `s.e0` second, which comes out as
     retail's `sw s5,0x40` then `sw s5,0x44`;
   - `func_00283CE0` returns a float (the `D - 1` and `i` calls), `func_00283D38(int, int, float)`
     returns the int that is stored twice.
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.
   Body measured in that unit: */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    TI128 p0;
    TI128 t0;
    TI128 p1;
    TI128 t1;
    int e0;
    int e1;
    int e2;
    int e3;
    int z50;
    int z54;
    int z58;
    float f5c;
    float f60;
    int z64;
    float f68;
    float f6c;
    char pad70[0x20];
} L02_003D6A20_Seg;

extern int D_L02_001B0344 __attribute__((sda));

extern int D_L02_001B0370 __attribute__((sda));

extern int D_L02_001B0374 __attribute__((sda));

extern TI128 D_L02_002412A0[];

extern TI128 D_L02_002415C0[];

extern void func_00281DE8(void *, int, int, int);

extern float func_00283CE0(int);

extern int func_00283D38(int, int, float);

extern void func_00280B90(void *, int, int);

void func_L02_003D6A20(void) {
    L02_003D6A20_Seg s;
    int i;
    int prev;
    float step;
    float t;
    int r;
    TI128 *t1;
    TI128 *t2;

    if (D_L02_001B0344 >= 2) {
        func_00281DE8(&s, 0x2B, 1, 0x80);
        s.z50 = 0;
        s.z54 = 0;
        s.z58 = 0;
        s.f5c = 1.0f;
        s.f60 = 1.0f;
        s.z64 = 0;
        s.f68 = 1.0f;
        s.f6c = 1.0f;
        prev = 0;
        step = 1.0f / func_00283CE0(D_L02_001B0344 - 1);
        for (i = 0; i < D_L02_001B0344 - 1; i++) {
            t1 = D_L02_002415C0;
            t2 = D_L02_002412A0;
            s.p0 = t1[i];
            s.t0 = t2[i];
            s.p1 = t1[i + 1];
            s.t1 = t2[i + 1];
            t = func_00283CE0(i) * step;
            r = func_00283D38(D_L02_001B0374, D_L02_001B0370, t * t);
            s.e1 = prev;
            s.e0 = prev;
            s.e3 = r;
            s.e2 = r;
            prev = r;
            func_00280B90(&s, 0, 0);
        }
    }
}
