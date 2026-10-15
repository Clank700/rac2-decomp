/* func_00121AB8, 96 bytes, boot. A 64-bit multiply helper from the software
   floating-point group (the EE has no FPU): three 32x32 multiplies feed
   HI/LO and one register, and the result is rebuilt with a mask.
   Retail: mult $a0,$v1 ; mult $a2,$a2,$a1 ; multu $a0,$a1 ; mflo/mfhi ; then
   hi32(product) + hi_b + lo32(hi_a*lo_b) forms the high word. The first
   multiply's HI/LO is read by nothing, so the retail build emitted it and then
   overwrote it with multu.
   This candidate is the algebraically correct synthesis; tools/check.py shows
   the same three-multiply family but 24 of 25 words differ. Plain `a * b` is
   not the route at all: both compilers turn it into a `jal __muldi3` libcall.
   Unblocked by a source shape that makes cc1 use the 2-operand signed `mult`
   and the 3-operand `mult1` in one basic block without reading them. */
typedef unsigned int u32x;
typedef signed int s32x;

long long func_00121AB8(long long a, long long b) {
    u32x lo_a = (u32x)a;
    u32x lo_b = (u32x)b;
    s32x hi_a = (s32x)(a >> 32);
    s32x hi_b = (s32x)(b >> 32);
    unsigned long long p = (unsigned long long)lo_a * lo_b;
    s32x high = (s32x)(p >> 32) + hi_a * (s32x)lo_b + (s32x)lo_a * hi_b;

    return (long long)((u32x)p | ((unsigned long long)(u32x)high << 32));
}
