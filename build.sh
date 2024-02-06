#!/bin/bash

set -e

DEBUG=false

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --debug) DEBUG=true;;
        --*) echo "Unknown flag was passed"; exit 1 ;;
        *) TARGET="$1";;
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
