class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        left = 0
        curr_min = float('inf')
        for right in range(len(nums)):
            if nums[right] < curr_min:
                curr_min = nums[right]
                left = right
            elif nums[right] > curr_min:
                ans = max(ans, nums[right] - nums[left])

        return ans