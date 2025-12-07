line = None
operators = None
rows = []
with open('input.txt') as f:
    lines = f.read().splitlines()
for line in lines:
    if line[0] != ' ' and not line[0].isdigit():
        operators = line
        break
    rows.append(line)
ans = 0
curr_nums = []
for c in reversed(range(len(rows[0]))):
    num = 0
    for row in rows:
        if row[c].isdigit():
            num *= 10
            num += int(row[c])
    if num != 0:
        curr_nums.append(num)
    operator = operators[c]
    if operator == '*':
        print(curr_nums)
        prod = 1
        for num in curr_nums:
            prod *= num
        curr_nums = []
        ans += prod
    elif operator == '+':
        print(curr_nums)
        s = sum(curr_nums)
        ans += s
        curr_nums = []

print(ans)