#include "include_asm.h"

/* The three resident copy helpers in this unit need the grouped `lq`/`sq`
   profile with its scheduler barrier (-frac2-qcopy -frac2-qcopy-barrier). */

typedef int TI128 __attribute__((mode(TI)));

extern char D_001B5490[];
extern char D_001B5570[];
extern int func_00271130(void *, void *);
extern int func_002712D8(void *, void *);

/* Runs the current object through the resident visibility test, then copies
   its four 16-byte blocks into the resident snapshots and clears the test
   state. */


/* Copies the resident object's saved vectors back into its working ones. */


extern char D_00189F70[];
extern void func_00282CC0(char *first, char *second, char *third);

/* Copies the resident object's two vectors and asks the engine to rebuild its
   matrix when the object's type says so. */
void func_00270E30(void)
{
    unsigned char *object = (unsigned char *)D_001B5490;

    if (object[2] == 0) {
        *(TI128 *)(object + 0xC0) = *(TI128 *)(object + 0x50);
        if (object[3] == 2)
            func_00282CC0((char *)(object + 0xC0), D_00189F70, (char *)(object + 0xC0));
        *(TI128 *)(object + 0xD0) = *(TI128 *)(object + 0x60);
    }
}
