#!/usr/bin/python3.6
def fib():
    a = 0
    b = 1
    yield 1
    while 1:
        x = a + b
        yield x
        a = b
        b = x

fib_generator = fib()
fib_num = 0
index = 0

while len(str(fib_num)) < 1000:
    index += 1 
    fib_num = next(fib_generator)

print(index)