#!/usr/bin/python3.6
triangle = \
'''
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
'''

triangle = triangle.split('\n')[1:-1]
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

# triangle = triangle.split("\n")[1:-1]
# previous_index = 0
# next_index = None
# path_numbers = []

# # In the loop below we're first calculating the result of addition
# # of numbers in two consecutive rows in advance and then choosing
# # the path which has a greater sum for two choices.

# for row_number, row in enumerate(triangle):
#     row = list(map(int, row.split(' ')))
#     if row_number == 0:
#         path_numbers.append(row[0])
#     else:
#         choices = row[previous_index:previous_index+2]
#         if row_number < len(triangle) - 1:
#             if next_index:
#                 path_numbers.append(row[next_index])
#                 previous_index = next_index
#                 next_index = None
#                 continue

#             row_ahead = list(map(int, triangle[row_number + 1].split(' ')))
#             choices_ahead = row_ahead[previous_index:previous_index+3]
            
#             sums_ahead = [
#                 choices[0] + choices_ahead[0],
#                 choices[0] + choices_ahead[1],
#                 choices[1] + choices_ahead[1],
#                 choices[1] + choices_ahead[2]
#             ]
            
#             next_dict = {
#                 0: previous_index,
#                 1: previous_index+1,
#                 2: previous_index+1,
#                 3: previous_index+2
#             }

#             max_index = sums_ahead.index(max(sums_ahead))
#             next_index = next_dict[max_index]

#             if max_index > 1:
#                 path_numbers.append(choices[1])
#             else:
#                 path_numbers.append(choices[0])
#         else:
#             path_numbers.append(max(choices))

# for row_number, row in enumerate(triangle):
#     row = [int(i) for i in row.split(' ')]
#     if row_number == 0:
#         path_numbers.append(row[0])
#     else:
#         choices = [row[previous_index], row[previous_index + 1]]
#         path_numbers.append(max(choices))
#         if max(choices) == choices[1]:
#             previous_index += 1

