#!/usr/bin/python3.6
import math

num = 600851475143

def is_prime(number):
    if number == 2:
        return True

    for i in range(2, math.ceil(math.sqrt(number))):
        if number % i == 0:
            return False
    return True

for i in range(math.ceil(math.sqrt(num)), 1, -1):
    if num % i == 0:
        if is_prime(i):
            print(i)
            break
