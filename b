#!/usr/bin/env bash
set -euo pipefail
pwd
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
mkdir -p "$SCRIPT_DIR/workspace"
gcc -Wall -Wextra -Werror -Os main.c -o "$SCRIPT_DIR/workspace/add"
