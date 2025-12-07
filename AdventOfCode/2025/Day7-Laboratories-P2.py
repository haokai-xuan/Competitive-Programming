from collections import deque

def find_start(grid, rows, cols):
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 'S':
                start_pos = (r + 1, c)
                return start_pos
            
def in_bounds(rows, cols, r, c):
    return r >= 0 and r < rows and c >= 0 and c < cols

grid = []
line = None
while True:
    line = input()
    if line == 'q':
        break
    row = [c for c in line]
    grid.append(row)

rows, cols = len(grid), len(grid[0])
start_pos = find_start(grid, rows, cols)

memo = {}
def count(r, c):
    if r >= rows:
        return 1
    if (r, c) in memo:
        return memo[(r, c)]
    if grid[r][c] == '.':
        ans = count(r + 1, c)
    else:
        ans = count(r, c - 1) + count(r, c + 1)
    memo[(r, c)] = ans
    return ans

print(count(start_pos[0] + 1, start_pos[1]))