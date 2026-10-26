/* func_002C36D0 (268 bytes, 28 places): glow particle spawn, 002C3150 family.
   26 October 2026 (M32): 268/268 under the qcopy profile as its own unit; only the
   callee-saved register assignment differs (retail: motion $s0, particle $s1, kind $s2,
   position $s3). In the permuter. */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int colour;
    unsigned char unk08;
    unsigned char unk09;
    short life;
    float unk0C;
    TI128 position;
    struct {
        short fade;
        unsigned char kind;
        unsigned char unk03;
    } motion;
} Particle_002C36D0;

extern Particle_002C36D0 *func_002B9030(int);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern int func_002A77E0(int);
extern unsigned char *D_001F2638;

/* Spawns a fading glow particle of the given kind at position, gone after life
   frames. */
Particle_002C36D0 *func_002C36D0(TI128 *position, int life, int kind, int arg3)
{
    Particle_002C36D0 *p = func_002B9030(0x3E);
    typeof(p->motion) *m = &p->motion;

    if (p != 0) {
        p->position = *position;
        p->colour = 0x7F7F4040;
        p->unk09 = func_00283CF0(4.0f) + 0x40;
        p->unk01 = 0;
        p->unk03 = 0x48;
        p->unk0C = 30000.0f;
        p->unk08 = func_002A77E0(0xFF);
        m->kind = kind;
        m->unk03 = arg3;
        if (kind >= 2)
            kind = 0;
        p->unk02 = D_001F2638[kind];
        m->fade = func_00283CF0(127.0f / func_00283CE0(life));
        p->life = life;
    }
    return p;
}
