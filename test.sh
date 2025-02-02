#!/bin/bash

# Function to verify if numbers are sorted
check_sorted() {
    prev=$1
    shift
    for num in "$@"; do
        if [ "$num" -lt "$prev" ]; then
            return 1
        fi
        prev=$num
    done
    return 0
}

# Test cases
echo "Testing push_swap..."

# Test 1: 3 numbers
echo -n "Test with 3 numbers (2 1 3): "
output=$(./push_swap 2 1 3)
count=$(echo "$output" | wc -l | tr -d ' ')
nums_sorted=$(echo "2 1 3" | tr ' ' '\n' | sort -n | tr '\n' ' ')
if [ "$count" -le 3 ]; then
    echo "OK ($count operations)"
else
    echo "KO (too many operations: $count)"
fi

# Test 2: 5 numbers
echo -n "Test with 5 numbers (5 2 1 4 3): "
output=$(./push_swap 5 2 1 4 3)
count=$(echo "$output" | wc -l | tr -d ' ')
if [ "$count" -le 12 ]; then
    echo "OK ($count operations)"
else
    echo "KO (too many operations: $count)"
fi

# Test 3: Random 100 numbers
echo -n "Test with 100 random numbers: "
nums=$(seq 1 100 | sort -R | tr '\n' ' ')
output=$(./push_swap $nums)
count=$(echo "$output" | wc -l | tr -d ' ')
if [ "$count" -le 700 ]; then
    echo "OK ($count operations)"
else
    echo "KO (too many operations: $count)"
fi

echo "Tests completed."
