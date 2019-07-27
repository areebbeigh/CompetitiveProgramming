#!/usr/bin/python3.6

import os
import sys

if len(sys.argv) >= 2:
    number = int(sys.argv[1])
else:
    number = 0
    for f in os.listdir():
        try:
            num = int(f.replace("problem_", "").replace(".py", ""))
            if num > number:
                number = num
        except:
            continue
    
    number += 1


filename = "problem_{}.py".format(number)

with open(filename, "w") as f:
    f.write("#!/usr/bin/python3.6\n")

os.system("chmod +x " + filename)
os.system("code problem_{}.py".format(number))
