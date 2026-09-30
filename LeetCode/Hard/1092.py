class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        lcs_res = self.lcs(str1, str2)
        print(f"LCS: {lcs_res}")
        
        i = 0
        j = 0
        scs = ""
        for char in lcs_res:
            while str1[i] != char:
                scs += str1[i]
                i += 1
            while str2[j] != char:
                scs += str2[j]
                j += 1
            scs += char
            i += 1
            j += 1
        
        scs += str1[i:]
        scs += str2[j:]

        return scs
        
    def lcs(self, str1, str2):
        n = len(str1)
        m = len(str2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        i = n
        j = m
        res = ""
        while i > 0 and j > 0:
            if str1[i - 1] == str2[j - 1]:
                i -= 1
                j -= 1
                res += str1[i]
            elif dp[i - 1][j] > dp[i][j - 1]:
                i -= 1
            else:
                j -= 1
        return res[::-1]
