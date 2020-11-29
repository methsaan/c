#! /bin/bash

set -o pipefail
set -o nounset
set -o errexit

gcc execfile.c
