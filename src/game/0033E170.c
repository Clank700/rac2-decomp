#include "include_asm.h"

void* func_0033E170(void* param_1);

extern void func_0033AB50(int);

extern unsigned long long func_00347EA0(unsigned long long);

extern int func_0033E348(int);

void* func_0033E170(void* param_1)
{
  func_0033AB50((int)param_1 + 8);
  func_00347EA0((int)param_1 + 0x2b0);
  return param_1;
}

INCLUDE_ASM("asm/game", func_0033E1A8);

INCLUDE_ASM("asm/game", func_0033E1B0);

int func_0033E310(int owner)
{
    int result;
    result = func_0033E348(owner);
    return *(int *)(owner + 0x378) + result * 0x14;
}
