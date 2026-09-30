class Solution:
    def kthCharacter(self, k: int) -> str:
        def operate(s):
            n = len(s)
            for i in range(n):
                c = s[i]
                new_c = chr(ord("a") + (ord(c) - ord("a") + 1) % 26)
                s.append(new_c)

        s = ["a"]
        while len(s) < k:
            operate(s)

        return s[k - 1]