typedef int s32;
typedef unsigned char u8;

extern u8 *ref_L00_001B1AFC_00[];

void func_L00_003296C0(char *object, s32 index, u8 value)
{
    s32 offset;

    if (object == 0)
        return;
    offset = *(u8 *)(ref_L00_001B1AFC_00[index] + 4) * 8;
    *(char **)(ref_L00_001B1AFC_00[index] + offset) = object;
    *(u8 *)(ref_L00_001B1AFC_00[index] + offset + 5) = value;
    *(unsigned short *)(ref_L00_001B1AFC_00[index] + offset + 6) = 0;
    ++*(u8 *)(ref_L00_001B1AFC_00[index] + 4);
}
