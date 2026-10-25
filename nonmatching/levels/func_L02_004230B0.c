/*
 * Retained complete manual C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por
 * 1124/1132 bytes.
 * us: 0/2 placements; us2: 0/2 placements; pal: 0/2 placements.
 * Residual: Both complete144-byte packets, the64-byte frame and all row/cross-section captures
 * remain. Two real UV branches and unscaled width stores recover1124 of1132 bytes with the
 * retail0x1F0 frame. Header-store and FP scheduling, UV phase organization and register
 * lifetimes remain different.
 * Reopen: Independent packet-header/UV and width-phase lifetime evidence; keep both
 * submissions, actual per-program initializer ref and complete buffers.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { Vector point[4]; u32 color[4]; float uv[8]; u64 reserved,texture,setup,state; } QuadPacket;
typedef struct { u8 reserved[0x140]; float position[4]; } FlareTargetView;
extern FlareTargetView D_L02_001BA3C0 __attribute__((nosda));
extern u32 D_L02_001B1FE0 __attribute__((sda));
extern u32 D_L02_001B1FE4 __attribute__((sda));
extern float func_002A7878(float,float);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern u64 func_0027C878(int);
extern int func_001163B0(void);
extern void ref_L02_004230B0_00(char *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_002830C0(void *,void *,void *);
extern void func_00280B90(void *,void *,int);

/* Build two tapered strips from a beam point toward a random nearby endpoint. */
void func_L02_004230B0(u8 *object,void *position)
{
    QuadPacket outer,inner;
    Vector frame[4],endpoint,small,wide;
    u8 *state=*(u8 **)(object+0x68);
    u32 color;
    float size;
    endpoint.f[0]=func_002A7878(-1.0f,1.0f);
    endpoint.f[1]=func_002A7878(-1.0f,1.0f);
    endpoint.f[2]=func_002A7878(-1.0f,1.0f);
    func_00282F20(&endpoint,&endpoint,func_002A7878(0.25f,0.65f));
    func_00282CC0(&endpoint,position,&endpoint);
    outer.texture=func_0027C878(23);
    outer.setup=0xFF9000000260ULL;
    outer.reserved=0;
    outer.state=0x8000000040ULL|((u64)(func_001163B0()%2+1)<<2);
    outer.color[1]=D_L02_001B1FE0;outer.color[0]=D_L02_001B1FE0;outer.color[3]=D_L02_001B1FE0;outer.color[2]=D_L02_001B1FE0;
    inner.texture=func_0027C878(23);
    small.q=0;wide.q=0;
    color=D_L02_001B1FE4;
    inner.color[1]=color;inner.color[0]=color;
    inner.color[3]=color&0xFFFFFF;inner.color[2]=color&0xFFFFFF;
    inner.setup=0xFF9000000260ULL;inner.state=0x8000000048ULL;inner.reserved=0;
    small.f[3]=1;wide.f[3]=1;
    size=func_002A7878(0.1f,0.2f);
    small.f[2]=size;
    wide.f[2]=size+size;
    small.f[2]*=*(float *)(state+0x60);
    wide.f[2]*=*(float *)(state+0x60);
    ref_L02_004230B0_00((char *)&outer);ref_L02_004230B0_00((char *)&inner);
    if (func_001163B0()&1) {
        inner.uv[5]=0; inner.uv[7]=1;
        outer.uv[0]=0;outer.uv[1]=0;outer.uv[2]=0;outer.uv[3]=1;
        outer.uv[4]=1;outer.uv[5]=0;outer.uv[6]=1;outer.uv[7]=1;
        inner.uv[0]=0;inner.uv[1]=0;inner.uv[2]=0;inner.uv[3]=1;
        inner.uv[4]=1;inner.uv[6]=1;
    } else {
        inner.uv[7]=0;inner.uv[5]=1;
        outer.uv[0]=0;outer.uv[1]=1;outer.uv[2]=0;outer.uv[3]=0;
        outer.uv[4]=1;outer.uv[5]=1;outer.uv[6]=1;outer.uv[7]=0;
        inner.uv[0]=0;inner.uv[1]=1;inner.uv[2]=0;inner.uv[3]=0;
        inner.uv[4]=1;inner.uv[6]=1;
    }
    func_00282CF0(&frame[0],&endpoint,position);
    func_00282F20(&frame[0],&frame[0],1.0f);
    func_00282CF0(&frame[1],D_L02_001BA3C0.position,position);
    func_00282DD8(&frame[2],&frame[1],&frame[0]);
    func_00282F20(&frame[2],&frame[2],1.0f);
    func_00282DD8(&frame[1],&frame[0],&frame[2]);
    qcopy(&frame[3],position);
    qcopy(&outer.point[0],&small);qcopy(&inner.point[0],&wide);
    func_00282D30(&outer.point[1],&outer.point[0],-1.0f);
    func_00282D30(&inner.point[1],&inner.point[0],-1.0f);
    func_002830C0(&outer.point[0],&outer.point[0],frame);
    func_002830C0(&outer.point[1],&outer.point[1],frame);
    func_002830C0(&inner.point[0],&inner.point[0],frame);
    func_002830C0(&inner.point[1],&inner.point[1],frame);
    qcopy(&frame[3],&endpoint);
    small.f[2]*=0.15f;wide.f[2]=small.f[2]+small.f[2];
    qcopy(&outer.point[2],&small);qcopy(&inner.point[2],&wide);
    func_00282D30(&outer.point[3],&outer.point[2],-1.0f);
    func_00282D30(&inner.point[3],&inner.point[2],-1.0f);
    func_002830C0(&outer.point[2],&outer.point[2],frame);
    func_002830C0(&outer.point[3],&outer.point[3],frame);
    func_002830C0(&inner.point[2],&inner.point[2],frame);
    func_002830C0(&inner.point[3],&inner.point[3],frame);
    func_00280B90(&outer,0,0);func_00280B90(&inner,0,0);
}
