class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans = 0
        for i in range(1, len(nums) - 1):
            j = i
            while j < len(nums) - 1 and nums[j] == nums[i]:
                j += 1
            if nums[i - 1] > nums[i] and nums[i] < nums[j]:
                ans += 1
            elif nums[i - 1] < nums[i] and nums[i] > nums[j]:
                ans += 1

            i = j - 1
        
        return ans