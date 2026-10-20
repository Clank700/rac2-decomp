/* func_00287EB0 (176 bytes): candidate compiles to 176 bytes with the game compiler
   (-O2 -G8 -ffunction-sections, the profile of a -g8.c unit; src/game/00287E98.c is
   marked sdk, which gives 168 bytes). Same instructions as retail except registers:
   this cc1 keeps the index in $a3 and the loaded slot field in $a2 where retail has
   index in $a2 and the field in $a3, and it places the mult of the second lookup before
   the store to D_00139568[index] where retail stores first. Every variant tried
   (short/int field, early return, store order, pointer to the index byte, unsigned
   index) gave the same swap. */
typedef struct {
    int f00;
    char pad04[0x46];
    short f4A;
    short f4C;
    char pad4E[0x1E];
    int f6C;
    char pad70[0x1E];
    unsigned short f8E;
    char pad90[0x50];
} Slot287E98;
extern Slot287E98 D_00239BA0[];
extern unsigned char D_00139568[];
extern int D_00139868[];
extern int D_00139688[];

void func_00287EB0(int index)
{
    Slot287E98 *s = &D_00239BA0[D_00139568[index]];
    short v = s->f4A;
    if (v == 0) return;
    {
        int x = s->f6C;
        if (x >= 0) {
            x <<= 5;
            if (D_00139868[index] < x) D_00139868[index] = x;
        }
    }
    D_00139568[index] = (unsigned char)v;
    if (D_00239BA0[(unsigned char)v].f00 != 0) D_00139688[index] = D_00239BA0[(unsigned char)v].f8E;
}
