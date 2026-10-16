extern int G1;
extern int G2 __attribute__((sda));
extern int G3 __attribute__((nosda));
int func_00000001(void) { return G1 + G2 + G3; }
