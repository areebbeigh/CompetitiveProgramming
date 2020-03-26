N = int(input())
no_handshake_edges = {}
no_handshakes = 0

for _ in range(10):
    f = None
    for idx, id in enumerate(map(int, input().split(' '))):
        if idx == 0:
            f = id
            if id not in no_handshake_edges:
                no_handshake_edges[id] = set()
            continue
        if id in no_handshake_edges and f in no_handshake_edges[id]:
            continue
        no_handshake_edges[f].add(id)
        no_handshakes += 1

print(N*(N-1)//2 - no_handshakes)