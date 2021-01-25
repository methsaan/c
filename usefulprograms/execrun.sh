#! /bin/bash

set -o pipefail
set -o nounset
set -o errexit

errors=$(gcc execfile.c)
destdir=/home/test/programming/c/usefulprograms/errors.txt
echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"

printf "%s" "$errors" >> "$destdir"
printf "%s" "$errors" >> "$destdir"
printf "%s" "$errors" >> "$destdir"
printf "%s" "$errors" >> "$destdir"
printf "%s" "$errors" >> "$destdir"
