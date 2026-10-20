#include "include_asm.h"

/* The X bias lives in small data, so this file is built with -G8. */
extern float ref_L00_0033A688_00 __attribute__((sda));
extern float D_001ADD0C;
extern void func_00335E38(char *, float, float, float, float);

/* Offsets the record position by the two resident biases and hands it to the
   shared spawn helper with no rotation. */
void func_0033A688(char *a0)
{
    if (*(int *)(a0 + 0x20C) != 0) {
        float *position = *(float **)(a0 + 0x1FC);

        func_00335E38(a0 + 0x170, position[0] + ref_L00_0033A688_00,
                      position[1] + D_001ADD0C, 0.0f, 0.0f);
    }
}

/* The table of four resident ints is reached through $gp and the resident
   pointer through the small-data unit, so this body needs -G8. */
extern char *D_001A8CFC[] __attribute__((sda));
extern char D_001ADC88[];
extern int D_001ADD30 __attribute__((sda));
extern void func_003361E0(char *, char *, int);
extern int *func_00335E20(char *);
extern void func_00336390(char *, char *, int);
extern void func_00335E68(char *, int);

#define FIELD(off) (*(int *)(obj + (off)))

void func_0033AA00(char *obj, int *arr, char *third)
{
    char *p = obj + 4;
    int *q = (int *)&D_001ADD30;
    int i;
    int n;
    int *out;
    int off;

    for (i = 3; i >= 0; i--) {
        if (*arr != 0) {
            func_003361E0(p, D_001ADC88, FIELD(0x200));
            *(int *)func_00335E20(p) = *q;
            func_00336390(p, D_001A8CFC[0] + 0x8710, *arr);
        } else {
            func_00336390(p, D_001A8CFC[0] + 0x8710, 0);
            func_00335E68(p, 0);
        }
        p += 76;
        q += 1;
        arr += 1;
    }
    FIELD(0x1F8) = 0;
    *(int *)obj = (int)third;
    n = 0;
    if (*(int *)(third + 4) != -1) {
        /* The named -1 makes the compiler keep the loop's comparison constant
           in the preheader, where the retail body has it. */
        int minus = -1;
        off = 0;
        out = (int *)(obj + 0x1B8);
        do {
            *out++ = 0;
            off += 0x18;
            FIELD(0x1F8) = FIELD(0x1F8) + 1;
            n++;
            if (*(int *)(off + (int)*(int *)obj + 4) == minus)
                break;
        } while (n < 16);
    }
}
