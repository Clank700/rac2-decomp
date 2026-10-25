/* Near miss, 2026-10-25 wave 10: 536 bytes expected, 540 produced, 0 of 1
   place (15_gorn @0x00436990).  One redundant instruction, at +0x5C: this C
   emits `daddu $a0,$s0,$zero` before the func_380080 call while retail calls it
   with the incoming $a0 (which still holds the object).  Every other word,
   including the whole class-1 table walk and the delay-slot layout of the
   state-3 / state-2 branches, is byte-identical, so removing that one copy
   matches.
   Tried: parameter named s0 directly; a local `char *s0 = a0` with the call on
   `a0`; the 0xFF store through `a0` instead of `s0`; the call result in a local
   `int v`.  All give 540 and the same redundant copy.  Next hypothesis: the
   original passes the *parameter* to the first call while the 0xFF store is
   what forces the saved register, i.e. two source names for the same pointer;
   or the store is a field of a differently-typed object so that the parameter
   pseudo is not live across the call.  This is an allocator tie, not a
   control-flow difference. */

extern int func_380080(char *);
extern void func_3806A8(char *, void *, int, int);
extern void func_35A218(char *, int, int, int, float, int);
extern void *func_3804E8(char *);
extern int func_383E28(char *);
extern void func_383C48(char *, char *);
extern void func_383700(char *, int);
extern void func_382AE0(char *);
extern void func_381EB8(char *, int, int, int);
extern int func_307D78(float);
extern int func_3068A0(int *);
extern char *D_L15_001EE480[];
extern void func_L15_00436BA8(char *);
extern void func_L15_00436C68(void);

/* The gun platform's three states: 0 spawns it, 1 walks the shot table one
   entry per frame and 2 waits for the reload counter.  The table entry holds
   the shot count at 0 and the per-shot float at 0x1C of each 0x10-byte slot. */
void func_L15_00436990(char *a0) {
    char *s0 = a0;
    char *s1 = *(char **)(s0 + 0x68);

    switch (*(unsigned char *)(s0 + 0x20)) {
    case 0:
        *(unsigned char *)(s0 + 0x30) = 0xFF;
        if (func_380080(a0) == 0) {
            return;
        }
        func_L15_00436BA8(s0);
        if (*(int *)(s1 + 0x264) != 0) {
            func_3806A8(s0, (void *)func_L15_00436C68, 0, 0);
        }
        func_35A218(s0, *(int *)(s1 + 0x268), 0x8000FF00, 0x81, 0.75f, 1);
        break;
    case 1: {
        char *p;
        char *s3;
        int n;

        func_35A218(s0, *(int *)(s1 + 0x268), 0x8000FF00, 0x81, 0.75f, 1);
        s3 = (char *)func_3804E8(s0);
        p = D_L15_001EE480[*(int *)(s1 + 0x268)];
        if (func_383E28(s0) != 0) {
            n = *(int *)(s1 + 0x26C);
            *(int *)(s1 + 0x26C) = n + 1;
            if (n + 1 == *(int *)p - 1) {
                *(unsigned char *)(s0 + 0x20) = 3;
            } else {
                float f = *(float *)(p + n * 0x10 + 0x1C);

                if (f != -1.0f) {
                    if ((func_307D78(f) & 1) != 0) {
                        *(int *)(s1 + 0x274) = (func_307D78(f) >> 1) * 0x3C;
                        *(unsigned char *)(s0 + 0x20) = 2;
                    }
                }
                func_383C48(s0, p + (*(int *)(s1 + 0x26C) << 4) + 0x10);
                *(int *)(s3 + 0x130) = 0x1E8480;
            }
        }
        func_383700(s0, 0xC);
        func_382AE0(s0);
        func_381EB8(s0, 0, 1, 1);
        break;
    }
    case 2:
        if (func_3068A0((int *)(s1 + 0x274)) != 0) {
            *(unsigned char *)(s0 + 0x20) = 1;
        }
        break;
    }
}
