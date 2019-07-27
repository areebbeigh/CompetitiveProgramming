not_divisible = True
x = 1

while 1:
    num = x*20

    remainders = []

    for i in (3,6,7,8,9,11,12,13,14,15,16,17,18,19):
        remainders.append(num % i)
    
    if sum(remainders) == 0:
        print("answer", num)
        break

    print(num)
    x += 1


