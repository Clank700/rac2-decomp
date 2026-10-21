/* func_002A0250 - 172 bytes, 28 places (the boot and every level).
   Screened in wave 13 (worker g4): 3 call(s), 0 $gp-relative small-data access(es), 0 MMI lq/sq word(s), 0 64-bit daddu copy(ies), 0 float constant(s).
   Near miss: the statement order, the three calls and the packet writes match, but this
   cc1 common-subexpression-eliminated the lui of the 0x1Bxxxx data into one register
   (168 bytes against the retail 172) where retail re-materialises it for every access, and
   it splits the two literal addresses (0x10FFC0, 0x100080) as lui+ori where retail uses
   lui+addiu.  The packet pointer is 0x1B2608 in the levels and 0x1B22A8 in the boot, so
   every 0x1Bxxxx word of this body needs a ref_ name.
   Not matched in wave 13 (worker g4): the lui re-materialisation and the constant split
   were not reproduced. */

extern unsigned short D_0010FFB0;
extern char D_0010FFC0[];
extern char D_00100080[];
extern int ref_002A0250_00;
extern char *ref_002A0250_01;
extern int ref_002A0250_02;
extern int ref_002A0250_03;
extern char *ref_002A0250_04;
extern int ref_002A0250_05;
extern int ref_002A0250_06;
extern int ref_002A0250_07;
extern int D_001A72D0;
extern int D_001A72D4;
extern void func_002FC410(unsigned int, unsigned int);
extern void func_002FC070(int);
extern void func_002FC560(unsigned int, unsigned long long);

void func_002A0250(void)
{
    func_002FC410((unsigned int)D_0010FFC0, D_0010FFB0);
    ref_002A0250_00 = 6;
    func_002FC070((int)D_00100080);
    func_002FC560(0x47, 0x5360B);
    ref_002A0250_04 = ref_002A0250_01;
    ref_002A0250_06 = ref_002A0250_02 + 0xFFFF0000;
    ref_002A0250_05 = ref_002A0250_03;
    D_001A72D0 = D_001A72D4;
    ref_002A0250_01 = ref_002A0250_01 + 0x10;
    ref_002A0250_07 = 0;
}
