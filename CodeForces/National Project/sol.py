#!/usr/bin/python3
import math

for _ in range(int(input())):
    n, g, b = map(int, input().split(' '))
    min_good_days = math.ceil(n/2)
    if min_good_days/g <= 1:  # we got all the days we need
        print(n)
        continue
    bad_days = (math.ceil(min_good_days/g) - 1) * b
    res = min_good_days + bad_days
    if res - n < 0:
        res += n - res
    print(res)