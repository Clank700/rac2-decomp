/* Not a C row (wave 13, worker g3): the catalogue splits a piece of its neighbour.

   The three instructions at 0x002FED78 are

     002FED78  addiu $v0, $zero, -1
     002FED7C  nop
     002FED80  addiu $sp, $sp, 0x40

   and they are followed by the padding up to 0x002FED90, where func_002FED90 starts.
   The previous function ends at 0x002FED70 with its `jr $ra` and the `addiu $sp,$sp,0x10`
   in its delay slot.

   There is no `jr $ra` inside the row, so the code cannot return, and the
   `addiu $sp,$sp,0x40` has no matching prologue: the row is the tail of a function the
   catalogue cut in the wrong place. No C can be placed here. */

void func_002FED78(void)
{
}
