with open('input-day12.txt') as f:
    lines = f.readlines()
lines = [line.splitlines()[0] for line in lines]

counts = []
regions = []
current = 0

for line in lines:
    if ':' in line and 'x' not in line:
        continue
    elif ':' in line:
        curr = []
        curr.append(int(line[:2]))
        curr.append(int(line[3:5]))
        curr.extend([int(num) for num in line[7:].split()])
        regions.append(curr)
    elif not line:
        counts.append(current)
        current = 0
    else:
        for c, cell in enumerate(line):
            if cell == '#':
                current += 1

ans = 0
# skip = 0
# s = 0
# not_skipped = []
for reg in regions:
    x, y = reg[:2]
    reqs = reg[2:]
    total = 0
    for i in range(6):
        total += reqs[i] * counts[i]
    if x * y < total:
        # skip += 1
        continue
    if x * y - total <= 1000:
        # not_skipped.append((total, x * y))
        # s += x * y - total
        ans += 1

# print(skip)
print(ans)
# print(not_skipped)
# print("avg:", s/len(not_skipped))