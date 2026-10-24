/* func_L04_00432530: complete retained C, 224 retail bytes.
 * Profile: game compiler -O2 -G0 -ffunction-sections.
 * Local checks in shared/L04_00417308.c: US, US2 and PAL each 5/5, exit0.
 * Full --strict builds reject the generated .rodata jump-table dependency:
 * the table cannot be placed as C with the current linker policy. No match
 * credit is claimed. This extracted standalone source was not recompiled.
 * Reopen only with qualified generated-data placement support or a new
 * ordinary-C source hypothesis; no fake aliases or computed-goto gadgets.
 */

unsigned int func_L04_00432530(float angle, int alpha)
{
    float sector = angle * 0.1591549367f * 6.0f;
    int index = (int)sector;
    unsigned int rising, falling, color;

    sector -= index;
    rising = (int)(sector * 255.0f);
    falling = (int)((1.0f - sector) * 255.0f);
    switch (index) {
    case 0:
        color = (rising << 8) | 255;
        break;
    case 1:
        color = falling | 0xff00;
        break;
    case 2:
        color = (rising << 16) | 0xff00;
        break;
    case 3:
        color = (falling << 8) | 0xff0000;
        break;
    case 4:
        color = rising | 0xff0000;
        break;
    case 5:
        color = (falling << 16) | 255;
        break;
    default:
        color = 0;
        break;
    }
    return ((unsigned int)alpha << 24) | color;
}
