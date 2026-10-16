/* Which spelling makes this compiler reach a symbol through $gp (GPREL16)?
   Compile with -O2 -G0 -ffunction-sections and read the emitted .s: only a
   %gp_rel / $gp access matters here. */
extern int A __attribute__((sda));
extern int B __attribute__((section(".sdata")));
extern int C __attribute__((sda)) __asm__("C_alias");
extern float D __attribute__((sda));
extern int E[4] __attribute__((sda));
extern int F __attribute__((section(".sdata"))) __asm__("F_alias");
extern int G;
extern int *H __attribute__((sda));

int t1(void) { return A; }
int t2(void) { return B; }
int t3(void) { return C; }
float t4(void) { return D; }
int t5(void) { return E[1]; }
int t6(void) { return F; }
int t7(void) { return G; }
int t8(void) { return *H; }
int t9(int v) { A = v; return A; }
