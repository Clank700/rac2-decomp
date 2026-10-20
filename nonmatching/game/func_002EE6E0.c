/* 220-byte near miss; retail is 216 bytes. Same calls in the same order, but this cc1 keeps the owner in $s1 (retail $s0), so the first early exit is a plain branch with the epilogue restore in its delay slot where retail has a branch-likely, and it repeats the loop guard above the loop where retail jumps straight to the test. Every loop spelling tried (for, while, break form, index or pointer walk, positive guards) also gives 220 bytes. */
extern int func_002ED688(unsigned char *owner);
extern unsigned int func_002EE6A8(unsigned char *owner);
extern void func_002EE678(unsigned char *owner, unsigned int value);
extern int func_002ACCA8(unsigned char *a, int b);
extern void func_002ED9C0(unsigned char *owner);
extern void func_002EE8B0(char *a0);
extern int D_00214F90[];

void func_002EE6E0(unsigned char *owner)
{
    int *base = D_00214F90;
    int *p;
    int i;
    unsigned int state;

    if (base[36] == 0)
        return;
    if (func_002ED688(owner) == 0)
        return;
    state = func_002EE6A8(owner);
    if (state == 0xB)
        return;
    if (state == 0xD)
        func_002EE678(owner, 1);
    p = base + 39;
    for (i = 0; i < base[36]; i++, p++) {
        if (func_002ACCA8(owner + 0x10, *p)) {
            func_002ED9C0(owner);
            func_002EE678(owner, 0xD);
            func_002EE8B0((char *)owner);
            return;
        }
    }
}
