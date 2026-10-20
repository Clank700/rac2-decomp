/* func_002B4B70 (boot function, 116 bytes; 27 levels, 28 places in all).
 * Near miss: compiles to 116 bytes, the retail size; tools/check.py stops at
 * "instruction at +0x4 differs" for the boot (the full place count was not
 * run for this exact version). Meant for 002B3868-g8.c (-G8): the $gp globals
 * are sda, the absolute ones nosda. What still differs: (1) the first test of
 * status: the retail keeps status in $t0 and tests the xor result with movz,
 * while the C makes cc1 if-convert it to sltu into another register, so the
 * registers of the whole function are permuted; (2) the table D_001A8BB8 is a
 * bare symbol in the retail (lui $v0 ; lw, and lui $at ; sw), where the C gets
 * an explicit lui into $t2 that is reused for the store. Tried without
 * success: the stores in an if (status == 0) block with the return at the
 * join (108 bytes), D_001A8BB8 as an incomplete array (108 bytes), and the
 * function in 002B3868.c (-G0), where the sda declarations of the $gp globals
 * come out absolute (132 bytes).
 */
extern int D_001AA100 __attribute__((sda));
extern int D_001AA0F8 __attribute__((sda));
extern int D_001AA0FC __attribute__((sda));
extern int D_001AA104 __attribute__((sda));
extern int D_0018C2EC __attribute__((nosda));
extern int D_001A8BB8 __attribute__((nosda));
extern int D_001B1D50[];

int func_002B4B70(int value, int index)
{
    int count = D_001AA100;
    int status = 1;
    int n;

    if (D_001A8BB8 == -2)
        status = 0;
    if (count == 0)
        status = 1;
    if (D_0018C2EC == 0)
        status = -1;
    if (status != 0)
        return status;
    D_001AA0F8 = value;
    n = count - 1;
    D_001AA0FC = index;
    value = D_001B1D50[n];
    D_001AA100 = n;
    D_001A8BB8 = value;
    D_001AA104 = 0;
    return status;
}
