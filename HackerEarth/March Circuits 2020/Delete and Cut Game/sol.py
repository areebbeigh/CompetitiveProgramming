# https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/delete-and-cut-game-91969de1/
import math
import sys
sys.setrecursionlimit(10**5+1)

class Node:
    def __init__(self, data):
        self.data = data
        self.nodes = set()
        self.components = 0 # no. of nodes I'm connected to (in dfs tree)
        self.n = None # discovery time
        self.l = None # lowest node reachable
        self.parent = None

    def __eq__(self, other):
        return self.data == other.data

    def __hash__(self):
        return self.data

    # def __repr__(self):
    #     return f'Node<{self.data, self.parent is None}>'


class Graph:
    def __init__(self):
        self.nodes = {}
        self.counter = 0
        self.bridges = []

    def add_edge(self, a, b):
        if a not in self.nodes:
            self.nodes[a] = Node(a)
        if b not in self.nodes:
            self.nodes[b] = Node(b)
        self.nodes[a].nodes.add(self.nodes[b])
        self.nodes[b].nodes.add(self.nodes[a])

    def bridges_helper(self, v, visited):
        visited.add(v)
        v.n = v.l = self.counter
        self.counter += 1
        # print('c:', v)

        for w in v.nodes:
            if w not in visited:
                w.parent = v
                self.bridges_helper(w, visited)
                v.l = min(w.l, v.l)

                if w.l > v.n:
                    # print('cut edge:', v, w)
                    self.bridges.append((v, w))
            else:
                if v.parent is not None and v.parent != w:
                    # print('updating:', v, w)
                    v.l = min(v.l, w.n)
                continue

    def find_bridges(self):
        visited = set()
        for v in self.nodes.values():
            # print(v)
            if v not in visited:
                self.bridges_helper(v, visited)

    def count_connected_helper(self, node1, node2, visited):
        visited.add(node1)
        rv = 1
        for w in node1.nodes:
            if w == node2 or w in visited:
                continue
            rv += self.count_connected_helper(w, node2, visited)
        return rv

    def count_connected(self, node1, node2):
        visited = set()
        c1 = self.count_connected_helper(node1, node2, visited)
        return c1, N-c1

N, M = map(int, input().split(' '))
graph = Graph()

for _ in range(M):
    a, b = map(int, input().split(' '))
    graph.add_edge(a, b)

# graph.count_connected()
graph.find_bridges()

a_wins = 0
b_wins = 0

for node1, node2 in graph.bridges:
    components1, components2 = graph.count_connected(node1, node2)
    if components1 % 2 == 0 and components2 % 2 == 0:
        a_wins += 1
    else:
        b_wins += 1

def modInverse(b,m):
    g = math.gcd(b, m)
    if (g != 1):
        # print("Inverse doesn't exist")
        return -1
    else:
        # If b and m are relatively prime,
        # then modulo inverse is b^(m-2) mode m
        return pow(b, m - 2, m)

def modDivide(a,b,m):
    a = a % m
    inv = modInverse(b,m)
    if(inv == -1):
        raise Exception
    else:
        return (inv*a) % m

t = a_wins + b_wins
m = 1000000007
if t == 0:
    print(0, 0)
else:
    print(modDivide(a_wins, t, m), modDivide(b_wins, t, m))