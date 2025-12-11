from collections import deque

coords = []
with open("input-day9.txt") as f:
    lines = f.readlines()
for line in lines:
    coords.append(tuple(map(int, line.split(","))))

lookupx = {}
lookupy = {}
rlookupx = {}
rlookupy = {}

for index, x in enumerate(sorted(set(x for x, _ in coords))):
    lookupx[x] = index * 2
    rlookupx[index * 2] = x
for index, y in enumerate(sorted(set(y for _, y in coords))):
    lookupy[y] = index * 2
    rlookupy[index * 2] = y

def l(i):
    return lookupx[coords[i][0]], lookupy[coords[i][1]]

n = len(coords)
s = set()

for i in range(n):
    x1, y1 = l(i)
    x2, y2 = l((i + 1) % n)

    if y1 == y2:
        for x in range(min(x1, x2), max(x1, x2) + 1):
            s.add((x, y1))
    if x1 == x2:
        for y in range(min(y1, y2), max(y1, y2) + 1):
            s.add((x1, y))

min_x = min(x for x, y in s)
points_at_min_x = [(x, y) for x, y in s if x == min_x]
leftmost_topmost = min(points_at_min_x)
seed = (leftmost_topmost[0] + 1, leftmost_topmost[1] + 1)

q = deque()
q.append(seed)
while len(q) > 0:
    cell = q.popleft()
    for dx, dy in [(1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0)]:
        nx, ny = cell[0] + dx, cell[1] + dy
        if (nx, ny) in s:
            continue
        else:
            s.add((nx, ny))
            q.append((nx, ny))

ans = 0

for i in range(n):
    x1, y1 = l(i)
    for j in range(i + 1, n):
        x2, y2 = l(j)

        good = True

        min_x = min(x1, x2)
        min_y = min(y1, y2)
        max_x = max(x1, x2)
        max_y = max(y1, y2)

        for x in range(min_x, max_x + 1):
            for y in [min_y, max_y]:
                if (x, y) not in s:
                    good = False
                    break
        for y in range(min_y, max_y + 1):
            for x in [min_x, max_x]:
                if (x, y) not in s:
                    good = False
                    break
        
        if good:
            ax = rlookupx[x1]
            ay = rlookupy[y1]
            bx = rlookupx[x2]
            by = rlookupy[y2]
            ans = max(ans, (abs(ax - bx) + 1) * (abs(ay - by) + 1))

print(ans)