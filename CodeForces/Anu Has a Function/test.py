#!/usr/bin/python3
import random
from functools import reduce
from itertools import permutations

def f(x, y):
    return (x | y) - y

def comp_arr(arr):
    pass

for i in range(100):
    i = random.choice([1, 10])
    arr = [random.randint(1, 20) for __ in range(i)]
    m = reduce(f, arr)
    for a in permutations(arr):
        x = reduce(f, a)
        if x > m:
            print('errored', a, (arr), x, m)
            m = x
            arr = a
    print(arr, m)
    print('----')
    # input()
