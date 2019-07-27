#!/usr/bin/python3.6

first_thousand = range(1,1000)

for a in first_thousand:
    for b in first_thousand:
        if b > a:
            c = (a*a + b*b)**0.5
            if float(c).is_integer() and c > b and a+b+c==1000:
                print(a*b*c)
                print(a,b,c)
                exit()
            # for c in first_thousand:
            #     if c > b and a*a + b*b == c*c and a + b + c == 1000:
            #         print(a*b*c)
            #         exit()