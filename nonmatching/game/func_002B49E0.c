/* func_002B49E0 (boot function, 396 bytes; 27 levels, 28 places in all).
 * Near miss: compiles to 396 bytes, the retail size; tools/check.py reports
 * "instruction at +0x28 differs" for the boot and 0 of 28 places in all. Meant
 * for 002B3868-g8.c (-G8): the $gp globals are sda, the absolute ones nosda.
 * What still differs: the absolute loads come out as an explicit lui and an
 * lw into another register, where the retail loads the symbol into the same
 * register it uses as the base (D_001A8BB8, D_001A79F0, D_001A8BB0 and the
 * table address), and two stores are in another order. D_001A79F0 has two
 * names (an assembler alias for the second): with one name cc1 kept its
 * address in $s3 across the call, and the frame came out 0x30 (404 bytes).
 * Tried: the function in 002B3868.c (-G0), where the sda declarations of the
 * $gp globals come out absolute (420 bytes).
 */
extern int D_001AA100 __attribute__((sda));
extern int D_001B1D50[];

extern int D_001AA0F8 __attribute__((sda));
extern int D_001AA0FC __attribute__((sda));
extern int D_001AA104 __attribute__((sda));
extern int D_001AA7F0 __attribute__((sda));
extern int D_001B170C __attribute__((sda));
extern int D_001A8BB8 __attribute__((sda));
extern int D_001A8BB8_abs __asm__("D_001A8BB8") __attribute__((nosda));
extern int D_001A79F0 __attribute__((nosda));
extern int D_001A79F0_b __asm__("D_001A79F0") __attribute__((nosda));
extern int D_0018C2EC __attribute__((nosda));
extern int D_001C4F40 __attribute__((nosda));
extern int D_001A8BB0 __attribute__((nosda));
extern int D_001A8B88[];
extern void func_002858B0(int);

int func_002B49E0(int index, int mode, int a2, int a3, unsigned char *flag)
{
    int result;
    int entry;
    int v;
    int count;

    if (flag != 0)
        *flag = 0;
    result = -1;
    if (D_001A8BB8_abs == -2)
        result = 0;
    if (mode == 1 && !(D_001AA100 < 8))
        result = -2;
    entry = index >= 0 ? D_001A8B88[index] : 0;
    if (entry != 0)
        result = -3;
    if (D_0018C2EC == 0)
        result = -1;
    if (result != 0)
        return result;
    D_001AA0F8 = a2;
    D_001AA0FC = a3;
    D_001AA104 = (int)flag;
    D_001A8BB8 = index;
    if ((D_001A79F0 == 8 && D_001C4F40 == 1) || (D_001A79F0 == 0x13 && D_001C4F40 == 0)) {
        if ((unsigned)(index - 3) < 2) {
            D_001B170C = 2;
            if (index == 4)
                func_002858B0(2);
        }
        v = D_001A79F0_b;
    } else {
        v = D_001AA7F0;
    }
    if ((unsigned)(v - 22) < 2) {
        if ((unsigned)(index - 3) < 2) {
            D_001B170C = 3;
            if (index == 4)
                func_002858B0(3);
        }
    }
    if (mode == 1) {
        count = D_001AA100;
        D_001B1D50[count] = D_001A8BB0;
        D_001AA100 = count + 1;
    }
    return result;
}
