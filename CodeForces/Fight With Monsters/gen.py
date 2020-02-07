#!/usr/bin/python3
import random

n,a,b,k = [random.randint(1, 10) for i in range(4)]
print(n, a, b, k)
for i in range(n):
    print(random.randint(1, 19), end=' ')
print()