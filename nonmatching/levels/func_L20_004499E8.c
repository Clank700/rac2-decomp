/* Near miss from src/levels/20_yeedil/L20_0043ECB0.c: the build refuses this body at its
   place — 132 bytes, expected 140. Kept as a starting point;
   not linked, not counted. */
extern void func_L20_004499E8(char *, char *, char *);
extern void func_L20_0039BDF0(char *, char *, int, int);

int func_L20_00443328(char *arg0, char *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    char *p = D_L20_001B2F9C + (*(int *)(state + 0x238) << 8);

    if (func_L03_003CA138(p) != 0) {
        func_L20_004499E8(p, arg0, arg1);
        func_L20_0039BDF0(p, p + 0x10, 0x168, 0);
        return (int)p;
    }
    return 0;
}
