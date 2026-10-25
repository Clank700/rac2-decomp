/* Nonmatching C: Update the object movement, target interaction, child state and drawing callbacks.
 * Tested profile: -O2 -G8 -ffunction-sections.
 * Measured US size: 4444 bytes; retail: 4424 bytes.
 * Placement checks: US and US2: 0/2 each; PAL: absent from the catalogue.
 * Remaining: State dispatch layout, helper-call scheduling and saved-register allocation remain different.
 * Reopen with independent object and Vars vector lifetimes; preserve the canonical grouped helper banks, real returns, full 64-bit dispatch flags and function callbacks.
 */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union Vector {
    Quad q;
    struct { float x, y, z, w; } v;
} Vector;

typedef struct Moby Moby;
typedef struct Vars Vars;
struct Moby {
    char pad00[0x10];
    Vector position;
    unsigned char state;
    char pad21[3];
    char *model;
    char pad28[0xC];
    unsigned short flags;
    char pad36[0xC];
    unsigned char frame, animation;
    char pad44[0x1C];
    unsigned char animationFlags;
    char pad61[7];
    Vars *vars;
    char pad6C[0x29];
    unsigned char mode;
    char pad96[2];
    int draw;
    char pad9C[0xC];
    unsigned char color;
    char padA9;
    short classId;
    char padAC[0x14];
    float matrix[12];
    float rotation[4];
};
struct Vars {
    char pad00[0x20];
    float health;
    short pad24, damageTimer;
    char pad28[8];
    float field30;
    char pad34[0x1FC];
    Vector targetPosition;
    Moby *target;
    char pad244[0x14];
    int field258, field25C;
    char pad260[0x10];
    short timer;
    char pad272[4];
    short triggered;
    char pad278[8];
    float field280, field284;
    int field288;
    float field28C, field290;
    int field294;
    float field298;
    int field29C, counter;
    float field2A4, field2A8;
    Moby *child;
    int field2B0;
    char pad2B4[8];
    int field2BC, effect;
    char pad2C4[0xBC];
    Vector destination;
};

