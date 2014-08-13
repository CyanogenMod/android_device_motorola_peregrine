#!/bin/sh

set -e

export VENDOR=motorola
export DEVICE=peregrine
./../../$VENDOR/msm8226-common/extract-files.sh $@
