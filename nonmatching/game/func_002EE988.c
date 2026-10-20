/* 364-byte near miss; retail is 372 bytes. Same calls, same constants and the same two 16-byte copies. Differences: the table pointer's high half goes to $a0 (retail $s0), so the index load is scheduled first; this cc1 keeps the object pointer in $s4 and the owner in $s3 (retail: owner in $s4, object+0x60 in $s3, the object only in $a0); the locals d and e swap their stack slots (retail d at 0x30, e at 0x40); and the first copy is not scheduled ahead of the constant setup. */
typedef int V4_Fb6552688 __attribute__((mode(TI)));
extern int func_002ED688(unsigned char *owner);
extern unsigned int func_002ED870(void);
extern void func_00282CF0(void *a0, void *a1, void *a2);
extern float func_00282DF0(char *a0);
extern void func_00282D30(char *a0, char *a1, float f);
extern void func_00282F20_10(V4_Fb6552688 *, char *, float);
extern void func_00282CC0_26(char *, V4_Fb6552688 *, char *);
extern int func_002761F8(char *a0, char *a1, int mode, char *self, int flag);
extern int func_00277258(char *a0, int mode, char *self, float scale);
extern V4_Fb6552688 D_001BAFA0;
extern V4_Fb6552688 D_001BAFB0;
extern char *D_001B1C54;
extern int D_00214F90[];

void func_002EE988(char *owner)
{
    V4_Fb6552688 a;
    V4_Fb6552688 b;
    V4_Fb6552688 c;
    V4_Fb6552688 d;
    V4_Fb6552688 e;
    char *object;
    char *table;
    float len;

    if (func_002ED870() != 0)
        return;
    object = (char *)func_002ED688((unsigned char *)owner);
    if (object == 0)
        return;
    table = D_001B1C54 + D_00214F90[0] * 128;
    func_00282CF0(&a, object + 0x60, table + 0x30);
    len = func_00282DF0((char *)&a);
    if (*(float *)table < len) {
        func_00282F20_10(&a, (char *)&a, len - (len - *(float *)table));
        func_00282CC0_26(object + 0x60, &a, table + 0x30);
    }
    if (func_002761F8(owner + 0x10, object + 0x60, 2, owner, 0)) {
        d = D_001BAFA0;
        func_00282D30((char *)&b, (char *)&D_001BAFA0 + 0x20, 0.00097656f);
        func_00282F20_10(&c, (char *)&b, 5.0f);
        func_00282CC0_26((char *)&e, &d, (char *)&c);
        *(V4_Fb6552688 *)(object + 0x60) = e;
    }
    if (func_00277258(object + 0x60, 2, (char *)owner, 5.0f)) {
        *(V4_Fb6552688 *)(object + 0x60) = D_001BAFB0;
    }
}
