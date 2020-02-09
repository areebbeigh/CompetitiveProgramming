#!/usr/bin/python3
from collections import deque

class Node:
    data = None

    def __repr__(self):
        return f'Node<{self.data}>'

    def __eq__(self, other):
        return self.data == other.data

    def __hash__(self):
        return self.data

    def __init__(self, data):
        self.nodes = set()
        self.weights = {}
        self.data = data
    
    def add_node(self, other):
        self.nodes.add(other)
        other.nodes.add(self)
    
    def set_weight(self, other, weight):
        self.weights[other] = weight
        other.weights[self] = weight

cache = {}

def find_path(source, destination):
    queue = deque([source])
    parent_map  = {}
    visited = set()
    while queue:
        node = queue.popleft()
        visited.add(node)
        if node == destination:
            break
        for n in node.nodes:
            if n in visited:
                continue
            parent_map[n] = node
            queue.append(n)
    
    path = [destination]
    while True:
        parent = parent_map.get(node, None)
        if not parent:
            break
        path.append(parent)
        node = parent
    return path

nodes = {}
edges = []
path_weights = []

for _ in range(int(input()) - 1):
    a, b = map(int, input().split(' '))
    nodes[a] = nodes.get(a, Node(a))
    nodes[b] = nodes.get(b, Node(b))
    nodes[a].add_node(nodes[b])
    edges.append((a, b))

for _ in range(int(input())):
    a, b, w = map(int, input().split(' '))
    path = find_path(nodes[a], nodes[b])
    path_weights.append((path, w))
    # print(a, b, path)
    i = 0
    prev = path[i]
    while i < len(path)-1:
        i += 1
        next = path[i]
        if prev.weights.get(next, -1) < w:
            prev.set_weight(next, w)
        prev = next

for path, w in path_weights:
    i = 0
    prev = path[i]
    min_w = 10**6 + 1
    while i < len(path)-1:
        i += 1
        next = path[i]
        x = prev.weights.get(next, None)
        if x:
            min_w = min(x, min_w)
        if min_w < w:
            break
        prev = next
    if min_w != w:
        print(-1)
        exit()

for a, b in edges:
    print(nodes[a].weights.get(nodes[b], 1), end=' ')
print()
