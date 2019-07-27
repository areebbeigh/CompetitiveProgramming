#!/usr/bin/python3
import os
import sys

template = 'template.cpp'
template_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), template)
with open(template_path, 'r') as f:
    template = f.read()

if len(sys.argv) > 1:
    file_path = os.path.join(os.getcwd(), sys.argv[1])
    with open(file_path, 'w') as f:
        f.write(template)
        os.system('code ' + file_path)

