import random
import sys

cases = int(sys.argv[1]) if len(sys.argv) > 1 else 1
print(cases)
for x in range(cases):
    n = 3
    arr = [random.randint(1, 2000) for x in range(n)]
    print(n)
    for i in arr:
        print(i, end=' ')
    print()