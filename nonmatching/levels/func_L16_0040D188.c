/* func_L16_0040D188 (208 bytes, 1 place, level 16) -- structure transcribed, NOT
   compiled: the unit needs a $gp access this file's profile cannot give (see below).

   The inner walk is the "0x7FFF-masked id list" skeleton the lead circulated, and
   its instruction shape matches the already-matched
   src/levels/01_oozla/L01_003CAFE0-g8.c word for word: `do { e = base + ((*p &
   0x7FFF) << 8); ... } while (*(s16 *)p++ >= 0);` produces retail's
   `lh $v0,-0x2($a1)` + `bgezl $v0,body` + `lhu $v0,0x0($a1)` delay slot here too.

   Retail, in order:
     40D188  a2 = arg0
     40D18C  if (a2[0x21] == 0xFF) return
     40D19C  p = (u16 *)D_001FB660[a2[0x21]];        /* 0x1FB660, u32 table */
     40D1AC  goto test
     body 40D1B8
             e = D_001B2B1C + ((*p & 0x7FFF) << 8);   /* base is a POINTER global,
                                                        loaded from 0x1B2B1C */
             if (e == 0) return
             c = *(s16 *)(e + 0xAA);
             if (c == 0xF35)  *(u32 *)(*(u8 **)(e + 0x68) + 0x244) = 1;
             else if (c == 0xEA3) *(u32 *)(*(u8 **)(e + 0x68) + 0x24C) = 1;
             p++;
     test 40D208
             if (a2[0x21] == 0xFF) return
             if (D_<gp+0x3B48> < a2[0x21]) return
             if (p == 0) return
             if (*(s16 *)(p - 1) >= 0) goto body        /* the do/while condition */
             if (p == (u16 *)D_001FB660[a2[0x21]]) goto body   /* head reloaded */
             return

   Two traps for whoever takes this:
     - the index a2[0x21] is RE-READ at both tests because the body stores through
       `*(u8 **)(e + 0x68)`, so this cc1 cannot prove they do not alias; that is
       what puts the extra tests between the loop top and the do/while condition;
     - the bound at 40D214 is a `lw $v0,0x3B48($gp)` access, so the unit needs
       GPREL16: an `-G8` file with a sized, <= 8-byte `sda` symbol (wave 6's rule).
       Level 16's L16_00403900.c holds many other functions of this lot, so this
       one probably belongs in its own `L16_...-g8.c` unit rather than changing the
       file's profile. */
