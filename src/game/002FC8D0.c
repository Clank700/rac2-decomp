#include "include_asm.h"

typedef int s32;

typedef unsigned char u8;

/* lot10: privately byte-gated bodies. */
extern s32 func_00126470(u8 *, s32, s32, s32, s32, s32, s32, s32);

extern s32 func_0011AEA0(s32);

extern s32 func_00126730(u8 *, u8 *);

extern s32 func_001244B8(s32, s32);

/* Family d50cdefed4015bae — 364 bytes, a 16384-byte block loop that builds two
   four-word GS packets per iteration and calls the measured SDK helper at
   0x00126288 in between.

   The resident write pointer at 0x001B3D08 is read ten times and stored three
   times.  Two authored views of that one measured cell are needed and are the
   qualified form here:
     * the read view is volatile, so every use is a fresh load -- the retail
       body re-loads the cell before every field store (aliasing through the
       loaded pointer is not enough to force it: without the qualifier cc1
       forwards a stored value into the next two reads);
     * the write view is an ordinary pointer, so the store written before the
       call is moved into the `jal` delay slot, which is where retail keeps it
       (a volatile store is left in place).
   The bare symbols keep the address materialisation a per-site assembler job
   (`lui`+`lw` mid-stream, the single `$gp` form in a delay slot).

   -G0 promotion (agent f02, 2026-10-07): under -G8 these two declarations need
   no attribute, because -G8 alone puts the cell in small data.  Under -G0 cc1
   would otherwise model each access as an explicit `lui`+`lw` pair, hoist the
   base into a callee-saved register and reuse it, which changes both the
   register allocation and the body size.  The measured `sda` attribute puts
   cc1 back on the one-instruction model, so gas expands every site exactly as
   the retail build did: absolute `lui`+`lw` in ordinary flow, the single `$gp`
   form inside the `.set nomacro` region cc1 emits for the `jal` delay slot.
   Nothing else about the body changed. */

extern int *volatile D_L02_001B3D08_3 __attribute__((sda));

extern int *D_L02_001B3D08_5 __attribute__((sda));

