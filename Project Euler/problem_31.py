#!/usr/bin/python3.6
coins = [200, 100, 50, 20, 10, 5, 2, 1]

def count(coins, n, coins_sum):
    if coins_sum == 0:
        return 1
    
    if coins_sum < 0 or n < 0:
        return 0

    return count(coins, n, coins_sum - coins[n]) + count(coins, n - 1, coins_sum)

print(count(coins, len(coins) - 1, 200))
