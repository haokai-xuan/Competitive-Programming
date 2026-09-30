class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)
        subarr_sum = total - x

        left = 0
        curr = 0
        msf = -1
        for right in range(len(nums)):
            curr += nums[right]
            while left < len(nums) and curr > subarr_sum:
                curr -= nums[left]
                left += 1
            if curr == subarr_sum:
                msf = max(msf, right - left + 1)
        
        return -1 if msf == -1 else len(nums) - msf