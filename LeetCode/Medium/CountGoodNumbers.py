class Solution:
    def countGoodNumbers(self, n: int) -> int:
        ans = 1
        MOD = 10 ** 9 + 7
        
        odd_positions = n // 2
        even_positions = n - odd_positions

        return (pow(5, even_positions, MOD) * pow(4, odd_positions, MOD)) % MOD