/* func_00298E08, near miss (not linked): 248 bytes, the same size as retail's, in the -G8
   unit src/game/00298838.c. The prologue differs: this cc1 interleaves the base-address setup
   (lui into a temporary, copied into $s0) with the register saves, where retail saves $s0 and
   $ra, takes the address of p, then loads the base straight into $s0 (lui/addiu) after the $ra
   save. That is the prologue interleaving recorded in COMPILER-NOTES.md. The epilogue's
   store order and register choice are not settled: the order search compared text with the
   immediates masked, so it could not see the store offsets. Separate aliases for the two uses
   of D_001A7B90 stop the address being kept across the calls, and sda aliases give retail's
   bare-symbol scalar loads and stores. Moving the base into the first call instead gives 256
   bytes. */
extern int D_001393E0[];

extern void func_00288970(int, void *);
extern void func_002B7CE0(int);
extern void func_002B7C80(int, int, int);
extern void func_00282AB0(void *, void *, int);
extern char D_0014B540[];
extern char D_001A7B90[];
extern int D_001A79F0[] __attribute__((sda));
extern int D_001A7290[] __attribute__((sda));
extern int D_001A72C0[] __attribute__((sda));
extern int D_00152C00[];
extern int D_001A7424_1[] __attribute__((sda));
extern int D_001A7424_2[] __attribute__((sda));
extern char D_001A7B90_1[];

void func_00298E08(void)
{
    char buf[40];
    char *p;
    char *s0 = D_0014B540;
    int *st;
    int x;

    func_00288970(*(int *)(s0 + 0x344) << 11, &p);
    func_002B7CE0(1);
    func_002B7C80((int)p, *(int *)(s0 + 0x340) + *(int *)(s0 + 0x32C), *(int *)(s0 + 0x344));
    s0 = p;
    s0 += *(int *)(s0 + 0x10);
    func_00282AB0(buf, D_001A7B90, 40);
    func_00298D28((int *)s0);
    func_00282AB0(D_001A7B90_1, buf, 40);
    D_001A79F0[0] = 0;
    st = D_001393E0;
    if (st[0x17C / 4] != 0)
        st[0x17C / 4] = 0;
    if (*(short *)((char *)st + 0x18) >= 0)
        *(short *)((char *)st + 0x18) = -1;
    x = D_001A7424_1[0];
    D_00152C00[6] = -1;
    x &= ~0x200;
    D_001A7290[0] = -1;
    D_001A7424_2[0] = x;
    D_001A72C0[0] = -1;
    D_00152C00[12] = -1;
}
