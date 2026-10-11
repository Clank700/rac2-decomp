#include "include_asm.h"

extern void func_00282CC0_2(char *dst, char *left, char *right);

extern void func_00300190(char *dst, char *src);

extern int func_00283CF0(float value);

extern void func_002B9180_2(char *object);

extern int func_00282978_1(char *p);

extern void func_002B9180_1(char *p);

extern void func_00282CC0_1(char *p0, char *p1, char *p2);

typedef int s32;

/*
 * Disassembled at 0x002cd220
 * Signature: int FUN_002cd220(void)
 * Behavior:
 *   - Saves RA on stack
 *   - Calls FUN_0027C540(0)
 *   - Calls FUN_0029C138()
 *   - Calls FUN_0027C660()
 *   - Restores RA from stack
 *   - Returns 0
 */
extern void func_0027C540_2(long);

extern void func_L00_0030D210(void);

extern void func_0027C660_2(void);

unsigned long long func_L00_00346A80(void);

extern void func_0027C540_9(long);

extern void func_L00_0030D2B0(void);

extern void func_0027C660_9(void);

/* Function at 0x002cd8c0: FUN_002CD8C0
 * 
 * Disassembly summary:
 * - 12 instructions, 48 bytes total
 * - Prologue: save ra, allocate 16-byte stack frame
 * - Three calls to external functions:
 *   1. FUN_0027C540(0)
 *   2. FUN_0029C450()
 *   3. FUN_0027C660()
 * - Epilogue: restore ra, return 0, deallocate stack
 * - No local variables used
 * - Return type is void-like; returns zero in v0
 * - Delay slots are_NOP/unused in this case
 */

/* External function declarations (exact addresses from task metadata) */
extern void func_0027C540_7(long);

extern void func_L00_0030D528(void);

extern void func_0027C660_7(void);

extern void func_0027C540_6(long);

extern void func_L00_0030D758(void);

extern void func_0027C660_6(void);

void func_0027C540_3(long);

void func_0027C660_3(void);

void func_L00_0030D808(void);

/* 
 * Function: FUN_002D2EE0
 * 
 * Disassembly summary:
 * - Saves return address on stack
 * - Calls FUN_0027C540(0) (with zero argument)
 * - Calls FUN_0029C7A0()
 * - Calls FUN_0027C660()
 * - Restores return address
 * - Returns 0
 *
 * Notes:
 * - The function follows standard MIPS ABI prologue/epilogue.
 * - Delay slots are filled with NOP or argument setup as seen in disassembly.
 * - No local variables used.
 * - All external function addresses come from the assigned externals list.
 */

extern void func_0027C540_4(long arg0);

extern void func_L00_0030D878(void);

extern void func_0027C660_4(void);

/* External function declarations as per target specification */
extern void func_0027C540_5(long);

extern void func_0027C660_5(void);

extern void func_L00_0030D9C8(void);

/* External functions declared with exact aliases from task.externals */
extern void func_0027C540_8(long param_1);

extern void func_0027C660_8(void);

extern void func_L00_0030DA38(void);

/* Target: FUN_002d5540 on MIPS (SCUS_972.68, -O2 -G0 -ffunction-sections)
 * Calls three externals: FUN_0027C540(int), FUN_0029CED8(void), FUN_0027C660(void)
 * Returns 0. Stack frame size 16 bytes. Delay slots filled.
 */
extern void func_0027C540_1(long);

extern void func_L00_0030DFE0(void);

extern void func_0027C660_1(void);

/* Frozen Batch A A03-counter-mod50-80; acknowledged claim b5e8cf533fd3cee3cb2dcdd0bf7be9549f6cc39cd932c589176487a8b170abee. */
typedef int BatchA_A03_s32;

extern BatchA_A03_s32 D_L00_001A8FE0[] __attribute__((sda));

extern BatchA_A03_s32 D_001A7BC0[] __attribute__((sda));

extern BatchA_A03_s32 D_001A7B90_1[] __attribute__((sda));

/* Read the word at offset 0x 18 through the pointer stored at owner offset 0x 68. */
unsigned int func_L00_0032C638(unsigned int param_1)
{
    unsigned int inner_ptr;
    unsigned int result;

    inner_ptr = *(unsigned int *)(param_1 + 0x68);
    result = *(unsigned int *)(inner_ptr + 0x18);
    return result;
}

