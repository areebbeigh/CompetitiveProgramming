#!/usr/bin/python3.6
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)


print(
    sum(map(lambda x: int(x), str(factorial(100))))
)
