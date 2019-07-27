a = range(100, 1000)
b = range(100, 1000)

largest_palindrome = 0

for el_a in a:
    for el_b in b:
        prod = str(el_a * el_b)
        prod_reversed = list(prod)
        prod_reversed.reverse()
        prod_reversed = "".join(prod_reversed)
        if prod == prod_reversed and int(prod) > largest_palindrome:
            largest_palindrome = int(prod)

print(largest_palindrome)