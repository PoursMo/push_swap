#!/bin/bash

PRINT=false
SIZE=5
NUMTESTS=10

make re

while [[ "$#" -gt 0 ]]; do
    case $1 in
        --checker | -ch) MODE="checker" ;;
        --count | -co) MODE="count" ;; 
		--print|-pr) PRINT=true ;;
		--size | -sz) SIZE=$2; shift ;;
		--numtests | -nt) NUMTESTS=$2; shift ;;
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

for i in $(seq 1 $NUMTESTS);
do
	TEST=$(python3 generator.py $SIZE -500 500)
	if [ "$PRINT" = true ]; then
		echo $TEST
	fi
	run_tests
done