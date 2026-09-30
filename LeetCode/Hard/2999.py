class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        low = str(start)
        high = str(finish)
        N = len(high)
        low = low.zfill(N)
        prefix_len = N - len(s)

        dp = [[[-1 for _ in range(2)] for _ in range(2)] for _ in range(N + 1)]

        def dfs(i, limit_low, limit_high):
            if i == N:
                return 1
            if dp[i][int(limit_low)][int(limit_high)] != -1:
                return dp[i][int(limit_low)][int(limit_high)]

            lo = int(low[i]) if limit_low else 0
            hi = int(high[i]) if limit_high else 9
            res = 0
            if i < prefix_len:
                for digit in range(lo, min(hi, limit) + 1):
                    res += dfs(i + 1,
                        limit_low and digit == lo,
                        limit_high and digit == hi
                    )
            else:
                suffix_digit = int(s[i - prefix_len])
                if lo <= suffix_digit and suffix_digit <= min(hi, limit):
                    res = dfs(
                        i + 1,
                        limit_low and suffix_digit == lo,
                        limit_high and suffix_digit == hi
                    )

            dp[i][int(limit_low)][int(limit_high)] = res
            return res

        return dfs(0, True, True)