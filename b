#!/usr/bin/env bash
set -euo pipefail
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
mkdir -p "$SCRIPT_DIR/out"
gcc -Wall -Wextra -Werror -Os main.c -o "$SCRIPT_DIR/out/add"
