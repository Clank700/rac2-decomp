/* from src/game/003439A0.c: 252 bytes, retail's size (tools/check.py: 0 of 28 places).
   The first difference is at 0x3443D4 (+0x5C). This cc1 emits the shared zero return as its own copy
   at the end of the function, while retail has one `b` to the epilogue placed between the case 1 and
   case 3 bodies, so the case 3 branch lands two words short of retail's target. The case 1 flag test
   also loads its byte into $v1 (lbu $v1,6($v0)) where retail loads it into $v0 (lbu $v0,0x7AFE($v0)).
   Tried: zero arms as explicit returns or as ?: / if-else values with the default as `return 0` last
   (252 bytes, the form here), and `value = 0` as the default, or the default in the middle (256 bytes).
   Data: the 16-byte table at 0x1AE260 (a copy of boot data), D_00139568 (byte index table),
   D_001A7AF8 (flags), D_00239BA0 (224-byte entries; the field at +0x42 is read). Standalone. */

extern unsigned char D_00139568[];
extern unsigned char D_001A7AF8[];
extern unsigned char D_00239BA0[];
typedef struct { unsigned char pad[0x42]; short field42; unsigned char rest[0xE0 - 0x44]; } Entry224;

int func_00344378(char *p)
{
    int table[4] = { 0x30B2, 0x30B3, 0x30B4, 0x30B5 };
    int mode = *(int *)(p + 0x448);
    int value;

    switch (mode) {
    case 0:
    case 2: {
        int index = *(int *)(p + 0x444);
        if (D_001A7AF8[index] != 0)
            value = ((Entry224 *)D_00239BA0)[D_00139568[index]].field42;
        else
            value = 0;
        break;
    }
    case 1:
        if (D_001A7AF8[6] != 0)
            value = ((Entry224 *)D_00239BA0)[D_00139568[6]].field42;
        else
            value = 0;
        break;
    case 3:
        value = table[*(int *)(p + 0x444)];
        break;
    default:
        return 0;
    }
    return value;
}
