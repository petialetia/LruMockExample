#!/bin/bash

set -e

./build.sh $@

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --*) ;;
        *) TARGET="$1";;
    esac
    shift
done

EXECUTABLE_NAME=$([ "$TARGET" == "" ] && echo "TemplateProject" || echo "$TARGET") #TODO: change to your default target

EXECUTABLE="bin/${EXECUTABLE_NAME}.out"

./$EXECUTABLE
