class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = defaultdict(int)
        for i in range(len(nums)):
            mp[nums[i]] = 1

        ans = 0
        for num in mp:
            if num - 1 not in mp:
                l = 1
                cand = num + 1
                while cand in mp:
                    l += 1
                    cand += 1
                ans = max(l, ans)

        return ans