#!/bin/bash

# Compile the C++ program
g++ -Wall -Wextra -O2 -std=c++17 -o "$1" "$1.cpp"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program with input redirection
    ./"$1" < input.txt > output.txt 2> error.txt && cat output.txt
else
    echo "Compilation failed"
fi

