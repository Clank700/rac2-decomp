/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 352/356 bytes; us: 0/27 placements; us2: 0/27 placements; pal: 0/27 placements.
 * Four reviewed qzero calls clear the complete 64-byte matrix, with full position copy and three-
 * component velocity/result stores. The correct frame and long prefix agree, but the first matrix-
 * row address is retained early instead of rematerialized for the transpose call. An unrolled
 * clear-loop trial reached 356 bytes with other scheduling differences.
 * Reopen with real first-row/transpose pointer-lifetime evidence. Keep all four rows and do not add
 * a dummy instruction, barrier or invented volatile access.
 * Original complete variants and allocator diagnostics are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
/* Known effect header and payload prefix; total allocation extent is unspecified. */
typedef struct { unsigned char b0,b1,b2,b3; int color; unsigned char seed,alpha; unsigned short size; float life; union { Quad q; float f[4]; } position; float payload[8]; } Particle;
extern Particle *func_002B9030(int);
extern int func_00283CF0(float);
extern int func_001163B0(void);
extern float func_00283CE0(int);
extern float func_00282E80(void *,void *);
extern float func_002A7878(float,float);
extern int func_002A77E0(int);
extern s32 func_002AB1F0(u8 *);
extern void func_00282CF0(float *,void *,void *);
extern void func_00283698(void *,void *);
extern void func_002830C0(float *,float *,void *);
extern unsigned char *D_L00_001FEA68,*D_L00_001FEAAC,*D_L00_001FEA40,*D_L00_001FEA78;
extern char D_00189EA0[];

Particle *func_L00_0033C0D0(char *object,Quad *position,float *velocity,int *config,int flag)
{
    float relative[4];
    Quad matrix[4];
    Particle *p=func_002B9030(0x4a);
    if(p) {
        float *out;
        p->alpha=func_00283CF0(0.04f)-96;
        p->b3=flag?0x48:0x44;
        p->b1=0;
        out=p->payload;
        p->b2=*D_L00_001FEA68;
        p->seed=func_001163B0();
        p->life=0;
        qcopy(&p->position, position);
        out[0]=velocity[0];out[1]=velocity[1];out[2]=velocity[2];
        func_00282CF0(relative,position,object+0x10);
        qzero(&matrix[0]);qzero(&matrix[1]);qzero(&matrix[2]);qzero(&matrix[3]);
        func_00283698(matrix,object+0xc0);
        func_002830C0(relative,relative,matrix);
        out[4]=relative[0];out[5]=relative[1];out[6]=relative[2];
        *(char **)(out+3)=object;
        *(int **)(out+7)=config;
        p->size=*(unsigned short *)((char*)config+0xc);
        p->color=*config;
    }
    return p;
}
