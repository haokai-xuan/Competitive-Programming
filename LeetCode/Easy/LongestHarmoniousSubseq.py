class Solution:
    def findLHS(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1

        ans = 0
        for key, val in mp.items():
            if key - 1 in mp:
                ans = max(ans, mp[key - 1] + mp[key])
            if key + 1 in mp:
                ans = max(ans, mp[key + 1] + mp[key])

        return ans