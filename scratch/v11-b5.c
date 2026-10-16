/* worker lvl6-11 -- round 5: symbol constants for L12_004254A8, switch/if shapes for L02_003FC1B0. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* ---------------- func_L12_004254A8 ---------------- */
extern s32 func_002ACBC8(s32);
extern void func_002A7750(void *, s32, s32);
extern u8 D_L12_00189EA0[];
extern u8 D_L12_001395DB;

/* b6: both level addresses as file symbols (sign-adjusted %hi/%lo pair) */
void b6(u8 *a0) {
    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    if (*(s32 *)*(u8 **)(a0 + 0x68) == -1)
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* b7: same, with the field value in a named local */
void b7(u8 *a0) {
    s32 v;

    if (*(u8 *)(a0 + 0x20) != 0)
        return;
    v = *(s32 *)*(u8 **)(a0 + 0x68);
    if (v == -1)
        return;
    if (func_002ACBC8((s32)D_L12_00189EA0) == 0)
        return;
    D_L12_001395DB = 1;
    func_002A7750(a0, 1, -1);
}

/* ---------------- func_L02_003FC1B0 ---------------- */
/* c4: if/else chain laid out exactly like the retail decision tree */
s32 c4(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    if (a1 == 0xA44)
        return 0xA44;
    if (a1 < 0xA45) {
        if (a1 == 0x9CA)
            return ++v1[0x14];
        return 0x9CA;
    }
    if (a1 == 0xC3B)
        return ++v1[0x16];
    if (a1 < 0xC3C) {
        if (a1 == 0xB22)
            return ++v1[0x15];
        return 0xB22;
    }
    if (a1 == 0xC3E)
        return ++v1[0x17];
    return 0xC3E;
}

/* c5: same chain with one result variable */
s32 c5(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);
    s32 r;

    if (a1 == 0xA44)
        r = 0xA44;
    else if (a1 < 0xA45)
        r = (a1 == 0x9CA) ? ++v1[0x14] : 0x9CA;
    else if (a1 == 0xC3B)
        r = ++v1[0x16];
    else if (a1 < 0xC3C)
        r = (a1 == 0xB22) ? ++v1[0x15] : 0xB22;
    else if (a1 == 0xC3E)
        r = ++v1[0x17];
    else
        r = 0xC3E;
    return r;
}

/* c6: switch, cases in the retail tree order, no default */
s32 c6(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    switch (a1) {
    case 0xA44:
        return 0xA44;
    case 0x9CA:
        return ++v1[0x14];
    case 0xB22:
        return ++v1[0x15];
    case 0xC3B:
        return ++v1[0x16];
    case 0xC3E:
        return ++v1[0x17];
    }
    return 0xA44;
}

/* c7: switch without the extra constants, void-ish tail */
s32 c7(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);
    s32 r = 0xA44;

    switch (a1) {
    case 0x9CA:
        r = ++v1[0x14];
        break;
    case 0xB22:
        r = ++v1[0x15];
        break;
    case 0xC3B:
        r = ++v1[0x16];
        break;
    case 0xC3E:
        r = ++v1[0x17];
        break;
    }
    return r;
}

/* c8: increment then read back (post-increment spelling) */
s32 c8(u8 *a0, s32 a1) {
    s32 *v1 = *(s32 **)(a0 + 0x68);

    if (a1 == 0xA44)
        return 0xA44;
    if (a1 < 0xA45) {
        if (a1 == 0x9CA) {
            v1[0x14]++;
            return v1[0x14];
        }
        return 0x9CA;
    }
    if (a1 == 0xC3B) {
        v1[0x16]++;
        return v1[0x16];
    }
    if (a1 < 0xC3C) {
        if (a1 == 0xB22) {
            v1[0x15]++;
            return v1[0x15];
        }
        return 0xB22;
    }
    if (a1 == 0xC3E) {
        v1[0x17]++;
        return v1[0x17];
    }
    return 0xC3E;
}
