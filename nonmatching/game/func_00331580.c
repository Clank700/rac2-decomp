/* near miss, 1 difference: cc1 CSEs the sym address of the post-loop call with the loop one and hoists it into $s2; retail rematerialises it at both calls. Everything else matches. Needs the declarations of src/game/0032EB28.c (f32, s32, u8). */
extern f32 func_002A78D8(f32 low, f32 high);
extern s32 func_00283CF0(f32 value);
extern u8 *func_002C16C0(f32 *pos, void *sym, s32 a2, s32 a3, s32 color, s32 alpha, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16);
extern signed char D_001A8BD0[];
extern u8 *D_001F26B0;

void func_00331580(f32 *pos, f32 scale)
{
    f32 v[3];
    f32 size = scale * 6300.0f;
    u8 *effect;
    s32 i;

    for (i = 1; i >= 0; i--) {
        v[0] = pos[0] + func_002A78D8(0.0f, 0.04f);
        v[1] = pos[1] + func_002A78D8(0.0f, 0.04f);
        v[2] = pos[2] + func_002A78D8(0.0f, 0.04f);
        func_002C16C0(v, D_001A8BD0, 15, 0x5F, 0x7F7F7F, func_00283CF0(func_002A78D8(1.0f, 3.0f)), size, 500.0f, 1.0f, 0.0f, 0.0f);
    }
    effect = func_002C16C0(v, D_001A8BD0, 15, 0x7F, 0x407FFF, func_00283CF0(func_002A78D8(1.0f, -1.0f)), size * 0.8f, 500.0f, 1.0f, 0.0f, 0.0f);
    if (effect != 0) {
        effect[2] = D_001F26B0[5];
    }
}
