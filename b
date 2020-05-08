#!/bin/bash

BASEDIR=$(dirname $0)
PROG=${0##*/}
USAGE="$PROG - build and run C++ source file.

$PROG <source_file> [<options_for_source>]
"

[[ $# -lt 1 ]] && echo "$USAGE" && exit 0

SRCFILE=$(readlink -f $1)
[[ -z "$SRCFILE" ]] || [[ ! -r $SRCFILE ]] &&
    { echo "$1 not found" && exit 1; }
shift
SRCFILE=${SRCFILE#$(readlink -f $BASEDIR)/}

CXXFLAGS+=" -g -Wall -pthread"
[[ "$SRCFILE" =~ "test_" ]] && grep -qw "gtest.h" $SRCFILE 2>/dev/null &&
    TESTLIBS+=" -lgtest -lgtest_main"

cd $BASEDIR
binfile=$(basename $SRCFILE)
BINFILE="build/${binfile%.*}"

(set -x && g++ $CXXFLAGS ${SRCFILE} -o $BINFILE $TESTLIBS && $BINFILE "$@")
echo "+ Exit code: $?"
