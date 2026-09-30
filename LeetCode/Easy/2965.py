
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        mp = {}

        a = 0
        b = 0

        n = len(grid)
        total = (n * n) * (n * n + 1) // 2
        curr = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] in mp:
                    a = grid[i][j]
                else:
                    mp[grid[i][j]] = 1
                    curr += grid[i][j]
        
        b = total - curr
        
        return [a, b]