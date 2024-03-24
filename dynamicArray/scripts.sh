#!/bin/bash

# Compile the C++ files
echo "Compiling C++ files..."
clang++ -std=c++11 -o main main.cpp includes/dynamic_array.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    printf "Compilation successful.\nRunning the program...\nOutput:\n"

    # Run the created executable
    ./main
else
    echo "Compilation failed."
fi
