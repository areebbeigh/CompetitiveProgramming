#!/usr/bin/python3.6
from math import sqrt

def is_prime(n):
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def rotations(n):
    yield n
    n = str(n)
    rotation = n[-1] + n[:-1]
    while rotation != n:
        yield int(rotation)
        rotation = rotation[-1] + rotation[:-1]

def is_circular(n, primes):
    rots = rotations(n)
    res = True
    for p in rots:
        if p not in primes:
            res = False
            break
    return res

def count_circular_primes(maximum):
    primes = set()
    count = 0
    for i in range(2, 1000001):
        if is_prime(i):
            primes.add(i)
    for p in primes:
        if p > maximum:
            continue
        if is_circular(p, primes):
            count += 1
    return count
print(count_circular_primes(1000000))
# print(list(rotations(197)))

