#include "include_asm.h"

extern char D_00189E20_17[];

typedef unsigned char u8;

extern u8 D_00189E20_1[];

typedef struct { u8 prefix[0x34]; unsigned short flags; } FlagPairObjectView;

typedef struct {
    u8 prefix[0x1860];
    FlagPairObjectView *secondary;
    u8 between[0xa2c];
    FlagPairObjectView *primary;
} FlagPairResidentView;

typedef int s32;

typedef struct {
    u8 field00[0x218]; signed short field218; u8 field21A[0x12e];
    signed short field348; u8 field34A[4]; signed short field34E;
    u8 field350[0x1147]; u8 field1497; u8 field1498[2]; u8 field149A;
    u8 field149B[0xdf9]; s32 field2294;
} NativeModeResident;

extern NativeModeResident D_00189E20_8;

extern s32 D_L00_001A8FF0 __attribute__((sda));

extern volatile u8 D_001A7B08[4] __attribute__((sda));

extern s32 D_L00_001A8FF4_1 __attribute__((sda));

typedef float f32;

#ifndef RAC2_T_S16_FC94396F4
#define RAC2_T_S16_FC94396F4
typedef signed short s16_Fc94396f4;
#endif

#ifndef RAC2_T_FAMILYC94396F4VECTOR_FC94396F4
#define RAC2_T_FAMILYC94396F4VECTOR_FC94396F4
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FamilyC94396F4Vector_Fc94396f4;
#endif

#ifndef RAC2_T_FAMILYC94396F4STATE_FC94396F4
#define RAC2_T_FAMILYC94396F4STATE_FC94396F4
typedef struct {
    u8 reserved0[846];
    s16_Fc94396f4 gate;
    u8 reserved1[8004];
    s32 state;
    u8 reserved2[43];
    u8 mode;
} FamilyC94396F4State_Fc94396f4;
#endif

extern FamilyC94396F4State_Fc94396f4 D_00189E20_15;

extern u8 D_0018A0E0[];

extern void func_00282F20_6(u8 *buffer, u8 *table, f32 parameter);

extern void func_L00_002D3BD8(u8 *buffer, FamilyC94396F4Vector_Fc94396f4 *source, f32 zero);

extern void func_L00_002D3B58(FamilyC94396F4Vector_Fc94396f4 *destination,
                    FamilyC94396F4Vector_Fc94396f4 *source, f32 zero);

extern void func_00282CC0_16(FamilyC94396F4Vector_Fc94396f4 *destination,
                    FamilyC94396F4Vector_Fc94396f4 *source, u8 *buffer);

/* Measured partial layouts; original type and game roles are unknown. */
typedef float Rac2Native_5fc519c90e0e763a_f32;

extern void func_L00_002D34C0_1(Rac2Native_5fc519c90e0e763a_f32);

extern void func_00282F20_5(char *local, char *a, float k);

extern float func_00282DB0_2(char *a, char *src);

extern void func_00282D30_11(char *dst, char *src, float k);

extern void func_00282CF0_8(char *dst, char *src, char *local);

extern char D_00189E20_14[];

            /* 0x00189E20 */

#ifndef RAC2_T_V4_FC186F630
#define RAC2_T_V4_FC186F630
typedef int V4_Fc186f630 __attribute__((mode(TI)));
#endif

extern unsigned char D_00189E20_4[];

extern float func_00282E20_1(char *object);

extern void func_00283410_2(char *dst, char *src);

extern void func_00283698_1(char *dst, char *src);

extern void func_002830C0_1(char *dst, char *src, char *extra);

#ifndef RAC2_T_PERSISTENT_F882F1178
#define RAC2_T_PERSISTENT_F882F1178
typedef struct {
    unsigned char pad0[4960];
    void *p1360;
    void *p1364;
    void *p1368;
    unsigned char pad1[4512];
    float f250C;
    float f2510;
    float f2514;
} Persistent_F882f1178;
#endif

