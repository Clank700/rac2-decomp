#!/usr/bin/env bash
# Screen the tour-2 candidate corrections in one boot.
python3 scratch/variants.py func_L00_00329FF0 scratch/f1.c scratch/f2.c
python3 scratch/variants.py func_L00_003296C0 scratch/g1.c scratch/g2.c
python3 scratch/variants.py func_L13_00389848 scratch/h1.c --level 13
