/* func_L00_002F59A8: M3 2026-10-26: D_L00_001B1BA6/BA7 as .sdata macro words give every form (the $gp read is a macro load in a slot); 140/140. Left: retail puts the divide-by-zero guard before the div (the trap-delay barrier class) and builds the 0x1B98 table address first.
 */
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern int func_00288E18(int, int);
extern s16 D_L00_001B1B88[];
extern s16 D_L00_001B1B98[];
extern u8 D_L00_001B1BA6 __attribute__((section(".sdata")));
extern u8 D_L00_001B1BA7 __attribute__((section(".sdata")));

void func_L00_002F59A8(void)
{
    if (D_L00_001B1BA6 == 0)
        return;
    if (func_00288E18(D_L00_001B1B88[D_L00_001B1BA7],
                    D_L00_001B1B98[D_L00_001B1BA7]) == 0)
        return;
    D_L00_001B1BA6 = D_L00_001B1BA6 - 1;
    D_L00_001B1BA7 = (D_L00_001B1BA7 + 1) % 7;
}
