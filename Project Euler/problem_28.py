#!/usr/bin/python3.6

end = 9
grid = 3
target_grid = 1001

diagnol_members = [1, 3, 5, 7, 9]

while grid < target_grid:
    grid += 2
    diag_member = (end + 1) + (grid - 2)
    diagnol_members.append(diag_member)
    
    for i in range(1,4):
        diag_member = diag_member + grid - 1
        diagnol_members.append(diag_member)
    
    end = diagnol_members[-1]

# print(diagnol_members)

print(sum(diagnol_members))
