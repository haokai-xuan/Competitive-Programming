class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans = 0
        max_diff = 0
        max_val = 0

        for i in range(len(nums)):
            ans = max(ans, max_diff * nums[i])
            max_diff = max(max_diff, max_val - nums[i])
            max_val = max(max_val, nums[i])

        return ans