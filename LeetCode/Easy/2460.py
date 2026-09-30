class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        return self.move_zeroes(nums)

    def move_zeroes(self, nums):
        left = -1
        for right in range(len(nums)):
            if nums[right] == 0 and left == -1:
                left = right
            elif nums[right] != 0 and left != -1:
                nums[left] = nums[right]
                nums[right] = 0
                left += 1
        return nums