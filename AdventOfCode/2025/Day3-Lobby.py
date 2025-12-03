ans = 0
bank = ""
while True:
    bank = input()
    if bank == "q":
        break
    d1_max = float('-inf')
    d2_max = float('-inf')
    d1_index = -1
    for i, joltage in enumerate(bank[:-1]):
        joltage = int(joltage)
        if joltage > d1_max:
            d1_max = joltage
            d1_index = i
    for joltage in bank[d1_index + 1:]:
        d2_max = max(d2_max, int(joltage))

    ans += d1_max * 10 + d2_max

print(ans)
