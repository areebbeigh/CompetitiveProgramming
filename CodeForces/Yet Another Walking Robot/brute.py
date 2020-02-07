#!/usr/bin/python3
# Brute force solution: count deltas

for _ in range(int(input())):
    input()
    steps = input()
    deltas = dict(zip(
        range(len(steps)), 
        [[0,0, ''] for _ in range(len(steps))]))
    
    res = None
    min_len = None
    for step_index, s in enumerate(steps):
        for i, pos in deltas.items():
            if i > step_index:
                break
            if s == 'L':
                pos[0] -= 1
            if s == 'R':
                pos[0] += 1
            if s == 'U':
                pos[1] += 1
            if s == 'D':
                pos[1] -= 1
            if pos == [0, 0, '']:
                st = i + 1
                ed = step_index + 1
                assert 1 <= st <= ed
                assert st <= ed <= len(steps)
                pos[-1] = f'{st} {ed}'
                if not res or (ed - st) < min_len:
                    res = pos[-1]
                    min_len = ed - st
        # print(deltas)
    if res:
        print(res)
    else:
        print(-1)