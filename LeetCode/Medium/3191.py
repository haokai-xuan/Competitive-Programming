class Solution:
    def minOperations(self, nums: List[int]) -> int:
        operations = 0

        n = len(nums)
        for i in range(n - 2):
            if nums[i] == 0:
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                operations += 1

        if not nums[-1] or not nums[-2]:
            return -1
        else:
            return operations
