line = None
ranges = []
while True:
    line = input()
    if not line:
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

while True:
    line = input()
    if line == "q":
        break
    id = int(line)
    l, r = 0, len(merged)
    while l < r:
        mid = (l + r) // 2
        if merged[mid][0] <= id:
            l = mid + 1
        else:
            r = mid
    index = l - 1
    if index < 0:
        continue
    elif id <= merged[index][1]:
        ans += 1

print(ans)