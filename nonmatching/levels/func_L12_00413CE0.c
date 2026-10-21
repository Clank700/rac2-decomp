/* Near miss: func_L12_00413CE0 (src/levels/12_todano/L12_00398E50.c), 452 bytes, 1 place.  With the
   opt-in `-frac2-qcopy` profile (#262) in a unit of its own (src/levels/12_todano/L12_00413CE0-g8.c,
   flags `-O2 -G8 -ffunction-sections -frac2-qcopy`; -G8 for D_L12_001B1840 and D_L12_001B2EB8,
   read through `$gp`) the C below is retail's 452 bytes and the copy has retail's register
   addresses (`addiu v1,v1,0x10 ; lq v0,0(v1) ; sq v0,0(sp)`), which is what the earlier 444-byte
   record lacked.  18 of its 113 words still differ (tools/check.py: 0 of 1 places match, first
   difference at +0x34), all of them in the front, before the walk:

     retail  lw a0,0x2C0(s3) ; beq ; lui v0 ; sll a0 ; addiu v0 ; addu a0 ; lw v1,0(a0) ; addiu v1,v1,0x10
             lq v0,0(v1) ; sq v0,0(sp) ; lbu a0,0x21(s4) ; lui v0 ; addiu v1,v0,lo ; lui at ; ori ; mtc1 f20
             sll a0 ; addu a0,a0,v1 ; lw s2,0(a0) ; daddu s5,zero,zero ; b ; daddu s6,v0,zero
     here    the same instructions, but the `lbu` of the group byte, the second table's `lui`/`addiu`,
             the 100000.0f constant, its `lw s2` and `daddu s5` are scheduled between the first table's
             insns and above the `lq`/`sq`, which moves the allocation of a0/a1/a2/v0/v1 in the front.

   Cause (measured): retail's copy was a volatile asm, a barrier for both scheduling passes, so the
   walk's setup could not move above it; `rac2_qcopy` is an ordinary insn, and the second chain
   (the group byte and the second table) fills the load-latency stalls of the first one.  The
   hoisted insns are pseudo-register computations and loads from the object, which cannot depend
   on the copy's store (its destination is `vec` on the stack).  Measured in a scratch copy (not
   allowed in src/): with the copy as one volatile asm, `__asm__ __volatile__("lq $2,0(%1)\n\tsq
   $2,0(%0)" : : "r"(vec), "r"(D_L12_001FEAC0[state->f2C0] + 0x10) : "$2", "memory")`, the same C
   is exact (1 of 1 places).  None of -fno-schedule-insns, -fno-schedule-insns2,
   -fno-sched-interblock, -fno-gcse, -mno-split-addresses, -fno-strength-reduce, -g gets the
   profile build below 18 words.
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.

   Body of the record: the id-list walk, the best/bestd initialisation after the copy (that is what
   gives s5 = best, s6 = high half of the second table), the PathState member stores (which let the
   scheduler lift the $gp halfword load D_L12_001B1840 above the stores, as retail has it) and the
   second names are all right. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern u16 *D_L12_001FB960[];

/* The path-follower state of an entity: the record fields the nearest-entity hand-over touches. */
typedef struct {
    u8 pad00[0x2B0];
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    u8 pad2C4[0x2D0 - 0x2C4];
    s32 f2D0;
    s32 f2D4;
    u8 pad2D8[0x2DC - 0x2D8];
    s32 f2DC;
    u16 f2E0;
    u8 pad2E2[0x2EA - 0x2E2];
    u8 f2EA;
    u8 pad2EB[0x302 - 0x2EB];
    u8 f302;
    u8 f303;
} PathState;

extern u8 *D_L12_001B2E9C_base[3] __asm__("D_L12_001B2E9C") __attribute__((sda));

extern s32 D_L12_001B2EB8;

extern u16 D_L12_001B1840_h __asm__("D_L12_001B1840") __attribute__((sda));

extern u8 *D_L12_001FEAC0[];

extern f32 func_2F1B20(void *a, void *b);

/* Hands the object's path state to the nearest eligible entity of its group. */
void func_L12_00413CE0(u8 *a0)
{
    PathState *state = *(PathState **)(a0 + 0x68);
    u8 *best;
    f32 bestd;
    f32 vec[4];
    u16 *p;
    u8 *e;
    PathState *sub;
    f32 d;

    if (state->f2C0 != -1) {
        *(TI128 *)vec = *(TI128 *)(D_L12_001FEAC0[state->f2C0] + 0x10);
        best = 0;
        bestd = 100000.0f;
        for (p = D_L12_001FB960[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L12_001B2EB8 && p != 0 &&
             ((p != 0 && (s16)p[-1] >= 0) || p == D_L12_001FB960[a0[0x21]]);
             p++) {
            e = D_L12_001B2E9C_base[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            sub = *(PathState **)(e + 0x68);
            d = func_2F1B20(e + 0x10, vec);
            if (sub != 0 && (sub->f302 & 1)) {
                if (d < bestd) {
                    bestd = d;
                    best = e;
                }
            }
        }
        if (best != 0) {
            PathState *dst = *(PathState **)(best + 0x68);

            dst->f2B0 = state->f2B0;
            dst->f2B4 = state->f2B4;
            dst->f2B8 = state->f2B8;
            dst->f2BC = state->f2BC;
            dst->f2C0 = state->f2C0;
            dst->f2D0 = state->f2D0;
            dst->f2D4 = state->f2D4;
            dst->f2E0 = D_L12_001B1840_h;
            dst->f2DC = state->f2C0;
            dst->f2EA = 1;
            dst->f302 = 2;
            dst->f303 = state->f303;
        }
    }
}
