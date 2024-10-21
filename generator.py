import random

size = 5
lower_bound = 0
upper_bound = 500

def generate_numbers(size, lower_bound, upper_bound):
    if size > (upper_bound - lower_bound + 1):
        raise ValueError("Range is too small for the number of unique numbers requested.")
    numbers = random.sample(range(lower_bound, upper_bound + 1), size)
    return ' '.join(map(str, numbers))

unique_numbers = generate_numbers(size, lower_bound, upper_bound)
print(unique_numbers)