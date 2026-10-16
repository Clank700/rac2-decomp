#include "common.h"
#include "structs.h"

extern int r1_func_0011D960(void);

extern void r1_func_0011D9A8(void);

typedef struct {
    unsigned char pad0[0x838];
    int unk838;
    int unk83C;
    unsigned char pad840[0x18];
    void *cbData;
} MpegDec;

extern char r1_D_00153888[];

extern void func_0012C3B0(void *);

extern void r1_func_0012BC78(int, void *);

extern void r1_func_0012C468(void *, void *);

#define IPU_CTRL   ((volatile unsigned int *)0x10002010)

#define IPU_BP     ((volatile unsigned int *)0x10002020)

#define IPU_TOP    ((unsigned long *)0x10002030)

#define D3_CHCR    ((volatile unsigned int *)0x1000B400)

#define D3_QWC     ((volatile unsigned int *)0x1000B420)

#define D4_CHCR    ((volatile unsigned int *)0x1000B000)

#define D4_QWC     ((volatile unsigned int *)0x1000B020)

#define D_ENABLER  ((volatile unsigned int *)0x1000F520)

#define D_ENABLEW  ((volatile unsigned int *)0x1000F590)

extern int func_0012B1C0(void *);

/* func_0012C508 returns a short: its epilogue sign-extends $v0. */
extern short func_0012C508(int, int);

INCLUDE_ASM("asm/core", func_00129450);

/* func_001296A0 is rac1-decomp src/core/00125630.c func_00125880 (_getAllRefs,
   libmpeg), adapted from Lombyte (MIT) by OpenRAC's tools/port.py. The RAC1 and
   RAC2 objects carry it at the same relative position (RAC2 = RAC1 + 0x3E20)
   and both are 1796 bytes. Fields used below were re-measured against RAC2's
   own accesses: ref_images at 0x1B8, mb_buf at 0x590, mb_buf_index at 0x810
   (`lw $v0,0x810($s1)`), fetch_count at 0x6BC (`sw $zero,0x6BC(...)`), so the
   RAC1 struct layout carries over unchanged. The three error strings are at
   0x13BA20/0x13BA40/0x13BA60, reached as %hi 0x14 / %lo -0x45E0/-0x45C0/-0x45A0.
   Fifth to eighth integer arguments arrive in $t0-$t3 (the SDK compiler's EE
   convention): motion_type, pmv, mvfs, dmvector. */

typedef struct MpegRefImage296A0 MpegRefImage296A0;

typedef struct {
    u8 pad000[0x12C];
    int fetch_count; /* 0x12C */
    u8 pad130[0x140 - 0x130];
} MbBuf296A0;

typedef struct {
    u8 pad000[0x120];
    int second_field; /* 0x120 */
    u8 pad124[0x150 - 0x124];
    int picture_coding_type; /* 0x150 */
    u8 pad154[0x174 - 0x154];
    int picture_structure; /* 0x174 */
    u8 pad178[0x1B8 - 0x178];
    MpegRefImage296A0 *ref_images[12]; /* 0x1B8 */
    u8 pad1E8[0x590 - 0x1E8];
    MbBuf296A0 mb_buf[2]; /* 0x590 */
    int mb_buf_index; /* 0x810 */
} MpegDecoder296A0;

extern void func_00129DA8(MpegDecoder296A0 *d, MpegRefImage296A0 *ref, int sfield,
                          int dfield, int yofs, int h, int bx, int by, int dx,
                          int dy, int fieldpred, int avg);

extern void func_0012B3E0(MpegDecoder296A0 *d, int DMV[][2], int *dmvector, int mvx,
                          int mvy);

/* _errMessage takes one argument, this call site hands it three; the alias is
   the only spelling that keeps the extra two live in $a1/$a2. */
extern void func_00130250_msg(MpegDecoder296A0 *d, char *fmt, int code)
    __asm__("func_00130250");

extern char D_0013BA20[];

extern char D_0013BA40[];

extern char D_0013BA60[];

