#!/usr/bin/env python3
"""
How much of the game's code is C: progress/report.json, from the last full build.

  python3 tools/progress.py        # also rewrites the table in README.md

Every distinct function counts once: the boot executable's functions, and each level
function of config/levels/functions.tsv that the boot does not also have (a function many
levels share is one function). A function is C when its C linked into at least one program
that came out equal to the retail one (build/<program>/placed.json, written by
tools/build.py). Run `tools/build.py all` first.
"""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import levels  # noqa: E402

REPORT = ROOT / "progress/report.json"


def main() -> None:
    placed = set()
    programs = ["boot"] + [levels.level_dir(n) for n in sorted(levels.NAMES)]
    for program in programs:
        path = ROOT / "build" / program / "placed.json"
        if not path.is_file():
            sys.exit(f"no build of {program}: run tools/build.py all first")
        placed |= set(json.loads(path.read_text())["functions"])
    boot = levels.read_boot_functions()
    rows = [r for r in levels.read_catalogue() if r[1] != "boot"]
    parts = {
        "boot": {"functions": len(boot), "bytes": sum(n for _, _, n in boot),
                 "matched_functions": sum(1 for f, _, _ in boot if f in placed),
                 "matched_bytes": sum(n for f, _, n in boot if f in placed)},
        "levels": {"functions": len(rows), "bytes": sum(r[2] for r in rows),
                   "matched_functions": sum(1 for r in rows if r[0] in placed),
                   "matched_bytes": sum(r[2] for r in rows if r[0] in placed)},
    }
    total = {k: sum(p[k] for p in parts.values()) for k in parts["boot"]}
    report = {"game": "Ratchet & Clank: Going Commando", "version": "SCUS_972.68 (USA v1.01)",
              **total, "percent": round(100 * total["matched_bytes"] / total["bytes"], 2), "parts": parts}
    REPORT.parent.mkdir(exist_ok=True)
    REPORT.write_text(json.dumps(report, indent=1) + "\n")
    placements = sum(len(json.loads((ROOT / "build" / p / "placed.json").read_text())["functions"])
                     for p in programs[1:])
    row = lambda label, d: (f"| {label} | {d['matched_functions']:,} of {d['functions']:,} | "
                            f"{d['matched_bytes']:,} of {d['bytes']:,} bytes |")
    table = "\n".join(["| | Functions | Code |", "| --- | ---: | ---: |",
                       row("Boot executable", parts["boot"]), row("Levels", parts["levels"]),
                       row("**Total**", total)[:-2] + f" ({report['percent']}%) |", "",
                       f"The 27 levels hold {sum(len(r[4]) for r in levels.read_catalogue()):,} function "
                       f"placements; C covers {placements:,} of them."])
    readme = ROOT / "README.md"
    text = readme.read_text()
    a, b = text.index("<!-- progress -->") + len("<!-- progress -->"), text.index("<!-- /progress -->")
    readme.write_text(text[:a] + "\n" + table + "\n" + text[b:])
    print(f"{total['matched_functions']} of {total['functions']} functions, "
          f"{total['matched_bytes']} of {total['bytes']} bytes ({report['percent']}%)")


if __name__ == "__main__":
    main()
