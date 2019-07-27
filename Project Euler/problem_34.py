#!/usr/bin/python3.6
import math

nums = []

for i in range(999999, 2, -1):
    digits = list(map(int, str(i)))
    if sum(map(math.factorial, digits)) == i:
      nums.append(i)

print(sum(nums), nums)
