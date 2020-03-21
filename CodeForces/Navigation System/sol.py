# http://codeforces.com/contest/1320/problem/B
from collections import deque


class Graph:
    def __init__(self):
        self.edges = {}
        self.distances = {}
        self.shortest_paths = {}

    def join_nodes(self, a, b):
        if a not in self.edges:
            self.edges[a] = set()
        self.edges[a].add(b)

    def bfs_mark_distances(self, source):
        queue = deque([source])
        visited = set([source])
        self.distances[source] = 0

        while queue:
            parent = queue.popleft()
            for n in self.edges[parent]:
                if n in visited:
                    continue
                self.distances[n] = self.distances[parent] + 1
                # print('-', n, parent, self.distances[n])
                queue.append(n)
                visited.add(n)

    def count_shortest_paths(self):
        for e, children in self.edges.items():
            for c in children:
                if self.distances[e] == self.distances[c] - 1:
                    if c not in self.shortest_paths:
                        self.shortest_paths[c] = 0
                    self.shortest_paths[c] += 1

graph = Graph()
n, m = map(int, input().split(' '))

for _ in range(m):
    a, b = map(int, input().split(' '))
    graph.join_nodes(b, a) # creating a transpose graph

input()
path = list(map(int, input().split(' ')))
destination = path[-1]
graph.bfs_mark_distances(destination)
graph.count_shortest_paths()

min_rebuild = 0
max_rebuild = 0
for i in range(len(path)-1):
    if graph.distances[path[i+1]] != graph.distances[path[i]] - 1:
        min_rebuild += 1
    if (graph.distances[path[i+1]] != graph.distances[path[i]] - 1
        or graph.shortest_paths[path[i]] > 1):
        max_rebuild += 1
print(min_rebuild, max_rebuild)