extern void D_00126288(int *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

typedef unsigned int u32;

extern int D_L03_001B31A0 __attribute__((sda));

extern int D_L03_001B31A4 __attribute__((sda));

extern void func_0011A950(int, int);

extern void func_0011B658(int);

/* Measured partial layouts; original type and game roles are unknown. */
typedef unsigned int Rac2Native_74a5d71aacb394c6_u32;

typedef struct {
    Rac2Native_74a5d71aacb394c6_u32 first[64];
    Rac2Native_74a5d71aacb394c6_u32 second[64];
    unsigned char gap[0x20];
    int count;
    Rac2Native_74a5d71aacb394c6_u32 current;
} Rac2Native_74a5d71aacb394c6_ExtraIndexState48;

extern int D_L03_002325D0[];

typedef float f32;

/* Relocates serialized header offsets and compacts each row in its original storage. */
typedef unsigned long long NativeCompactU64;

typedef union {
    s32 field00[4];
    struct {
        NativeCompactU64 field00;
        short field08;
        short field0A;
        unsigned short field0C;
        unsigned short field0E;
    } compact;
} NativeCompactRow16;

typedef struct {
    u8 field00[6];
    short field06;
    u8 field08[4];
    f32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1C;
    u32 field20;
} NativeCompactHeader;

extern s32 func_00282A18(s32 value);

#ifndef RAC2_T_V4_F213135AA
#define RAC2_T_V4_F213135AA
typedef struct { float x, y, z, w; } V4_F213135aa;
#endif

extern float F213135aa_FUN_002A7878(float a, float b);

extern void F213135aa_FUN_002833F0(char *a, char *b);

extern void F213135aa_FUN_00282F20(char *a, char *b, float f);

extern void F213135aa_FUN_00282CF0(char *a, char *b, char *c);

extern void F213135aa_FUN_00282DD8(char *a, char *b, char *c);

extern void F213135aa_FUN_002AB668(char *a, char *b, float f);

void func_002FC8D0(u8 *a0, s32 a1, s32 a2) {
    u8 image[112];
    s32 remain = (a2 + 0x3fff) & ~0x3fff;
    s32 src = 0, dst = 0;
    for (; remain > 0; remain -= 0x4000) {
        func_00126470(image, (s32)(short)((a1+src)>>8), 1, 1, 0, 0, 64, 64);
        src += 0x4000;
        func_0011AEA0(0);
        func_00126730(image,a0+dst);
        dst += 0x3000;
        func_001244B8(0,0);
    }
}

/* shared native body of family d50cdefed4015bae (default profile) */
void func_002FC990(int a0, int a1, int a2)
{
    int s0 = (a2 + 16383) & -16384;
    int s6 = 0;
    int s5 = 0;

    while (s0 > 0) {
        *(int *)((char *)D_L02_001B3D08_3 + 0) = 0x10000006;
        *(int *)((char *)D_L02_001B3D08_3 + 4) = 0;
        *(int *)((char *)D_L02_001B3D08_3 + 8) = 0;
        *(int *)((char *)D_L02_001B3D08_3 + 12) = 0x50000006;
        {
            int *next = (int *)((char *)D_L02_001B3D08_3 + 16);
            D_L02_001B3D08_5 = next;
            D_00126288(next, (short)((a1 + s6) >> 8), 1, 1, 0, 0, 64, 64);
        }
        s6 += 16384;
        s0 -= 16384;
        {
            int *p = D_L02_001B3D08_3;
            int off = a0 + s5;
            s5 += 12288;
            D_L02_001B3D08_5 = (int *)((char *)p + 96);
            *(int *)((char *)p + 96) = 0x30000300;
            *(int *)((char *)D_L02_001B3D08_3 + 4) = off;
            *(int *)((char *)D_L02_001B3D08_3 + 8) = 0;
            *(int *)((char *)D_L02_001B3D08_3 + 12) = 0x50000300;
            D_L02_001B3D08_5 = (int *)((char *)D_L02_001B3D08_3 + 16);
        }
    }
}

INCLUDE_ASM("asm/game", func_002FCB00);

INCLUDE_ASM("asm/game", func_002FCD18);

/* shared native body of family 349daa693c44d158 */
void func_002FCDA8(void)
{
    if ((*(volatile u32 *)0x1000E010 & 0x20000) != 0) {
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_0011A950(1, D_L03_001B31A0);
    func_0011A950(15, D_L03_001B31A4);
    func_0011B658(1);
    D_L03_001B31A0 = 0;
    D_L03_001B31A4 = 0;
}

INCLUDE_ASM("asm/game", func_002FCE18);

INCLUDE_ASM("asm/game", func_002FCF18);

INCLUDE_ASM("asm/game", func_002FCF90);

INCLUDE_ASM("asm/game", func_002FCFC8);

INCLUDE_ASM("asm/game", func_002FD1A0);

INCLUDE_ASM("asm/game", func_002FD1B8);

INCLUDE_ASM("asm/game", func_002FD828);

INCLUDE_ASM("asm/game", func_002FDB40);

INCLUDE_ASM("asm/game", func_002FDBD8);

INCLUDE_ASM("asm/game", func_002FDF40);

INCLUDE_ASM("asm/game", func_002FE5A0);

INCLUDE_ASM("asm/game", func_002FE880);

INCLUDE_ASM("asm/game", func_002FE8D8);

INCLUDE_ASM("asm/game", func_002FE9D0);

INCLUDE_ASM("asm/game", func_002FEC50);

INCLUDE_ASM("asm/game", func_002FEC78);

INCLUDE_ASM("asm/game", func_002FED28);

INCLUDE_ASM("asm/game", func_002FED78);

INCLUDE_ASM("asm/game", func_002FED90);

INCLUDE_ASM("asm/game", func_002FEE50);

INCLUDE_ASM("asm/game", func_002FEE70);

INCLUDE_ASM("asm/game", func_002FF0B0);

INCLUDE_ASM("asm/game", func_002FF0D8);

void func_002FF288(void)
{
}

INCLUDE_ASM("asm/game", func_002FF290);

INCLUDE_ASM("asm/game", func_002FF300);

INCLUDE_ASM("asm/game", func_002FF3F8);

INCLUDE_ASM("asm/game", func_002FF450);

INCLUDE_ASM("asm/game", func_002FF968);

INCLUDE_ASM("asm/game", func_002FFB68);

INCLUDE_ASM("asm/game", func_002FFCF8);

INCLUDE_ASM("asm/game", func_002FFD78);

INCLUDE_ASM("asm/game", func_002FFFE0);

INCLUDE_ASM("asm/game", func_00300048);

INCLUDE_ASM("asm/game", func_00300180);

INCLUDE_ASM("asm/game", func_00300190);

INCLUDE_ASM("asm/game", func_003001E0);

INCLUDE_ASM("asm/game", func_00300248);

s32 func_00300280(s32 *a0,s32 a1) {
 s32 out=-1,i=0,flag=1; s32 *p=a0;
 for(;i<64;i++,p++) {
  if(*p==0) {
   *p=a1;
   a0[0x89]=flag;
   a0[0x88]++;
   out=i;
   p[0x40]=0;
   break;
  }
 }
 return out;
}

/* Clear corresponding indexed words and decrement a record count */
void func_00300300(Rac2Native_74a5d71aacb394c6_ExtraIndexState48 *state, int index) {
    state->first[index] = 0;
    state->second[index] = 0;
    if (--state->count == 0) {
        state->current = 0;
    }
}

INCLUDE_ASM("asm/game", func_00300330);

INCLUDE_ASM("asm/game", func_003004A8);

INCLUDE_ASM("asm/game", func_003004B0);

/* shared native body of family 8a42bc68419c7402 */
int func_003004E0(int value)
{
    int i;
    int found = 0;

    for (i = 0; i < D_L03_002325D0[64]; i++)
    {
        if (D_L03_002325D0[i] == value)
        {
            found = 1;
            break;
        }
    }
    return found;
}

/* func_00300540 : dispatch: weapon category selected by the identifier */
s32 func_00300540(s32 a0) {
    s32 v = 0;
    if (a0 == 0 || a0 == 14 || a0 == 13) v = 2;
    else if (a0 == 1 || a0 == 3 || a0 == 11 || a0 == 12) v = 1;
    return v;
}

INCLUDE_ASM("asm/game", func_00300598);

INCLUDE_ASM("asm/game", func_003005A0);

/* relocates serialized offsets and compacts16-byte rows in their original storage using captured sourcewords */
NativeCompactHeader *func_00300618(NativeCompactHeader *header) {
    u32 base = (u32)header;
    NativeCompactRow16 *source;
    s32 index;
    header->field10 += base;
    header->field14 += base;
    header->field18 += base;
    header->field1C += base;
    if (header->field20 != 0) header->field20 += base;
    index = 0;
    source = (NativeCompactRow16 *)header->field18;
    header->field0C *= 0.0032116016f;
    if (header->field06 > 0) {
        do {
            s32 first = source->field00[0];
            s32 second = source->field00[1];
            s32 third = source->field00[2];
            s32 fourth = source->field00[3];
            ((NativeCompactRow16 *)header->field18)[index].compact.field0A = first >> 4;
            source++;
            ((NativeCompactRow16 *)header->field18)[index].compact.field08 = second >> 4;
            ((NativeCompactRow16 *)header->field18)[index].compact.field0C = func_00282A18(third);
            ((NativeCompactRow16 *)header->field18)[index].compact.field0E = func_00282A18(fourth);
            ((NativeCompactRow16 *)header->field18)[index].compact.field00 = 0;
            index++;
        } while (index < header->field06);
    }
    return header;
}

INCLUDE_ASM("asm/game", func_00300748);

INCLUDE_ASM("asm/game", func_00300910);

INCLUDE_ASM("asm/game", func_00300968);

INCLUDE_ASM("asm/game", func_00300A00);

INCLUDE_ASM("asm/game", func_00300AA8);

INCLUDE_ASM("asm/game", func_00300F58);

INCLUDE_ASM("asm/game", func_00301D10);

INCLUDE_ASM("asm/game", func_00301F18);

int func_003022A0(char *obj, char *obj2, float x, float y)
{
    V4_F213135aa m0, m1, m2;
    char *s1;
    char *s3;
    float f22;

    s1 = *(char **)(obj + 104);
    if (*(unsigned char *)(obj + 32) == 4)
        return 0;
    f22 = 0.0f;
    if (x == 0.0f)
        x = F213135aa_FUN_002A7878(-30.0f, 30.0f) * 1.7453294247388839721680e-02f;
    if (y == 0.0f)
        y = F213135aa_FUN_002A7878(f22, 30.0f) * 1.7453294247388839721680e-02f;
    s3 = s1 + 32;
    if (*(unsigned char *)(obj + 32) == 3) {
        F213135aa_FUN_002833F0((char *)&m0, s1 + 16);
        F213135aa_FUN_00282F20(s3, (char *)&m2, 1.3333334028720855712891e-01f);
    }
    *(float *)(s1 + 100) = f22;
    *(float *)(s1 + 76) = x;
    *(float *)(s1 + 72) = y;
    *(char **)(s1 + 96) = obj2;
    F213135aa_FUN_00282CF0((char *)&m1, obj2 + 16, obj + 16);
    s1 = s1 + 48;
    F213135aa_FUN_00282DD8((char *)&m0, s3, (char *)&m1);
    F213135aa_FUN_00282F20(s1, (char *)&m0, 1.0f);
    F213135aa_FUN_002AB668(s1, s1, 2.0943954586982727050781e-01f);
    *(unsigned char *)(obj + 32) = 4;
    return 1;
}

INCLUDE_ASM("asm/game", func_00302440);

INCLUDE_ASM("asm/game", func_00302470);

INCLUDE_ASM("asm/game", func_00302848);

INCLUDE_ASM("asm/game", func_00302A20);

INCLUDE_ASM("asm/game", func_00302A88);

INCLUDE_ASM("asm/game", func_00302DA0);

INCLUDE_ASM("asm/game", func_00303070);

INCLUDE_ASM("asm/game", func_00303210);

INCLUDE_ASM("asm/game", func_00303568);

INCLUDE_ASM("asm/game", func_00303738);

INCLUDE_ASM("asm/game", func_00303AC8);

INCLUDE_ASM("asm/game", func_00303BF8);

INCLUDE_ASM("asm/game", func_00303DA8);

INCLUDE_ASM("asm/game", func_00303E20);

INCLUDE_ASM("asm/game", func_00304128);
