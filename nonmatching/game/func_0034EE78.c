/* func_0034EE78 (224 bytes, 28 places), closer M2: one word off under -O2 -G0.
 * Cubic Hermite blend. Each term is written back into its own parameter (retail keeps
 * r0..r3 in the parameters' saved FPRs), t3 = t2 * t, and the first term is
 * ((2t3 - 3t2) * p0) + p0. Left: retail's final add of that term is add.s $f21,$f2,$f21
 * (product first); this cc1 swaps the commutative operands to add.s $f21,$f21,$f2 because
 * the target is the parameter itself. A fresh variable for the term breaks the
 * allocation (32 words off); -g, -G8 and four operand orders leave the word as it is. */
extern char D_001AE7A0[];
extern char D_001AE7B8[];
extern void func_00115E38(char *, int, char *);

float func_0034EE78(float t, float p0, float m0, float m1, float p1)
{
    float t2, t3, r0, r1, r2, r3;

    if (!(t >= 0.0f && t <= 1.0f))
        func_00115E38(D_001AE7A0, 0x24, D_001AE7B8);

    t2 = t * t;
    t3 = t2 * t;
    p0 = ((t3 + t3) - (t2 * 3.0f)) * p0 + p0;
    m0 = m0 * ((t3 - (t2 + t2)) + t);
    m1 = m1 * (t3 - t2);
    p1 = p1 * ((t2 * 3.0f) - (t3 + t3));
    return ((p0 + m0) + m1) + p1;
}
