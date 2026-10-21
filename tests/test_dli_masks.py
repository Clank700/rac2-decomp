"""Authored, asset-free R5900 dli regression cases.

Ordinary CI validates fixture semantics and skips assembler execution if absent.
Compiler qualification must run with RAC2_COMPILER_ROOT set to the new tools;
an explicit missing assembler is an error, never a skip.

The isolated sign-bit form is independently documented by the public RAC1
assembler model (GPL-3.0), commit 813090403fe822acd929616da0fee2081131f92e:
https://github.com/OpenRAC/rac1-decomp/blob/813090403fe822acd929616da0fee2081131f92e/tools/ps2eeas_dli.py
The test code and constant cases here are authored independently; no game
bytes, SDK sources, or assembler-output rewriting are used.
"""
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import elf

CASES = json.loads((ROOT / "tests/fixtures/dli_masks.json").read_text())
REGISTERS = (2, 8, 16, 31)
MASK64 = (1 << 64) - 1


def retarget(words, reg):
    """Retarget the authored $2 golden sequence using instruction register fields."""
    out = []
    for encoded in words:
        word = int(encoded, 16)
        opcode = word >> 26
        if opcode in (9, 13, 15):
            rs, rt = (word >> 21) & 31, (word >> 16) & 31
            if rt != 2 or rs not in (0, 2):
                raise ValueError("unexpected immediate register in fixture")
            word &= ~((31 << 21) | (31 << 16))
            word |= (reg if rs == 2 else 0) << 21 | reg << 16
        elif opcode == 0 and (word & 63) in (0x38, 0x3A, 0x3C, 0x3E):
            if (word >> 16) & 31 != 2 or (word >> 11) & 31 != 2:
                raise ValueError("unexpected shift register in fixture")
            word = (word & ~((31 << 16) | (31 << 11))) | reg << 16 | reg << 11
        else:
            raise ValueError(f"unsupported fixture opcode: {word:08x}")
        out.append(word)
    return out


def execute_constant(words, result_register):
    """Execute the six scalar operations used by these authored dli sequences."""
    registers = [0] * 32
    for word in words:
        opcode, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        rd, shift, function = (word >> 11) & 31, (word >> 6) & 31, word & 63
        immediate = word & 0xFFFF
        if opcode == 15:  # lui sign-extends its 32-bit result to 64 bits.
            value = immediate << 16
            registers[rt] = value - (1 << 32) if value & (1 << 31) else value
        elif opcode == 13:
            registers[rt] = registers[rs] | immediate
        elif opcode == 9:
            signed = immediate - 0x10000 if immediate & 0x8000 else immediate
            value = (registers[rs] + signed) & 0xFFFFFFFF
            registers[rt] = value - (1 << 32) if value & (1 << 31) else value
        elif opcode == 0 and function in (0x38, 0x3C):
            registers[rd] = registers[rt] << (shift + (32 if function == 0x3C else 0))
        elif opcode == 0 and function in (0x3A, 0x3E):
            registers[rd] = registers[rt] >> (shift + (32 if function == 0x3E else 0))
        else:
            raise ValueError(f"unsupported instruction: {word:08x}")
        registers = [value & MASK64 for value in registers]
        registers[0] = 0
    return registers[result_register]