INCLUDE_ASM("asm/levels", func_L00_0032C9B8);

INCLUDE_ASM("asm/levels", func_L00_0032CA28);

INCLUDE_ASM("asm/levels", func_L00_0032CB30);

INCLUDE_ASM("asm/levels", func_L00_0032CF60);

INCLUDE_ASM("asm/levels", func_L00_0032D100);

INCLUDE_ASM("asm/levels", func_L00_0032D208);

INCLUDE_ASM("asm/levels", func_L00_0032D310);

INCLUDE_ASM("asm/levels", func_L00_0032EF10);

INCLUDE_ASM("asm/levels", func_L00_0032EFB0);

INCLUDE_ASM("asm/levels", func_L00_0032F030);

INCLUDE_ASM("asm/levels", func_L00_0032F038);

INCLUDE_ASM("asm/levels", func_L00_0032F080);

void func_L00_003318D8(void)
{
}

INCLUDE_ASM("asm/levels", func_L00_00333E20);

INCLUDE_ASM("asm/levels", func_L00_00333F90);

/* Calls a three-argument callee twice and a two-argument callee twice over fields of the first object, folds a float field through a float-to-int callee into an int field of the object, and calls a last callee when the updated field is negative. */
void func_L00_003340A8(char *a)
{
    char *p1 = a + 16;
    char *p2 = a + 32;
    char *p3 = a + 48;
    int v;

    func_00282CC0_2(p1, p1, p3);
    func_00282CC0_2(p2, p2, p3);
    func_00300190(p1, p1);
    func_00300190(p2, p2);
    v = *(int *)(a + 4) - (func_00283CF0(*(float *)(p3 + 12)) << 24);
    *(int *)(a + 4) = v;
    *(int *)(a + 12) = v;
    if (v < 0)
        func_002B9180_2(a);
}

INCLUDE_ASM("asm/levels", func_L00_00335558);

INCLUDE_ASM("asm/levels", func_L00_00336548);

INCLUDE_ASM("asm/levels", func_L00_00338AE0);

INCLUDE_ASM("asm/levels", func_L00_00338D28);

INCLUDE_ASM("asm/levels", func_L00_00338DF8);

INCLUDE_ASM("asm/levels", func_L00_0033AA40);

INCLUDE_ASM("asm/levels", func_L00_0033BA68);

INCLUDE_ASM("asm/levels", func_L00_0033C0D0);

INCLUDE_ASM("asm/levels", func_L00_0033C238);

INCLUDE_ASM("asm/levels", func_L00_0033C638);

INCLUDE_ASM("asm/levels", func_L00_0033E210);

INCLUDE_ASM("asm/levels", func_L00_0033E220);

INCLUDE_ASM("asm/levels", func_L00_0033E3B8);

INCLUDE_ASM("asm/levels", func_L00_0033E888);

INCLUDE_ASM("asm/levels", func_L00_0033EA00);

INCLUDE_ASM("asm/levels", func_L00_0033EC48);

INCLUDE_ASM("asm/levels", func_L00_0033EE38);

/* Guarded child-descriptor update: when the guard call returns non-zero the child is released, otherwise a packed colour byte is folded into a parent word and a four-float vector is assembled and handed to a spawn helper before three counters are advanced. */
void func_L00_0033F678(char *a0)
{
    char local[16];
    char *s1 = a0;
    char *s0;
    int a1;
    int v1;
    char *p;

    if (func_00282978_1(a0 + 10) != 0) {
        func_002B9180_1(a0);
        return;
    }
    s0 = a0 + 32;
    a1 = *(int *)(s1 + 4);
    v1 = (a1 >> 24) + *(unsigned char *)(s0 + 20);
    *(int *)(s1 + 4) = (a1 & 0x00ffffff) | (v1 << 24);
    p = s1 + 16;
    *(float *)(local + 0) = *(float *)(s1 + 32);
    *(float *)(local + 4) = *(float *)(s0 + 4);
    *(float *)(local + 8) = *(float *)(s0 + 8);
    *(int *)(local + 12) = 0;
    func_00282CC0_1(p, p, local);
    *(float *)(s0 + 8) = *(float *)(s0 + 8) - *(float *)(s0 + 12);
    *(unsigned char *)(s1 + 8) = *(unsigned char *)(s1 + 8) + *(unsigned char *)(s0 + 21);
    *(float *)(s1 + 12) = *(float *)(s1 + 12) + *(float *)(s0 + 16);
}

