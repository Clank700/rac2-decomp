#include "include_asm.h"
extern char *D_001A8CFC;
extern void func_0034E478(void *);

void func_PAL_0029CA70(void) {
    if (D_001A8CFC != 0)
        func_0034E478(D_001A8CFC + 0x36F28);
}
