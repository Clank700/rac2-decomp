/* from src/core/00130288.c: an IPU/decoder setup - func_12FA98(*(a0+0x858), &mode) with
   mode 2 then 3, two func_12C3B0(s) calls, a zero store to 0x10002000, func_11F5E0 /
   func_11F628 around it, then 0x1000B410 = a2 & 0x0FFFFFFF, 0x1000B420 = 4,
   0x1000B400 = 0x101, and func_12C380(s, a1) with the last func_12FA98 call. No C attempt:
   the mode stores are merged into the call delay slots (a shape measured elsewhere as
   hard to force), and the two `lui $at` hardware stores sit between register-based ones. */
