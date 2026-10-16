typedef int s32;

extern s32 D_L00_001BC200[];

int func_L00_002E36F8(s32 key)
{
    s32 *entry = (s32 *)D_L00_001BC200[3];
    int count = D_L00_001BC200[4];
    int i;

    for (i = 0; i < count; i++) {
        if (entry[1] == key)
            return entry[0];
        entry += 4;
    }
    return 0;
}
