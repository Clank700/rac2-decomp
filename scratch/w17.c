typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_L00_001A7908;
extern s32 D_L00_001B8E10;
extern s16 D_L00_00190086;
/* the one word retail reaches through $gp, and the same block addressed absolutely */
extern s32 D_L00_00189E20 __attribute__((sda));
extern u8 D_L00_00189E20_1[];

/* y1: gp word under the sda name, block read through a base local */
s32 y1(void) {
    u8 *blk = D_L00_00189E20_1;
    s32 v;

    if (D_L00_001A7908 == 0)
        return 0;
    v = D_L00_00189E20;
    if (v == 2)
        return 0;
    if (v == 6)
        return 0;
    if (D_L00_001B8E10 != 0 && D_L00_00190086 == 5)
        return 0;
    if (*(u8 *)(blk + 0x22B4) != 0)
        return 0;
    if (*(s32 *)(blk + 0x229C) == 0x14)
        return 0;
    if (*(s32 *)(blk + 0x24CC) == 0)
        return 0;
    v = *(s32 *)(blk + 0x2294);
    if (v == 0x6F || v == 0x31 || v == 0x1C || v == 0x8C)
        return 0;
    return 1;
}

/* y2: block fields addressed straight off the absolute name */
s32 y2(void) {
    s32 v;

    if (D_L00_001A7908 == 0)
        return 0;
    v = D_L00_00189E20;
    if (v == 2)
        return 0;
    if (v == 6)
        return 0;
    if (D_L00_001B8E10 != 0 && D_L00_00190086 == 5)
        return 0;
    if (*(u8 *)(D_L00_00189E20_1 + 0x22B4) != 0)
        return 0;
    if (*(s32 *)(D_L00_00189E20_1 + 0x229C) == 0x14)
        return 0;
    if (*(s32 *)(D_L00_00189E20_1 + 0x24CC) == 0)
        return 0;
    v = *(s32 *)(D_L00_00189E20_1 + 0x2294);
    if (v == 0x6F || v == 0x31 || v == 0x1C || v == 0x8C)
        return 0;
    return 1;
}

/* y3: the gp word read first, the block base taken from the sda name */
s32 y3(void) {
    u8 *blk = (u8 *)&D_L00_00189E20;
    s32 v;

    if (D_L00_001A7908 == 0)
        return 0;
    v = D_L00_00189E20;
    if (v == 2)
        return 0;
    if (v == 6)
        return 0;
    if (D_L00_001B8E10 != 0 && D_L00_00190086 == 5)
        return 0;
    if (*(u8 *)(blk + 0x22B4) != 0)
        return 0;
    if (*(s32 *)(blk + 0x229C) == 0x14)
        return 0;
    if (*(s32 *)(blk + 0x24CC) == 0)
        return 0;
    v = *(s32 *)(blk + 0x2294);
    if (v == 0x6F || v == 0x31 || v == 0x1C || v == 0x8C)
        return 0;
    return 1;
}
