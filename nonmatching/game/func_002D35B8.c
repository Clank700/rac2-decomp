/* func_002D35B8 (228 bytes, 28 places), closer M2: 228/228 under -O2 -G0.
 * Rewritten from retail: the root pointer at 0x1A8CFC is an sda word re-read with the
 * lw macro at each use; func_00343560 returns the class index into D_00139568; the class
 * records are 0xE0 bytes at D_00239BA0; both fields are stored as words; the function
 * returns 0. (The old draft named callees that do not exist and used literal addresses.)
 * Left: the saved-register roles rotate (retail: 0x139568 table s0, records s1, 0x3C108
 * s2, object/target s3, 0xE0 s4; here the offset and the record base swap), and with it
 * the schedule of the second index load. The offset as a local is worse. */
typedef struct {
    char pad00[6];
    short f06;
    char pad08[0x3A];
    short f42;
    char pad44[0x9C];
} ClassRecord;

extern char *D_001A8CFC __attribute__((sda));
extern unsigned char D_00139568[];
extern ClassRecord D_00239BA0[];

extern void func_00341550(void *, int);
extern int func_00343560(unsigned char *);
extern char *func_003435A8(char *);

int func_002D35B8(char *object)
{
    char *target;

    if (D_001A8CFC != 0) {
        func_00341550(D_001A8CFC + 0x3BE08, 1);
        {
            int v = D_00239BA0[D_00139568[func_00343560((unsigned char *)D_001A8CFC + 0x3C108)]].f42;
            char *a = D_001A8CFC + 0x3C108;
            *(int *)(object + 0x34) = v;
            target = func_003435A8(a);
        }
        *(int *)(target + 0x58) = D_00239BA0[D_00139568[func_00343560((unsigned char *)D_001A8CFC + 0x3C108)]].f06;
    }
    return 0;
}
