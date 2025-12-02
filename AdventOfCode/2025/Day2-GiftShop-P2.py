def isInvalid(n):
    n = str(n)
    for i in range(2, len(n) + 1):
        if len(n) % i == 0:
            size = len(n) // i
            all_same = True
            seq = n[0:size]
            for start in range(size, len(n), size):
                end = start + size
                if seq != n[start:end]:
                    all_same = False
                    break
            if all_same:
                return True
    return False

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