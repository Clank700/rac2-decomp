/* func_00325DA0 (284 bytes, 7 places) - M27 near miss: 276/284 B, -G8 unit (00325DA0-g8.c).
 *
 * The goto loop (jump to the test, no loop.c hoisting) gives retail's shape: the byte
 * offset computed before the loop with the sra/sll inside it, the moby base and the
 * D_001EE5A0 row re-read each pass, the $gp read of D_001B1B78. Two words are missing:
 * retail copies the slot argument to $a2 at entry (D_001B1688 is read into $a1) and
 * tests the group through `andi $v1,$a3,0xFF`, where $a3 is the group byte loaded at
 * the end of each pass (a PRE copy). A u8/int group local makes it worse (272 B).
 */
#include "common.h"

typedef struct Moby_325DA0 {
    u8 pad00[0x21];
    u8 group;
    u8 pad22[0x68 - 0x22];
    s32 *pvar;
    u8 pad6C[0xAA - 0x6C];
    s16 team;
    u8 padAC[0x100 - 0xAC];
} Moby_325DA0;

extern s32 D_001B1688[] __attribute__((sda));
extern Moby_325DA0 *D_001B1B5C[] __attribute__((sda));
extern s32 D_001B1B78;
extern u16 *D_001EE5A0[];
extern void func_0027CFD0(void (*)(Moby_325DA0 *), Moby_325DA0 *);
extern void func_00325EC0(Moby_325DA0 *);

/* Clear one pvar slot in every moby of the same group and team, then queue the follow-up. */
void func_00325DA0(Moby_325DA0 *m, s32 *slot)
{
    u16 *list;
    Moby_325DA0 *o;
    s32 off;

    if (*slot == D_001B1688[0]) return;
    if (m->group == 0xFF) {
        *slot = D_001B1688[0];
    } else {
        off = (char *)slot - (char *)m->pvar;
        list = D_001EE5A0[m->group];
        goto test;
    body:
        o = &D_001B1B5C[0][*list & 0x7FFF];
        if (o == 0) goto done;
        if (o->team == m->team) o->pvar[off >> 2] = D_001B1688[0];
        list++;
    test:
        if (m->group != 0xFF && m->group <= D_001B1B78 && list != 0
            && ((s16)list[-1] >= 0 || list == D_001EE5A0[m->group])) goto body;
    }
done:
    func_0027CFD0(func_00325EC0, m);
}
