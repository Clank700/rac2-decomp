/* Complete nonmatching reconstruction: 972/980 bytes.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * Placement checks: US: 0/27; US2: 0/27; PAL absent from catalogue.
 * The target branch is corrected to (target && mode) || (globalTarget && !mode), and the light factory keeps its real position/color/f12/f13 ABI and int32 result. All five vectors are16-byte aligned. D_0018AA18 remains a scalar pointer at its actual address. The retail LQ silently aligns that address down from0x18aa18 to0x18aa10, unlike its scalar LW. The explicit address mask is a hardware-semantics diagnostic only: the aligned block owner and extent are still unqualified, so this source must not be promoted.972/980 bytes remain nonmatching; frame0xa0 differs from retail0xb0, and global-base/branch/register allocation differs. The zero target vector and all four emissions remain.
 * Reopen only after independently qualifying the aligned block owner/readable extent behind the AA18-based LQ, then real target/global-state lifetimes. Do not declare a false16-byte AA18 object, add an alias global, or pass an8-byte-aligned address directly to qcopy.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef float Vector[4] __attribute__((aligned(16)));
typedef struct { char prefix[0x50]; float speed; char tail[0x8C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_0013957F NOT_SDA;
extern short D_0018C30C NOT_SDA;
extern float D_0018A580[4];
extern int D_0018B320 NOT_SDA;
extern char *D_0018AA18 NOT_SDA;
extern int D_L00_001ADB2C __attribute__((sda));
extern char *D_0018C0B0 NOT_SDA;
extern char *D_L00_001BF218 NOT_SDA;
extern void func_0029FCC0(char *, int, char *);
extern void func_00282F20(void *, void *, float);
extern int func_00291308(void *, unsigned int, float, float);
extern void func_L00_0037FA90(char *, char *, float, float, float);
extern void func_L00_0032A1A8(char *, char *, char *, float);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern char *func_L00_003A7C30(void *, void *, int, int);
extern int func_00277F48(void *, int, void *, void *, float);
extern int func_002ABB78(char *);
extern int func_L00_003A80F8(char *, void *);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);

/* Aim and spawn a beam, then flash four layers around its muzzle. */
void func_L00_003A3B58(char *moby)
{
    Vector origin, velocity, targetPosition, delta, unit;
    char *state = *(char **)(moby + 0x68);
    char *beam;
    float speed = D_L00_00262570[D_0013957F].speed * (1.0f / 60.0f);
    int mode = 0;
    if (D_0018C30C == 1) {
        func_0029FCC0(moby, 0, (char *)origin);
        func_00282F20(velocity, moby + 0xD0, -speed);
    } else {
        func_0029FCC0(moby, 0, (char *)origin);
        func_00282F20(velocity, D_0018A580, speed);
    }
    *(int *)(state + 0x10) = func_00291308(origin, 0x7F608060, 15.0f, 0.0f);
    *(int *)(state + 0x14) = 30;
    if (D_0018B320) {
        mode = 1;
        func_L00_0037FA90((char *)velocity, (char *)origin, speed, 128.0f, 0.3490659595f);
    } else if (D_0018AA18) {
        func_L00_0032A1A8(D_0018AA18, (char *)origin, (char *)velocity, speed);
    }
    if (D_L00_001ADB2C) {
        char *target = *(char **)(state + 0x30);
        if ((target && D_0018B320) || (D_0018AA18 && !D_0018B320)) {
            if (target)
                qcopy(targetPosition, (target + 0x10));
            else
                /* LQ discards the low four address bits; the scalar at +8 is distinct. */
                qcopy(targetPosition, (void *)((unsigned int)&D_0018AA18 & ~15U));
            func_00282CF0(delta, targetPosition, origin);
            mode = 2;
            func_00282F20(unit, velocity, 1.0f);
            func_00282D30(velocity, unit, func_00282DB0(unit, delta) + 3.0f);
        }
    }
    beam = func_L00_003A7C30(origin, velocity, *(int *)(state + 0x18), mode);
    if (beam)
        *(char **)(beam + 0xB8) = moby;
    if (func_00277F48(origin, 1, D_0018C0B0, 0, 1.0f) && D_L00_001BF218) {
        char *hit = D_L00_001BF218;
        char *model = *(char **)(hit + 0x24);
        if ((model && *(short *)(model + 0x46) == 5) || func_002ABB78(hit))
            func_L00_003A80F8(beam, hit + 0x10);
    }
    *(VectorBits *)targetPosition = 0;
    func_002C2210(origin, 8, 0x4010FF10, 2, 1, targetPosition, 1, 7.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0x4010FF10, 2, -1, targetPosition, 1, 5.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0xC0FFFFFF, 2, 1, targetPosition, 1, 3.0f, 0.1f, 0.0f);
    func_002C2210(origin, 8, 0xB0FFFFFF, 2, -1, targetPosition, 1, 2.5f, 0.1f, 0.0f);
}
