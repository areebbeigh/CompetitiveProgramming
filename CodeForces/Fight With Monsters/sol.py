#!/usr/bin/python3
# http://codeforces.com/contest/1296/problem/D
import math

n, a, b, k = map(int, input().split())
monsters = list(map(int, input().split()))

res = 0
losing_monsters = []
for m in monsters:
    x = math.ceil(m/(a+b))
    if x*(a+b) - m >= b:
        res += 1
        continue
    m = m - x*(a+b) + b
    losing_monsters.append(m)

# we'll use our power to kill monsters with lowest hp just before b wins
for m in sorted(losing_monsters):
    if a*k < m:
        continue
    k -= math.ceil(m/a)
    res += 1

print(res)