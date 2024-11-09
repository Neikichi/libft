#!/bin/bash

# Directory of source files
SRC_DIR="./src"
# Output header file
HEADER_FILE="./include/proto.h"

# Create header guard macros
echo "#ifndef MY_HEADER_H" > $HEADER_FILE
echo "#define MY_HEADER_H" >> $HEADER_FILE
echo "" >> $HEADER_FILE

# Use grep to find function definitions in the source directory
grep -h -E '^[a-zA-Z_][a-zA-Z_0-9]*[ \t]+\**[a-zA-Z_][a-zA-Z_0-9]*\s*\([^)]*\)\s*\{' "$SRC_DIR"/*.c |
sed -E 's/\s*\{.*$/;/' >> $HEADER_FILE

echo "" >> $HEADER_FILE
echo "#endif // MY_HEADER_H" >> $HEADER_FILE

