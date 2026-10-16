typedef int s32;

typedef struct {
    s32 value;
    s32 key;
    char pad[8];
} E2e36f8;

extern s32 D_L00_001BC200[];

int func_L00_002E36F8(s32 key)
{
    int count = D_L00_001BC200[4];
    E2e36f8 *entry;
    int i;

    if (count > 0) {
        i = 0;
        entry = (E2e36f8 *)D_L00_001BC200[3];
        do {
            if (entry->key == key)
                return entry->value;
            entry++;
            i++;
        } while (i < count);
    }
    return 0;
}
