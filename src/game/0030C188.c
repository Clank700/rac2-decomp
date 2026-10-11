#include "include_asm.h"

extern char *Ffc961fca_FUN_002AD0B0(char *a1);

extern void Ffc961fca_FUN_00283410(char *dst, char *src);

extern void Ffc961fca_FUN_00282CC0(char *dst, char *src, char *tail);

extern void Ffc961fca_FUN_00282CF0(char *dst, char *src, char *tail);

extern void Ffc961fca_FUN_00283698(char *dst, char *src);

extern void Ffc961fca_FUN_00283098(char *dst, char *src, char *tail);

extern void Ffc961fca_FUN_00283738(char *dst, char *src, char *tail);

typedef struct {
    char pad0[0x20];
    unsigned char state;
} Level16VendorMoby;

INCLUDE_ASM("asm/game", func_0030C188);

INCLUDE_ASM("asm/game", func_0030C440);

INCLUDE_ASM("asm/game", func_0030CAA0);

INCLUDE_ASM("asm/game", func_0030CAD0);

INCLUDE_ASM("asm/game", func_0030CCD0);

INCLUDE_ASM("asm/game", func_0030D430);

INCLUDE_ASM("asm/game", func_0030D5B8);

INCLUDE_ASM("asm/game", func_0030DB88);

INCLUDE_ASM("asm/game", func_0030DE88);

INCLUDE_ASM("asm/game", func_0030E030);

INCLUDE_ASM("asm/game", func_0030E6F8);

INCLUDE_ASM("asm/game", func_0030E700);

INCLUDE_ASM("asm/game", func_0030E8A8);

INCLUDE_ASM("asm/game", func_0030ECC8);

INCLUDE_ASM("asm/game", func_0030F408);

INCLUDE_ASM("asm/game", func_0030F7B0);

INCLUDE_ASM("asm/game", func_00310960);

INCLUDE_ASM("asm/game", func_00310A40);

INCLUDE_ASM("asm/game", func_00310C88);

INCLUDE_ASM("asm/game", func_00310D70);

void func_00310D78(char *o0, char *o1)
{
    char b0[64];
    char b1[64];
    char b2[64];
    char *r = Ffc961fca_FUN_002AD0B0(o1);

    if (r == 0)
        return;
    Ffc961fca_FUN_00283410(b0, r);
    Ffc961fca_FUN_00282CC0(o0 + 16, o0 + 16, r + 16);
    Ffc961fca_FUN_00282CF0(o0 + 16, o0 + 16, o1 + 16);
    if ((*(int *)(r + 60) & 2) != 0) {
        Ffc961fca_FUN_00283410(b2, r + 32);
        Ffc961fca_FUN_00283698(b1, b2);
        Ffc961fca_FUN_00283098(o0 + 16, o0 + 16, b1);
        Ffc961fca_FUN_00283098(o0 + 16, o0 + 16, o1 + 192);
    } else {
        Ffc961fca_FUN_00283098(o0 + 16, o0 + 16, b0);
    }
    Ffc961fca_FUN_00282CC0(o0 + 16, o0 + 16, o1 + 16);
    Ffc961fca_FUN_00283738(o0 + 192, b0, o0 + 192);
}

INCLUDE_ASM("asm/game", func_00310E98);

INCLUDE_ASM("asm/game", func_003116E8);

INCLUDE_ASM("asm/game", func_00311F70);

INCLUDE_ASM("asm/game", func_003120C8);

INCLUDE_ASM("asm/game", func_003125F8);

INCLUDE_ASM("asm/game", func_00312600);

int func_00312B58(Level16VendorMoby *moby) {
    return moby->state == 6;
}

INCLUDE_ASM("asm/game", func_00312B68);

INCLUDE_ASM("asm/game", func_00312B70);

INCLUDE_ASM("asm/game", func_00312D48);

INCLUDE_ASM("asm/game", func_00312D58);

INCLUDE_ASM("asm/game", func_00312E00);

int func_00312E10(unsigned char *p) { return p[0x20] == 1; }

INCLUDE_ASM("asm/game", func_00312E20);

INCLUDE_ASM("asm/game", func_00312EA8);

INCLUDE_ASM("asm/game", func_00312EB0);

INCLUDE_ASM("asm/game", func_003130F0);

INCLUDE_ASM("asm/game", func_00313210);

INCLUDE_ASM("asm/game", func_00313548);

INCLUDE_ASM("asm/game", func_00313600);

INCLUDE_ASM("asm/game", func_00313678);
