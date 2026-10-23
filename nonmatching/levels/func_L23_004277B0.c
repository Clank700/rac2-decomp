#include "include_asm.h"

typedef unsigned char u8;
typedef int s32;

/*
 * func_L23_004277B0 -- catalogue entry is 8 bytes early; the body below is measured
 * and complete, but check.py compares the full 52 catalogued bytes.
 *
 * retail, extent 0x004277B0..0x004277E4 (52 bytes):
 *   0x004277B0  addiu $sp, $sp, 0x190     <- unmatched restore after a completed return
 *   0x004277B4  nop
 *   0x004277B8  addiu $sp, $sp, -0x10     <- real entry, 44-byte wrapper
 *   0x004277BC  sd $s0, 0x0($sp)
 *   0x004277C0  sd $ra, 0x8($sp)
 *   0x004277C4  jal func_L23_004277E8 ; 0x004277C8 daddu $s0,$a0,$zero
 *   0x004277CC  jal func_L23_004278B0 ; 0x004277D0 daddu $a0,$s0,$zero
 *   0x004277D4  ld $s0, 0x0($sp)
 *   0x004277D8  ld $ra, 0x8($sp)
 *   0x004277DC  jr $ra
 *   0x004277E0  addiu $sp, $sp, 0x10
 *   0x004277E4  nop                       <- the next entry's own alignment word
 *
 * Retail control on 23 October 2026: the preceding `jr $ra` is at 0x004277A4,
 * its delay slot at 0x004277A8 restores 0xD0, and 0x004277AC is nop. The
 * positive 0x190 adjustment is therefore unmatched residue, not that return's
 * delay slot. The data pointer at 0x002ABE40 targets 0x004277B8. PS2Recomp
 * independently finds that entry but includes the trailing nop in its 48-byte
 * extent; the wrapper itself is 44 bytes. A generator correction still needs
 * qualification; this retained C is not an integrated match. It preserves arg0
 * because the first call clobbers $a0:
 */

extern void func_L23_004277E8(u8 *);
extern void func_L23_004278B0(u8 *);

void func_L23_004277B0(u8 *arg0) {
    func_L23_004277E8(arg0);
    func_L23_004278B0(arg0);
}

/* A tools/levels.py LEVEL_ENTRY_OFFSETS{(23, 0x004277B0): 8} entry (the mechanism
 * already used for the three level-0 entries) would put the 44 bytes above into
 * check.py's reach. */
