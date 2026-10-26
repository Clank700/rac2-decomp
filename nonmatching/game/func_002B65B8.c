/* Near miss: the scan is the retail's instruction for instruction, but the
   shared tail is one instruction longer and the multiply lands in another
   register.

   func_002B65B8, boot 0x002B65B8, catalogue size 148 (0x94).
   Profile: the game's default `-O2 -G0 -ffunction-sections`.

   The retail bytes are

        002b65b8  lui    $v0,0x27
        002b65bc  daddu  $t0,$v0,$zero
        002b65c0  lw     $v1,-0x1780($v0)
        002b65c4  addiu  $v0,$zero,-1
        002b65c8  beq    $v1,$v0,. + 4 + (0xC << 2)
        002b65cc  daddu  $a2,$zero,$zero
        002b65d0  beq    $v1,$a0,. + 4 + (0xA << 2)
        002b65d4  addiu  $v1,$t0,-0x1780
        002b65d8  addiu  $a3,$zero,-1
        002b65dc  addiu  $v1,$v1,0xC
        002b65e0  lw     $v0,0($v1)
        002b65e4  beq    $v0,$a3,. + 4 + (0x5 << 2)
        002b65e8  addiu  $a2,$a2,0x1
        002b65ec  nop
        002b65f0  nop
        002b65f4  bne    $v0,$a0,. + 4 + (-0x6 << 2)
        002b65f8  addiu  $v1,$v1,0xC
        002b65fc  beqz   $a1,. + 4 + (0x7 << 2)
        002b6600  addiu  $a0,$zero,0xC
        002b6604  lui    $v1,0x1B
        002b6608  lw     $v1,0x1B44($v1)
        002b660c  mult   $a0,$a2,$a0
        002b6610  lui    $v0,0x1D
        002b6614  b      . + 4 + (0x6 << 2)
        002b6618  addiu  $v0,$v0,0x4E0
        002b661c  lui    $v1,0x1B
        002b6620  lw     $v1,0x1B40($v1)
        002b6624  mult   $a0,$a2,$a0
        002b6628  lui    $v0,0x1D
        002b662c  addiu  $v0,$v0,-0x20C0
        002b6630  addiu  $a1,$t0,-0x1780
        002b6634  sll    $v1,$v1,2
        002b6638  addu   $v1,$v1,$v0
        002b663c  addu   $a1,$a1,$a0
        002b6640  lw     $v0,0x4($a1)
        002b6644  jr     $ra
        002b6648  sw     $v0,0($v1)

   The table is the level's own dispatch table: three-word records - the class
   id, the function that updates that class, a shared auxiliary pointer - ended
   by a class id of -1.  The class count at 0x001B1B40 names the slot of a
   class with a header (the table at 0x001CDF40), the count at 0x001B1B44 the
   slot of a class without one (the table at 0x001D04E0); the second argument
   says which of the two the caller's class is.

   This C compiles to 152 bytes, four more than the retail, and matches 0 of 28
   places.  The scan is the retail's word for word - the same preheader tests
   of the first record, the same -1 terminator, the same 0xC stride and the
   same index in the delay slot of the terminator test - and the two branches
   and the shared tail have the retail's shape.  What is left is allocation in
   the tail: the retail materialises the constant 12 in the delay slot of the
   `beqz` and lets the multiply overwrite that register (the R5900
   three-operand `mult $a0,$a2,$a0`), while this cc1 materialises the constant
   later and multiplies into a third register (`mult $a1,$a2,$v0`); the shared
   tail also keeps one instruction more than the retail's.

   Tried: loading the update function in each branch and storing it after
   them (164 bytes, the tail loaded the function a second time); computing a
   record pointer in each branch (168 bytes, the loop changed shape); giving
   the byte offset to a variable computed in each branch (160 bytes, and the
   branch-likely form of the loop's back edge appeared); the same with the
   branches ordered counter first and the tail reaching the record through the
   struct type (152 bytes, the loop matches, the tail is one instruction
   longer and the multiply lands in another register).
*/

/* The level's class dispatch table: three-word records, each a class id, the
   function that updates that class and a shared auxiliary pointer, ended by a
   class id of -1. */
typedef struct {
    int classId;
    void (*update)(char *);
    void *aux;
} ClassDispatchRecord;

extern ClassDispatchRecord D_0026E880[];

extern void (*D_001CDF40[])(char *);
extern void (*D_001D04E0[])(char *);
extern int D_001B1B40;
extern int D_001B1B44;

void func_002B65B8(int classId, int noHeader)
{
    int i = 0;
    void (**dest)(char *);
    int slot;
    int off;

    while (D_0026E880[i].classId != -1) {
        if (D_0026E880[i].classId == classId)
            break;
        i++;
    }
    if (noHeader) {
        slot = D_001B1B44;
        dest = D_001D04E0;
        off = i * 12;
    } else {
        slot = D_001B1B40;
        dest = D_001CDF40;
        off = i * 12;
    }
    dest[slot] = ((ClassDispatchRecord *)((char *)D_0026E880 + off))->update;
}
