class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        left = 0
        ans = 0

        mp = defaultdict(int)

        for right in range(len(s)):
            mp[s[right]] += 1

            while len(mp) == 3:
                ans += len(s) - right

                mp[s[left]] -= 1
                if mp[s[left]] == 0:
                    mp.pop(s[left])
                
                left += 1

        return ans