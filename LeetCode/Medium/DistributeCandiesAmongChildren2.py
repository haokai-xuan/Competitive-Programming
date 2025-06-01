class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ans = 0
        for i in range(min(n, limit) + 1):
            if n - i > 2 * limit:
                continue
            c2_min = max(0, n - i - limit)
            c2_max = min(limit, n - i)
            ans += c2_max - c2_min + 1

        return ans