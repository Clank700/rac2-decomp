/* From src/game/003418C0.c: links at 7 of 28 places (func_L00_004370F8 would be at 0x00443778). */
int func_003418C0(char *self, int arg1)
{
    f32_Fd368add8 *v;

    v = *(f32_Fd368add8 **)(self + 536);
    func_00335E38_1(self, D_L01_001AE3F8 + v[0], D_L01_001AE3FC + v[1], 0.0f, 0.0f);
    v = *(f32_Fd368add8 **)(self + 536);
    func_00335E38_1(self + 152, D_L01_001AE408 + v[0], D_L01_001AE40C + v[1], 0.0f, 0.0f);
    v = *(f32_Fd368add8 **)(self + 536);
    func_00335E38_1(self + 76, D_L01_001AE400 + v[0], D_L01_001AE404 + v[1], 0.0f, 0.0f);
    v = *(f32_Fd368add8 **)(self + 536);
    func_00335E38_1(self + 228, D_L01_001AE410 + v[0], D_L01_001AE414 + v[1], 0.0f, 0.0f);
    v = *(f32_Fd368add8 **)(self + 536);
    func_00335E38_1(self + 464, D_L01_001AE418 + v[0], D_L01_001AE41C + v[1], 0.0f, 0.0f);

    *(int *)func_00335E20_1(self + 304) = func_002A9588(0x60442D00, 0x70FFFEED, 20, 0, 0);
    func_003417D0(self, arg1);
    func_00341760(self);
    func_L00_004370F8(self);
    return *(int *)(self + (*(int *)(self + 764) << 2) + 440);
}
