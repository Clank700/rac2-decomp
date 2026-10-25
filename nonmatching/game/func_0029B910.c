/* Near miss, not linked. Boot function func_0029B910 (328 bytes, 28 places),
   profile -O2 -G8 -ffunction-sections (sibling 0029AE78-g8.c).

   Last verdict: `python scratch\wslcmp.py src/game/0029AE78-g8.c func_0029B910 full`
   -> 272 bytes, expected 328; 0 of 28 places match.

   The control flow and the record/list addresses are understood: the four mission slot
   ids are at 0x1A9AC8, the 0x28-byte record table starts at 0x262940 (state +0x18,
   count s16 +0x1C, level u16 +0x20, unlocked word +0x24) and the 0x18-byte list entries
   start at 0x256418. Retail writes the entry's `second` through a base at 0x25641C plus a
   byte-offset induction variable and the colour/id through a second pointer induction
   variable at 0x256420, and it keeps the record base 0x262940 in one register while the
   level/flag field addresses are folded to 0x262960/0x262964 inside the loop. A single
   struct-array expression (below) makes the compiler use one output pointer and the
   record base with displacements, so the two output induction variables and the folded
   field bases are the remaining difference; the loop body, the if/else mode selection
   (0 when the slot is live, 2 when it is not) and the 0x6029A1FF/0x60F0F0B0 colours are
   otherwise right. */

extern char *D_001A8CFC[] __attribute__((sda));
extern int D_001A9AC8[2] __attribute__((sda));
extern int func_002ED8A0(int);

typedef struct {
    unsigned short id;           /* +0x00 */
    short pad02;
    int next;                    /* +0x04 */
    int pad08[4];
    int state;                   /* +0x18 */
    short count;                 /* +0x1C */
    short pad1E;
    unsigned short level;        /* +0x20 */
    short pad22;
    int flag;                    /* +0x24 */
} MissionRec;

typedef struct {
    int first;                   /* +0x00 */
    int second;                  /* +0x04 */
    int color;                   /* +0x08 */
    float angle;                 /* +0x0C */
    short id;                    /* +0x10 */
    short pad12;
    int text;                    /* +0x14 */
} ListEntry;

extern MissionRec D_00262940[];
extern ListEntry D_00256418[];
extern void func_0033A9D0(char *, int, int);

void func_0029B910(void) {
    int i;
    if (D_001A8CFC[0] != 0) {
        for (i = 0; i < 4; i++) {
            int idx = func_002ED8A0(D_001A9AC8[i]);
            if (idx >= 0) {
                MissionRec *rec = &D_00262940[idx];
                D_00256418[i].second = rec->count;
                D_00256418[i].color = rec->flag >= 1 ? 0x6029A1FF : 0x60F0F0B0;
                D_00256418[i].id = rec->level;
                func_0033A9D0(D_001A8CFC[0] + 0x3F138, i, 0);
            } else {
                func_0033A9D0(D_001A8CFC[0] + 0x3F138, i, 2);
            }
        }
    }
}
