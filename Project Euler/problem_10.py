#!/usr/bin/python3.6
import math

def is_prime(n):
    if n == 1:
      return False
  
    if n == 2:
      return True

    for i in range(int(math.sqrt(n)), 1, -1):
        if n % i == 0:
          return False
    return True

print(sum([i for i in range(1, 2000000) if is_prime(i)]))
