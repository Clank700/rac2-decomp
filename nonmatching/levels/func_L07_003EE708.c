/* func_L07_003EE708 (1264 bytes, 1 place: level 07_siberius) - best attempt, NOT MATCHED, and
 * not placeable even if it were exact: the switch's jump table.
 *
 * Built as a function of src/levels/07_siberius/L07_00389EB8-g8.c (case 3 takes a $gp address),
 * this body is 1256 bytes against retail's 1264. tools/check.py: "1256 bytes, expected 1264".
 * What differs:
 *
 *  1. The jump table, as in func_L06_003FDA08: six states through `jr $a0` and a table at
 *     0x2A3380 in the level's data ({+0x54, +0xBC, +0x188, +0x1A8, +0xEC, +0x378}, so the case
 *     bodies come in the order 0, 1, 4, 2, 3, 5). The C `switch` gives the same dispatch but
 *     the table lands in .rodata, which tools/build.py cannot place.
 *
 *  2. The 128-bit copy wall, 8 bytes. Case 0 copies the object's position into the state
 *     (`*(TI128 *)(s3 + 0xF0) = *(TI128 *)(s1 + 0x10)`): retail forms both addresses
 *     (`addiu $a0,$s3,0xF0 ; addiu $v1,$s1,0x10 ; lq $v0,0($v1) ; sq $v0,0($a0)`), this cc1
 *     folds the offsets (`lq $v0,0x10($s1)` ... `sq $v0,0xF0($s3)`, later in the block).
 *
 *  3. Case 3's id-list base, three words. Retail computes `addiu $v0,$s3,0x9C` in the delay slot
 *     of the `bc1f`, uses it for the guard (`list[w120] != -1`) and copies it to $s4 for the
 *     walk (`daddu $s4,$v0,$zero`); here the guard already uses $s4. A second C variable
 *     (`q` for the guard, `list = q` or a fresh `(int *)(s3 + 0x9C)` for the walk) is merged
 *     back into one by cse/gcse; the guard written with the expression instead folds the 0x9C
 *     into the displacement, and the loop test with the expression is far worse.
 *
 * Everything else is retail's, word for word: the compare ahead of the table, the case 4 block
 * (`if (i >= 6 || (list = ..., list[i + 1]) == -1)` with the base computed lazily after the first
 * test, which is what puts `addiu $a2,$s3,0x9C` after `addiu $v0,$a1,1`), the walk with the
 * group re-read from the list at every test (`& 0xFF`, not a char cast, which gives an `lbu`),
 * the 0xFE / 0xFD tests (an `unsigned char` read: with `char *e` cc1 folds `e[0x20] == 0xFE`
 * to false), the 0xD29 / 0xD2A pair as a `switch`, the tail after the switch, and case 5's
 * `+=` (with func_002AA2E8 declared as returning a float).
 *
 * Callees (level 7 addresses -> names): 0x310BF8 func_002A7940, 0x3109C8 func_002A7750,
 * 0x316808 func_002ACBC8, 0x3EECE0 func_L07_003EECE0, 0x31FA60 func_002B3868, 0x3EEE28
 * func_L07_003EEE28 (returns a float in case 3), 0x311AA0 func_002A8508, 0x2E3F80 func_00282948,
 * 0x31FAD0 func_002B38B8, 0x2E47D0 func_00283098, 0x2E4310 func_00282CC0, 0x355488 func_002E5CF8,
 * 0x3E7380 func_L07_003E7380, 0x3EBBE8 func_L07_003EBBE8, 0x313DD8 func_002AA2E8, 0x306800
 * func_0029F338, 0x312FA8 func_002A9640, 0x313008 func_002A96A0, 0x31CC18 func_002B0A68,
 * 0x2E4340 func_00282CF0, 0x2E45F0 func_00282F20, 0x3EF428 func_0032DA58.
 */

#include "include_asm.h"

extern void func_0029F338(int);

typedef int TI128 __attribute__((mode(TI)));

