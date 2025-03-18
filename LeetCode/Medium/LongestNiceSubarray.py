class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        curr = 0
        longest = 0
        temp_longest = 0

        left = 0
        for right in nums:
            while curr & right:
                temp_longest -= 1
                curr ^= nums[left]
                left += 1
                
            temp_longest += 1
            curr |= right

            longest = max(longest, temp_longest)

        return longest