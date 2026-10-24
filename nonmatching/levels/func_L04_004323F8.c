/* func_L04_004323F8: complete retained C, 312 retail bytes.
 * Profile: game compiler -O2 -G0 -ffunction-sections.
 * Local checks in shared/L04_00417308.c: US, US2 and PAL each 5/5, exit0.
 * Full --strict builds reject the generated .rodata jump-table dependency:
 * the table cannot be placed as C with the current linker policy. No match
 * credit is claimed. This extracted standalone source was not recompiled.
 * Reopen only with qualified generated-data placement support or a new
 * ordinary-C source hypothesis; no fake aliases or computed-goto gadgets.
 */

unsigned int func_L04_004323F8(float angle, float saturation, float value, int alpha)
{
    float sector = angle * 0.1591549367f * 6.0f;
    int index = (int)sector;
    unsigned int high, low, falling, rising, color;

    high = (int)(value * 255.0f);
    /* This grouping preserves the retail single-precision rounding. */
    low = (int)(value * ((1.0f - saturation) * 255.0f));
    sector -= index;
    falling = (int)(value * ((1.0f - saturation * sector) * 255.0f));
    rising = (int)(value * ((1.0f - saturation * (1.0f - sector)) * 255.0f));
    switch (index) {
    case 0:
        color = high | (rising << 8) | (low << 16);
        break;
    case 1:
        color = falling | (high << 8) | (low << 16);
        break;
    case 2:
        color = low | (high << 8) | (rising << 16);
        break;
    case 3:
        color = low | (falling << 8) | (high << 16);
        break;
    case 4:
        color = rising | (low << 8) | (high << 16);
        break;
    case 5:
        color = high | (low << 8) | (falling << 16);
        break;
    default:
        color = 0;
        break;
    }
    return ((unsigned int)alpha << 24) | color;
}
