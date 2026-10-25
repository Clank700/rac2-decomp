/* Retained complete manual C reconstruction; nonmatching, not linked.
 * Checked source: src/levels/06_notak/L06_0037E6B0-helpers.c
 * Profile: -O2 -G0 -ffunction-sections
 * Retail US extent: 280 bytes.
 * Actual final coverage: us: 0/1, exit1, 280 compiled bytes; us2: 0/1, exit1, 280 compiled bytes; pal: catalogue absent, exit1.
 * Residual: 280/280 bytes. Moving the state-pointer lifetime after the first real copy restores the retail save set and entry. Float-constant/byte-header scheduling after +0x6C and later call/store scheduling still differ. The second ordinary TI copy retains its real folded-address form.
 * Reopen only with: A specific measured scheduling policy or real field-lifetime witness for the float constant, byte header writes and conversion call; no fabricated dependency or barrier.
 * Earlier complete variants are retained privately. No native execution or
 * complete linked-program equality is claimed by these placement measurements.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern char *func_002B9030(int a0);
extern int func_00283CF0(float f12);
extern void *D_L06_001FF50C;
extern int func_002A77E0(int a0);
extern float func_00283CE0(int a0);

void func_L06_0037E6B0(char *a0, char *a1, int a2, float f12, float f13)
{
    char *m = func_002B9030(0x53);

    if (m != 0) {
        qcopy(m + 0x10, a0);
        {
        char *st = m + 0x20;
        *(int *)(m + 4) = 0x50502010;
        *(unsigned char *)(m + 9) = func_00283CF0(2.0f) + 0x40;
        *(unsigned char *)(m + 3) = 0x48;
        *(unsigned char *)(m + 1) = 0;
        *(float *)(m + 0xC) = f12 * 105000.0f;
        *(unsigned char *)(m + 2) = *(unsigned char *)D_L06_001FF50C;
        *(unsigned char *)(m + 8) = func_002A77E0(0xFF);
        *(short *)(m + 0xA) = a2;
        *(TI128 *)st = *(TI128 *)a1;
        {
        float converted = func_00283CE0((short)a2);
        *(float *)(st + 0x14) = f12;
        *(float *)(st + 0x1C) = f13;
        *(short *)(st + 0x18) = 0;
        *(float *)(st + 0xC) = converted;
        *(float *)(st + 0x10) = 0.5f;
        *(short *)(st + 0x1A) = func_002A77E0(6) - 3;
        }
        }
    }
}
