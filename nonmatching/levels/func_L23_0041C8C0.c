/* func_L23_0041C8C0 (408 bytes, level 23 only) -- NEAR MISS, not integrated.
   Belongs in src/levels/23_damosel_orbit/L23_00416388.c (no $gp access, default -G0).
   state: 408 bytes, retail's size, but 26 of the 102 words differ: register numbering and
   instruction order, plus one `nop` here (the assembler's pad before the loop head) where
   retail has the row-pointer copy `daddu $v1,$v0,$zero`:
   - Block 0: retail builds the row address in $v0 (`lui $v0,%hi(D_L23_00259050); addiu;
     addu $v0,$a0,$v0`), loads the first word into $v1, and copies the row pointer into $v1
     for the walk (`daddu $v1,$v0,$zero`), with the loop constant 49 in $a0. This C puts the
     row address in $a0, the first word in $v0, no copy, the walk pointer in $a0 and 49 in
     $v1. Cause measured with the allocator dumps: local-alloc gives the first-word load
     (shorter life) the first register and the address pair the next, retail's order is the
     other way round; global-alloc then prefers $a0 for the row pointer because the multiply
     result lives there.
   - The prologue: retail writes `daddu $s1,$a2,$zero` right after `sd $s1`, this C after
     `sd $s0`.
   - The tail: retail schedules `sll $a0,$s1,2` before `lui $v0,%hi(D_L23_001B3738)` and the
     `lq $a1,0($sp)` after the first counter increment; this C reverses both.
   What is already exact and should be kept: the search loop (`i == 49` test inside the loop,
   which gives retail's `bne $s0,$a0` and the hoisted -1), the three stores through
   `D[type][i]` (a fixed row `D[1][i]` flips the `addu` operands), and the `do { } while (0)`
   around the search: its loop note stops the scheduler from moving the 16-byte copy
   below the multiply, as retail has it first.
   Tried without gain (about 60 compiles, shapes of the walk and of the guard, two pointer
   names, an inline finder, the order and spelling of the three tail statements, the type of
   the table words): none moved the block-0 allocation.
   The by-value quad argument is a pointer plus a 16-byte local copy here: a TI128 value kept
   across the calls is saved in a callee-saved register pair by this cc1, retail keeps it in
   memory. The callees' real prototypes are unknown. */

typedef int TI128 __attribute__((mode(TI)));

extern void *D_L23_00259050[3][60];
extern int D_L23_001B3738[3];
extern int D_L23_001B3744 __attribute__((sda));
extern void *func_L22_003FB1F8(void *, TI128 *, int, float);
extern void *func_L22_003FC780(void *, TI128 *, int, float);
extern void *func_L22_003FD1E8(void *, TI128 *, int, float);

int func_L23_0041C8C0(void *obj, TI128 *pos, int type, int arg3) {
    char buf[16] __attribute__((aligned(16)));
    int i;
    char *slot;

    *(TI128 *)buf = *pos;
    do {
        for (i = 0; i < 50; i++) {
            if (D_L23_00259050[type][i] == 0)
                break;
            if (i == 49) {
                i = -1;
                break;
            }
        }
    } while (0);
    if (i != -1) {
        switch (type) {
        case 0:
            D_L23_00259050[type][i] = func_L22_003FB1F8(obj, pos, arg3, 4.0f);
            break;
        case 1:
            D_L23_00259050[type][i] = func_L22_003FC780(obj, pos, arg3, 3.65f);
            break;
        case 2:
            D_L23_00259050[type][i] = func_L22_003FD1E8(obj, pos, arg3, 3.65f);
            break;
        }
        slot = D_L23_00259050[type][i];
        if (slot != 0) {
            D_L23_001B3744++;
            D_L23_001B3738[type]++;
            *(TI128 *)(slot + 0x10) = *(TI128 *)buf;
        }
    }
    return i;
}
