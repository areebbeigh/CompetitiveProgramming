#!/usr/bin/python3
import sys
n = int(input())
cities = list(map(int, input().strip().split(' ')))
max_beauty_memo = {}

sys.setrecursionlimit(100000)
def solve(start):
    b1 = cities[start]
    rv = b1
    if max_beauty_memo.get(start):
        return max_beauty_memo[start]
    for i2 in range(start+1, len(cities)):
        b2 = cities[i2]
        if b2 - b1 == i2 - start:
            res = solve(i2)
            rv = max(b1+res, rv)
    max_beauty_memo[start] = rv
    return rv

res = 0
for i in range(len(cities)):
    res = max(res, solve(i))

print(res)