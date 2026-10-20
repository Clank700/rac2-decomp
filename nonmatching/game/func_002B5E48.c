/* from src/game/002B5278.c: 176 bytes, the size of retail's, not matched.
 * The first instruction differs: retail copies $a0 (obj) to $a2 on entry, because $a0 is
 * reused for the field at moby+0x3C that feeds the call; this cc1 keeps obj in $a0 and loads
 * the field into a temporary. Retail's moby base is in $s1 and the moby+0x60 pointer in $s0,
 * the other way round here. The 16-byte source is folded into an lq offset where retail
 * loads through a materialised pointer. */
typedef int TI128_002B5E48 __attribute__((mode(TI)));
typedef union { TI128_002B5E48 q; float f[4]; } Vec4Q_002B5E48;

extern int func_002C9218(int a0, void *a1, void *a2, float f);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(char *, char *, float);

int func_002B5E48(char *obj, char *moby)
{
    Vec4Q_002B5E48 v;
    char *s2;
    char *s0;
    int id;

    id = *(int *)(moby + 0x3C);
    if (id == -1) return 0;
    if (*(unsigned int *)(moby + 0x9C) & 1) return 0;
    s2 = obj + 0x10;
    v.q = *(TI128_002B5E48 *)s2;
    s0 = moby + 0x60;
    if (func_002C9218(id, &v, s2, *(float *)moby) != 0) {
        func_00282CF0(s0, &v, s2);
        func_00282F20(s0, s0, *(float *)moby);
        *(unsigned int *)(moby + 0x94) |= 0x10;
        return 1;
    }
    return 0;
}
