/* Twelve bytes, `addiu $sp,$sp,0x30; nop; addiu $sp,$sp,0x50`, no `jr $ra` and
   nothing that sets a register it reads. The twelve bytes before it are the end of
   the previous function (`jr $ra; addiu $sp,$sp,0x50` at 0x0032E890..0x0032E894),
   so the row is a split-off remnant between two entries, not C.
   What follows the row is a real body: `nop` at 0x0032E8A4, then its prologue
   `addiu $sp,$sp,-0x70; sd $s2,0x40($sp); sd $s3,0x48($sp)` at 0x0032E8A8, so the
   row is the previous function's tail plus padding and the catalogue entry for
   the body it leads into is elsewhere. One place only (17_smolg).
   Fix belongs in tools/levels.py. Kept as data for the maintainers. */
