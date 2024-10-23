#!/bin/bash

TEST_FILE="test_arguments.txt"

make re

while IFS= read -r args; do
	IFS= read -r expected
    echo "Running test with arguments: $args"
    eval ./push_swap $args
	echo expected: $expected

done < "$TEST_FILE"
