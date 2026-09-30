class Solution:
    def countAndSay(self, n: int) -> str:
        def helper(n):
            if n == 1:
                return "1"
            
            s = ""
            n_minus = helper(n - 1)
            prev = n_minus[0]
            cnt = 1
            for i in range(1, len(n_minus)):
                if n_minus[i] == prev:
                    cnt += 1
                else:
                    s += str(cnt) + prev
                    prev = n_minus[i]
                    cnt = 1
            s += str(cnt) + prev

            return s
            
        return helper(n)