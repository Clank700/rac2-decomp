/* Nonmatching C: Create and update the resident object from the resident pose and joint matrices.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 380 bytes; retail: 380 bytes.
 * Placement checks: US and US2: 0/19 each; PAL: absent from the catalogue.
 * Remaining: The first placed instruction difference is at +0x4c in vector destination and later object-pointer register allocation.
 * Reopen with a real pointer-lifetime witness; preserve the complete 64-byte input and rotation matrices, the intervening 16-byte Euler vector and all three transfers.
 */
#include "common.h"







typedef int TI128 __attribute__((mode(TI)));


typedef union {
    TI128 q;
    struct {
        u8 pad[8];
        f32 f;
    } s;
} ResidentRec90;


typedef struct {
    u8 pad000[0x80];
    TI128 q080;
    ResidentRec90 q090;
    u8 pad0a0[0x1860 - 0xa0];
    u8 *p1860;
    u8 pad1864[0x2290 - 0x1864];
    u8 *p2290;
    s32 f2294;
} ResidentState;

extern ResidentState D_00189E20;

extern void *func_0029EFD0(int);

extern void func_0029FC20(char *,s32,char *);

extern void func_002A0F48(u8 *);

extern void func_00283678(u8 *, void *);

extern void func_002A7470(u8 *, s32, s32, s32);

extern void func_00283410(void *, void *);

extern void func_00283788(void *, void *, void *);

extern void func_00282C88(TI128 *);


/* Both matrices are complete 64-byte matrices. The vector lies between them. */
typedef struct {
    TI128 matrix[4];
    TI128 euler;
    TI128 rotation[4];
} Scratch;


typedef struct {
    TI128 v;
} ResidentQuad;


void func_L00_002A6008(void) {
  u8 *obj;
  Scratch s;
  ResidentQuad *dst1;
  ResidentQuad *src1;
  ResidentQuad *dst2;
  ResidentQuad *src2;

  if (D_00189E20.p1860 == 0) {
    obj = (u8 *)func_0029EFD0(0x47A);
    D_00189E20.p1860 = obj;
    if (obj == 0)
      goto end;
    dst1 = (ResidentQuad *)(obj + 0x10);
    src1 = (ResidentQuad *)&D_00189E20.q080;
    qcopy(dst1, src1);
    dst2 = (ResidentQuad *)(obj + 0xF0);
    src2 = (ResidentQuad *)&D_00189E20.q090.q;
    qcopy(dst2, src2);
    *(u16 *)(obj + 0x32) = 0x40;
    *(u8 *)(D_00189E20.p1860 + 0x31) = 1;
    *(u8 *)(D_00189E20.p1860 + 0x30) = 0;
    *(u16 *)(D_00189E20.p1860 + 0x34) = 0;
    func_002A0F48(D_00189E20.p1860);
    if (D_00189E20.p1860 == 0)
      goto end;
  }
  func_0029FC20((char *)D_00189E20.p2290,5,(char *)&s);
  qcopy(D_00189E20.p1860 + 0x10, &s.matrix[3]);
  func_002A0F48(D_00189E20.p1860);
  func_00282C88(&s.euler);
  *(f32 *)((u8 *)&s.euler + 8) = -D_00189E20.q090.s.f;
  func_00283410(&s.rotation[0], &s.euler);
  func_00283788(&s, &s, &s.rotation[0]);
  func_00283678(D_00189E20.p1860 + 0xC0, &s);
  *(u64 *)(D_00189E20.p1860 + 0x38) = *(u64 *)(D_00189E20.p2290 + 0x38);
  if (D_00189E20.f2294 == 0x4B) {
    if (*(u8 *)(D_00189E20.p1860 + 0x43) == 1)
      goto end;
    func_002A7470(D_00189E20.p1860, 1, 0, 0xA);
    goto end;
  }
  if (*(u8 *)(D_00189E20.p1860 + 0x43) == 0)
    goto end;
  func_002A7470(D_00189E20.p1860, 0, 0, 0x11);
end:
  return;
}
