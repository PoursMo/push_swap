#!/bin/bash

TEST_FILE="test_arguments.txt"

cflag -g *.c -o push_swap

while IFS= read -r args; do
    echo "Running test with arguments: $args"
    
    eval valgrind --leak-check=full --track-origins=yes ./push_swap $args

done < "$TEST_FILE"
