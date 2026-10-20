/* 248-byte near miss; retail is 248 bytes. Every instruction matches except the high half of the table pointer and the order of the two table loads: this cc1 loads D_001B1C54 through $a0 and reads the index first, where retail loads it into $s0 (its destination) and reads the pointer first. Neither the statement order, the declaration nor the index spelling changed it. */
typedef int V4_Fb6552688 __attribute__((mode(TI)));
extern float func_002A7940(void);
extern float func_00283180(float a0);
extern float func_00283198(float a0);
extern float func_002A7878(float a0, float a1);
extern char *D_001B1C54;
extern int D_00214F90[];
extern int func_002ED688(unsigned char *owner);
extern void func_00282CC0_26(char *, V4_Fb6552688 *, char *);
extern void func_002EE988(char *);

void func_002EE7B8(unsigned char *owner)
{
    char *object;
    char *table;
    float a;
    float b;

    object = (char *)func_002ED688(owner);
    if (object == 0)
        return;
    table = D_001B1C54 + D_00214F90[0] * 128;
    a = func_00283180(func_002A7940()) * func_002A7878(0.0f, *(float *)table);
    *(float *)(object + 0x60) = a;
    b = func_00283198(func_002A7940()) * func_002A7878(0.0f, *(float *)table);
    *(float *)(object + 0x68) = 0.0f;
    *(float *)(object + 0x64) = b;
    func_00282CC0_26(object + 0x60, (V4_Fb6552688 *)(table + 0x30), object + 0x60);
    *(float *)(object + 0x68) = func_002A7878(-64.0f, 64.0f) + *(float *)((char *)owner + 0x18);
    func_002EE988((char *)owner);
    *(int *)(object + 0x130) = 300;
}
