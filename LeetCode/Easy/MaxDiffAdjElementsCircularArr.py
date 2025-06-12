class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(n + 1):
            ans = max(ans, abs(nums[i % n] - nums[(i + 1) % n]))

        return ans