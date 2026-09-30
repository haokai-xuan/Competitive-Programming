class Solution:
    def countLargestGroup(self, n: int) -> int:
        mp = defaultdict(list)

        max_len = -1
        ans = 0
        
        for i in range(1, n + 1):
            s = 0
            for c in str(i):
                s += int(c)
            mp[s].append(i)
            max_len = max(max_len, len(mp[s]))

        for key, lst in mp.items():
            if len(lst) == max_len:
                ans += 1
            
        return ans

        