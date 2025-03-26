class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = [entry for row in grid for entry in row]
        nums.sort()
        median = nums[len(nums) // 2]

        ans = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if abs(median - grid[i][j]) % x:
                    return -1
                ans += abs(median - grid[i][j]) // x

        return ans