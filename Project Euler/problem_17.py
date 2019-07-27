#!/usr/bin/python3.6
import inflect

ie = inflect.engine()

print(
    sum([
        len(ie.number_to_words(i).replace("-", "").replace(" ", ""))
        for i in range(1, 1001)
    ])
)
    
