#!/usr/bin/python3.6
def d(n):
    result = 0

    for i in range(1, n):
        if n % i == 0:
            result += i

    return result

amicable_numbers = set()

for i in range(1, 10001):
    d_i = d(i)
    if d(d_i) == i and d_i <= 10000 and d_i != i:
        amicable_numbers.add(i)
        amicable_numbers.add(d_i)

print(sum(amicable_numbers))