class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                top = float('inf')
                left = float('inf')
                if i - 1 >= 0:
                    top = dp[i - 1][j]
                if j - 1 >= 0:
                    left = dp[i][j - 1]
                
                if top == float('inf') and left == float('inf'):
                    dp[i][j] = grid[i][j]
                else:
                    dp[i][j] = grid[i][j] + min(top, left)

        return dp[m - 1][n - 1]