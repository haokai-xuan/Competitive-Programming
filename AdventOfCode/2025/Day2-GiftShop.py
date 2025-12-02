def isInvalid(n):
    n = str(n)
    if len(n) % 2:
        return False
    for i in range(len(n) // 2):
        if n[i] != n[len(n) // 2 + i]:
            return False
    return True

line = input()
ranges = line.split(",")
ans = 0
for r in ranges:
    r = r.split("-")
    start, end = int(r[0]), int(r[1])
    for i in range(start, end + 1):
        if isInvalid(i):
            ans += i
print(ans)