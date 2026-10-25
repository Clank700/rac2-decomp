/* Bounded complete manual reconstruction, 2026-10-25; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 768/792 bytes; us: 0/27 placements; us2: 0/27 placements; pal: 0/27 placements.
 * All four five-point trails, four displacement vectors and signed halfword timers remain. Position
 * capture and both trail resets use clobbering qcopy. The bounded-random helper receives its real
 * vector-output pointer in A0 with two FP inputs. Frame 0xE0 agrees; outer-loop/base
 * materialization and saved-register schedules differ. A branch-local row cursor gave 696 bytes and
 * is retained privately.
 * Reopen with: Independent trail-row/timer cursor and allocation evidence beyond the negative row-
 * cursor form. Preserve every point, emission/random call and vector component; no artificial HI
 * dependency.
 * Original drafts, useful variants and diagnostics remain private.
 * No linked-image equality or complete native behavior is established.
 */
#include "common.h"
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
extern short D_L00_001B28B0[4];
extern unsigned short D_L00_001B28B8[4];
extern Vector D_L00_0023D9E0[4][5],D_L00_001B8DC0;
extern float D_L00_001AFA14 __attribute__((sda));
extern void func_002A7988(void *,float,float);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern float func_002A7878(float,float),func_002A78D8(float,float);
extern void func_002ACEC0(void *,void *,void *,float);
void func_L00_003B4EF8(unsigned char *object)
{
    Vector position,direction,axis,displacements[4];
    int i,j;
    float sign,angle;
    qcopy(&position,object+0x10);
    for(i=0;i<4;++i) {
        if(!D_L00_001B28B0[i])continue;
        --D_L00_001B28B0[i];
        if(D_L00_001B28B0[i]<0)D_L00_001B28B0[i]=0;
        if(!D_L00_001B28B0[i]) {
            D_L00_001B28B0[i]=4;D_L00_001B28B8[i]=64;
            func_002A7988(&direction,D_L00_001AFA14,D_L00_001AFA14);
            qcopy(&D_L00_0023D9E0[i][0],&position);
            sign=1.0f;
            for(j=0;j<4;++j) {
                func_00282CF0(&axis,&D_L00_0023D9E0[i][j],&D_L00_001B8DC0);
                angle=func_002A7878(0.17453295f,0.78539824f)*sign;
                sign=-sign;
                func_002ACEC0(&direction,&direction,&axis,angle);
                func_00282CC0(&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j],&direction);
            }
        } else {
            for(j=0;j<4;++j) {
                func_00282CF0(&displacements[j],&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j]);
                displacements[j].v[0]+=func_002A78D8(0.0f,0.1f);
                displacements[j].v[1]+=func_002A78D8(0.0f,0.1f);
                displacements[j].v[2]+=func_002A78D8(0.0f,0.1f);
            }
            qcopy(&D_L00_0023D9E0[i][0],&position);
            for(j=0;j<4;++j)func_00282CC0(&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j],&displacements[j]);
            if(D_L00_001B28B0[i]<1)D_L00_001B28B8[i]=0;
            else D_L00_001B28B8[i]=32;
        }
    }
}
