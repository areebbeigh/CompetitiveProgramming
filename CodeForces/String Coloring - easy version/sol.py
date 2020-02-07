#!/usr/bin/python3
#http://codeforces.com/contest/1296/problem/E1

class Node:
    idx = None
    letter = None
    color = False

    def __init__(self, idx, letter):
        assert idx >= 0 and letter
        self.dependencies = []
        self.dependents = []
        self.idx = idx
        self.letter = letter
    
    def __repr__(self):
        return f'Node<{self.idx, self.letter}>'

    def add_dependency(self, node):
        assert type(node) is Node
        self.dependencies.append(node)
        node.dependents.append(self)

input()
string = input()
nodes = [Node(*x) for x in enumerate(string)]

def check_dep_depth(node, max_depth=1):
    """Check if any node dep path exceeds max_depth"""
    if max_depth < 0:
        return False
    for n in node.dependencies:
        n.color = not node.color
        if not check_dep_depth(n, max_depth-1):
            return False
    return True

for idx, n1 in enumerate(nodes):
    if idx == len(nodes) - 1:
        continue
    for n2 in nodes[idx+1:]:
        if n2.letter < n1.letter:
            # print(n1, n2)
            n1.add_dependency(n2)

for n in nodes:
    if not check_dep_depth(n, 1):
        print('NO')
        exit()

print('YES')
print(''.join(str(int(n.color)) for n in nodes))