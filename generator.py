import random

def generate_numbers(size, lower_bound, upper_bound):
    if size > (upper_bound - lower_bound + 1):
        raise ValueError("Range is too small for the number of unique numbers requested.")
    numbers = random.sample(range(lower_bound, upper_bound + 1), size)
    return ' '.join(map(str, numbers))

size = 50            # Number of unique numbers to generate
lower_bound = 0      # Lower bound of the range
upper_bound = 500    # Upper bound of the range

unique_numbers = generate_unique_numbers(size, lower_bound, upper_bound)
print(unique_numbers)