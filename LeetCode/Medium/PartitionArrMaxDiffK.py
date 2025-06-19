class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 0
        left = 0
        for right in range(1, len(nums)):
            if nums[right] - nums[left] > k:
                ans += 1
                left = right

        ans += 1
        return ans