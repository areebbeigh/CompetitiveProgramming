#!/usr/bin/python3
for _ in range(int(input())):
    s = int(input())
    spent = 0

    while s:
        spent += int(s/10) * 10
        s = s % 10 + int(s/10)
        if s < 10:
            spent += s
            s = 0

    print(spent)
