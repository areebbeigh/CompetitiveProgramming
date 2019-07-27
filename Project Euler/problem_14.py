#!/usr/bin/python3.6
# def next_num(n):
#     if n % 2 == 0:
#         return n/2
#     return 3*n + 1

# def collatz(n):
#     chain = [n]

#     while chain[-1] != 1:
#         chain.append(next_num(chain[-1]))
    
#     return len(chain)

def count_chain(n):
    if n == 1:
        return 1
    
    if n % 2 == 0:
        return 1 + count_chain(n/2)
    
    return count_chain(3*n + 1)

largest_chain_length = 0
ans = 0

for i in range(500000, 1000000):
    # if i % 2 == 0:
    #     collatz_i = collatz(i/2) + 1
    # else:
    #     collatz_i = collatz(i)
    
    # if collatz_i > largest_chain_length:
    #     largest_chain_length = collatz_i
    #     ans = i
    if i % 2 == 0:
        chain_length = count_chain(i/2) + 1
    else:
        chain_length = count_chain((3*i+1)/2) + 2
    
    if chain_length > largest_chain_length:
        largest_chain_length = chain_length
        ans = i

print(ans)