import time
start = time.time()

n = 7
x = 28

while 1:
    # print(n, x)

    factors = set((1, x))

    # for i in range(2, x):
    #     if not x % i:
    #         factors += [i]

    for i in range(2, int(x**0.5 + 1)):
        if not x % i:
            factors = factors.union(set((i, x/i)))
    
    # print(len(factors))

    if len(factors) > 500:
        break

    n += 1
    x = sum(range(1, n+1))

print(x)

print("time taken", time.time() - start)
