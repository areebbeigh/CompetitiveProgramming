#!/usr/bin/python3
import random

x = []
for _ in range(4):
    x.append(str(random.randint(1,10)))

print(' '.join(x))