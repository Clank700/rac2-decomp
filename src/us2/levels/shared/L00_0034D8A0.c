#include "include_asm.h"

extern int D_00138344;
typedef struct {
    char reserved00[0x14];
    char *source;
    int value;
    char reserved1c[0x118];
    int fallback;
} CallbackStateL001FEC40;
extern CallbackStateL001FEC40 D_L00_001FEC40;
extern void func_L00_0030DA68(int);

/* Guarded callback update: with the pending-input bit set, refreshes the value from its source and reports it (or the fallback's -1), otherwise reports a configured input or runs the setup call. */
int func_US2_L00_0034D8A0(void)
{
    int result = 0;
    int flags = D_00138344;
    if (flags & 0x10) {
        int value = *(int *)(D_L00_001FEC40.source + 0xE0);
        if (value != 0)
            D_L00_001FEC40.value = value;
        else if (D_L00_001FEC40.fallback == 0) {
            value = -1;
            goto return_value;
        }
        value = 0;
return_value:
        return value;
    }
    if (flags & 0x900)
        result = 1;
    else
        func_L00_0030DA68(flags);
    return result;
}

INCLUDE_ASM("asm/us2/levels", func_US2_L00_0034D928);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_0034D9F8);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_0034DA28);

INCLUDE_ASM("asm/us2/levels", func_US2_L00_0034DAB0);
