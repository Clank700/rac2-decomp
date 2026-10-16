typedef int s32;
typedef unsigned char u8;

extern u8 D_L00_00268E20[];

u8 *func_L00_0032A0B8(s32 a0, s32 a1)
{
    s32 idx = a1 * 0xA430;
    s32 *e = (s32 *)(D_L00_00268E20 + idx);

    if (e[1] != a0) {
        return 0;
    }
    return D_L00_00268E20 + 8 + idx;
}
