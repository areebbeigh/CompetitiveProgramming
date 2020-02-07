t = int(input())
for i in range(t):
    n = int(input())
    array = list(map(int, input().split()))
    evens = []
    odds = []
    
    for i in array:
        if i % 2 == 0:
            evens.append(i)
        else:
            odds.append(i)

    if not odds:
        print('NO')
        continue

    if len(odds) % 2 != 0:
        print('YES')
        continue
    
    if not evens:
        print('NO')
    else:
        print('YES')
    