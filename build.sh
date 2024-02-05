#!/bin/bash

set -e

TARGET="$1"

mkdir -p build
cd build

if [[($@ == *'--debug'*)]]
then
    cmake -DCMAKE_BUILD_TYPE=Debug ..
else
    cmake ..
fi

if [ "$TARGET" == "" ]
then
    cmake --build . -j 16
else
    cmake --build . --target $TARGET -j 16
fi
