typedef int s32;

extern float func_002EF240(void);
extern int func_002EF250(float);

s32 func_L00_00329FF0(s32 value)
{
    s32 unit = 16;

    if (value % unit != 0)
        value = (func_002EF250(func_002EF240() / unit) + 1) * 16;
    return value;
}
