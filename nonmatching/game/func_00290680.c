/* func_00290680, near miss (not linked): 152 bytes compiled against retail's 148.
   Apart from one nop, the instructions agree with retail (the $gp displacements are
   relocations and were not compared): the branch layout, both clamps and the float
   constants. The nop sits between the mfc1 that moves the converted int into $a3 and the
   beqz that tests it; retail has no nop there (it branches on an mfc1 result directly at
   002C4C34 and 002C4C48). Same result with the sdk profile of src/game/00290670.c and with
   the game profile of a -g8 sibling. */
extern int D_001A9014 __attribute__((sda));
extern int D_001A9018 __attribute__((sda));
extern void func_0027DDC0(int, int, int, int);

void func_00290680(void)
{
    int n;
    int r;

    if (D_001A9018 != 0) {
        D_001A9018 = 0;
        n = D_001A9014 + 1;
        D_001A9014 = n;
        if (n >= 11)
            D_001A9014 = 10;
    } else {
        n = D_001A9014 - 1;
        D_001A9014 = n;
        if (n < 0)
            D_001A9014 = 0;
    }
    r = (int)((float)D_001A9014 * 0.1f * 48.0f);
    if (r != 0)
        func_0027DDC0(0, 0, 0, r);
}
