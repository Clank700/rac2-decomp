/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier -mno-split-addresses -fno-schedule-insns
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: 0/1 placements.
 * US compiled size: 192 bytes; retail: 184 bytes.
 * Remaining difference: 192 bytes versus 184. A self-position pointer is kept in S2 across three calls, producing an extra save/restore; retail recomputes that address. The actual allocator dump confirms the three-call live range. Helper and address/scheduling variants tied.
 * Reopen only with: A genuine field lifetime or qualified API contract that causes address recomputation without artificial barriers, register pins or false alias information.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
extern int D_L02_001B0138 __attribute__((sda));
extern int D_L02_001B013C NOT_SDA;
extern int func_L01_0031BC68(int, int, float);
extern void func_002A7750(u8 *, int, int), func_L00_003294F0(u8 *, int);
extern int func_L02_002EF388(void *, void *, void *, void *, int);
/* Restores the actor's saved spawn point and registers its hidden proxy. */
/* Partial actor prefix used only for its measured state and vector fields. */
typedef struct { u8 prefix[0x10]; Quad position; u8 gap[0x48]; char *state; } L02_SpawnActorView;
void func_L02_003D0238(char *self) {
    L02_SpawnActorView *actor=(L02_SpawnActorView *)self;
    char *state = actor->state;
    *(int *)(state + 0xD8) = 0;
    *(int *)(self + 0x78) = func_L01_0031BC68(D_L02_001B0138, D_L02_001B013C, *(float *)(state + 0xD8));
    func_002A7750((u8 *)self, 1, -1);
    qcopy(&actor->position,state + 0xA0);
    qcopy(state + 0x60,state + 0xA0);
    qzero(state + 0x50);
    self[0x31] = 1;
    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFFE) | 0x1000;
    func_L00_003294F0((u8 *)self, 0);
    func_L02_002EF388(self, &actor->position, self + 0xF0, 0, 0);
}
