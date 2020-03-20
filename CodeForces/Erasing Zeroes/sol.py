#!/usr/bin/python3

for _ in range(int(input())):
    string = input()
    res = 0
    temp_count = 0
    encountered_one = False
    for c in string:
        if not encountered_one and c == '1':
            encountered_one = True
        elif encountered_one and c == '0':
            temp_count += 1
        elif encountered_one and c == '1':
            res += temp_count
            temp_count = 0
    print(res)