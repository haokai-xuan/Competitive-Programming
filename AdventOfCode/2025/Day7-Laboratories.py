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

q = deque()
q.append(start_pos)
ans = 0
visited = [[False for _ in range(cols)] for _ in range(rows)]
visited[start_pos[0]][start_pos[1]] = True
print(start_pos)

while len(q) != 0:
    r, c = q.popleft()
    if grid[r][c] == '^':
        if in_bounds(rows, cols, r, c - 1) and not visited[r][c - 1]:
            q.append((r, c - 1))
            visited[r][c - 1] = True
        if in_bounds(rows, cols, r, c + 1) and not visited[r][c + 1]:
            q.append((r, c + 1))
            visited[r][c + 1] = True
        ans += 1
    elif in_bounds(rows, cols, r + 1, c) and not visited[r + 1][c]:
        q.append((r + 1, c))
        visited[r + 1][c] = True

print(ans)