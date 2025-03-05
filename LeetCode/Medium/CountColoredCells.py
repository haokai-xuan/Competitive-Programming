class Solution:
    def coloredCells(self, n: int) -> int:
        sum = 1

        i = 2
        while i <= n:
            sum += 4 * (i - 1)
            i += 1
        return sum