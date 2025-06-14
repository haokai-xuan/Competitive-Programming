class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        max_rep = None
        min_rep = None
        imax = 0
        imin = 0
        for c in s:
            if c != "9":
                max_rep = c
                break
        for c in s:
            if c != "0":
                min_rep = c
                break
        for i in range(len(s)):
            imax *= 10
            imin *= 10
            if s[i] == max_rep:
                imax += 9
            else:
                imax += int(s[i])

            if s[i] == min_rep:
                imin += 0
            else:
                imin += int(s[i])
            

        # print(imax, imin)
        return imax - imin