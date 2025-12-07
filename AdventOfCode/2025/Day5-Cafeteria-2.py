line = None
ranges = []
while True:
    line = input()
    if line == 'q':
        break
    r = line.split("-")
    s, e = int(r[0]), int(r[1])
    ranges.append((s, e))

ranges.sort()
merged = []
for s, e in ranges:
    if not merged:
        merged.append((s, e))
    elif s <= merged[-1][1]:
        merged[-1] = (merged[-1][0], max(merged[-1][1], e))
    else:
        merged.append((s, e))
ans = 0
for s, e in merged:
    ans += e - s + 1
print(ans)