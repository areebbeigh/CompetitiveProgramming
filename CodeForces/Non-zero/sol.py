#!/usr/bin/python3

for _ in range(int(input())):
    input()
    arr_sum = 0
    prod = 1
    steps = 0
    count = {}
    arr = map(int, input().split(' '))
    max_el = -10**9
    min_el = 10**9
    for n in arr:
        if n == 0:
            n += 1
            steps += 1
        arr_sum += n
        prod *= n
        max_el = max(n, max_el)
        min_el = min(n, min_el)
        count[n] = count.get(n, 0) + 1
    assert prod != 0
    if arr_sum != 0:
        print(steps)
        continue
    if max_el > 0:
        steps += 1
        count[max_el] -= 1
        count[max_el + 1] = count.get(max_el + 1, 0) + 1
        print(steps)
        continue
    n = min(min_el, max_el) # we add to the smaller of the two so we don't hit 0
    if n + 1 != 0:
        steps += 1
        count[n] -= 1
        count[n + 1] = count.get(min_el + 1, 0) + 1
        print(steps)
        continue
    steps += 2
    count[n] -= 1
    count[n + 2] = count.get(n + 2, 0) + 1
    print(steps)
