# Near misses

C that compiles close to a function but not to its bytes: a starting point, never linked
and never counted. Move a file into `src/` once `tools/build.py` places it.

| Function | Size | Bytes that differ |
| --- | ---: | ---: |
| [`func_0012FB48`](boot/func_0012FB48.c) | 20 | 3 |
| [`func_00278E78`](game/func_00278E78.c) | 48 | C candidate emits 40 bytes; control flow and global address sequence differ |
| [func_00282C50](game/func_00282C50.c) | 8 | 0 of 28 exact; jr ra matches, but retail delay slot is raw 0x460D6029 and C emits abs.s f0,f13 |
| [`func_00288970`](game/func_00288970.c) | 64 | Candidate is 68 bytes; retail branch-likely delay-slot store is missing |
| [`func_0028B288`](boot/func_0028B288.c) | 44 | 14 |
| [`func_00295870`](game/func_00295870.c) | 68 | Candidate is 64 bytes; mask is not in the retail branch delay slot |
| [`func_0029B658`](game/func_0029B658.c) | 60 | 60-byte candidate swaps the retail global-pointer and saved-object registers |
| [`func_0029B810`](game/func_0029B810.c) | 52 | Candidate is 48 bytes; retail has an extra pointer copy before jr |
| [`func_0029DC58`](game/func_0029DC58.c) | 52 | 26 bytes differ; retail uses bnel with a zero delay-slot result then tests bit 27 |
| [`func_0029FAE0`](game/func_0029FAE0.c) | 60 | 4 bytes differ; retail uses literal lui high halves, not %hi relocations |
| [`func_002A0380`](game/func_002A0380.c) | 60 | 2 bytes differ; table load and branch use v1 instead of retail v0 |
| [`func_002A0488`](game/func_002A0488.c) | 48 | 4 bytes differ; store placement at +0x24 is outside jr delay slot |
| [`func_002C38A0`](game/func_002C38A0.c) | 64 | Candidate is 56 bytes; retail begins with stack adjustment and nop |
| [`func_002C5020`](game/func_002C5020.c) | 68 | Candidate is 72 bytes; retail GP-relative load needs file-level -G8 |
| [`func_002C9A60`](boot/func_002C9A60.c) | 20 | 9 |
| [`func_002C9C60`](game/func_002C9C60.c) | 44 | 8 |
| [`func_002CC528`](game/func_002CC528.c) | 40 | 4 |
| [`func_002D33C0`](game/func_002D33C0.c) | 60 | 2 instructions differ; global-address lui and stack adjustment order differs |
| [`func_002E5F40`](game/func_002E5F40.c) | 32 | 1 |
| [`func_002FCF90`](game/func_002FCF90.c) | 52 | 12 bytes differ; retail schedules zero stores in the return delay slot |
| [func_0031AAB0](game/func_0031AAB0.c) | 88 | check.py 3/3, but level 00 cannot place it: needs .text.func_0031AB08 at its place, which is not C |
| [`func_0031E528`](game/func_0031E528.c) | 52 | 19 bytes differ; loop pointer schedule and beql delay-slot store differ |
| [`func_00327D08`](game/func_00327D08.c) | 72 | Candidate is 76 bytes; retail threshold load is GP-relative |
| [func_00341E58](game/func_00341E58.c) | 52 | check.py 28/28, but level 00 cannot place it: needs .text.func_00341E90 at its place, which is not C |
| [func_0034E478](game/func_0034E478.c) | 64 | check.py 28/28, but level 00 cannot place it: needs .text.func_0034E4B8 at its place, which is not C |
| [func_00351A38](game/func_00351A38.c) | 72 | check.py 28/28, but level 00 cannot place it: needs .text.func_00351938 at its place, which is not C |

## USA v2.00 trials

