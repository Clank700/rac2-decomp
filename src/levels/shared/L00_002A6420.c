#include "include_asm.h"

typedef unsigned char u8;

extern void func_L00_002A61C8(int arg0, int arg1, int arg2, int arg3);

extern int func_L00_002B3998_1(float value);

#ifndef RAC2_T_RESIDENTSTATE_FD160FB9C
#define RAC2_T_RESIDENTSTATE_FD160FB9C
typedef struct {
    u8 pad000[0x1b8];
    int f1B8;
    u8 pad1bc[0xc2c - 0x1bc];
    int fC2C;
    u8 padc30[0x149d - 0xc30];
    u8 b149D;
    u8 pad149e[0x2290 - 0x149e];
    u8 *p2290;
    int f2294;
} ResidentState_Fd160fb9c;
#endif

extern ResidentState_Fd160fb9c D_00189E20_16;

extern char D_00189E20_2[];

extern void func_L00_002D3638(char *target, int mode, float value, float zero, float scale);

extern int func_002761F8_2(char *first, char *second, int mode, int flag, int extra);

extern float func_00282E48_4(char *source, short *table);

extern short D_L00_001BF220_2[];

extern float D_0018A084;

typedef int s32;

typedef float f32;

extern void func_L00_002D36E0(f32, f32, f32, f32 *, s32);

typedef unsigned int u32;

extern u8 D_00189E20_1[];

typedef struct {
    u8 prefix[0x1220];
    u32 field1220;
    u8 gap[0x20];
    s32 field1244, field1248;
} NativeIndexedFieldsView;

typedef struct {
    u8 pad0000[0x2294];
    u32 kind;
    u32 unknown2298;
    u32 mode;
} ResidentFlags2294;

/* Reads a resident mode word and the kind byte of a pointer field, then for kind 3, 4 or 20 tests two float thresholds through a predicate and triggers a four-argument action with selector zero or one. */
void func_L00_002A6420(void)
{
    int selector;

    if (D_00189E20_16.f2294 == 2) {
        if (D_00189E20_16.f1B8 < 15)
            return;
    }

    selector = D_00189E20_16.b149D;

    if (D_00189E20_16.f2294 == 2) {
        if (D_00189E20_16.f1B8 == 22)
            func_L00_002A61C8(selector, 0, 1, 30);
    }

    switch (D_00189E20_16.p2290[67]) {
    case 3:
        if (D_00189E20_16.fC2C != 0)
            return;
        if (func_L00_002B3998_1(49.5f) != 0)
            func_L00_002A61C8(selector, 0, 1, 30);
        if (func_L00_002B3998_1(17.0f) != 0)
            func_L00_002A61C8(selector, 1, 1, 30);
        return;
    case 4:
        if (D_00189E20_16.fC2C != 0)
            return;
        if (func_L00_002B3998_1(12.5f) != 0)
            func_L00_002A61C8(selector, 0, 1, 30);
        if (func_L00_002B3998_1(1.0f) != 0)
            func_L00_002A61C8(selector, 1, 1, 30);
        return;
    case 20:
        if (D_00189E20_16.fC2C != 0)
            return;
        if (func_L00_002B3998_1(8.0f) != 0)
            func_L00_002A61C8(selector, 0, 1, 30);
        if (func_L00_002B3998_1(21.0f) != 0)
            func_L00_002A61C8(selector, 1, 1, 30);
        return;
    }
}

INCLUDE_ASM("asm/levels", func_L00_002A65D8);

INCLUDE_ASM("asm/levels", func_L00_002A6708);

INCLUDE_ASM("asm/levels", func_L00_002A67F8);

INCLUDE_ASM("asm/levels", func_L00_002A6DD0);

INCLUDE_ASM("asm/levels", func_L00_002A7000);

/* shared native body of family 0be97c76a107 */
void func_L00_002A7070(void)
{
    char *base = D_00189E20_2;
    int i, j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            char *p = *(char **)(base + 4640 + i * 80);

            if (j == 1)
                p = *(char **)(base + 4644 + i * 80);
            else if (j == 2)
                p = *(char **)(base + 4648 + i * 80);
            if (p != 0)
                *(long long *)(p + 56) = *(long long *)(*(char **)(base + 8848) + 56);
        }
    }
}

void func_L00_002A70F0(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_002A70F8);

INCLUDE_ASM("asm/levels", func_L00_002A74A8);

INCLUDE_ASM("asm/levels", func_L00_002A75D8);

INCLUDE_ASM("asm/levels", func_L00_002A76B8);

INCLUDE_ASM("asm/levels", func_L00_002A7748);

INCLUDE_ASM("asm/levels", func_L00_002A7958);

INCLUDE_ASM("asm/levels", func_L00_002A7A10);

INCLUDE_ASM("asm/levels", func_L00_002A7A50);

INCLUDE_ASM("asm/levels", func_L00_002A7DE8);

INCLUDE_ASM("asm/levels", func_L00_002A7E60);

INCLUDE_ASM("asm/levels", func_L00_002A9460);

