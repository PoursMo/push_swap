#!/bin/bash

TEST_FILE="test_arguments.txt"

make re

while IFS= read -r args; do
    echo "Running test with arguments: $args"
    
    eval ./push_swap $args

done < "$TEST_FILE"
