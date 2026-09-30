class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = -1
        for right in range(len(nums)):
            if nums[right] == 0 and left == -1:
                left = right
            elif nums[right] != 0 and left != -1:
                nums[left] = nums[right]
                nums[right] = 0
                left += 1