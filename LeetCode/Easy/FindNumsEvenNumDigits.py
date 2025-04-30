class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            s = str(nums[i])
            if len(s) % 2 == 0:
                ans += 1
        
        return ans