class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2:
            return False

        target = total // 2
        memo = {}

        def dfs(index, subset_sum):
            if index == len(nums) or subset_sum > target:
                return False
            if subset_sum == target:
                return True

            if (index, subset_sum) in memo:
                return memo[(index, subset_sum)]

            if dfs(index + 1, subset_sum):
                memo[(index, subset_sum)] = True
                return True
            if dfs(index + 1, subset_sum + nums[index]):
                memo[(index, subset_sum)] = True
                return True

            memo[(index, subset_sum)] = False
            return False

        return dfs(0, 0)