INCLUDE_ASM("asm/levels", func_L00_002A9600);

INCLUDE_ASM("asm/levels", func_L00_002A9760);

INCLUDE_ASM("asm/levels", func_L00_002A9D38);

INCLUDE_ASM("asm/levels", func_L00_002A9E30);

INCLUDE_ASM("asm/levels", func_L00_002A9F30);

INCLUDE_ASM("asm/levels", func_L00_002A9FE8);

INCLUDE_ASM("asm/levels", func_L00_002AA0F0);

INCLUDE_ASM("asm/levels", func_L00_002AA178);

INCLUDE_ASM("asm/levels", func_L00_002AA200);

INCLUDE_ASM("asm/levels", func_L00_002AA478);

INCLUDE_ASM("asm/levels", func_L00_002AA570);

INCLUDE_ASM("asm/levels", func_L00_002AA750);

INCLUDE_ASM("asm/levels", func_L00_002AA938);

INCLUDE_ASM("asm/levels", func_L00_002AABE0);

INCLUDE_ASM("asm/levels", func_L00_002AAE00);

INCLUDE_ASM("asm/levels", func_L00_002AB0A8);

INCLUDE_ASM("asm/levels", func_L00_002AB0C0);

INCLUDE_ASM("asm/levels", func_L00_002AB0D8);

INCLUDE_ASM("asm/levels", func_L00_002AB0F0);

/* scales and blends two 16-byte samples through a helper, and on a successful comparison writes a table-derived value to the caller's output */
int func_L00_002AB108(float *out, float scale, float amount)
{
    char buffer[32];

    func_L00_002D3638(buffer, 1, D_0018A084 - 0.02f, 0.0f, scale);
    func_L00_002D3638(buffer + 16, 1, amount, 0.0f, scale);
    if (func_002761F8_2(buffer, buffer + 16, 2, 0, 0)) {
        if (out)
            *out = func_00282E48_4(buffer, D_L00_001BF220_2);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_002AB1D8);

INCLUDE_ASM("asm/levels", func_L00_002AB3E0);

INCLUDE_ASM("asm/levels", func_L00_002AB420);

INCLUDE_ASM("asm/levels", func_L00_002AB948);

INCLUDE_ASM("asm/levels", func_L00_002ABBA0);

INCLUDE_ASM("asm/levels", func_L00_002AC1A0);

INCLUDE_ASM("asm/levels", func_L00_002AC578);

INCLUDE_ASM("asm/levels", func_L00_002ACA08);

INCLUDE_ASM("asm/levels", func_L00_002ACF88);

INCLUDE_ASM("asm/levels", func_L00_002AD868);

INCLUDE_ASM("asm/levels", func_L00_002ADB40);

/* forwards an output pointer, three pinned floating constants and selector one to the typed helper */
void func_L00_002ADCF8(f32 *output) {
 func_L00_002D36E0(0.3f,0.0f,1.34f,output,1);
}

INCLUDE_ASM("asm/levels", func_L00_002ADD30);

/* returns indexed resident word 0x1220 when field 0x1244 equals two, otherwise zero */
u32 func_L00_002ADE68(s32 index) {
 NativeIndexedFieldsView *p=(NativeIndexedFieldsView *)((u8 *)&D_00189E20_1+index*0x50);
 if(p->field1244==2) return p->field1220;
 return 0;
}

/* returns indexed resident word 0x1248 when field 0x1244 equals two, otherwise minus one */
s32 func_L00_002ADEA0(s32 index) {
 NativeIndexedFieldsView *p=(NativeIndexedFieldsView *)((u8 *)&D_00189E20_1+index*0x50);
 if(p->field1244==2) return p->field1248;
 return -1;
}

/* tests whether the indexed resident status equals 12 or 17 */
s32 func_L00_002ADED8(s32 index) {
 s32 value=func_L00_002ADEA0(index);
 if(value==12 || value==17) return 1;
 return 0;
}

/* tests whether the indexed resident status equals 47 */
s32 func_L00_002ADF10(s32 index) {
 return func_L00_002ADEA0(index)==47;
}

INCLUDE_ASM("asm/levels", func_L00_002ADF38);

/* tests the measured unsigned resident kind and mode alternatives */
s32 func_L00_002ADF80(void)
{
    ResidentFlags2294 *root = (ResidentFlags2294 *)D_00189E20_1;

    if (root->mode == 17 || root->mode == 18
        || root->kind == 0x67 || root->kind == 0x7f
        || root->kind == 0x73 || root->kind == 0x72) {
        return 1;
    }
    return 0;
}

/* returns the provided value, or object byte 0xa9 when the value is 255 */
u32 func_L00_002ADFD0(u8 *object,u32 value) {
    if(value==255) value=object[0xa9];
    return value;
}

INCLUDE_ASM("asm/levels", func_L00_002ADFE8);

INCLUDE_ASM("asm/levels", func_L00_002AE070);

INCLUDE_ASM("asm/levels", func_L00_002AE0C8);
