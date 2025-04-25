class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        ps = [nums[0]]
        N = len(nums)
        for i in range(1, N):
            ps.append(ps[i - 1] + nums[i])
        
        ans = 0
        for i in range(N):
            start = max(0, i - nums[i])
            ans += ps[i] - (0 if start == 0 else ps[start - 1])
        
        return ans