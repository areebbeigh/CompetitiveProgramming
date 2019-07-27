#!/usr/bin/python3.6
import itertools
print(
    sorted(list(itertools.permutations(range(0, 10))))[999999]
)
