# Level dispatch tables — the prototype's class identifiers reach the retail

**Measured 2026-10-02 against the pinned retail overlays** (`config/overlays.json`,
27 levels). This document reports one transfer that had not been tested before: the
class identifier axis. The positional axis — same index in the prototype's table and in
the retail's — stays refuted, as measured on 2026-10-01.

## What the retail carries

Each level overlay ships three dispatch tables in its own sections, and none of them is a
flat pointer array:

| Section | Record | Words |
| --- | --- | ---: |
| `lvl.vtbl` | `oClass`, `UpdateMoby_<oClass>` handler, auxiliary pointer | 3 |
| `lvl.camvtbl` | camera id, `InitCamera`, `ActivateCamera`, `UpdateCamera`, `ExitCamera` | 5 |
| `lvl.sndvtbl` | sound id, `UpdateSound_<id>` | 2 |

The moby table ends on padding, the camera and sound tables on an `0xffffffff`
terminator. In `lvl.vtbl` the third word is the same value for every record of a level in
26 of the 27 levels; level 1 has exactly one record pointing elsewhere (`0x2a5d94`), so the
field is a usable pointer to a shared descriptor rather than padding — so far unused here.

Handlers live in the level's own `.text`. **5,598 of 5,788 handlers (96.7 %) are preceded
by a `jr ra` within the three words before them** — they are function entries, not
arbitrary addresses. The remaining 3.3 % show no such return before them in that window.

## Why an identifier transfers

Class identifiers are not positions. `UpdateMoby_<oClass>` numbering is the community's
convention for these tables, and the same numbering survives from the 8 August 2003
prototype to the retail USA v1.01.

The control that makes this evidence rather than an assumption is falsifiable and free:
in the prototype's extraction, several oClass values **share one address**, because the
linker merged identical functions (for instance `UpdateMoby_13` and `UpdateMoby_14`).
If the identifier really transfers, those oClass values must also share one retail
handler.

| Control, 27 levels | Result |
| --- | ---: |
| Pairs of oClass sharing one prototype address | **282** |
| … whose two retail handlers are the same function | **282 / 282** |
| Retail handlers shared by oClass with *different* prototype addresses | **1** (`0x03cfb00`, level 0) |

One exception in 27 levels is a retail linker merge, not a broken correspondence.

## Coverage

| Table | Records | Functions named |
| --- | ---: | ---: |
| Moby (`lvl.vtbl`) | **5 788** | **5 460** (94.3 %) — 4 843 distinct handlers |
| Camera (`lvl.camvtbl`) | 217 | **864** |
| Sound (`lvl.sndvtbl`) | 32 | **32** |
| | | **6 356 names proposed** |

The 328 unnamed moby records are class identifiers **absent from the 8 August build** —
added later. Their identifiers are read from the table; no name can be given to them from
this source, but they are real classes, and that is checked independently below.

### The identifiers are the retail's own class enumeration

`Wrench` unpacks the retail's moby classes into `moby_classes/<id>_<name>`, which is an
independent enumeration of what a class identifier is in this build. Cross-checked against
the table:

| | |
| --- | ---: |
| Classes Wrench enumerates in the retail | **1 476** |
| Distinct identifiers in the dispatch table | 1 158 |
| … that Wrench also enumerates | **1 119** (96.6 %) |
| The 328 unnamed records' identifiers, found in Wrench's list | **129 / 129** |

Twenty-one of those class folders carried a name in that survey — `0_ratchet`, `10_clank`, `2425_fan`,
`2716_slot_machine`, `4056_elevator_dam`, `4057_secret_door`, `2452_ant_ring`,
`3138_clanks_apt_glass`, and thirteen more. The source of the labels is now identified:
Wrench's public underlay metadata (see below), rather than strings in the boot or overlays.

The retail camera identifier set (`0,3,4,5,6,7,17,19,20,23,24,25,26,27`)
contains the prototype's set exactly, plus `20`; camera transfer rests on that set equality
and on the record layout, not on the pair control above, which is moby-specific.

