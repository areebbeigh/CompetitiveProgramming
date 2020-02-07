#!/usr/bin/python3
import random
import sys

cases = int(sys.argv[1]) if len(sys.argv) > 1 else 1
print(cases)
for i in range(cases):
    n = random.randint(1, 5)
    print(n)
    for _ in range(n):
        print(random.choice(('L', 'R', 'D', 'U')), end='')
    print()