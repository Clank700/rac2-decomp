/* Near miss (level 2, one place): 332 bytes against retail's 336.
 *
 * The frame (0x30 bytes with $s0-$s2/$ra/$f20), the calls, the stores up to the copy and the
 * code after it are retail's instructions; what differs is the destination address of the
 * 16-byte copy and the schedule that follows from it. Spelling notes: the angle is
 * func_002A7878(0.0f, 1.5707965f) (retail's constant is 0x3FC90FDC), and the two halfword
 * stores to +0x34 stay two only when the load through the +0x24 record sits between them
 * (written as one expression, or as two statements with nothing between, cc1 folds them to a
 * single `andi 0xFFFC` and one store).
 *
 * The copy takes the 16 bytes at D_L02_001B01C0 ($gp + 0x11D0, small data) into +0x10 of the
 * object. Retail holds both addresses in registers and copies through them:
 *     addiu $a2,$s1,0x10        (destination, hoisted next to the first stores)
 *     addiu $a1,$gp,0x11D0      (source)
 *     lq    $v0,0($a1)
 *     sq    $v0,0($a2)
 * This cc1 keeps the source address in a register but folds the destination into the store,
 * `sq $v0,0x10($s1)`, so the `addiu $a2` is missing (the 4 bytes) and the registers of the two
 * address pairs rotate. It is the constant-offset tie in cse's find_best_addr (see
 * docs/COMPILER-NOTES.md, "The 128-bit copy wall").
 *
 * Measured: replacing the destination by an opaque register (a non-volatile empty asm taking
 * `arg0 + 0x10` and returning it, used only to measure; nothing like it is allowed in src/)
 * gives exactly 336 bytes and leaves two differences: retail emits the destination address
 * before the source address (here the source first, $a3/$a1 instead of $a2/$a1), and retail
 * keeps the hero block's `lui $v1,0x19` after the `sq`, where this scheduler hoists it above
 * the flag stores.
 *
 * Tried, all folding the destination: the pointer in a local (`TI128 *d`), a TI128 member of a
 * struct (`((Obj *)p)->pos = ...`), a one-member struct of TI128, a static inline copy helper
 * taking TI128 * or char * parameters, an aligned float aggregate (that gives ld/sd pairs), the
 * source and destination in either order.
 *
 * What would unblock it: a spelling of the copy that makes cse keep `arg0 + 0x10` as a value
 * (retail's shape is what an asm quadword-copy macro with "r" operands produces, which src/
 * does not allow), or a compiler-side change of the address cost tie.
 */

typedef int TI128 __attribute__((mode(TI)));

extern float func_002A7878(float, float);

extern void func_002A7750(char *, int, int);

extern void func_002A0488(char *, int, int, int);

extern void func_L02_003D4AF0(char *, int);

extern void func_L02_003D5570(char *);

extern float func_00283248(float, float);

typedef struct {
    char pad0[0x80];
    float x;
    float y;
} L02_003D7900_Hero;

extern L02_003D7900_Hero D_00189E20;

extern int D_L02_001B01C0 __attribute__((sda));

void func_L02_003D47B0(char *arg0, int arg1) {
    char *state = *(char **)(arg0 + 0x68);
    float r;
    L02_003D7900_Hero *hero;

    *(float *)(state + 0x20) = (float)*(short *)(state + 0x24);
    r = func_002A7878(0.0f, 1.5707965f);
    *(float *)(state + 0x304) = 0.0f;
    *(short *)(state + 0x32C) = 0;
    *(int *)(state + 0x300) = 0;
    *(short *)(state + 0x32A) = 0;
    *(short *)(state + 0x98) = 0;
    *(float *)(state + 0x2F4) = r;
    func_002A7750(arg0, 2, 1);
    func_L02_003D4AF0(arg0, 1);
    *(unsigned char *)(state + 0x7A) = 0;
    *(unsigned char *)(state + 0x2E) = 1;
    *(unsigned char *)(arg0 + 0x31) = 1;
    *(unsigned short *)(arg0 + 0x34) = *(unsigned short *)(arg0 + 0x34) & 0xFFFE;
    *(int *)(arg0 + 0x98) = *(int *)(*(char **)(arg0 + 0x24) + 0x10);
    *(unsigned short *)(arg0 + 0x34) = (*(unsigned short *)(arg0 + 0x34) | 0x1000) & 0xFFFD;
    *(unsigned char *)(arg0 + 0x7F) = 0;
    *(TI128 *)(arg0 + 0x10) = *(TI128 *)&D_L02_001B01C0;
    hero = &D_00189E20;
    *(float *)(arg0 + 0xF8) = func_00283248(hero->x - *(float *)(arg0 + 0x10),
                                            hero->y - *(float *)(arg0 + 0x14));
    *(int *)(state + 0x310) = 0;
    *(short *)(state + 0x318) = 0;
    func_L02_003D5570(arg0);
    *(short *)(state + 0x31A) = 0;
    if (*(short *)(state + 0x60) != 0) {
        *(short *)(state + 0x60) = 0;
        func_002A0488(arg0, *(unsigned char *)(state + 0x64),
                      *(unsigned char *)(state + 0x65),
                      *(unsigned char *)(state + 0x66));
        *(short *)(state + 0x62) = 1;
    }
    *(short *)(state + 0x330) = arg1;
}