`v2.00/`: small functions written against the USA v2.00 release (`SCUS_972.68_v2.00.iso`, see
docs/REGIONS.md), most of them comparing equal there apart from link-dependent fields. Nothing
builds v2.00 yet; many of these functions also exist in v1.01 at other addresses, so they are
starting points for both. `FloatToInt` and the functions like it (an in-place `cvt.w.s $f12,$f12`)
are probably handwritten: no C spelling reproduces them.

## Moved from src/ (2026-10-11)

C carried over from the old layout that compiles but does not link at its places: usually a
level address written as a number, which only fits one level.

- [`func_0011EA38`](core/func_0011EA38.c)
- [`func_00121B18`](core/func_00121B18.c)
- [`func_00124C98`](core/func_00124C98.c)
- [`func_0012C680`](core/func_0012C680.c)
- [`func_0012C788`](core/func_0012C788.c)
- [`func_0012C878`](core/func_0012C878.c)
- [`func_00130A60`](core/func_00130A60.c)
- [`func_00130A70`](core/func_00130A70.c)
- [`func_00130A80`](core/func_00130A80.c)
- [`func_001317E8`](core/func_001317E8.c)
- [`func_0027F110`](game/func_0027F110.c)
- [`func_00287E98`](game/func_00287E98.c)
- [`func_00288BE8`](game/func_00288BE8.c) â€” recovered in [maintained C](../src/game/00288BB8-g8.c); the earlier draft is retained.
- [`func_00288D70`](game/func_00288D70.c)
- [`func_00290670`](game/func_00290670.c)
- [`func_002985F0`](game/func_002985F0.c) â€” recovered in [maintained C](../src/game/002985F0-g8.c); the earlier draft is retained.
- [`func_00298780`](game/func_00298780.c) â€” recovered in [maintained C](../src/game/00298780-g8.c); the earlier draft is retained.
- [`func_L00_00309AE8`](levels/shared/func_L00_00309AE8.c) â€” recovered in [maintained C](../src/levels/shared/L00_00309AE8-g8.c); the earlier draft is retained.
- [`func_L00_00309B10`](levels/shared/func_L00_00309B10.c) â€” recovered in [maintained C](../src/levels/shared/L00_00309AE8-g8.c); the earlier draft is retained.
- [`func_L00_00309B58`](levels/shared/func_L00_00309B58.c) â€” recovered in [maintained C](../src/levels/shared/L00_00309AE8-g8.c); the earlier draft is retained.
- [`func_L00_00309B80`](levels/shared/func_L00_00309B80.c) â€” recovered in [maintained C](../src/levels/shared/L00_00309AE8-g8.c); the earlier draft is retained.
- [`func_L03_0043ACD8`](levels/shared/func_L03_0043ACD8.c) â€” recovered in [maintained C](../src/levels/shared/L03_003C5B28-g8.c); the earlier draft is retained.
- [`func_002985F0`](game/func_002985F0.c)
- [`func_00298780`](game/func_00298780.c)
- [`func_L00_00309AE8`](levels/shared/func_L00_00309AE8.c)
- [`func_L00_00309B10`](levels/shared/func_L00_00309B10.c)
- [`func_L00_00309B58`](levels/shared/func_L00_00309B58.c)
- [`func_L00_00309B80`](levels/shared/func_L00_00309B80.c)
- [`func_L03_0043ACD8`](levels/shared/func_L03_0043ACD8.c)

## Small level functions, first Haiku trial (2026-10-12)

Left by 16 Haiku workers after a bounded effort each (docs/AGENT_WORKFLOW.md); the note is the
worker's own. Several are not C problems: rows of the catalogue that are not functions, and
handwritten routines.

