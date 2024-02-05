#!/bin/bash

set -e

DEBUG=false

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --debug) DEBUG=true; echo "Debug" ;;
        --*) echo "Unknown flag was passed"; exit 1 ;;
        *) TARGET="$1"; echo "Target" ;;
    esac
    shift
done

mkdir -p build
cd build

if [ $DEBUG ]
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
