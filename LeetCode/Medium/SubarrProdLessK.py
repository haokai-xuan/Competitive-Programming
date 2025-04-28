class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        N = len(nums)
        ans = 0
        left = 0
        curr = 1
        for right in range(N):
            curr *= nums[right]
            while curr >= k and left <= right:
                curr /= nums[left]
                left += 1
            ans += right - left + 1

        return ans