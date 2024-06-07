#!/bin/bash

# Run CMake to generate build files
cmake -S . -B build

# Navigate to the build directory
cd build  

# Compile the project using make
make

# Run the executable
./library_ex_exec

# Run the tests
ctest || { echo "Tests failed"; exit 1; }

# Navigate back to the parent directory
cd .. 

# Remove the build directory
rm -rf build
