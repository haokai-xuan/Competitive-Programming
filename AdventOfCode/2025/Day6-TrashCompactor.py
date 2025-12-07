line = None
operators = None
rows = []
with open('input.txt') as f:
    lines = f.read().splitlines()
for line in lines:
    lst = line.strip().split()
    if not lst[0].isdigit():
        operators = lst
        break
    lst = [int(num) for num in lst]
    rows.append(lst)
ans = 0
for c_index in range(len(rows[0])):
    col_ans = 1 if operators[c_index] == '*' else 0
    for r in rows:
        if operators[c_index] == '*':
            col_ans *= r[c_index]
        else:
            col_ans += r[c_index]
    ans += col_ans

print(ans)