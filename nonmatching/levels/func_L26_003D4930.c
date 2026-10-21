/* Near miss: func_L26_003D4930 (src/levels/26_jamming_array/L26_002EC840.c), 436 bytes, 1 place.
   With the opt-in `-frac2-qcopy` profile (#262) in a unit of its own
   (src/levels/26_jamming_array/L26_003D4930-g8.c, flags `-O2 -G8 -ffunction-sections -frac2-qcopy`;
   -G8 because the group count is read through $gp, in a delay slot) the C below is retail's 436
   bytes and matches word for word up to the last statement: the prologue, the stamp test that opens
   the group walk (D_L26_001B1C1C is the bare `lui`/`lw` of the second name below, the group count
   the delay-slot $gp load), the walk and its callback registration (func_L26_003D4AE8, matched), the
   signed `% 8` phase (`movn` form), the ring advance, both calls, and the copy's own insns
   (`lw v1,0x194(s2) ; addiu a0,s1,0x10 ; sll ; addu v1,v1,s2 ; addiu v1,v1,0x80 ; lq v0,0(a0) ;
   sq v0,0(v1)`), which the profile now makes retail's register-address form.  9 of its 109 words
   still differ (tools/check.py: 0 of 1 places match, first difference at +0x188), and all of them
   are the epilogue around that copy:

     retail  lw v1,0x194(s2) ; addiu a0,s1,0x10 ; sll ; addu ; addiu ; lq ; sq ;
             ld s0 ; ld s1 ; ld s2 ; ld ra ; jr ra ; addiu sp,sp,0x20
     here    lw v1,0x194(s2) ; addiu a0,s1,0x10 ; ld s0 ; sll ; ld s1 ; addu ; ld ra ; addiu ;
             ld s2 ; lq ; sq ; jr ra ; addiu sp,sp,0x20

   Cause (measured, sched2 trace of the last block): the four restores are frame loads
   (`mem/u`, unchanging reads, so they never depend on the copy's store) and become ready when the
   second call retires; the copy needs the 5-cycle chain `lw ; sll ; addu ; addiu`, and the loads
   fill its cycles (priority 5: cost 2 plus the blockage; the copy has no unit, cost 1, priority
   4).  Retail's copy was a volatile asm, a barrier, so the restores stayed behind it.  Measured in
   a scratch copy (not allowed in src/): with the copy as one volatile asm,
   `__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(state + *(int *)(state + 0x194) * 16
   + 0x80), "r"(a0 + 0x10) : "$2", "memory")`, the same C is exact up to the operand order of the
   address add, and with the address spelled `*(int *)(state + 0x194) * 16 + (int)state + 0x80`
   inside that asm it is exact (1 of 1 places); it is also exact, with the C below as it stands,
   when the profile's own copy is kept and `__asm__ __volatile__("" : : : "memory");` is written
   right after it (the barrier after the copy is what matters).  None of -fno-schedule-insns,
   -fno-schedule-insns2,
   -fno-sched-interblock, -fno-gcse, -mno-split-addresses, -fno-strength-reduce, -g gets the
   profile build below 9 words.
   What would unblock it: a barrier form of the profile (the pattern given a volatile asm's
   dependences in sched_analyze_insn, as -frac2-zero-ti-barrier does for the clear); the C below
   would then go into that unit unchanged.

   Earlier tries on the copy's address (kept for the record, all irrelevant now that the profile
   materialises it): pointer locals for source and destination, `(TI128 *)(state + 0x80) + idx`
   and `((TI128 *)(state + 0x80))[idx]`, the base kept in a `u8 *` local, a struct view of the
   state, a one-member struct around the TI128, a TI128 temporary. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L26_001B1C38 __attribute__((sda));

extern u8 *D_L26_001B1C1C_1[3] __attribute__((sda));

extern u16 *D_L26_001FA6E0[];

extern int D_L26_001B1748;

extern void func_002AB6D8(u8 *, u8 *);

extern void func_002A91F0(u8 *, u8 *);

extern void func_L00_002E6CF0(void *, u8 *);

extern void func_L26_003D4AE8(u8 *a0);

/* Every 8th tick of the frame word D_L26_001B1748 the object's ring of eight samples advances; the
   object's rotation angles are refreshed from its matrix, the matrix of the current slot is
   rebuilt from them and the object's position vector is copied into the slot's 16-byte record.
   When the state's stamp (+0x19C) differs from the frame word, every entity of the object's group
   is stamped and the object is registered with func_L26_003D4AE8 first. */
void func_L26_003D4930(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    float phase;

    if (*(int *)(state + 0x19C) != D_L26_001B1748) {
        for (p = D_L26_001FA6E0[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L26_001B1C38 && p != 0 &&
             ((p != 0 && (short)p[-1] >= 0) || p == D_L26_001FA6E0[a0[0x21]]);
             p++) {
            e = D_L26_001B1C1C_1[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            *(int *)(*(u8 **)(e + 0x68) + 0x19C) = D_L26_001B1748;
        }
        func_L00_002E6CF0((void *)func_L26_003D4AE8, a0);
    }
    phase = (float)(D_L26_001B1748 % 8) * 0.125f;
    *(float *)(state + 0x198) = phase;
    if (phase == 0.0f) {
        *(int *)(state + 0x194) = (*(int *)(state + 0x194) + 1) % 8;
        if (*(int *)(state + 0x190) < 8)
            *(int *)(state + 0x190) = *(int *)(state + 0x190) + 1;
    }
    func_002AB6D8(a0 + 0xC0, a0 + 0xF0);
    func_002A91F0(state + 0x100 + *(int *)(state + 0x194) * 16, a0 + 0xF0);
    *(TI128 *)(state + 0x80 + *(int *)(state + 0x194) * 16) = *(TI128 *)(a0 + 0x10);
}
