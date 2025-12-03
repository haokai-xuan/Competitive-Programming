ans = 0
bank = ""
while True:
    bank = input()
    if bank == "q":
        break
    final_joltage = 0
    last_index = 0
    for i in reversed(range(12)):
        rng = bank[last_index:len(bank) - i]
        l = list(rng)
        l = [int(n) for n in l]
        digit = max(l)
        last_index = last_index + l.index(digit) + 1
        final_joltage *= 10
        final_joltage += digit
    ans += final_joltage

print(ans)
