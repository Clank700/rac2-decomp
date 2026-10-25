/* 0 of 1 places match - last line: 11_joba: 568 bytes, expected 560
   Walks the level object list from D_L11_001B35A8 and calls the handler its kind
   (+0xAA halfword) selects; 0xCC0..0xCC9 and 0xAE0..0xAE2 are the case ranges,
   and the kinds with one handler share a body: 0xA5C/0x1192 -> func_L02_003DED08,
   0xAE0..0xAE2 + 0xAEC + 0xB06 + 0xB09 + 0xCC0..0xCC9 + 0xCDB -> func_0029F338.
   The switch and every case body match instruction for instruction; the difference
   is the prologue: retail does not move the `%hi` of the data argument
   (D_L11_001A8F20) out of the loop, while this cc1 hoists it into $s2 (an extra
   `sd $s2`/`lui $s2` and a bigger frame), so the body is two instructions over retail.
   The same hoist appears with the constant in a case-local pointer; a dedicated
   loop-optimizer option or a source shape that keeps the address at the call is
   the next thing to try. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

extern char *D_L11_001B35A8;
extern char D_L11_001A8F20[];
extern void func_002A8F70(char *, char *, int, char *, float, void *);
extern void func_003320F0(char *);
extern void func_00333048(char *);
extern void func_L02_00414D48(char *);
extern void func_L02_003F0628(char *);
extern void func_L02_00392C70(char *);
extern void func_L02_003948D0(char *);
extern void func_L02_003AA650(char *);
extern void func_L02_003DED08(char *);
extern void func_L11_00458F58(char *);
extern void func_0029F338(char *);

/* Walks the level's object list and runs the handler its kind selects. */
void func_L11_00447360(char *a0)
{
    char *n = D_L11_001B35A8;

    while (n != 0) {
        switch (*(s16 *)(n + 0xAA)) {
        case 0xCB: {
            char *data = D_L11_001A8F20;

            func_002A8F70(n, a0, 0x10000, n + 0x10, 100.0f, data);
            break;
        }
        case 0xE7D:
            func_003320F0(n);
            break;
        case 0xEB0:
            func_00333048(n);
            break;
        case 0xCB2:
            func_L02_00414D48(n);
            break;
        case 0xB02:
            func_L02_003F0628(n);
            break;
        case 0x1366:
            func_L02_00392C70(n);
            break;
        case 0x1367:
            func_L02_003948D0(n);
            break;
        case 0x326:
            func_L02_003AA650(n);
            break;
        case 0xA5C:
        case 0x1192:
            func_L02_003DED08(n);
            break;
        case 0xE20:
            func_L11_00458F58(n);
            break;
        case 0xAE0 ... 0xAE2:
        case 0xAEC:
        case 0xB06:
        case 0xB09:
        case 0xCC0 ... 0xCC9:
        case 0xCDB:
            func_0029F338(n);
            break;
        }
        n = *(char **)(n + 0x28);
    }
}

