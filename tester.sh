#!/bin/bash

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --checker) MODE="checker" ;;
        --count) MODE="count" ;; 
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

run_tests() {        
        if [ "$MODE" == "checker" ]; then
            RESULT=$(./push_swap $TEST | ./checker_linux $TEST)
        elif [ "$MODE" == "count" ]; then
            RESULT=$(./push_swap $TEST | wc -l)
        else
            RESULT=$(./push_swap $TEST)
        fi

        echo $RESULT
}

for i in {1..10}
do
	TEST=$(python3 generator.py)
	run_tests
done