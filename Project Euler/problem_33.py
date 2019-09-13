#!/usr/bin/python3.6
def denominators(num):
    for i in range(10, 100):
        if i == num:
            continue
        for d in str(i):
            if d != '0' and d in str(num):
                yield i

def reduce_terms(a, b):
    for d in str(a):
        if d in str(b):
            a = int(str(a).replace(d, '', 1))
            b = int(str(b).replace(d, '', 1))
            break
    else:
        raise ValueError()    
    return a, b
    

def curious_frac(a, b):
    a, b = reduce_terms(a, b)
    return a/b if b != 0 else -1

a = 1
b = 1

for i in range(10, 100):
    for j in denominators(i):
        if j > i and i/j == curious_frac(i, j):
            a *= i
            b *= j

print(b//a)

