#!/usr/bin/python3.6

def is_abundant(n):
    product_sum = 0

    for i in range(1, n):
        if n % i == 0:
            product_sum += i
    
    return product_sum > n

abundant_nums = []

for i in range(1, 28124):
    if is_abundant(i):
        abundant_nums.append(i)

abundant_num_sums = set()

for i in abundant_nums:
    for n in abundant_nums:
        abundant_num_sums.add(i + n)

# print(list(abundant_num_sums)[0], 24 in abundant_num_sums)

result = 0

for i in range(1, 28124):
    if i not in abundant_num_sums:
        result += i

print(result)

