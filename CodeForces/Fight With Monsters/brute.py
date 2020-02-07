#!/usr/bin/python3
# Brute force solution
import math

n, a, b, k = map(int, input().split())
monsters = list(map(int, input().split()))

def attack(monster_hp, a, b, turn):
    return monster_hp - b if turn % 2 == 0 else monster_hp - a

res = 0
for m in sorted(monsters):
    turn = 1
    while attack(m, a, b, turn) > 0:
        m = attack(m, a, b, turn)
        turn += 1
    # if it's a's turn
    if turn % 2 != 0:
        res += 1
        continue
    # skip if we can kill the monster by not letting b play
    if attack(m, a * k, b, turn + 1) > 0:
        continue
    k -= math.ceil(m/a)
    res += 1

print(res)