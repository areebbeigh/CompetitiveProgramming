n = 0
x = []
y = 200000

while n < 200000:
    n += 1
    y += 1
    x.append(str(y))

print(n)
print(' '.join(x))