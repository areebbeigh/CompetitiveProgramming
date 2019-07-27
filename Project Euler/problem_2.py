def fib():
    a = 0
    b = 1
    while 1:
        x = a + b
        a = b
        b = x
        yield x

fib_gen = fib()
fib_terms = [0]

while fib_terms[-1] < 4000000:
    fib_terms += [next(fib_gen)]

res = sum(filter(lambda x: x%2==0, fib_terms))

print(res)