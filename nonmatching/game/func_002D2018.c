/*
 * Near miss (M19, 2026-10-26): 364/364 bytes, 4 differing instructions, tail scheduling only.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections (as its matched sibling 002D01D0-g32.c). us: 0/28.
 * Residual: retail builds the %hi of D_0025CB50 before the text table address; no statement
 * order moves it. Queued on the permuter.
 */
typedef struct { char prefix[0x14]; char *source; int value; char gap[0x118]; int fallback; } SelectionCallback;
typedef struct { char reserved[0x1C4]; int flags; } CallbackMenuState;
typedef struct { char reserved00[0x34]; int text; int f38; int timer; } MenuPanel;
typedef struct { short text; short pad; } MenuText;

extern SelectionCallback D_001F2840;
extern CallbackMenuState D_00138180;
extern int func_002E5E58(int, unsigned int, void *);
extern int D_001ABA60 __attribute__((sda));
extern MenuPanel D_0025CAA0[];
extern int D_0025CB50[];
extern MenuText D_001ABD6A[];

int func_002D2018(void)
{
    int result = 0;
    int flags = ((CallbackMenuState *)&D_00138180)->flags;
    int old = D_001ABA60;

    if (flags & 0x10) {
        int value;
        int status;
        D_001ABA60 = 0;
        value = *(int *)(D_001F2840.source + 0xE0);
        if (value != 0)
            D_001F2840.value = value;
        else if (D_001F2840.fallback == 0) {
            status = -1;
            goto finish;
        }
        status = 0;
finish:
        return status;
    }
    if (flags & 0x900) {
        D_001ABA60 = 0;
        result = 1;
    } else if (flags & 0x8000) {
        if (old > 0)
            func_002E5E58(3, 0, 0);
        else
            func_002E5E58(5, 0, 0);
        if (--D_001ABA60 < 0)
            D_001ABA60 = 0;
    } else if (flags & 0x2000) {
        if (old < 5)
            func_002E5E58(3, 0, 0);
        else
            func_002E5E58(5, 0, 0);
        if (++D_001ABA60 > 5)
            D_001ABA60 = 5;
    }
    if (old != D_001ABA60)
        D_0025CAA0[0].timer = -300;
    D_0025CB50[0] = D_001ABA60;
    D_0025CAA0[0].text = D_001ABD6A[D_001ABA60].text;
    return result;
}
