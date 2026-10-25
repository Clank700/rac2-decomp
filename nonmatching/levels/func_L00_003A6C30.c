/* Complete nonmatching reconstruction: 3168/3200 bytes.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * Placement checks: US: 0/27; US2: 0/27; PAL absent from catalogue.
 * The complete acquisition/firing controller retains its six live16-byte vectors and48-byte damage packet. Metadata access keeps the canonical int32 return and explicit pointer interpretation. func_00291308 takes position/color plus radius/spread in f12/f13, and returns an int32 index or -1. Range captures now occur after first-time initialization. The light offset is really cleared before its XYZ stores. Each light-field write reloads the current slot after the transform call, as retail does; this changes3064 to3168 bytes with the retail0x110 frame. Target CFG, state/global bases, packet and table-index allocation still differ.
 * Reopen with independent target-state CFG and real global-owner evidence, or measured acquisition/firing pointer lifetimes. Preserve complete damage storage, actual call banks and per-write light-slot reloads.
 */
#include "common.h"
typedef float Vector[4] __attribute__((aligned(16)));
struct Rac2Native_5f824a0e369ccf7b_src_record { u8 b0,b1,b2,b3; u16 s4,s6,s8,s10,s12; u8 e,f; };
extern struct Rac2Native_5f824a0e369ccf7b_src_record D_L00_00294980[],D_L00_00294A00[];
extern int D_0018B064 NOT_SDA,D_0018B320 NOT_SDA,D_0018C0B4 NOT_SDA,D_0018C354 NOT_SDA,D_00189FF8 NOT_SDA;
extern char *D_0018C0B0 NOT_SDA,*D_0018AA18 NOT_SDA;
extern u8 D_0018C0DC NOT_SDA,D_0018C0D8 NOT_SDA,D_00139586 NOT_SDA;
extern short D_0018C30C NOT_SDA,D_0018C8DC NOT_SDA;
extern unsigned int D_0018C8E0 NOT_SDA,D_0018C8E4 NOT_SDA,D_001A7390 NOT_SDA,D_001A79F0 NOT_SDA;
extern unsigned int D_00138320 NOT_SDA,D_00138324 NOT_SDA,D_0018B050 NOT_SDA;
extern int D_L00_001A8F00 NOT_SDA,D_L00_001B2874 __attribute__((sda));
extern float D_L00_001B2868 NOT_SDA,D_L00_001B286C __attribute__((sda)),D_L00_001B2870 NOT_SDA;
extern unsigned int D_L00_001AF6C0 __attribute__((sda)),D_L00_001AF6C4 __attribute__((sda));
extern unsigned int D_L00_001AF6C8 __attribute__((sda)),D_L00_001AF6CC __attribute__((sda));
extern float D_00189EA0[4],D_0018A550[4],D_0018A580[4];
extern float D_0018A594 NOT_SDA,D_0018A598 NOT_SDA;
extern float D_L00_001B8DC0[4];
extern char *D_L00_001C3280[];
typedef struct { char prefix[0x50]; float speed,rate; char middle[0x18]; float damage; char tail[0x6C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
typedef struct { float radius,spread,power,reserved; float position[4]; } MuzzleLight;
extern MuzzleLight D_L00_001C6F40[];
extern void func_L00_003A7AF0(char *),func_0029FCC0(char *,int,char *);
extern void func_00282D30(void *,void *,float),func_00282CC0(void *,void *,void *),func_00282CF0(void *,void *,void *),func_00282F20(void *,void *,float);
extern int func_00282978(void *),func_00282948(void *),func_002829D8(void *),func_002AB1F0(u8 *),func_002ABB78(char *);
extern void func_002AF000(float *,float,float,float);
extern char *func_L00_00324D18(void *,void *,int,float,float,float,float,float);
extern int func_L00_002D4040(int),func_L00_002D3F30(int,int);
extern void func_00273318(void *,unsigned int,void *,int,int,int,float,float,float);
extern float func_00282E48(void *,void *),func_00282C48(float),func_00283CE0(int);
extern void func_002A75E0(void *,int,int,int,int),func_002A7470(void *,int,int,int),func_L00_002C42E0(int,int);
extern void func_L00_003A78B0(void *),func_L00_003E4968(void *),func_L00_002AF568(void),func_L00_002AF7D0(void);
extern int func_00291308(void *,unsigned int,float,float),func_002E5DA0(int,int,char *,int),func_002E5CF8(int,int,char *);
extern int func_L00_002D6998(struct Rac2Native_5f824a0e369ccf7b_src_record *),func_L00_002D6978(int);
extern void func_L00_003E2180(void *,char *,char *,float),func_L00_0041EB38(void *,char *,char *);
extern int func_00277F48(void *,int,void *,void *,float);
extern void func_002A8E20(void *,void *),func_002AFFD8(char *,char *,int),func_L00_003E3258(void *,int,int);
extern void func_L00_002D6B70(void),func_00291450(int),func_00283098(void *,void *,void *);

/* Acquire a target, fire either weapon variant and maintain its light effects. */
void func_L00_003A6C30(char *moby)
{
    char *state = *(char **)(moby + 0x68);
    Vector muzzle,targetPosition,playerPoint,offset,direction,center;
    char damage[0x30] __attribute__((aligned(16)));
    char *target = 0;
    float previousRange, horizontal, vertical;
    int specialMode = D_0018B064 == 3;
    if (D_L00_001A8F00 == 8)
        return;
    if (*(u8 *)(moby + 0x20) == 0) {
        *(u8 *)(moby + 0x20) = 2;
        func_L00_003A7AF0(moby);
    }
    horizontal = D_L00_001B2868;
    previousRange = D_L00_001B286C;
    D_L00_001B286C = *(short *)(moby + 0xAA) == 0x5D2 ? 20.0f : 30.0f;
    if (*(short *)(moby + 0xAA) == 0x5D2)
        func_0029FCC0(moby,0,(char *)muzzle);
    else {
        func_00282D30(muzzle,moby + 0xD0,-1.3f);
        func_00282CC0(muzzle,muzzle,moby + 0x10);
    }
    *(float *)(state + 0x14) = muzzle[0];
    *(float *)(state + 0x18) = muzzle[1];
    *(float *)(state + 0x1C) = muzzle[2];
    func_00282D30(playerPoint,D_0018C0B0 + 0xE0,0.75f);
    func_00282CC0(playerPoint,D_00189EA0,playerPoint);
    vertical = D_L00_001B2870;
    D_L00_001B2868 = D_L00_001B2870 = 0.1047197655f;
    *(int *)(state + 0x2C) = 0;
    func_00282978(state + 6);
    if (*(char **)state) {
        char *locked = *(char **)state;
        float *component = (float *)func_002AB1F0((u8 *)locked);
        if (component) {
            func_00282D30(offset,locked + 0xE0,*(float *)((char *)component + 0x10));
            func_00282CC0(targetPosition,locked + 0x10,offset);
        } else {
            qcopy(targetPosition, (locked + 0x10));
        }
        if (*(u8 *)(locked + 0x20) != 0xFE && *(u8 *)(locked + 0x20) != 0xFD &&
            (!component || *component > 0.0f || func_002ABB78(locked)) && *(u8 *)(locked + 0x31) && !D_0018C30C) {
            target = locked;
            D_0018AA18 = locked;
        } else {
            *(short *)(state + 4) = -1;
            *(int *)state = 0;
            *(int *)(state + 8) = 0;
        }
    }
    if (!D_0018B320) {
        if (*(u8 *)(moby + 0x20) == 1 && !D_0018C30C && *(short *)(state + 6) == 0) {
            char *candidate;
            func_002AF000(offset,1.0f,D_0018A598,D_0018A594);
            candidate = func_L00_00324D18(playerPoint,offset,1,vertical,horizontal,previousRange,0.7853982449f,0.6108652949f);
            if (!candidate) {
                *(int *)state = 0;
                *(short *)(state + 4) = -1;
                *(int *)(state + 8) = 0;
                target = 0;
                *(int *)(state + 0x34) = *(short *)(moby + 0xAA) == 0x5D2 ? D_L00_001AF6C4 : D_L00_001AF6CC;
            } else if (candidate != *(char **)(state + 0x30)) {
                *(int *)(state + 0x34) = *(short *)(moby + 0xAA) == 0x5D2 ? D_L00_001AF6C4 : D_L00_001AF6CC;
            } else if (func_00282948(state + 0x34)) {
                float *component;
                *(char **)state = candidate;
                *(short *)(state + 4) = *(short *)(candidate + 0xAA);
                *(int *)(state + 8) = 0;
                *(short *)(state + 6) = *(short *)(moby + 0xAA) == 0x5D2 ? D_L00_001AF6C0 : D_L00_001AF6C8;
                component = (float *)func_002AB1F0((u8 *)candidate);
                if (component) {
                    *(float *)(state + 8) = *(float *)((char *)component + 0x10);
                    func_00282D30(direction,candidate + 0xE0,*(float *)((char *)component + 0x10));
                    func_00282CC0(targetPosition,candidate + 0x10,direction);
                } else {
                    qcopy(targetPosition, (candidate + 0x10));
                }
                target = candidate;
            }
            *(char **)(state + 0x30) = candidate;
        }
    } else {
        *(int *)state = 0;
    }
    if (D_0018C0B4 == 29 || D_0018B320) {
        unsigned int color = 0x600FFF0F;
        if (*(float *)(state + 0xC) > 0.0f && func_L00_002D4040(-1))
            color = 0x600000FF;
        func_00273318(moby,color,0,0x26,-1,4,1.0f,0.0f,90.0f);
    }
    if (*(char **)state) {
        float distance = func_00282E48(D_L00_001B8DC0,targetPosition);
        func_00273318(moby,0xFF0FFF0F,targetPosition,0x26,-1,4,
                      func_00282C48(0.9f - distance * 0.006666667f * 0.65f),0.0f,90.0f);
    }
    if (*(int *)(state + 0x28) > 0 &&
        (*(int *)(state + 0x28) > 8 || !(D_00138320 & D_0018B050) || !func_L00_002D4040(-1)))
        (*(int *)(state + 0x28))--;
    if (*(u8 *)(moby + 0x42) == *(u8 *)(moby + 0x43) && (*(u8 *)(moby + 0x60) & 2))
        func_002A75E0(moby,1,0,2,0);
    if (*(u8 *)(moby + 0x20) == 1) {
        int ready = 1;
        if (D_0018C0B4 == 1)
            func_L00_002C42E0(29,1);
        if (D_0018C0B4 == 29)
            ready = func_00282948(&D_0018C354) != 0;
        else
            D_0018C354 = 40;
        if (func_002829D8(state + 0xC) && !D_0018C0DC && (D_00138320 & D_0018B050) && ready) {
            if (func_L00_002D3F30(-1,1)) {
                int count,i;
                D_L00_001B2874 = 1;
                if (D_0018C8DC != -1)
                    D_0018C8DC++;
                if (D_0018C8E0 < D_001A7390)
                    D_0018C8E0 = D_001A7390;
                D_0018C8E4 |= (1U << (D_001A79F0 & 31)) | 0x80000000U;
                if (*(short *)(moby + 0xAA) == 0x5D2)
                    func_L00_003A78B0(moby);
                else
                    func_L00_003E4968(moby);
                if (*(short *)(state + 0x10) == 0) {
                    func_L00_002AF568();
                    *(short *)(state + 0x10) = 1;
                }
                if (*(u8 *)(moby + 0x43) != 2)
                    func_002A7470(moby,2,0,0);
                if (*(int *)(state + 0x24) == -1)
                    *(int *)(state + 0x24) = func_00291308(moby + 0x10,0,4.0f,0.0f);
                *(int *)(state + 0x28) = 10;
                func_002E5DA0(0,0,moby,*(short *)(moby + 0xAA));
                if (*(short *)(moby + 0xAA) == 0x5D2)
                    func_L00_002D6998(D_L00_00294980);
                else if (*(int *)(state + 0x3C) < 0)
                    *(int *)(state + 0x3C) = func_L00_002D6998(D_L00_00294A00);
                if (*(short *)(moby + 0xAA) == 0x5D2)
                    func_L00_003E2180(muzzle,moby,target,previousRange);
                else
                    func_L00_0041EB38(muzzle,moby,target);
                *(float *)(state + 0xC) = 1.0f / D_L00_00262570[D_00139586].rate;
                count = func_00277F48(muzzle,0,moby,0,0.5f);
                for (i = 0; i < count; i++) {
                    char *hit = D_L00_001C3280[i];
                    float *component;
                    if (hit == D_0018C0B0)
                        continue;
                    component = (float *)func_002AB1F0((u8 *)hit);
                    if (!component)
                        continue;
                    *(int *)(damage + 0x14) = 0x10000;
                    *(int *)(damage + 0x20) = 1;
                    *(float *)(damage + 0x1C) = D_L00_00262570[D_00139586].damage;
                    *(char **)(damage + 0x10) = moby;
                    func_00282CF0(offset,hit + 0x10,muzzle);
                    func_00282F20(offset,offset,D_L00_00262570[D_00139586].speed * (1.0f / 60.0f));
                    qcopy(damage, offset);
                    func_00282F20(damage,damage,1.0f);
                    *(short *)(damage + 0x1A) = *(short *)(moby + 0xAA);
                    *(u8 *)(damage + 0x18) = 1;
                    *(u8 *)(damage + 0x19) = 1;
                    *(float *)(damage + 0xC) = 5627.9248046875f;
                    func_002A8E20(hit,damage);
                    func_002AFFD8(hit + 0x10,(char *)direction,1);
                    func_00282D30(direction,direction,*(float *)((char *)component + 0x10));
                    func_00282CC0(center,direction,hit + 0x10);
                    func_L00_003E3258(center,0x19,1);
                }
            } else {
                if ((D_00138324 & D_0018B050) || D_L00_001B2874 == 1) {
                    func_002E5CF8(1,0,moby);
                    D_L00_001B2874 = 0;
                }
                *(float *)(state + 0xC) = 1.0f / D_L00_00262570[D_00139586].rate;
            }
        }
        if (!((D_00138320 & D_0018B050) && func_L00_002D4040(-1) && D_0018C0D8)) {
            if (*(int *)(state + 0x3C) >= 0) {
                func_L00_002D6B70();
                *(int *)(state + 0x3C) = -1;
            }
        }
        if (*(int *)(state + 0x3C) > 0 && !func_L00_002D6978(*(int *)(state + 0x3C) - 1))
            *(int *)(state + 0x3C) = -1;
        if (!((D_00138320 & D_0018B050) && func_L00_002D4040(-1)) &&
            !(D_00189FF8 < 10 && D_0018C0D8)) {
            func_L00_002AF7D0();
            *(short *)(state + 0x10) = 0;
        }
    } else if (*(u8 *)(moby + 0x20) == 2) {
        func_L00_002AF7D0();
        if (func_002829D8(state + 0xC))
            *(u8 *)(moby + 0x20) = 1;
    }
    if (*(int *)(state + 0x24) != -1) {
        if (!specialMode && *(int *)(state + 0x28) > 0) {
            float ratio,total;
            qzero(offset);
            offset[0] = 2.0f; offset[2] = 2.0f;
            func_00283098(offset,offset,D_0018A550);
            D_L00_001C6F40[*(int *)(state + 0x24)].position[0] = D_00189EA0[0] + offset[0];
            D_L00_001C6F40[*(int *)(state + 0x24)].position[1] = D_00189EA0[1] + offset[1];
            D_L00_001C6F40[*(int *)(state + 0x24)].position[2] = D_00189EA0[2] + offset[2];
            D_L00_001C6F40[*(int *)(state + 0x24)].position[3] = 4.0f;
            ratio = func_00283CE0(*(int *)(state + 0x28));
            total = func_00283CE0(10);
            ratio /= total;
            D_L00_001C6F40[*(int *)(state + 0x24)].radius = ratio;
            D_L00_001C6F40[*(int *)(state + 0x24)].spread = ratio * 0.5f;
            D_L00_001C6F40[*(int *)(state + 0x24)].power = D_L00_001C6F40[*(int *)(state + 0x24)].spread;
        } else {
            func_00291450(*(int *)(state + 0x24));
            *(int *)(state + 0x24) = -1;
        }
    }
}