The data is in **`docs/moby-dispatch.tsv`** —
`table · level · id · role · address · aux · proposed_name · source · class_label · class_label_source` — with virtual addresses
as they appear in the overlay ELF. A tool that loads an overlay at file offset rather than at
its virtual address must translate first.

### Community object labels

`class_label` records an attributed human-readable Moby class label where a named class has an
existing retail dispatch row. `class_label_source` contains immutable links to the public
declarations supporting it. Both fields are empty when no sourced label is available; camera
and sound identifiers are separate namespaces and receive no Moby labels.

The original labels come from Wrench commit `1b48f4d1ed02de9e05b57802ab518f9ec39c23df`:

- [`data/underlay/gc_moby_classes.asset`](https://github.com/chaoticgd/wrench/blob/1b48f4d1ed02de9e05b57802ab518f9ec39c23df/data/underlay/gc_moby_classes.asset)
  supplies **Slot Machine**.
- [`data/underlay/level_design.asset`](https://github.com/chaoticgd/wrench/blob/1b48f4d1ed02de9e05b57802ab518f9ec39c23df/data/underlay/level_design.asset)
  supplies **Fan**, the Endako elevators, doors and tube/ant objects, and the Todano
  **Elevator Dam** and **Secret Door**.

Those labels annotate **12 existing Moby rows**. Each class/handler pair was checked directly
in `lvl.vtbl` from the contributor's matching USA v1.01 ISO. For example, class **2425**
is labelled **Fan** and points at `0x003ca938` in Endako. The existing function catalogue
maps that exact entry to `func_L03_003CA938` in `src/levels/03_endako/L03_00399230-g8.c`.
To find it, search the TSV for `Fan`, then look up the row's level/address in
`config/levels/functions.tsv`; shared code can have a canonical name from another level.

These are attributed community labels, not recovered designer symbols or texture filenames.
Preserve their source spelling. A handler shared by several classes does not acquire a
single object's identity: those 12 Wrench rows have **9 distinct handler entries**. `proposed_name`
and `source` still describe the existing dispatch-name transfer and are unchanged. The
new columns are appended, so positional readers of the original eight fields retain their
meaning. No C function, catalogue entry or Ghidra naming rule is changed.

The TSV remains the one published mapping; no second class-name table or generated
resource dump is needed. Textures, meshes, material graphs and instance lists remain local.

The full [Wrench underlay at that revision](https://github.com/chaoticgd/wrench/tree/1b48f4d1ed02de9e05b57802ab518f9ec39c23df/data/underlay)
was also checked across its 18 `.asset` files, restricting declarations to the `gc` game
namespace. It supplies **25 named Moby classes, 101 named Tie classes, 17 named Shrub
classes and 27 level names**. These are source declarations, not counts of models observed
in a particular extraction. Only 12 of the named Moby IDs occur in this dispatch TSV, and
all 12 are labelled. The other 13 do not gain an invented handler entry.

Tie and Shrub IDs occupy different namespaces and cannot label Moby handlers. For example,
`gc.shrub_classes.4018` is **Blue Fern**, while `gc.moby_classes.4018` is the separate
**Therm Water** class described below. Preserve the full `(game, class type, ID)` key when
using Wrench metadata for asset identification; a number alone is not an object identity.

### Equipment labels corroborated across sources

An additional **30 classes / 810 existing rows** have matching model attributions in:

- [Replanetizer's RAC2 model list](https://github.com/RatchetModding/Replanetizer/blob/2136bd9fbe4815b0119921e794a87d847da9816e/LibReplanetizer/ModelLists/MobyModelsRC2.txt),
  which uses **hexadecimal** class IDs and targets the PS3 collection.
- [APRac2's explicit equipment model IDs](https://github.com/evilwb/APRac2/blob/12148dcedcbcb19bf6fc47f0a5b45281d06740bc/data/Items.py),
  whose [supported target](https://github.com/evilwb/APRac2/blob/12148dcedcbcb19bf6fc47f0a5b45281d06740bc/README.md#what-versions-of-the-ratchet--clank-2-are-supported)
  is PS2 USA v1.01, `SCUS-97268`.

Their `class_label_source` cells contain both immutable declaration links, separated by
`; `. Class IDs were converted to decimal for the TSV; names agree after ignoring case,
spacing and punctuation (for example, **Helipack** / **Heli-Pack**). The displayed label
keeps Replanetizer's spelling. All 810 class/handler pairs were also checked in the original
PS2 ISO's `lvl.vtbl`; no PS3 address was transferred. This establishes source agreement and
retail dispatch identity, not an independent live observation of each object's appearance.

Only an **explicit** APRac2 `oclass_id` counts. An omitted field inherits a fallback Wrench
model, so it cannot identify the item; upgraded weapons can reuse a base model, so their
display names cannot overwrite its class label. These are equipment **model** names, not
proof that every instance is an equipped weapon, a pickup or a projectile.

Wrench also has a class-specific description outside its name tables:
[`moby4018_therm_water.h`](https://github.com/chaoticgd/wrench/blob/46e80430158a4a11e9cbd51424c84a015bbab058/data/overlay/src/game_gc/update/moby4018_therm_water.h#L3-L22).
The label **Therm Water** preserves its filename wording; it is not a recovered symbol.
Its `update4018` layout is compatible with all five original class-4018 instances in Notak:
each has 64 PVar bytes, the low-height field agrees with the instance's Z position, and the
frozen flag is Boolean. The class's dispatch pointer is `0x00456bb0`. This checks the class
association and the stated layout controls, not every field or live water behaviour.

The TSV now labels **43 classes / 823 rows**. Other Replanetizer names remain unconfirmed
here. APRac2-only **Clank Zapper** (`0x0ed8`) and **Shield Charger** (`0x0a5c`) are also left
unlabelled pending another check. A missing exact entry in the function catalogue is not
replaced with the nearest function: use the measured dispatch address as written.

### Identifying an object with MobyViewer

[CreepNT's MobyViewer](https://github.com/CreepNT/MobyViewer/tree/78ed6b0057f74367c851a40dd2b7f9832338dafe)
reads live Moby instances from PCSX2. The procedure below was checked against that revision's
README and source; this revision has **not been run or qualified with the current PCSX2
build** for this research. Record both tool versions when qualifying a session.

1. Use your own unmodified matching USA v1.01 ISO in PCSX2 and enter the level being
   investigated. Verify the disc version separately: MobyViewer detects the game family,
   not the repository's target hash. Keep saves and observation output private.
2. Obtain MobyViewer from its [upstream releases](https://github.com/CreepNT/MobyViewer/releases/tag/0.13)
   (the 0.13 release provides `MobyViewer-win64.exe` for 64-bit Windows). With PCSX2 running, choose the PS2 target
   and press **Attach**. Confirm **Current game: Ratchet & Clank 2** and sensible instance
   positions. On Windows its direct-process backend is available; **Use IPC** selects an
   alternative backend which upstream marks experimental. An attachment failure is a tool
   compatibility problem, not evidence that a class is absent.
3. Start without a name lookup file. In **Options and filters**, enable the **oClass**
   filter using the **decimal** ID from this TSV; `0x0979` in a lookup list means decimal
   `2425`, not `979`. Inspect **oClass**, **Moby UID**, position and **Update function address**.
   Do not confuse the separate 8-bit **mClass** field with the 16-bit **oClass**.
4. Correlate a numeric instance with the visible object by position and repeatable movement,
   appearance or disappearance. Orange title bars indicate currently visible instances;
   they do not identify the object by themselves. Record the level, class, UID, update
   pointer and the observation that supports the proposed name. Distinguish held models,
   pickups, projectiles and effects. Observe a second instance or scene when possible.
5. Match `(level, oClass, update pointer)` against this TSV and the original `lvl.vtbl`.
   A class can share a handler with other classes. Resolve a canonical C name only at an
   exact catalogue entry. Use **Full refresh** after changing level or loading a state,
   since the instance stack and overlay addresses can change. Repeat the control after it.
6. Once confirmed, add the label and an attributable source to this TSV. Summarize any new
   observation and its limits in the PR; private screenshots and dumps stay local. A lookup
   label displayed by the viewer is not independent confirmation of the label itself.

For convenient later browsing, MobyViewer accepts a local `rc2.txt` with one
**four-digit hexadecimal** `ID=Label` per line, such as `0979=Fan`; `FFFF` is invalid.
Generate it from the labelled Moby rows into ignored `build/`, deduplicating by class ID,
then place it where that MobyViewer build reads its lookup files. Release builds look for
`rc2.txt` in their working directory; debug builds use `../data/` (see
[`widgets.cpp`](https://github.com/CreepNT/MobyViewer/blob/78ed6b0057f74367c851a40dd2b7f9832338dafe/src/widgets.cpp#L26-L30)).
The upstream README suggests placing it beside the executable; launch from that directory.
Never import the lookup back as new evidence or commit a second name list.

For example, run this Python code from the repository root to generate the lookup:

```python
import csv
from pathlib import Path

with Path("docs/moby-dispatch.tsv").open(encoding="utf-8", newline="") as stream:
    labels = {int(r["id"]): r["class_label"] for r in csv.DictReader(stream, delimiter="\t")
              if r["table"] == "moby" and r["class_label"]}
Path("build").mkdir(exist_ok=True)
Path("build/rc2.txt").write_text(
    "".join(f"{key:04X}={value}\n" for key, value in sorted(labels.items())), encoding="utf-8")
```

## What this is not

- **Not designer names.** `UpdateMoby_3032` states a moby class, not a creature. The sourced
  community labels above describe classes or equipment models, not the full behaviour of
  their handlers. Assert-message evidence is a separate source of semantic information
  (see [`ASSERT-MESSAGE-NAMES.md`](ASSERT-MESSAGE-NAMES.md)).
- **Not boot code.** Crossing all 5,788 handlers with the boot bodies this project has
  mapped into the levels (82 per level in `config/level-catalog.json`, 288 in the wider
  prefix survey) gives **zero overlap**. The dispatch tables point at level-local code —
  which is also why the earlier "0 of 698" measurement looked like a dead end.
- **Not a placement.** Naming a level function does not put reviewed C into a level, and
  this table is not part of `config/level-catalog.json`.

## Applying the names

`tools/ghidra/ApplyMobyNames.java` is a Ghidra script: it reads `docs/moby-dispatch.tsv`
and names the functions of the overlay currently open, taking the level name as its first
argument. It builds both address candidates from the ELF section table on disk (virtual
address and file offset, because an overlay may have been imported either way), leaves an
existing name alone, gives a function shared by several classes the first name it receives,
and reports what it did. Nothing is persisted until the program is saved.

Measured on the first two overlays, with this table:

| Overlay | Rows for the level | Renamed | Already named | No function at the address |
| --- | ---: | ---: | ---: | ---: |
| `1_oozla` | 253 | **183** | 22 | 48 |
| `2_maktar_nebula` | 254 | **188** | 20 | 46 |

Both were controlled afterwards by a separate read-only check: every name landed on an
address present in the TSV — **183 of 183** and **188 of 188**, zero elsewhere. The rows
with no function are addresses Ghidra's analysis did not turn into functions; the table
carries them regardless.

## Provenance

The class identifiers come from **CreepNT's `rc2_aug8_research`**
(https://codeberg.org/CreepNT/rc2_aug8_research) — extracted tables of the 8 August 2003
prototype build, `extracted/sections_info/moby_symtab.csv`, `cam_symtab.csv`,
`snd_symtab.csv`. No game bytes are reproduced here: the table published alongside this
document holds identifiers, addresses and structural role names only. The retail side is
read from the same pinned overlays this repository already records by SHA-256, so every
row can be re-derived.
