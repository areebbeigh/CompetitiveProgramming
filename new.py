#!/usr/bin/python3
import os
import sys

template = None

with open('template.cpp', 'r') as f:
    template = f.read()

if len(sys.argv) > 1:
    with open(sys.argv[1], 'w') as f:
        f.write(template)
        os.system('code ' + sys.argv[1])

