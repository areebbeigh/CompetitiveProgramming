# https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/shift-and-replace-d96fc236/

class Node:
    def __init__(self):
        self.data = None
        self.idx = None

    # def __repr__(self):
    #     return f'Node<{self.idx, self.data}>'

    def merge(self, left, right):
        if left.data > right.data:
            self.data = left.data
            self.idx = left.idx
        else:
            self.data = right.data
            self.idx = right.idx
        if left.data == right.data:
            self.idx = min(left.idx, right.idx)


class SegTree:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [self.get_new_node() for _ in  range(4*len(arr))]
        self.build()

    def get_new_node(self):
        return Node()

    def build(self, node=1, l=0, h=None):
        if h is None:
            h = len(self.arr)-1
        if l == h:
            self.tree[node].data = self.arr[l]
            self.tree[node].idx = l
        else:
            mid = (l + h)//2
            left_child = 2*node
            right_child = (2*node) + 1
            self.build(left_child, l, mid)
            self.build(right_child, mid+1, h)
            self.tree[node].merge(self.tree[left_child], self.tree[right_child])

    def update(self, idx, val, node=1, l=0, h=None):
        if h is None:
            h = len(self.arr) - 1

        if l == h:
            self.tree[node].data += val
            self.arr[idx] += val
            return

        mid = (l + h)//2
        left_child = 2*node
        right_child = 2*node + 1
        if l <= idx <= mid:
            self.update(idx, val, left_child, l, mid)
        else:
            self.update(idx, val, right_child, mid+1, h)
        self.tree[node].merge(self.tree[left_child], self.tree[right_child])

    def query_top(self):
        return self.tree[1]

N = int(input())
A = list(map(int, input().split(' ')))
Q = int(input())

elements_in_pos = {}
scores = SegTree([0] * N)

def solve_satisfying_shifts(n, real_index, update=1):
    if n > N:
        return
    identity_pos = n-1
    if identity_pos <= real_index:
        shifts = real_index - identity_pos
    else:
        shifts = real_index + (N - identity_pos)
    if not (0 <= shifts < N):
        return
    if shifts not in elements_in_pos:
        elements_in_pos[shifts] = 0
        assert update == 1
    elements_in_pos[shifts] += update

def solve_score(n, real_index, update=1):
    i = idx - (a-1)
    if 0 <= i < N:
        scores.update(i, update)

for idx, a in enumerate(A):
    solve_score(a, idx)
    solve_satisfying_shifts(a, idx)
# print('---')
# print(scores.query_top())

for _ in range(Q):
    idx, b = map(int, input().split(' '))
    idx -= 1
    solve_score(A[idx], idx, -1)
    solve_satisfying_shifts(A[idx], idx, -1)
    A[idx] = b
    solve_score(A[idx], idx, 1)
    solve_satisfying_shifts(A[idx], idx, 1)

    start = scores.query_top()
    # print(start)
    lshifts = start.idx
    cost = lshifts + (N - elements_in_pos[lshifts])
    print(cost)

