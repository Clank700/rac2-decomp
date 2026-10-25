/* Near miss: 444 bytes, expected 444, 0 of 28 places (USA v1.01 boot).
 *
 * Profile: -O2 -G8 -ffunction-sections (D_L15-style small data: the block
 * source is reached through $gp).
 * Last verdict: `python scratch/wslcmp.py src/game/002E7018-g8.c func_002ED0A0`
 *   func_002ED0A0: 0 of 28 places match   [boot: instruction at +0x4 differs]
 *
 * Remaining difference: retail keeps the state block's high half in $s6 and
 * re-derives the block address after the calls; this cc1 materialises the full
 * address once and spends one extra saved register.  The 0xD54 search, the
 * four-iteration colour loop and the final record store are identical.
 */
extern char D_001B8840[];
extern void func_00282CC0(unsigned char *, unsigned char *, unsigned char *);
/* Sets up the four fading quads of one record in the resident state block:
   picks the 0xD54 record, rebuilds its 0x10-byte blocks through the colour
   helpers and stores the record's first word into the state's draw object. */
extern int D_001AC200 __attribute__((sda));
extern char D_002628D0[];
extern char D_002628F0[];
extern char D_001B5340[];

extern void func_00283098(char *, char *, char *);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282F20(char *, char *, float);

void func_002ED0A0(void)
{
    char *record = 0;
    int index = -1;
    int flag = 0;
    int limit = 0x270F;
    int i;

    if (*(int *)(D_001B8840 + 0x30) == 0) {
        index = 0x32;
        flag = 1;
    }
    if (index == -1)
        return;
    if (*(int *)(D_001B8840 + 0x34) < index)
        return;
    if (limit < *(int *)(D_001B8840 + 0x34))
        return;
    *(int *)(D_001B8840 + 0x50) = (int)D_002628D0;
    for (i = 0; i < *(short *)(D_001B8840 + 0x44); i++) {
        char *entry = *(char **)(D_001B8840 + 0x18C + i * 4);

        if (*(short *)(entry + 0xAA) == 0xD54) {
            record = entry;
            break;
        }
    }
    if (record != 0) {
        char *base = D_002628F0;
        char *src = (char *)&D_001AC200;
        char *dst = record + 0x10;
        int n = 3;
        char buf[16];

        do {
            func_00283098(base, src, record + 0xC0);
            src += 0x10;
            n--;
            func_00282CC0((unsigned char *)base, (unsigned char *)base, (unsigned char *)dst);
            func_00282CF0(buf, D_001B5340, base);
            func_00282F20(buf, buf, 0.15f);
            func_00282CC0((unsigned char *)base, (unsigned char *)base, (unsigned char *)buf);
            base += 0x10;
        } while (n >= 0);
    }
    *(int *)(*(char **)(D_001B8840 + 0x50) + 0x68) = *(int *)(D_001B8840 + 0x18C + flag * 4);
}
