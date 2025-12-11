from collections import deque

targets = []
buttons = []

with open("input-day10.txt") as f:
    lines = f.readlines()
for line in lines:
    k = None
    parts = line.split(" ")
    curr_buttons = []
    for p in parts:
        if p.startswith("{"):
            p = p.replace("{", "")
            p = p.replace("}", "")
            p = p.split(",")
            p = [int(t) for t in p]
            targets.append(p)
        elif p.startswith("["):
            k = len(p) - 2
        else:
            p = p.replace("(", "")
            p = p.replace(")", "")
            indexes = p.split(",")
            indexes = [int(i) for i in indexes]
            button = [0] * k
            for i in range(k):
                if i in indexes:
                    button[i] = 1
            curr_buttons.append(button)
    buttons.append(curr_buttons)

num_machines = len(targets)
ans = 0
for i in range(num_machines):
    q = deque()
    k = len(targets[i])
    init = tuple(0 for _ in range(k))
    q.append((init, 0))
    visited = set()
    visited.add(init)
    curr_ans = float('inf')
    while len(q) > 0:
        state, operations = q.popleft()
        if state == tuple(targets[i]):
            curr_ans = operations
            break
        for b in buttons[i]:
            next_state = tuple(state[j] + b[j] for j in range(k))
            if all(next_state[j] <= targets[i][j] for j in range(k)) and next_state not in visited:
                visited.add(next_state)
                q.append((next_state, operations + 1))

    ans += curr_ans

print(ans)