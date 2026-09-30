class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n
            
        two_before = 1
        one_before = 2
        ans = 0

        for i in range(n - 2):
            ans = two_before + one_before
            two_before = one_before
            one_before = ans

        return ans