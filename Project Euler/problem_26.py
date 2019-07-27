#!/usr/bin/python3.6
def get_recurring_cycle_by_long_division(denominator):
    numerator = 10
    quotients = []
    remainders = []
    first = True

    while numerator % denominator != 0:
        remainders.append(numerator)
        numerator *= 10 if numerator < denominator and not first else 1
        quotient = numerator // denominator
        numerator = numerator % denominator
        # print(numerator, denominator)
        if numerator in remainders and not first:
            break
        quotients.append(quotient)
        first = False
    
    return ''.join(map(str, quotients))


longest_cycle = ''
d = ''

for i in range(2,1000):
    cycle = get_recurring_cycle_by_long_division(i)
    print(i, cycle)
    if cycle:
        if len(cycle) > len(longest_cycle):
            longest_cycle = cycle
            d = i

print()
print(d, longest_cycle, len(longest_cycle))