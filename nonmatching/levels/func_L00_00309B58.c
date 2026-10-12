/* 9 instructions, 2 swapped (+0x10 and +0x14): retail puts the constant 3 in the branch delay slot and the store address as lui $at; ours puts lui $v1 (the address) in the slot. Missing: how retail schedules the store of sym (assembler-expanded through $at). Same bytes as the other three. */
void func_L00_00309B58(void)
{
    int flags = (int)D_001A7424;
    if ((flags & 0x40) == 0) {
        D_001A7420_1 = 3;
    }
}