| Function | Size | What the worker found |
| --- | ---: | --- |
| [`func_L00_00309DB0`](levels/func_L00_00309DB0.c) | 28 | 7 instructions in retail, 12 in ours; no jr ra in the retail bytes (addiu sp,+0x20 / daddu / addiu sp,+0x40), so no C of this shape can equal them. Catalogue size or split is suspect. Stub below is a guess only. |
| [`func_L00_0031BE88`](levels/func_L00_0031BE88.c) | 36 | 28 bytes against retail's 36: retail is a beql on the null test with the 0 result in its delay slot, then a bnez with addiu 1 / daddu 0 tail; the compiler gives beqz or bnel plus sltu, so the branch-likely shape is missing. |
| [`func_L00_0032A088`](levels/func_L00_0032A088.c) | 48 | 1 of 12 instructions differs (27 places, all at +0x10): retail adds the element address as base + index (addu a2,a1); the compiler emits index + base (addu a1,a2). Reordering the operands, a cast, or a base local did not change it. |
| [`func_L00_00341798`](levels/func_L00_00341798.c) | 28 | No attempt: all 7 instructions would differ. The retail bytes at 0x341798 are not code: seven words 0x27bd0030, 0, 0x27bd0050, 0, 0x27bd0080, 0, 0x27bd0020 (addiu sp,sp,imm with nops between), directly after the epilogue of the function end… |
| [`func_L00_0037F790`](levels/func_L00_0037F790.c) | 84 | 84 bytes, 1 instruction differs: retail loads $a0 = 0 again before $a1/$a2 for the second call (the first call's delay slot holds one $a0 = 0 too), so retail has 21 instructions and this has 20; GCC puts that move in the delay slot of the s… |
| [`func_L00_00380058`](levels/func_L00_00380058.c) | 116 | 116 bytes, 3 instructions differ: the loop table pointer and the counter swap registers (retail: pointer in $s0 loaded with lui/addiu, counter in $s1; this gives counter $s0, pointer $s1 via a copy from $v0). Same result with for, do-while … |
| [`func_L00_00384C20`](levels/func_L00_00384C20.c) | 132 | 132 bytes, 4 instructions differ (128 bytes here): the two do-while loops have the right shape, but GCC loads each entry into $a0 and tests it there, while retail loads it into $v0, tests it, then copies it to $a0 in the branch delay slot, … |
| [`func_L00_0042A4E8`](levels/func_L00_0042A4E8.c) | 24 | 0 of 6 instructions match: retail is three `jr $ra; nop` pairs (24 bytes) with no prologue. A single C function cannot emit three bare returns; the catalogue row likely merged three empty stubs. |
| `func_L00_00428EE0` | 32 | no attempt: the bytes start mid-function, probably the tail of its neighbour |
| [`func_L00_0042A500`](levels/func_L00_0042A500.c) | 32 | 8 instructions; 3 differ: the table-base load comes out as `lui $v1,0; lw $v0,0($v1)` (retail: `lui $v0,0x1B; lw $v0,0x1844($v0)`) and the sll/lw order differs. The two stores already match. |
| [`func_L00_0042B6A8`](levels/func_L00_0042B6A8.c) | 32 | 8 instructions, 40 bytes emitted against 32: retail computes the data address gp-relative (`addiu $v0,$gp,-0x1388`) and stores it in the call delay slot; -G0 gives lui/addiu and a frame that saves a0 in $v1. |
| [`func_L00_0042B6C8`](levels/func_L00_0042B6C8.c) | 32 | 8 instructions, 40 bytes emitted against 32: same shape as func_L00_0042B6A8 (`addiu $v0,$gp,-0x13A8`), same gp-relative address problem under -G0. |
| [`func_L00_002EE058`](levels/func_L00_002EE058.c) | 24 | from src/levels/shared/L00_002E5918.c: 6 retail instructions, C compiles to 5 (ld/sd pairs). Missing: retail's two ldc2 quad loads, a COP2 VU0 macro-mode op (.word 0x4BE2086B) and sdc2 quad store, which plain C cannot emit. Not matchable in… |
| [`func_L00_002EE078`](levels/func_L00_002EE078.c) | 24 | from src/levels/shared/L00_002E5918.c: 6 retail instructions, C compiles to 5 (ld/sd pairs). Missing: retail's two ldc2 quad loads, a COP2 VU0 macro-mode op (.word 0x4BE2086F) and sdc2 quad store, which plain C cannot emit. Not matchable in… |
| [`func_L00_002EE290`](levels/func_L00_002EE290.c) | 32 | from src/levels/shared/L00_002E5918.c: no C attempt; 8 retail instructions (ldc2, four COP2 macro-mode ops, mtc1, jr), a plain C body compiles to 2 and cannot emit the VU0 ops. Placeholder only. |
| [`func_L00_003B9290`](levels/func_L00_003B9290.c) | 64 | 72 bytes vs retail 64 (18 instructions vs 16): the loop body matches retail instruction for instruction; the difference is the first load. Retail reads the count straight off $gp (lw a0,0xD8C($gp)); cc1 emits lui+lw of the symbol address. S… |
| [`func_L00_003B60E8`](levels/func_L00_003B60E8.c) | 108 | 108 bytes: prologue, field loads and register use match retail; about 7 loop instructions differ (retail: beql on *w with the s+=0x150 in its delay slot, bgezl with the next *w load in its delay slot). Missing: the source shape that makes G… |
| [`func_L00_003B4E88`](levels/func_L00_003B4E88.c) | 112 | 120 bytes vs retail 112 (30 instructions vs 28), and not reachable as written: retail loads two words off $gp in ordinary flow (lw v0,0xA28($gp), lw v1,0xA2C($gp)) and cc1 emits lui+lw of their addresses instead (same boundary as func_L00_0… |
| [`func_L00_003B8158`](levels/func_L00_003B8158.c) | 116 | 88 bytes vs retail 116 (22 instructions vs 29): the control flow and the first call match; missing the else arm, which retail builds as an 8-byte local copied from 0x1AFBC8 with ldl/ldr/sdl/sdr (unaligned doubleword pairs, the struct's type… |
| [`func_L00_003B7908`](levels/func_L00_003B7908.c) | 148 | 156 bytes vs retail 148 (39 instructions vs 37): the loop, the calls and the frame match retail instruction for instruction; the difference is that retail takes the addresses of two $gp-resident globals with one addiu each (addiu s1,$gp,0xB… |
| [`func_L00_0035F9F0`](levels/func_L00_0035F9F0.c) | 24 | near miss: 4 of 6 retail instructions (retail 24 bytes, this 16). Missing the dsll32/dsra32 sign extension of the int parameter before bnel. |
| [`func_L00_0036BE28`](levels/func_L00_0036BE28.c) | 40 | near miss: 9 of 10 instructions (ours 36 bytes, retail 40). Retail loads through $at with hand-placed nops and ends in jr ra + lui ra, 0x7000 (looks like hand asm); plain C gives $v0 and fewer nops. |
| [`func_L00_0036C9AC`](levels/func_L00_0036C9AC.c) | 40 | near miss: 9 of 10 instructions (ours 36 bytes, retail 40). Same wait-loop family as func_L00_0036BE28: retail loads through $at, hand-placed nops, jr ra then lui ra, 0x7000. |
| [`func_L00_0036C9D4`](levels/func_L00_0036C9D4.c) | 40 | near miss: 9 of 10 instructions (ours 36 bytes, retail 40). Same wait-loop family as func_L00_0036BE28: retail loads through $at, hand-placed nops, jr ra then lui ra, 0x7000. |
| [`func_L00_0036D274`](levels/func_L00_0036D274.c) | 40 | near miss: 9 of 10 instructions (ours 36 bytes, retail 40). Same wait-loop family as func_L00_0036BE28: retail loads through $at, hand-placed nops, jr ra then lui ra, 0x7000. |
| [`func_L00_0036D29C`](levels/func_L00_0036D29C.c) | 40 | near miss: 9 of 10 instructions (ours 36 bytes, retail 40). Same wait-loop family as func_L00_0036BE28: retail loads through $at, hand-placed nops, jr ra then lui ra, 0x7000. |
| [`func_L00_003F34D8`](levels/func_L00_003F34D8.c) | 64 | func_L00_003F34D8: 8 instructions differ (register choice: retail keeps the count in $t1 and the quad temp in $v0; ours uses $v1/$a0). Quad copy is lq/sq via TImode. Missing: the allocator order. |
| [`func_L00_003F8DC8`](levels/func_L00_003F8DC8.c) | 64 | func_L00_003F8DC8: 72 bytes against 64 (retail uses $gp for the global at 0x1B0A20 via "sw ...,0x1A30($gp)"; this file builds -G0, so the sda global becomes lui/sw). Needs the file-level -G8 that the file does not have; not matched. |
| [`func_L00_003F0130`](levels/func_L00_003F0130.c) | 104 | func_L00_003F0130: 104 bytes, 27 places; the loop, prologue and call match, but the final read of the base global (0x1B2BB4) is "lw $v0,0x3BC4($gp)" in retail, which -G0 (this file) cannot emit: needs -G8 for L00_003EE100.c. Missing: the fi… |
| [`func_L00_003EEE20`](levels/func_L00_003EEE20.c) | 108 | func_L00_003EEE20: 100 bytes against 108; the whole body matches except that retail has two nops between cvt.s.w and div.s (the int divisor converted to float), which this compiler does not emit for any form tried (variable divisor, (float)… |
| [`func_L00_003F09A0`](levels/func_L00_003F09A0.c) | 124 | func_L00_003F09A0: 124 bytes, 1st differing instruction at +0x2c: retail schedules the counter increment before the $a3 constant and puts the element address in $v1 (ours in $v0); the loop, the call to func_L00_003F0B10 and the gp reload ma… |
| [`func_L00_002B5590`](levels/func_L00_002B5590.c) | 92 | 19 instructions (76 bytes) against retail's 23 (92 bytes): the frame is 0x30 not 0x40 and s1 is never saved; retail keeps &a in s1 across the first call (hoisted before it), GCC rematerializes sp+0 after it. Copy/zero order and the calls ma… |
| [`func_L00_00424A50`](levels/func_L00_00424A50.c) | 52 | 3 instructions differ, all store order (52 bytes): the field stores match retail (float b at +84, sh 1 at +62, float a at +76 of the block at +352) but GCC emits a, b, sh where retail has b, sh, a; missing: the source shape that makes the s… |
| [`func_L00_00403BF8`](levels/func_L00_00403BF8.c) | 52 | 52 bytes: under a -G8 probe only the first two instructions differ (retail does li v1,15 before the lui of the base address into v1; the compiler emits lui v0 first); the loop and store match |
| [`func_L00_00403C30`](levels/func_L00_00403C30.c) | 56 | 56 bytes: under a -G8 probe only the first two instructions differ (retail does daddu a0,zero,zero before the lui of the base into v1; the compiler emits lui v0 first and copies it); the loop matches |
| [`func_L00_004028C0`](levels/func_L00_004028C0.c) | 96 | 96 bytes: under a -G8 probe the compile is 80 bytes; the prefix through the jal and the sb agree, the tail differs (retail stores -1 through a beq and keeps a dead li 10 before a b in the else path); also needs config/cflags.txt -O2 -G8 |
| [`func_L00_00403CB8`](levels/func_L00_00403CB8.c) | 160 | 152 of 160 bytes: the found-slot loop and the call sequence match in shape; retail keeps arg in s1 and the slot value in s0 across the calls, ours assigns the registers the other way round (and the else path ends with the value stored back) |
| [`func_L00_002D40A0`](levels/func_L00_002D40A0.c) | 76 | 72 bytes vs 76 (19 instructions): near miss. Retail keeps the 16-byte lq/sq temp in $v0 and folds the copy destination (0x18B6C0) into $v1, then rebases $v1 by -0x18A0 for the other stores; ours keeps the base in $v0 or $a2, so the temp reg… |
| [`func_L00_002D5E30`](levels/func_L00_002D5E30.c) | 132 | 172 bytes vs 132 (not matched): the loop is misread. Retail stores the running sum to *a0 on each pass, adds *a2 from the flag (M>>5 < sum) and walks halfwords from 0x262262; the early exits and the sum update order are not right here. Star… |
| [`func_L01_003246D0`](levels/func_L01_003246D0.c) | 36 | 4 of 11 instructions differ (36 bytes). Retail passes the 64-bit return of func_3246F8 straight into func_3246A0 (daddu, no conversion). Any C prototype narrower than unsigned long makes GCC sign-extend it (dsll32/dsra32); with unsigned lon… |
| [`func_L01_00304270`](levels/func_L01_00304270.c) | 52 | Does not match: the attempt compiles to 36 bytes, retail is 52 (13 instructions). Retail loads its pointer from $v1, a register that is not an argument, and tests with a2; the self-jump (j func_304270) on a 0x100 test suggests a caller-set … |
| [`func_L00_003E6710`](levels/func_L00_003E6710.c) | 104 | 0 of 27 exact: about 10 of 26 instructions differ. Loop shape and calls match (func_L00_003E6F48, the back-edge reload of D_L00_001B2B50 via sda); we keep the base load before the saves and swap the counter/offset registers (retail: counter… |
| [`func_L00_003E4B80`](levels/func_L00_003E4B80.c) | 108 | 0 of 27 exact: 100 bytes, retail 108. Missing two nops between cvt.s.w and div.s (retail: mtc1, nop, cvt.s.w, nop, nop, div.s); the early return and the join through a0 match. |
| [`func_L00_003E6F48`](levels/func_L00_003E6F48.c) | 124 | 0 of 27 exact: the loop, the call and its arguments match; the base-pointer load is hoisted above the saves (retail: after s1=a0) and the back-edge reload uses v1 where retail uses v0 (lw v0,0x3B64(gp) in the bgez-like delay slot). |
| [`func_L00_003E80A8`](levels/func_L00_003E80A8.c) | 164 | 0 of 27 exact: 144 bytes, retail 164 (5 instructions short: retail keeps base, offset and record pointer live across the calls and saves s0-s4). The calls and the 96.0f scale match; the compiler folds base+off and loses the saved registers. |
| [`func_L00_003E9490`](levels/func_L00_003E9490.c) | 172 | 0 of 27 exact: 164 bytes, retail 172. The 128-bit copies (lq/sq) and the calls match; the copy store lands in the branch delay slot (retail: lq, sq, b, ld in the delay slot), so the two copy paths are 2 instructions off. |

## Linked at some of their places only (2026-10-12)

C that was in `src/` and links in some programs but not in all: a level address written into
it, a jump table it needs, or two different functions the catalogue holds as one. A function
counts when it links at every place it has.

| Function | Places it links at | What the build says elsewhere |
| --- | --- | --- |
| [`func_002DCAB8`](game/func_002DCAB8.c) | 26 of 28 | instruction at +0x38 differs |
| [`func_L00_002B1308`](levels/func_L00_002B1308.c) | 0 of 27 | needs .rodata at its place, which is not C |
| [`func_L00_002D4A38`](levels/func_L00_002D4A38.c) | 26 of 27 | instruction at +0x2c differs |
| [`func_L00_003DC350`](levels/func_L00_003DC350.c) | 2 of 27 | instruction at +0x4 differs |
| [`func_L00_00424BB8`](levels/func_L00_00424BB8.c) | 23 of 27 | instruction at +0x28 differs: `16_snivelak`, `22_dobbo_orbit`, `23_damosel_orbit` and `26_jamming_array` hold other constants |
