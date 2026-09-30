class Solution:
    def makeFancyString(self, s: str) -> str:
        i = 0
        ans = []
        while i < len(s):
            if i < len(s) - 2:
                if s[i] == s[i + 1] == s[i + 2]:
                    i += 1
                    continue
                else:
                    ans.append(s[i])
                    i += 1
            else:
                ans.append(s[i])
                i += 1

        return ''.join(ans)