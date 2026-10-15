/* Not attempted to completion in this run; the reconstruction below is the
 * part that was decoded and it is believed correct, but it was never
 * compiled - treat it as a starting point, not a candidate.
 *
 * src/core/001253A8.c line 54. sceCdRead, named by its own two debug strings
 * "call cdread cmd" (D_0013B2E0) and "cdread end" (D_0013B2F8) and by RPC #1
 * on the N-command client D_00137550. Frame 0x80; s3 = arg0 (bsize),
 * s1 = arg1 (lsn), s4 = arg2 (mode), s0 = arg3 (the 3-byte command data).
 *
 *   1. if ((D_001363B4 & 1) == 0 && func_00124AF0() == 6) return 0;
 *   2. if (func_00124980(4) == 0) return 0;      /* N-command guard */
 *   3. build the command at D_00136480: +0 bsize, +4 lsn, +8 mode,
 *      +0xC/+0xD/+0xE = buff[0..2], +0x10 = D_00137480 (send buffer),
 *      +0x14 = D_00137540;
 *   4. select the read command from buff[2]: 1 -> 0x918, 2 -> 0x924,
 *      and `mult` it against lsn -- note the R5900 three-operand form, rd set;
 *   5. if ((D_001363B4 & 2) == 0) { D_00137540 = 0; func_0011CEC8(mode, ...); }
 *      then func_0011CEC8 (sceSifWriteBackDCache) over 0x90 bytes at
 *      D_00137480, 0x18 at D_00136480 and 4 at D_00137540;
 *   6. if (D_00136390 > 0) func_0011C820 (Kprintf) with "call cdread cmd";
 *   7. D_001363D4 = D_001363B0 = 1; sceSifCallRpc(func_0011D620) with
 *      a0 = 0x137550, a1 = 1, a2 = 1, a3 = 0x136480, t0 = 0x18, t1 = 0,
 *      t2 = 0, t3 = 0x1246E0, 0(sp) = 0x137480;
 *   8. on failure clear the two flags and func_0011AC40(D_001363A8), return 0;
 *      on success, if (D_00136390 > 0) Kprintf("cdread end"), return 1.
 *
 * Why it stopped: 480 bytes of SDK from disassembly, and the run's remaining
 * budget was needed to bank the two functions that did land plus these
 * near-misses. The flag pairs and the exact Kprintf guards are the parts to
 * re-measure first; everything else above is instruction-level.
 *
 * rac1's src/core/00121750.c is the same object (sceCdRead) one RAC earlier
 * and carries two matched siblings, func_00121930 (sceCdGetError) and
 * func_001219C8 (sceCdBreak), which give the S-command / RPC / SignalSema
 * idiom and the "failure path first" layout the source needs.
 */
