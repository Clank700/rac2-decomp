/* Mid worker 11 near miss (func_003472B8).
   Profile: -O2 -G0 -ffunction-sections.
   Status: same 428 bytes and instruction forms; only register numbering differs (float zero/accumulator f20/f21, table and flag base temporaries). */
#include "common.h"

#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    u8 pad[6];
    s16 index;
    u8 pad8[2];
} MenuEntry;

extern MenuEntry D_00282998[];
extern u8 D_001A7AF8[];
extern u8 D_001A7A80[];
extern Pair ref_003472B8_00;

extern void func_00335E68(char *, int);
extern float *func_00335E10(char *);
extern void func_00335E38(char *, float, float, float, float);

void func_003472B8(char *obj) {
    Pair pad;
    MenuEntry *entry = &D_00282998[FLD(obj, int, 0x4FC) + (FLD(obj, int, 0x500) << 2)];
    int index = entry->index;
    int bits;
    u8 *flags;
    char *a;
    char *b;
    float x;
    float y;

    if (D_001A7AF8[index] == 0) {
        return;
    }
    a = obj + 0x2E8;
    flags = &D_001A7A80[index];
    pad = ref_003472B8_00;
    b = obj + 0x330;
    bits = flags[0] & 4;
    func_00335E68(a, (flags[0] & 1) | (bits != 0));
    bits = flags[0] & 0x10;
    func_00335E68(b, bits != 0);
    x = FLD(obj, float *, 0x498)[0] + func_00335E10(a)[0] + (float)pad.x;
    y = FLD(obj, float *, 0x498)[1] + func_00335E10(a)[1] + (float)pad.y;
    func_00335E38(a, x, y, 0.0f, 0.0f);
    x = FLD(obj, float *, 0x498)[0] + func_00335E10(b)[0] + (float)pad.x;
    y = FLD(obj, float *, 0x498)[1] + func_00335E10(b)[1] + (float)pad.y;
    func_00335E38(b, x, y, 0.0f, 0.0f);
}
