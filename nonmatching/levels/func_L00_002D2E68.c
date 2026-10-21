/* Not attempted - body read in full, no C written: a loop over seven slots, 508 bytes,
   27 places.

   The body: the state block's first object gets its halfword flag 0x34 set; the call
   to func_L00_002D6418 runs only on the first turn of the loop; the word at
   $gp-0x60F0 (0x001A8F00, the same word the `lui`/`addiu` pair loads a few words
   later) decides the branch; the two guards on the shorts at 0x001BCAC0+0x44 and at
   0x00152C00+0x20 pick the path; a walk over the table at 0x001BCAC0+0x18C keeps the
   last entry's flag with a `movz`; and the three pointers at the base of the state
   (+0x1220, +0x1224, +0x1228) each get their halfword flag 0x34 set when they are
   not null.

   The blocking word is at +0xF8: `mult $s0,$v0` (the count times 0x50) is followed by
   `addu $a0,$v1,$s5`, and $v1 is the *high* word the multiply leaves in $hi - the
   retail takes the high half of a 64-bit product as the address offset, with no
   `mfhi` and no shift.  Plain C cannot spell that: a 64-bit multiply needs its `mfhi`
   and its shift, and a 32-bit multiply leaves the low half in $lo, not in the
   register the address is built from.  The loop's other shapes (the `bnel`/`bnez`
   chain, the `sltiu` range test on the count, the `movz` of the walk) are ordinary
   C, and the word at $gp-0x60F0 needs the two-name pattern (an `sda` name for the
   $gp form and an absolute alias for the macro form) in a `-g8` unit. */
