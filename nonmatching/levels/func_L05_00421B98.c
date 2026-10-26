/* func_L05_00421B98 (1852 B): draw two HUD icon pairs, the countdown icon and its box.
 * M25 2026-10-26 near miss. Profile -O2 -G8 -ffunction-sections (a -g8.c unit): 1848/1852 bytes.
 * Byte-identical modulo addresses to func_L10_00424CD0, func_L15_00431590 and func_L25_0040DE40
 * (family F35): one match ports to all four.
 * Measured declarations: x halves are sda scalars (), y halves the plain sized scalar
 * after them (lui $at per access); D_L05_001A904C, D_L05_001B2D80/2D84 plain sized
 * (lui/load in flow, $gp in delay slots). The colors initializer must sit in an inner
 * block after the two draws (retail copies it just before func_0028E588).
 * Left: retail saves an unused $s2 (frame 0xF0, mine 0xE0); 0x8710 lives in $s1 and the
 * state pointer in $s0 (mine swapped); retail loads the float constants after the y
 * conversion and uses $a0 as the mfc1/mtc1 temporary (arg 0 set last); the countdown
 * box computes x-0x33 before the D_L05_001B2D80 test (args precomputed).
 */
#include "common.h"

extern char *D_L05_001B13B0 __attribute__((sda));
extern int D_L05_001B354C __attribute__((sda));
extern int D_L05_001B3548 __attribute__((sda));
extern int D_L05_001B1428 __attribute__((sda));
extern int D_L05_001B142C;
extern int D_L05_001B1430 __attribute__((sda));
extern int D_L05_001B1434;
extern int D_L05_001B1438 __attribute__((sda));
extern int D_L05_001B143C;
extern int D_L05_001B1440 __attribute__((sda));
extern int D_L05_001B1444;
extern int D_L05_001A904C;
extern int D_L05_001B2D80;
extern float D_L05_001B2D84;
extern int D_001A79FC;
extern int func_00336D50(int, int);
extern void func_00300A00(int, int, float, float, float, float, float);
extern int func_00282948(void *);
extern float func_00283CE0(int);
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern int func_00115DA8(char *, const char *, ...);
extern void func_0027F5B8(int, int, unsigned long long, unsigned char *, int);

void func_L05_00421B98(int first, int second, int third, int fourth)
{
    char text[0x80];
    char *state = *(char **)(D_L05_001B13B0 + 0x68);
    float scale;
    int time;

    if (D_L05_001B354C == 0) {
        D_L05_001B354C = 1;
        D_L05_001B3548 = D_001A79FC;
    }
    if (D_L05_001A904C == 0)
        return;
    if (first) {
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xBD), 0x60442D00, (float)D_L05_001B1428,
                      (float)(int)((float)D_L05_001B142C * D_L05_001B2D84 + 0.5f), -1.0f, 1.0f, 0.0f);
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xBE), 0x55F0C070, (float)D_L05_001B1428,
                      (float)(int)((float)D_L05_001B142C * D_L05_001B2D84 + 0.5f), -1.0f, 1.0f, 0.0f);
    }
    if (second && D_L05_001B3548 < D_001A79FC) {
        if (func_00282948(state + 0x50) == 0) {
            time = *(int *)(state + 0x50);
            if (time >= 0x123) {
                scale = func_00283CE0(300 - time) * 0.1f;
                if (scale > 1.0f)
                    scale = 1.0f;
                else if (scale < 0.0f)
                    scale = 0.0f;
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xBF), 0x60442D00, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), scale, scale, 0.0f);
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC0), 0x55F0C070, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), scale, scale, 0.0f);
            } else if (time < 10) {
                scale = func_00283CE0(time) * 0.1f;
                if (scale > 1.0f)
                    scale = 1.0f;
                else if (scale < 0.0f)
                    scale = 0.0f;
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xBF), 0x60442D00, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), scale, scale, 0.0f);
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC0), 0x55F0C070, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), scale, scale, 0.0f);
            } else {
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xBF), 0x60442D00, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), 1.0f, 1.0f, 0.0f);
                func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC0), 0x55F0C070, (float)D_L05_001B1430,
                              (float)(int)((float)D_L05_001B1434 * D_L05_001B2D84 + 0.5f), 1.0f, 1.0f, 0.0f);
                {
                    unsigned int colors[4] = { 0x8080F0F0, 0x8080F0F0, 0x8080F0F0, 0x8080F0F0 };
                    func_0028EA58(func_0028E588(0xEAA2, 3), D_L05_001B1430 - 0x33, (int)((float)(D_L05_001B1434 - 13) * D_L05_001B2D84 + 0.5f + (D_L05_001B2D80 == 1 ? 1.0f : 0.0f)), 0x1C, 0x1C, colors);
                    func_00115DA8(text, "%d", D_001A79FC);
                    func_0027F5B8(D_L05_001B1430 + 5, (int)((float)(D_L05_001B1434 + 2) * D_L05_001B2D84 + 0.5f),
                                  0x80808080ULL, (unsigned char *)text, 0x80);
                }
            }
        } else {
            D_L05_001B3548 = D_001A79FC;
            *(int *)(state + 0x50) = 300;
        }
    }
    if (third) {
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC1), 0x60442D00, (float)D_L05_001B1438,
                      (float)(int)((float)D_L05_001B143C * D_L05_001B2D84 + 0.5f), 1.1f, 1.0f, 0.0f);
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC2), 0x55F0C070, (float)D_L05_001B1438,
                      (float)(int)((float)D_L05_001B143C * D_L05_001B2D84 + 0.5f), 1.1f, 1.0f, 0.0f);
    }
    if (fourth) {
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC1), 0x60442D00, (float)D_L05_001B1440,
                      (float)(int)((float)D_L05_001B1444 * D_L05_001B2D84 + 0.5f), 1.1f, 1.0f, 0.0f);
        func_00300A00(func_00336D50(D_L05_001A904C + 0x8710, 0xC2), 0x55F0C070, (float)D_L05_001B1440,
                      (float)(int)((float)D_L05_001B1444 * D_L05_001B2D84 + 0.5f), 1.1f, 1.0f, 0.0f);
    }
}
