/* Near miss: func_L07_00410930 (src/levels/07_siberius/L07_003F4578.c), 532 bytes, the size of
   retail's. Compile it as a -g8 file (it takes the address of the $gp object D_L07_001B1730
   outside a delay slot).

   Everything after the call to func_L00_002B9D60 matches word for word at its place: the three
   id-list walks (two over 32-byte records clearing and setting bit 2 of the byte at +0x1E, one
   over 64-byte records lowering the float at +0x38 by 100.0 and calling func_L00_0036AE00), the
   group-word tables, the final store. The two struct views (the object's flag word and counter,
   the state's two group words) are what lets the scheduler lift the load of the group table
   D_L07_001A9014 above the stores to the object, as retail has it, and the third walk needs its
   own pointer variable (q), which is what gives retail's a1 for the first two walks and s0 for the
   third.

   Only the front differs, and that is the 128-bit zero wall: retail zeroes the vector with

     por v0,zero,zero ; ... ; sq v0,0x10(sp)        (the register is rewritten by the lq that
                                                      copies the vector into the argument slot)

   and the chain's rac2_fold_zero_ti_store (tools/compiler/transformers/fold_zero_ti_store.py)
   folds a zero TImode register into the store when the register is dead afterwards, so this prints
   `sq $zero,0x10(sp)`. One word fewer, which also removes the loop-head alignment: mine has a nop
   before the first walk's top that retail does not need (hence the same total size), and the
   prologue saves and argument setup are scheduled in another order around the missing `por`.
   Tried for the zero: `*(TI128 *)v = 0`, two zero stores with one dead (cse deletes it and the
   fold still applies), a TI128 variable holding the zero, aggregate initialisers (memset calls or
   word stores). None keeps the register live at the pass.

   Written as a volatile asm `por`/`sq` pair in a scratch copy (not allowed in src/) the pair is
   emitted, but after the prologue saves (120 of 133 words): retail's `por` is hoisted above them,
   so it is an ordinary schedulable instruction, a zero the compiler put in a register, not an asm
   macro. Counted over the retail programs (a shared function once per program), 3,793 `por` feed an
   `sq` with a non-zero offset and 1,048 one with a zero offset, and 3,066 `sq $zero` have a
   non-zero offset, so the offset is not what separates the two forms.

   Would unblock it: the fold pass declining when the store is the only user and the
   materialisation is hoisted to the block head (retail has thousands of such pairs), or a way to
   keep the zero register live past the pass. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

/* The object up to its flag word, its state pointer and its counter. */
typedef struct {
    u8 pad00[0x34];
    u16 flags34;
    u8 pad36[0x68 - 0x36];
    u8 *state;
    u8 pad6c[0x98 - 0x6C];
    s32 f98;
} SibObj;

/* The state record up to its two group words. */
typedef struct {
    u8 pad00[0xCC];
    s32 groupCC;
    s32 groupD0;
} SibGroups;

extern f32 D_L07_001B173C;

extern u8 D_L07_001B1730 __attribute__((sda));

extern u16 **D_L07_001A9014;

extern u8 *D_L07_001B2954;

extern u8 *D_L07_001B295C;

extern s32 D_L07_001B1E90;

extern void func_L00_002B9D60(void *obj, void *pos, s32 a2, s32 a3);

extern void func_L00_0036AE00(s32 id, s32 a1);

/* Switches the object to its second phase. */
void func_L07_00410930(SibObj *a0)
{
    f32 arg[4];
    f32 v[4];
    SibGroups *state;
    u16 *p;
    u16 *q;
    u8 *e;

    *(TI128 *)v = 0;
    v[2] = D_L07_001B173C;
    *(TI128 *)arg = *(TI128 *)v;
    state = (SibGroups *)a0->state;
    func_L00_002B9D60(&D_L07_001B1730, arg, 0, 1);
    a0->flags34 |= 2;
    a0->f98 = 0;
    for (p = D_L07_001A9014[state->groupD0];
         p != 0 && ((s16)p[-1] >= 0 || p == D_L07_001A9014[state->groupD0]) &&
         (e = D_L07_001B2954 + ((*p & 0x7FFF) << 5)) != 0;
         p++) {
        e[0x1E] &= 0xFB;
    }
    for (p = D_L07_001A9014[state->groupCC];
         p != 0 && ((s16)p[-1] >= 0 || p == D_L07_001A9014[state->groupCC]) &&
         (e = D_L07_001B2954 + ((*p & 0x7FFF) << 5)) != 0;
         p++) {
        e[0x1E] |= 4;
    }
    for (q = D_L07_001A9014[state->groupCC];
         q != 0 && ((s16)q[-1] >= 0 || q == D_L07_001A9014[state->groupCC]) &&
         (e = D_L07_001B295C + ((*q & 0x7FFF) << 6)) != 0;
         q++) {
        *(f32 *)(e + 0x38) -= 100.0f;
        func_L00_0036AE00(*q & 0x7FFF, 1);
    }
    D_L07_001B1E90 = 2;
}
