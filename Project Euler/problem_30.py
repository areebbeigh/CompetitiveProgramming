#!/usr/bin/python3.6

result = 0

for i in range(2, 99999999):
    if i == sum(map(lambda x: int(x)**5, str(i))):
        result += i
        print(result)
