/* Retained complete C repair, 2026-10-25; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Private placement checks: us: 0/28, us2: absent, pal: absent.
 * The source includes its actual s32 typedef context. Both aggregate copies
 * remain eight ID words plus seven string words. The qualified US table has
 * its first ID sentinel at index 7, so this sentinel loop stays within both
 * copied objects.
 * Current code is 316/316 bytes; the first preheader high-address relocation
 * differs at +0xA0. Runtime changes to the supplied sentinel table and native
 * behavior are unqualified.
 */

#include "common.h"

typedef struct {
    s32 v[8];
} IdTable_1AB938;

typedef struct {
    s32 v[7];
} StringTable_1AB958;

typedef struct {
    int value;
    int id;
    int a;
    int b;
    int c;
} CheatEntry_25FC90;

extern IdTable_1AB938 D_001AB938;
extern StringTable_1AB958 D_001AB958;
extern char D_001A7A40[];
extern unsigned char D_001A7A50[];
extern CheatEntry_25FC90 D_0025FC90[];

int func_002CC550(void)
{
    IdTable_1AB938 ids = D_001AB938;
    StringTable_1AB958 strings = D_001AB958;
    int count = 0;
    int i;

    for (i = 0; i < 12; i++) {
        if (ids.v[i] == -1)
            break;
        if (D_001A7A50[ids.v[i]] != 0) {
            D_0025FC90[count].value = strings.v[i];
            D_0025FC90[count].id = (int)(D_001A7A40 + ids.v[i]);
            D_0025FC90[count].a = 0x2DC6;
            D_0025FC90[count].b = 0x2DC7;
            D_0025FC90[count].c = 0;
            count++;
        }
    }
    D_0025FC90[count].value = 0;
    return 0;
}
