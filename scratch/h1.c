typedef struct {
    int entries[64];    /* +0x000 */
    int count;          /* +0x100 */
} Table_389848;

typedef struct {
    char pad[0xAA];
    short key;          /* +0xAA */
} Obj_389848;

extern Table_389848 ref_L13_00232450_00;

void func_L13_00389848(Obj_389848 *object)
{
    int found = 0;
    int i;

    for (i = 0; i < ref_L13_00232450_00.count; i++) {
        if (ref_L13_00232450_00.entries[i] == object->key) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        ref_L13_00232450_00.entries[ref_L13_00232450_00.count] = object->key;
        ++ref_L13_00232450_00.count;
    }
}
