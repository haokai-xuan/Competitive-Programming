rot = None
cnt = 0
dial = 50
rot = input()
while rot != 'q':
    dir = rot[0]
    clicks = int(rot[1:])
    clicks *= -1 if dir == 'R' else 1
    dial = (dial + clicks) % 100
    if dial == 0:
        cnt += 1
    rot = input()

print(cnt)