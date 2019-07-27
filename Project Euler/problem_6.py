def sum_first_n_squares(n):
    return (n*(n+1)*(2 * n + 1)/6)

def sum_first_n(n):
    return n*(n+1)/2

print(sum_first_n(100)**2 - sum_first_n_squares(100))