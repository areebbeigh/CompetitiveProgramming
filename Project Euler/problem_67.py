#!/usr/bin/python3.6
with open('p067_triangle.txt', 'r') as f:
    triangle = f.readlines()

triangle = [line.replace('\n', '') for line in triangle]
reversed_triangle = [list(map(int, line.split(' '))) for line in reversed(triangle)]

def reduce_triangle(triangle):
    max_sums = []
    row_ahead = triangle[1]
    current_row = triangle[0]
    
    if len(row_ahead) == 1:
        return max(current_row[0] + row_ahead[0], current_row[1] + row_ahead[0])

    for num_index, num in enumerate(row_ahead):
        choices = current_row[num_index:num_index+2]
        max_sums.append(max(num + choices[0], num + choices[1]))

    return reduce_triangle([max_sums] + triangle[2:])


print(reduce_triangle(reversed_triangle))

