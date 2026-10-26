/* Retained complete C; not linked or counted. Updated25 October2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * 292/292 bytes with the actual five GPRs plus F12 forwarded through the
 * wrapper to its deep consumer. Direction is passed in T0, end is genuinely
 * reloaded after the call, and the record table contains pointers. AAA00 has
 * its real ignored float return.
 * Frame0x30 agrees but first mismatch+0x4 remains allocation of
 * frame/object/index/sentinel registers. The real pointer-table spelling and
 * bank-order control tied. The canonical wrapper forwarding repair is
 * independently object-neutral; native interfaces must remain consistent.
 */

#include "include_asm.h"

typedef unsigned int u32;

extern char *D_L09_001FE6C0[];

extern int func_L09_0033E8B0(char *object, int index, void *out, int current, int direction, float step);

extern int func_L09_0033E658(int index);

extern float func_00283248(float x, float y);

extern float func_002AAA00(char *a, char *b, int c, float d, float e, float f, float g);

/* Steps the run's frame to the next entry of the level's table and hands the
   distance from the object to that entry's point to the stage. */
int func_L09_003F7B28(char *object, int index)
{
    char *frame = *(char **)(object + 0x68);
    short cur = *(short *)(frame + 0x1C8);
    short end = *(short *)(frame + 0x1CA);
    int ret = 1;
    int dir = -1;
    int step = -1;
    int next;
    short idx;
    int r;
    float dist;

    dir = (cur < end) ? ret : dir;
    next = func_L09_0033E8B0(object, index, object + 0x10, cur, dir,
                               *(float *)(frame + 0x128));
    idx = (short)next;
    *(short *)(frame + 0x1C8) = next;
    if (idx != step) {
        if (idx != *(short *)(frame + 0x1CA))
            ret = 0;
    }
    step = idx + 1;
    r = func_L09_0033E658(index);
    if (r < step) {
        float *rec = (float *)(D_L09_001FE6C0[index] + step * 16);

        dist = func_00283248(rec[4] - *(float *)(object + 0x10),
                             rec[5] - *(float *)(object + 0x14));
    } else {
        dist = func_00283248(*(float *)(frame + 0x1F0) - *(float *)(object + 0x10),
                             *(float *)(frame + 0x1F4) - *(float *)(object + 0x14));
    }
    func_002AAA00(object + 0xF8, frame + 0x1B4, 0, dist,
                  *(float *)(frame + 0x114), *(float *)(frame + 0x118),
                  *(float *)(frame + 0x11C));
    return ret;
}
