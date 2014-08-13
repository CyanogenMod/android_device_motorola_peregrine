#!/bin/sh

set -e

export DEVICE=peregrine
export VENDOR=motorola
./../../$VENDOR/msm8226-common/setup-makefiles.sh $@
