rot = None
cnt = 0
dial = 50
rot = input()
while rot != 'q':
    dir = rot[0]
    clicks = int(rot[1:])
    step = -1 if dir == 'L' else 1
    for _ in range(clicks):
        dial = (dial + step) % 100
        if dial == 0:
            cnt += 1
    rot = input()

print(cnt)