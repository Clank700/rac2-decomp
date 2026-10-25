/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 120/120 bytes; us: 0/8 placements; us2: 0/8 placements; pal: 0/8 placements.
 * The state pointer is read before the guard, preserving retail ordering. A known state prefix
 * retains the index, elapsed word, phase and target pointer without asserting the complete object
 * extent. The full position copy is preserved. Owner/state GPR allocation and table-base sharing
 * differ from +0x4 despite equal size.
 * Reopen with actual owner/state live-range evidence. The typed prefix did not change the emitted
 * bytes; avoid more declaration permutations.
 * Prior complete variants and allocator diagnostics are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"


typedef int TI128 __attribute__((mode(TI)));

extern char *D_L02_001FF1C0[];
extern void func_002A7750(u8 *, s32, s32);

/* Known state prefix only; later fields and total extent are unspecified. */
struct TableState {
    s32 index;
    u8 unknown04[4];
    s32 elapsed;
    f32 phase;
    char *target;
};

void func_L02_003DBEC8(char *a0)
{
    struct TableState *q = *(struct TableState **)(a0 + 0x68);
    char *e;
    if (*(u8 *)(a0 + 0x20) != 0) {
        return;
    }
    *(u8 *)(a0 + 0x30) = 0x80;
    q->phase = -1.0f;
    e = D_L02_001FF1C0[q->index];
    q->elapsed = 0;
    q->target = e;
    qcopy(a0 + 0x10, e + 0x10);
    func_002A7750((u8 *)a0, 1, -1);
}
