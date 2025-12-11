reds = []
line = None
while True:
    line = input()
    if line == 'q':
        break
    coords = [int(i) for i in line.split(',')]
    reds.append((coords[0], coords[1]))

pairs = []
for i in range(len(reds)):
    for j in range(i + 1, len(reds)):
        pairs.append([(reds[i][0], reds[i][1]), (reds[j][0], reds[j][1])])

ans = 0
for p in pairs:
    c1x, c1y = p[0][0], p[0][1]
    c2x, c2y = p[1][0], p[1][1]
    w, h = abs(c1x - c2x) + 1, abs(c1y - c2y) + 1
    ans = max(ans, w * h)

print(ans)