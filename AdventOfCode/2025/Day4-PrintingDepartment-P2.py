grid = []
while True:
    row = input()
    if row == 'q':
        break
    grid.append(list(row))

d = [(-1, -1), [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1]]

rows, cols = len(grid), len(grid[0])
ans = 0

def remove():
    global grid
    to_remove = []
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] != "@":
                continue
            cnt = 0
            valid = True
            for dx, dy in d:
                nr = i + dx
                nc = j + dy
                if nr >= 0 and nr < rows and nc >= 0 and nc < cols:
                    if grid[nr][nc] == "@":
                        cnt += 1
                        if cnt >= 4:
                            valid = False
            if valid:
                to_remove.append((i, j))

    for i, j in to_remove:
        grid[i][j] = "."

    return len(to_remove)

while True:
    removed = remove()
    if removed == 0:
        break
    ans += removed

print(ans)