class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        ans = 0
        N = len(nums)
        for i in range(N - 2):
            if nums[i] + nums[i + 2] == nums[i + 1] / 2:
                ans += 1
        
        return ans