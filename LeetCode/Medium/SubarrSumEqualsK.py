class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ps_mp = defaultdict(int)
        ps_mp[0] = 1
        ps = 0
        ans = 0

        for num in nums:
            ps += num
            ans += ps_mp[ps - k]
            ps_mp[ps] += 1
        
        return ans