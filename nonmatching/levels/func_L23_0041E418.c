/* func_L23_0041E418 (level 23, 284 bytes) -- NEAR MISS, not integrated.
   state: 284 bytes against retail's 284 (71 instructions); check.py: 0 of 1 places match.
   everything through the call to func_002A77E0 matches: the 12-byte table copy from 0x1B17B0,
   the timing tests, the two conditional appends and the count == 0 return of -1.
   what still differs: the dispatch on the call's result. Retail tests the result against 1 first
   (`beq`), then `slti` against 2, then `bnez` for the zero case; this C emits the zero test first.
   measured without the case -1 arm: 280 or 272 bytes (case 0, case 1, default in the six orders), 268
   with an if-chain using `||` (the compiler folds the range test away), 288 with separate returns,
   292 with an explicit case 2. The case -1 arm (same value as the default) reaches 284 bytes but
   keeps the tree shape wrong at +0xE8.
*/

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern u8 *D_L23_001B1484 __attribute__((sda));

/* the three words at 0x1B17B0 are copied to the stack; the entries picked by the timing tests are chosen by a helper */
typedef struct {
    s32 v[3];
} L23Table3;

extern L23Table3 D_L23_001B17B0;

typedef struct {
    u8 pad[0x18];
    s32 f18;
    s32 f1C;
} L23Block1F90;

extern L23Block1F90 D_L23_001B1F90;

typedef struct {
    u8 pad[0x1874];
    s32 f1874;
} D00189E20_View;

extern D00189E20_View D_00189E20;

extern s32 func_002A77E0(s32);

s32 func_L23_0041E418(void) {
    u8 *obj = *(u8 **)(D_L23_001B1484 + 0x68);
    L23Table3 table = D_L23_001B17B0;
    s32 count = 0;

    if (D_00189E20.f1874 < *(s16 *)(obj + 0x2F4) - 5) {
        table.v[0] = 0;
        count = 1;
    }
    if (count == 0 || !(D_00189E20.f1874 < *(s16 *)(obj + 0x2F4) / 2)) {
        if (D_L23_001B1F90.f18 < *(s16 *)(obj + 0x2FA)) {
            table.v[count++] = 1;
        }
        if (D_L23_001B1F90.f1C < *(s16 *)(obj + 0x2FE)) {
            table.v[count++] = 2;
        }
    }
    if (count == 0) {
        return -1;
    }
    switch (func_002A77E0(count)) {
    case 1:
        return table.v[1];
    case 0:
        return table.v[0];
    case -1:
        return table.v[2];
    }
    return table.v[2];
}

