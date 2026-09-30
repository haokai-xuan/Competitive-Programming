class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = int(1e9 + 7)
        def solve(num):
            if num == 1:
                return 1
            
            return ((solve(num - 1) << num.bit_length()) | num) % MOD

        return solve(n)