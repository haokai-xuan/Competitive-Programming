from itertools import combinations

targets = []
buttons = []

with open("input-day10.txt") as f:
    lines = f.readlines()
for line in lines:
    parts = line.split(" ")
    curr_buttons = []
    k = None
    for p in parts:
        if p.startswith("["):
            k = len(p) - 2
            continue
        elif p.startswith("{"):
            p = p.replace("{", "")
            p = p.replace("}", "")
            targets.append(tuple(int(i) for i in p.split(",")))
        else:
            p = p.replace("(", "")
            p = p.replace(")", "")
            indexes = p.split(",")
            indexes = [int(i) for i in indexes]
            button = [0] * k
            for i in indexes:
                button[i] = 1
            curr_buttons.append(tuple(button))
    buttons.append(curr_buttons)

# Returns a dictionary of all possible button states mapped to the minimum number of button presses to achieve it.
def get_pattern_costs(buttons):
    out = {}
    n = len(buttons)
    k = len(buttons[0])
    for pattern_len in range(n + 1):
        for btn_indices in combinations(range(n), pattern_len):
            pattern = tuple(map(sum, zip(tuple([0] * k), *(buttons[i] for i in btn_indices))))
            if pattern not in out:
                out[pattern] = pattern_len
    return out

def solve_machine(target, buttons):
    pattern_costs = get_pattern_costs(buttons)
    memo = {}
    def dfs(target):
        if target in memo:
            return memo[target]
        if all(x == 0 for x in target):
            return 0
        
        best = float('inf')
        for pattern, pattern_cost in pattern_costs.items():
            if all(i <= j and i % 2 == j % 2 for i, j in zip(pattern, target)):
                new_target = tuple((j - i) // 2 for i, j in zip(pattern, target))
                best = min(best, pattern_cost + 2 * dfs(new_target))

        memo[target] = best
        return best

    return dfs(target)

ans = 0
for i in range(len(targets)):
    subans = solve_machine(targets[i], buttons[i])
    ans += subans
print(ans)