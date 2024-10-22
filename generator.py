import random
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('size', type=int)
parser.add_argument('lower_bound', type=int)
parser.add_argument('upper_bound', type=int)
args = parser.parse_args()

def generate_numbers(size, lower_bound, upper_bound):
    if size > (upper_bound - lower_bound + 1):
        raise ValueError("Range is too small for the number of unique numbers requested.")
    numbers = random.sample(range(lower_bound, upper_bound + 1), size)
    return ' '.join(map(str, numbers))

unique_numbers = generate_numbers(args.size, args.lower_bound, args.upper_bound)
print(unique_numbers)