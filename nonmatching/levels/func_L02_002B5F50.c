/* Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 388 bytes; compiled: 392 bytes.
 * Final coverage: us: 0/9; us2: 0/9; pal: 0/9.
 * Residual: 392/388 bytes. Retail chronology, four-slot path calls and stored V0 results
 * are repaired. Distinct phase references recover the resident high-half/base lifetime.
 * Actor/copy pointer allocation, byte-index temporary and final branch-likely schedule
 * still differ.
 * Reopen: A measured actor-prefix/call-lifetime witness preserving the qualified
 * zero-input setup callees and full four-slot path contract; do not restore the earlier
 * false FP input or byte-as-result stores.

 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_0029F338(void *a0);
extern void func_L00_002A53B8(void);
extern void func_0028B3D0(int a0, int a1, void *a2, void *a3, void *a4, int a5, int a6);
extern int func_L00_002F6B90(u32 a0);
extern void func_L00_002A6708(void);
extern void func_L00_002D24B8(void);
extern int func_L00_002A4DB0(char *object, int index, int route, char *table);
extern void func_L00_002C42E0(int a0, int a1);
extern char D_L02_001B5B40[];
extern char D_L02_001B6140[];
extern int D_L02_001A8F00;
extern char D_L02_002FB7D0[];
extern char D_L02_002FB820[];
extern char D_L02_002FC0F0[];

/* The resident state of the game, at 0x199E20. */
typedef struct {
    char pad00[0x0C14];
    void *f_0C14;
    void *f_0C18;
    char pad0C1C[0x0C24 - 0x0C1C];
    float f_0C24;
    char pad0C28[0x1860 - 0x0C28];
    void *f_1860;
    void *f_1864;
    char pad1868[0x2290 - 0x1868];
    void *f_2290;
    int f_2294;
    char pad2298[0x22B4 - 0x2298];
    unsigned char f_22B4;
    char pad22B5[0x24CC - 0x22B5];
    int f_24CC;
    int f_24D0;
    short f_24D4;
} ResidentStatePrefix;

extern unsigned char D_00199E20[];

void func_L02_002B5F50(void) {
    ResidentStatePrefix *g;
    unsigned char *p;
    unsigned char v;
    int result;

    if (((ResidentStatePrefix *)D_00199E20)->f_22B4 == 1) {
        ((ResidentStatePrefix *)D_00199E20)->f_24D0 = ((ResidentStatePrefix *)D_00199E20)->f_24CC;
        ((ResidentStatePrefix *)D_00199E20)->f_24CC = ((ResidentStatePrefix *)D_00199E20)->f_24D4;
        if (((ResidentStatePrefix *)D_00199E20)->f_1860 != 0) {
            func_0029F338(((ResidentStatePrefix *)D_00199E20)->f_1860);
            ((ResidentStatePrefix *)D_00199E20)->f_1860 = 0;
        }
        if (((ResidentStatePrefix *)D_00199E20)->f_1864 != 0) {
            func_0029F338(((ResidentStatePrefix *)D_00199E20)->f_1864);
            ((ResidentStatePrefix *)D_00199E20)->f_1864 = 0;
        }
    }
    func_L00_002A53B8();
    g = (ResidentStatePrefix *)D_00199E20;
    g->f_22B4 = 0;
    func_0028B3D0(0x23, 0, D_L02_002FB7D0, D_L02_002FB820, D_L02_002FC0F0, 0, 0);
    func_L00_002F6B90(3);
    if (g->f_0C14 != 0)
        *(unsigned short *)((char *)g->f_0C14 + 0x34) &= 0xFFF9;
    g->f_0C14 = 0;
    func_L00_002A6708();
    p = (unsigned char *)g->f_0C18;
    g->f_2290 = p;
    qcopy(p + 0x10, (char *)g + 0x80);
    *(int *)(p + 0x9C) = 0;
    g->f_0C24 = 1.0f;
    func_L00_002D24B8();
    p = (unsigned char *)g->f_2290;
    v = p[0x42];
    if (v != 0xFF) {
        result = func_L00_002A4DB0((char *)p, v, p[0x40], D_L02_001B5B40);
        *(int *)((char *)g->f_2290 + 0x58) = result;
    }
    p = (unsigned char *)g->f_2290;
    v = p[0x43];
    result = func_L00_002A4DB0((char *)p, v, p[0x41], D_L02_001B6140);
    *(int *)((char *)g->f_2290 + 0x5C) = result;
    if (g->f_2294 != 0x61 || (D_L02_001A8F00 != 2 && D_L02_001A8F00 != 6))
        func_L00_002C42E0(0, 1);
}
