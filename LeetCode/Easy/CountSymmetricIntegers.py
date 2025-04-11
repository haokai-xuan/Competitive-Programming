class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        for i in range(low, high + 1):
            i_str = str(i)
            if len(i_str) % 2:
                i = pow(10, len(i_str)) - 1
                continue
            digits = [int(digit) for digit in i_str]
            first_n = digits[:len(i_str) // 2]
            last_n = digits[len(i_str) // 2:]
            if sum(first_n) == sum(last_n):
                ans += 1

        return ans