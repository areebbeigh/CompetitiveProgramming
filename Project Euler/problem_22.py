#!/usr/bin/python3.6
with open("p022_names.txt", "r") as f:
    names = f.read().replace("\n", "").replace("\"", "").split(",")
    names.sort()

# def get_letter_index(l):
#     alphabet = list("abcdefghijklmnopqrstuvwxyz")
#     return alphabet.index(l.lower()) + 1

result = 0

for name in names:
    result += sum(map(lambda x: ord(x) - 64, list(name))) * (names.index(name) + 1)

print(result)