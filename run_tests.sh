#!/bin/bash

# Number of test cases (parameterized)
NUM_TESTS=1

# Compile the project
cmake -S . -B out/Debug
cmake --build out/Debug

# Run tests
for i in $(seq 1 $NUM_TESTS)
do
    echo "Running test $i..."
    sed -n "/^===$((i-1))$/,/^===$i$/p" tests/Test.in.txt | sed '1d;$d' | ./out/Debug/PB > tests/temp.$i.out.txt
    expected=$(sed -n "/^===$((i-1))$/,/^===$i$/p" tests/Test.out.txt | sed '1d;$d')
    if diff -u <(echo "$expected") tests/temp.$i.out.txt > tests/diff.$i.txt; then
        echo "Test $i passed!"
        rm tests/diff.$i.txt
    else
        echo "Test $i failed! See diff in tests/diff.$i.txt"
    fi
    rm tests/temp.$i.out.txt
done
