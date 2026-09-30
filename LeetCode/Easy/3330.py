class Solution:
    def possibleStringCount(self, word: str) -> int:
        ans = 1
        prev = None
        for c in word:
            if c != prev:
                prev = c
            else:
                ans += 1

        return ans