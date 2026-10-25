/* Near miss: 348 bytes, expected 352, 0 of 1 place (level 05 feltzin).
 *
 * Profile: -O2 -G8 -ffunction-sections.
 * Last verdict: `python scratch/wslcmp.py src/levels/05_feltzin_system/L05_00314E28-g8.c func_L05_0041FE98`
 *   func_L05_0041FE98: 0 of 1 places match   [05_feltzin_system: 348 bytes, expected 352]
 *
 * Remaining difference: the constant 1 lands in $a0 here and in $a1 in retail,
 * the state-block address is materialised before the first call here and in
 * its delay slot in retail, and the table word needs retail's `daddu` copy of
 * the shared table address (`addu a0,v1,v0; lw v0,0(a0); daddu v1,a0; sw
 * v0,0x14(v1)`).  The whole reset, the two cached-record shutdowns and the
 * eight-word snapshot copy match.
 */
/* The full reset: the same record and snapshot copy as func_L05_0041FC60, plus
   the table entry's pending word, the frame hooks and the shutdown of the two
   cached records. */
extern char D_L05_002A1800[];
extern int func_002ED8A0(void);

void func_L05_0041FE98(void)
{
    char *p = (char *)D_L05_00221D10;
    int index;

    func_L05_0037B210();
    func_L05_00379F18(1);
    D_L05_001B1360 = -2;
    *(int *)(p + 0x2C) = 1;
    *(int *)(p + 0x28) = 100;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0xC) = 0;
    D_L05_001B13E8 = 1;
    D_L05_001B1364 = 0;
    *(int *)(p + 0x14) = 0;
    index = func_002ED8A0();
    D_L05_001B13F0 = 0;
    *(int *)(D_L05_002A1800 + index * 0x28 + 0x14)
        = *(int *)(D_L05_002A1800 + index * 0x28 + 0x10);
    func_L05_0037D6E8();
    func_L05_00379F68();
    func_L05_00445A98();
    *(float *)(p + 0x30) = 8.0f;
    func_L05_00379F28(0);
    if (D_L05_001B13B4 != 0) {
        func_0029F338(D_L05_001B13B4);
        D_L05_001B13B4 = 0;
    }
    if (D_L05_001B13B8 != 0) {
        func_0029F338(D_L05_001B13B8);
        D_L05_001B13B8 = 0;
    }
    D_L05_001B2000 = D_L05_001B3558;
    D_L05_001B2001 = D_L05_001B3559;
    D_L05_001B2002 = D_L05_001B355A;
    D_L05_001B2008 = D_L05_001B3560;
    D_L05_001B2010 = D_L05_001B3568;
    D_L05_001B2004 = D_L05_001B355C;
    D_L05_001B200C = D_L05_001B3564;
    D_L05_001B2014 = D_L05_001B356C;
}

