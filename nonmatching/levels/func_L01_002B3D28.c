/* Near miss retained from the interrupted wave 10 worker 08: 516 bytes against 520,
 * 0 of 3 places (01_oozla and its two copies). Last measured with
 *   python scratch/wslcmp.py src/levels/shared/L01_002A7248.c func_L01_002B3D28
 * The tail call to func_002AA3A8 and the final float constant setup are the residue:
 * this cc1 emits the `ori` after the `mtc1` and calls an unbound index.
 * The source marker is restored; this is a starting point, not a match. */

void func_L01_002B3D28(void)
{
    float f20;

    if (*(unsigned char *)(D_L01_00189E20 + 0x22B4) == 0) {
        *(float *)(D_L01_00189E20 + 0x258) = 0.800000011920929f;
        *(float *)(D_L01_00189E20 + 0x25C) = 0.699999988079071f;
        *(float *)(D_L01_00189E20 + 0x260) = 0.44999998807907104f;
    }
    if (*(int *)(D_L01_00189E20 + 0x229C) == 4) {
        if (*(short *)(D_L01_00189E20 + 0x4AC) < *(int *)(D_L01_00189E20 + 0x1B8)) {
            if (*(unsigned char *)(D_L01_00189E20 + 0x49E) == 0)
                *(float *)(D_L01_00189E20 + 0x25C) = *(float *)(D_L01_00189E20 + 0x4B8);
        }
    } else {
        int v1 = *(int *)(D_L01_00189E20 + 0x2294);

        if (v1 == 6)
            *(float *)(D_L01_00189E20 + 0x25C) = 0.5f;
        else if (v1 == 4)
            *(float *)(D_L01_00189E20 + 0x258) = 0.3500000238418579f;
        else if (v1 == 0x7C)
            *(float *)(D_L01_00189E20 + 0x260) = 0.800000011920929f;
    }

    if (*(unsigned char *)(D_L01_00189E20 + 0x287) != 0) {
        if (*(int *)(D_L01_00189E20 + 0x22A4) == 0x12)
            goto tail;
        if (*(int *)(D_L01_00189E20 + 0x22B0) == 0x12)
            goto tail;
        if (*(unsigned char *)(D_L01_00189E20 + 0x22B4) == 0) {
            if (*(float *)(D_L01_00189E20 + 0x254) < 0.5299999713897705f)
                goto tail;
        }
        if (*(int *)(D_L01_00189E20 + 0x229C) == 0x11)
            goto tail;
        if (*(unsigned char *)(D_L01_00189E20 + 0x1494) != 0)
            goto tail;
        if (!(*(float *)(D_L01_00189E20 + 0x264) * 0.5f <
              ref_L01_002B3D28_00(D_L01_00189E20 + 0x240, D_L01_00189E20 + 0x80)))
            return;
    }
tail:
    f20 = 0.019999999552965164f;
    ref_L01_002B3D28_01(D_0018A070, *(float *)(D_L01_00189E20 + 0x258), f20);
    ref_L01_002B3D28_01(D_0018A070 + 4, *(float *)(D_L01_00189E20 + 0x25C), f20);
    ref_L01_002B3D28_02(D_0018A070 + 0x14, D_0018A070 + 0x18,
                        *(float *)(D_L01_00189E20 + 0x260), f20, 0.30000001192092896f,
                        0.06666667014360428f);
}
