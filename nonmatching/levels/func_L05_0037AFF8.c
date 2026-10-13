/* Near miss from src/levels/shared/L05_0037AEC0-g8.c: the build refuses this body at its
   place — 176 bytes, expected 272. Kept as a starting point;
   not linked, not counted. */
extern void func_L05_0037AFF8(char *object);

extern void func_L05_0037B108(void);

extern void func_L05_0037AEC0(char *object, int flag);

/* Shuts every live entry down, then clears the two spawn slots and the pending count. */
void func_L05_0037B210(void)
{
    int i;

    for (i = 0; i < D_L05_001AC4D8; i++)
        func_L05_0037AFF8((char *)D_L05_00225DD0[i]);
    D_L05_00221D10[4] = 0;
    D_L05_00221D10[3] = 0;
    func_L05_0037B108();
}