extern float func_002A7940();
extern void func_002A7750(char *, int, int);
extern int func_002ACBC8(char *, int);
extern void func_L07_003EECE0(char *);
extern int func_002B3868(char *);
extern float func_L07_003EEE28(char *);
extern int func_002A8508(int, int);
extern int func_00282948(void *);
extern int func_002B38B8(char *);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_002E5CF8(int, int, char *);
extern void func_L07_003E7380(char *, void *, void *, char *, int);
extern void func_L07_003EBBE8(char *, void *, void *, char *, int);
extern float func_002AA2E8(void *, float, float);
extern int func_002A9640(char *, int, int);
extern float func_002A96A0(char *, int);
extern void func_002B0A68(char *, int, void *, int, float, float, float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_0032DA58(char *, void *, void *, float);

extern char D_00189EA0[];
extern char D_L07_001B9200[];
extern int D_L07_001B0C50 __attribute__((sda));
extern unsigned short *D_L07_001FAD60[];
extern char *D_L07_001B22DC[] __attribute__((sda));
extern int D_L07_001B22F8[] __attribute__((sda));

#define AT(base, idx) (*(int *)((char *)(base) + ((idx) << 2)))
#define LIST(idx) AT(list, idx)

void func_L07_003EE708(char *a0)
{
    char *s1 = a0;
    char *s3;

    s3 = *(char **)(s1 + 0x68);
    switch (*(unsigned char *)(s1 + 0x20)) {
    case 0:
        if (*(short *)(s3 + 0x24) == 0) {
            *(short *)(s3 + 0x24) = 0x28;
            *(float *)(s3 + 0x20) = 40.0f;
        }
        *(float *)(s3 + 0x104) = func_002A7940();
        *(float *)(s3 + 0x108) = func_002A7940();
        *(TI128 *)(s3 + 0xF0) = *(TI128 *)(s1 + 0x10);
        func_002A7750(s1, 1, -1);
        *(int *)(s1 + 0x98) = 0;
        *(unsigned short *)(s1 + 0x34) = (*(unsigned short *)(s1 + 0x34) | 0x41) & 0xEFFF;
        break;
    case 1:
        if (*(int *)(s3 + 0x90) != -1) {
            if (func_002ACBC8(D_00189EA0, *(int *)(s3 + 0x90)))
                func_L07_003EECE0(s1);
        }
        break;
    case 4: {
        int *list;
        int i;

        if (func_002B3868(s1))
            *(int *)(s3 + 0x124) = 0x3C;
        func_L07_003EEE28(s1);
        i = *(int *)(s3 + 0x120);
        if (i >= 6 || (list = (int *)(s3 + 0x9C), LIST(i + 1)) == -1) {
            func_002A7750(s1, 5, -1);
        } else {
            if (func_002A8508(LIST(i), -1) == 0) {
                if (func_00282948(s3 + 0x124)) {
                    *(int *)(s3 + 0x120) = *(int *)(s3 + 0x120) + 1;
                    func_002A7750(s1, 3, -1);
                }
            }
        }
        break;
    }
    case 2:
        func_L07_003EEE28(s1);
        if (func_002B38B8(s1))
            func_002A7750(s1, 3, -1);
        break;
    case 3: {
        float f;
        int *q;
        int *list;
        unsigned short *p;
        char *e;
        char buf[16];

        f = func_L07_003EEE28(s1);
        if (f < 3.0f) {
            q = (int *)(s3 + 0x9C);
            if (AT(q, *(int *)(s3 + 0x120)) != -1) {
                list = (int *)(s3 + 0x9C);
                func_00283098(buf, &D_L07_001B0C50, s1 + 0xC0);
                func_00282CC0(buf, buf, s1 + 0x10);
                for (p = D_L07_001FAD60[LIST(*(int *)(s3 + 0x120))];
                     (LIST(*(int *)(s3 + 0x120)) & 0xFF) != 0xFF &&
                     LIST(*(int *)(s3 + 0x120)) <= D_L07_001B22F8[0] && p != 0 &&
                     ((short)p[-1] >= 0 || p == D_L07_001FAD60[LIST(*(int *)(s3 + 0x120))]);
                     p++) {
                    e = D_L07_001B22DC[0] + ((*p & 0x7FFF) << 8);
                    if (e == 0)
                        break;
                    if (*(unsigned char *)(e + 0x20) != 0xFE) {
                        if (*(unsigned char *)(e + 0x20) != 0xFD) {
                            switch (*(short *)(e + 0xAA)) {
                            case 0xD29:
                                func_002E5CF8(0, 0, s1);
                                func_L07_003E7380(e, buf, e + 0x10, s1, *(int *)(s3 + 0x110));
                                break;
                            case 0xD2A:
                                func_002E5CF8(0, 0, s1);
                                func_L07_003EBBE8(e, buf, e + 0x10, s1, *(int *)(s3 + 0x110));
                                break;
                            }
                        }
                    }
                }
            }
            func_002A7750(s1, 4, -1);
        }
        break;
    }
    case 5: {
        func_L07_003EEE28(s1);
        func_002AA2E8(s3 + 0x114, 0.16666667f, 0.00083333335f);
        *(float *)(s3 + 0x118) += *(float *)(s3 + 0x114);
        if (30.0f < *(float *)(s3 + 0x118)) {
            if (*(unsigned char *)(s1 + 0x31) == 0) {
                func_0029F338((int)s1);
                return;
            }
        }
        break;
    }
    }
    if (*(unsigned char *)(s1 + 0x20) < 2)
        return;
    if (*(int *)(s3 + 0x110) != 0)
        return;
    {
        char buf2[16];
        int t;
        float f2;

        t = func_002A9640(s1, 0x10000, 0);
        f2 = func_002A96A0(s1, t);
        func_002AA2E8(s3 + 0x20, 0.0f, f2);
        *(unsigned char *)(s1 + 0xA8) = 0xFF;
        if (*(float *)(s3 + 0x20) == 0.0f) {
            func_002B0A68(s1, 0x7F7, s3 + 0x60, 0xFF, 5.0f, 10.0f, 5.0f, 10.0f);
            func_00282CF0(buf2, D_L07_001B9200, s1 + 0x10);
            func_00282F20(buf2, buf2, 1.0f);
            func_0032DA58(s1, s1 + 0x10, buf2, 0.0f);
            func_002E5CF8(2, 0, s1);
            func_0029F338((int)s1);
        }
    }
}
