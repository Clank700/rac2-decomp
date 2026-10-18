extern int func_00282978(short *);
extern void func_00282CC0_17(char *, char *, char *);
extern void func_002B9180(void *);
extern unsigned char *D_001F2608[];
extern float D_001AA384 __attribute__((sda));

void func_002C1FC0(char *self)
{
    char *state = self + 32;
    if (func_00282978((short *)(self + 10)))
        *(float *)(state + 8) -= *(float *)(state + 24);
    func_00282CC0_17(self + 16, self + 16, state);
    self[8] = (unsigned char)self[8] + *(unsigned char *)(state + 20);
    if ((unsigned char)self[2] == D_001F2608[0][0])
        *(float *)(self + 12) += D_001AA384 * 3500.000244140625f;
    if (*(float *)(self + 24) < *(float *)(state + 16))
        func_002B9180(self);
}

extern float D_001AA380 __attribute__((sda));

void func_002C1B38(char *self)
{
    char *motion = self + 0x20;
    func_00282CC0_17(self + 0x10, self + 0x10, motion);
    if (*(float *)(self + 0x10) < 2.0f || *(float *)(self + 0x10) > 1021.0f ||
        *(float *)(self + 0x14) < 2.0f || *(float *)(self + 0x14) > 1021.0f ||
        *(float *)(self + 0x18) < 2.0f || *(float *)(self + 0x18) > 1021.0f) {
        func_002B9180(self);
        return;
    }
    *(float *)(self + 0x0C) += *(float *)(motion + 0x10);
    *(unsigned char *)(self + 8) += 1;
    if (*(float **)(motion + 0x14))
        *(float *)(self + 0x18) = **(float **)(motion + 0x14) + D_001AA380;
    if (--*(short *)(self + 0xA) == 0) {
        *(int *)(self + 4) -= 0x01000000;
        *(short *)(self + 0xA) = 4;
    }
    if ((*(unsigned int *)(self + 4) & 0xFF000000) == 0)
        func_002B9180(self);
}
