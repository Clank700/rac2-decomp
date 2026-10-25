/* Near miss: builds the cheat menu entries at D_0025FC90 from the two tables.
 *
 * wslcmp (boot): 0 of 28 places; 316 bytes against 316, first difference at +0xA0
 * (`%hi at +0xa0 differs`). Everything matches except the two address
 * materialisations in the loop preheader and one byte load:
 *   retail  lui t5,%hi ; addiu t5,t5,%lo     (one register, %hi/%lo folded)
 *           lui t4,%hi ; addiu t4,t4,%lo
 *   here    lui v0,%hi ; lui v1,%hi ; addiu t5,v0,%lo ; addiu t4,v1,%lo
 * i.e. the same cc1 "address destination is its own temporary" wall recorded for
 * func_L05_004155A0. The 60-byte copy is two struct assignments (8 ints from
 * D_001AB938, 7 ints from D_001AB958); the sentinel loop bound of 12 with
 * -1 termination, the 20-byte record layout, the 0x2DC6/0x2DC7 words and the
 * terminator store all agree. Local pointer variants for the two bases measured
 * worse (340 bytes and a different allocation).
 */
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
