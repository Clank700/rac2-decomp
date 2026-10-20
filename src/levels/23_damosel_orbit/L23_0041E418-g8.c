#include "include_asm.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef int s32;

/* the selected state object, and the two candidate pointers beside it */
extern u8 *D_L23_001B1484 __attribute__((sda));

/* the same word read through an absolute access */
extern u8 *D_L23_001B1484_2;

extern s32 D_L23_001B1958 __attribute__((sda));

extern s32 D_L23_001B1954 __attribute__((sda));

extern s32 D_0018C0B0 __attribute__((nosda));

extern s32 D_L23_001B1430 __attribute__((sda));

extern s16 D_L23_001B1B94 __attribute__((sda));

extern s16 D_L23_001B1B96 __attribute__((sda));

extern void func_00291450(s32);

extern void func_L00_002E6CF0(void *, void *);

extern void func_L23_0042AD10(void *);

extern void func_L23_0042AD90(void *);

extern void func_L23_0042ADB0(void);

extern void func_L23_00429DC8(void *);

extern void func_L23_00429FF8(void *);

extern void func_L23_0042A8C0(void *);

extern void func_L23_0042A018(void *);

extern void func_L23_0042A438(void *);

extern s32 func_L23_0041B948(void);

extern s32 func_L23_0041C0C0(void);

extern s32 func_L23_0041C0B0(void);

extern float D_L23_001B3930 __attribute__((sda));

/* reports whether the current state object carries byte 0x20 equal to four */
s32 func_L23_0041E548(void) {
    u8 *state = D_L23_001B1484;

    if (state == 0) {
        return 0;
    }
    return state[0x20] == 4;
}

extern s32 D_L23_001B194C __attribute__((sda));

extern s32 D_L23_001B1950 __attribute__((sda));

/* two absolute level words: sized past the $gp limit so each store is a bare symbol through $at */
extern s32 D_L23_001A8AB0[4] __attribute__((sda));

extern s32 D_L23_001A8AC0[4] __attribute__((sda));

extern void func_002E59F8(s32 handle);

extern void func_0029F338(u8 *object);

/* releases the handle of the slot chosen by the key, then the object the slot holds */
void func_L23_00423588(s32 key, s32 flag) {
    s32 *slot;
    s32 handle;
    u8 *obj;
    u8 *v;

    if (key == D_0018C0B0) {
        handle = D_L23_001B194C;
        slot = &D_L23_001B1954;
        if (handle != -1) {
            func_002E59F8(handle);
            D_L23_001B194C = -1;
        }
    } else {
        handle = D_L23_001B1950;
        slot = &D_L23_001B1958;
        if (handle != -1) {
            func_002E59F8(handle);
            D_L23_001B1950 = -1;
        }
    }
    obj = (u8 *)*slot;
    if (obj != 0) {
        if (*(s16 *)(obj + 0xAA) != 0x1190) {
            *slot = 0;
        } else {
            if (flag == 0 && obj[0x20] != 0) {
                return;
            }
            v = *(u8 **)(obj + 0x68);
            D_L23_001A8AB0[0] = 0;
            D_L23_001A8AC0[0] = 0;
            if (*(s16 *)(v + 0x2C) != -1) {
                func_00291450(*(s16 *)(v + 0x2C));
            }
            func_0029F338((u8 *)*slot);
            *slot = 0;
        }
    }
}

/* returns one of the two pinned words, chosen by the measured key */
s32 func_L23_00423698(s32 arg0) {
    s32 *word = &D_L23_001B1958;

    if (arg0 == D_0018C0B0) {
        word = &D_L23_001B1954;
    }
    return *word;
}

/* releases both measured handles and clears them */
void func_L23_0042AC70(void) {
    s16 handle = D_L23_001B1B94;

    if (handle != -1) {
        func_00291450(handle);
        D_L23_001B1B94 = -1;
    }
    handle = D_L23_001B1B96;
    if (handle != -1) {
        func_00291450(handle);
        D_L23_001B1B96 = -1;
    }
}

/* releases the measured handles and seeds the frame */
void func_L23_00429CC0(u8 *arg0) {
    s32 *payload = *(s32 **)(arg0 + 0x68);

    func_L23_00429DC8(arg0);
    if (D_L23_001B1484_2 != 0) {
        if (func_L23_0041B948() != 0) {
            func_L00_002E6CF0((void *)func_L23_0042A018, arg0);
        } else if (func_L23_0041C0C0() != 0) {
            func_L00_002E6CF0((void *)func_L23_0042A438, arg0);
        } else if (func_L23_0041C0B0() != 0) {
            func_L23_0042A8C0(arg0);
        } else {
            payload[1] = 0;
        }
        if (func_L23_0041C0C0() == 0) {
            s16 handle = D_L23_001B1B94;

            if (handle != -1) {
                D_L23_001B3930 = 0.02f;
                func_00291450(handle);
                D_L23_001B1B94 = -1;
            }
        }
        if (func_L23_0041C0B0() == 0) {
            s16 handle = D_L23_001B1B96;

            if (handle != -1) {
                func_00291450(handle);
                D_L23_001B1B96 = -1;
            }
        }
    }
    func_L23_00429FF8(arg0);
}

/* refreshes the two counters around the measured callback */
void func_L23_0042ACC0(void *arg0) {
    func_L23_0042AD10(arg0);
    if (D_L23_001B1484_2 != 0) {
        if (D_L23_001B1430 != 0) {
            func_L00_002E6CF0((void *)func_L23_0042ADB0, arg0);
        }
    }
    func_L23_0042AD90(arg0);
}


extern s32 D_L23_001B3714;

extern s32 D_L23_001B13E8 __attribute__((sda));

extern void func_002E5CF8(int, int, u8 *);

/* publishes the boot stamp once, seeding the shared state first */
void func_L23_0041E570(void) {
    if (D_L23_001B3714 == 0) {
        u8 *state = D_L23_001B1484;

        if (state != 0) {
            func_002E5CF8(0x10, 0, state);
        }
    }
    D_L23_001B3714 = D_L23_001B13E8;
}
