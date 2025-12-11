poly = []
lines = None
with open("input-day9.txt") as f:
    lines = f.readlines()
for line in lines:
    coords = [int(i) for i in line.split(',')]
    poly.append((coords[0], coords[1]))

n = len(poly)
ans = 0

def on_segment(A, B, C):
    return (A[1] == B[1] == C[1] and C[0] >= min(A[0], B[0]) and C[0] <= max(A[0], B[0])) or (A[0] == B[0] == C[0] and C[1] >= min(A[1], B[1]) and C[1] <= max(A[1], B[1]))

def point_in_poly(c, r):
    inside = False
    for i in range(n):
        c1, r1 = poly[i]
        c2, r2 = poly[(i + 1) % n]

        if on_segment((c1, r1), (c2, r2), (c, r)):
            return True
        
        if (r1 > r) != (r2 > r):
            c_intersect = c1
            if c_intersect >= c:
                inside = not inside

    return inside


def rect_inside(A, B):
    Ac, Ar = A
    Bc, Br = B
    C = (Ac, Br)
    D = (Bc, Ar)
    for (c, r) in [A, B, C, D]:
        if not point_in_poly(c, r):
            return False
        
    c1, c2 = sorted([Ac, Bc])
    r1, r2 = sorted([Ar, Br])
        
    for c in range(c1 + 1, c2):
        if not point_in_poly(c, Ar):
            return False
    for c in range(c1 + 1, c2):
        if not point_in_poly(c, Br):
            return False
        
    for r in range(r1 + 1, r2):
        if not point_in_poly(Ac, r):
            return False
    for r in range(r1 + 1, r2):
        if not point_in_poly(Bc, r):
            return False
        
    return True

for i in range(n):
    for j in range(i + 1, n):
        A = poly[i]
        B = poly[j]

        area = (abs(A[0] - B[0]) + 1) * (abs(A[1] - B[1]) + 1)
        if area <= ans:
            continue
        
        if rect_inside(A, B):
            ans = area

print(ans)