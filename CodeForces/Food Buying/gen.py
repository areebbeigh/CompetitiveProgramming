#!/usr/bin/python3
import random
import sys

cases = int(sys.argv[1]) if len(sys.argv) > 1 else 1
print(cases)
for i in range(cases):
    print(random.randint(1, 10**9))