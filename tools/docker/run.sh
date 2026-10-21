#!/usr/bin/env bash
# The private runtime launcher for the workers (not part of the repository).
#
# The upstream tools/docker/run.sh builds and runs the "rac2-build:latest" image.
# The private runtime uses the derived image "rac2-build-win-runtime:py312" (the
# upstream image with Python 3.12, which the build needs) and lets the bridge
# mount the worker's own volume over the worker's path, so that the compilers and
# the extracted programs live in the worker's private volume.
#
#   bash tools/docker/run.sh python3 tools/build.py all
set -euo pipefail
repo=$(cd "$(dirname "$0")/../.." && pwd)
CLI="${CONTAINER_CLI:-$(command -v podman >/dev/null 2>&1 && echo podman || echo docker)}"
IMAGE="${RAC2_BUILD_IMAGE:-rac2-build-win-runtime:py312}"
if ! $CLI image inspect "$IMAGE" >/dev/null 2>&1; then
  echo "The image $IMAGE is missing; it cannot be rebuilt from the upstream Dockerfile." >&2
  exit 1
fi
exec $CLI run --rm --platform linux/386 -v "$repo:$repo" -w "$repo" -e WORK=/tmp/rac2-compiler \
  "$IMAGE" bash -c 'wineserver -p >/dev/null 2>&1 || true; exec "$@"' bash "$@"
