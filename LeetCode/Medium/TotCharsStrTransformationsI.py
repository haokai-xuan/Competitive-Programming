class Solution(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        MOD = int(1e9 + 7)
        arr = [0] * 26
        for c in s:
            arr[ord(c) - ord("a")] += 1
        ans = 0
        for i in range(t):
            new_arr = [0] * 26
            for j in range(26):
                if arr[j] != 0 and j == 25:
                    new_arr[0] += arr[j]
                    new_arr[1] += arr[j]
                elif arr[j] != 0:
                    new_arr[j + 1] += arr[j]
            arr = new_arr

        return sum(arr) % MOD