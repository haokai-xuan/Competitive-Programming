class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        left = 1
        for right in range(1, n):
            if nums[right] != nums[right - 1]:
                nums[left] = nums[right]
                left += 1
            right += 1

        return left