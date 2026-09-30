class Solution:
    def maxSum(self, nums: List[int]) -> int:
        m = max(nums)
        if m < 0:
            return m

        s = set()
        for n in nums:
            s.add(n)

        ans = 0
        for n in s:
            if n > 0:
                ans += n
        
        return ans