#!/usr/bin/python3

def build_partial_helper(adjacents, letter, visited, prefix=None):
    if not prefix:
        prefix = []
    if letter in visited:
        return False
    visited.add(letter)
    prefix.append(letter)
    for a in adjacents[letter]:
        if a not in visited:
            return build_partial_helper(adjacents, a, visited, prefix)
    return prefix

def build_partial(adjacents, letter, visited):
    visited.add(letter)
    res = []
    for idx, a in enumerate(adjacents[letter]):
        r = build_partial_helper(adjacents, a, visited)
        if not r:
            return False
        if idx == 0:
            r.reverse()
            res.extend(r)
            res.append(letter)
        else:
            res.extend(r)
    return res

for _ in range(int(input())):
    password = input()
    adjacents = dict([(chr(n+97), set()) for n in range(26)])
    for idx, c in enumerate(password):
        after = idx + 1
        before = idx - 1
        if after < len(password):
            adjacents[c].add(password[after])
        if before >= 0:
            adjacents[c].add(password[before])

    res = []
    visited = set()
    invalid = False

    for letter in adjacents.keys():
        if letter in visited or not adjacents[letter]:
            continue
        if len(adjacents[letter]) > 2:
            invalid = True
            break
        partial = build_partial(adjacents, letter, visited)
        if not partial:
            invalid = True
            break
        res.extend(partial)
    if invalid:
        print('NO')
        continue
    for n in range(26):
        a = chr(n+97)
        if a not in visited:
            res.append(a)
    print('YES')
    print(''.join(res))