void func_001296A0(MpegDecoder296A0 *d, int bx, int by, int mb_type, int motion_type,
                   int pmv[2][2][2], int mvfs[2][2], int *dmvector) {
    int dmv[2][2];
    MpegRefImage296A0 *refs[2][2];
    int one = 1;
    int avg;
    int currentfield;
    int same = one;

    avg = 0;

    d->mb_buf[d->mb_buf_index].fetch_count = 0;

    if ((mb_type & 8) || d->picture_coding_type == 2) {
        if (d->picture_structure == 3) {
            if (motion_type == 2 || !(mb_type & 8)) {
                func_00129DA8(d, d->ref_images[0], 0, 0, 0, 16, bx, by, pmv[0][0][0],
                              pmv[0][0][1], 0, 0);
            } else if (motion_type == same) {
                func_00129DA8(d, d->ref_images[0], mvfs[0][0], 0, 0, 8, bx, by,
                              pmv[0][0][0], pmv[0][0][1] >> 1, same, 0);
                func_00129DA8(d, d->ref_images[0], mvfs[1][0], 1, 0, 8, bx, by,
                              pmv[1][0][0], pmv[1][0][1] >> 1, same, 0);
            } else if (motion_type == 3) {
                func_0012B3E0(d, dmv, dmvector, pmv[0][0][0], pmv[0][0][1] >> 1);
                func_00129DA8(d, d->ref_images[0], 0, 0, 0, 8, bx, by, pmv[0][0][0],
                              pmv[0][0][1] >> 1, same, 0);
                func_00129DA8(d, d->ref_images[0], 1, 0, 0, 8, bx, by, dmv[0][0],
                              dmv[0][1], same, one);
                func_00129DA8(d, d->ref_images[0], 1, 1, 0, 8, bx, by, pmv[0][0][0],
                              pmv[0][0][1] >> 1, same, 0);
                func_00129DA8(d, d->ref_images[0], 0, 1, 0, 8, bx, by, dmv[1][0],
                              dmv[1][1], same, one);
            } else {
                func_00130250_msg(d, D_0013BA20, motion_type);
            }
        } else {
            currentfield = d->picture_structure == 2;
            /* Keep the retail stack order: two field choices per reference set. */
            refs[0][0] = d->ref_images[4];
            refs[0][1] = d->ref_images[8];
            refs[1][0] = d->ref_images[5];
            refs[1][1] = d->ref_images[9];
            one = 2;
            same = 0;
            if (d->picture_coding_type == one && d->second_field) {
                same = currentfield != mvfs[0][0];
            }
            if (motion_type == 1 || !(mb_type & 8)) {
                func_00129DA8(d, refs[same][mvfs[0][0]], 0, 0, 0, 16, bx, by,
                              pmv[0][0][0], pmv[0][0][1], 0, 0);
            } else if (motion_type == 2) {
                func_00129DA8(d, refs[same][mvfs[0][0]], 0, 0, 0, 8, bx, by,
                              pmv[0][0][0], pmv[0][0][1], 0, 0);
                same = d->picture_coding_type == motion_type && d->second_field &&
                       currentfield != mvfs[1][0];
                func_00129DA8(d, refs[same][mvfs[1][0]], 0, 0, 8, 8, bx, by,
                              pmv[1][0][0], pmv[1][0][1], 0, 0);
            } else if (motion_type == 3) {
                same = d->second_field ? motion_type - 2 : 0;
                func_0012B3E0(d, dmv, dmvector, pmv[0][0][0], pmv[0][0][1]);
                func_00129DA8(d, refs[0][currentfield], 0, 0, 0, 16, bx, by,
                              pmv[0][0][0], pmv[0][0][1], 0, 0);
                func_00129DA8(d, refs[same][!currentfield], 0, 0, 0, 16, bx, by,
                              dmv[0][0], dmv[0][1], 0, 1);
            } else {
                func_00130250_msg(d, D_0013BA40, motion_type);
            }
        }
        avg = 1;
    }

    if (mb_type & 4) {
        if (d->picture_structure == 3) {
            same = 1;
            if (motion_type == 2) {
                func_00129DA8(d, d->ref_images[1], 0, 0, 0, 16, bx, by, pmv[0][1][0],
                              pmv[0][1][1], 0, avg);
            } else {
                func_00129DA8(d, d->ref_images[1], mvfs[0][1], 0, 0, 8, bx, by,
                              pmv[0][1][0], pmv[0][1][1] >> 1, same, avg);
                func_00129DA8(d, d->ref_images[1], mvfs[1][1], 1, 0, 8, bx, by,
                              pmv[1][1][0], pmv[1][1][1] >> 1, same, avg);
            }
        } else if (motion_type == 1) {
            func_00129DA8(d, mvfs[0][1] ? d->ref_images[9] : d->ref_images[5], 0, 0, 0,
                          16, bx, by, pmv[0][1][0], pmv[0][1][1], 0, avg);
        } else if (motion_type == 2) {
            func_00129DA8(d, mvfs[0][1] ? d->ref_images[9] : d->ref_images[5], 0, 0, 0,
                          8, bx, by, pmv[0][1][0], pmv[0][1][1], 0, avg);
            func_00129DA8(d, mvfs[1][1] ? d->ref_images[9] : d->ref_images[5], 0, 0, 8,
                          8, bx, by, pmv[1][1][0], pmv[1][1][1], 0, avg);
        } else {
            func_00130250_msg(d, D_0013BA60, motion_type);
        }
    }
}

