#include "include_asm.h"

extern int func_0033E348(int);

extern int func_00348128(unsigned char *);

typedef int s32;

typedef unsigned char u8;

void func_00348138(int);

void func_00348138(int param_1);

extern void func_00348068(unsigned char *owner, float *records);

int func_0033E348(int owner)
{
    return func_00348128((unsigned char *)(owner + 0x2b0));
}

INCLUDE_ASM("asm/game", func_0033E368);

INCLUDE_ASM("asm/game", func_0033E3A0);

INCLUDE_ASM("asm/game", func_0033E428);

INCLUDE_ASM("asm/game", func_0033E480);

INCLUDE_ASM("asm/game", func_0033E4B8);

INCLUDE_ASM("asm/game", func_0033E4C0);

INCLUDE_ASM("asm/game", func_0033E5C0);

INCLUDE_ASM("asm/game", func_0033E620);

INCLUDE_ASM("asm/game", func_0033E640);

INCLUDE_ASM("asm/game", func_0033E6C8);

INCLUDE_ASM("asm/game", func_0033E6D0);

INCLUDE_ASM("asm/game", func_0033EA60);

INCLUDE_ASM("asm/game", func_0033EC98);

INCLUDE_ASM("asm/game", func_0033ED88);

INCLUDE_ASM("asm/game", func_0033F030);

INCLUDE_ASM("asm/game", func_0033F0A0);

INCLUDE_ASM("asm/game", func_0033F210);

INCLUDE_ASM("asm/game", func_0033F218);

INCLUDE_ASM("asm/game", func_0033FB98);

INCLUDE_ASM("asm/game", func_00340250);

INCLUDE_ASM("asm/game", func_00340498);

INCLUDE_ASM("asm/game", func_00340638);

INCLUDE_ASM("asm/game", func_003407F8);

INCLUDE_ASM("asm/game", func_003409C8);

INCLUDE_ASM("asm/game", func_00340B70);

INCLUDE_ASM("asm/game", func_00340D18);

INCLUDE_ASM("asm/game", func_00340D68);

INCLUDE_ASM("asm/game", func_00341030);

INCLUDE_ASM("asm/game", func_003411B0);

INCLUDE_ASM("asm/game", func_003411C0);

INCLUDE_ASM("asm/game", func_00341220);

/* stores three consecutive words; byte-identical across all 27 levels. */
void func_00341540(u8 *a0, s32 a1, s32 a2, s32 a3) { *(s32 *)(a0 + 0x2F0) = a1; *(s32 *)(a0 + 0x2F4) = a2; *(s32 *)(a0 + 0x2F8) = a3; }

/* Measured target: byte-identical across all 27 levels. */
void func_00341550(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x220) = a1; }

INCLUDE_ASM("asm/game", func_00341558);

INCLUDE_ASM("asm/game", func_003415B8);

INCLUDE_ASM("asm/game", func_00341610);

INCLUDE_ASM("asm/game", func_00341760);

void func_003417C8(void)
{
}

INCLUDE_ASM("asm/game", func_003417D0);

INCLUDE_ASM("asm/game", func_003418C0);

INCLUDE_ASM("asm/game", func_00341A48);

void func_00341A68(int param_1)
{
  func_00348138(param_1 + 0x228);
  return;
}

INCLUDE_ASM("asm/game", func_00341A88);

INCLUDE_ASM("asm/game", func_00341C20);

INCLUDE_ASM("asm/game", func_00341C90);

INCLUDE_ASM("asm/game", func_00341CD0);

/* Measured target: byte-identical across all 27 levels. */
void func_00341CD8(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x8) = a1; }

INCLUDE_ASM("asm/game", func_00341CE0);

INCLUDE_ASM("asm/game", func_00341E50);

INCLUDE_ASM("asm/game", func_00341E58);

INCLUDE_ASM("asm/game", func_00341E90);

INCLUDE_ASM("asm/game", func_00341EB0);

INCLUDE_ASM("asm/game", func_00341EE8);

INCLUDE_ASM("asm/game", func_00341F38);

INCLUDE_ASM("asm/game", func_003420C8);

INCLUDE_ASM("asm/game", func_00342118);

void func_00342380(unsigned char *owner, float *records)
{
    *(float **)(owner + 0x250) = records;
    func_00348068(owner + 0x188, records);
}

/* Measured target: byte-identical across all 27 levels. */
void func_003423A8(u8 *a0, s32 a1) { *(s32 *)(a0 + 0x170) = a1; }

/* multiplies the index by 20 and adds it to a base; byte-identical across all 27 levels. */
s32 func_003423B0(u8 *a0) { return *(s32 *)(a0 + 0x250) + *(s32 *)(a0 + 0x16C) * 20; }

INCLUDE_ASM("asm/game", func_003423C8);

void func_00342420(void)
{
}

INCLUDE_ASM("asm/game", func_00342428);

INCLUDE_ASM("asm/game", func_003424C0);

INCLUDE_ASM("asm/game", func_003425B8);
