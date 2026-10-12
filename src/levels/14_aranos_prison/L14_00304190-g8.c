#include "include_asm.h"

/* This unit is built with -G8: these two bodies reach a global through $gp. */

/* Quadword copy, as the game's own macro wrote it (lq/sq through a materialised address). */
static __inline__ void qcopy(void *dst, void *src) {
    __asm__ __volatile__("lq $2,0x0(%1)\n\tsq $2,0x0(%0)" : : "r"(dst), "r"(src) : "$2", "memory");
}

extern int D_001A79F0;
extern int D_001A72E0;
extern int D_L14_001B23D0 __attribute__((sda));
extern int D_L14_001B259C __attribute__((sda));
extern char D_L14_00284690[];

extern void func_367708();
extern void func_3674A0();
extern void func_367778();
extern void func_385CB8(unsigned int reg, unsigned long value);
extern void func_L14_00304190();

void func_L14_00304280(void) {
    func_367708();
    D_L14_001B23D0 = (int)D_L14_00284690;
    if (D_001A79F0 == 0xE) {
        func_L14_00304190();
    } else {
        func_3674A0();
    }
    func_367778();
    func_385CB8(0x47, 0x5360B);
    func_385CB8(0x4E, 0x1000000 | (D_001A72E0 >> 13));
}

INCLUDE_ASM("asm/levels", func_L14_003E5030);
