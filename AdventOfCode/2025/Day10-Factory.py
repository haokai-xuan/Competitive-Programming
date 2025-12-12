from collections import deque

diagrams = []
buttons = []

with open("input-day10.txt") as f:
    lines = f.readlines()
for line in lines:
    parts = line.split(" ")
    curr_buttons = []
    for p in parts:
        if p.startswith("["):
            p = p.replace("[", "")
            p = p.replace("]", "")
            d = 0
            for i in range(len(p)):
                if p[i] == '#':
                    d |= 1 << i
            diagrams.append(d)
        elif p.startswith("{"):
            break
        else:
            p = p.replace("(", "")
            p = p.replace(")", "")
            indexes = p.split(",")
            indexes = [int(i) for i in indexes]
            button = 0
            for i in indexes:
                button |= 1 << i
            curr_buttons.append(button)
    buttons.append(curr_buttons)

num_machines = len(diagrams)
ans = 0
for i in range(num_machines):
    q = deque()
    q.append((0, 0))
    visited = set()
    visited.add(0)
    curr_ans = float('inf')
    while len(q) > 0:
        state, operations = q.popleft()
        if state == diagrams[i]:
            curr_ans = operations
            break
        for b in buttons[i]:
            next_state = state ^ b
            if next_state not in visited:
                visited.add(next_state)
                q.append((next_state, operations + 1))

    ans += curr_ans

print(ans)