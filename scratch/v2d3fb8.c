/* shape variants for func_L00_002D3FB8 (retail: 136 bytes, 34 instructions) */
typedef struct {
    unsigned char pad0[142];
    unsigned short f8E;
    unsigned char rest[80];
} Entry;

extern int func_2D3FB0(int);
extern unsigned char counts[];
extern Entry table[];
extern int slots[];

int v1(int a0, int a1)
{
    int idx = func_2D3FB0(a0);
    int *slot = &slots[idx];
    int v = *slot + a1;
    Entry *e;
    int ceiling;

    *slot = v;
    e = &table[counts[idx]];
    ceiling = e->f8E;
    if (ceiling == 0)
        return 0;
    if (v - ceiling <= 0)
        return 0;
    *slot = ceiling;
    return v - ceiling;
}

int v2(int a0, int a1)
{
    int idx = func_2D3FB0(a0);
    int *slot = &slots[idx];
    int v = *slot + a1;
    Entry *e;
    int ceiling;

    *slot = v;
    e = &table[counts[idx]];
    ceiling = e->f8E;
    if (ceiling == 0)
        return 0;
    if (v <= ceiling)
        return 0;
    *slot = ceiling;
    return v - ceiling;
}

int v3(int a0, int a1)
{
    int idx = func_2D3FB0(a0);
    int *slot = &slots[idx];
    int v = *slot + a1;
    Entry *e;

    *slot = v;
    e = &table[counts[idx]];
    if (e->f8E == 0 || v - e->f8E <= 0)
        return 0;
    *slot = e->f8E;
    return v - e->f8E;
}

int v4(int a0, int a1)
{
    int idx = func_2D3FB0(a0);
    int *slot = &slots[idx];
    int v = *slot + a1;
    Entry *e;
    unsigned short ceiling;

    *slot = v;
    e = &table[counts[idx]];
    ceiling = e->f8E;
    if (ceiling == 0)
        return 0;
    if (v - ceiling <= 0)
        return 0;
    *slot = ceiling;
    return v - ceiling;
}

int v5(int a0, int a1)
{
    int idx = func_2D3FB0(a0);
    int *slot = &slots[idx];
    int v = *slot + a1;
    Entry *e;
    int ceiling;

    *slot = v;
    e = &table[counts[idx]];
    ceiling = e->f8E;
    if (ceiling != 0 && v - ceiling > 0) {
        *slot = ceiling;
        return v - ceiling;
    }
    return 0;
}
