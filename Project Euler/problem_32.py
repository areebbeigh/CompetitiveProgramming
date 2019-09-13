#!/usr/bin/python3.6
from math import sqrt

def digit_frequency(num, freq):
    for i in str(num):
        if i == '0' or freq[int(i)] > 0:
            return False
        freq[int(i)] += 1
    
    return True

def all_ones(freq):
    for k, v in freq.items():
        if v != 1:
            return False
    return True

def factors(num):
    for i in range(1, int(sqrt(num)) + 1):
        if num % i == 0:
            yield i

def is_pandigital(num):
    for f in factors(num):
        freq = dict(zip(range(1, 10), [0] * 9))
        
        if not digit_frequency(num, freq):
            continue

        f2 = num//f
        
        if not (digit_frequency(f, freq) and digit_frequency(f2, freq)):
            continue

        if all_ones(freq):
            return True

    return False

res = 0

for i in range(2,10000):
    if is_pandigital(i):
        res += i

print(res)

