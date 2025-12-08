class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1] * n
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, a, b):
        ra, rb = self.find(a,), self.find(b)
        if ra == rb:
            return False
        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        self.size[ra] += self.size[rb]
        return True
    def component_sizes(self):
        for i in range(len(self.parent)):
            self.parent[i] = self.find(i)
        cnt = {}
        for i in range(len(self.parent)):
            if self.parent[i] not in cnt:
                cnt[self.parent[i]] = 1
            else:
                cnt[self.parent[i]] += 1
        return sorted(list(cnt.values()), reverse=True)
    
coords = []
line = None
while True:
    line = input()
    if line == 'q':
        break
    coords.append([int(i) for i in line.split(',')])

n = len(coords)
dsu = DSU(n)
pairs = []
for i in range(n):
    xi, yi, zi = coords[i][0], coords[i][1], coords[i][2]
    for j in range(i + 1, n):
        xj, yj, zj = coords[j][0], coords[j][1], coords[j][2]
        dx = xi - xj
        dy = yi - yj
        dz = zi - zj
        d2 = dx ** 2 + dy ** 2 + dz ** 2
        pairs.append((d2, i, j))
pairs.sort()

for i in range(1000):
    _, i, j = pairs[i]
    dsu.union(i, j)

sizes = dsu.component_sizes()
print(sizes[0] * sizes[1] * sizes[2])