#ifndef RAC2_T_NODE_F882F1178
#define RAC2_T_NODE_F882F1178
typedef struct {
    unsigned char pad[120];
    int field120;
} Node_F882f1178;
#endif

extern Persistent_F882f1178 D_00189E20_11;

extern int D_L00_001A8F00 __attribute__((sda));

extern float func_00283B98_4(float, float);

extern float func_00283198_3(float);

extern int func_00283D38_1(int, int, float);

extern void func_L00_00326048(int, float *, int, int, float);

INCLUDE_ASM("asm/levels", func_L00_002D2A10);

INCLUDE_ASM("asm/levels", func_L00_002D2E68);

/* shared native body of family ea34650e369e */
void func_L00_002D3068(void)
{
    char *b = D_00189E20_17;
    char *p;
    int i;

    p = *(char **)(b + 3096);
    *(unsigned short *)(p + 52) &= 0xFFFE;

    for (i = 0; i < 7; i++) {
        p = *(char **)(b + 4640 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
        p = *(char **)(b + 4644 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
        p = *(char **)(b + 4648 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
    }

    if (1) {
        char *c = D_00189E20_17;
        p = *(char **)(c + 4892);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
    }

    if (1) {
        char *c = D_00189E20_17;
        if (*(unsigned char *)(c + 8884) == 1) {
            c = D_00189E20_17;
            p = *(char **)(c + 6244);
            if (p != 0)
                *(unsigned short *)(p + 52) &= 0xFFFE;
        }
    }

    if (1) {
        char *c = D_00189E20_17;
        if (*(short *)(c + 9468) != 0 || *(int *)(c + 8860) == 31) {
            c = D_00189E20_17;
            p = *(char **)(c + 4880);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
            c = D_00189E20_17;
            p = *(char **)(c + 4884);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
            c = D_00189E20_17;
            p = *(char **)(c + 4892);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
        }
    }

    if (1) {
        char *c = D_00189E20_17;
        if ((*(unsigned char *)(c + 8894) != 0 && *(int *)(c + 4680) == 10) ||
            *(unsigned char *)(c + 8895) != 0) {
            char *d = D_00189E20_17;
            p = *(char **)(d + 4640);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
        }
    }
}

/* Set bit0 of the primary object's halfword flags and of the optional secondary object's flags */
void func_L00_002D31D0(void) {
    FlagPairResidentView *root = (FlagPairResidentView *)D_00189E20_1;
    FlagPairObjectView *primary = root->primary;
    FlagPairObjectView *secondary;
    primary->flags |= 1;
    secondary = root->secondary;
    if (secondary) secondary->flags |= 1;
}

/* Clear bit0 of the primary object's halfword flags and of the optional secondary object's flags */
void func_L00_002D3208(void) {
    FlagPairResidentView *root = (FlagPairResidentView *)D_00189E20_1;
    FlagPairObjectView *primary = root->primary;
    FlagPairObjectView *secondary;
    primary->flags &= ~1;
    secondary = root->secondary;
    if (secondary) secondary->flags &= ~1;
}

INCLUDE_ASM("asm/levels", func_L00_002D3240);

INCLUDE_ASM("asm/levels", func_L00_002D3248);

INCLUDE_ASM("asm/levels", func_L00_002D3290);

/* resident mode predicate: returns 0, 1 or 2 from the resident state words */
s32 func_L00_002D3400(void) {
    s32 result = D_00189E20_8.field348;
    if (D_L00_001A8FF0 != 0 && D_L00_001A8FF4_1 == 0) result = 2;
    if (D_L00_001A8FF4_1 != 0 || D_00189E20_8.field2294 == 59 ||
        (D_00189E20_8.field2294 == 110 && D_00189E20_8.field149A == 0) ||
        D_00189E20_8.field2294 == 109 || D_00189E20_8.field218 != 0 ||
        (D_00189E20_8.field1497 != 0 && D_001A7B08[3] != 0 &&
         D_00189E20_8.field2294 == 0 && D_00189E20_8.field34E < 4)) result = 1;
    if (result == 1 && D_00189E20_8.field149A != 0) result = 0;
    return result;
}

/* Dispatches a shared mode to update the destination Z component or compose two temporary transforms through the measured helper sequence. */
void func_L00_002D34C0(FamilyC94396F4Vector_Fc94396f4 *destination,
                                      FamilyC94396F4Vector_Fc94396f4 *source,
                                      f32 parameter)
{
    u8 first[16];
    u8 second[16];

    switch (D_00189E20_15.mode) {
    case 0:
        destination->z = source->z - parameter;
        return;
    case 1:
        func_00282F20_6(first, (u8 *)&D_00189E20_15 + 672, -parameter);
        func_L00_002D3BD8(second, source, 0.0f);
        func_L00_002D3B58(destination, destination, 0.0f);
        func_00282CC0_16(destination, destination, second);
        func_00282CC0_16(destination, destination, first);
        return;
    case 2:
        if (D_00189E20_15.state == 58 && D_00189E20_15.gate == 0) {
            func_00282F20_6(first, (u8 *)&D_00189E20_15 + 672, -parameter);
        } else {
            func_00282F20_6(first, D_0018A0E0, parameter);
        }
        func_L00_002D3BD8(second, source, 0.0f);
        func_L00_002D3B58(destination, destination, 0.0f);
        func_00282CC0_16(destination, destination, second);
        func_00282CC0_16(destination, destination, first);
        return;
    default:
        return;
    }
}

INCLUDE_ASM("asm/levels", func_L00_002D3638);

INCLUDE_ASM("asm/levels", func_L00_002D36E0);

/* calls the measured float callee with the negated input */
void func_L00_002D3778(Rac2Native_5fc519c90e0e763a_f32 value) {
 func_L00_002D34C0_1(-value);
}

INCLUDE_ASM("asm/levels", func_L00_002D3798);

INCLUDE_ASM("asm/levels", func_L00_002D38A0);

/* switches on a state byte in a shared table: copies 16 bytes and clears the third word, or computes a dot product that scales a vector and subtracts it into the destination */
void func_L00_002D3960(char *dst, char *src)
{
    char local[16];
    char *base;
    float f;

    base = D_00189E20_14;
    switch (*(unsigned char *)(base + 8899)) {
    case 0:
        *(V4_Fc186f630 *)dst = *(V4_Fc186f630 *)src;
        *(int *)(dst + 8) = 0;
        break;
    case 1:
        func_00282F20_5(local, base + 672, 1.0f);
        f = func_00282DB0_2(local, src);
        func_00282D30_11(local, local, f);
        func_00282CF0_8(dst, src, local);
        break;
    case 2:
        f = func_00282DB0_2(base + 704, src);
        func_00282D30_11(local, base + 704, f);
        func_00282CF0_8(dst, src, local);
        break;
    }
}

/* Reads one byte and one pointer from a shared global; returns a callee float when the byte is zero, returns 0.0f when the byte is outside 0..2, otherwise fills three stack locals through three callees and returns the last callee float. */
float func_L00_002D3A58(char *arg)
{
    char first[64];
    char second[64];
    char third[16];
    unsigned char *p = D_00189E20_4;
    int flag = p[8899];

    if (flag == 0)
        return func_00282E20_1(arg);
    if (flag < 0)
        return 0.0f;
    if (flag >= 3)
        return 0.0f;
    func_00283410_2(first, (char *)(*(int *)(p + 8848) + 240));
    func_00283698_1(second, first);
    func_002830C0_1(third, arg, second);
    return func_00282E20_1(third);
}

INCLUDE_ASM("asm/levels", func_L00_002D3B00);

INCLUDE_ASM("asm/levels", func_L00_002D3B58);

INCLUDE_ASM("asm/levels", func_L00_002D3BD8);

INCLUDE_ASM("asm/levels", func_L00_002D3C68);

INCLUDE_ASM("asm/levels", func_L00_002D3CF8);

INCLUDE_ASM("asm/levels", func_L00_002D3D98);

INCLUDE_ASM("asm/levels", func_L00_002D3EA8);

INCLUDE_ASM("asm/levels", func_L00_002D3F30);

/* Return the complete supplied unsigned-long 64-bit value unchanged. */
/* Target: FUN_003427B0 — identity function returning its first argument */
/* Disassembly: jr ra; move v0,a0 (MIPS delay slot) */
/* Compiled with: -O2 -G0 -ffunction-sections */

unsigned long func_L00_002D3FB0(unsigned long param_1)
{
  return param_1;
}

INCLUDE_ASM("asm/levels", func_L00_002D3FB8);

INCLUDE_ASM("asm/levels", func_L00_002D4040);

INCLUDE_ASM("asm/levels", func_L00_002D40A0);

INCLUDE_ASM("asm/levels", func_L00_002D40F0);

INCLUDE_ASM("asm/levels", func_L00_002D4138);

INCLUDE_ASM("asm/levels", func_L00_002D4140);

INCLUDE_ASM("asm/levels", func_L00_002D49F0);

/* Advances three mode-selected resident scalars through a rate helper and writes a 0..1 fold of the first two into offset 120 of the objects those scalars point at. */
void func_L00_002D4A38(void)
{
    Node_F882f1178 *node;

    node = (Node_F882f1178 *)D_00189E20_11.p1360;
    if (node != 0) {
        if (*(int *)0x1A8F00 == 2)
            D_00189E20_11.f250C = func_00283B98_4(D_00189E20_11.f250C, 0.020362177863717079f);
        else
            D_00189E20_11.f250C = func_00283B98_4(D_00189E20_11.f250C, 0.034906592220067978f);
        node->field120 = func_00283D38_1(0xd2d2d2, 0x285050,
                                 func_00283198_3(D_00189E20_11.f250C) * 0.5f + 0.5f);
    }
    node = (Node_F882f1178 *)D_00189E20_11.p1364;
    if (node != 0) {
        if (D_L00_001A8F00 != 2) {
            float limit;
            int which;

            limit = func_00283B98_4(D_00189E20_11.f2510, 0.049451004713773727f);
            D_00189E20_11.f2510 = limit;
            which = 0x1ee628;
            if (limit > 0.0f && limit < 1.9198623895645142f) {
                which = 0x1e1ed2;
            }
            node->field120 = func_00283D38_1(node->field120, which, 0.070000000298023224f);
        } else {
            D_00189E20_11.f2510 = func_00283B98_4(D_00189E20_11.f2510, 0.026179943233728409f);
            node->field120 = func_00283D38_1(0x1e1ed2, 0x1e1e50,
                                     func_00283198_3(D_00189E20_11.f2510) * 0.5f + 0.5f);
        }
    }
    if (D_00189E20_11.p1368 != 0) {
        if (D_L00_001A8F00 == 2)
            func_L00_00326048((int)D_00189E20_11.p1368, &D_00189E20_11.f2514, 0xdcdcdc, 0x323232,
                    0.026179943233728409f);
        else
            func_L00_00326048((int)D_00189E20_11.p1368, &D_00189E20_11.f2514, 0xdcdcdc, 0x323232,
                    0.040724355727434158f);
    }
}

INCLUDE_ASM("asm/levels", func_L00_002D4C28);

INCLUDE_ASM("asm/levels", func_L00_002D4D98);

INCLUDE_ASM("asm/levels", func_L00_002D4E58);

INCLUDE_ASM("asm/levels", func_L00_002D5000);

INCLUDE_ASM("asm/levels", func_L00_002D5098);

INCLUDE_ASM("asm/levels", func_L00_002D5158);

INCLUDE_ASM("asm/levels", func_L00_002D5940);

INCLUDE_ASM("asm/levels", func_L00_002D5E30);

INCLUDE_ASM("asm/levels", func_L00_002D5EB8);

INCLUDE_ASM("asm/levels", func_L00_002D6418);
