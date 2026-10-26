/* func_00288F48 (108 bytes, 28 places), closer M2: 104 bytes under -O2 -G0, no volatile.
 * Retail re-reads the count and rebuilds its address on every pass, which a goto loop
 * gives (loop.c never sees it, so nothing is hoisted); the table pointer is an sda word
 * read with the lw macro. Left: retail copies the loaded pointer into a second register
 * for the loop (daddu $a3,$v1 in the first bne's slot) where this cc1 loads it straight
 * into the loop register, and reorg then fills that slot from the loop head instead
 * (one instruction, 4 bytes). The ref_ names follow the boot form ref_00288F48_kk. */
typedef struct { int unk00; int key; int unk08; int unk0C; } SelectorEntry;

typedef struct { char pad00[0x2C]; int count; } SelectorCount;

extern SelectorCount ref_00288F48_00;
extern SelectorEntry *ref_00288F48_01 __attribute__((sda));

int func_00288F48(int key)
{
    int found = -1;
    int i = 0;
    SelectorEntry *table;

    if (ref_00288F48_00.count > 0) {
        table = ref_00288F48_01;
        if (table[0].key == key) {
            found = 0;
        } else {
        next:
            i++;
            if (i < ref_00288F48_00.count) {
                if (table[i].key != key)
                    goto next;
                found = i;
            }
        }
    }
    return found;
}
