# Brute force solution

def check_odd_sum(arr, replaced={}):
    if sum(arr) % 2 != 0:
        return True
    
    for replacing in arr:
        for j, a in enumerate(arr):
            if a == replacing or j not in replaced:
                continue
            arr[j] = replacing
            replaced.add(j)
            if check_odd_sum(arr, replaced):
                return True
            arr[j] = a
            replaced.remove(j)

t = int(input())
for i in range(t):
    n = int(input())
    array = list(map(int, input().split()))
    if check_odd_sum(array):
        print('YES')
    else:
        print('NO')