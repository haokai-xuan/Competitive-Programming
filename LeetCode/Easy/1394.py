class Solution:
    def findLucky(self, arr: List[int]) -> int:
        mp = defaultdict(int)
        for i in arr:
            mp[i] += 1

        ans = -1
        for key, freq in mp.items():
            if key == freq:
                ans = max(ans, key)

        return ans