# https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/minimum-and-xor-or-6a05bbd4/
for _ in range(int(input())):
    input()
    A = list(map(int, input().split(' ')))
    A.sort()
    res = 10**9 + 1
    for idx in range(len(A)-1):
        r = (A[idx] & A[idx+1]) ^ (A[idx] | A[idx+1])
        res = min(res, r)
    print(res)