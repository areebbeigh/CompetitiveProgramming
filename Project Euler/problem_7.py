#!/usr/bin/python3.6
import math

def is_prime(number):
    if number == 2:
        return True

    if number == 1 or number % 2 == 0:
        return False

    for i in range(math.ceil(math.sqrt(number)), 1, -1):
        if number % i == 0:
            return False
    return True

x = 0
prime = 0

while x != 10001:
    x += 1
    prime += 1
    while not is_prime(prime):
        prime += 1

print(prime)
