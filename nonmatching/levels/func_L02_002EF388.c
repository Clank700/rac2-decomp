/* Retained manual C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections
 * Retail: 564 bytes; compiled: 528 bytes.
 * Final coverage: us: 0/17; us2: 0/17; pal: 0/17.
 * Residual: 528/564 bytes with a 0xF0 rather than 0x100 frame. Full 64-byte inverse and
 * product storage are retained. The product writer writes 48 bytes; its 64-byte reader
 * consumes the fourth row before writing angles at that same row. Pointer spills,
 * owner/loop allocation and scalar field order still differ.
 * Reopen: A real owner/link-record and input-pointer lifetime witness that accounts for
 * retail spills and save set. No padding or guessed scratch extent. Explicit
 * matrix/position/rotation cursor forms tied.

 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
extern u8 *func_0029EFD0(int);
extern int func_L02_003272D8(char *);
extern void func_00283698(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern int func_002AE730(float *, int *);
extern void func_00283738(void *, void *, void *);
extern void func_002AB6D8(float *, float *);
extern void func_002833F0(void *, void *);

int func_L02_002EF388(u8 *object, TI128 *position, TI128 *rotation, u8 **links, int count) {
    float inverse[16] __attribute__((aligned(16)));
    float relative[4] __attribute__((aligned(16)));
    /* The three-row product occupies rows 0..2; the angle output shares row 3.
     * The angle reader consumes all 64 bytes before writing its three results. */
    union {
        float full[16];
        struct { float rows[12]; float angles[4]; } view;
    } rotationWork __attribute__((aligned(16)));
    u8 *fused = func_0029EFD0(0x9BB);
    u8 *data;
    TI128 *originalPosition, *originalRotation;
    u8 *originalMatrix;
    int i;
    if (!fused)
        return 0;
    *(u8 **)(fused + 0xB8) = object;
    fused[0x30] = 0xFF;
    qcopy(fused + 0x10, position);
    data = *(u8 **)(fused + 0x68);
    originalRotation = (TI128 *)(object + 0xF0);
    originalPosition = (TI128 *)(object + 0x10);
    originalMatrix = object + 0xC0;
    *(u8 **)(data + 0x10) = object;
    *(unsigned int *)(data + 0x20) = *(u16 *)(object + 0x34);
    *(int *)(data + 0x30) = func_L02_003272D8((char *)object);
    func_00283698(inverse, originalMatrix);
    for (i = 0; i < count && i < 3; i++) {
        if (links[i]) {
            *(u8 **)(data + 0x14 + i * 4) = links[i];
            *(unsigned int *)(data + 0x24 + i * 4) = *(u16 *)(links[i] + 0x34);
            *(int *)(data + 0x34 + i * 4) = func_L02_003272D8((char *)links[i]);
            func_00282CF0(relative, links[i] + 0x10, originalPosition);
            func_00283098(relative, relative, inverse);
            func_002AE730(relative, (int *)(data + 0x40 + i * 4));
            func_00283738(rotationWork.full, inverse, links[i] + 0xC0);
            func_002AB6D8(rotationWork.full, rotationWork.view.angles);
            func_002AE730(rotationWork.view.angles, (int *)(data + 0x4C + i * 4));
            *(u16 *)(links[i] + 0x34) |= 0x102;
            *(u16 *)(links[i] + 0x34) |= 1;
            links[i][0x31] = 0;
            *(int *)(links[i] + 0x98) = 0;
        }
    }
    qcopy(originalPosition, position);
    qcopy(originalRotation, rotation);
    func_002833F0(originalMatrix, originalRotation);
    *(int *)(object + 0x98) = 0;
    object[0x31] = 0;
    *(u16 *)(object + 0x34) |= 0x103;
    return 1;
}
