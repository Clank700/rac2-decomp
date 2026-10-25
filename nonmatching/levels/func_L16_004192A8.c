/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 796 bytes; retail 800 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: The explicit active/init/common state chain and four-element cursor initialization
 * reach 796 bytes, up from 788. The frame is 0x90 against retail 0xA0, with one fewer saved GPR.
 * Resident-state base addressing, request scratch and float schedules still differ. The state
 * helper takes a full-width integer.
 * Reopen: A verified resident player/request workspace layout and pointer lifetime witness that
 * reproduces the 0xA0 frame.
 */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct { Quad16 vector; int owner,flags; unsigned char enabled,kind; unsigned short id; float distance; int active; } CollisionRequest;
typedef struct { Vector128 position,offset; CollisionRequest request; Vector128 direction; } MarkerWorkspace;
extern float func_002A7940(void);
extern void func_002A7750(unsigned char *,int,int);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_00277258(void *,int,void *,float);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern void func_L00_002B30E8(void);
extern void func_00282D60(void *,void *,float);
extern float func_00283B98(float,float);
extern float func_002A78D8(float,float);
extern void func_L00_002E6CF0(void (*)(void *),void *);
extern void func_L13_0041FBE0(void *);
extern float func_002AA2E8(float *,float,float);
extern int D_001A79F0;
extern Vector128 D_00189EA0;
extern char *D_0018C0B0;
extern char *D_0018A15C;
extern int D_0018A160;
extern char *D_L16_001BFF58 NOT_SDA;
extern Quad16 D_L16_001A8F20;
extern float D_L16_001B1CA0 __attribute__((sda));
extern float D_L16_001B1CA4 __attribute__((sda));
extern float D_L16_001B1CA8 __attribute__((sda));
void func_L16_004192A8(char *object)
{
    MarkerWorkspace local;
    float *state=*(float **)(object+0x68);
    float value;
    int i;
    if (*(unsigned char *)(object+0x20)==1) goto active;
    if (*(unsigned char *)(object+0x20)>=2) goto common;

        state[0]=1.0f;
        state[8]=func_002A7940();
        state[2]=0.5f;
        state[1]=0.0f;
        state[0]=1.0f;
        { float *values=state+7; for(i=3;i>=0;i--) *values--=1.0f; }
        *(unsigned char *)(object+0x30)=0xff;
        func_002A7750((unsigned char *)object,1,-1);
        object[0x31]=0;
        *(unsigned short *)(object+0x34)|=1;
    goto common;
active:
    if (D_001A79F0==16) {

        qcopy(&local.position,&D_00189EA0);
        func_00282F20(&local.offset,D_0018C0B0+0xe0,0.75f);
        func_00282CC0(&local.position,&local.position,&local.offset);
        if (func_00277258(&local.position,0,D_0018C0B0,0.5f)!=0 && D_L16_001BFF58!=0 && D_L16_001BFF58==object) {
            func_002A8C00((char *)&local.request,(int)object,1,100.0f,&D_L16_001A8F20);
            local.request.id=*(unsigned short *)(object+0xaa);
            func_L00_002B30E8();
        }
        if (D_0018A15C!=0 && D_0018A15C==object && D_0018A160!=0) {
            ((float *)&local.direction)[0]=0.0f;
            ((float *)&local.direction)[1]=1.0f;
            ((float *)&local.direction)[2]=0.0f;
            ((float *)&local.direction)[3]=1.0f;
            func_00282F20(&local.direction,&local.direction,10.0f);
            func_002A8C00((char *)&local.request,(int)object,1,10.0f,(Quad16 *)&local.direction);
            local.request.id=*(unsigned short *)(object+0xaa);
            func_L00_002B30E8();
        }
    }
common:
    if (state[0]!=0.0f) {
        func_00282D60(&local.position,object,0.0009765625f);
        state[8]=func_00283B98(state[8],D_L16_001B1CA0*0.0002908882452f);
        state[3]+=(D_L16_001B1CA4+func_002A78D8(0.25f,0.5f))*0.016666668f;
        if (state[3]>1.0f) state[3]-=1.0f;
        for(i=1;i<=2;i++) {
            value=state[i]+D_L16_001B1CA8*0.016666668f;
            state[i]=value;
            if(value>1.0f) state[i]=value-1.0f;
        }
        func_L00_002E6CF0(func_L13_0041FBE0,object);
        func_002AA2E8(state,1.0f,0.008333333768f);
    }
}