/* Measured partial dispatch view; no whole-context extent is inferred. */
typedef struct {
    u8 reserved_00[0x18]; u8 enabled, count, kind;
    u8 reserved_1b[0x65]; u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
struct family_27f9_object;

extern int D_L00_001A8F00 __attribute__((sda));
extern char D_00188660[];
extern char D_L00_001B0318[];
extern char D_L00_001A8F20[];
extern int func_003216E8(Moby *);
extern void func_0029F338(Moby *);
extern int func_002B3890(Moby *);
extern void *func_002B60B0(u8 *,float,float,float,float);
extern float func_00282C48(float);
extern void func_002A7750(Moby *, int, int);
extern void func_002A7470(Moby *, int, int, int);
extern int func_002A7820(int, int);
extern void *func_002A9640(void *,u32,s32);
extern unsigned long func_002B1C20(void *,Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_002E59F8(int);
extern int func_002E5CF8(int,int,char *);
extern void func_00283098(Vector *, Vector *, float *);
extern void func_00282CC0(Vector *, Vector *, Vector *);
extern u8 *func_0032C700(void *,int,int,int,int,int,int,int,float,float,int,int,int,void *);
extern void func_00322A30(Moby *);
extern void func_002A6C58(Moby *, int, int);
extern void func_002B5258(char *);
extern void func_002AEF28(float *,float *,float *,float,float,float);
extern float func_002A7E08(struct family_27f9_object *,float *,float *,float,float,float);
extern float func_002AA3A8(float *,float *,float,float,float,float);
extern float func_002A89A8(void *,int,float);
extern float func_002AA548(float *,float *,float,float,float,float);
extern void func_0026FEB8(const char *,...);
extern void func_002833F0(float *, float *);
extern void func_00282CF0(Vector *, Vector *, Vector *);
extern float func_00283248(float, float);
extern float func_00282E20(Vector *);
extern float func_002AA458(void *,void *,void *,float,float,float);
extern float func_00282E48(Vector *, Vector *);
extern float func_00282E80(Vector *, Vector *);
extern float func_00283C80(float, float);
extern int func_002B4FF0(char *,float *,float);
extern int func_002B50E0(void *,void *,float);
extern void func_00322690(Moby *,char *,int,float);
extern void func_L00_002E6EF8(void (*)(void *),void *);
extern void func_003225C0(void *);
extern void func_00321E80(char *);
extern void func_00321FE0(void *);

void func_L00_003D54B0(Moby *moby)
{
    Vars *vars = moby->vars;
    Vector position, delta;
    unsigned long hit;
    int index;
    char *damage;
    float height, angle;

    if (func_003216E8(moby)) {
        func_0029F338(moby);
        return;
    }
    if (D_L00_001A8F00 == 2) {
        moby->draw = 0;
        moby->flags = (moby->flags | 0x41) & 0xEFFF;
        return;
    }
    moby->flags = (moby->flags & 0xFFBE) | 0x1000;
    moby->draw = *(int *)(moby->model + 0x10);
    switch (moby->mode) {
    case 0:
        if (func_002B3890(moby))
            func_002B60B0((u8 *)moby, 0.00222222228f, 0.0666666701f, 0.00116355298f, 0.104719773f);
        if (vars->field258 == 1 && vars->field294 &&
            func_00282C48(moby->position.v.z - vars->targetPosition.v.z) < 2.0f && D_L00_001A8F00 != 2) {
            func_002A7750(moby, 11, 4);
            if (moby->animation != 1)
                func_002A7470(moby, 1, 0, 4);
            if (vars->field288 != -1) {
                func_002A7750(moby, 10, 1);
                if (moby->animation != 26)
                    func_002A7470(moby, 26, 0, 4);
            }
        } else if (vars->triggered) {
            func_002A7750(moby, 9, 3);
            vars->triggered = 0;
            if (vars->timer < 300)
                vars->timer = func_002A7820(480, 600);
        }
        break;
    case 2:
        if (func_002B3890(moby))
            func_002B60B0((u8 *)moby, 0.00222222228f, 0.0666666701f, 0.00116355298f, 0.104719773f);
        if (vars->field258 == 1 && vars->field294 && !vars->field2B0) {
            func_002A7750(moby, 5, -1);
            if (moby->animation != 25)
                func_002A7470(moby, 25, 0, 4);
            vars->field2B0 = 1;
        } else if (vars->triggered && vars->field294 && !vars->field2B0) {
            vars->triggered = 0;
            func_002A7750(moby, 5, -1);
            if (moby->animation != 25)
                func_002A7470(moby, 25, 0, 4);
            vars->field2B0 = 1;
        }
        damage = func_002A9640(vars->child, 0x10000, 0);
        if (damage && vars->damageTimer <= 0) {
            vars->health -= *(float *)(damage + 0x2C);
            vars->child->color = 255;
            vars->damageTimer = 15;
            if (!vars->field2B0) {
                func_002A7750(moby, 5, -1);
                if (moby->animation != 25)
                    func_002A7470(moby, 25, 0, 4);
                vars->field2B0 = 1;
            }
            if (vars->health <= 0.0f)
                func_002A7750(moby, 15, 5);
        }
        qcopy(&vars->child->position, &moby->position);
        break;
    case 3:
        if (func_002B3890(moby))
            func_002B60B0((u8 *)moby, 0.00222222228f, 0.0666666701f, 0.00116355298f, 0.104719773f);
        if ((vars->field258 == 1 || vars->field25C == 1) && vars->field294) {
            func_002A7750(moby, 11, 4);
            if (moby->animation != 1)
                func_002A7470(moby, 1, 0, 4);
        } else if (!vars->timer) {
            func_002A7750(moby, 2, 0);
            if (moby->animation != 3)
                func_002A7470(moby, 3, 0, 10);
        }
        break;
    case 4:
        if (func_002B3890(moby))
            func_002B60B0((u8 *)moby, 0.00444444455f, 0.13333334f, 0.00116355298f, 0.104719773f);
        if (vars->field258 != 1 && vars->field25C != 1 && moby->state != 5 && moby->state != 4)
            goto retreat;
        break;
    case 5:
        hit = func_002B1C20(moby, (Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)((char *)vars + 0x60));
        index = vars->effect;
        if (index != -1 && *(Moby **)(D_00188660 + index * 0x70 + 0x88) == moby &&
            *(unsigned char *)(D_00188660 + index * 0x70 + 0x74))
            func_002E59F8(index);
        vars->effect = -1;
        if ((hit & 1) || vars->health <= 0.0f) {
            func_002E5CF8(12, 0, (char *)moby);
            if (vars->child && vars->child->classId == 0xAB7)
                func_0029F338(vars->child);
            position.q = 0;
            moby->draw = 0;
            position.v.z = 0.75f;
            moby->flags = (moby->flags | 0x41) & 0xEFFF;
            func_00283098(&position, &position, moby->matrix);
            func_00282CC0(&position, &position, &moby->position);
            func_0032C700(&position, 0, 5, 5, 5, 0, 0, 0, 0.5f, 20.0f, 1, 0, 0, 0);
            func_00322A30(moby);
            func_002A6C58(moby, 0, 3);
            func_0029F338(moby);
            return;
        }
        if (hit & 2) {
            if (vars->field258 == 1 || vars->field25C == 1) {
                func_002A7750(moby, 12, 4);
                if (moby->animation != 28)
                    func_002A7470(moby, 28, 0, 10);
            } else {
retreat:
                func_002A7750(moby, 9, 3);
                if (moby->animation != 6)
                    func_002A7470(moby, 6, 0, 10);
                vars->timer = func_002A7820(580, 600);
            }
        }
        break;
    }
    switch (moby->state) {
    case 1:
        if (!vars->field2BC)
            func_002B5258((char *)moby);
        break;
    case 3:
        func_002AEF28((float *)moby, &vars->field2A4, &vars->field2A8, 0.069813177f, 0.0523598865f, 0.0130899716f);
        break;
    case 5:
        vars->counter++;
        index = vars->effect;
        if (*(Moby **)(D_00188660 + index * 0x70 + 0x88) != moby ||
            !*(unsigned char *)(D_00188660 + index * 0x70 + 0x74))
            vars->effect = func_002E5CF8(13, 4, (char *)moby);
        func_002A7E08((struct family_27f9_object *)moby, (float *)vars->target, &vars->field28C, 0.001f, 0.01f, 0.1f);
        func_002AA3A8(&moby->rotation[1], &vars->field290, 0.0f, 0.0166666675f, 0.0f, 0.0666666701f);
        func_002AA3A8(&moby->rotation[0], &vars->field290, 0.0f, 0.0166666675f, 0.0f, 0.0666666701f);
        height = func_002A89A8(&moby->position, 0, 0.5f);
        if (moby->position.v.z - height > 0.05f) {
            moby->position.v.z -= height * 0.00025f;
        } else {
            index = vars->effect;
            if (index != -1 && *(Moby **)(D_00188660 + index * 0x70 + 0x88) == moby &&
                *(unsigned char *)(D_00188660 + index * 0x70 + 0x74))
                func_002E59F8(index);
            vars->effect = -1;
            func_002A7750(moby, 8, -1);
            if (moby->animation != 14)
                func_002A7470(moby, 14, 0, 3);
        }
        if (moby->animationFlags & 2) {
            func_002A7750(moby, 4, -1);
            if (moby->animation != 26)
                func_002A7470(moby, 26, 0, 15);
        }
        break;
    case 4:
        vars->counter++;
        func_002A7E08((struct family_27f9_object *)moby, (float *)vars->target, &vars->field28C, 0.001f, 0.01f, 0.1f);
        func_002AA3A8(&moby->rotation[1], &vars->field290, 0.0f, 0.0166666675f, 0.0f, 0.0666666701f);
        func_002AA3A8(&moby->rotation[0], &vars->field290, 0.0f, 0.0166666675f, 0.0f, 0.0666666701f);
        height = func_002A89A8(&moby->position, 0, 0.5f);
        if (moby->position.v.z - height > 0.05f) {
            func_002AA548(&moby->position.v.z, &vars->field280, height - 3.0f, 0.0166666675f, 0.163333341f, 0.166666672f);
        } else {
            func_0026FEB8(D_L00_001B0318, vars->counter);
            index = vars->effect;
            if (index != -1 && *(Moby **)(D_00188660 + index * 0x70 + 0x88) == moby &&
                *(unsigned char *)(D_00188660 + index * 0x70 + 0x74))
                func_002E59F8(index);
            vars->effect = -1;
            func_002A7750(moby, 8, -1);
            if (moby->animation != 14)
                func_002A7470(moby, 14, 0, 3);
            moby->draw = *(int *)(moby->model + 0x10);
            if (vars->child->classId == 0xAB7)
                func_0029F338(vars->child);
            vars->field30 = 0.5f;
            moby->flags |= 0x1000;
        }
        break;
    case 6:
        if (moby->animationFlags & 2) {
            func_002A7750(moby, 7, -1);
            if (moby->animation != 13)
                func_002A7470(moby, 13, 0, 15);
        }
        break;
    case 7:
        func_002AA3A8(&moby->rotation[1], &vars->field290, 0.0f, 0.0166666675f, 0.0f, 0.0666666701f);
        func_002833F0(moby->matrix, moby->rotation);
        func_002A7E08((struct family_27f9_object *)moby, (float *)vars->target, &vars->field28C, 0.001f, 0.01f, 0.1f);
        height = func_002A89A8(&moby->position, 0, 0.5f);
        if (moby->position.v.z - height > 0.05f) {
            func_002AA548(&moby->position.v.z, &vars->field280, height - 3.0f, 0.0250000022f, 0.163333341f, 0.25f);
        } else {
            func_002A7750(moby, 8, -1);
            if (moby->animation != 14)
                func_002A7470(moby, 14, 0, 3);
        }
        break;
    case 8:
        if (moby->animationFlags & 2) {
            func_002A7750(moby, 12, 4);
            if (moby->animation != 28)
                func_002A7470(moby, 28, 0, 15);
            moby->position.v.z = func_002A89A8(&moby->position, 0, 0.5f);
        }
        break;
    case 10:
        qcopy(&position, &vars->destination);
        position.v.z -= 3.0f;
        func_00282CF0(&delta, &position, &moby->position);
        moby->rotation[2] = func_00283248(delta.v.x, delta.v.y);
        moby->rotation[1] = func_00283248(func_00282E20(&delta), delta.v.z);
        func_002833F0(moby->matrix, moby->rotation);
        func_002AA458(&moby->position, &position, &vars->field280, 0.0166666675f, 0.0f, 0.333333343f);
        if (func_00282E48(&moby->position, &position) < 0.4f) {
            if (moby->animation != 13)
                func_002A7470(moby, 13, 0, 10);
            func_002A7750(moby, 7, -1);
        }
        break;
    case 11:
        func_002B5258((char *)moby);
        if (moby->animationFlags & 2) {
            func_002B60B0((u8 *)moby, 0.00111111114f, 0.0333333351f, 0.00116355298f, 0.104719773f);
            func_002A7750(moby, 12, -1);
            if (moby->animation != 28)
                func_002A7470(moby, 28, 0, 15);
        }
        break;
    case 12:
        func_002B60B0((u8 *)moby, 0.00111111114f, 0.0333333351f, 0.00116355298f, 0.104719773f);
        if (func_00282E80(&moby->position, &vars->target->position) < 2.8f) {
            angle = func_00283248(vars->targetPosition.v.x - moby->position.v.x, vars->targetPosition.v.y - moby->position.v.y);
            if (func_00283C80(moby->rotation[2], angle) < 0.383972466f)
                goto checkFrame;
        }
        if (func_00282E80(&moby->position, &vars->target->position) > 2.8f)
            func_002B4FF0((char *)moby, (float *)&vars->targetPosition, vars->field284);
        else {
            angle = func_00283248(vars->target->position.v.x - moby->position.v.x, vars->target->position.v.y - moby->position.v.y);
            func_002B50E0(moby, &moby->position, angle);
        }
checkFrame:
        if (moby->frame == 28)
            func_00322690(moby, D_L00_001A8F20, 4, vars->field298);
        break;
    case 13:
        if (moby->frame == 15)
            func_L00_002E6EF8(func_003225C0, moby);
        angle = func_00283248(vars->target->position.v.x - moby->position.v.x, vars->target->position.v.y - moby->position.v.y);
        func_002B50E0(moby, &moby->position, angle);
        break;
    case 14:
        if (moby->animationFlags & 2) {
            if (func_00282E80(&moby->position, &vars->target->position) > 4.0f) {
                func_002B60B0((u8 *)moby, 0.00444444455f, 0.13333334f, 0.00116355298f, 0.104719773f);
                func_002A7750(moby, 12, -1);
                if (moby->animation != 28)
                    func_002A7470(moby, 28, 0, 10);
            } else {
                func_002B60B0((u8 *)moby, 0.00222222228f, 0.0666666701f, 0.00116355298f, 0.104719773f);
                func_002A7750(moby, 12, -1);
                if (moby->animation != 7)
                    func_002A7470(moby, 7, 0, 10);
            }
        }
        break;
    }
    func_00321E80((char *)moby);
    func_L00_002E6EF8(func_00321FE0, moby);
}