INCLUDE_ASM("asm/core", func_00129DA8);

INCLUDE_ASM("asm/core", func_0012A1C8);

ASM_FUNC("asm/core", func_0012A3E8);

ASM_FUNC("asm/core", func_0012A460);

ASM_FUNC("asm/core", func_0012A4F8);

ASM_FUNC("asm/core", func_0012A5B0);

ASM_FUNC("asm/core", func_0012A680);

ASM_FUNC("asm/core", func_0012A730);

ASM_FUNC("asm/core", func_0012A7E8);

ASM_FUNC("asm/core", func_0012A8E0);

ASM_FUNC("asm/core", func_0012A9E0);

ASM_FUNC("asm/core", func_0012AA80);

ASM_FUNC("asm/core", func_0012AB30);

ASM_FUNC("asm/core", func_0012AC10);

ASM_FUNC("asm/core", func_0012ACF8);

ASM_FUNC("asm/core", func_0012ADD0);

ASM_FUNC("asm/core", func_0012AEA0);

ASM_FUNC("asm/core", func_0012AFC0);

ASM_FUNC("asm/core", func_0012B0D8);

/* rac1-decomp src/core/00125630.c: func_00127378 */
void func_0012B198(int arg0) {
    unsigned int *p = (unsigned int *)0x10002010;
    *p = (*p & 0xFF7FFFFF) | (arg0 << 23);
}

/* rac1-decomp src/core/00125630.c: func_001273A0 */
/* _waitBdecOut (libmpeg). Adapted from Lombyte (MIT) for PAL. */
int func_0012B1C0(void *arg0) {
    MpegDec *d = arg0;
    int cb1[8];
    int cb2[8];
    int ret;
    int intr;
    unsigned int bp;
    long top;
    unsigned int rest;

    ret = 1;
    func_0012C3B0(d);
    if (*D4_QWC != 0 && !(*IPU_CTRL & 0x4000)) {
        do {
            if (*D3_QWC == 0 && !(*D3_CHCR & 0x100)) {
                cb1[0] = 1;
                r1_func_0012BC78((int)d->cbData, cb1);
            }
        } while (*D4_QWC != 0 && !(*IPU_CTRL & 0x4000));
    }
    bp = *IPU_BP;
    top = *IPU_TOP;
    d->unk838 = top;
    if (top < 0) {
        rest = bp & 0x1F;
        d->unk83C = rest ? 32 - rest : 0;
    } else {
        d->unk83C = 32;
    }
    if (*IPU_CTRL & 0x4000) {
        r1_func_0012C468(d, r1_D_00153888);
        cb2[0] = 2;
        r1_func_0012BC78((int)d->cbData, cb2);
        *(unsigned int *)0x10002010 = 0x40000000;
        cb2[0] = 3;
        r1_func_0012BC78((int)d->cbData, cb2);
        intr = r1_func_0011D960();
        *D_ENABLEW = *D_ENABLER | 0x10000;
        *D4_CHCR = 0;
        *D_ENABLEW = *D_ENABLER & ~0x10000;
        if (intr) {
            r1_func_0011D9A8();
        }
        ret = 0;
        *D4_QWC = 0;
    }
    return ret;
}

/* rac1-decomp src/core/00125630.c: func_001275A0 */
/* Returns its callee's value: retail keeps the frame and calls, and
   2.9-ee turns a void one-call function into a bare tail jump (8 bytes
   against 28). */
short func_0012B3C0(int arg0) {
    return func_0012C508(arg0, 3);
}
