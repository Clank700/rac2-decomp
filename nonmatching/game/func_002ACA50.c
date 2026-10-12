/* From src/game/002AA800.c: links at 2 of 28 places (instruction at +0x4 differs). */
/* shared native body of family 354e785cbdee35b5 */
void func_002ACA50(int param_1, short *param_2, short param_3)
{
    int i;

    param_1 = (param_1 - *(int *)0x001B359C) << 8 >> 16;
    for (i = 1; i <= param_2[0]; i++) {
        if (param_2[i] == param_1) return;
    }
    if (param_2[0] < param_3) {
        param_2[0] = param_2[0] + 1;
        param_2[param_2[0]] = param_1;
    }
}
