class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        num = 0
        ans = 0
        index = -1
        for i in range(len(s) - 1, -1, -1):
            new_num = num
            if s[i] == "1":
                new_num += 2 ** (len(s) - i - 1)
            if new_num > k:
                index = i
                break
            else:
                num = new_num
            ans += 1
        for i in range(index):
            if s[i] == "0":
                ans += 1

        return ans