class FixtureTests(unittest.TestCase):
    def test_baseline_and_expected_sequences_preserve_64_bit_values(self):
        for case in CASES:
            for reg in REGISTERS:
                for field in ("baseline_words_r2", "words_r2"):
                    with self.subTest(case=case["name"], reg=reg, version=field):
                        self.assertEqual(execute_constant(retarget(case[field], reg), reg),
                                         int(case["value"], 16))

    def test_controls_and_positive_boundaries_are_present(self):
        cases = {case["name"]: case for case in CASES}
        for name in ("zero", "minus_one", "low_run_31", "low_run_63",
                     "pack_neighbor_minus_one", "pack_neighbor_plus_one",
                     "pack_hole_bit30", "shifted_low_ones_control", "long_max",
                     "gs_control", "sparse_control", "signed32_control", "unsigned32_control"):
            with self.subTest(control=name):
                self.assertFalse(cases[name]["changed_by_fix"])
                self.assertEqual(cases[name]["words_r2"], cases[name]["baseline_words_r2"])
        expected_lengths = {"sign_bit": 2, "sign_bit_signed": 2, "low_run_32": 5,
                            "pack_d_mask": 6, "low_run_62": 6}
        for name, length in expected_lengths.items():
            self.assertTrue(cases[name]["changed_by_fix"])
            self.assertEqual(len(cases[name]["words_r2"]), length)
        self.assertEqual(cases["sign_bit"]["words_r2"], ["2402ffff", "000217fc"])
        self.assertEqual(cases["sign_bit"]["words_r2"], cases["sign_bit_signed"]["words_r2"])


class AssemblerOutputTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        compiler = Path(os.environ.get("RAC2_COMPILER_ROOT", ROOT / "build/compiler/tools")).resolve()
        assembler = compiler / "as"
        if not assembler.is_file():
            if "RAC2_COMPILER_ROOT" in os.environ:
                raise RuntimeError("RAC2_COMPILER_ROOT must contain the newly built as")
            raise unittest.SkipTest("EE assembler absent; compiler build must run with RAC2_COMPILER_ROOT")
        cls.outputs = {}
        with tempfile.TemporaryDirectory() as directory:
            temporary = Path(directory)
            lines = [".text", ".set noreorder", ".set noat"]
            for case in CASES:
                for reg in REGISTERS:
                    symbol = f'dli_{case["name"]}_r{reg}'
                    lines += [f".globl {symbol}", f".type {symbol},@function", f"{symbol}:",
                              f'dli ${reg},{case["literal"]}', f".size {symbol},.-{symbol}"]
            source, output = temporary / "authored.s", temporary / "authored.o"
            source.write_text("\n".join(lines) + "\n")
            result = subprocess.run([str(assembler), "-o", str(output), str(source)],
                                    capture_output=True, text=True)
            if result.returncode:
                raise RuntimeError(f"authored dli assembly failed: {result.stderr}")
            obj = elf.read_object(output)
            symbols = {symbol["name"]: symbol for symbol in obj["symbols"]}
            for case in CASES:
                for reg in REGISTERS:
                    name = f'dli_{case["name"]}_r{reg}'
                    symbol = symbols[name]
                    data = obj["sections"][symbol["section"]]["data"]
                    body = data[symbol["value"]:symbol["value"] + symbol["size"]]
                    cls.outputs[case["name"], reg] = body

    def test_forms_encodings_and_sizes_in_four_registers(self):
        for case in CASES:
            for reg in REGISTERS:
                with self.subTest(case=case["name"], reg=reg):
                    expected = b"".join(struct.pack("<I", word) for word in retarget(case["words_r2"], reg))
                    self.assertEqual(self.outputs[case["name"], reg], expected)

    def test_assembled_sequences_have_the_required_64_bit_semantics(self):
        for case in CASES:
            for reg in REGISTERS:
                with self.subTest(case=case["name"], reg=reg):
                    body = self.outputs[case["name"], reg]
                    words = [item[0] for item in struct.iter_unpack("<I", body)]
                    self.assertEqual(execute_constant(words, reg), int(case["value"], 16))

    def test_unaffected_controls_keep_baseline_bytes(self):
        for case in CASES:
            if not case["changed_by_fix"]:
                for reg in REGISTERS:
                    with self.subTest(control=case["name"], reg=reg):
                        baseline = b"".join(struct.pack("<I", word)
                                            for word in retarget(case["baseline_words_r2"], reg))
                        self.assertEqual(self.outputs[case["name"], reg], baseline)


if __name__ == "__main__":
    unittest.main()
