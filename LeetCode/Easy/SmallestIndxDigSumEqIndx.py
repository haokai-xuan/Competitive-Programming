class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        def digitsSum(n):
            s = 0
            while n:
                digit = n % 10
                s += digit
                n //= 10
            return s

        for i in range(len(nums)):
            if digitsSum(nums[i]) == i:
                return i

        return -1©leetcode