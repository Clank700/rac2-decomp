/* func_002AFF60, near miss (not linked): 116 bytes compiled against retail's 120.
   Retail copies the first argument into $v0 on entry, sets $a0 and $a1 for the call to
   func_00282CF0, then moves $v0 into $a2 in the call's delay slot. This cc1 coalesces the
   copy: it moves $a0 into $a2 before $a0 and $a1 are set (the arguments left to right
   in retail, right to left here). Tried: char * parameters, unsigned int (matches the
   same 116 bytes), a separate local holding the first argument (116 bytes), unsigned long
   (64-bit in this compiler: 148 bytes). Register allocation and move order only. */
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern char D_001AC8B0[];

void func_002AFF60(char *a, char *b, int c)
{
    func_00282CF0(b, D_001AC8B0, a);
    *(int *)(b + 8) = 0;
    func_00282F20(b, b, 1.0f);
    if (c == 0)
        func_00282D30(b, b, -1.0f);
}