INCLUDE_ASM("asm/levels", func_L00_0033FFB8);

INCLUDE_ASM("asm/levels", func_L00_003402B8);

/* Guarded child-descriptor update: when the guard call returns non-zero the child is released, otherwise a packed colour byte is folded into a parent word and a four-float vector is assembled and handed to a spawn helper before three counters are advanced. */
void func_L00_00340490(char *a0)
{
    char local[16];
    char *s1 = a0;
    char *s0;
    int a1;
    int v1;
    char *p;

    if (func_00282978_1(a0 + 10) != 0) {
        func_002B9180_1(a0);
        return;
    }
    s0 = a0 + 32;
    a1 = *(int *)(s1 + 4);
    v1 = (a1 >> 24) + *(unsigned char *)(s0 + 20);
    *(int *)(s1 + 4) = (a1 & 0x00ffffff) | (v1 << 24);
    p = s1 + 16;
    *(float *)(local + 0) = *(float *)(s1 + 32);
    *(float *)(local + 4) = *(float *)(s0 + 4);
    *(float *)(local + 8) = *(float *)(s0 + 8);
    *(int *)(local + 12) = 0;
    func_00282CC0_1(p, p, local);
    *(float *)(s0 + 8) = *(float *)(s0 + 8) - *(float *)(s0 + 12);
    *(unsigned char *)(s1 + 8) = *(unsigned char *)(s1 + 8) + *(unsigned char *)(s0 + 21);
    *(float *)(s1 + 12) = *(float *)(s1 + 12) + *(float *)(s0 + 16);
}

INCLUDE_ASM("asm/levels", func_L00_00340560);

INCLUDE_ASM("asm/levels", func_L00_003406E8);

INCLUDE_ASM("asm/levels", func_L00_00340898);

INCLUDE_ASM("asm/levels", func_L00_00340CF8);

INCLUDE_ASM("asm/levels", func_L00_003411A0);

INCLUDE_ASM("asm/levels", func_L00_00341410);

INCLUDE_ASM("asm/levels", func_L00_00341658);

INCLUDE_ASM("asm/levels", func_L00_00341798);

/* advances an index with signed delta and either wraps by count or clamps the applicable endpoint */
/* Advances a signed index, wrapping or clamping to the measured count. */
s32 func_L00_003417B8(const s32 *count, s32 index, s32 delta, s32 wrap) {
    if (wrap != 0) {
        index = (index + delta + *count) % *count;
    } else {
        index += delta;
        if (delta < 0) {
            if (index < 0) index = 0;
        } else if (index > *count - 1) {
            index = *count - 1;
        }
    }
    return index;
}

INCLUDE_ASM("asm/levels", func_L00_00341820);

INCLUDE_ASM("asm/levels", func_L00_00341A88);

INCLUDE_ASM("asm/levels", func_L00_00341B18);

INCLUDE_ASM("asm/levels", func_L00_00341D08);

INCLUDE_ASM("asm/levels", func_L00_00341FA8);

INCLUDE_ASM("asm/levels", func_L00_003425F8);

INCLUDE_ASM("asm/levels", func_L00_00342C80);

INCLUDE_ASM("asm/levels", func_L00_00342EB0);

unsigned int func_L00_00345AF0(void)
{
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_00345AF8);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
int func_L00_00346680(void)
{
  func_0027C540_2(0);
  func_L00_0030D210();
  func_0027C660_2();
  return 0;
}

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
unsigned long long func_L00_00346A80(void)
{
  func_0027C540_9(0);
  func_L00_0030D2B0();
  func_0027C660_9();
  return 0;
}

INCLUDE_ASM("asm/levels", func_L00_00346AB0);

INCLUDE_ASM("asm/levels", func_L00_00346AB8);

INCLUDE_ASM("asm/levels", func_L00_00346B50);

INCLUDE_ASM("asm/levels", func_L00_00346CD8);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
long long func_L00_00346D20(void)
{
    func_0027C540_7(0LL);
    func_L00_0030D528();
    func_0027C660_7();
    return 0LL;
}

INCLUDE_ASM("asm/levels", func_L00_00346DB0);

INCLUDE_ASM("asm/levels", func_L00_00347A28);

INCLUDE_ASM("asm/levels", func_L00_003485E8);

