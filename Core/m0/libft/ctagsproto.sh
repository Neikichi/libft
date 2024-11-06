#!/bin/bash

# Output header file
HEADER_FILE="generated_prototypes.h"

# Clear the header file
echo "// Function prototypes" > "$HEADER_FILE"

# Loop through each .c file in src directory
for file in src/*.c; do
    # Use ctags to extract function names and generate full prototypes
    ctags -x --c-kinds=f "$file" | awk '{for (i=5; i<NF; i++) printf $i " "; printf $NF; print ";"}' >> "$HEADER_FILE"
done

# Confirm header file creation
echo "Prototypes have been written to $HEADER_FILE"

