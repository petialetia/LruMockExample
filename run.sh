#!/bin/bash

set -e

TARGET="$1"

./build.sh $@

EXECUTABLE_NAME=$([ "$TARGET" == "" ] && echo "TemplateProject" || echo "$TARGET")

EXECUTABLE="bin/${EXECUTABLE_NAME}.out"

./$EXECUTABLE
