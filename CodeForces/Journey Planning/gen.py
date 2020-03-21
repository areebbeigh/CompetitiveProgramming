#!/usr/bin/python3
import random
n = 200000
x = []
for _ in range(n):
    x.append(str(random.randint(200000, 400000)))
print(n)
print(' '.join(x))