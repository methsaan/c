#! /bin/bash

set -o pipefail
set -o nounset
set -o errexit

errors=$(gcc execfile.c)
echo "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"
echo $errors
echo $errors
echo $errors
echo $errors
echo $errors
