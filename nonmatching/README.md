# Near misses

C that compiles close to a function but not to its bytes: a starting point, never linked
and never counted. Move a file into `src/` once `tools/build.py` places it.

| Function | Size | Bytes that differ |
| --- | ---: | ---: |
| [`func_0012FB48`](boot/func_0012FB48.c) | 20 | 3 |
| [`func_0028B288`](boot/func_0028B288.c) | 44 | 14 |
| [`func_002C9A60`](boot/func_002C9A60.c) | 20 | 9 |

## USA v2.00 trials

`v2.00/`: small functions written against the USA v2.00 release (`SCUS_972.68_v2.00.iso`, see
docs/REGIONS.md), most of them comparing equal there apart from link-dependent fields. Nothing
builds v2.00 yet; many of these functions also exist in v1.01 at other addresses, so they are
starting points for both. `FloatToInt` and the functions like it (an in-place `cvt.w.s $f12,$f12`)
are probably handwritten: no C spelling reproduces them.
