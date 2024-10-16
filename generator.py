import random

# Function to generate a list of numbers from 0 to 500, with edge cases included
def generate_test_series():
    # Generate numbers from 0 to 500
    numbers = list(range(101))
    
    # Edge case 1: Sorted in ascending order
    ascending_order = numbers.copy()

    # Edge case 2: Sorted in descending order
    descending_order = numbers[::-1]

    # Edge case 4: Random order
    random_order = numbers.copy()
    random.shuffle(random_order)
    
    return {
        "ascending_order": ascending_order,
        "descending_order": descending_order,
        "random_order": random_order,
    }

# Generate the test cases
test_series = generate_test_series()

# Print all test cases as space-separated numbers without labels
for series in test_series.values():
    print(" ".join(map(str, series)))
