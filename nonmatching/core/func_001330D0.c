/* from src/core/00131780.c: table base reached gp-relative in retail, absolute here */
/*
 * The slot table at gp - 0x7B50 (0x001A74A0) indexed by the counter at
 * gp - 0x7B30 (0x001A74C0): the pointed-to counter is bumped and the pointer
 * goes to func_00132028 with the store in its delay slot. Retail's base is
 * `addiu $v0,$gp,-0x7B50`, i.e. gas's gp-relative address of the table; with
 * `__attribute__((sda))` on the array in a -g8 file this cc1 still
 * materialises it absolutely (`lui $v1,0 ; addiu $v1,$v1,0`), eight bytes
 * more than the 56 retail has.
 */
extern int *D_001A74A0[] __attribute__((sda));

extern int D_001A74C0 __attribute__((sda));

extern void func_00132028_arg(int *arg0) __asm__("func_00132028");

void func_001330D0(void) {
    int *p = D_001A74A0[D_001A74C0];

    (*p)++;
    func_00132028_arg(p);
}
