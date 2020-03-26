#!/usr/bin/python3
# https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/annoying-chemistry-f5fb9556/
from math import gcd

def lcm(a, b):
    return (a*b)/gcd(a,b)

x, y, p, q = map(int, input().split(' '))
lcm1 = lcm(x, p)
lcm2 = lcm(y, q)
i = 1
while True:
    a = max(lcm1, lcm2) * i
    if lcm1 > lcm2:
        b3 = a/p
        b1 = a/x
        b2 = b3 * q/y
    else:
        b3 = a/q
        b2 = a/y
        b1 = b3 * p/x
    i += 1
    if b1 == int(b1) and b2 == int(b2) and b3 == int(b3):
        break
# print(lcm1, lcm2)
# print(b1, b2, b3)
# assert b1 == int(b1)
# assert b2 == int(b2)
# assert b3 == int(b3)

print(' '.join(map(lambda x: str(int(x)), (b1, b2, b3))))