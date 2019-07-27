#!/usr/bin/python3.6
class Grid:
    
    def __init__(self, n):
        self.x = 0
        self.y = 0
        self.n = n
        self.last_move = ''
        self.setup()

    def setup(self):
        self.grid = []
        for i in range(0, self.n + 1):
            self.grid.append([])
            for i in range(self.n + 1):
                self.grid[-1].append(['o'])
        self.grid[0][0] = 'x'

    def print_grid(self):
        for r in self.grid:
            print(' '.join(map(lambda x: x[0], r)))
        print()

    def move(self, pos):
        if pos[0] > self.n or pos[1] > self.n:
            raise BaseException(f'{pos} is blocked')

        self.x = pos[0]
        self.y = pos[1]
        self.grid[self.y][self.x] = 'x'
        
        return True

    def can_go_down(self):
        return self.y < self.n

    def down(self, steps=1):
        if self.move((self.x, self.y + 1)):
            self.last_move = 'down'

    def can_go_right(self):
        return self.x < self.n

    def right(self, steps=1):
        if self.move((self.x + 1, self.y)):
            self.last_move = 'right'

    @property
    def pos(self):
        return (self.x, self.y)

    def set_pos(self, pos):
        self.move(pos)

def main(grid, pos=(0,0), cache={}, direction=False):
    grid.set_pos(pos)
    if direction == 'd' and grid.can_go_down():
        grid.down()
    elif direction == 'r' and grid.can_go_right():
        grid.right()
    
    # if grid.n - 1 == grid.x:
    #     return grid.n - grid.y + 1

    # if grid.n - 1 == grid.y:
    #     return grid.n - grid.x + 1

    grid.print_grid()
    if grid.can_go_down() and grid.can_go_right():
        x = grid.x
        y = grid.y
        if (x, y) in cache.keys():
            # input(f'> {x} {y}')
            return cache[(x, y)]
        paths = main(grid, (x, y), cache, 'd') + main(grid, (x, y), cache, 'r')
        cache[(x, y)] = paths
        return paths
    
    return 1

from sys import argv
print(main(Grid(int(argv[1]))))
