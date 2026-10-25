/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 2128 bytes; retail 2132 bytes.
 * us: 0/2 placements match (exit 1).
 * us2: 0/2 placements match (exit 1).
 * pal: 0/2 placements match (exit 1).
 * Remaining: The 0x160-byte frame agrees, but the state pointer is spilled instead of kept in
 * retail s4, and UV temporary/allocation schedules differ. Typed state fields and staged
 * rotation outputs still give 2128 bytes. Shared qcopy keeps the two real vertex copies without
 * closing the body.
 * Reopen: Independent packet and state-lifetime evidence explaining retail saved-pointer and UV
 * temporary allocation.
 */

#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { float direction[4]; u8 gap10[12]; float angle; u8 gap20[8]; float scroll; } TrailState;
typedef struct { u8 pad[0x70]; long f70,f78,f80,f88; } QuadPacket;
extern void func_00281DE8(QuadPacket *,int,int,int);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00280B90(void *,void *,int);
extern void func_00281EB8(void *,int,u32,int,float,float,float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283B98(float,float);
extern float func_002A7940(void);
extern float D_L16_001B9B00[4];
extern void func_L11_0045FFB0(char *);
extern float D_L16_001B199C NOT_SDA;
extern float D_L16_001B1910 __attribute__((sda));
extern float D_L16_001B1914 __attribute__((sda));
extern float D_L16_001B1918 __attribute__((sda));
extern float D_L16_001B191C __attribute__((sda));
extern float D_L16_001B1924 __attribute__((sda));
extern float D_L16_001B1938 __attribute__((sda));
extern float D_L16_001B193C __attribute__((sda));
extern float D_L16_001B19A0 __attribute__((sda));
extern float D_L16_001B19A4 __attribute__((sda));
extern u32 D_L16_001B1920 __attribute__((sda));
extern u32 D_L16_001B1928 __attribute__((sda));
extern u32 D_L16_001B192C __attribute__((sda));
extern u32 D_L16_001B1930 __attribute__((sda));
extern u32 D_L16_001B1934 __attribute__((sda));
extern u32 D_L16_001B1940 __attribute__((sda));
extern u32 D_L16_001B1944 __attribute__((sda));
extern u32 D_L16_001B1950 __attribute__((sda));
extern u32 D_L16_001B1954 __attribute__((sda));
extern u32 D_L16_001B1958 __attribute__((sda));
extern u32 D_L16_001B195C __attribute__((sda));
extern u32 D_L16_001B1960 __attribute__((sda));
extern u32 D_L16_001B1964 __attribute__((sda));
extern u32 D_L16_001B1968 __attribute__((sda));
extern u32 D_L16_001B196C __attribute__((sda));
extern u32 D_L16_001B1970 __attribute__((sda));
extern u32 D_L16_001B1974 __attribute__((sda));
extern u32 D_L16_001B1978 __attribute__((sda));
extern u32 D_L16_001B1980 __attribute__((sda));
extern u32 D_L16_001B1984 __attribute__((sda));
extern u32 D_L16_001B1988 __attribute__((sda));
extern u32 D_L16_001B1990 __attribute__((sda));
extern u32 D_L16_001B1994 __attribute__((sda));
extern u32 D_L16_001B1998 __attribute__((sda));
/* Only the sixth GPR slot is observed: retail copies t1. The first five
   raw slots below are unused; their original semantic types remain unknown. */
void func_L16_00414038(u32 unused0,u32 unused1,u32 unused2,u32 unused3,u32 unused4,u8 *object)
{
    QuadPacket packet;
    float camera[4],back[4],rear[4],side[4],center[4];
    float *vertex;
    float *uv;
    u32 *color;
    TrailState *state=*(TrailState **)(object+0x68);
    float cosine,sine,x,y,angle,size,rotatedX,rotatedY;
    int i;
    (void)unused0; (void)unused1; (void)unused2; (void)unused3; (void)unused4;
    func_L11_0045FFB0((char *)&packet);
    func_00281DE8(&packet,D_L16_001B1940,1,0x80);
    vertex=(float *)packet.pad;
    uv=(float *)(packet.pad+0x50);
    color=(u32 *)(packet.pad+0x40);
    color[0]=color[1]=(D_L16_001B195C<<24)|(D_L16_001B1958<<16)|(D_L16_001B1954<<8)|D_L16_001B1950;
    color[2]=color[3]=(D_L16_001B196C<<24)|(D_L16_001B1968<<16)|(D_L16_001B1964<<8)|D_L16_001B1960;
    uv[0]=0.0f; uv[1]=0.0f; uv[2]=0.0f; uv[3]=1.0f;
    uv[4]=1.0f; uv[5]=0.0f; uv[6]=1.0f; uv[7]=1.0f;
    for (i=0;i<4;i++) {
        uv[i*2]-=state->scroll;
        if (uv[i*2]<=7.0f) uv[i*2]+=7.0f;
    }
    state->scroll+=0.1f;
    if (state->scroll>=4.0f) state->scroll-=4.0f;
    func_00282CF0(camera,object+0x10,D_L16_001B9B00);
    func_00282F20(back,state,-D_L16_001B193C);
    func_00282CC0(rear,object+0x10,back);
    func_00282DD8(side,camera,back);
    func_00282F20(side,side,D_L16_001B191C);
    func_00282F20(center,state,D_L16_001B199C);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[2]; color[1]=color[3]; color[2]=color[3]=0x801010;
    qcopy(vertex,vertex+8);
    qcopy(vertex+4,vertex+12);
    func_00282CC0(vertex+8,vertex+8,back);
    func_00282CC0(vertex+12,vertex+12,back);
    func_00280B90(&packet,0,0);
    func_00282F20(back,state,-4.0f);
    uv[0]=0.0f; uv[1]=0.0f; uv[2]=0.0f; uv[3]=1.0f;
    uv[4]=1.0f; uv[5]=0.0f; uv[6]=1.0f; uv[7]=1.0f;
    cosine=func_00283180(state->angle);
    sine=func_00283198(state->angle);
    for (i=0;i<4;i++) {
        x=uv[i*2]-0.5f; y=uv[i*2+1]-0.5f;
        rotatedY=x*sine+y*cosine;
        rotatedX=x*cosine-y*sine;
        uv[i*2+1]=rotatedY+0.5f;
        uv[i*2]=rotatedX+0.5f;
    }
    state->angle=func_00283B98(state->angle,D_L16_001B1938*0.017453294f);
    func_00281DE8(&packet,D_L16_001B1944,1,0x80);
    packet.f70=5;
    color[0]=color[1]=(D_L16_001B192C<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1910);
    func_00282F20(center,state,D_L16_001B199C);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B192C<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1914);
    func_00282F20(center,state,D_L16_001B19A0);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1934<<24)|(D_L16_001B1978<<16)|(D_L16_001B1974<<8)|D_L16_001B1970;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1918);
    func_00282F20(center,state,D_L16_001B19A0);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    color[0]=color[1]=(D_L16_001B1930<<24)|0xFFFFFF;
    color[2]=color[3]=(D_L16_001B1988<<16)|(D_L16_001B1984<<8)|D_L16_001B1980;
    func_00282F20(side,side,D_L16_001B1910);
    func_00282F20(center,state,D_L16_001B19A4);
    func_00282CC0(center,object+0x10,center);
    func_00282CC0(vertex,center,side);
    func_00282CF0(vertex+4,center,side);
    func_00282F20(back,state,-0.6f);
    func_00282CC0(rear,center,back);
    func_00282CC0(rear,rear,back);
    func_00282CC0(vertex+8,rear,side);
    func_00282CF0(vertex+12,rear,side);
    func_00280B90(&packet,0,0);
    angle=func_002A7940();
    func_00281EB8(object+0x10,D_L16_001B1920,D_L16_001B1928,1,D_L16_001B1924,0.08f,angle);
    size=D_L16_001B1924*0.4f;
    angle=func_002A7940();
    func_00281EB8(object+0x10,D_L16_001B1920,0x80808080U,1,size,0.08f,angle);
}
