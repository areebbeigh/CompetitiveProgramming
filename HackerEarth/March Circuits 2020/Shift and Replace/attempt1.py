# https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/shift-and-replace-d96fc236/

N = int(input())
A = list(map(int, input().split(' ')))
Q = int(input())

best_start = 0
best_score = 0
score = [0 for _ in range(N)]
elements_in_pos = {}

for idx, a in enumerate(A):
    i = idx - (a-1)
    if  0 <= i < len(score):
        score[i] += 1
        if score[i] > best_score:
            best_score = score[i]
            best_start = i
    i2 = a-1
    if i2 <= idx:
        k = idx - i2
    else:
        k = idx + (len(A) - i2)
    if k not in elements_in_pos:
        elements_in_pos[k] = 0
    elements_in_pos[k] += 1

# print(A)
# print(score)
# print(elements_in_pos)

for _ in range(Q):
    idx, b = map(int, input().split(' '))
    idx -= 1
    a = A[idx]
    i1 = idx - (a-1)
    i2 = idx - (b-1)
    i1_ = a - 1
    i2_ = b - 1

    if i1_ <= idx:
        k1 = idx - i1_
    else:
        k1 = idx + (len(A) - i1_)
    if i2_ <= idx:
        k2 = idx - i2_
    else:
        k2 = idx + (len(A) - i2_)

    if 0 <= i1 < len(score):
        score[i1] -= 1
    elements_in_pos[k1] -= 1

    if 0 <= i2 < len(score):
        score[i2] += 1
        if score[i2] > best_score:
            best_score = score[i2]
            if best_score == score[i2]:
                if i2 < best_start:
                    best_start = i2
            else:
                best_start = i2

    if k2 not in elements_in_pos:
        elements_in_pos[k2] = 0
    elements_in_pos[k2] += 1
    A[idx] = b
    if i1 == best_start:
        best_score = max(score)
        best_start = score.index(best_score)
    in_pos = 0 if best_start not in elements_in_pos else elements_in_pos[best_start]
    cost = best_start + len(A) - in_pos
    print(cost)