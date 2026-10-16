typedef int s32;

typedef struct {
    s32 value;
    s32 key;
    char pad[8];
} E2e36f8;

extern s32 D_L00_001BC200[];

int func_L00_002E36F8(s32 key)
{
    E2e36f8 *entry = (E2e36f8 *)D_L00_001BC200[3];
    int count = D_L00_001BC200[4];
    int i;

    for (i = 0; i < count; i++) {
        if (entry[i].key == key)
            return entry[i].value;
    }
    return 0;
}
