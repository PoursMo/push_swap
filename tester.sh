#!/bin/bash

# Path to your push_swap executable
PUSH_SWAP="./push_swap"

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'  # No color / reset

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        --checker) MODE="checker" ;;   # Use checker_Mac
        --count) MODE="count" ;;       # Count lines with wc -l
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

# Generate test cases using the Python script and store them in variables
TESTS=$(python3 generator.py)

# Function to run the tests
run_tests() {
    echo "Running tests..."

    # Read each line from the Python output (the generated test cases)
    while IFS= read -r TEST; do
        echo "Test: $TEST"
        
        # Adjust behavior based on MODE
        if [ "$MODE" == "checker" ]; then
            RESULT=$($PUSH_SWAP $TEST | ./checker_Mac $TEST)
        elif [ "$MODE" == "count" ]; then
            RESULT=$($PUSH_SWAP $TEST | wc -l)
        else
            RESULT=$($PUSH_SWAP $TEST)
        fi

        # Check the result and print in color
        if [[ "$RESULT" == "OK" ]]; then
            echo -e "${GREEN}Result: OK${NC}"
        elif [[ "$RESULT" == "KO" ]]; then
            echo -e "${RED}Result: KO${NC}"
        else
            echo "Result: $RESULT"
        fi

        echo "-----------------------------------"
    done <<< "$TESTS"
}

# Run the tests
run_tests