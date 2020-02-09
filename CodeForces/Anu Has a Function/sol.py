#!/usr/bin/python3
# http://codeforces.com/contest/1300/problem/C

# Segment tree: we'll only query the total ORs (root), so no query()
class SegTree:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [None for _ in range(2*len(arr)*2)]
        self.build()
    
    def build(self, node=1, start=0, end=None):
        if end == None:
            end = len(self.arr) - 1
        # print(start, end, node, self.tree)
        # if node == 4:
            # input()
        if start == end:
            # print(start, node, len(self.arr), len(self.tree))
            self.tree[node] = self.arr[start]
        else:
            mid = (start + end)//2
            # print('->', mid)
            self.build(node*2, start, mid)
            self.build(node*2 + 1, mid+1, end)
            self.tree[node] = self.tree[node*2] | self.tree[node*2 + 1]
    
    def update(self, idx, val, node=1, start=0, end=None):
        if end == None:
            end = len(self.arr) - 1
        if start == end:
            self.arr[idx] = val
            self.tree[node] = val
        else:
            mid = (start + end)//2
            if start <= idx <= mid:
                self.update(idx, val, 2*node, start, mid)
            else:
                self.update(idx, val, 2*node + 1, mid+1, end)
            self.tree[node] = self.tree[2*node] | self.tree[2*node + 1]

input()
arr = list(map(int, input().strip().split(' ')))
tree = SegTree(arr.copy())
cumilative_or = [None for _ in range(len(arr))]

max_f = -1
first_idx = -1

for idx, a in enumerate(arr):
    tree.update(idx, 0)
    f = (a | tree.tree[1]) - tree.tree[1]
    if f > max_f:
        max_f = f
        first_idx = idx
    tree.update(idx, a)

# print(arr[first_idx], first_idx, max_f)

print(arr[first_idx], end=' ')
for idx, a in enumerate(arr):
    if idx == first_idx:
        continue
    print(a, end=' ')
print()
