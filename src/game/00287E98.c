#include "common.h"
#include "structs.h"

   /* current buffer */
extern short r1_D_0015EDC4;
extern void func_00287E98(void);
extern int D_001A8A64 __attribute__((sda));

void func_00287E98(void) {
    D_001A8A64 = 1;
}


void func_00287EA8(void) {
    D_001A8A64 = 0;
}

INCLUDE_ASM("asm/game", func_00287EB0);

/* 0xE0-byte slots of the table at D_00239BA0; f4A and f4C link the slots. */
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

int func_00287F60(int index)
{
    int count = 0;
    int i = index;
    while (D_00239BA0[i].f4C != 0) i = D_00239BA0[i].f4C;
    if (D_00239BA0[i].f4A != 0) {
        do {
            i = D_00239BA0[i].f4A;
            count++;
        } while (D_00239BA0[i].f4A != 0);
    }
    return count;
}

int func_00287FF8(int slot, int n)
{
    int result = 0;
    int i = slot;
    int k;
    if (func_00287F60(i) >= n) {
        while (D_00239BA0[i].f4C != 0) i = D_00239BA0[i].f4C;
        if (n > 0) {
            for (k = n; k != 0; k--) i = D_00239BA0[i].f4A;
        }
        D_00139568[slot] = (unsigned char)i;
        result = 1;
    }
    return result;
}
