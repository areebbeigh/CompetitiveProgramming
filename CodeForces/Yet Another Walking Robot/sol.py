#!/usr/bin/python3
# http://codeforces.com/contest/1296/problem/C

for _ in range(int(input())):
    input()
    steps = input()
    visited = {0: {0: -1}}
    pos_x = 0
    pos_y = 0
    res = None
    min_length = None
    for i, s in enumerate(steps):
        if s == 'L':
            pos_x -= 1
        if s == 'R':
            pos_x += 1
        if s == 'U':
            pos_y += 1
        if s == 'D':
            pos_y -= 1
        
        start = None
        if visited.get(pos_x):
            start = visited.get(pos_x).get(pos_y)
        if start != None:
            path_length = i - start
            if min_length == None or path_length < min_length:
                if start == -1:
                    res = f'{1} {i + 1}'
                else:
                    res = f'{start + 2} {i + 1}'
                min_length = path_length

        visited[pos_x] = visited.get(pos_x, {})
        visited[pos_x][pos_y] = i
        # print(visited, s)
    if res:
        print(res)
    else:
        print(-1)