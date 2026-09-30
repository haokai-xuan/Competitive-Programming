class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prev_max = nums[0]
        ans = prev_max
        N = len(nums)

        for i in range(1, N):
            prev_max = max(prev_max + nums[i], nums[i])
            ans = max(prev_max, ans)

        return ans