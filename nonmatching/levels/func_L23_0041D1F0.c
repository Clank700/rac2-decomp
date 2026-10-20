/* func_L23_0041D1F0 (420 bytes, src/levels/23_damosel_orbit/L23_00416388.c, -g8 sibling): tools/check.py gives
   1 of 1, but only with one `*(volatile int *)` read of entry[8] in case 1: without it gcse (PRE) reuses the
   earlier load across the stores where retail reloads. Held back: a volatile used to force a reload is an
   artificial barrier (AGENTS.md). Retail's reload suggests the original could not prove that the stores to
   D_L23_001B3750 do not alias `entry`; a spelling where `entry` comes from somewhere opaque may give it. */

typedef short s16;


extern char D_00189E20[];

extern int D_L23_001B374C __attribute__((sda));

extern int D_L23_001B374C_2;

extern int D_L23_001B3750 __attribute__((sda));

extern int D_L23_001B3750_2;

extern int D_L23_001B3754;

extern int D_L23_001B14A4 __attribute__((sda));

extern char D_L23_001B1F90[];

/* Raises one of three level values by its step and clamps it to its limit. The entry word is
   read through a volatile access after the first store: the compiler otherwise reuses the earlier
   load of that word. */
int func_L23_0041D1F0(char *obj, int unused, int mode, int flag) {
    char *state = *(char **)(obj + 0x68);
    char *entry = D_L23_001B1F90 + flag * 16;
    int result = 0;

    switch (mode) {
    case 0:
        if (flag) {
            char *g = D_00189E20;

            if (*(int *)(g + 0x1874) < *(s16 *)(state + 0x2F4)) {
                *(int *)(g + 0x1874) = *(int *)(g + 0x1874) + *(s16 *)(state + 0x2F0);
                if (*(s16 *)(state + 0x2F4) < *(int *)(g + 0x1874))
                    *(int *)(g + 0x1874) = *(s16 *)(state + 0x2F4);
                result = 1;
                D_L23_001B374C = 0;
            }
        } else {
            float lim = (float)*(s16 *)(state + 0x24);

            if (*(float *)(state + 0x20) < lim) {
                *(float *)(state + 0x20) = *(float *)(state + 0x20) + (float)*(s16 *)(state + 0x2F2);
                if (lim < *(float *)(state + 0x20))
                    *(float *)(state + 0x20) = lim;
                result = 1;
            }
        }
        break;
    case 1:
        if (*(int *)(entry + 8) < *(s16 *)(state + 0x2FA)) {
            if (*(s16 *)(state + 0x2FA) < *(int *)(entry + 8) + *(s16 *)(state + 0x2F8))
                D_L23_001B3750 = *(s16 *)(state + 0x2FA) - *(int *)(entry + 8);
            else
                D_L23_001B3750_2 = *(s16 *)(state + 0x2F8);
            *(int *)(entry + 8) = *(volatile int *)(entry + 8) + *(s16 *)(state + 0x2F8);
            if (*(s16 *)(state + 0x2FA) < *(int *)(entry + 8))
                *(int *)(entry + 8) = *(s16 *)(state + 0x2FA);
            result = 1;
            if (flag)
                D_L23_001B374C = 1;
        }
        break;
    case 2:
        if (*(int *)(entry + 12) < *(s16 *)(state + 0x2FE)) {
            *(int *)(entry + 12) = *(int *)(entry + 12) + *(s16 *)(state + 0x2FC);
            if (*(s16 *)(state + 0x2FE) < *(int *)(entry + 12))
                *(int *)(entry + 12) = *(s16 *)(state + 0x2FE);
            result = 1;
            if (flag)
                D_L23_001B374C_2 = 2;
        }
        break;
    }
    if (result)
        D_L23_001B3754 = D_L23_001B14A4;
    return result;
}
