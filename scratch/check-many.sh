#!/usr/bin/env bash
# Check several functions in one container boot (private worker helper).
for name in "$@"; do
  echo "########## $name"
  python3 tools/check.py "$name" --diff || true
done
