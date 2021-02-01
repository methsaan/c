#! /bin/bash

set -o pipefail
set -o nounset
set -o errexit

echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"

gcc execfile.c> errors.txt
echo "haho"
cat errors.txt
cat errors.txt
cat errors.txt
cat errors.txt
cat errors.txt
