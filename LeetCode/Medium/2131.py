class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        mp = defaultdict(int)
        for word in words:
            mp[word] += 1
        used_center = False
        ans = 0

        for word, freq in mp.items():
            rev = word[::-1]
            if word == rev:
                pairs = freq // 2
                ans += pairs * 4
                if freq % 2 and not used_center:
                    ans += 2
                    used_center = True
            elif word < rev:
                ans += 4 * min(freq, mp.get(rev, 0))

        return ans