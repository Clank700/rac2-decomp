#include "include_asm.h"

/* Frozen Batch A A14-struct-2field-20; acknowledged claim 3e0e0bb01b3da304ddd50c7212de48bebcbf96d3b2d117369779044d96f69b21. */
typedef unsigned int BatchA_A14_u32;

typedef struct { unsigned char pad[0x2494]; BatchA_A14_u32 a; BatchA_A14_u32 b; } BatchA_A14_S;

extern BatchA_A14_S D_00189E20;

typedef struct { short key; short val; } Entry;

extern Entry *D_0018C2B8;

/* Measured partial layouts; original type and game roles are unknown. */
typedef int Rac2Native_28c929cadd7aca24_s32;

typedef unsigned char Rac2Native_28c929cadd7aca24_u8;

typedef struct {
    Rac2Native_28c929cadd7aca24_u8 prefix[0xc40];
    Rac2Native_28c929cadd7aca24_s32 selected;
    Rac2Native_28c929cadd7aca24_s32 index;
    Rac2Native_28c929cadd7aca24_u8 gap[0x1648];
    Rac2Native_28c929cadd7aca24_u8 *object;
} Rac2Native_28c929cadd7aca24_NativeResidentView;

extern Rac2Native_28c929cadd7aca24_NativeResidentView D_00189E20_19;

INCLUDE_ASM("asm/levels", func_L00_002CAD90);

INCLUDE_ASM("asm/levels", func_L00_002CAF20);

INCLUDE_ASM("asm/levels", func_L00_002CB038);

INCLUDE_ASM("asm/levels", func_L00_002CB218);

INCLUDE_ASM("asm/levels", func_L00_002CB2D8);

INCLUDE_ASM("asm/levels", func_L00_002CB3A8);

INCLUDE_ASM("asm/levels", func_L00_002D1AE8);

INCLUDE_ASM("asm/levels", func_L00_002D1B70);

INCLUDE_ASM("asm/levels", func_L00_002D1C40);

INCLUDE_ASM("asm/levels", func_L00_002D1DA0);

INCLUDE_ASM("asm/levels", func_L00_002D1ED8);

/* A14-struct-2field-20 freshly exact-verified under family reservation */
void func_L00_002D1F60(void) {
    D_00189E20.a = 0;
    D_00189E20.b = 0;
}

/* shared native body of family c68ad20a */
int func_L00_002D1F78(int key, int *out)
{
    Entry *e = D_0018C2B8;
    Entry *p;

    if (e == 0)
        return 0;
    if (e->key == -1)
        goto notfound;
    p = e;
    for (;;) {
        if (key == p->key) {
            *out = p->val;
            return 1;
        }
        p++;
        if (p->key == -1)
            goto notfound;
    }
notfound:
    *out = 0;
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_002D1FD8);

INCLUDE_ASM("asm/levels", func_L00_002D2070);

INCLUDE_ASM("asm/levels", func_L00_002D20D0);

INCLUDE_ASM("asm/levels", func_L00_002D2168);

INCLUDE_ASM("asm/levels", func_L00_002D23C0);

/* updates the resident selection and index after validating the selected table entry */
void func_L00_002D2470(Rac2Native_28c929cadd7aca24_s32 selected, Rac2Native_28c929cadd7aca24_s32 index) {
    if (selected >= 0) {
        Rac2Native_28c929cadd7aca24_u8 *object = D_00189E20_19.object;
        Rac2Native_28c929cadd7aca24_s32 offset = object[0x43] * 4;
        Rac2Native_28c929cadd7aca24_u8 *table = *(Rac2Native_28c929cadd7aca24_u8 **)(object + 0x24);
        Rac2Native_28c929cadd7aca24_u8 *entry = *(Rac2Native_28c929cadd7aca24_u8 **)(table + offset + 0x48);
        if (index < entry[0x10]) {
            D_00189E20_19.selected = selected;
            D_00189E20_19.index = index;
        }
    }
}

INCLUDE_ASM("asm/levels", func_L00_002D24B8);

INCLUDE_ASM("asm/levels", func_L00_002D24D0);

INCLUDE_ASM("asm/levels", func_L00_002D24E8);
