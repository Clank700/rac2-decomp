/* G8 profile: 27/27 in both USA releases; PAL 0/27, instruction at +0x38 differs. Preserve the canonical-data draft; qualify the PAL timing-constant difference before integration. */
#include "include_asm.h"

/* func_L00_002A5480 is a unit of its own: it reads the tick counter through $gp, so it
   needs the -G8 profile (the -g8 name gives it), and the two names of the one address
   (D_L00_001B19C8 through $gp, ref_L00_002A5480_00 in absolute) are what the retail does: the
   comparison reads the small-data copy and the arithmetic the absolute one. The stamp
   is the tick plus the first call's result plus 0x14, plus the second call's result; the
   tick has to be read into a variable of its own first, or this cc1 makes the first
   call's result the accumulator and the two closing ADDU come out the other way round. */

typedef unsigned char u8;

typedef int s32;

extern u8 D_00189E20[];

extern s32 D_L00_001B19C8 __attribute__((sda));

extern s32 ref_L00_002A5480_00;

extern s32 func_002A77E0(s32);

/* One-shot delay timer: the first pass stamps the resident block, the second one asks
   the helper twice and stores the sum of the two answers. */
void func_L00_002A5480(void)
{
    u8 *b = D_00189E20;
    s32 t;
    s32 t2;
    s32 s;
    s32 k;

    if (*(s32 *)(b + 0x1180) != 0)
        return;
    if (*(s32 *)(b + 0x1188) == 0) {
        *(s32 *)(b + 0x1184) = ref_L00_002A5480_00 + 0x1e;
        return;
    }
    if (D_L00_001B19C8 > *(s32 *)(b + 0x1184)) {
        *(s32 *)(b + 0x1180) = 1;
        t = func_002A77E0(*(s32 *)(b + 0x1188));
        t2 = func_002A77E0(*(s32 *)(b + 0x1188));
        s = t + 0x14;
        k = ref_L00_002A5480_00;
        k = k + s;
        k = k + t2;
        *(s32 *)(b + 0x1184) = k;
    }
}
