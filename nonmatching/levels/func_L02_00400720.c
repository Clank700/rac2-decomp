/* func_L02_00400720 (548 bytes, 1 place: 02:00400720) -- NEAR MISS, not integrated (21 October 2026).
   The C below is exact (tools/check.py 1 of 1) in L02_003F5430-g8.c (`-O2 -G8 -ffunction-sections
   -frac2-gcse-unsplit-edges -frac2-keep-block-order`), but only through a statement with no effect:
   `lp = list;` again before the second loop, where `lp` already equals `list`. That second definition
   keeps gcse from propagating `lp` into `list`, so the stores through `lp` may alias the two globals
   and their loads stay below the loop, as in retail; without it gcse hoists the loads of D_001A7A00
   and D_L02_001B152C above the loop. A no-op that only steers the compiler is not a remedy under
   AGENTS.md, so it is held back. Needed: a natural spelling of the second loop's stores that keeps
   them as possible aliases (a pointer that walks the list, a helper, or the original's macro).
   Everything else is measured: the two thresholds are `const` (they are never written in level 2,
   and retail reads them ahead of the stores to the state); the hero block's address and the ids
   23/24 each have a variable of their own, as retail rebuilds the address from its high half and
   loads each id next to its store. */

extern const float D_L02_001B1520 __attribute__((sda));
extern const s32 D_L02_001B1524 __attribute__((sda));
extern float D_L02_001B1528 __attribute__((sda));
extern float D_L02_001B152C __attribute__((sda));
extern s32 D_L02_001B1530 __attribute__((sda));
extern s32 D_001A7A00;
extern char D_001A63A8[];
extern s32 func_00282948(void *);

/* Picks an idle message for the object. Nothing happens while the message system at D_001A63A8
   is busy (+0x68 set, +0x24 not -1) or while the countdown at +0xE4 of the state runs. A float
   (+0xE8, plus a2) and a count (+0xEC, plus a1) accumulate; when the float passes D_L02_001B1520
   or the count D_L02_001B1524, the messages 0x1D..0x22 not played yet (the half-words at
   +0x1D0 + id * 2; 0x1D only while +0xD0 is zero) become candidates and both restart. When
   func_00282948 reports the timer at +0x100 idle, both restart and the timer is set to 300. The
   messages 0x1A..0x1C join when a3 is above D_L02_001B1528, 0x23 when the hero block's int at
   +0x24CC is under D_001A7A00 * D_L02_001B152C and 0x24 when it is not positive. One candidate,
   picked at random, is started through func_L02_00400650 and the countdown is set to
   D_L02_001B1530 plus a random share of it.

   Spelling measured against retail: the two thresholds are const (retail reads them ahead of
   the stores to the state); lp is a second name for the list, set twice, so that gcse treats
   the stores through it as possibly aliasing and leaves the loads of D_001A7A00 and
   D_L02_001B152C below the second loop (they are hoisted above it otherwise); the hero block's
   address and the two ids each have a variable of their own, as retail rebuilds the address
   from its high half and loads each id next to its store. */
void func_L02_00400720(char *a0, s32 a1, float a2, float a3) {
    char *state = *(char **)(a0 + 0x68);
    char *g = D_001A63A8;
    char *hero;
    char *hero2;
    s32 id23;
    s32 id24;
    s32 list[12];
    s32 n;
    s32 j;
    s32 k;
    s32 count;
    float acc;
    s32 *lp = list;

    if (*(s32 *)(g + 0x68) != 0)
        return;
    if (*(s32 *)(g + 0x24) != -1)
        return;
    if (*(s32 *)(state + 0xE4) != 0)
        return;
    n = 0;
    acc = *(float *)(state + 0xE8) + a2;
    count = *(s32 *)(state + 0xEC) + a1;
    *(s32 *)(state + 0xEC) = count;
    *(float *)(state + 0xE8) = acc;
    if (D_L02_001B1520 < acc || D_L02_001B1524 < count) {
        for (j = 0; j < 6; j++) {
            s32 id;

            if (j == 0 && *(s32 *)(state + 0xD0) != 0)
                continue;
            id = j + 0x1D;
            if (*(s16 *)(state + 0x1D0 + id * 2) == 0)
                list[n++] = id;
        }
        *(s32 *)(state + 0xEC) = 0;
        *(s32 *)(state + 0xE8) = 0;
    }
    if (func_00282948(state + 0x100) != 0) {
        *(s32 *)(state + 0xEC) = 0;
        *(s32 *)(state + 0x100) = 300;
        *(s32 *)(state + 0xE8) = 0;
    }
    if (D_L02_001B1528 < a3) {
        lp = list;
        for (k = 0; k < 3; k++) {
            s32 id = k + 0x1A;

            if (*(s16 *)(state + 0x1D0 + id * 2) == 0)
                lp[n++] = id;
        }
    }
    hero = (char *)&D_00189E20;
    if ((float)*(s32 *)(hero + 0x24CC) < (float)D_001A7A00 * D_L02_001B152C) {
        id23 = 0x23;
        if (*(s16 *)(state + 0x216) == 0)
            list[n++] = id23;
    }
    hero2 = (char *)&D_00189E20;
    if (*(s32 *)(hero2 + 0x24CC) <= 0) {
        id24 = 0x24;
        if (*(s16 *)(state + 0x218) == 0)
            list[n++] = id24;
    }
    if (n != 0) {
        func_L02_00400650(a0, list[func_002A77E0(n)]);
        *(s32 *)(state + 0xE4) = D_L02_001B1530 + func_002A77E0(D_L02_001B1530);
    }
}