INCLUDE_ASM("asm/levels", func_L00_00349040);

INCLUDE_ASM("asm/levels", func_L00_00349628);

INCLUDE_ASM("asm/levels", func_L00_0034B470);

INCLUDE_ASM("asm/levels", func_L00_0034BC90);

INCLUDE_ASM("asm/levels", func_L00_0034C038);

INCLUDE_ASM("asm/levels", func_L00_0034C060);

INCLUDE_ASM("asm/levels", func_L00_0034C090);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
int func_L00_0034C118(void)
{
    func_0027C540_6(0);
    func_L00_0030D758();
    func_0027C660_6();
    return 0;
}

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
unsigned long long func_L00_0034C288(void)
{
    func_0027C540_3(0);
    func_L00_0030D808();
    func_0027C660_3();
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_0034C2B8);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
unsigned long long func_L00_0034C340(void)
{
    func_0027C540_4(0);
    func_L00_0030D878();
    func_0027C660_4();
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_0034C370);

INCLUDE_ASM("asm/levels", func_L00_0034C3F8);

INCLUDE_ASM("asm/levels", func_L00_0034C428);

INCLUDE_ASM("asm/levels", func_L00_0034C4B0);

INCLUDE_ASM("asm/levels", func_L00_0034C4E0);

INCLUDE_ASM("asm/levels", func_L00_0034C568);

INCLUDE_ASM("asm/levels", func_L00_0034C638);

INCLUDE_ASM("asm/levels", func_L00_0034C668);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
/* Implementation matching decompiled output */
long func_L00_0034C6F0(void)
{
  func_0027C540_5(0);
  func_L00_0030D9C8();
  func_0027C660_5();
  return 0;
}

INCLUDE_ASM("asm/levels", func_L00_0034C720);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
/* Candidate function: FUN_002d3390 */
unsigned long long func_L00_0034C7F0(void)
{
    func_0027C540_8(0);
    func_L00_0030DA38();
    func_0027C660_8();
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_0034C8E8);

INCLUDE_ASM("asm/levels", func_L00_0034E6F0);

INCLUDE_ASM("asm/levels", func_L00_0034E950);

INCLUDE_ASM("asm/levels", func_L00_0034E978);

/* Run the three measured setup calls with an explicit long zero, then return the defined integer zero. */
long long func_L00_0034E9A0(void)
{
    func_0027C540_1(0);
    func_L00_0030DFE0();
    func_0027C660_1();
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_0034EA38);

INCLUDE_ASM("asm/levels", func_L00_0034EB78);

INCLUDE_ASM("asm/levels", func_L00_0034EC00);

INCLUDE_ASM("asm/levels", func_L00_0034ECD0);

INCLUDE_ASM("asm/levels", func_L00_0034ED58);

INCLUDE_ASM("asm/levels", func_L00_0034ED80);

INCLUDE_ASM("asm/levels", func_L00_0034EDB0);

INCLUDE_ASM("asm/levels", func_L00_0034EDC8);

INCLUDE_ASM("asm/levels", func_L00_0034EF68);

INCLUDE_ASM("asm/levels", func_L00_00350F20);

INCLUDE_ASM("asm/levels", func_L00_00350F28);

unsigned int func_L00_00351608(void)
{
    return 0;
}

INCLUDE_ASM("asm/levels", func_L00_00357CB0);

/* A03-counter-mod50-80 freshly exact-verified under family reservation */
void func_L00_003584B0(void)
{
    if (D_L00_001A8FE0[0] == 0) {
        BatchA_A03_s32 n = D_001A7BC0[0] + 1;
        D_001A7BC0[0] = n;
        if (n % 50 == 0) {
            if (D_001A7B90_1[0]) {
                D_001A7BC0[0] = n + 10;
            }
        }
    }
}

/* Return the constant signed integer one. */
/* Returns the constant integer 1. Matches FUN_0012F940 disassembly and decompilation. */
int func_L00_00358668(void) {
    return 1;
}

INCLUDE_ASM("asm/levels", func_L00_00358670);

INCLUDE_ASM("asm/levels", func_L00_003586A0);

INCLUDE_ASM("asm/levels", func_L00_003588A8);

INCLUDE_ASM("asm/levels", func_L00_00358B30);

INCLUDE_ASM("asm/levels", func_L00_00358D50);
