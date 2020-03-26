for i in range(int(input())):
    _, B = map(int, input().split(' '))
    houses = list(map(int, input().split(' ')))
    houses.sort()
    res = 0
    for h in houses:
        B -= h
        if B >= 0:
            res += 1
        else:
            break
    print('Case #{}: {}'.format(i+1, res))