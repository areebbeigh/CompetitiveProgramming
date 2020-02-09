#!/usr/bin/python3
import random

n = random.randint(1, 20)
print(n)
for _ in range(n):
    print(random.randint(1, 20), end=' ')
print()
