/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 452/444 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: The three old overlapping TI declarations are replaced by incomplete float
 * views. Consumer 0032A258 reads at least 8 bytes at A0/A8 and 28 at B0; those
 * minima do not prove whole external extents, so no small fake object is used
 * to force SDA. Real constructor pointer returns and single-argument destroy
 * are preserved. The local vector is complete; the 0x50 frame agrees, but
 * absolute-vs-GP address setup and mode/vector scheduling still differ.
 * Reopen with: Independent complete range-object extents and SDA storage evidence,
 * then revisit the source mode/local lifetime. Do not shrink a wide extern.
 */

#include "common.h"

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

/* The consumer reads at least 8, 8 and 28 bytes respectively; whole
 * external extents remain unknown, so these views stay incomplete. */
extern float D_L20_001B23A0[];

extern float D_L20_001B23A8[];

extern float D_L20_001B23B0[];

extern void func_L00_0033E220(void *, void *, int, int, int, int, int, int, float, float);

extern void func_002A7750(char *, int, int);

extern void *func_002A9640(void *, u32, s32);

extern void func_L00_0032A258(char *, void *, void *, void *, int, int, int, int, int, int, int);

extern void func_L01_0031A278(void *, void *, float, float, float);

extern void func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, int);

extern char *func_L00_00326620(char *, int, int);

extern void func_0029F338(void *);

void func_L20_00449178(char *arg0) {
    char *self = arg0;
    char *state = *(char **)(self + 0x68);
    int mode = *(u8 *)(self + 0x20);
    union { TI128 q; float f[4]; } v;

    switch (mode) {
    case 0: goto L491CC;
    case 1: goto L49230;
    case 2: goto L49270;
    default: return;
    }
L491CC:
    v.q = 0;
    v.f[2] = 2.0f;
    func_L00_0033E220(&v, self, 0x40204080, -1, 1, -1, 0, -1, 420000.0f, 1.0f);
    func_002A7750(self, 1, -1);
    return;
L492BC:
    if (mode == 2) {
        goto L49270;
    }
    return;
L49230:
    if (func_002A9640(self, 0x4010000, 0) != 0) {
        if (*(u32 *)state == 0) {
            func_002A7750(self, 2, -1);
        }
    }
    *(u8 *)(self + 0xA8) = 0xFF;
    return;
L49270:
    func_L00_0032A258(self, &D_L20_001B23B0, &D_L20_001B23A8, &D_L20_001B23A0,
                      0xFFFF, 0, -1, 0, 0xFFFF, mode, 0);
    func_L01_0031A278(self, &v, 0.0f, 0.0f, 2.0f);
    func_0032C700(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.5f, 20.0f, 1, 1, 0, 0);
    func_L00_00326620(self, 0x126A, 0);
    func_0029F338(self);
    return;
}
